program test_io_err

  implicit none
  integer :: n, k, l
  logical :: ok

  ok = .true.

  open(5, err=500, iostat=n)
   k = 45
   goto 505
500 continue
   k = 46
505 continue
  print *, 'k after OPEN:', k
  ok = ok .and. (k == 45)

  close(5, err=510, iostat=n)
   k = 55
   goto 515
510 continue
   k = 56
515 continue
  print *, 'k after CLOSE:', k
  ok = ok .and. (k == 55)

  read(5, err=520, iostat=n) l
   k = 65
   goto 523
520 continue
   k = 66
523 continue
  print *, 'iostat after read:', n, ' k:', k
  ok = ok .and. (k == 66)

  l = 34
  write(5, err=525, iostat=n) l
   k = 65
   goto 528
525 continue
   k = 66
528 continue
  print *, 'iostat after write:', n, ' k:', k
  ok = ok .and. (k == 66)

  if (ok) then
    print *, 'PASS'
  else
    print *, 'FAIL'
  end if

end program test_io_err
