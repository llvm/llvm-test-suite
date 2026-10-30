! SPEC: F2008 Bit comparison (BGE,BGT,BLE,BLT)
  
program main
  use iso_fortran_env
  implicit none

  integer :: i0, j0
  integer(int32) :: i32, j32
  integer(int64) :: i64, j64

  ! ====================
  ! A-1 BGE / B-1 default / C-1 default / D-1 decimal / E-1 decimal
  ! ====================

  i0 = 10
  j0 = 10
  print*, bge(i0, j0)
  print*, bge(-1,1)
  print*, bge(1,1)
  print*, bge(-2,-1)

  ! ====================
  ! A-2 BGT / B-2 int32 / C-2 int32 / D-2 binary / E-3 octal
  ! ====================
  i32 = int(B'1010',int32)
  j32 = int(O'12',int32)
  print*, bgt(i32, j32)
  print*, bgt(B'1000',O"7")
  print*, bgt(B'1000',O"10")
  print*, bgt(B'1000',O'11')

  ! ====================
  ! A-3 BLE / B-3 int64 / C-3 int64 / D-3 octal / E-4 hex
  ! ====================
  i64 = int(O'12',int64)
  j64 = int(Z'A',int64)
  print*, ble(i64, j64)
  print*, ble(O'777777777777',Z"FFFFFFFFFF")
  print*, ble(O'17777777777777',Z"FFFFFFFFFF")
  print*, ble(O'27777777777777',Z'FFFFFFFFFF')

  ! ====================
  ! A-4 BLT / B-2 int32 / C-3 int64 / D-4 hex / E-2 binary
  ! ====================
  i32 = int(Z'A',int32)
  j64 = int(B'1010',int64)
  print*, blt(i32, j64)
  print*, blt(Z'FF',B"111111111")
  print*, blt(Z'FF',B"11111111")
  print*, blt(Z'FF',B'11111110')

  ! ====================
  ! A-1 BGE / B-3 int64 / C-1 default / D-4 hex / E-1 decimal
  ! ====================  
  j64 = int(Z'A',int64)
  j0 = 10
  print*, bge(i64, j32)
  print*, bge(Z"1FF",255)
  print*, bge(Z"FF",255)
  print*, bge(Z'FE',255)

  ! ====================
  ! A-2 BGT / B-1 default / C-3 int64 / D-1 decimal / E-4 hex
  ! ====================
  i0 = 10
  j64 = int(Z'A',int64)
  print*, bgt(i0, j64)
  print*, bgt(255,Z"FE")
  print*, bgt(255,Z"FF")
  print*, bgt(255,Z'1FF')
end program main
