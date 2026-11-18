! SPEC: F2008 R904,R905

program main
  implicit none
  integer :: u, ios
  character(10) :: s

  ! NEWUNIT with FILE specified and STATUS omitted
  open(newunit=u, file="t1.txt", iostat=ios)
  if (ios == 0)  write(*, *) "case1 OK"
  write(u,*) "case1 OK"
  close(u)

  ! NEWUNIT with STATUS='SCRATCH' and no FILE specified
  open(newunit=u, status='SCRATCH', iostat=ios)
  if (ios == 0)  write(*, *) "case2 OK"
  close(u)

  ! NEWUNIT with STATUS='UNKNOWN' and no FILE specified
  open(newunit=u, file="t3.txt", status="UNKNOWN", iostat=ios)
  if (ios == 0)  write(*, *) "case3 OK"
  write(u,*) "case3 OK"
  close(u)

  ! STATUS specified by a character variable
  s = "REPLACE"
  open(newunit=u, file='t4.txt', status=s, iostat=ios)
  if (ios == 0)  write(*, *) "case4 OK"
  write(u,*) "case4 OK"
  close(u)

  ! STATUS specified by a character concatenation expression
  open(newunit=u, file='t5.txt', status="UN"//"KNOWN", iostat=ios)
  if (ios == 0)  write(*, *) "case5 OK"
  write(u,*) "case5 OK"
  close(u)

  ! STATUS specified by a character function result
  open(newunit=u, status=get_status(), iostat=ios)
  if (ios == 0)  write(*, *) "case6 OK"
  close(u)

  ! STATUS specified by a substring expression
  s = "SCRATCHXXX"
  open(newunit=u, status=s(1:7), iostat=ios)
  if (ios == 0)  write(*, *) "case7 OK"
  close(u)

contains

  function get_status() result(r)
    character(7) :: r
    r = "SCRATCH"
  end function get_status

end program
