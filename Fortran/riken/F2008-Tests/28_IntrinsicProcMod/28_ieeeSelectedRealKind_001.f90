! SPEC: F2008 14.11.18

program main
    use iso_fortran_env
    use ieee_arithmetic
    implicit none
    real :: r
    print *, 'rasix =', radix(r)

! ====================
! A-3, B-3, C-3
! ====================
    print *, ieee_selected_real_kind(15, 307, radix(r))

! ====================
! A-4, B-4, C-1
! ====================
    print *, ieee_selected_real_kind(33, 4931)

! ====================
! A-2, B-1, C-1
! ====================
    print *, ieee_selected_real_kind(6)

end program main
