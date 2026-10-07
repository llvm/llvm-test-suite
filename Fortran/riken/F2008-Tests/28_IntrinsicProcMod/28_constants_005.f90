! SPEC: F2008:13.8.2.15 IOSTAT INQUIRE INTERNAL UNIT
  
program main
  use iso_fortran_env
  implicit none

  ! ====================
  ! D-1
  ! E-1
  ! ====================

  if (iostat_inquire_internal_unit >= 0) then
      print *, "iostat_inquire_internal_unit: OK"
  else
      print *, "iostat_inquire_internal_unit: NG"
  end if

end program main
