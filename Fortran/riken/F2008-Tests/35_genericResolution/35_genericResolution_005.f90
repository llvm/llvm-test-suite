! RUN: %flang %s -o %t && %t | FileCheck %s
! RUN: %gfortran %s -o %t && %t | FileCheck %s

! SPEC: F2008 12.4.3.4.5, R1207 C1212, C1213, C1214, C1215

! ====================
! A-1
! B-5
! C-1
! ====================
module mod5
    implicit none
    interface func
        module procedure func_a, func_b
    end interface func

contains
    function func_a(a)
        integer :: func_a
        integer, allocatable, intent(in) :: a
        func_a = a * 2
    end function func_a

    function func_b(a)
        integer :: func_b
        integer, pointer, intent(in) :: a
        func_b = a * 2
    end function func_b
end module mod5

program main
    use mod5
    implicit none
    integer, allocatable :: i
    integer, target :: r = 3
    integer, pointer :: p_r

    allocate(i)
    i = 5
    p_r => r

    print *, 'func(i) :', func(i)
    print *, 'func(p_r) :', func(p_r)
end program main

! CHECK:  func(i) : 10
! CHECK-NEXT:  func(p_r) : 6
