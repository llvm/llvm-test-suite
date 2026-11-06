! RUN: %flang %s -o %t && %t | FileCheck %s
! RUN: %gfortran %s -o %t && %t | FileCheck %s

! SPEC: F2008 13.7.147

program main
    implicit none
    real :: r

! ====================
! A-6, B-2, C-3
! ====================
    print *, 'No.1 :', selected_real_kind(34, 37, radix(r))

! ====================
! A-3, B-6, C-3
! ====================
    print *, 'No.2 :', selected_real_kind(15, 4932, radix(r))

! ====================
! A-6, B-6, C-3
! ====================
    print *, 'No.3 :', selected_real_kind(34, 4932, radix(r))

! ====================
! A-4, B-4, C-5
! ====================
    print *, 'No.4 :', selected_real_kind(33, 4931, radix(r)+1)

end program main

! CHECK:  No.1 : -1
! CHECK-NEXT:  No.2 : -2
! CHECK-NEXT:  No.3 : -3
! CHECK-NEXT:  No.4 : -5
