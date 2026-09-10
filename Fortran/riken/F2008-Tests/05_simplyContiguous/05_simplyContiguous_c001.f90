! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:6.5.4 Simply contiguous array designators

program simplyContiguous_c001
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

  call sub1c       ! simply-contiguous; B-5

contains

  subroutine sub1c
    integer, dimension(:), pointer :: p2
    integer, dimension(:,:), pointer :: p4
    integer, dimension(:), pointer :: p6
    integer, dimension(:,:), pointer :: p8

    p2(1:5) => t1(4:7)                 ! A1-2, B-4
    p4(1:M+1,3:6) => t2(:, 3:6)        ! A1-4, B-4
    p6(0:L*M*N) => t3(:, :, :)         ! A1-6, B-4
    p8(1:3,1:8) => t3(:, 2:5, 8)       ! A1-8, B-4

  end subroutine sub1c

end program simplyContiguous_c001


! FLANG: 05_simplyContiguous_c001.f90:33
! FLANG-SAME: error:
! FLANG: 05_simplyContiguous_c001.f90:34
! FLANG-SAME: error:
! FLANG: 05_simplyContiguous_c001.f90:35
! FLANG-SAME: error:
! FLANG: 05_simplyContiguous_c001.f90:36
! FLANG-SAME: error:

! GFORT: 05_simplyContiguous_c001.f90:33
! GFORT-NOT: .f90
! GFORT: Error:
! GFORT: 05_simplyContiguous_c001.f90:34
! GFORT-NOT: .f90
! GFORT: Error:
! GFORT: 05_simplyContiguous_c001.f90:35
! GFORT-NOT: .f90
! GFORT: Error:
! GFORT: 05_simplyContiguous_c001.f90:36
! GFORT-NOT: .f90
! GFORT: Error:

