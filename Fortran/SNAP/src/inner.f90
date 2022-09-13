!-----------------------------------------------------------------------
!
! MODULE: inner_module
!> @brief
!> This module controls the inner iterations. Inner iterations include
!> the KBA mesh sweep, which is parallelized via MPI and vectorized over
!> angles in a given octant. Inner source computed here and inner
!> convergence is checked.
!
!-----------------------------------------------------------------------

MODULE inner_module

  USE global_module, ONLY: i_knd, r_knd, one, ounit, zero

  USE geom_module, ONLY: nx, ny, nz, nc

  USE sn_module, ONLY: nmom, cmom, lma, nang, noct

  USE data_module, ONLY: ng

  USE control_module, ONLY: epsi, tolr, dfmxi, inrdone, it_det

  USE solvar_module, ONLY: q2grp0, q2grpm, s_xs, flux0, flux0pi, fluxm,&
    qtot, fixup_counter

  USE sweep_module, ONLY: sweep

  USE time_module, ONLY: tinrsrc, tsweeps, wtime

  USE plib_module, ONLY: nthreads, glmax, comm_snap, iproc, root, ichunk

  USE thrd_comm_module, ONLY: assign_thrd_set

  IMPLICIT NONE

  PRIVATE

  PUBLIC :: inner


  CONTAINS


  SUBROUTINE inner ( inno, iits, t, do_grp, ng_per_thrd, nnstd_used,   &
    grp_act )

!-----------------------------------------------------------------------
!
! Do a single inner iteration for all groups. Calculate the total source
! for each group and sweep the mesh over octants. Repeat for all groups
! unless the group is converged according to inrdone(g).
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: inno, t

    INTEGER(i_knd), INTENT(INOUT) :: ng_per_thrd, nnstd_used

    INTEGER(i_knd), DIMENSION(ng), INTENT(OUT) :: iits

    INTEGER(i_knd), DIMENSION(ng), INTENT(INOUT) :: do_grp

    INTEGER(i_knd), DIMENSION(ng,nthreads), INTENT(INOUT) :: grp_act
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: n, g

    REAL(r_knd) :: t1, t2, t3, t4
!_______________________________________________________________________
!
!   Compute the inner source and add it to fixed + out-of-group sources.
!   No need to do inner operations if the group's inners are converged.
!_______________________________________________________________________

  !$OMP MASTER

    CALL wtime ( t1 )

    do_grp = 1
    WHERE( inrdone ) do_grp = 0

    CALL assign_thrd_set ( do_grp, ng, ng_per_thrd, ny*nz, nnstd_used, &
      grp_act )

  !$OMP END MASTER
  !$OMP BARRIER

    CALL inner_src ( ng_per_thrd, nnstd_used, grp_act(:,t) )
  !$OMP BARRIER

  !$OMP MASTER
    CALL wtime ( t2 )
    tinrsrc = tinrsrc + t2 - t1
  !$OMP END MASTER
!_______________________________________________________________________
!
!   With source computed, set previous copy of flux; new flux moments
!   iterates computed during sweep.
!_______________________________________________________________________

    DO n = 1, ng_per_thrd
      g = grp_act(n,t)
      IF ( g == 0 ) EXIT
      flux0pi(:,:,:,g) = flux0(:,:,:,g)
    END DO
!_______________________________________________________________________
!
!   Call for the transport sweep. Check convergence, using threads.
!_______________________________________________________________________

  !$OMP MASTER
    CALL wtime ( t3 )
  !$OMP END MASTER

  !$OMP BARRIER

    CALL sweep ( t, do_grp, ng_per_thrd, nnstd_used, grp_act )

  !$OMP BARRIER

  !$OMP MASTER

    CALL wtime ( t4 )
    tsweeps = tsweeps + t4 - t3
!_______________________________________________________________________
!
!   Check inner convergence. Apply nested threads to group sets.
!_______________________________________________________________________

    do_grp = 1
    WHERE( inrdone ) do_grp = 0

    CALL assign_thrd_set ( do_grp, ng, ng_per_thrd, 0, nnstd_used,     &
      grp_act )

  !$OMP END MASTER
  !$OMP BARRIER
!_______________________________________________________________________
!
!   Thread group loops for computing local difference (df) array.
!_______________________________________________________________________

  !$OMP PARALLEL DO NUM_THREADS(nnstd_used) IF(nnstd_used>1)           &
  !$OMP& SCHEDULE(STATIC,1) DEFAULT(SHARED) PRIVATE(n,g)               &
  !$OMP& PROC_BIND(CLOSE)
    DO n = 1, ng_per_thrd
      g = grp_act(n,t)
      IF ( g == 0 ) CYCLE
      CALL inner_df_calc ( inno, iits(g), flux0pi(:,:,:,g),            &
                        flux0(:,:,:,g), dfmxi(g) )
    END DO
  !$OMP END PARALLEL DO
!_______________________________________________________________________
!
!   All procs then reduce dfmxi for all groups, determine which groups
!   are converged and print requested info
!_______________________________________________________________________

  !$OMP BARRIER
  !$OMP MASTER

    CALL glmax ( dfmxi, ng, comm_snap )
    WHERE( dfmxi <= epsi ) inrdone = .TRUE.

    IF ( iproc==root .AND. it_det==1 ) THEN
      DO g = 1, ng
        fixup_counter(:,1,g) = fixup_counter(:,1,g) /                  &
          ( REAL(nx,r_knd) * REAL(ny,r_knd) * REAL(nz,r_knd) *         &
            REAL(nang,r_knd) * REAL(noct,r_knd) )
        WRITE( ounit, 221 ) g, iits(g), dfmxi(g),                      &
                            (fixup_counter(n,1,g),n=1,4)
      END DO
    END IF

  !$OMP END MASTER
!_______________________________________________________________________

    221 FORMAT( 4X, 'Group ', I3, 4X, ' Inner ', I5, 4X, ' Dfmxi ',    &
                ES11.4, '     Fixup x/y/z/t ', 4(ES9.2,1x) )
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE inner


  SUBROUTINE inner_src ( ng_per_thrd, nnstd_used, grp_act )

!-----------------------------------------------------------------------
!
! Compute the inner source, i.e., the within-group scattering source.
! Thread over groups and use nested threads on i-lines when available.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: ng_per_thrd, nnstd_used

    INTEGER(i_knd), DIMENSION(ng), INTENT(IN) :: grp_act
!_______________________________________________________________________
!
!   Local variables
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
        CALL inner_src_calc ( j, k, s_xs(:,:,:,:,g), flux0(:,j,k,g),   &
          fluxm(:,:,j,k,g), q2grp0(:,j,k,g), q2grpm(:,:,j,k,g),        &
          qtot(:,:,:,:,:,g) )
      END DO
      END DO
  !$OMP END DO NOWAIT

    END DO
  !$OMP END PARALLEL
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE inner_src


  SUBROUTINE inner_src_calc ( j, k, sxs_g, f0, fm, qo0, qom, q )

!-----------------------------------------------------------------------
!
! Compute the within-group scattering for a given group. Add it to fixed
! and out-of-group sources.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: j, k

    REAL(r_knd), DIMENSION(nx), INTENT(IN) :: f0, qo0

    REAL(r_knd), DIMENSION(cmom-1,nx), INTENT(IN) :: fm, qom

    REAL(r_knd), DIMENSION(nx,ny,nz,nmom), INTENT(IN) :: sxs_g

    REAL(r_knd), DIMENSION(cmom,ichunk,ny,nz,nc), INTENT(OUT) :: q
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: ic, ich, i, mom, l
!_______________________________________________________________________
!
!   Loop over i cells. Set the first source moment with flux0 (f0). Then
!   set remaining source moments with fluxm (fm) and combination of
!   higher scattering orders.
!_______________________________________________________________________

    ic = 0
    ich = 1

    DO i = 1, nx

      ic = ic + 1

      q(1,ic,j,k,ich) = qo0(i) + f0(i)*sxs_g(i,j,k,1)

      mom = 1
      DO l = 2, nmom
        q(mom+1:mom+lma(l),ic,j,k,ich) = qom(mom:mom+lma(l)-1,i) +     &
          fm(mom:mom+lma(l)-1,i)*sxs_g(i,j,k,l)
        mom = mom + lma(l)
      END DO

      IF ( ic == ichunk ) THEN
        ic = 0
        ich = ich + 1
      END IF

    END DO
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE inner_src_calc


  SUBROUTINE inner_df_calc ( inno, iits, flux0pi, flux0, dfmxi )

!-----------------------------------------------------------------------
!
! Check for inner iteration convergence using the flux array.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: inno

    INTEGER(i_knd), INTENT(OUT) :: iits

    REAL(r_knd), INTENT(OUT) :: dfmxi

    REAL(r_knd), DIMENSION(nx,ny,nz), INTENT(INOUT) :: flux0pi

    REAL(r_knd), DIMENSION(nx,ny,nz), INTENT(IN) :: flux0
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    REAL(r_knd), DIMENSION(nx,ny,nz) :: df
!_______________________________________________________________________
!
!   Compute max for individual group, all spatial extent.
!_______________________________________________________________________

    iits = inno

    df = one
    WHERE( ABS( flux0pi ) < tolr )
      flux0pi = one
      df = zero
    END WHERE
    df = ABS( flux0/flux0pi - df )

    dfmxi = MAXVAL( df )
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE inner_df_calc


END MODULE inner_module
