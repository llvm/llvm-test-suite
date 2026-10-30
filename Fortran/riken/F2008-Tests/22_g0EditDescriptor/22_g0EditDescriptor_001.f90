! SPEC: F2008 Introduction, 10.7.5

program main
  use, intrinsic :: ieee_arithmetic
  implicit none

  integer :: i = -123
  real    :: r = 12.34
  complex :: c
  logical :: l = .true.
  character(len=5) :: str = "ABC"
  real    :: inf, nan

  ! IEEE
  inf = ieee_value(1.0, ieee_positive_inf)
  nan = ieee_value(1.0, ieee_quiet_nan)
  c = cmplx(1.5, 3.7)

  ! ====================
  ! A-1 integer
  ! B-1 g0
  ! ====================
  print '(a, g0)', 'integer(g0) = ', i
  print '(a, i0)', 'integer(i0) = ', i

  ! ====================
  ! A-2 real
  ! B-1 g0
  ! ====================
  print '(a, g0)', 'real(g0) = ', r
  print '(a, g15.7)', 'real(g15.7) = ', r
  ! ====================
  ! A-2 real
  ! B-2 g0.d
  ! ====================
  print '(a, g0.4)', 'real(g0.4) = ', r
  print '(a, g15.4)', 'real(g15.4) = ', r

  ! ====================
  ! A-3 complex
  ! B-1 g0
  ! ====================
  print "(a, '(', g0, ',', g0,')')", 'complex(g0) = ', c
  print "(a, '(', g15.7, ',', g15.7,')')", 'complex(g15.7) = ', c
  ! ====================
  ! A-3 complex
  ! B-2 g0.d
  ! ====================
  print "(a, '(', g0.4, ',', g0.4,')')", 'complex(g0.4) = ', c
  print "(a, '(', g15.4, ',', g15.4,')')", 'complex(g15.4) = ', c
  
  ! ====================
  ! A-4 logical
  ! B-1 g0
  ! ====================
  print '(a, g0)', 'logocal(g0) = ', l
  print '(a, l1)', 'logocal(l1) = ', l

  ! ====================
  ! A-5 character
  ! B-1 g0
  ! ====================
  print '(a, g0)', 'character(g0) = ', str
  print '(a, a)', 'character(a) = ', str

  ! ====================
  ! A-6 Infinity
  ! B-1 g0
  ! ====================
  print '(a, g0)', 'inf(g0) = ', inf
  print '(a, f0.0)', 'inf(f0.0) = ', inf
  
  ! ====================
  ! A-7 NaN
  ! B-1 g0
  ! ====================
  print '(a, g0)', 'nan(g0) = ', nan
  print '(a, f0.0)', 'nan(f0.0) = ', nan

end program
