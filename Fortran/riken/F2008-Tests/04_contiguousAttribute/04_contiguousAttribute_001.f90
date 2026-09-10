! SPEC: F2008:5.3.7 CONTIGUOUS attribute
! SPEC: F2008 R533, R502

program main
  use iso_fortran_env
  implicit none

  real(real32) :: a(6), b(10,10)
  integer :: i, j
  
  integer :: ix(6) = [3,5,1,6,2,4]

  !--- test A-1, B-1
  do i = 1,6
     a(i) = real(i, real32)
  end do

  print *, 'Actual arg.: real(real32) :: a(:)'
  call test_nocontig_1d(a(:))
  call test_contig_1d(a(:))
  print *, ''

  !--- test A-1, B-3
  do i = 1,6
     a(i) = real(i, real32)
  end do

  print *, 'Actual arg.: real(real32) :: a(ix(:))'
  call test_nocontig_1d(a(ix(:)))
  call test_contig_1d(a(ix(:)))
  print *, ''

  !--- test A-1, B-2
  do j = 1,10
     do i = 1,10
        b(i,j) = real(i + 10 * j, real32)
     end do
  end do
  
  print *, 'Actual arg.: real(real32) :: b(2:9,1:5)'
  call test_nocontig_2d(b(2:9,1:5))
  call test_contig_2d(b(2:9,1:5))
  print *, ''

contains

  subroutine test_nocontig_1d(x)
    real(real32), intent(in) :: x(:)

    print *, 'Dummy arg. : real(real32) :: x(:)'
    print *, '  distance between x(1) and x(2):', LOC(x(2)) - LOC(x(1))
  end subroutine test_nocontig_1d

  subroutine test_contig_1d(x)
    real(real32), contiguous, intent(in) :: x(:)

    print *, 'Dummy arg. : real(real32), contiguous :: x(:)'
    print *, '  distance between x(1) and x(2):', LOC(x(2)) - LOC(x(1))
  end subroutine test_contig_1d

  subroutine test_nocontig_2d(x)
    real(real32), intent(in) :: x(:,:)

    print *, 'Dummy arg. : real(real32) :: x(:,:)'
    print *, '  distance between x(1,1) and x(2,1):', LOC(x(2,1)) - LOC(x(1,1))
    print *, '  distance between x(1,1) and x(1,2):', LOC(x(1,2)) - LOC(x(1,1))
  end subroutine test_nocontig_2d

  subroutine test_contig_2d(x)
    real(real32), contiguous, intent(in) :: x(:,:)

    print *, 'Dummy arg. : real(real32), contiguous :: x(:,:)'
    print *, '  distance between x(1,1) and x(2,1):', LOC(x(2,1)) - LOC(x(1,1))
    print *, '  distance between x(1,1) and x(1,2):', LOC(x(1,2)) - LOC(x(1,1))
  end subroutine test_contig_2d

end program main
