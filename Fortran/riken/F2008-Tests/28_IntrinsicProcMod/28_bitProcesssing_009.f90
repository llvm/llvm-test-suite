! SPEC: F2008 Merging bits (MERGE_BITS)

program main
  use iso_fortran_env
  implicit none

  integer(int32) :: i32,j32,m32
  integer(int64) :: i64,j64,m64

  ! ====================
  ! A-1 MERGE_BITS / B-1 default / C-1 default / D-1 default / E-1 decimal / F-1 decimal / G-1 decimal
  ! ====================
  print*, merge_bits(10,20,2)

  ! ====================
  ! A-1 MERGE_BITS / B-2 int32 / C-2 int32 / D-1 default / E-2 binary / F-1 decimal / G-1 octal
  ! ====================
  i32 = int(B"1111",int32)
  j32 = 10
  print*, merge_bits(i32,j32,O"10")
  print*, merge_bits(B"1111",10,O"10")

  ! ====================
  ! A-1 MERGE_BITS / B-3 int64 / C-3 int64 / D-3 int64 / E-1 decimal / F-2 binary / G-4 hex
  ! ====================  
  i64 = 20
  j64 = int(B"1110",int64)
  m64 = int(Z"A",int64)
  print*, merge_bits(i64,j64,m64)
  print*, merge_bits(20,B"1110",Z"A")
  
end program main
