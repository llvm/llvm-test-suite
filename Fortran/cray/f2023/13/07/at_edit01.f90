! Self-checking execution tests for the AT edit descriptor
! (Fortran 2023 Standard, 13.7.4).
!
! The AT edit descriptor outputs CHARACTER data with trailing blanks
! removed (trimmed). It does not accept a width field.
! AT may only be used for output, not input.
!
! Each test compares actual formatted output against an expected string
! and prints PASS or FAIL. The reference output is just PASS lines.
program at_edit01
  implicit none
  character(10) :: s10
  character(20) :: s20
  character(5)  :: s5
  character(1)  :: s1
  character(80) :: got
  integer :: npass, nfail

  npass = 0
  nfail = 0

  ! Test 1: Basic trailing blank trimming
  s10 = "hello"
  write(got, '(AT)') s10
  call check("basic trim", got, "hello")

  ! Test 2: String fills variable exactly (no trailing blanks)
  s5 = "world"
  write(got, '(AT)') s5
  call check("exact fit", got, "world")

  ! Test 3: All blanks become empty output
  s10 = " "
  write(got, '(AT)') s10
  call check("all blanks", got, "")

  ! Test 4: Leading blanks are preserved
  s10 = "  hello"
  write(got, '(AT)') s10
  call check("leading blanks", got, "  hello")

  ! Test 5: Internal blanks are preserved
  s10 = "ab cd ef"
  write(got, '(AT)') s10
  call check("internal blanks", got, "ab cd ef")

  ! Test 6: Single non-blank character
  s1 = "X"
  write(got, '(AT)') s1
  call check("single char", got, "X")

  ! Test 7: Single blank character
  s1 = " "
  write(got, '(AT)') s1
  call check("single blank", got, "")

  ! Test 8: Repeat count (2AT)
  s10 = "aaa"
  s5 = "bb"
  write(got, '(2AT)') s10, s5
  call check("2AT repeat", got, "aaabb")

  ! Test 9: AT with 1X separator
  s10 = "abc"
  s5 = "de"
  write(got, '(AT,1X,AT)') s10, s5
  call check("AT 1X AT", got, "abc de")

  ! Test 10: Contrast AT vs A descriptor
  s10 = "hi"
  write(got, '("A :",A)') s10
  call check("A descriptor", got, "A :hi        ")
  write(got, '("AT:",AT)') s10
  call check("AT descriptor", got, "AT:hi")

  ! Test 11: Longer variable
  s20 = "hello world"
  write(got, '(AT)') s20
  call check("longer string", got, "hello world")

  ! Test 12: Multiple items with different lengths
  s20 = "first"
  s10 = "second"
  s5 = "third"
  write(got, '(AT,"|",AT,"|",AT)') s20, s10, s5
  call check("multi items", got, "first|second|third")

  ! Test 13: Preserves leading and internal blanks only
  s20 = "  a  b  c"
  write(got, '(AT)') s20
  call check("leading+internal blanks", got, "  a  b  c")

  ! Test 14: Character literal (no trailing blanks to trim)
  write(got, '(AT)') "literal"
  call check("char literal", got, "literal")

  ! Summary
  write(*,'(A,I0,A,I0,A)') "Result: ", npass, " passed, ", nfail, " failed"
  if (nfail > 0) stop 1

contains
  subroutine check(name, actual, expected)
    character(len=*), intent(in) :: name, actual, expected
    if (trim(actual) == trim(expected)) then
      write(*,'(A,A)') "PASS: ", name
      npass = npass + 1
    else
      write(*,'(A,A)') "FAIL: ", name
      write(*,'(A,A,A)') "  Expected: [", trim(expected), "]"
      write(*,'(A,A,A)') "  Got:      [", trim(actual), "]"
      nfail = nfail + 1
    end if
  end subroutine

end program at_edit01
