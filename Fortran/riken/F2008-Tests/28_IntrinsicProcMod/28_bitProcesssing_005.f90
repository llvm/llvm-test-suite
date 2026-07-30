! SPEC: F2008 Counting bits (POPPAR)

program main
  use iso_fortran_env
  implicit none

  integer(int32) :: i32
  integer(int64) :: i64

  ! ====================
  ! A-1 POPPAR / B-1 default / C-1 positive
  ! ====================
  print*, poppar(11)

  ! ====================
  ! A-1 POPPAR / B-1 default / C-1 zero
  ! ====================
  print*, poppar(0)

  ! ====================
  ! A-1 POPPAR / B-1 default / C-1 minus
  ! ====================
  print*, poppar(-1)

  ! ====================
  ! A-1 POPPAR / B-2 int32 / C-1 positive
  ! ====================
  i32 = 11
  print*, poppar(i32)

  ! ====================
  ! A-1 POPPAR / B-2 int32 / C-1 zero
  ! ====================  
  i32 = 0
  print*, poppar(i32)

  ! ====================
  ! A-1 POPPAR / B-2 int32 / C-1 minus
  ! ====================
  i32 = -1
  print*, poppar(i32)

  ! ====================
  ! A-1 POPPAR / B-3 int64 / C-1 positive
  ! ====================
  i64 = 11
  print*, poppar(i64)

  ! ====================
  ! A-1 POPPAR / B-3 int64 / C-1 zero
  ! ====================  
  i64 = 0
  print*, poppar(i64)

  ! ====================
  ! A-1 POPPAR / B-3 int64 / C-1 minus
  ! ====================
  i64 = -1
  print*, poppar(i64)

end program main
