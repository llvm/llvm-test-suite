! SPEC: F2008:13.8.2.11 INT8, INT16, INT32, and INT64, 13.8.2.12 INTEGER KINDS
  
program main
  use iso_fortran_env
  implicit none

  integer(int8) :: x8(1), y8(1)
  integer(int16) :: x16(1), y16(1)
  integer(int32) :: x32(1), y32(1)
  integer(int64) :: x64(1), y64(1)
  integer :: i
  logical :: flg = .true.

  ! ====================
  ! A-1/2/3/4
  ! C-1
  ! E-1
  ! ====================
  
  do i = 1, size(integer_kinds)
    if (integer_kinds(i) <= 0) then
      flg = .false.
    end if
  end do

  if (int8 == 0) then
    print *, "int8: NG"
  else
    if (int8 < 0) then
      ! unsupported
      print *, "int8: OK"
    else
      x8 = findloc(integer_kinds, int8)
      if (x8(1) > 0) then
        y8 = findloc(integer_kinds, int8, back=.true.)
        if (x8(1) == y8(1)) then
          print *, 'int8: OK'
        else
          ! Multiple definitions of int8
          flg = .false.
        end if
      else
        ! int8 is not defined
        flg = .false.
      end if
    end if
  end if

  if (int16 == 0) then
    print *, "int16: NG"
  else
    if (int16 < 0) then
      ! unsupported
      print *, "int16: OK"
    else
      x16 = findloc(integer_kinds, int16)
      if (x16(1) > 0) then
        y16 = findloc(integer_kinds, int16, back=.true.)
        if (x16(1) == y16(1)) then
          print *, 'int16: OK'
        else
          ! Multiple definitions of int16
          flg = .false.
        end if
      else
        ! int16 is not defined
        flg = .false.
      end if
    end if
  end if

  if (int32 == 0) then
    print *, "int32: NG"
  else
    if (int32 < 0) then
      ! unsupported
      print *, "int32: OK"
    else
      x32 = findloc(integer_kinds, int32)
      if (x32(1) > 0) then
        y32 = findloc(integer_kinds, int32, back=.true.)
        if (x32(1) == y32(1)) then
          print *, 'int32: OK'
        else
          ! Multiple definitions of int32
          flg = .false.
        end if
      else
        ! int32 is not defined
        flg = .false.
      end if
    end if
  end if

  if (int64 == 0) then
    print *, "int64: NG"
  else
    if (int64 < 0) then
      ! unsupported
      print *, "int64: OK"
    else
      x64 = findloc(integer_kinds, int64)
      if (x64(1) > 0) then
        y64 = findloc(integer_kinds, int64, back=.true.)
        if (x64(1) == y64(1)) then
          print *, 'int64: OK'
        else
          ! Multiple definitions of int64
          flg = .false.
        end if
      else
        ! int64 is not defined
        flg = .false.
      end if
    end if
  end if

  if (flg) then
      print *, "integer_kinds: OK"
  else
      print *, "integer_kinds: NG"
  end if

end program main
