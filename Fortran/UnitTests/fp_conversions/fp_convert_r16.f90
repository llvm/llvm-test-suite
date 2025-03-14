module fp_convert_m
  implicit none
  type answer
    integer(kind=1)   :: i8
    integer(kind=2)   :: i16
    integer(kind=4)   :: i32
    integer(kind=8)   :: i64
    integer(kind=16)  :: i128
    unsigned(kind=1)  :: u8
    unsigned(kind=2)  :: u16
    unsigned(kind=4)  :: u32
    unsigned(kind=8)  :: u64
    unsigned(kind=16) :: u128
  end type answer
contains

  subroutine print_answer(a)
    type(answer), intent(in) :: a
    print *, a%i8
    print *, a%i16
    print *, a%i32
    print *, a%i64
    print *, a%i128
    print *, a%u8
    print *, a%u16
    print *, a%u32
    print *, a%u64
    print *, a%u128
  end subroutine print_answer

  function do_conversion(value) result(result)
    real(kind=16), intent(in) :: value
    type(answer) :: result
    result%i8 = int(value, kind=1)
    result%i16 = int(value, kind=2)
    result%i32 = int(value, kind=4)
    result%i64 = int(value, kind=8)
    result%i128 = int(value, kind=16)
    result%u8 = uint(value, kind=1)
    result%u16 = uint(value, kind=2)
    result%u32 = uint(value, kind=4)
    result%u64 = uint(value, kind=8)
    result%u128 = uint(value, kind=16)
  end function do_conversion

  subroutine testcase(value)
    real(kind=16), intent(in) :: value
    type(answer) :: result
    result = do_conversion(value)
    call print_answer(result)
  end subroutine
end module fp_convert_m

program fp_convert
  use ieee_arithmetic, only: ieee_value, ieee_quiet_nan, ieee_positive_inf, ieee_negative_inf
  use fp_convert_m
  implicit none

  real(kind=16) :: r128, nan, inf, ninf

  nan = ieee_value(nan, ieee_quiet_nan)
  inf = ieee_value(inf, ieee_positive_inf)
  ninf = ieee_value(ninf, ieee_negative_inf)

  print *, "huge"
  call testcase(huge(r128))

  print *, "-huge"
  call testcase(-huge(r128))

  print *, "tiny"
  call testcase(tiny(r128))

  print *, "-tiny"
  call testcase(-tiny(r128))

  print *, "inf"
  call testcase(inf)

  print *, "-inf"
  call testcase(ninf)

  print *, "nan"
  call testcase(nan)

end program fp_convert
