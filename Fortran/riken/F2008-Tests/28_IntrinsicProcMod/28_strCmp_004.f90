! SPEC: F2008:13.7.98 LLT

program main
  implicit none

  integer, parameter :: ascii = selected_char_kind('ASCII')

  character(kind=ascii, len=3) :: a = 'ONE'
  character(kind=ascii, len=3) :: b = 'TWO'
  character(kind=ascii, len=5) :: c = 'ONE' ! padded with blanks
  character(kind=ascii, len=0) :: e = ''
  character(kind=ascii, len=0) :: f = ''

  !====================
  ! A-4 LLT
  ! D-1 same length
  ! ASCII order a('ONE' < 'TWO')
  !====================
  print *, "LLT('ONE','TWO') =", llt(a, b)

  !====================
  ! A-4 LLT
  ! D-2 different length (c > a, blank padding)
  !====================
  print *, "LLT('ONE  ','ONE') =", llt(c, a)

  !====================
  ! A-4 LLT
  ! D-3 different length (a > c, blank padding)
  !====================
  print *, "LLT('ONE','ONE  ') =", llt(a, c)

  !====================
  ! A-4 LLT
  ! D-4 zero length
  !====================
  print *, "LLT('', '') =", llt(e, f)

end program
