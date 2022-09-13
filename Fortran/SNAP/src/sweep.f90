!-----------------------------------------------------------------------
!
! MODULE: sweep_module
!> @brief
!> This module controls the mesh sweep scheduling. It directs the flow
!> of KBA stages for different octants, groups, spatial work chunks.
!
!-----------------------------------------------------------------------

MODULE sweep_module

  USE global_module, ONLY: i_knd, l_knd, zero, one

  USE data_module, ONLY: ng

  USE geom_module, ONLY: nc, ny, nz, jdim, kdim, ndiag

  USE sn_module, ONLY: nang

  USE control_module, ONLY: inrdone, ncor, corner_sch, nops, yzstg,    &
    corner_loop_order, multiswp

  USE octsweep_module, ONLY: octsweep

  USE solvar_module, ONLY: flkx, flky, flkz, fmin, fmax, flux0, fluxm, &
    jb_in, kb_in, jb_out, kb_out, fixup_counter

  USE plib_module, ONLY: nthreads, waitinit, ichunk, npey, npez

  USE thrd_comm_module, ONLY: assign_thrd_set, multiswp_recv_bdry,     &
    multiswp_test_pick, multiswp_send_bdry

  IMPLICIT NONE

  PRIVATE

  PUBLIC :: sweep

  SAVE


  CONTAINS


  SUBROUTINE sweep ( t, do_grp, ng_per_thrd, nnstd_used, grp_act )

!-----------------------------------------------------------------------
!
! Driver for the mesh sweeps. Manages the loops over octant pairs.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: t

    INTEGER(i_knd), INTENT(INOUT) :: ng_per_thrd, nnstd_used

    INTEGER(i_knd), DIMENSION(ng), INTENT(INOUT) :: do_grp

    INTEGER(i_knd), DIMENSION(ng,nthreads), INTENT(INOUT) :: grp_act

!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: cor, jd, kd, g, nc_tot, nstg, n, nulreq,         &
      dummy(2)=(/0, 0/)

    INTEGER(i_knd), DIMENSION(ncor) :: mtag, ic_op, gc, g_op

    INTEGER(i_knd), DIMENSION(2*ncor) :: reqr, reqs

    LOGICAL(l_knd), DIMENSION(ncor) :: done, callrecv
!_______________________________________________________________________
!
!   Assign the work to threads. Main level threads always applied to
!   energy groups. Apply nested threads additionally to groups if
!   swp_typ is 0. Apply nested threads to mini-KBA if swp_typ is 1.
!_______________________________________________________________________

  !$OMP MASTER

    do_grp = 1
    WHERE ( inrdone ) do_grp = 0

    CALL assign_thrd_set ( do_grp, ng, ng_per_thrd, ndiag, nnstd_used, &
      grp_act )

  !$OMP END MASTER
  !$OMP BARRIER
!_______________________________________________________________________
!
!   Clean up and initialize some values.
!_______________________________________________________________________

    nc_tot = 0

    clean_loop: DO n = 1, ng_per_thrd

      g = grp_act(n,t)
      IF ( g == 0 ) EXIT clean_loop

      fixup_counter(:,:,g) = zero

      fmin(g) = HUGE( one )
      fmax(g) = zero

      flkx(:,:,:,g) = zero
      flky(:,:,:,g) = zero
      flkz(:,:,:,g) = zero

      flux0(:,:,:,g) = zero
      fluxm(:,:,:,:,g) = zero

      if ( multiswp == 1 ) nc_tot = nc_tot + nc

    END DO clean_loop
!_______________________________________________________________________
!
!   Single sweep, using non-blocking send, blocking receive. Each thread
!   initializes the reqs (send request) array for asynchronous sends.
!_______________________________________________________________________

    IF ( multiswp == 0 ) THEN

      CALL waitinit ( reqs, SIZE( reqs ) )
!_______________________________________________________________________
!
!     Loop over octant pairs; set the starting corner, i.e., the
!     direction in y and z. Spawn the nested threads if used.
!_______________________________________________________________________

      cor_loop: DO cor = 1, ncor

        jd = corner_sch(1,cor)
        kd = corner_sch(2,cor)
!_______________________________________________________________________
!
!       Loop over the groups assigned to each thread.
!_______________________________________________________________________

        grp_loop: DO n = 1, ng_per_thrd

          g = grp_act(n,t)
!_______________________________________________________________________
!
!         Sweep all the chunks of an octant pair (+/- x-dir).
!_______________________________________________________________________

          CALL octsweep ( g, jd, kd, t, reqs, SIZE( reqs ), 0, 1,      &
            nnstd_used )
!_______________________________________________________________________
!
!         End the loops. Destroy the task set.
!_______________________________________________________________________

        END DO grp_loop

      END DO cor_loop

    ELSE
!_______________________________________________________________________
!
!     Multiple, simultaneious sweeps from all starting corners, using
!     completely asynchronous sends and receives and tests to check
!     communication completeness.
!_______________________________________________________________________

      CALL waitinit ( reqr, SIZE( reqr ) )
      CALL waitinit ( reqs, SIZE( reqs ) )
      nulreq = reqs(1)

      nc_tot = nc_tot*2
      nstg = nc_tot + npey + npez - 2
!_______________________________________________________________________
!
!     Initialize all the counters that will control the concurrent
!     octant sweeps.
!
!     done(ncor)     - flag for when all groups done for a starting
!                      corner
!     callrecv(ncor) - which starting corner needs to call for another
!                      message
!     mtag(ncor)     - message tag for each starting corner
!     ic_op(ncor)    - chunk counter for each corner over octant-pair
!     gc(ncor)       - group corresponding to each starting corner
!     g_op(ncor)     - counter for each corner over octant-pair and
!                      all groups
!_______________________________________________________________________

      done     = .FALSE.
      callrecv = .TRUE.

      ic_op = 1
      gc    = 1
      g_op  = 1
!_______________________________________________________________________
!
!     If there are more threads than groups with work left to do, call
!     it done immediately.
!_______________________________________________________________________

      IF ( grp_act(1,t) == 0 ) done = .TRUE.
!_______________________________________________________________________
!
!     Loop over all chunks: all groups, all octants. Simultaneous sweeps
!     from starting corners (2 in 2D, 4 in 3D). Exit when all work done.
!_______________________________________________________________________

      done_loop: DO

        IF ( ALL( done ) ) EXIT
!_______________________________________________________________________
!
!       Call to non-blocking receive for the corner that has
!       callrecv=true: first pass that is all starting corners;
!       subsequent passes only one corner is true.
!_______________________________________________________________________

        CALL multiswp_recv_bdry ( jdim, kdim, ncor, ng, ic_op,         &
          grp_act(:,t), gc, callrecv, mtag, reqr, SIZE( reqr ), nang,  &
          ichunk, ny, nz, jb_in, kb_in )
!_______________________________________________________________________
!
!       Determine next corner to be swept according to available
!       message, safe buffer space, and remaining stages for given
!       direction.
!_______________________________________________________________________

        CALL multiswp_test_pick ( ncor, corner_loop_order, yzstg, nstg,&
          nulreq, g_op, reqr, SIZE( reqr ), done, reqs, SIZE( reqs ),  &
          cor )
!_______________________________________________________________________
!
!       Set up the sweep for this corner.
!_______________________________________________________________________

        g = grp_act(gc(cor),t)

        SELECT CASE ( cor )
          CASE ( 1 )
            jd = 1; kd = 1
          CASE ( 2 )
            jd = 2; kd = 1
          CASE ( 3 )
            jd = 1; kd = 2
          CASE ( 4 )
            jd = 2; kd = 2
        END SELECT
!_______________________________________________________________________
!
!       Sweep the task defined by the group, chunk, octant. Send the
!       outgoing data downstream.
!_______________________________________________________________________

        CALL octsweep ( g, jd, kd, 0, dummy, 2, ic_op(cor), cor, 0 )

        CALL multiswp_send_bdry ( ncor, jd, kd, nang, ichunk, ny, nz,  &
          mtag(cor), reqs(cor), reqs(ncor+cor), jb_out(:,:,:,cor,g),   &
          kb_out(:,:,:,cor,g) )
!_______________________________________________________________________
!
!       Increment the counters, and reset control variables.
!_______________________________________________________________________

        IF ( ic_op(cor) /= 2*nc ) THEN
          ic_op(cor) = ic_op(cor) + 1
        ELSE
          ic_op(cor) = 1
          gc(cor) = gc(cor) + 1
        END IF

        IF ( g_op(cor) /= nc_tot ) THEN
          g_op(cor) = g_op(cor) + 1
          callrecv(cor) = .TRUE.
        ELSE
          done(cor) = .TRUE.
        END IF
!_______________________________________________________________________
!
!     End loop over all operations. End multiswp selection.
!_______________________________________________________________________

      END DO done_loop

    END IF
!_______________________________________________________________________
!
!   Sum fixup count over corners (if multiswp is on). Calculate dummy
!   min and max scalar fluxes (not used elsewhere currently).
!_______________________________________________________________________

    edit_loop: DO n = 1, ng_per_thrd

      g = grp_act(n,t)
      IF ( g == 0 ) EXIT edit_loop

      IF ( multiswp == 1 ) fixup_counter(:,1,g) =                      &
                         fixup_counter(:,1,g) + fixup_counter(:,2,g) + &
                         fixup_counter(:,3,g) + fixup_counter(:,4,g)

      fmin(g) = MINVAL( flux0 )
      fmax(g) = MAXVAL( flux0 )

    END DO edit_loop
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE sweep


END MODULE sweep_module
