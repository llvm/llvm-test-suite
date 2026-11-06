! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:6.5.4 Simply contiguous array designators

program simplyContiguous_c002
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

  call sub2b       ! not simply-contiguous; B-3, B-4

contains

  subroutine sub2b
    integer, dimension(:,:), pointer :: p5
    integer, dimension(:), pointer :: p6
    integer, dimension(:), pointer :: p7
    integer, dimension(:,:,:), pointer :: p8
    integer, dimension(:), pointer :: p9

    p5(1:2,1:2) => t2(8, 1:4)           ! A2-5, B-3   ! OK (1-dim target)
    p6(3:5) => t3(3, 7, 3:6)            ! A2-6, B-4   ! OK (1-dim target)
    p7(1:M*4) => t3(1, :, 4:7)          ! A2-7, B-3
    p8(1:L,1:3,1:N-1) => t3(:, 4:6, :)  ! A2-8, B-4
    p9(1:L*3*10) => t3(:, 4:6, 2:5)     ! A2-9, B-3

  end subroutine sub2b

end program simplyContiguous_c002


! FLANG: 05_simplyContiguous_c002.f90:36
! FLANG-SAME: error:
! FLANG: 05_simplyContiguous_c002.f90:37
! FLANG-SAME: error:
! FLANG: 05_simplyContiguous_c002.f90:38
! FLANG-SAME: error:

! GFORT: 05_simplyContiguous_c002.f90:36
! GFORT-NOT: .f90
! GFORT: Error:
! GFORT: 05_simplyContiguous_c002.f90:37
! GFORT-NOT: .f90
! GFORT: Error:
! GFORT: 05_simplyContiguous_c002.f90:38
! GFORT-NOT: .f90
! GFORT: Error:

