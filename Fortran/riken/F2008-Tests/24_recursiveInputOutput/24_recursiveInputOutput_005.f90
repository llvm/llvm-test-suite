! RUN: %flang %s -o %t && %t | FileCheck %s
! RUN: FileCheck --input-file=data5-1.txt %s -check-prefix=EXE1
! RUN: FileCheck --input-file=data5-2.txt %s -check-prefix=EXE2
! RUN: %gfortran %s -o %t && %t | FileCheck %s
! RUN: FileCheck --input-file=data5-1.txt %s -check-prefix=EXE1
! RUN: FileCheck --input-file=data5-2.txt %s -check-prefix=EXE2

! SPEC: F2008 9.12, R910, R911, R912, R913

! A-1 Different units
! B-2 WRITE
! C-2 output-item-list
! D-2 WRITE 
! E-1 nest=1

program main
  use iso_fortran_env, only: iostat_end
  implicit none
  integer :: unit_num = 10
  integer :: ios
  integer :: i
  character(len=100) :: line
  real :: val = 3.14159

  open(unit=unit_num, file='data5-1.txt', status='replace')

  write(unit_num, '(A, F0.4)') "val = ", val
  write(unit_num, *) "func: ", func()

  close(unit_num)

  print *, "Done!"

contains
  integer function func()
    integer :: unit_num = 20
    real :: val = 10.5

    open(unit=unit_num, file='data5-2.txt', status='replace')

    write(unit_num, '(A, F0.4)') "val = ", val
    close(unit_num)

    func = 1
  end function func

end program main

! CHECK: Done!
! EXE1: val = 3.1416
! EXE1-NEXT: func:  1
! EXE2: val = 10.5000
