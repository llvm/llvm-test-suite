! SPEC: F2008:13.7.61 FINDLOC

program main
  implicit none

  integer :: a(3,4)
  logical :: m(3,4)
  integer :: pos(4)
 
  ! a =
  ! 0  -5   7   7
  ! 3   4  -1   2
  ! 1   5   6   7
  a = reshape([ &
     0,3,1, &
    -5,4,5, &
     7,-1,6, &
     7,2,7 ], [3,4])
  
  ! ====================
  ! C-2 dim
  ! F-2/3 back
  ! ====================
  pos = findloc(a, 7, dim=1)
  write(*,'(A,4(I4,1X))') "position:", pos

  pos = findloc(a, 7, dim=1, back=.false.)
  write(*,'(A,4(I4,1X))') "position(back:false):", pos

  pos = findloc(a, 7, dim=1, back=.true.)
  write(*,'(A,4(I4,1X))') "position(back:true) :", pos

end program

! CHECK=NEXT: position(back:false):   0    0    1    1
! CHECK=NEXT: position(back:true) :   0    0    1    3
