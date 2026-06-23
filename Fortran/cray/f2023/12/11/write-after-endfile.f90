program write_after_endfile

  implicit none
  integer :: n, k, iounit
  logical :: ok

  ok = .true.

  open(newunit=iounit, file='test_io.dat', status='replace', &
       form='unformatted', err=500, iostat=n)
   k = 45
   goto 505
500 continue
   k = 46
505 continue
  print *, 'k after OPEN:', k
  ok = ok .and. (k == 45)

  write(iounit) 123

  ! Write the endfile record, leaving the unit positioned after it.
  endfile(iounit, err=510, iostat=n)
   k = 55
   goto 515
510 continue
   k = 56
515 continue
  print *, 'k after ENDFILE:', k
  ok = ok .and. (k == 55)

  ! A WRITE after ENDFILE is an error.  With ERR= and IOSTAT= present,
  ! the runtime must set IOSTAT (nonzero) and branch to the ERR= label
  ! instead of aborting.  Before this fix the error was raised too early
  ! and the program crashed rather than taking the ERR= branch.  The exact
  ! IOSTAT value is processor-dependent, so the test only checks that an
  ! error was signaled (n /= 0), not its specific value.
  write(iounit, err=525, iostat=n) 456
   k = 65
   goto 528
525 continue
   k = 66
528 continue
  print *, 'k after WRITE:', k
  ok = ok .and. (k == 66) .and. (n /= 0)

  if (ok) then
    print *, 'PASS'
  else
    print *, 'FAIL'
  end if

  close(iounit)

end program write_after_endfile
