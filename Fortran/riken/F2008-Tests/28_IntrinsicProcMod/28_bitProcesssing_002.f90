! SPEC: F2008 Combined shifting (DSHIFTL,DSHIFTR)

program main
  use iso_fortran_env
  implicit none

  integer :: i0, j0
  integer(int32) :: i32, j32
  integer(int64) :: i64, j64

  ! ====================
  ! A-1 DSHIFTL / B-1 default / C-1 default / D-1 decimal / E-1 decimal / F-1 positive
  ! ====================
  i0 = 2
  j0 = 2**24
  print*, dshiftl(i0,j0,8)
  print*, dshiftl(1,2**30,4)

  ! ====================
  ! A-2 DSHIFTR / B-1 default / C-2 int32 / D-1 decimal / E-2 binary / F-1 positive
  ! ====================
  i0 = 2
  j32 = int(B"1000000000000000000000000000000",int32)
  print*, dshiftr(i0,j32,30)
  print*, dshiftr(1,B"1000000000000000000000000000000",28)

  ! ====================
  ! A-1 DSHIFTL / B-3 int64 / C-3 int64 / D-3 octal / E-1 decimal / F-1 positive
  ! ====================
  i64 = int(O"10",int64)
  j64 = 2**30

  print*, dshiftl(i64,j64,4)
  print*, dshiftl(O"10",2**25,8)

  ! ====================
  ! A-2 DSHIFTR / B-1 default / C-2 int32 / D-1 decimal / E-4 hex / F-1 positive
  ! ====================
  i0 = 4
  j32 = int(Z"FFFFFFFF",int32)
  print*, dshiftr(i0,j32,30)
  print*, dshiftr(1,Z"FFFFFFFF",28)

  ! ====================
  ! A-1 DSHIFTL / B-1 default / C-1 default / D-1 decimal / E-1 decimal / F-2 zero
  ! ====================
  i0 = 2
  j0 = 2**24
  print*, dshiftl(i0,j0,0)
  print*, dshiftl(1,2**30,0)

end program main
