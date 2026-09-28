! RUN: %flang %s -o %t && %t | FileCheck %s
! RUN: FileCheck --input-file=data4.txt %s -check-prefix=EXE
! RUN: %gfortran %s -o %t && %t | FileCheck %s
! RUN: FileCheck --input-file=data4.txt %s -check-prefix=EXE

! SPEC: F2008 9.12, R910, R911, R912, R913

! A-1 Different units
! B-2 WRITE
! C-2 output-item-list
! D-1 READ 
! E-1 nest=1

program main
  use iso_fortran_env, only: iostat_end
  implicit none
  integer :: unit_num = 100
  integer :: ios
  integer :: i
  character(len=100) :: line
  real :: val = 3.14159

  open(unit=unit_num, file='data4.txt', status='replace')

  write(unit_num, '(A, F0.4)') "val = ", val
  write(unit_num, *) "func: ", func(line)

  close(unit_num)

  print *, line

contains
  integer function func(l)
    character(len=*), intent(out) :: l
    integer :: unit_num = 20
    integer :: ios
    character(len=100) :: line

    l = ""

    open(newunit=unit_num, file='input4.dat', status='old', action='read', iostat=ios)
    if (ios /= 0) then
        print *, 'Error: File cannot be opened.'
        stop
    end if

    do
        read(unit_num, '(A)', iostat=ios) line
        
        if (ios == iostat_end) exit
        
        if (ios /= 0) then
            print *, 'Error: A read error has occurred.'
            exit
        end if
        
        l = trim(l) // trim(line)

    end do

    close(unit_num)

    func = 1
  end function func

end program main

! CHECK:  input4.dat :write ->read
! EXE: val = 3.1416
! EXE-NEXT: func:  1