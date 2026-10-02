! F2023 Suite Test -- Fortran 2023 subclause 7.6.2 "Enumeration types"
! ---------------------------------------------------------------------------
! Positive-path runtime test of formatted input/output of data of enumeration
! type.
!
! Standard references exercised by this test:
!   12.6.3 p6           a list item of enumeration type shall correspond to an
!                       I, B, O, or Z edit descriptor in a formatted data
!                       transfer statement (list-directed transfer of such an
!                       item is not permitted, so it is not exercised here)
!   13.7.2.2 p1         the effective item for an I edit descriptor may be of
!                       enumeration type
!   13.7.2.2 p6         on output the value transferred is the ordinal
!                       position of the item; on input the value of the field
!                       shall be positive and not greater than the number of
!                       enumerators, and the item is assigned the enumeration
!                       value with that ordinal position
!   13.7.2.2 p4,p5      the Iw and Iw.m output field forms
!   13.7.2.4 p1         the effective item for a B, O, or Z edit descriptor
!                       may be of enumeration type
!   13.7.2.4 p4         B, O, and Z input produces ET (INT (X)) where X is the
!                       boz-literal-constant denoted by the input field
!   16.9.110 Case (v)   INT (A) is the ordinal position of A
!
! The B, O, and Z *output* field is defined in terms of the bit sequence of
! the internal value (13.7.2.4 p5), which the standard does not fix for an
! enumeration type, so only the success of such a transfer is checked here.
! B, O, and Z *input* is normatively defined, so its result is checked.
!
! On success the program prints "PASS ..." and exits with status zero; on
! failure it writes diagnostics to the error unit and terminates with a
! nonzero status.
! ---------------------------------------------------------------------------

module enum_io_mod
  use iso_fortran_env, only: error_unit
  implicit none

  enumeration type :: v_value
    enumerator :: v_one, v_two, v_three
    enumerator v_four
  end enumeration type v_value

  enumeration type :: w_value
    enumerator :: w1, w2, w3, w4, w5, wendsentinel
  end enumeration type w_value

  ! 7.6.2 NOTE: a derived type whose components are of enumeration type is
  ! written with one edit descriptor per component.
  type :: vw
    type(v_value) :: v
    type(w_value) :: w
  end type

  integer :: nfail = 0

contains

  subroutine check_int(actual, expected, label)
    integer, intent(in) :: actual, expected
    character(len=*), intent(in) :: label
    if (actual /= expected) then
      write (error_unit, '(3A,I0,A,I0)') 'FAIL: enum_05: ', label, &
          ': expected ', expected, ', got ', actual
      nfail = nfail + 1
    end if
  end subroutine check_int

  subroutine check_string(actual, expected, label)
    character(len=*), intent(in) :: actual, expected
    character(len=*), intent(in) :: label
    if (actual /= expected) then
      write (error_unit, '(7A)') 'FAIL: enum_05: ', label, ': expected "', &
          expected, '", got "', actual, '"'
      nfail = nfail + 1
    end if
  end subroutine check_string

  subroutine check_true(condition, label)
    logical, intent(in) :: condition
    character(len=*), intent(in) :: label
    if (.not. condition) then
      write (error_unit, '(2A)') 'FAIL: enum_05: ', label
      nfail = nfail + 1
    end if
  end subroutine check_true

  ! The "sub" procedure of the 7.6.2 NOTE: printing a value acts similarly to
  ! printing INT of that value.
  subroutine sub_to_string(a, text)
    type(v_value), intent(in) :: a
    character(len=*), intent(out) :: text
    write (text, 1) a
1   format('A has ordinal value ', I0)
  end subroutine sub_to_string

  ! The "showme" procedure of the 7.6.2 NOTE.
  subroutine showme_to_string(ka, text)
    type(vw), intent(in) :: ka
    character(len=*), intent(out) :: text
    write (text, 1) ka
1   format(1X, 'v ordinal is ', I0, ', w ordinal is ', I0)
  end subroutine showme_to_string

end module enum_io_mod

program enum_05_formatted_io
  use enum_io_mod
  implicit none

  type(v_value) :: x, y, arr(4), back(4)
  type(w_value) :: w
  type(vw) :: pair
  character(len=64) :: line
  character(len=64) :: lines(4)
  character(len=64) :: text
  character(len=16) :: field
  integer :: i, iostat, unit

  ! --- 13.7.2.2 p6: I editing on output transfers the ordinal position.
  write (line, '(I1)') v_one
  call check_string(trim(line), '1', 'I1 output of v_one')

  write (line, '(I1)') v_four
  call check_string(trim(line), '4', 'I1 output of v_four')

  write (line, '(I0)') v_three
  call check_string(trim(line), '3', 'I0 output of v_three')

  write (line, '(I5)') v_two
  call check_string(line(1:5), '    2', 'I5 output is right justified')

  ! 13.7.2.2 p5: the Iw.m form pads with leading zeros.
  write (line, '(I5.3)') v_two
  call check_string(line(1:5), '  002', 'I5.3 output of v_two')

  write (line, '(I0.2)') v_four
  call check_string(trim(line), '04', 'I0.2 output of v_four')

  ! The ordinal written is the one reported by INT.
  do i = 1, 4
    x = v_value(i)
    write (line, '(I0)') x
    write (text, '(I0)') int(x)
    call check_string(trim(line), trim(text), 'I0 output agrees with INT')
  end do

  ! Values of a second type, and values produced by the intrinsics.
  write (line, '(I0)') wendsentinel
  call check_string(trim(line), '6', 'I0 output of wendsentinel')

  write (line, '(I0)') huge(v_one)
  call check_string(trim(line), '4', 'I0 output of HUGE')

  write (line, '(I0)') next(v_one)
  call check_string(trim(line), '2', 'I0 output of NEXT')

  write (line, '(I0)') previous(v_four)
  call check_string(trim(line), '3', 'I0 output of PREVIOUS')

  ! --- Several enumeration items, arrays, and implied-DO lists.
  write (line, '(4(I0,1X))') v_one, v_two, v_three, v_four
  call check_string(trim(line), '1 2 3 4', 'four items in one transfer')

  arr = [v_four, v_three, v_two, v_one]
  write (line, '(4I2)') arr
  call check_string(line(1:8), ' 4 3 2 1', 'array output')

  write (line, '(4I2)') (arr(i), i=4, 1, -1)
  call check_string(line(1:8), ' 1 2 3 4', 'implied-DO output')

  ! Items of two different enumeration types in one transfer.
  write (line, '(I0,1X,I0)') v_two, w5
  call check_string(trim(line), '2 5', 'items of two enumeration types')

  ! A derived-type item is expanded into its components (7.6.2 NOTE).
  pair = vw(v_three, w4)
  write (line, '(2I2)') pair
  call check_string(line(1:4), ' 3 4', 'derived-type item output')

  ! --- The procedures of the 7.6.2 NOTE.
  call sub_to_string(v_three, text)
  call check_string(trim(text), 'A has ordinal value 3', 'the NOTE sub')

  call showme_to_string(vw(v_two, w5), text)
  call check_string(trim(text), ' v ordinal is 2, w ordinal is 5', &
      'the NOTE showme')

  ! --- 13.7.2.2 p6: I editing on input assigns the value with that ordinal.
  field = '3'
  read (field, '(I1)') x
  call check_int(int(x), 3, 'I1 input of 3')
  call check_true(x == v_three, 'I1 input of 3 is v_three')

  field = '1'
  read (field, '(I1)') x
  call check_true(x == v_one, 'I1 input of 1 is v_one')

  field = '    4'
  read (field, '(I5)') x
  call check_true(x == v_four, 'I5 input with leading blanks')

  field = '6'
  read (field, '(I1)') w
  call check_true(w == wendsentinel, 'input of the last ordinal')

  ! Every ordinal position survives a write followed by a read.
  do i = 1, 4
    x = v_value(i)
    write (line, '(I0)') x
    read (line, '(I5)') y
    call check_true(x == y, 'I editing round trip')
  end do

  ! Array input.
  field = ' 4 3 2 1'
  read (field, '(4I2)') back
  call check_true(all(int(back) == [4, 3, 2, 1]), 'array input')

  ! Input of several items of different enumeration types.
  field = '2 5'
  read (field, '(I1,1X,I1)') x, w
  call check_true(x == v_two, 'multi-type input, first item')
  call check_true(w == w5, 'multi-type input, second item')

  ! --- 13.7.2.4: B, O, and Z editing.
  ! Input is defined as ET (INT (X)) for the boz-literal-constant X denoted by
  ! the field, so the resulting values are checked directly.
  field = '11'
  read (field, '(B2)') x
  call check_true(x == v_three, 'B input of 11 is ordinal 3')

  field = '100'
  read (field, '(B3)') x
  call check_true(x == v_four, 'B input of 100 is ordinal 4')

  field = '2'
  read (field, '(O1)') x
  call check_true(x == v_two, 'O input of 2 is ordinal 2')

  field = '4'
  read (field, '(Z1)') x
  call check_true(x == v_four, 'Z input of 4 is ordinal 4')

  field = '6'
  read (field, '(Z1)') w
  call check_true(w == wendsentinel, 'Z input of 6 is ordinal 6')

  ! The output field for B, O, and Z is the bit sequence of the internal
  ! value, which the standard leaves to the processor for an enumeration
  ! type, so only the success of the transfer is checked.
  iostat = -1
  write (line, '(B8)', iostat=iostat) v_three
  call check_int(iostat, 0, 'B output completes')
  call check_true(len_trim(line) > 0, 'B output is not empty')

  iostat = -1
  write (line, '(O8)', iostat=iostat) v_three
  call check_int(iostat, 0, 'O output completes')
  call check_true(len_trim(line) > 0, 'O output is not empty')

  iostat = -1
  write (line, '(Z8)', iostat=iostat) v_three
  call check_int(iostat, 0, 'Z output completes')
  call check_true(len_trim(line) > 0, 'Z output is not empty')

  iostat = -1
  write (line, '(4Z4)', iostat=iostat) arr
  call check_int(iostat, 0, 'Z output of an array completes')

  ! --- The same transfers through an external file.
  open (newunit=unit, status='scratch', form='formatted', action='readwrite')
  do i = 1, 4
    write (unit, '(I0)') v_value(i)
  end do
  write (unit, '(2I3)') vw(v_two, w3)
  rewind (unit)
  do i = 1, 4
    read (unit, '(I5)') x
    call check_int(int(x), i, 'external file round trip')
  end do
  read (unit, '(2I3)') pair
  call check_int(int(pair%v), 2, 'external file component v')
  call check_int(int(pair%w), 3, 'external file component w')
  close (unit)

  ! --- An internal file that is an array of records.
  write (lines, '(I0)') arr
  do i = 1, 4
    write (text, '(I0)') int(arr(i))
    call check_string(trim(lines(i)), trim(text), 'array internal file record')
  end do

  read (lines, '(I5)') back
  call check_true(all(int(back) == int(arr)), 'array internal file input')

  if (nfail == 0) then
    print '(A)', 'PASS enum_05_formatted_io'
  else
    write (error_unit, '(A,I0,A)') 'enum_05: ', nfail, ' check(s) failed'
    error stop 1
  end if

end program enum_05_formatted_io
