! SPEC: F2008:6.5.4 Simply contiguous array designators

program simplyContiguous_001
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

  call sub1a       ! simply-contiguous; B-1, B-2
  call sub1b       ! simply-contiguous; B-3, B-4
  call sub2a       ! not simply-contiguous; B-1, B-2

contains

  subroutine sub1a
    integer, dimension(:), pointer :: p1
    integer, dimension(:), pointer :: p2
    integer, dimension(:,:), pointer :: p3
    integer, dimension(:,:), pointer :: p4
    integer, dimension(:), pointer :: p5
    integer, dimension(:,:,:), pointer :: p6
    integer, dimension(:,:,:), pointer :: p7
    integer, dimension(:,:), pointer :: p8
    integer, dimension(:), pointer :: p9

    p1(1:N) => t1(:)              ! A1-1, B-2
    p2 => t1(4:7)                 ! A1-2, B-1
    p3(0:M-1,3:N+2) => t2(:, :)   ! A1-3, B-2
    p4 => t2(:, 3:6)              ! A1-4, B-1
    p5(1:) => t2(2:4, 4)          ! A1-5, B-2
    p6 => t3(:, :, :)             ! A1-6, B-1
    p7(0:,1:,7:) => t3(:, :, 5:7) ! A1-7, B-2
    p8 => t3(:, 2:5, 8)           ! A1-8, B-1
    p9(13:15) => t3(3:5, 4, 7)    ! A1-9, B-2

    print *, p1(N), t1(N)
    print *, p2(ubound(p2)), t1(7)
    print *, p3(M-1,N+2), t2(M,N)
    print *, p4(ubound(p4,1),ubound(p4,2)), t2(M,6)
    print *, p5(ubound(p5)), t2(4,4)
    print *, p6(L,M,N), t3(L,M,N)
    print *, p7(ubound(p7,1),ubound(p7,2),ubound(p7,3)), t3(L,M,7)
    print *, p8(L,4), t3(L,5,8)
    print *, p9(15), t3(5,4,7)
    print *

  end subroutine sub1a

  subroutine sub1b
    integer, dimension(:,:), pointer :: p1
    integer, dimension(:), pointer :: p2
    integer, dimension(:,:), pointer :: p3
    integer, dimension(:,:), pointer :: p4
    integer, dimension(:,:,:), pointer :: p5
    integer, dimension(:), pointer :: p6
    integer, dimension(:,:,:), pointer :: p7
    integer, dimension(:), pointer :: p8
    integer, dimension(:,:), pointer :: p9

    p1(1:2,1:N/2) => t1(:)           ! A1-1, B-3
    p2(1:3) => t1(4:7)               ! A1-2, B-4
    p3(1:N,0:M-1) => t2(:, :)        ! A1-3, B-3
    p4(1:M,1:2) => t2(:, 3:6)        ! A1-4, B-4
    p5(1:1,1:3,1:1) => t2(2:4, 4)    ! A1-5, B-3
    p6(1:L*M*N-3) => t3(:, :, :)     ! A1-6, B-4
    p7(1:M,1:L,1:3) => t3(:, :, 5:7) ! A1-7, B-3
    p8(1:3) => t3(:, 2:5, 8)         ! A1-8, B-4
    p9(1:1,13:15) => t3(3:5, 4, 7)   ! A1-9, B-3

    print *, p1(2,N/2), t1(N)
    print *, p2(3), t1(6)
    print *, p3(N,M-1), t2(M,N)
    print *, p4(M,2), t2(M,4)
    print *, p5(1,3,1), t2(4,4)
    print *, p6(L*M*N-3), t3(L-3,M,N)
    print *, p7(M,L,3), t3(L,M,7)
    print *, p8(3), t3(3,2,8)
    print *, p9(1,15), t3(5,4,7)
    print *

  end subroutine sub1b

  subroutine sub2a
    integer, pointer :: p1
    integer, dimension(:), pointer :: p5
    integer, dimension(:), pointer :: p6
    integer, dimension(:,:), pointer :: p7
    integer, dimension(:,:,:), pointer :: p8
    integer, dimension(:,:,:), pointer :: p9

    p1 => t1(3)                       ! A2-1, B-1
    p5(1:) => t2(8, 1:4)              ! A2-5, B-2
    p6 => t3(3, 7, 3:6)               ! A2-6, B-1
    p7(1:,1:) => t3(1, :, 4:7)        ! A2-7, B-2
    p8 => t3(:, 4:6, :)               ! A2-8, B-1
    p9(1:,1:,1:) => t3(:, 4:6, 2:5)   ! A2-9, B-2

    print *, p1, t1(3)
    print *, p5(4), t2(8,4)
    print *, p6(4), t3(3,7,6)
    print *, p7(M,4), t3(1,M,7)
    print *, p8(L,3,N), t3(L,6,N)
    print *, p9(L,3,4), t3(L,6,5)
    print *

  end subroutine sub2a
  
end program simplyContiguous_001
