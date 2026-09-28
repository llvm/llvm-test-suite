! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 C1244

program main
  implicit none
  real :: arr(3)
  real, save :: seed = 12345.0
  integer :: i

  call random(arr)

  write(*,'(A,3F6.2)') "arr =", arr

contains
  impure pure elemental subroutine random(x)
    real, intent(out) :: x
    seed = mod(seed*3 + 1.0, 100.0)
    x = seed / 100.0
    write(*,'(A,F6.2)') "seed =", seed 
  end subroutine

end program

! GFORT: 36_pureProcExt_c001.f90:18:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 36_pureProcExt_c001.f90:17:
! FLANG-SAME: error:
