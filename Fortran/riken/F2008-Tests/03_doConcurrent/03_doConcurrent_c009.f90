! RUN: not %flang %s 2>&1 | FileCheck %s --check-prefix=FLANG
! RUN: not gfortran -std=f2008 %s 2>&1 | FileCheck %s --check-prefix=GFORT

! SPEC: F2008 C825

program main
  implicit none
  integer :: a(5) = [10,20,30,40,50]

  call sub(a)
  write(*,'(5(I4,1X))') a

contains

  integer function impure_func(i)
    integer, intent(in) :: i
    print *, "side effect"
    impure_func = i * 2
  end function impure_func

  subroutine sub(arr)
    integer, intent(out) :: arr(5)
    integer :: i

    do concurrent (i = 1:5)
      arr(i) = impure_func(i)
    end do
  end subroutine sub
end program main


! GFORT: 03_doConcurrent_c009.f90:26
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 03_doConcurrent_c009.f90:26
! FLANG-SAME: error:
