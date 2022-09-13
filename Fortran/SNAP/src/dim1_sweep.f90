!-----------------------------------------------------------------------
!
! MODULE: dim1_sweep_module
!> @brief
!> This module contains the 1D mesh sweep logic.
!
!-----------------------------------------------------------------------

MODULE dim1_sweep_module

  USE global_module, ONLY: i_knd, r_knd, zero, two, one, half

  USE geom_module, ONLY: nx, hi

  USE sn_module, ONLY: cmom, nang, mu, w

  USE data_module, ONLY: src_opt, qim

  USE control_module, ONLY: fixup, tolr, update_ptr, it_det

  USE plib_module, ONLY: ichunk

  IMPLICIT NONE

  PUBLIC :: dim1_sweep


  CONTAINS


  SUBROUTINE dim1_sweep ( id, d1, d2, d3, d4, oct, g, psii, qtot, ec,  &
    vdelt, ptr_in, ptr_out, dinv, flux0, fluxm, wmu, flkx, t_xs,       &
    fixup_counter )

!-----------------------------------------------------------------------
!
! 1-D slab mesh sweeper.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: id, d1, d2, d3, d4, oct, g

    REAL(r_knd), INTENT(IN) :: vdelt

    REAL(r_knd), DIMENSION(nang), INTENT(IN) :: wmu

    REAL(r_knd), DIMENSION(nang), INTENT(INOUT) :: psii

    REAL(r_knd), DIMENSION(nx), INTENT(IN) :: t_xs

    REAL(r_knd), DIMENSION(nx), INTENT(INOUT) :: flux0

    REAL(r_knd), DIMENSION(nx+1), INTENT(INOUT) :: flkx

    REAL(r_knd), DIMENSION(4), INTENT(INOUT) :: fixup_counter

    REAL(r_knd), DIMENSION(cmom,ichunk), INTENT(IN) :: qtot

    REAL(r_knd), DIMENSION(cmom-1,nx), INTENT(INOUT) :: fluxm

    REAL(r_knd), DIMENSION(nang,cmom), INTENT(IN) :: ec

    REAL(r_knd), DIMENSION(nang,ichunk), INTENT(IN) :: dinv

    REAL(r_knd), DIMENSION(d1,d2,d3,d4), INTENT(IN) :: ptr_in

    REAL(r_knd), DIMENSION(d1,d2,d3,d4), INTENT(OUT) :: ptr_out
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: ilo, ihi, ist, i, l

    REAL(r_knd) :: sum_hv

    REAL(r_knd), DIMENSION(nang) :: psi, pc, den

    REAL(r_knd), DIMENSION(nang,2) :: hv, fxhv

    REAL(r_knd), DIMENSION(nang,nx) :: qm
!_______________________________________________________________________
!
!   Set up the mms source if necessary.
!_______________________________________________________________________

    qm = zero
    IF ( src_opt == 3 ) qm = qim(:,:,1,1,oct,g)
!_______________________________________________________________________
!
!   Set up the sweep order in the i-direction. ilo here set according
!   to direction--different than ilo in octsweep. Setup the fixup
!   counter.
!_______________________________________________________________________

    IF ( id == 1 ) THEN
      ilo = nx; ihi = 1; ist = -1
    ELSE
      ilo = 1; ihi = nx; ist = 1
    END IF

    fxhv = zero
!_______________________________________________________________________
!
!   Sweep the i cells. Set the boundary condition.
!_______________________________________________________________________

    i_loop: DO i = ilo, ihi, ist

      IF ( i == ilo )  psii = zero
!_______________________________________________________________________
!
!     Compute the angular source. MMS source scales linearly with time.
!     Note that for 1-D ichunk=nx, so i index on qtot is ok.
!_______________________________________________________________________

      psi = qtot(1,i) + qm(:,i)

      DO l = 2, cmom
        psi = psi + ec(:,l)*qtot(l,i)
      END DO
!_______________________________________________________________________
!
!     Compute the numerator for the update formula
!_______________________________________________________________________

      pc = psi + psii*mu*hi
      IF ( vdelt /= zero ) pc = pc + vdelt*ptr_in(:,i,1,1)
!_______________________________________________________________________
!
!     Compute the solution of the center. Use DD for edges. Use fixup
!     if requested. Note for 1-D ichunk=nx, so i index of dinv is ok.
!_______________________________________________________________________

      IF ( fixup == 0 ) THEN

        psi = pc*dinv(:,i)

        psii = two*psi - psii
        IF ( vdelt/=zero .AND. update_ptr )                            &
          ptr_out(:,i,1,1) = two*psi - ptr_in(:,i,1,1)

      ELSE
!_______________________________________________________________________
!
!       Multi-pass set to zero + rebalance fixup. Determine angles that
!       will need fixup first.
!_______________________________________________________________________

        hv = one; sum_hv = SUM( hv )

        pc = pc * dinv(:,i)

        fixup_loop: DO

          fxhv(:,1) = two*pc - psii
          IF ( vdelt /= zero ) fxhv(:,2) = two*pc - ptr_in(:,i,1,1)

          WHERE ( fxhv < zero ) hv = zero
!_______________________________________________________________________
!
!         Exit loop when all angles are fixed up
!_______________________________________________________________________

          IF ( sum_hv == SUM( hv ) ) EXIT fixup_loop
          sum_hv = SUM( hv )
!_______________________________________________________________________
!
!         Recompute balance equation numerator and denominator and get
!         new cell average flux
!_______________________________________________________________________

          pc = psii*mu*hi*(one+hv(:,1))
          IF ( vdelt /= zero )                                         &
            pc = pc + vdelt*ptr_in(:,i,1,1)*(one+hv(:,2))
          pc = psi + half*pc

          den = t_xs(i) + mu*hi*hv(:,1) + vdelt*hv(:,2)

          WHERE( pc <= zero ) den = zero

          WHERE( den < tolr )
            pc = zero
            den = one
          END WHERE

          pc = pc / den

        END DO fixup_loop
!_______________________________________________________________________
!
!       Fixup done: update counts and compute edges with resolved center
!_______________________________________________________________________

        IF ( it_det == 1 ) THEN
          fixup_counter(1) = fixup_counter(1) + nang - SUM( HV(:,1) )
          IF ( vdelt /= zero )                                         &
            fixup_counter(4) = fixup_counter(4) + nang - SUM( HV(:,2) )
        END IF

        psi = pc

        psii = fxhv(:,1) * hv(:,1)
        IF ( vdelt/=zero .AND. update_ptr )                            &
          ptr_out(:,i,1,1) = fxhv(:,2) * hv(:,2)

      END IF
!_______________________________________________________________________
!
!     Compute the flux moments
!_______________________________________________________________________

      psi = w*psi

      flux0(i) = flux0(i) + SUM( psi )
      DO l = 1, cmom-1
        fluxm(l,i) = fluxm(l,i) + SUM( ec(:,l+1)*psi )
      END DO
!_______________________________________________________________________
!
!     Compute dummy leakages (not used elsewhere currently)
!_______________________________________________________________________

      flkx(i+id-1) = flkx(i+id-1) + ist*SUM( wmu*psii )
!_______________________________________________________________________
!
!     Finish the loop
!_______________________________________________________________________

    END DO i_loop
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE dim1_sweep


END MODULE dim1_sweep_module
