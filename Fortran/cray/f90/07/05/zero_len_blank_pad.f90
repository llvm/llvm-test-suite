! Test intrinsic assignments with zero-len source arrays.
! The resulting dest should be blank-padded to its length.
! F90 - 7.5.1.4
program zero_len_blank_pad
  implicit none
  character(len=0), dimension(0)  :: zla
  character(len=4), dimension(10) :: dest
  zla = ""
  dest = "ABCD"
  dest(1:) = zla(called(1):)(:called(0))
  if (dest(1) == "    " .and. dest(10) == "    ") then
    print *, "PASS"
  else
    print *, "FAIL"
  end if

contains

  pure integer function called(i)
    integer, intent(in) :: i
    called = i
  end function

end program
