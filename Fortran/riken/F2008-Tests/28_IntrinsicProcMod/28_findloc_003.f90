! SPEC: F2008:13.7.61 FINDLOC

program main
  use iso_fortran_env, only: int32, int64
  implicit none
  integer :: a(3,4)
  logical :: m(3,4)
  integer :: pos(2)
 
  ! a =
  ! 0  -5   7   7
  ! 3   4  -1   2
  ! 1   5   6   7
  a = reshape([ &
     0,3,1, &
    -5,4,5, &
     7,-1,6, &
     7,2,7 ], [3,4])
  
  ! m =
  ! T   T   F   T
  ! T   T   F   T
  ! T   T   F   T
  m = reshape([ &
      .true.,.true.,.true., &
      .true.,.true.,.true., &
      .false.,.false.,.false., &
      .true.,.true.,.true. ], [3,4])

  ! ====================
  ! D-2 mask
  ! E-2 kind
  ! F-2/3 back 
  ! ====================
  pos = findloc(a, 7, mask=m)
  write(*,'(A,2(I4,1X))') "position:", pos

  pos = findloc(a, 7, mask=m, kind=int32, back=.false.)
  write(*,'(A,2(I4,1X))') "position(back:false):", pos
  write(*,*) "kind=int32: ", kind(findloc(a, 7, mask=m, kind=int32, back=.false.))

  pos = findloc(a, 7, mask=m, kind=int64, back=.true.)
  write(*,'(A,2(I4,1X))') "position(back:true) :", pos
  write(*,*) "kind=int64: ", kind(findloc(a, 7, mask=m, kind=int64, back=.true.))

end program
