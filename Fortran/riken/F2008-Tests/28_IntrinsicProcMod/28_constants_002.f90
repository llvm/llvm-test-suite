! SPEC: F2008:13.8.2.21 REAL32, REAL64, and REAL128, 13.8.2.20 REAL KINDS
  
program main
  use iso_fortran_env
  implicit none

  real(real32) :: x32(1), y32(1)
  real(real64) :: x64(1), y64(1)
  real(real128) :: x128(1), y128(1)
  integer :: i
  logical :: flg = .true.

  ! ====================
  ! B-1/2/3
  ! C-1
  ! E-1
  ! ====================
  
  do i = 1, size(real_kinds)
    if (real_kinds(i) <= 0) then
      flg = .false.
    end if
  end do

  if (real32 == 0) then
    print *, "real32: NG"
  else
    if (real32 < 0) then
      ! unsupported
      print *, "real32: OK"
    else
      x32 = findloc(real_kinds, real32)
      if (x32(1) > 0) then
        y32 = findloc(real_kinds, real32, back=.true.)
        if (x32(1) == y32(1)) then
          print *, 'real32: OK'
        else
          ! Multiple definitions of real32
          flg = .false.
        end if
      else
        ! real32 is not defined
        flg = .false.
      end if
    end if
  end if

  if (real64 == 0) then
    print *, "real64: NG"
  else
    if (real64 < 0) then
      ! unsupported
      print *, "real64: OK"
    else
      x64 = findloc(real_kinds, real64)
      if (x64(1) > 0) then
        y64 = findloc(real_kinds, real64, back=.true.)
        if (x64(1) == y64(1)) then
          print *, 'real64: OK'
        else
          ! Multiple definitions of real64
          flg = .false.
        end if
      else
        ! real64 is not defined
        flg = .false.
      end if
    end if
  end if

  if (real128 == 0) then
    print *, "real128: NG"
  else
    if (real128 < 0) then
      ! unsupported
      print *, "real128: OK"
    else
      x128 = findloc(real_kinds, real128)
      if (x128(1) > 0) then
        y128 = findloc(real_kinds, real128, back=.true.)
        if (x128(1) == y128(1)) then
          print *, 'real128: OK'
        else
          ! Multiple definitions of real128
          flg = .false.
        end if
      else
        ! real128 is not defined
        flg = .false.
      end if
    end if
  end if

  if (flg) then
      print *, "real_kinds: OK"
  else
      print *, "real_kinds: NG"
  end if

end program main
