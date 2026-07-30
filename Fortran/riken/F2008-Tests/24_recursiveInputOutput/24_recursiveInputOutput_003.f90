! RUN: %flang %s -o %t && %t | FileCheck %s
! RUN: FileCheck --input-file=data3.txt %s -check-prefix=EXE
! RUN: %gfortran %s -o %t && %t | FileCheck %s
! RUN: FileCheck --input-file=data3.txt %s -check-prefix=EXE

! SPEC: F2008 9.12, R910, R911, R912, R913

! A-1 Different units
! B-1 READ
! C-1 input-item-list
! D-2 WRITE
! E-1 nest=1

program main
    use iso_fortran_env, only: iostat_end
    implicit none

    integer :: unit_num = 10
    integer :: ios(0:1)
    character(len=100) :: line
    character(len=:), allocatable :: filename

    filename = 'input3.dat'

    open(unit_num, file=filename, status='old', action='read', iostat=ios(0))

    if (ios(0) /= 0) then
        print *, 'Open Error: ', filename
        stop
    end if

    do
        read(unit_num, '(A)', iostat=ios(func())) line
        
        if (ios(1) == iostat_end) exit
        
        if (ios(1) /= 0) then
            print *, 'Read Error: ', filename
            exit
        end if
        
        print *, trim(line)
    end do

    close(unit_num)

    print *, "Done!"

contains
  integer function func()
    integer :: unit_num = 20
    real :: val = 10.5

    open(unit=unit_num, file='data3.txt', status='replace')

    write(unit_num, '(A, F0.4)') "val = ", val
    close(unit_num)

    func = 1
  end function func

end program main

! CHECK:   input3: xxxxxxx
! CHECK-NEXT:  input3: yyyyyyy
! CHECK-NEXT:  Done!
! EXE: val = 10.5000