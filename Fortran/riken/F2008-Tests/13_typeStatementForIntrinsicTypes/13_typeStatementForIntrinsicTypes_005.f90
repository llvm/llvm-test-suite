! SPEC: F2008 R403,R404,R420,R421,R422

program main
    implicit none
    integer res
    character(len=20) :: my_string1
    character(len=10) :: my_string2
   
    res = func1()
    res = func2()
    res = func3()
    my_string1 = "abcdefghijklmnopqrst"
    res = func4(my_string1)
    my_string2 = "klmnopqrst"
    res = func5(my_string2)

contains
    ! ====================
    ! A-1 TYPE
    ! B-5 CHARACTER
    ! D-1 None
    ! E-1 type decl
    ! ====================
    integer function func1()
        type(character) :: str1
        str1 = 'xyz'
        print *, 'str1 = ', str1, ", ", 'length =', len(str1)

        func1 = 1
    end function func1

    ! ====================
    ! A-1 TYPE
    ! B-5 CHARACTER
    ! D-2 character(len=l10)
    ! E-1 type decl
    ! ====================
    integer function func2()
        integer, parameter :: l10 = 10
        type(character(len=l10)) :: str2
        str2 = 'abcdefghijklmnopqrst'
        print *, 'str2 = ', str2, ", ", 'length =', len(str2)

        func2 = 1
    end function func2

    ! ====================
    ! A-1 TYPE
    ! B-5 CHARACTER
    ! D-3 character(l15)
    ! E-1 type decl
    ! ====================
    integer function func3()
        integer, parameter :: l15 = 15
        type(character(l15)) :: str3
        str3 = '1234565789012345'
        print *, 'str3 = ', str3, ", ", 'length =', len(str3)

        func3 = 1
    end function func3

    ! ====================
    ! A-1 TYPE
    ! B-5 CHARACTER
    ! D-4 character(len=*)
    ! E-1 type decl
    ! ====================
    integer function func4(str4)
        type(character(len=*)), intent(in) :: str4
        print *, 'str4 = ', str4, ", ", 'length =', len(str4)

        func4 = 1
    end function func4

    ! ====================
    ! A-1 TYPE
    ! B-5 CHARACTER
    ! D-5 character(*)
    ! E-1 type decl
    ! ====================
    integer function func5(str5)
        type(character(*)), intent(in) :: str5
        print *, 'str5 = ', str5, ", ", 'length =', len(str5)

        func5 = 1
    end function func5

end program
