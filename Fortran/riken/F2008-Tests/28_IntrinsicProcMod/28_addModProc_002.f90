! SPEC: F2008:15.2.3.7 C SIZEOF

program main
  use iso_fortran_env, only: real32
  use iso_c_binding
  implicit none
  real(real32),dimension(10) :: a
  integer(c_short),dimension(10) :: b

  !========================
  ! A-3 x_sizeof(x)
  ! B-1 use module
  ! C-1 not assumed-size array 
  ! D-1 interoperable data
  !========================
  print*, c_sizeof(a)
  print*, c_sizeof(b)
  
end program

! CHECK=NEXT: 20
