program io_after_close

  implicit none
  integer :: n, k, l, iounit
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

  close(iounit, err=510, iostat=n)
   k = 55
   goto 515
510 continue
   k = 56
515 continue
  print *, 'k after CLOSE:', k
  ok = ok .and. (k == 55)

  ! Flang may treat READ from a closed unit as EOF or as another
  ! processor-dependent condition. Do not check this result here.
  read(iounit, end=520, iostat=n) l
520 continue

  l = 34
  write(iounit, err=525, iostat=n) l
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

end program io_after_close