! SPEC: F2008 Counting bits (TRAILZ)

program main
  use iso_fortran_env
  implicit none

  integer(int32) :: i32
  integer(int64) :: i64

  ! ====================
  ! A-1 TRAILZ / B-1 default / C-1 positive
  ! ====================
  print*, trailz(10)

  ! ====================
  ! A-1 TRAILZ / B-1 default / C-1 zero
  ! ====================
  print*, trailz(0)

  ! ====================
  ! A-1 TRAILZ / B-1 default / C-1 minus
  ! ====================
  print*, trailz(-1)

  ! ====================
  ! A-1 TRAILZ / B-2 int32 / C-1 positive
  ! ====================
  i32 = 10
  print*, trailz(i32)

  ! ====================
  ! A-1 TRAILZ / B-2 int32 / C-1 zero
  ! ====================  
  i32 = 0
  print*, trailz(i32)

  ! ====================
  ! A-1 TRAILZ / B-2 int32 / C-1 minus
  ! ====================
  i32 = -1
  print*, trailz(i32)

  ! ====================
  ! A-1 TRAILZ / B-3 int64 / C-1 positive
  ! ====================
  i64 = 10
  print*, trailz(i64)

  ! ====================
  ! A-1 TRAILZ / B-3 int64 / C-1 zero
  ! ====================  
  i64 = 0
  print*, trailz(i64)

  ! ====================
  ! A-1 TRAILZ / B-3 int64 / C-1 minus
  ! ====================
  i64 = -1
  print*, trailz(i64)

end program main
