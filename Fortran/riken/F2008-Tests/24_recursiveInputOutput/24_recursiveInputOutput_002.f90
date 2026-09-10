! RUN: %flang %s -o %t && %t | FileCheck %s
! RUN: %gfortran %s -o %t && %t | FileCheck %s

! SPEC: F2008 9.12, R910, R911, R912, R913

! A-1 Different units
! B-1 READ
! C-1 input-item-list
! D-1 READ 
! E-2 nest=2

program main
    use iso_fortran_env, only: iostat_end
    implicit none

    integer :: unit_num = 10
    integer :: ios(0:1)
    character(len=100) :: line
    character(len=:), allocatable :: filename

    filename = 'input1.dat'

    open(unit_num, file=filename, status='old', action='read', iostat=ios(0))

    if (ios(0) /= 0) then
        print *, 'Open Error: ', filename
        stop
    end if

    do
        read(unit_num, '(A)', iostat=ios(func1())) line
        
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
    integer function func1()
        integer :: unit_num2 = 20
        integer :: ios2(0:1)
        character(len=100) :: line2
        character(len=:), allocatable :: filename2

        filename2 = 'input2.dat'

        open(unit_num2, file=filename2, status='old', action='read', iostat=ios2(0))
        if (ios2(0) == 0) then
            do
                read(unit_num2, '(A)', iostat=ios2(func2())) line2
        
                if (ios2(1) == iostat_end) exit
        
                if (ios2(1) /= 0) then
                    print *, 'Read Error: ', filename2
                    exit
                end if
        
                print *, trim(line2)
            end do

            close(unit_num2)
        else
            print *, 'Open Error: ', filename2
        end if

        func1 = 1
    end function func1

    integer function func2()
        integer :: unit_num3 = 30
        integer :: ios3
        character(len=100) :: line3
        character(len=:), allocatable :: filename3

        filename3 = 'input3.dat'

        open(unit_num3, file=filename3, status='old', action='read', iostat=ios3)
        if (ios3 == 0) then
            do
                read(unit_num3, '(A)', iostat=ios3) line3
        
                if (ios3 == iostat_end) exit
        
                if (ios3 /= 0) then
                    print *, 'Read Error: ', filename3
                    exit
                end if
        
                print *, trim(line3)
            end do

            close(unit_num3)
        else
            print *, 'Open Error: ', filename3
        end if

        func2 = 1
    end function func2

end program main

! CHECK:  input3: xxxxxxx
! CHECK-NEXT:  input3: yyyyyyy
! CHECK-NEXT:  input2: 11111
! CHECK-NEXT:  input3: xxxxxxx
! CHECK-NEXT:  input3: yyyyyyy
! CHECK-NEXT:  input2: 22222
! CHECK-NEXT:  input3: xxxxxxx
! CHECK-NEXT:  input3: yyyyyyy
! CHECK-NEXT:  input1: aaa
! CHECK-NEXT:  input3: xxxxxxx
! CHECK-NEXT:  input3: yyyyyyy
! CHECK-NEXT:  input2: 11111
! CHECK-NEXT:  input3: xxxxxxx
! CHECK-NEXT:  input3: yyyyyyy
! CHECK-NEXT:  input2: 22222
! CHECK-NEXT:  input3: xxxxxxx
! CHECK-NEXT:  input3: yyyyyyy
! CHECK-NEXT:  input1: bbb
! CHECK-NEXT:  input3: xxxxxxx
! CHECK-NEXT:  input3: yyyyyyy
! CHECK-NEXT:  input2: 11111
! CHECK-NEXT:  input3: xxxxxxx
! CHECK-NEXT:  input3: yyyyyyy
! CHECK-NEXT:  input2: 22222
! CHECK-NEXT:  input3: xxxxxxx
! CHECK-NEXT:  input3: yyyyyyy
! CHECK-NEXT:  input1: ccc
! CHECK-NEXT:  input3: xxxxxxx
! CHECK-NEXT:  input3: yyyyyyy
! CHECK-NEXT:  input2: 11111
! CHECK-NEXT:  input3: xxxxxxx
! CHECK-NEXT:  input3: yyyyyyy
! CHECK-NEXT:  input2: 22222
! CHECK-NEXT:  input3: xxxxxxx
! CHECK-NEXT:  input3: yyyyyyy
! CHECK-NEXT:  Done!