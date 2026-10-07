! SPEC: 13.7.123 NORM2 (X [, DIM])

program main
  use iso_fortran_env
  implicit none

  real(real32),dimension(2) :: a
  data a/1.0,2.0/
  real(real64),dimension(2,2) :: b
  data b/1.0,2.0,3.0,4.0/

  ! ====================
  ! A-1 array / B-1 real
  ! ====================
  write(*,'(F8.6)') norm2(a)
  write(*,'(F14.12)') norm2(b)
  ! ====================
  ! A-1 array / B-1 real / C-2 int / D-1 1 <= DIM <= rank
  ! ====================  
  write(*,'(F14.12,F4.1)') norm2(b,1)
  write(*,'(F14.12,F15.12)') norm2(b,2)

end program main
