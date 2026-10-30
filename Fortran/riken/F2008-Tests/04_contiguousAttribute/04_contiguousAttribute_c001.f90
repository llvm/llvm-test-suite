! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:5.3.7 CONTIGUOUS attribute
! SPEC: F2008 R533, R502

program main
  use iso_fortran_env
  implicit none

  real(real32) :: b(10,10)
  integer :: i, j
  
  !--- test A-3, B-1
  do j = 1,10
     do i = 1,10
        b(i,j) = real(i + 10 * j, real32)
     end do
  end do
  
  print *, 'Actual arg.: real(real32) :: b(2:9,1:5)'
  call test_nocontig_explicit_2d(b(2:9,1:5))
  call test_contig_explicit_2d(b(2:9,1:5))
  print *, ''

contains

  subroutine test_nocontig_explicit_2d(x)
    real(real32), intent(in) :: x(8,5)

  end subroutine test_nocontig_explicit_2d

  subroutine test_contig_explicit_2d(x)
    real(real32), contiguous, intent(in) :: x(8,5)
                                 !!! error: x must be assumed shape.

  end subroutine test_contig_explicit_2d


end program main


! FLANG: 04_contiguousAttribute_c001.f90:
! FLANG-SAME: error:

! GFORT: 04_contiguousAttribute_c001.f90:33
! GFORT-NOT: .f90
! GFORT: Error:

