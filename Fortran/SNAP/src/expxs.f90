!-----------------------------------------------------------------------
!
! MODULE: expxs_module
!> @brief
!> This module contains the subroutines for expanding a cross section to
!> a full spatial map.
!
!-----------------------------------------------------------------------

MODULE expxs_module

  USE global_module, ONLY: i_knd, r_knd, zero

  USE geom_module, ONLY: nx, ny, nz

  USE sn_module, ONLY: nmom, cmom, lma

  USE data_module, ONLY: nmat

  IMPLICIT NONE

  PUBLIC

  INTERFACE expxs_reg
    MODULE PROCEDURE expxs_reg_1d, expxs_reg_3d
  END INTERFACE

  SAVE


  CONTAINS


  SUBROUTINE expxs_reg_1d ( xs, map, cs )

!-----------------------------------------------------------------------
!
! Expand one of the sig*(nmat,ng) arrays to a 1D spatial mapping. xs is
! a generic cross section array, map is the material map, and cs is the
! cross section expanded to the mesh.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), DIMENSION(nx), INTENT(IN) :: map

    REAL(r_knd), DIMENSION(nmat), INTENT(IN) :: xs

    REAL(r_knd), DIMENSION(nx), INTENT(OUT) :: cs
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: i
!_______________________________________________________________________

    DO i = 1, nx
      cs(i) = xs(map(i))
    END DO
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE expxs_reg_1d


  SUBROUTINE expxs_reg_3d ( xs, map, cs )

!-----------------------------------------------------------------------
!
! Expand one of the sig*(nmat,ng) arrays to a 3D spatial mapping. xs is
! a generic cross section array, map is the material map, and cs is the
! cross section expanded to the mesh.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), DIMENSION(nx,ny,nz), INTENT(IN) :: map

    REAL(r_knd), DIMENSION(nmat), INTENT(IN) :: xs

    REAL(r_knd), DIMENSION(nx,ny,nz), INTENT(OUT) :: cs
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: i, j, k
!_______________________________________________________________________

    DO k = 1, nz
      DO j = 1, ny
        DO i = 1, nx
          cs(i,j,k) = xs(map(i,j,k))
        END DO
      END DO
    END DO
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE expxs_reg_3d


  SUBROUTINE expxs_slgg ( scat, map, cs )

!-----------------------------------------------------------------------
!
! Expand the slgg(nmat,nmom,ng,ng) array to a 1D spatial mapping. scat
! is the slgg matrix for a single h->g group coupling, map is the
! material map, and cs is the scattering matrix expanded to the mesh.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), DIMENSION(nx), INTENT(IN) :: map

    REAL(r_knd), DIMENSION(nmat,nmom), INTENT(IN) :: scat

    REAL(r_knd), DIMENSION(cmom-1,nx), INTENT(OUT) :: cs
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: l, i, mom
!_______________________________________________________________________

    cs = zero

    DO i = 1, nx
      mom = 1
      DO l = 2, nmom
        cs(mom:mom+lma(l)-1,i) = scat(map(i),l)
        mom = mom + lma(l)
      END DO
    END DO
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE expxs_slgg


END MODULE expxs_module
