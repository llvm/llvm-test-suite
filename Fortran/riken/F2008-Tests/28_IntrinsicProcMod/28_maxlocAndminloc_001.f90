! SPEC: F2008 13.7.108 MAXLOC (ARRAY, DIM [, MASK, KIND, BACK]) or
!                      MAXLOC (ARRAY [, MASK, KIND, BACK])
!             13.7.114 MINLOC (ARRAY, DIM [, MASK, KIND, BACK]) or
!                      MINLOC (ARRAY [, MASK, KIND, BACK])

program main
  use iso_fortran_env
  implicit none

  integer(int32),dimension(10) :: a
  data a/10*10/
  logical,dimension(10) :: m
  data m/5*.true.,5*.false./

  ! ====================
  ! A-1 maxloc
  ! ====================
  print*, maxloc(a)

  ! ====================
  ! A-2 minloc / B-1 logical / C-1 BACK=false / D-2 MASK none / E-2 KIND none
  ! ====================
  print*, minloc(a,back=.false.)

  ! ====================
  ! A-1 maxloc / B-1 logical / C-2 BACK=true / D-2 MASK none / E-2 KIND none
  ! ====================
  print*, maxloc(a,back=.true.)

  ! ====================
  ! A-2 minloc / B-1 logical / C-2 BACK=true / D-1 MASK / E-2 KIND none
  ! ====================
  print*, minloc(a,mask=m,back=.true.)

  ! ====================
  ! A-1 maxloc / B-1 logical / C-2 BACK=true / D-2 MASK none / E-1 KIND
  ! ====================
  print*, maxloc(a,kind=int64,back=.true.)

  ! ====================
  ! A-2 minloc / B-1 logical / C-2 BACK=true / D-1 MASK / E-1 KIND
  ! ====================
  print*, minloc(a,mask=m,kind=int32,back=.true.)
  
end program main
