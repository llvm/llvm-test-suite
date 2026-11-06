! SPEC: F2008:13.7.95 LGE

program main
  implicit none

  integer, parameter :: ascii = selected_char_kind('ASCII')

  character(kind=ascii, len=3) :: a = 'ONE'
  character(kind=ascii, len=3) :: b = 'TWO'
  character(kind=ascii, len=5) :: c = 'ONE' ! padded with blanks
  character(kind=ascii, len=0) :: e = ''
  character(kind=ascii, len=0) :: f = ''

  !====================
  ! A-1 LGE
  ! D-1 same length
  ! ASCII order a('ONE' < 'TWO')
  !====================
  print *, "LGE('ONE','TWO') =", lge(a, b)

  !====================
  ! A-1 LGE
  ! D-2 different length (c > a, blank padding)
  !====================
  print *, "LGE('ONE  ','ONE') =", lge(c, a)

  !====================
  ! A-1 LGE
  ! D-3 different length (a > c, blank padding)
  !====================
  print *, "LGE('ONE','ONE  ') =", lge(a, c)

  !====================
  ! A-1 LGE
  ! D-4 zero length
  !====================
  print *, "LGE('', '') =", lge(e, f)

end program
