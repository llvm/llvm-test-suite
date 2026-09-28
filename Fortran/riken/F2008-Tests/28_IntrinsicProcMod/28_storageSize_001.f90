! SPEC: F2008 13.7.160 STORAGE SIZE (A [, KIND])

program main
  use iso_fortran_env
  implicit none
  real(real32) :: r1
  complex(real64),dimension(10) :: x1
  type zzz
     integer(int32) :: a
     integer(int64) :: b
     integer(int64),dimension(10) :: c
  end type zzz
  
  type(zzz) :: z1
  integer(int64),pointer :: p1
  character :: c1
  c1 = "abcdef"

! ====================
! A-1 constant B-1 real
! ====================
  print*, storage_size(1.1)

! ====================
! A-2 scalar variable B-2 real
! ====================
  print*, storage_size(r1)

! ====================
! A-3 array B-3 complex C-1 int
! ====================  
  print*, storage_size(x1,int16)

! ====================
! A-2 scalar variable B-4 character C-1 int
! ====================  
  print*, storage_size(c1,int8)

! ====================
! A-2 scalar variable B-5 pointer C-1 int
! ====================  
  print*, storage_size(p1,int64)

! ====================
! A-2 scalar variable B-6 derived C-1 int
! ====================    
  print*, storage_size(z1,int32)
end program main
