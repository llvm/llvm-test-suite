! SPEC: F2008 R514,R516

program main
  implicit none
  integer :: t1,t2
  integer :: a( &
       2,2,2,2,2, &
       2,2,2,2,2, &
       2,2,2,2,2 )

  integer, dimension( &
       2,2,2,2,2, &
       2,2,2,2,2, &
       2,2,2,2,2 ) :: b

  integer, parameter :: c( &
       2,2,2,2,2, &
       2,2,2,2,2, &
       2,2,2,2,2 ) = 1

  integer, dimension ( &
       2,2,2,2,2, &
       2,2,2,2,2, &
       2,2,2,2,2 ), parameter :: d = 1

  integer :: e( &
       2,2,2,2,2, &
       2,2,2,2,2, &
       2,2,2,2,2 )

  a = 1
  b = 1
  e = f1()
  t1 = sum(e)
  t2 = sum(f2())

  print *, size(shape(a)), size(shape(b)), size(shape(c)), size(shape(d)), size(shape(e)) ,size(shape(f2()))
  print *, sum(a), sum(b), sum(c), sum(d), t1, t2

contains

  function f1() result(r1)
    implicit none
    integer :: r1( &
         2,2,2,2,2, &
         2,2,2,2,2, &
         2,2,2,2,2 )
    r1 = 1
  end function

  function f2() result(r2)
    implicit none
    integer, dimension( &
         2,2,2,2,2, &
         2,2,2,2,2, &
         2,2,2,2,2 ) :: r2
    r2 = 1
  end function

end program
