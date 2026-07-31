! Flang NAMELIST extension: an assignment to a scalar item may omit its
! value (e.g. `l_flag=`, immediately followed by the next name-value
! pair or the group terminator), leaving the item's current value
! unchanged.  F2023 13.11.3.2 requires a value token to follow the `=`,
! but nvfortran and gfortran accept the empty form as "keep current
! value".  See flang/docs/Extensions.md.
!
! This test exercises both spelling variants:
!   * l_flag= i_count=7      (no whitespace around `=`)
!   * l_flag = i_count = 7   (whitespace on both sides of `=`)
! In each case l_flag must retain its .true. value and i_count must
! be set to 7 from the following assignment.

program p
  implicit none
  logical :: l_flag
  integer :: i_count
  character(len=64) :: buf
  namelist /test_nml/ l_flag, i_count

  ! Form 1: no whitespace around the `=`.
  l_flag = .true.
  i_count = 42
  buf = "&test_nml l_flag= i_count=7 /"
  read(buf, nml=test_nml)
  if (.not. l_flag) stop 1
  if (i_count /= 7) stop 2

  ! Form 2: whitespace on both sides of the `=`.
  l_flag = .true.
  i_count = 42
  buf = "&test_nml l_flag = i_count = 7 /"
  read(buf, nml=test_nml)
  if (.not. l_flag) stop 3
  if (i_count /= 7) stop 4
end program
