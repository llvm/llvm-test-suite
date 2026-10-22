! RUN: not %flang %s 2>&1 | FileCheck %s --check-prefix=FLANG
! RUN: not gfortran -std=f2008 %s 2>&1 | FileCheck %s --check-prefix=GFORT

! SPEC: F2008 C826

program main
  use, intrinsic :: ieee_exceptions
  implicit none
  integer :: a(5) = [10,20,30,40,50]

  call sub(a)
  write(*,'(5(I4,1X))') a

contains
  subroutine sub(arr)
    integer, intent(out) :: arr(5)
    integer :: i
    logical :: flag

    do concurrent (i = 1:5)
      call ieee_get_halting_mode(ieee_divide_by_zero, flag)
      arr(i) = merge(i*i, -i, flag)
    end do
  end subroutine sub
end program main

! GFORT: 03_doConcurrent_c011.f90:21
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 03_doConcurrent_c011.f90:21
! FLANG-SAME: error:
