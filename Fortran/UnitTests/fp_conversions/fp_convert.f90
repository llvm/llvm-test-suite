module fp_convert_m
  use iso_fortran_env
  implicit none
  integer            :: test_case = 1
  type answer
    integer(kind=1)  :: i8
    integer(kind=2)  :: i16
    integer(kind=4)  :: i32
    integer(kind=8)  :: i64
    unsigned(kind=1) :: u8
    unsigned(kind=2) :: u16
    unsigned(kind=4) :: u32
    unsigned(kind=8) :: u64
  end type answer
  type(answer)       :: answers(6)

  interface operator(==)
    module procedure answer_eq
  end interface operator(==)

contains

  subroutine init_answers()
    ! huge
    answers(1) = answer( &
                  127, 32767, 2147483647, 9223372036854775807_8, &
                  unsigned(255, kind=1), &
                  unsigned(65535, kind=2), &
                  unsigned(4294967295, kind=4), &
                  unsigned(18446744073709551615, kind=8))

    ! -huge
    answers(2) = answer( &
                  -128, -32768, -2147483648, -9223372036854775808_8, &
                  unsigned(0, kind=1), &
                  unsigned(0, kind=2), &
                  unsigned(0, kind=4), &
                  unsigned(0, kind=8))

    ! tiny
    answers(3) = answer( &
                  0, 0, 0, 0, &
                  unsigned(0, kind=1), &
                  unsigned(0, kind=2), &
                  unsigned(0, kind=4), &
                  unsigned(0, kind=8))

    ! -tiny
    answers(4) = answers(3)

    ! inf
    answers(5) = answer( &
                  127, 32767, 2147483647, 9223372036854775807_8, &
                  unsigned(255, kind=1), &
                  unsigned(65535, kind=2), &
                  unsigned(4294967295, kind=4), &
                  unsigned(18446744073709551615, kind=8))

    ! -inf
    answers(6) = answer( &
                  -128, -32768, -2147483648, -9223372036854775808_8, &
                  unsigned(0, kind=1), &
                  unsigned(0, kind=2), &
                  unsigned(0, kind=4), &
                  unsigned(0, kind=8))
  end subroutine init_answers
  subroutine print_answer(a)
    type(answer), intent(in) :: a
    print *, a%i8, a%i16, a%i32, a%i64, a%u8, a%u16, a%u32, a%u64
  end subroutine print_answer

  logical function answer_eq(a, b)
    type(answer), intent(in) :: a, b
    answer_eq = a%i8 == b%i8 .and. a%i16 == b%i16 .and. a%i32 == b%i32 .and. a%i64 == b%i64 &
                        .and. a%u8 == b%u8 .and. a%u16 == b%u16 .and. a%u32 == b%u32 .and. a%u64 == b%u64
  end function answer_eq

  subroutine do_conversion(value, result)
    real(kind=8), intent(in) :: value
    type(answer), intent(out) :: result
    result%i8 = int(value, kind=1)
    result%i16 = int(value, kind=2)
    result%i32 = int(value, kind=4)
    result%i64 = int(value, kind=8)

    result%u8 = uint(value, kind=1)
    result%u16 = uint(value, kind=2)
    result%u32 = uint(value, kind=4)
    result%u64 = uint(value, kind=8)
  end subroutine

  subroutine testcase(value, answers)
    real(kind=8), intent(in) :: value
    type(answer), intent(in) :: answers
    type(answer) :: result
    call do_conversion(value, result)
    if (result == answers) then
      print *, "PASS", test_case
    else
      print *, "FAIL", test_case
      print *, "Expected:"
      call print_answer(answers)
      print *, "Got:"
      call print_answer(result)
    end if
    test_case = test_case + 1
  end subroutine
end module fp_convert_m

program fp_convert
  use ieee_arithmetic, only: ieee_value, ieee_quiet_nan, ieee_positive_inf, ieee_negative_inf
  use fp_convert_m
  implicit none

  real(kind=8) :: r64, nan, inf, ninf

  call init_answers()

  nan = ieee_value(nan, ieee_quiet_nan)
  inf = ieee_value(inf, ieee_positive_inf)
  ninf = ieee_value(ninf, ieee_negative_inf)

  print *, "huge"
  call testcase(huge(r64), answers(1))

  print *, "-huge"
  call testcase(-huge(r64), answers(2))

  print *, "tiny"
  call testcase(tiny(r64), answers(3))

  print *, "-tiny"
  call testcase(-tiny(r64), answers(4))

  print *, "inf"
  call testcase(inf, answers(5))

  print *, "-inf"
  call testcase(ninf, answers(6))

end program fp_convert
