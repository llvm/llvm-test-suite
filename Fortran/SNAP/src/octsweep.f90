!-----------------------------------------------------------------------
!
! MODULE: octsweep_module
!> @brief
!> This module controls the setup and calls for sweeping a single octant
!> pair. It calls for the actual sweep logic depending on the spatial
!> dimensionality of the problem.
!
!-----------------------------------------------------------------------

MODULE octsweep_module

  USE global_module, ONLY: i_knd

  USE geom_module, ONLY: nc, ndimen, dinv, nx, ny, nz

  USE sn_module, ONLY: ec, nang, wmu, weta, wxi, noct

  USE data_module, ONLY: vdelt, ng

  USE control_module, ONLY: timedep, swp_typ, multiswp

  USE solvar_module, ONLY: psii, qtot, ptr_in, ptr_out, psij, psik,    &
    flux0, fluxm, jb_in, jb_out, kb_in, kb_out, fixup_counter, flkx,   &
    flky, flkz, t_xs

  USE thrd_comm_module, ONLY: no_op_lock_control

  USE dim1_sweep_module, ONLY: dim1_sweep

  USE dim3_sweep_module, ONLY: dim3_sweep

  USE mkba_sweep_module, ONLY: mkba_sweep

  IMPLICIT NONE

  PUBLIC :: octsweep


  CONTAINS


  SUBROUTINE octsweep ( g, jd, kd, t, reqs, szreq, ic_op, cor,         &
    nnstd_used )

!-----------------------------------------------------------------------
!
! Call for the appropriate sweeper depending on the dimensionality. Let
! the actual sweep routine know the octant info to get the order right.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: g, jd, kd, t, szreq, ic_op, cor,     &
      nnstd_used

    INTEGER(i_knd), DIMENSION(szreq), INTENT(INOUT) :: reqs
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: iop, d1, d2, d3, d4, d5, d6, id, oct, ich, llim, &
      ulim
!_______________________________________________________________________
!
!   If g=0, this thread has no work to do, but it cannot exit sweeps
!   immediately, because it must properly set it's own lock and unset
!   the subsequent thread's lock. Call for no-op controls. Note that
!   this is a nested threaded region, so master refers to the nested
!   threads. All main level threads will do this.
!_______________________________________________________________________

    IF ( g == 0 ) THEN
      DO iop = 1, 2*nc
        CALL no_op_lock_control ( t )
        CALL no_op_lock_control ( t )
      END DO
      RETURN
    END IF
!_______________________________________________________________________
!
!   Set ptr_in and ptr_out dimensions dependent on timedep because they
!   are not allocated if static problem.
!_______________________________________________________________________

    d1 = 0; d2 = 0; d3 = 0; d4 = 0; d5 = 0; d6 = 0
    IF ( timedep == 1 ) THEN
      d1 = nang; d2 = nx; d3 = ny; d4 = nz; d5 = noct; d6 = g
    END IF
!_______________________________________________________________________
!
!   For swp_typ=0 order, set the iop here and call for the sweep of
!   that chunk. Loop contains twice the number of chunks: half for
!   negative x-dir sweep, half for positive x-dir sweep.
!_______________________________________________________________________

    IF ( swp_typ == 0 ) THEN
!_______________________________________________________________________
!
!     For multiswp=0, set loops over all the chunks in the x-domain,
!     including the octant pair. Otherwise, multiswp scheduling handles
!     sweeping all chunks.
!_______________________________________________________________________

      IF ( multiswp == 0 ) THEN
        llim = 1; ulim = 2*nc
      ELSE
        llim = ic_op; ulim = ic_op
      END IF

      iop_loop: DO iop = llim, ulim
!_______________________________________________________________________
!
!       Determine octant and chunk index.
!_______________________________________________________________________

        id = 1 + (iop-1)/nc
        oct = id + 2*(jd - 1) + 4*(kd - 1)

        IF ( id == 1 ) THEN
          ich = nc - iop + 1
        ELSE
          ich = iop - nc
        END IF

        IF ( timedep == 1 ) d5 = oct
!_______________________________________________________________________
!
!       Call 1-D or multi-D sweeper.
!_______________________________________________________________________

        IF ( ndimen == 1 ) THEN

          CALL dim1_sweep ( id, d1, d2, d3, d4, oct, g,                &
            psii(:,1,1,cor,g), qtot(:,:,1,1,ich,g), ec(:,:,oct),       &
            vdelt(g), ptr_in(:,:,:,:,d5,d6), ptr_out(:,:,:,:,d5,d6),   &
            dinv(:,:,1,1,ich,g), flux0(:,1,1,g), fluxm(:,:,1,1,g),     &
            wmu, flkx(:,1,1,g), t_xs(:,1,1,g), fixup_counter(:,cor,g) )

        ELSE

          CALL dim3_sweep ( ich, id, d1, d2, d3, d4, jd, kd, oct, g,   &
            t, iop, reqs, szreq, psii(:,:,:,cor,g), psij(:,:,:,g),     &
            psik(:,:,:,g), qtot(:,:,:,:,ich,g), ec(:,:,oct),           &
            vdelt(g), ptr_in(:,:,:,:,d5,d6), ptr_out(:,:,:,:,d5,d6),   &
            dinv(:,:,:,:,ich,g), flux0(:,:,:,g), fluxm(:,:,:,:,g),     &
            jb_in(:,:,:,cor,g), jb_out(:,:,:,cor,g),                   &
            kb_in(:,:,:,cor,g), kb_out(:,:,:,cor,g), wmu, weta, wxi,   &
            flkx(:,:,:,g), flky(:,:,:,g), flkz(:,:,:,g), t_xs(:,:,:,g),&
            fixup_counter(:,cor,g) )

        END IF

      END DO iop_loop
!_______________________________________________________________________
!
!   Use the mini-kba swp_typ=1 sweeper that self-contains iop loop.
!_______________________________________________________________________

    ELSE

      CALL mkba_sweep ( d1, d2, d3, d4, d5, jd, kd, g, t, nnstd_used,  &
        reqs, szreq, psii(:,:,:,cor,g), psij(:,:,:,g), psik(:,:,:,g),  &
        qtot(:,:,:,:,:,g), ec, vdelt(g), ptr_in(:,:,:,:,:,d6),         &
        ptr_out(:,:,:,:,:,d6),  dinv(:,:,:,:,:,g), flux0(:,:,:,g),     &
        fluxm(:,:,:,:,g), jb_in(:,:,:,cor,g), jb_out(:,:,:,cor,g),     &
        kb_in(:,:,:,cor,g), kb_out(:,:,:,cor,g), wmu, weta, wxi,       &
        flkx(:,:,:,g), flky(:,:,:,g), flkz(:,:,:,g), t_xs(:,:,:,g),    &
        fixup_counter(:,cor,g) )

    END IF
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE octsweep


END MODULE octsweep_module
