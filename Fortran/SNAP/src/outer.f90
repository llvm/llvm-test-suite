!-----------------------------------------------------------------------
!
! MODULE: outer_module
!> @brief
!> This module controls the outer iterations. Outer iterations are
!> threaded over the energy dimension and represent a Jacobi iteration
!> strategy. Includes setting the outer source. Checking outer iteration
!> convergence.
!
!-----------------------------------------------------------------------

MODULE outer_module

  USE global_module, ONLY: i_knd, r_knd, one, zero

  USE geom_module, ONLY: nx, ny, nz

  USE sn_module, ONLY: nmom, cmom

  USE data_module, ONLY: ng, mat, slgg, qi, nmat

  USE solvar_module, ONLY: q2grp0, q2grpm, flux0, fluxm, flux0po

  USE control_module, ONLY: inrdone, tolr, dfmxo, epsi, otrdone

  USE inner_module, ONLY: inner

  USE time_module, ONLY: totrsrc, tinners, wtime

  USE plib_module, ONLY: nthreads, glmax, comm_snap

  USE expxs_module, ONLY: expxs_reg, expxs_slgg

  USE thrd_comm_module, ONLY: assign_thrd_set

  IMPLICIT NONE

  PRIVATE

  PUBLIC :: outer


  CONTAINS


  SUBROUTINE outer ( iits, otno, t, do_grp, ng_per_thrd, nnstd_used,   &
    grp_act, iitm_i )

!-----------------------------------------------------------------------
!
! Do a single outer iteration. Sets the out-of-group sources, performs
! inners for all groups.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: otno, t, iitm_i

    INTEGER(i_knd), INTENT(INOUT) :: ng_per_thrd, nnstd_used

    INTEGER(i_knd), DIMENSION(ng), INTENT(OUT) :: iits

    INTEGER(i_knd), DIMENSION(ng), INTENT(INOUT) :: do_grp

    INTEGER(i_knd), DIMENSION(ng,nthreads), INTENT(INOUT) :: grp_act
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: inno, g, n

    REAL(r_knd) :: t1, t2, t3, t4, dft(nthreads)
!_______________________________________________________________________
!
!   Compute the outer source: sum of fixed + out-of-group sources.
!   Each thread t will do a set of energy groups. Nested threads will
!   work over local ny*nz span. In many instances, changing do_grp
!   will not change grp_act, but the action better resembles production.
!_______________________________________________________________________

  !$OMP MASTER

    CALL wtime ( t1 )

    inrdone = .FALSE.
    iits = 0

    DO g = 1, ng
      do_grp(g) = ng - g + 1
    END DO

    CALL assign_thrd_set ( do_grp, ng, ng_per_thrd, ny*nz, nnstd_used, &
      grp_act )

  !$OMP END MASTER
  !$OMP BARRIER

    CALL outer_src ( ng_per_thrd, nnstd_used, grp_act(:,t) )
  !$OMP BARRIER

  !$OMP MASTER
    CALL wtime ( t2 )
    totrsrc = totrsrc + t2 - t1
  !$OMP END MASTER
!_______________________________________________________________________
!
!   Zero out the inner iterations group count. Save the flux for
!   comparison. Initialize inrdone.
!_______________________________________________________________________

    DO n = 1, ng_per_thrd
      g = grp_act(n,t)
      IF ( g == 0 ) EXIT
      flux0po(:,:,:,g) = flux0(:,:,:,g)
    END DO
!_______________________________________________________________________
!
!   Start the inner iterations
!_______________________________________________________________________

  !$OMP MASTER
    CALL wtime ( t3 )
  !$OMP END MASTER

  !$OMP BARRIER

    inner_loop: DO inno = 1, iitm_i

      CALL inner ( inno, iits, t, do_grp, ng_per_thrd, nnstd_used,     &
        grp_act )
  !$OMP BARRIER

      IF ( ALL( inrdone ) ) EXIT inner_loop

    END DO inner_loop

  !$OMP MASTER

    CALL wtime ( t4 )
    tinners = tinners + t4 - t3
!_______________________________________________________________________
!
!   Check outer convergence. Apply nested threads to group sets.
!_______________________________________________________________________

    do_grp = 1
    CALL assign_thrd_set ( do_grp, ng, ng_per_thrd, 0, nnstd_used,     &
      grp_act )

    dfmxo = -HUGE( one )

  !$OMP END MASTER
  !$OMP BARRIER
!_______________________________________________________________________
!
!   Thread to speed up computation of df by looping over groups. Rejoin
!   threads and then determine max error.
!_______________________________________________________________________

    dft(t) = -one

  !$OMP PARALLEL DO NUM_THREADS(nnstd_used) IF(nnstd_used>1)           &
  !$OMP& SCHEDULE(STATIC,1) DEFAULT(SHARED) PRIVATE(n,g)               &
  !$OMP& PROC_BIND(CLOSE)
    DO n = 1, ng_per_thrd
      g = grp_act(n,t)
      IF ( g == 0 ) CYCLE
      CALL outer_df_calc ( flux0po(:,:,:,g), flux0(:,:,:,g), dft(t) )
    END DO
  !$OMP END PARALLEL DO

  !$OMP CRITICAL
    dfmxo = MAX( dfmxo, dft(t) )
  !$OMP END CRITICAL
  !$OMP BARRIER

  !$OMP MASTER

    CALL glmax ( dfmxo, comm_snap )

    IF ( dfmxo<=100.0_r_knd*epsi .AND. ALL( inrdone ) .AND. otno/=1 )  &
      otrdone = .TRUE.

  !$OMP END MASTER
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE outer


  SUBROUTINE outer_src ( ng_per_thrd, nnstd_used, grp_act )

!-----------------------------------------------------------------------
!
! Loop over groups to compute each one's outer loop source.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: ng_per_thrd, nnstd_used

    INTEGER(i_knd), DIMENSION(ng), INTENT(IN) :: grp_act
!_______________________________________________________________________
!
!   Local Variables
!_______________________________________________________________________

    INTEGER(i_knd) :: n, g, k, j
!_______________________________________________________________________
!
!   Loop over each set of groups. Use nested threads if available.
!_______________________________________________________________________

  !$OMP PARALLEL NUM_THREADS(nnstd_used) IF(nnstd_used>1)              &
  !$OMP& DEFAULT(SHARED) PRIVATE(n,g,k,j) PROC_BIND(CLOSE)
    DO n = 1, ng_per_thrd

      g = grp_act(n)
      IF ( g == 0 ) EXIT

  !$OMP DO SCHEDULE(STATIC,1) COLLAPSE(2)
      DO k = 1, nz
      DO j = 1, ny
        CALL outer_src_calc ( g, j, k, qi(:,j,k,g), slgg(:,:,:,g),     &
          mat(:,j,k), q2grp0(:,j,k,g), q2grpm(:,:,j,k,g) )
      END DO
      END DO
  !$OMP END DO NOWAIT

    END DO
  !$OMP END PARALLEL
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE outer_src


  SUBROUTINE outer_src_calc ( g, j, k, qi0, sxs_g, map, qo0, qom )

!-----------------------------------------------------------------------
!
! Compute the scattering source for all cells and moments. This routine
! is called for each group. It computes source components from all the
! other groups, which are looped over here. It skips computing the
! source from itself, which is captured in the inner iterations.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: g, j, k

    INTEGER(i_knd), DIMENSION(nx), INTENT(IN) :: map

    REAL(r_knd), DIMENSION(nx), INTENT(IN) :: qi0

    REAL(r_knd), DIMENSION(nx), INTENT(OUT) :: qo0

    REAL(r_knd), DIMENSION(cmom-1,nx), INTENT(OUT) :: qom

    REAL(r_knd), DIMENSION(nmat,nmom,ng), INTENT(IN) :: sxs_g
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: gp

    REAL(r_knd), DIMENSION(nx) :: cs0

    REAL(r_knd), DIMENSION(cmom-1,nx) :: csm
!_______________________________________________________________________
!
!   Initialize sources. Include isotropic inhomogeneous source.
!_______________________________________________________________________

    qo0 = qi0
    qom = zero
!_______________________________________________________________________
!
!   Loop over originating groups, gp. Skip own group.
!_______________________________________________________________________

    DO gp = 1, ng

      IF ( gp == g ) CYCLE
!_______________________________________________________________________
!
!     Expand isotropic cross sections to fine mesh for current gp->g.
!     Add out of group scattering source.
!_______________________________________________________________________

      CALL expxs_reg ( sxs_g(:,1,gp), map, cs0 )

      qo0 = qo0 + cs0*flux0(:,j,k,gp)
!_______________________________________________________________________
!
!     Expand anisotropic cross sections to fine mesh for gp->g. Add
!     components to group scattering source moments. Close the loop.
!_______________________________________________________________________

      IF ( nmom == 1 ) CYCLE

      CALL expxs_slgg ( sxs_g(:,:,gp), map, csm )

      qom = qom + csm*fluxm(:,:,j,k,gp)

    END DO
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE outer_src_calc


  SUBROUTINE outer_df_calc ( flux0po, flux0, dft )

!-----------------------------------------------------------------------
!
! Check for convergence of outer iterations. Use only the zeroth moment
! data (flux0/flux0po).
!
!-----------------------------------------------------------------------

    REAL(r_knd), INTENT(INOUT) :: dft

    REAL(r_knd), DIMENSION(nx,ny,nz), INTENT(INOUT) :: flux0po

    REAL(r_knd), DIMENSION(nx,ny,nz), INTENT(IN) :: flux0
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    REAL(r_knd) :: dfg

    REAL(r_knd), DIMENSION(nx,ny,nz) :: df
!_______________________________________________________________________
!
!   Thread to speed up computation of df by looping over groups. Rejoin
!   threads and then determine max error.
!_______________________________________________________________________

    df = one
    WHERE( ABS( flux0po ) < tolr )
      flux0po = one
      df = zero
    END WHERE
    df = ABS( flux0/flux0po - df )

    dfg = MAXVAL( df )

    dft = MAX( dft, dfg )
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE outer_df_calc


END MODULE outer_module
