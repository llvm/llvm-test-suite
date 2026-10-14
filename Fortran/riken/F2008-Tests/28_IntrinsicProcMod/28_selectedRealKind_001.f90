! RUN: %flang %s -o %t && %t | FileCheck %s
! RUN: %gfortran %s -o %t && %t | FileCheck %s

! SPEC: F2008 13.7.147

program main
    implicit none
    real :: r
    print *, 'rasix =', radix(r)

! ====================
! A-1, B-1, C-1
! ====================
    print *, selected_real_kind()

! ====================
! A-3, B-3, C-3
! ====================
    print *, selected_real_kind(15, 307, radix(r))

! ====================
! A-4, B-4, C-1
! ====================
    print *, selected_real_kind(33, 4931)

! ====================
! A-2, B-1, C-1
! ====================
    print *, selected_real_kind(6)

end program main

! CHECK:  rasix =  2
! CHECK-NEXT:  4
! CHECK-NEXT:  8
! CHECK-NEXT:  16
! CHECK-NEXT:  4
