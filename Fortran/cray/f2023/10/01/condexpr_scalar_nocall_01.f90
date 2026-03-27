! Test for conditional expressions (Fortran 2023)

subroutine S(c1, A, B1, B2, B3, B4, B5, C, D)
  logical :: c1
  real :: A, B1, B2, B3, B4, B5, C(*), D(*)

  A = B1 + (c1 ? B2/B3 &
               : (1.0/B4 < 1.0 ? 2.0 / B5 : -2.0))

  C(1) = (D(1) > D(2) .and. D(3) < 0.0 &
          ? (D(4) > 0.0 .or. D(5) > 0.0 &
            ? 3.0/D(6) + D(7) : 19.0) &
          : (4.0/D(8) > 0.5 ? D(9) : D(10)))

end subroutine S

program main
  logical :: c1
  real :: A, B1, B2, B3, B4, B5, C(1), D(10)

  B1 = 100.0
  B2 =  10.0

  c1 = .true.
  B3 = 1.0
  B4 = 0.0
  B5 = 0.0
  D = [ 2.0, 1.0, -3.0, 4.0, 5.0, 6.0, 7.0, 0.0, 123.0, 456.0 ]
  call S(c1, A, B1, B2, B3, B4, B5, C, D)
  print *, 'A-T*;TT   110. 7.5  : ',  A, C(1)

  c1 = .false.
  B3 = 0.0
  B4 = 2.0
  B5 = 1.0
  D = [ 2.0, 1.0, 3.0, 4.0, -5.0, 0.0, 7.0, 4.0, 123.0, 456.0 ]
  call S(c1, A, B1, B2, B3, B4, B5, C, D)
  print *, 'B-FT;FT   102. 123. : ',  A, C(1)

  c1 = .false.
  B3 = 0.0
  B4 = 0.5
  B5 = 0.0
  D = [ 2.0, 1.0, -3.0, -4.0, -5.0, 0.0, 7.0, 9.0, 123.0, 456.0 ]
  call S(c1, A, B1, B2, B3, B4, B5, C, D)
  print *, 'C-FF;TF    98. 19.  : ',  A, C(1)

  c1 = .false.
  B3 = 0.0
  B4 = 3.0
  B5 = 0.5
  D = [ 1.0, 2.0, -3.0, -4.0, -5.0, 0.0, 7.0, 9.0, 123.0, 456.0 ]
  call S(c1, A, B1, B2, B3, B4, B5, C, D)
  print *, 'D-FT;FF   104. 456. : ',  A, C(1)

end program main
