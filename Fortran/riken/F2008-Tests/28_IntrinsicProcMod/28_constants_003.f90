! RUN: %flang %s -o %t && %t | FileCheck %s
! RUN: %gfortran %s -o %t && %t | FileCheck %s

! SPEC: F2008:13.8.2.4 CHARACTER KINDS
  
program main
  use iso_fortran_env
  implicit none

  integer :: i
  integer :: x(1), y(1)
  logical :: flg = .true.

  ! ====================
  ! C-3
  ! E-1
  ! ====================

  do i = 1, size(character_kinds)
    if (character_kinds(i) <= 0) then
      flg = .false.
    else
      x = findloc(character_kinds, character_kinds(i))
      y = findloc(character_kinds, character_kinds(i), back=.true.)
      if (x(1) /= y(1)) then
        ! Multiple definitions
        flg = .false.
      end if
    end if
  end do

  if (flg) then
      print *, "character_kinds: OK"
  else
      print *, "character_kinds: NG"
  end if

end program main

! CHECK:  character_kinds: OK
