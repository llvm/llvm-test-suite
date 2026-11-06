! RUN: not %flang %s 2>&1 | FileCheck %s --check-prefix=FLANG
! RUN: not gfortran -std=f2008 %s 2>&1 | FileCheck %s --check-prefix=GFORT

! SPEC: F2008 C825

program main
  implicit none
  integer :: a(5) = [10,20,30,40,50]

  call sub(a)
  write(*,'(5(I4,1X))') a

contains
  subroutine sub(arr)
    integer, intent(out) :: arr(5)
    integer :: i
    real :: r

    do concurrent (i = 1:5)
      call random_number(r)
      arr(i) = int(r * 10.0)
    end do
  end subroutine sub
end program main


! GFORT: 03_doConcurrent_c008.f90:20
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 03_doConcurrent_c008.f90:20
! FLANG-SAME: error:
