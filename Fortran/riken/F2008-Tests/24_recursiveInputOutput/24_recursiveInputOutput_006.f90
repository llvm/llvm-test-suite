! RUN: %flang %s -o %t && %t | FileCheck %s
! RUN: FileCheck --input-file=data6-1.txt %s -check-prefix=EXE1
! RUN: FileCheck --input-file=data6-2.txt %s -check-prefix=EXE2
! RUN: FileCheck --input-file=data6-3.txt %s -check-prefix=EXE3
! RUN: %gfortran %s -o %t && %t | FileCheck %s
! RUN: FileCheck --input-file=data6-1.txt %s -check-prefix=EXE1
! RUN: FileCheck --input-file=data6-2.txt %s -check-prefix=EXE2
! RUN: FileCheck --input-file=data6-3.txt %s -check-prefix=EXE3

! SPEC: F2008 9.12, R910, R911, R912, R913

! A-1 Different units
! B-2 WRITE
! C-2 output-item-list
! D-2 WRITE 
! E-1 nest=2

program main
  use iso_fortran_env, only: iostat_end
  implicit none
  integer :: unit_num = 10
  integer :: ios
  integer :: i
  character(len=100) :: line
  real :: val = 3.14159

  open(unit=unit_num, file='data6-1.txt', status='replace')

  write(unit_num, '(A, F0.4)') "val = ", val
  write(unit_num, *) "func1: ", func1()

  close(unit_num)

  print *, "Done!"

contains
  integer function func1()
    integer :: unit_num = 20
    real :: val = 10.5

    open(unit=unit_num, file='data6-2.txt', status='replace')

    write(unit_num, '(A, F0.4)') "val = ", val
    write(unit_num, *) "func2: ", func2()
    close(unit_num)

    func1 = 1
  end function func1

  integer function func2()
    integer :: unit_num = 30
    real :: val = 1.3

    open(unit=unit_num, file='data6-3.txt', status='replace')

    write(unit_num, '(A, F0.4)') "val = ", val
    close(unit_num)

    func2 = 1
  end function func2

end program main

! CHECK: Done!
! EXE1: val = 3.1416
! EXE1-NEXT: func1:  1
! EXE2: val = 10.5000
! EXE2-NEXT: func2:  1
! EXE3: val = 1.3000