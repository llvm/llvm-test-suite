! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:6.5.4 Simply contiguous array designators

program simplyContiguous_c003
  implicit none

  integer, parameter :: L = 5, M = 8, N = 10

  integer, parameter :: ix(N) = [2,7,5,3,9,8,1,4,10,6]
  integer :: i

  integer, dimension(N), target :: t1
  integer, dimension(M,N), target :: t2
  integer, dimension(L,M,N), target :: t3

  !! initialization
  t1 = [(i,i=1,N)]
  t2 = reshape([(i,i=1,M*N)], [M,N])
  t3 = reshape([(i,i=1,L*M*N)], [L,M,N])

  call sub2c       ! not simply-contiguous; B-5

contains

  subroutine sub2c
    integer, dimension(:), pointer :: p6
    integer, dimension(:,:,:), pointer :: p8

    p6(3:7) => t3(3, 7, 3:6)            ! A2-6, B-5
    p8(1:L,1:3,1:N+1) => t3(:, 4:6, :)  ! A2-8, B-5

  end subroutine sub2c

end program simplyContiguous_c003


! FLANG: 05_simplyContiguous_c003.f90:31
! FLANG-SAME: error:
! FLANG: 05_simplyContiguous_c003.f90:32
! FLANG-SAME: error:

! GFORT: 05_simplyContiguous_c003.f90:31
! GFORT-NOT: .f90
! GFORT: Error:
! GFORT: 05_simplyContiguous_c003.f90:32
! GFORT-NOT: .f90
! GFORT: Error:

