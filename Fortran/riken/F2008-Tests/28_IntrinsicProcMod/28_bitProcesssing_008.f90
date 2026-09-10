! SPEC: F2008 Shifting bits (SHIFTA,SHIFTL,SHIFTR)

program main
  use iso_fortran_env
  implicit none

  integer(int32) :: i32,s32
  integer(int64) :: i64,s64

  ! ====================
  ! A-1 SHIFTA / B-1 default / C-1 default / D-1 positive / E-1 positive
  ! ====================
  print*, shifta(1,3)

  ! ====================
  ! A-2 SHIFTL / B-2 int32 / C-2 int32 / D-1 positive / E-1 positive
  ! ====================
  i32 = 11
  s32 = 1
  print*, shiftl(i32,s32)
  
  ! ====================
  ! A-3 SHIFTR / B-3 int64 / C-2 int32 / D-2 negative / E-1 positive
  ! ====================
  i64 = -1
  s32 = 1
  print*, shiftr(i64,s32)

  ! ====================
  ! A-1 SHIFTA / B-2 int32 / C-3 int64 / D-2 negative / E-1 positive
  ! ====================  
  i32 = -1
  s64 = 1
  print*, shifta(i32,s64)

  ! ====================
  ! A-2 SHIFTL / B-3 int64 / C-3 int64 / D-1 positive / E-2 zero
  ! ====================  
  i64 = 10
  s64 = 0
  print*, shiftl(i64,s64)
  
end program main
