! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:5.3.7 CONTIGUOUS attribute
! SPEC: F2008 R533, R502

program main
  use iso_fortran_env
  implicit none

  integer :: i, j

  type wrap
     real :: rdata(4)
  end type wrap

  type(wrap), target :: t = wrap(rdata=[(real(i),i=1,4)])
  type(wrap), pointer, contiguous :: p

  !--- test A-4, C-1  (contiguous scalar pointer)
  p => t
  write(*, '(A,*(F4.0))')  't%rdata =', t%rdata
  write(*, '(A,*(F4.0))')  'p%rdata =', p%rdata

end program main


!! FLANG: 04_contiguousAttribute_c003.f90:18
!! FLANG-SAME: error:

! GFORT: 04_contiguousAttribute_c003.f90:18
! GFORT-NOT: .f90
! GFORT: Error:

