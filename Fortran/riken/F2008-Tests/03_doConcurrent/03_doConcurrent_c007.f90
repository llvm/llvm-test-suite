! RUN: not %flang %s 2>&1 | FileCheck %s --check-prefix=FLANG
! RUN: not gfortran -std=f2008 -w %s 2>&1 | FileCheck %s --check-prefix=GFORT

! SPEC: F2008 C824

program main
  implicit none
  integer :: a(5) = [10,20,30,40,50]

  call sub(a)
  write(*,'(5(I4,1X))') a

contains
  subroutine sub(arr)
    integer, intent(out) :: arr(5)
    integer :: i

    do concurrent (i = 1:5)
      if (i-3) 100,200,300
      arr(i) = i * i
    end do

100 continue
200 continue
300 continue
  end subroutine sub
end program main

! GFORT: 03_doConcurrent_c007.f90:19
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 03_doConcurrent_c007.f90:19
! FLANG-SAME: error:


