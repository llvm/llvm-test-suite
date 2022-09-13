!-----------------------------------------------------------------------
!
! MODULE: mms_module
!> @brief
!> This module contains all the setup and verification subroutines for
!> code verification with MMS.
!
!-----------------------------------------------------------------------

MODULE mms_module

  USE global_module, ONLY: i_knd, r_knd, ounit, zero, pi, one, half

  USE geom_module, ONLY: nx, ny, nz, lx, ly, lz, dx, dy, dz, ndimen,   &
    ny_gl, nz_gl

  USE sn_module, ONLY: cmom, nang, mu, eta, xi, w, noct, ec, nmom, lma

  USE data_module, ONLY: src_opt, ng, sigt, slgg, qim, qi, mat, v

  USE control_module, ONLY: timedep, tf, dt, tolr

  USE plib_module, ONLY: yproc, zproc, iproc, root, glmax, glmin,      &
    comm_snap, glsum

  IMPLICIT NONE

  PRIVATE

  PUBLIC :: mms_setup, mms_deallocate, mms_verify_1

  SAVE
!_______________________________________________________________________
!
! Module variables
!
! ref_flux(nx,ny,nz,ng)          - Manufactured solution
! ref_fluxm(cmom-1,nx,ny,nz,ng)  - Manufactured solution moments
!
! a             - i function constant
! b             - j function constant
! c             - k function constant
!
! ib(nx+1)      - i cell boundaries
! jb(ny+1)      - j cell boundaries
! kb(nz+1)      - k cell boundaries
!
!_______________________________________________________________________

  REAL(r_knd) :: a, b, c

  REAL(r_knd), ALLOCATABLE, DIMENSION(:) :: ib, jb, kb

  REAL(r_knd), ALLOCATABLE, DIMENSION(:,:,:,:), PUBLIC :: ref_flux

  REAL(r_knd), ALLOCATABLE, DIMENSION(:,:,:,:,:), PUBLIC :: ref_fluxm

  
  CONTAINS


  SUBROUTINE mms_setup ( ierr, error )

!-----------------------------------------------------------------------
!
! This subroutine controls the MMS setup, including computing the MMS
! source and the reference solution for comparison with/verification of
! the SNAP-computed source
!
!-----------------------------------------------------------------------

    CHARACTER(LEN=64), INTENT(OUT) :: error

    INTEGER(i_knd), INTENT(OUT) :: ierr
!_______________________________________________________________________
!
!   Start by allocating the reference, manufactured solution
!_______________________________________________________________________

    ierr = 0
    error = ' '
    CALL mms_allocate ( ierr, error )
    CALL glmax ( ierr, comm_snap )
    IF ( ierr /= 0 ) THEN
      error = '***ERROR: MMS_ALLOCATE: Error allocating MMS arrays'
      RETURN
    END IF
!_______________________________________________________________________
!
!   Set up cell boundaries
!_______________________________________________________________________

    ib(1) = zero
    jb(1) = yproc*ny*dy
    kb(1) = zproc*nz*dz
    a = zero; b = zero; c = zero

    CALL mms_cells
!_______________________________________________________________________
!
!   Compute the cell-average manufactured solution according to src_opt.
!   Compute for tfinal if timedep==1
!
!   src_opt = 3 --> f = t*g * sin(pi*x/lx) * sin(pi*y/ly) * sin(pi*z/lz)
!
!   Then compute the static MMS source. Will apply time dependence
!   directly in dim#_sweep.
!_______________________________________________________________________

    IF ( src_opt == 3 ) THEN
      CALL mms_flux_1
      CALL mms_src_1
      IF ( timedep == 1 ) CALL mms_flux_1_2
    END IF
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE mms_setup


  SUBROUTINE mms_allocate ( ierr, error )

!-----------------------------------------------------------------------
!
! Allocate MMS arrays.
!
!-----------------------------------------------------------------------

    CHARACTER(LEN=64), INTENT(OUT) :: error

    INTEGER(i_knd), INTENT(OUT) :: ierr
!_______________________________________________________________________

    ierr = 0
    error = ' '

    ALLOCATE( ref_flux(nx,ny,nz,ng), ref_fluxm(cmom-1,nx,ny,nz,ng),    &
      STAT=ierr )
    IF ( ierr /= 0 ) RETURN

    ref_flux = zero
    ref_fluxm = zero

    ALLOCATE( ib(nx+1), jb(ny+1), kb(nz+1), STAT= ierr )
    IF ( ierr /= 0 ) RETURN

    ib = zero
    jb = zero
    kb = zero
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE mms_allocate


  SUBROUTINE mms_deallocate

!-----------------------------------------------------------------------
!
! Deallocate MMS arrays.
!
!-----------------------------------------------------------------------
!_______________________________________________________________________

    IF ( ALLOCATED( ref_flux ) ) DEALLOCATE( ref_flux )
    IF ( ALLOCATED( ref_fluxm ) ) DEALLOCATE( ref_fluxm )
    IF ( ALLOCATED( ib ) ) DEALLOCATE( ib )
    IF ( ALLOCATED( jb ) ) DEALLOCATE( jb )
    IF ( ALLOCATED( kb ) ) DEALLOCATE( kb )
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE mms_deallocate


  SUBROUTINE mms_cells

!-----------------------------------------------------------------------
!
! Compute and store the cell boundaries arrays
!
!-----------------------------------------------------------------------
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: i, j, k
!_______________________________________________________________________

    DO i = 1, nx
      ib(i+1) = ib(i) + dx
    END DO

    IF ( ndimen > 1 ) THEN

      DO j = 1, ny
        jb(j+1) = jb(j) + dy
      END DO
  
      IF ( ndimen > 2 ) THEN
        DO k = 1, nz
          kb(k+1) = kb(k) + dz
        END DO
      END IF

    END IF

    IF ( src_opt == 3 ) THEN
      a = pi/lx
      IF ( ndimen > 1 ) b = pi/ly
      IF ( ndimen > 2 ) c = pi/lz
    END IF
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE mms_cells


  SUBROUTINE mms_flux_1

!-----------------------------------------------------------------------
!
! Manufactured solution is
!   t*g * sin(pi*x/lx) * sin(pi*y/ly) * sin(pi*z/lz).
!
! Where t = 1 for static, g = 1 for one group, y and z terms dropped for
! 1-D. Compute the cell-average value for the static solution over all
! cells.
!
!-----------------------------------------------------------------------
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: i, j, k, g, l, n

    REAL(r_knd), DIMENSION(cmom-1) :: p

    REAL(r_knd), DIMENSION(nx) :: tx

    REAL(r_knd), DIMENSION(ny) :: ty

    REAL(r_knd), DIMENSION(nz) :: tz
!_______________________________________________________________________
!
!   Get all the integrations done by dimension separately
!_______________________________________________________________________

    CALL mms_trigint ( 'COS', nx, a, dx, ib, tx )
    IF ( ndimen > 1 ) THEN
      CALL mms_trigint ( 'COS', ny, b, dy, jb, ty )
      IF ( ndimen > 2 ) THEN
        CALL mms_trigint ( 'COS', nz, c, dz, kb, tz )
      ELSE
        tz = one
      END IF
    ELSE
      ty = one
      tz = one
    END IF
!_______________________________________________________________________
!
!   Combine all dimensions
!_______________________________________________________________________

    DO g = 1, ng
    DO k = 1, nz
    DO j = 1, ny
    DO i = 1, nx
      ref_flux(i,j,k,g) = REAL( g, r_knd) * tx(i) * ty(j) * tz(k)
    END DO
    END DO
    END DO
    END DO
!_______________________________________________________________________
!
!   Compute the angular coefficients for the moments
!_______________________________________________________________________

    p = zero
    DO n = 1, noct
      DO l = 1, cmom-1
        p(l) = p(l) + SUM( w*ec(:,l+1,n) )
      END DO
    END DO
!_______________________________________________________________________
!
!   Apply these coefficients to the angularly independent manufactured
!   solution to get the moments
!_______________________________________________________________________

    DO l = 1, cmom-1
      ref_fluxm(l,:,:,:,:) = p(l)*ref_flux
    END DO
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE mms_flux_1


  SUBROUTINE mms_trigint ( trig, lc, d, del, cb, fn )

!-----------------------------------------------------------------------
!
! Perform the loop to do trig function integration --> sin/cos terms
!
!-----------------------------------------------------------------------

    CHARACTER(LEN=3), INTENT(IN) :: trig

    INTEGER(i_knd), INTENT(IN) :: lc

    REAL(r_knd), INTENT(IN) :: d, del

    REAL(r_knd), DIMENSION(lc+1), INTENT(IN) :: cb

    REAL(r_knd), DIMENSION(lc), INTENT(OUT) :: fn
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: i
!_______________________________________________________________________
!
!   Do the integration, divide by delta and constant. In case of sine
!   the constant isn't needed because these are streaming terms.
!_______________________________________________________________________

    fn = zero

    IF ( trig == 'COS' ) THEN
      DO i = 1, lc
        fn(i) = COS( d*cb(i) ) - COS( d*cb(i+1) )
      END DO
      fn = fn / (d*del)
    ELSE IF ( trig == 'SIN' ) THEN
      DO i = 1, lc
        fn(i) = SIN( d*cb(i+1) ) - SIN( d*cb(i) )
      END DO
      fn = fn / (del)
    ELSE
      RETURN
    END IF
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE mms_trigint


  SUBROUTINE mms_src_1

!-----------------------------------------------------------------------
!
! Compute the MMS source for the manufactured solution above. Compute
! the source up to the number of moments specified by the user. The
! source must be the cell-average. Does not need to include the time
! coefficient, which is done in octsweep.
!
!-----------------------------------------------------------------------
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: i, j, k, g, m, gp, l, ll, lm, n, is, js, ks, id, &
      jd, kd

    REAL(r_knd), DIMENSION(nx) :: cx, sx

    REAL(r_knd), DIMENSION(ny) :: cy, sy

    REAL(r_knd), DIMENSION(nz) :: cz, sz
!_______________________________________________________________________
!
!   Get the needed integrations. Need both sine and cosine for each
!   dimension.
!_______________________________________________________________________

    CALL mms_trigint ( 'COS', nx, a, dx, ib, cx )
    CALL mms_trigint ( 'SIN', nx, a, dx, ib, sx )

    IF ( ndimen > 1 ) THEN

      CALL mms_trigint ( 'COS', ny, b, dy, jb, cy )
      CALL mms_trigint ( 'SIN', ny, b, dy, jb, sy )

      IF ( ndimen > 2 ) THEN
        CALL mms_trigint ( 'COS', nz, c, dz, kb, cz )
        CALL mms_trigint ( 'SIN', nz, c, dz, kb, sz )
      ELSE
        cz = one
        sz = zero
      END IF

    ELSE

      cy = one
      sy = zero
      cz = one
      sz = zero

    END IF
!_______________________________________________________________________
!
!   Start computing angular MMS source. Loop over dimensions according
!   to allocation. Start with total interaction and streaming terms.
!   Then loop over scattering terms. If threads are available, use them
!   on this larger group loop to help speed up job.
!_______________________________________________________________________

  !$OMP PARALLEL DO SCHEDULE(DYNAMIC,1) DEFAULT(SHARED)                &
  !$OMP& PRIVATE(g,kd,ks,jd,js,id,is,n,k,j,i,m,gp,lm,l,ll)
    DO g = 1, ng
      DO kd = 1, MAX( ndimen-1, 1 )
        ks = -one
        IF ( kd == 2 ) ks = one
        DO jd = 1, MIN( ndimen, 2 )
          js = -one
          IF ( jd == 2 ) js = one
          DO id = 1, 2
            is = -one
            IF ( id == 2 ) is = one
            n = 4*(kd - 1) + 2*(jd - 1) + id
            DO k = 1, nz
            DO j = 1, ny
            DO i = 1, nx
              DO m = 1, nang
                qim(m,i,j,k,n,g) = qim(m,i,j,k,n,g) +                  &
                  REAL( g, r_knd ) * is*mu(m)*sx(i)*cy(j)*cz(k) +      &
                    sigt(mat(i,j,k),g)*ref_flux(i,j,k,g)
                IF ( ndimen > 1 ) THEN
                  qim(m,i,j,k,n,g) = qim(m,i,j,k,n,g) +                &
                    REAL( g, r_knd ) * js*eta(m)*cx(i)*sy(j)*cz(k)
                END IF
                IF ( ndimen > 2 ) THEN
                  qim(m,i,j,k,n,g) = qim(m,i,j,k,n,g) +                &
                    REAL( g, r_knd ) * ks*xi(m)*cx(i)*cy(j)*sz(k)
                END IF
                DO gp = 1, ng
                  qim(m,i,j,k,n,g) = qim(m,i,j,k,n,g) -                &
                    slgg(mat(i,j,k),1,gp,g) * ref_flux(i,j,k,gp)
                  lm = 2
                  DO l = 2, nmom
                    DO ll = 1, lma(l)
                      qim(m,i,j,k,n,g) = qim(m,i,j,k,n,g) - ec(m,lm,n)*&
                        slgg(mat(i,j,k),l,gp,g)*ref_fluxm(lm-1,i,j,k,g)
                      lm = lm + 1
                    END DO
                  END DO
                END DO
              END DO
            END DO
            END DO
            END DO
          END DO
        END DO
      END DO
    END DO
  !$OMP END PARALLEL DO
!_______________________________________________________________________
!
!   Time-dependent problems have a time-independent source term that
!   can be stored in qi.
!_______________________________________________________________________

    IF ( timedep == 1 ) THEN
      DO g = 1, ng
        qi(:,:,:,g) = ref_flux(:,:,:,g) / v(g)
      END DO
    END IF
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE mms_src_1


  SUBROUTINE mms_flux_1_2

!-----------------------------------------------------------------------
!
! Now that static source is computed, can scale reference solution to
! that of final time step. (Source is linearly scaled in time in
! octsweep.)
!-----------------------------------------------------------------------
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    REAL(r_knd) :: t
!_______________________________________________________________________
!
!   Compute the time at final time step center. Multiply with ref_flux.
!   No need for ref_fluxm since only ref_flux is checked in mms_verify.
!_______________________________________________________________________

    t = tf - half*dt
    ref_flux = t*ref_flux
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE mms_flux_1_2


  SUBROUTINE mms_verify_1 ( flux )

!-----------------------------------------------------------------------
!
! Verify the final solution is near the reference solution.
!
!-----------------------------------------------------------------------

    REAL(r_knd), DIMENSION(nx,ny,nz,ng), INTENT(IN) :: flux
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    CHARACTER(LEN=1) :: star='*'

    INTEGER(i_knd) :: i

    REAL(r_knd) :: dfmx, dfmn, dfsm

    REAL(r_knd), DIMENSION(nx,ny,nz,ng) :: df
!_______________________________________________________________________

    df = one
    WHERE( ABS( ref_flux ) < tolr )
      ref_flux = one
      df = zero
    END WHERE
    df = ABS( flux/ref_flux - df )

    dfmx = MAXVAL( df )
    CALL glmax ( dfmx, comm_snap )

    dfmn = MINVAL( df )
    CALL glmin ( dfmn, comm_snap )

    dfsm = SUM( df )
    CALL glsum ( dfsm, comm_snap )
    dfsm = dfsm / REAL( nx*ny_gl*nz_gl*ng )

    IF ( iproc == root ) THEN
      WRITE( ounit, 421 ) ( star, i = 1, 80 )
      WRITE( ounit, 422 ) dfmx
      WRITE( ounit, 425 ) dfmn
      WRITE( ounit, 426 ) dfsm
      WRITE( ounit, 428 ) ( star, i = 1, 80 )
    END IF
!_______________________________________________________________________

    421 FORMAT( 10X, 'MMS Verification', /, 80A )
    422 FORMAT( /, 4X, 'Manufactured/Computed Solutions Max Diff=',    &
                 ES13.6 )
    425 FORMAT( /, 4X, 'Manufactured/Computed Solutions Min Diff=',    &
                 ES13.6 )
    426 FORMAT( /, 4X, 'Manufactured/Computed Solutions Avg Diff=',    &
                 ES13.6 )
    428 FORMAT( /, 80A, / )
!_______________________________________________________________________

  END SUBROUTINE mms_verify_1


END MODULE mms_module
