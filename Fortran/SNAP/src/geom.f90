!-----------------------------------------------------------------------
!
! MODULE: geom_module
!> @brief
!> This module contains the variables that relate to the geometry of the
!> problem and the subroutines necessary to allocate and deallocate
!> geometry related data as necessary.
!
!-----------------------------------------------------------------------

MODULE geom_module

  USE global_module, ONLY: i_knd, r_knd, zero, one, two

  IMPLICIT NONE

  PUBLIC

  SAVE
!_______________________________________________________________________
!
! Module Input Variables
!
! ndimen   - number of spatial dimensions 1/2/3
! nx       - number of x-dir spatial cells (global)
! ny       - number of y-dir spatial cells (global on input, reset to
!            per PE in setup)
! nz       - number of z-dir spatial cells (global on input, reset to
!            per PE in setup)
! lx       - total length of x domain
! ly       - total length of y domain
! lz       - total length of z domain
!_______________________________________________________________________

  INTEGER(i_knd) :: ndimen=1, nx=4, ny=1, nz=1

  REAL(r_knd) :: lx=one, ly=one, lz=one
!_______________________________________________________________________
!
! Run-time variables
!
! ny_gl    - global number of y-dir spatial cells
! nz_gl    - global number of z-dir spatial cells
! jlb      - global index of local lower y bound
! jub      - global index of local upper y bound
! klb      - global index of local lower z bound
! kub      - global index of local upper z bound
!
! dx       - x width of spatial cell
! dy       - y width of spatial cell
! dz       - z width of spatial cell
!
! nc       - number of i-chunks, nx/ichunk
!
! jdim     - number of directions to sweep in j-direction: 1D=1, else=2
! kdim     - number of directions to sweep in z-direction: 3D=2, else=1
!
! hi       - Spatial DD x-coefficient
! hj       - Spatial DD y-coefficient
! hk       - Spatial DD z-coefficient
!
! dinv(nang,ichunk,ny,nz,nc,ng) - Sweep denominator pre-computed
!
! ndiag    - number of diagonals of mini-KBA sweeps in nested threading
!_______________________________________________________________________

  INTEGER(i_knd) :: ny_gl, nz_gl, jlb, jub, klb, kub, nc, ndiag=0,     &
    jdim, kdim

  REAL(r_knd) :: dx, dy, dz, hi, hj, hk

  REAL(r_knd), ALLOCATABLE, DIMENSION(:,:,:,:,:,:) :: dinv
!_______________________________________________________________________
!
! Derived data types for mini-KBA diagonals
!
! cell_id_type      - type for holding ijk indices of a cell on a given
!                     diagonal
! ic, j, k          - ijk integer indices of cell_id_type
! diag_type         - type for holding diagonal information
! len               - number of cells on a diagonal line/plane
! cell_id(len)      - array of cell ijk indices
! diag(ndiag)       - array of diagonal lines/planes information
!_______________________________________________________________________

  TYPE cell_id_type
    INTEGER(i_knd) :: ic, j, k
  END TYPE cell_id_type

  TYPE diag_type
    INTEGER(i_knd) :: len
    TYPE(cell_id_type), ALLOCATABLE, DIMENSION(:) :: cell_id
  END TYPE diag_type

  TYPE(diag_type), ALLOCATABLE, DIMENSION(:) :: diag


  CONTAINS


  SUBROUTINE geom_allocate ( nang, ng, swp_typ, ichunk, ndpwds, ierr )

!-----------------------------------------------------------------------
!
! Allocate the geometry-related solution arrays. Setup the diag_type
! data structures for mini-KBA if requested.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: nang, ng, swp_typ, ichunk

    INTEGER(i_knd), INTENT(INOUT) :: ndpwds

    INTEGER(i_knd), INTENT(OUT) :: ierr
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: i, j, k, nn, ing

    INTEGER(i_knd), ALLOCATABLE, DIMENSION(:) :: indx
!_______________________________________________________________________

    ierr = 0

    ALLOCATE( dinv(nang,ichunk,ny,nz,nc,ng), STAT=ierr )
    IF ( ierr /= 0 ) RETURN

    hi = zero
    hj = zero
    hk = zero
    dinv = zero

    ndpwds = ndpwds + SIZE( dinv )
!_______________________________________________________________________
!
!   If mini-KBA on spatial chunks is selected, set up the diagonal
!   'diag' derived data type, allocate many diagonals, and set indices
!   for cells. Because each chunk is same size, can create just one.
!_______________________________________________________________________

    IF ( swp_typ == 1 ) THEN

      ndiag = ichunk + ny + nz - 2

      ALLOCATE( diag(ndiag), indx(ndiag), STAT=ierr )
      IF ( ierr /= 0 ) RETURN

      diag%len = 0
      indx = 0
!_______________________________________________________________________
!
!     Cells of same diagonal all have same value according to i+j+k-2
!     formula. Use that to compute len for each diagonal. Use ichunk.
!_______________________________________________________________________

      DO k = 1, nz
      DO j = 1, ny
      DO i = 1, ichunk
        nn = i + j + k - 2
        diag(nn)%len = diag(nn)%len + 1
      END DO
      END DO
      END DO
!_______________________________________________________________________
!
!     Next allocate cell_id array within diag type according to len
!_______________________________________________________________________

      DO nn = 1, ndiag
        ing = diag(nn)%len
        ALLOCATE( diag(nn)%cell_id(ing), STAT=ierr )
        IF ( ierr /= 0 ) RETURN
        ndpwds = ndpwds + SIZE( diag(nn)%cell_id )
      END DO
!_______________________________________________________________________
!
!     Lastly, set each cell's actual ijk indices in this diagonal map
!_______________________________________________________________________

      DO k = 1, nz
      DO j = 1, ny
      DO i = 1, ichunk
        nn = i + j + k - 2
        indx(nn) = indx(nn) + 1
        ing = indx(nn)
        diag(nn)%cell_id(ing)%ic = i
        diag(nn)%cell_id(ing)%j  = j
        diag(nn)%cell_id(ing)%k  = k
      END DO
      END DO
      END DO

      DEALLOCATE( indx )

    END IF
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE geom_allocate


  SUBROUTINE geom_deallocate ( swp_typ )

!-----------------------------------------------------------------------
!
! Deallocate the geometry-related solution arrays.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: swp_typ
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: i
!_______________________________________________________________________
!
!   Deallocate the sweep parameters
!_______________________________________________________________________

    DEALLOCATE( dinv )
!_______________________________________________________________________
!
!   Deallocate the diagonal related arrays with swp_typ
!_______________________________________________________________________

    IF ( swp_typ == 1 ) THEN
      DO i = 1, ndiag
        DEALLOCATE( diag(i)%cell_id )
      END DO
      DEALLOCATE( diag )
    END IF
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE geom_deallocate


  SUBROUTINE geom_param_calc ( nang, ichunk, mu, eta, xi, cs, vd, d )

!-----------------------------------------------------------------------
!
! Calculate the DD spatial coefficients hi, hj, hk for all angles at
! the start of each time step. Compute the pre-computed/inverted dinv.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: nang, ichunk

    REAL(r_knd), INTENT(IN) :: vd

    REAL(r_knd), DIMENSION(nang), INTENT(IN) :: mu, eta, xi

    REAL(r_knd), DIMENSION(nx,ny,nz), INTENT(IN) :: cs

    REAL(r_knd), DIMENSION(nang,ichunk,ny,nz,nc), INTENT(OUT) :: d
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: k, j, ii, ich, i, m
!_______________________________________________________________________
!
!   Set the DD coefficients
!_______________________________________________________________________

    hi = two/dx
    IF ( ndimen > 1 ) THEN
      hj = two/dy
      IF ( ndimen > 2 ) THEN
        hk = two/dz
      END IF
    END IF
!_______________________________________________________________________
!
!   Compute the inverted denominator, saved for sweep
!_______________________________________________________________________

    DO k = 1, nz
      DO j = 1, ny
        ii = 0
        ich = 1
        DO i = 1, nx
          ii = ii + 1
          DO m = 1, nang
            d(m,ii,j,k,ich) = one / ( cs(i,j,k) + vd + hi*mu(m) +      &
                                      hj*eta(m) + hk*xi(m) )
          END DO
          IF ( ii == ichunk ) THEN
            ii = 0
            ich = ich + 1
          END IF
        END DO
      END DO
    END DO
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE geom_param_calc


END MODULE geom_module
