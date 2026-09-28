! SPEC: F2008:13.7.97 LLE

program main
  implicit none

  integer, parameter :: ascii = selected_char_kind('ASCII')

  character(kind=ascii, len=3) :: a = 'ONE'
  character(kind=ascii, len=3) :: b = 'TWO'
  character(kind=ascii, len=5) :: c = 'ONE' ! padded with blanks
  character(kind=ascii, len=0) :: e = ''
  character(kind=ascii, len=0) :: f = ''

  !====================
  ! A-3 LLE
  ! D-1 same length
  ! ASCII order a('ONE' < 'TWO')
  !====================
  print *, "LLE('ONE','TWO') =", lle(a, b)

  !====================
  ! A-3 LLE
  ! D-2 different length (c > a, blank padding)
  !====================
  print *, "LLE('ONE  ','ONE') =", lle(c, a)

  !====================
  ! A-3 LLE
  ! D-3 different length (a > c, blank padding)
  !====================
  print *, "LLE('ONE','ONE  ') =", lle(a, c)

  !====================
  ! A-3 LLE
  ! D-4 zero length
  !====================
  print *, "LLE('', '') =", lle(e, f)

end program
