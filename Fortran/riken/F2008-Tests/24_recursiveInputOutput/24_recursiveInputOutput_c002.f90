! RUN: %flang %s -o %t
! RUN: not --crash timeout 10s %t 2>&1 | FileCheck %s
! RUN: %gfortran %s -o %t
! RUN: not timeout 10s %t

! SPEC: F2008 9.12, R913

! A-2 Same units
! B-2 WRITE
! C-2 output-item-list
! D-2 WRITE 
! E-1 nest=1

program main
  implicit none
  integer :: unit_num = 10
  integer :: i
  real :: val = 3.14159

  open(unit=unit_num, file='data1.txt', status='replace')

  write(unit_num, *) "val = ", val
  write(unit_num, *) "func: ", func()

  close(unit_num)

  print *, "done!"

contains
  integer function func()
    integer :: unit_num = 10
    real :: val = 0.5

    open(unit=unit_num, file='data2.txt', status='replace')

    write(unit_num, *) "val = ", val

    close(unit_num)

    func = 1
  end function func

end program main

! CHECK:  error: Aborted