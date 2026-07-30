! SPEC: F2008:13.7.96 LGT

program main
  implicit none

  integer, parameter :: ascii = selected_char_kind('ASCII')

  character(kind=ascii, len=3) :: a = 'ONE'
  character(kind=ascii, len=3) :: b = 'TWO'
  character(kind=ascii, len=5) :: c = 'ONE' ! padded with blanks
  character(kind=ascii, len=0) :: e = ''
  character(kind=ascii, len=0) :: f = ''

  !====================
  ! A-2 LGT
  ! D-1 same length
  ! ASCII order a('ONE' < 'TWO')
  !====================
  print *, "LGT('ONE','TWO') =", lgt(a, b)

  !====================
  ! A-2 LGT
  ! D-2 different length (c > a, blank padding)
  !====================
  print *, "LGT('ONE  ','ONE') =", lgt(c, a)

  !====================
  ! A-2 LGT
  ! D-3 different length (a > c, blank padding)
  !====================
  print *, "LGT('ONE','ONE  ') =", lgt(a, c)

  !====================
  ! A-2 LGT
  ! D-4 zero length
  !====================
  print *, "LGT('', '') =", lgt(e, f)

end program
