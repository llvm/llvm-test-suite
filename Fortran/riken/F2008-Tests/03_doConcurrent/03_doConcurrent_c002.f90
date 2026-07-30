! RUN: not %flang %s 2>&1 | FileCheck %s --check-prefix=FLANG
! RUN: not gfortran -std=f2008 %s 2>&1 | FileCheck %s --check-prefix=GFORT

! SPEC: F2008 C821

program main
  implicit none
  integer :: a(5) = [10,20,30,40,50]

  call sub(a)
  write(*,'(5(I4,1X))') a

contains
  subroutine sub(arr)
    integer, intent(out) :: arr(5)
    integer :: i, j

    outer: do i = 1, 5
      do concurrent (j = 1:5)
        cycle outer
        arr(j) = j * j
      end do
    end do outer
  end subroutine sub
end program main

! GFORT: 03_doConcurrent_c002.f90:20
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 03_doConcurrent_c002.f90:20
! FLANG-SAME: error:
