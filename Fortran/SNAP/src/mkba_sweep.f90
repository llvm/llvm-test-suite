!-----------------------------------------------------------------------
!
! MODULE: mkba_sweep_module
!> @brief
!> This module contains the 2D and 3D mesh sweep logic using mini-KBA.
!
!-----------------------------------------------------------------------

MODULE mkba_sweep_module

  USE global_module, ONLY: i_knd, r_knd, zero, two, one, half

  USE plib_module, ONLY: ichunk, firsty, lasty, firstz, lastz,         &
    nnested

  USE geom_module, ONLY: nx, hi, hj, hk, ndimen, ny, nz, ndiag, diag, nc

  USE sn_module, ONLY: cmom, nang, mu, eta, xi, w, noct

  USE data_module, ONLY: src_opt, qim

  USE control_module, ONLY: fixup, tolr, update_ptr, angcpy, it_det

  USE thrd_comm_module, ONLY: sweep_recv_bdry, sweep_send_bdry

  IMPLICIT NONE

  PUBLIC :: mkba_sweep


  CONTAINS


  SUBROUTINE mkba_sweep ( d1, d2, d3, d4, d5, jd, kd, g, t, nnstd_used,&
    reqs, szreq, psii, psij, psik, qtot, ec, vdelt, ptr_in, ptr_out,   &
    dinv, flux0, fluxm, jb_in, jb_out, kb_in, kb_out, wmu, weta, wxi,  &
    flkx, flky, flkz, t_xs, fixup_counter )

!-----------------------------------------------------------------------
!
! 3-D slab mesh sweeper.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: d1, d2, d3, d4, d5, jd, kd, g, t,    &
      nnstd_used, szreq

    INTEGER(i_knd), DIMENSION(szreq), INTENT(INOUT) :: reqs

    REAL(r_knd), INTENT(IN) :: vdelt

    REAL(r_knd), DIMENSION(nang), INTENT(IN) :: wmu, weta, wxi

    REAL(r_knd), DIMENSION(4), INTENT(INOUT) :: fixup_counter

    REAL(r_knd), DIMENSION(nang,cmom,noct), INTENT(IN) :: ec

    REAL(r_knd), DIMENSION(nang,ny,nz), INTENT(INOUT) :: psii

    REAL(r_knd), DIMENSION(nang,ichunk,nz), INTENT(INOUT) :: psij,     &
      jb_in, jb_out

    REAL(r_knd), DIMENSION(nang,ichunk,ny), INTENT(INOUT) :: psik,     &
      kb_in, kb_out

    REAL(r_knd), DIMENSION(nx,ny,nz), INTENT(IN) :: t_xs

    REAL(r_knd), DIMENSION(nx,ny,nz), INTENT(INOUT) :: flux0

    REAL(r_knd), DIMENSION(nx+1,ny,nz), INTENT(INOUT) :: flkx

    REAL(r_knd), DIMENSION(nx,ny+1,nz), INTENT(INOUT) :: flky

    REAL(r_knd), DIMENSION(nx,ny,nz+1), INTENT(INOUT) :: flkz

    REAL(r_knd), DIMENSION(nang,ichunk,ny,nz,nc), INTENT(IN) :: dinv

    REAL(r_knd), DIMENSION(cmom-1,nx,ny,nz), INTENT(INOUT) :: fluxm

    REAL(r_knd), DIMENSION(cmom,ichunk,ny,nz,nc), INTENT(IN) :: qtot

    REAL(r_knd), DIMENSION(d1,d2,d3,d4,d5), INTENT(INOUT) :: ptr_in

    REAL(r_knd), DIMENSION(d1,d2,d3,d4,d5), INTENT(OUT) :: ptr_out
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: nedg, ist, jst, jlo, jhi, kst, klo, khi, d, n,   &
      ic, i, j, k, l, iop, ich, id, oct, ibl, ibr, ibb, ibt, ibf, ibk

    REAL(r_knd) :: sum_hv, sum_hv_n

    REAL(r_knd), DIMENSION(nang) :: psi, pc, den

    REAL(r_knd), DIMENSION(nang,4) :: hv, fxhv
!_______________________________________________________________________
!
!   Initialize the fixup counter
!_______________________________________________________________________

    nedg = 2
    IF ( ndimen == 3 ) nedg = 3
    IF ( vdelt /= zero ) nedg = nedg + 1
    fxhv = zero
!_______________________________________________________________________
!
!   Set up the y-dir and z-dir sweep order given octant info.
!_______________________________________________________________________

    IF ( jd == 1 ) THEN
      jst = -1; jlo = ny; jhi = 1
    ELSE
      jst = +1; jlo = 1; jhi = ny
    END IF

    IF ( kd == 1 ) THEN
      kst = -1; klo = nz; khi = 1
    ELSE
      kst = +1; klo = 1; khi = nz
    END IF
!_______________________________________________________________________
!
!   Loop over the spatial work chunks in +/- x-directions.
!_______________________________________________________________________

    iop_loop: DO iop = 1, 2*nc
!_______________________________________________________________________
!
!     Determine chunk index, octant, and finish setting up sweep order.
!_______________________________________________________________________

      id = 1 + (iop - 1)/nc
      oct = id + 2*(jd - 1) + 4*(kd - 1)

      IF ( id == 1 ) THEN
        ich = nc - iop + 1
        ist = -1
      ELSE
        ich = iop - nc
        ist = +1
      END IF
!_______________________________________________________________________
!
!     Process boundaries in y- and z-directions come from preset
!     boundary conditions (vacuum) or from upstream neighbors. Must call
!     to receive any data. If upstream is boundary, no communication.
!     The master of the nested threaded region calls; i.e., all main
!     level threads.
!_______________________________________________________________________

      CALL sweep_recv_bdry ( g, jd, kd, iop, t, reqs, szreq, nc, nang, &
        ichunk, ny, nz, jb_in, kb_in )
!_______________________________________________________________________
!
!     Loop over cells along the diagonals. Nested threads break up each
!     diagonal's work.
!_______________________________________________________________________

      diagonal_loop: DO d = 1, ndiag

  !$OMP PARALLEL DO NUM_THREADS(nnstd_used) IF(nnstd_used>1)           &
  !$OMP& SCHEDULE(STATIC,1) PROC_BIND(CLOSE)  DEFAULT(SHARED)          &
  !$OMP& PRIVATE(n,ic,i,j,k,l,psi,pc,hv,sum_hv,fxhv,sum_hv_n,den)
        line_loop: DO n = 1, diag(d)%len
!_______________________________________________________________________
!
!         Set the indices chunk indices and the global i index
!_______________________________________________________________________

          ic = diag(d)%cell_id(n)%ic
          IF ( ist < 0 ) ic = ichunk - ic + 1

          i = (ich-1)*ichunk + ic

          j = diag(d)%cell_id(n)%j
          IF ( jst < 0 ) j = ny - j + 1

          k = diag(d)%cell_id(n)%k
          IF ( kst < 0 ) k = nz - k + 1
!_______________________________________________________________________
!
!         Dummy operation to match real transport code where nx is not
!         always even divided by ichunk
!_______________________________________________________________________

          IF ( i > nx ) THEN
            jb_out(:,ic,k) = zero
            kb_out(:,ic,j) = zero
            CYCLE line_loop
          END IF
!_______________________________________________________________________
!
!         Compute the angular source. Add the MMS contribution if
!         necessary.
!_______________________________________________________________________

          psi = qtot(1,ic,j,k,ich)

          DO l = 2, cmom
  !DIR$ VECTOR ALIGNED
            psi = psi + ec(:,l,oct)*qtot(l,ic,j,k,ich)
          END DO

          IF ( src_opt == 3 ) psi = psi + qim(:,i,j,k,oct,g)
!_______________________________________________________________________
!
!         Left/right boundary conditions, always vacuum. Dummy
!         operations may be ignored.
!_______________________________________________________________________

          ibl = 0
          ibr = 0
          IF ( i==nx .AND. ist==-1 ) THEN
            psii(:,j,k) = zero
          ELSE IF ( i==1 .AND. ist==1 ) THEN
            SELECT CASE ( ibl )
              CASE ( 0 )
                psii(:,j,k) = zero
              CASE ( 1 )
                psii(:,j,k) = zero
            END SELECT
          END IF
!_______________________________________________________________________
!
!         Top/bottom boundary condtions for chunk. Either received from
!         upstream neighbor or set to zero (always vacuum) if no
!         upstream neighbor.
!_______________________________________________________________________

          ibb = 0
          ibt = 0
          IF ( j == jlo ) THEN
            IF ( jd==1 .AND. lasty ) THEN
              psij(:,ic,k) = zero
            ELSE IF ( jd==2 .AND. firsty ) THEN
              SELECT CASE ( ibb )
                CASE ( 0 )
                  psij(:,ic,k) = zero
                CASE ( 1 )
                  psij(:,ic,k) = zero
              END SELECT
            ELSE
              psij(:,ic,k) = jb_in(:,ic,k)
            END IF
          END IF
!_______________________________________________________________________
!
!         Front/back boundary condtions. Vacuum at global boundaries,
!         but set to some incoming flux from neighboring proc.
!_______________________________________________________________________

          ibf = 0
          ibk = 0
          IF ( k == klo ) THEN
            IF ( (kd==1 .AND. lastz) .OR. ndimen<3 ) THEN
              psik(:,ic,j) = zero
            ELSE IF ( kd==2 .AND. firstz ) THEN
              SELECT CASE ( ibf )
                CASE ( 0 )
                  psik(:,ic,j) = zero
                CASE ( 1 )
                  psik(:,ic,j) = zero
              END SELECT
            ELSE
              psik(:,ic,j) = kb_in(:,ic,j)
            END IF
          END IF
!_______________________________________________________________________
!
!         Compute the initial solution
!_______________________________________________________________________

          IF ( vdelt /= zero ) THEN
  !DIR$ VECTOR ALIGNED
            pc = ( psi + psii(:,j,k)*mu*hi + psij(:,ic,k)*eta*hj +     &
                   psik(:,ic,j)*xi*hk + ptr_in(:,i,j,k,oct)*vdelt ) *  &
                   dinv(:,ic,j,k,ich)
          ELSE
  !DIR$ VECTOR ALIGNED
            pc = ( psi + psii(:,j,k)*mu*hi + psij(:,ic,k)*eta*hj +     &
              psik(:,ic,j)*xi*hk ) * dinv(:,ic,j,k,ich)
          END IF
!_______________________________________________________________________
!
!         Compute outgoing edges with diamond difference, no negative
!         flux fixup
!_______________________________________________________________________

          IF ( fixup == 0 ) THEN
 
            psi = pc

            psii(:,j,k) = two*psi - psii(:,j,k)
            psij(:,ic,k) = two*psi - psij(:,ic,k)
            IF ( ndimen == 3 ) psik(:,ic,j) = two*psi - psik(:,ic,j)
            IF ( vdelt/=zero .AND. update_ptr ) THEN
              IF ( angcpy == 1 ) THEN
                ptr_in(:,i,j,k,oct) = two*psi - ptr_in(:,i,j,k,oct)
              ELSE
                ptr_out(:,i,j,k,oct) = two*psi - ptr_in(:,i,j,k,oct)
              END IF
            END IF

          ELSE
!_______________________________________________________________________
!
!           Use negative flux fixup. Compute outgoing edges. If
!           negative, set to zero and rebalance. Multi-pass until all
!           negativities eliminated. Initialize counters and determine
!           angles that will need fixup first.
!_______________________________________________________________________

            hv = one
            sum_hv = nedg * nang

            fixup_loop: DO

              fxhv(:,1) = two*pc - psii(:,j,k)
              WHERE( fxhv(:,1) < zero ) hv(:,1) = zero
              sum_hv_n = SUM( hv(:,1) )

              fxhv(:,2) = two*pc - psij(:,ic,k)
              WHERE( fxhv(:,2) < zero ) hv(:,2) = zero
              sum_hv_n = sum_hv_n + SUM( hv(:,2) )

              IF ( ndimen == 3 ) THEN
                fxhv(:,3) = two*pc - psik(:,ic,j)
                WHERE( fxhv(:,3) < zero ) hv(:,3) = zero
                sum_hv_n = sum_hv_n + SUM( hv(:,3) )
              END IF

              IF ( vdelt /= zero ) THEN
                fxhv(:,4) = two*pc - ptr_in(:,i,j,k,oct)
                WHERE( fxhv(:,4) < zero ) hv(:,4) = zero
                sum_hv_n = sum_hv_n + SUM( hv(:,4) )
              END IF
!_______________________________________________________________________
!
!             Exit loop when all angles are fixed up, i.e., no hv change
!_______________________________________________________________________

              IF ( sum_hv == sum_hv_n ) EXIT fixup_loop
              sum_hv = sum_hv_n
!_______________________________________________________________________
!
!             Recompute balance equation numerator and denominator and
!             get new cell average flux
!_______________________________________________________________________

              IF ( vdelt /= zero ) THEN
                pc = psi + half * ( psii(:,j,k)*mu*hi*(one+hv(:,1)) +  &
                                    psij(:,ic,k)*eta*hj*(one+hv(:,2)) +&
                                    psik(:,ic,j)*xi*hk*(one+hv(:,3)) + &
                               ptr_in(:,i,j,k,oct)*vdelt*(one+hv(:,4)) )
                den = t_xs(i,j,k) + mu*hi*hv(:,1) + eta*hj*hv(:,2) +   &
                  xi*hk*hv(:,3) + vdelt*hv(:,4)
              ELSE
                pc = psi + half * ( psii(:,j,k)*mu*hi*(one+hv(:,1)) +  &
                                    psij(:,ic,k)*eta*hj*(one+hv(:,2)) +&
                                    psik(:,ic,j)*xi*hk*(one+hv(:,3)) )
                den = t_xs(i,j,k) + mu*hi*hv(:,1) + eta*hj*hv(:,2) +   &
                  xi*hk*hv(:,3)
              END IF

              WHERE( pc <= zero ) den = zero

              WHERE( den < tolr )
                pc = zero
                den = one
              END WHERE

              pc = pc / den

            END DO fixup_loop
!_______________________________________________________________________
!
!           Fixup done: update counts and compute edges with resolved
!           center
!_______________________________________________________________________

            IF ( it_det == 1 ) THEN
             fixup_counter(1) = fixup_counter(1) + nang - SUM( HV(:,1) )
             fixup_counter(2) = fixup_counter(2) + nang - SUM( HV(:,2) )
             IF ( ndimen == 3 ) fixup_counter(3) =                     &
                                fixup_counter(3) + nang - SUM( HV(:,3) )
             IF ( vdelt/=zero ) fixup_counter(4) =                     &
                                fixup_counter(4) + nang - SUM( HV(:,4) )
            END IF

            psi = pc

            psii(:,j,k) = fxhv(:,1) * hv(:,1)
            psij(:,ic,k) = fxhv(:,2) * hv(:,2)
            IF ( ndimen == 3 ) psik(:,ic,j) = fxhv(:,3) * hv(:,3)
            IF ( vdelt/=zero .AND. update_ptr ) THEN
              IF ( angcpy == 1 ) THEN
                ptr_in(:,i,j,k,oct) = fxhv(:,4) * hv(:,4)
              ELSE
                ptr_out(:,i,j,k,oct) = fxhv(:,4) * hv(:,4)
              END IF
            END IF

          END IF
!_______________________________________________________________________
!
!         Save edge fluxes (dummy if checks for unused non-vacuum BCs)
!_______________________________________________________________________

          IF ( j == jhi ) THEN
            IF ( jd==2 .AND. lasty ) THEN
              CONTINUE
            ELSE IF ( jd==1 .AND. firsty ) THEN
              IF ( ibb == 1 ) CONTINUE
            ELSE
              jb_out(:,ic,k) = psij(:,ic,k)
            END IF
          END IF

          IF ( k == khi ) THEN
            IF ( kd==2 .AND. lastz ) THEN
              CONTINUE
            ELSE IF ( kd==1 .AND. firstz ) THEN
              IF ( ibf == 1 ) CONTINUE
            ELSE
              kb_out(:,ic,j) = psik(:,ic,j)
            END IF
          END IF
!_______________________________________________________________________
!
!         Compute dummy leakages (not used elsewhere currently)
!_______________________________________________________________________

          flkx(i+id-1,j,k) = flkx(i+id-1,j,k) +                        &
                             ist*SUM( wmu*psii(:,j,k) )
          flky(i,j+jd-1,k) = flky(i,j+jd-1,k) +                        &
                             jst*SUM( weta*psij(:,ic,k) )
          flkz(i,j,k+kd-1) = flkz(i,j,k+kd-1) +                        &
                             kst*SUM( wxi*psik(:,ic,j) )
!_______________________________________________________________________
!
!         Compute the flux moments
!_______________________________________________________________________

          psi = w*psi

          flux0(i,j,k) = flux0(i,j,k) + SUM( psi )
          DO l = 1, cmom-1
            fluxm(l,i,j,k) = fluxm(l,i,j,k) + SUM( ec(:,l+1,oct)*psi )
          END DO
!_______________________________________________________________________
!
!         Finish the loops
!_______________________________________________________________________

        END DO line_loop
  !$OMP END PARALLEL DO

      END DO diagonal_loop
!_______________________________________________________________________
!
!     Send data to downstream neighbors. Master of threaded region means
!     all main level threads do call for send.
!_______________________________________________________________________

      CALL sweep_send_bdry ( g, jd, kd, iop, t, reqs, szreq, nc, nang, &
        ichunk, ny, nz, jb_out, kb_out )
!_______________________________________________________________________
!
!   Close the chunks loop
!_______________________________________________________________________

    END DO iop_loop
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE mkba_sweep


END MODULE mkba_sweep_module
