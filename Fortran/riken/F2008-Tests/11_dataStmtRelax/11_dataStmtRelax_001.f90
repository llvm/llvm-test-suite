! SPEC: F2008:5.4.7 DATA statement

program dataStmtRelax_001
  use iso_fortran_env
  implicit none

  call charlie

contains

  subroutine charlie
    type person
       character(len=40) :: name
       integer :: age
    end type person

    character(*), parameter :: his_name = 'Charlie Brown'
    integer, parameter :: ages(*) = [8, 6]

    type(person) :: boy, girl

    data boy / person(his_name, ages(1)) /
    data girl / person('Sally' // his_name(index(his_name, ' '):), minval(ages)) /

    if (girl%name == "Sally Brown" .and. girl%age == 6) then
       print *, 'OK'
    end if

  end subroutine charlie

end program dataStmtRelax_001
