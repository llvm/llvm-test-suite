! SPEC: F2008 Bit transformational functions (IALL,IANY,IPARITY)

program main
  use iso_fortran_env
  implicit none

  integer(int32),dimension(5,3) :: a
  data a/1,3,5,7,9,2,4,6,8,10,4,3,5,7,9/
  integer(int64),dimension(2,2,2) :: b
  data b/1,2,3,4,5,6,7,8/
  logical,dimension(2,2,2) :: mask
  data mask/.true.,.false.,.true.,.false.,.true.,.false.,.true.,.false./

  ! ====================
  ! A-1 IALL / B-1 int32 / C-1 none / D-1 none 
  ! ====================
  print*, iall(a)
  
  ! ====================
  ! A-2 IANY / B-1 int32 / C-2 DIM <= rank / D-1 none 
  ! ====================
  print*, iany(a,2)

  ! ====================
  ! A-3 IPARYTY / B-2 int64 / C-2 DIM <= rank / D-2 logical
  ! ====================
  print*, iparity(b,3,mask)
  
end program main
