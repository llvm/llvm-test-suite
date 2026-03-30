! Self-checking execution tests for LZ, LZP, LZS edit descriptors
! and LEADING_ZERO= specifier (Fortran 2023).
!
! Each test compares actual formatted output against an expected string
! and prints PASS or FAIL. The reference output is just PASS lines.
program leading_zero_format
  implicit none
  character(len=*), parameter :: tmpfile = 'lz_test.tmp'
  character(len=80) :: got, got2, got3
  character(len=20) :: lz_val
  integer :: npass, nfail, u

  npass = 0
  nfail = 0

  ! ---------------------------------------------------------------
  ! Edit descriptor tests: LZP (print), LZS (suppress), LZ
  ! ---------------------------------------------------------------

  ! LZP with F descriptor
  write(got,'(LZP,F6.1)') 0.2
  call check("LZP F6.1", got, "   0.2")

  ! LZP with E descriptor
  write(got,'(LZP,E10.3)') 0.2
  call check("LZP E10.3", got, " 0.200E+00")

  ! LZP with D descriptor
  write(got,'(LZP,D10.3)') 0.2d0
  call check("LZP D10.3", got, " 0.200D+00")

  ! LZP with G descriptor (F-path, value in range)
  write(got,'(LZP,G10.3)') 0.2
  call check("LZP G10.3 F-path", got, " 0.200    ")

  ! LZP with G descriptor (E-path, value out of range)
  write(got,'(LZP,G10.3)') 0.0002
  call check("LZP G10.3 E-path", got, " 0.200E-03")

  ! LZS with F descriptor
  write(got,'(LZS,F6.1)') 0.2
  call check("LZS F6.1", got, "    .2")

  ! LZS with E descriptor
  write(got,'(LZS,E10.3)') 0.2
  call check("LZS E10.3", got, "  .200E+00")

  ! LZS with D descriptor
  write(got,'(LZS,D10.3)') 0.2d0
  call check("LZS D10.3", got, "  .200D+00")

  ! LZS with G descriptor (F-path)
  write(got,'(LZS,G10.3)') 0.2
  call check("LZS G10.3 F-path", got, "  .200    ")

  ! LZS with G descriptor (E-path)
  write(got,'(LZS,G10.3)') 0.0002
  call check("LZS G10.3 E-path", got, "  .200E-03")

  ! LZ (processor-defined; flang prints the zero)
  write(got,'(LZ,F6.1)') 0.2
  call check("LZ F6.1", got, "   0.2")

  ! LZ with E descriptor
  write(got,'(LZ,E10.3)') 0.2
  call check("LZ E10.3", got, " 0.200E+00")

  ! LZ with D descriptor
  write(got,'(LZ,D10.3)') 0.2d0
  call check("LZ D10.3", got, " 0.200D+00")

  ! LZ with G descriptor
  write(got,'(LZ,G10.3)') 0.2
  call check("LZ G10.3", got, " 0.200    ")

  ! LZ overrides OPEN SUPPRESS
  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', leading_zero='SUPPRESS')
  write(10,'(LZ,F6.1)') 0.4
  close(10)
  open(unit=10, file=tmpfile, status='old')
  read(10,'(A)') got
  call check("LZ overrides SUPPRESS", got, "   0.4")
  close(10, status='delete')

  ! ---------------------------------------------------------------
  ! Edge cases with edit descriptors
  ! ---------------------------------------------------------------

  ! Negative value < 1
  write(got,'(LZP,F7.1)') -0.2
  call check("LZP neg", got, "   -0.2")
  write(got,'(LZS,F7.1)') -0.2
  call check("LZS neg", got, "    -.2")

  ! Value >= 1 (leading zero control has no effect)
  write(got,'(LZP,F6.1)') 1.2
  call check("LZP >= 1", got, "   1.2")
  write(got,'(LZS,F6.1)') 1.2
  call check("LZS >= 1", got, "   1.2")

  ! Zero value
  write(got,'(LZP,F6.1)') 0.0
  call check("LZP zero", got, "   0.0")
  write(got,'(LZS,F6.1)') 0.0
  call check("LZS zero", got, "    .0")

  ! Switch mid-format
  write(got,'(LZP,F6.1,LZS,F6.1)') 0.5, 0.5
  call check("switch mid-fmt", got, "   0.5    .5")

  ! 1P scale factor with E descriptor
  write(got,'(LZP,1P,E10.3)') 0.2
  call check("LZP 1P E", got, " 2.000E-01")
  write(got,'(LZS,1P,E10.3)') 0.2
  call check("LZS 1P E", got, " 2.000E-01")

  ! Without comma separator (LZPF, LZSF)
  write(got,'(LZPF6.1)') 0.2
  call check("LZPF no comma", got, "   0.2")
  write(got,'(LZSF6.1)') 0.2
  call check("LZSF no comma", got, "    .2")

  ! Spaces in descriptors
  write(got,'(L ZP,F6.1)') 0.2
  call check("L ZP spaces", got, "   0.2")
  write(got,'(L Z S,F6.1)') 0.2
  call check("L Z S spaces", got, "    .2")
  write(got,'(L Z,F6.1)') 0.2
  call check("L Z spaces", got, "   0.2")

  ! ---------------------------------------------------------------
  ! LEADING_ZERO= specifier in OPEN
  ! ---------------------------------------------------------------

  ! OPEN with LEADING_ZERO='PRINT' — F and E descriptors
  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', leading_zero='PRINT')
  write(10,'(F6.1)') 0.3
  write(10,'(E10.3)') 0.3
  close(10)
  open(unit=10, file=tmpfile, status='old')
  read(10,'(A)') got
  call check("OPEN PRINT F6.1", got, "   0.3")
  read(10,'(A)') got
  call check("OPEN PRINT E10.3", got, " 0.300E+00")
  close(10, status='delete')

  ! OPEN with LEADING_ZERO='SUPPRESS' — F and E descriptors
  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', leading_zero='SUPPRESS')
  write(10,'(F6.1)') 0.3
  write(10,'(E10.3)') 0.3
  close(10)
  open(unit=10, file=tmpfile, status='old')
  read(10,'(A)') got
  call check("OPEN SUPPRESS F6.1", got, "    .3")
  read(10,'(A)') got
  call check("OPEN SUPPRESS E10.3", got, "  .300E+00")
  close(10, status='delete')

  ! OPEN with LEADING_ZERO='PROCESSOR_DEFINED'
  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', leading_zero='PROCESSOR_DEFINED')
  write(10,'(F6.1)') 0.3
  write(10,'(E10.3)') 0.3
  write(10,'(D10.3)') 0.3d0
  close(10)
  open(unit=10, file=tmpfile, status='old')
  read(10,'(A)') got
  call check("OPEN PROC_DEF F6.1", got, "   0.3")
  read(10,'(A)') got
  call check("OPEN PROC_DEF E10.3", got, " 0.300E+00")
  read(10,'(A)') got
  call check("OPEN PROC_DEF D10.3", got, " 0.300D+00")
  close(10, status='delete')

  ! WRITE with LEADING_ZERO='PROCESSOR_DEFINED'
  open(unit=10, file=tmpfile, status='replace', form='formatted')
  write(10,'(F6.1)', leading_zero='PROCESSOR_DEFINED') 0.3
  close(10)
  open(unit=10, file=tmpfile, status='old')
  read(10,'(A)') got
  call check("WRITE PROC_DEF F6.1", got, "   0.3")
  close(10, status='delete')

  ! LZS overrides PROCESSOR_DEFINED in OPEN
  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', leading_zero='PROCESSOR_DEFINED')
  write(10,'(LZS,F6.1)') 0.3
  close(10)
  open(unit=10, file=tmpfile, status='old')
  read(10,'(A)') got
  call check("LZS overrides PROC_DEF", got, "    .3")
  close(10, status='delete')

  ! Edit descriptor overrides OPEN specifier
  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', leading_zero='SUPPRESS')
  write(10,'(LZP,F6.1)') 0.4
  close(10)
  open(unit=10, file=tmpfile, status='old')
  read(10,'(A)') got
  call check("LZP overrides SUPPRESS", got, "   0.4")
  close(10, status='delete')

  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', leading_zero='PRINT')
  write(10,'(LZS,F6.1)') 0.4
  close(10)
  open(unit=10, file=tmpfile, status='old')
  read(10,'(A)') got
  call check("LZS overrides PRINT", got, "    .4")
  close(10, status='delete')

  ! OPEN PRINT with D, G, ES, EN descriptors
  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', leading_zero='PRINT')
  write(10,'(D10.3)') 0.5d0
  write(10,'(G10.3)') 0.5
  write(10,'(ES10.3)') 0.2
  write(10,'(EN12.3)') 0.2
  close(10)
  open(unit=10, file=tmpfile, status='old')
  read(10,'(A)') got
  call check("OPEN PRINT D10.3", got, " 0.500D+00")
  read(10,'(A)') got
  call check("OPEN PRINT G10.3", got, " 0.500    ")
  read(10,'(A)') got
  call check("OPEN PRINT ES10.3", got, " 2.000E-01")
  read(10,'(A)') got
  call check("OPEN PRINT EN12.3", got, " 200.000E-03")
  close(10, status='delete')

  ! OPEN SUPPRESS with D, G, ES, EN descriptors
  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', leading_zero='SUPPRESS')
  write(10,'(D10.3)') 0.5d0
  write(10,'(G10.3)') 0.5
  write(10,'(ES10.3)') 0.2
  write(10,'(EN12.3)') 0.2
  close(10)
  open(unit=10, file=tmpfile, status='old')
  read(10,'(A)') got
  call check("OPEN SUPPRESS D10.3", got, "  .500D+00")
  read(10,'(A)') got
  call check("OPEN SUPPRESS G10.3", got, "  .500    ")
  read(10,'(A)') got
  call check("OPEN SUPPRESS ES10.3", got, " 2.000E-01")
  read(10,'(A)') got
  call check("OPEN SUPPRESS EN12.3", got, " 200.000E-03")
  close(10, status='delete')

  ! Negative value with OPEN LEADING_ZERO=
  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', leading_zero='PRINT')
  write(10,'(F7.2)') -0.5
  close(10)
  open(unit=10, file=tmpfile, status='old')
  read(10,'(A)') got
  call check("OPEN PRINT neg", got, "  -0.50")
  close(10, status='delete')

  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', leading_zero='SUPPRESS')
  write(10,'(F7.2)') -0.5
  close(10)
  open(unit=10, file=tmpfile, status='old')
  read(10,'(A)') got
  call check("OPEN SUPPRESS neg", got, "   -.50")
  close(10, status='delete')

  ! Value >= 1 with OPEN (no effect)
  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', leading_zero='SUPPRESS')
  write(10,'(F6.1)') 1.5
  close(10)
  open(unit=10, file=tmpfile, status='old')
  read(10,'(A)') got
  call check("OPEN SUPPRESS >= 1", got, "   1.5")
  close(10, status='delete')

  ! Persistence across multiple WRITEs
  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', leading_zero='SUPPRESS')
  write(10,'(F6.1)') 0.1
  write(10,'(F6.1)') 0.2
  close(10)
  open(unit=10, file=tmpfile, status='old')
  read(10,'(A)') got
  call check("OPEN persist 1", got, "    .1")
  read(10,'(A)') got
  call check("OPEN persist 2", got, "    .2")
  close(10, status='delete')

  ! Case insensitivity of LEADING_ZERO= value
  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', leading_zero='print')
  write(10,'(F6.1)') 0.6
  close(10)
  open(unit=10, file=tmpfile, status='old')
  read(10,'(A)') got
  call check("OPEN lowercase print", got, "   0.6")
  close(10, status='delete')

  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', leading_zero='suppress')
  write(10,'(F6.1)') 0.6
  close(10)
  open(unit=10, file=tmpfile, status='old')
  read(10,'(A)') got
  call check("OPEN lowercase suppress", got, "    .6")
  close(10, status='delete')

  ! Edit descriptor resets after format completes
  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', leading_zero='PRINT')
  write(10,'(LZS,F6.1)') 0.7
  write(10,'(F6.1)') 0.7
  close(10)
  open(unit=10, file=tmpfile, status='old')
  read(10,'(A)') got
  call check("LZS then reset P", got, "    .7")
  read(10,'(A)') got
  call check("reset to PRINT", got, "   0.7")
  close(10, status='delete')

  ! Multiple items in one WRITE
  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', leading_zero='SUPPRESS')
  write(10,'(F6.1,F6.1)') 0.1, 0.2
  close(10)
  open(unit=10, file=tmpfile, status='old')
  read(10,'(A)') got
  call check("OPEN SUPPRESS multi", got, "    .1    .2")
  close(10, status='delete')

  ! ---------------------------------------------------------------
  ! INQUIRE with LEADING_ZERO=
  ! ---------------------------------------------------------------

  ! Default (no LEADING_ZERO specified in OPEN)
  open(unit=10, file=tmpfile, status='replace', form='formatted')
  inquire(unit=10, leading_zero=lz_val)
  call check("INQUIRE default", lz_val, "PRINT")
  close(10, status='delete')

  ! After OPEN with PRINT
  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', leading_zero='PRINT')
  inquire(unit=10, leading_zero=lz_val)
  call check("INQUIRE PRINT", lz_val, "PRINT")
  close(10, status='delete')

  ! After OPEN with SUPPRESS
  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', leading_zero='SUPPRESS')
  inquire(unit=10, leading_zero=lz_val)
  call check("INQUIRE SUPPRESS", lz_val, "SUPPRESS")
  close(10, status='delete')

  ! After OPEN with PROCESSOR_DEFINED
  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', leading_zero='PROCESSOR_DEFINED')
  inquire(unit=10, leading_zero=lz_val)
  call check("INQUIRE PROC_DEF", lz_val, "PRINT")
  close(10, status='delete')

  ! Unconnected unit
  inquire(unit=99, leading_zero=lz_val)
  call check("INQUIRE unconnected", lz_val, "UNDEFINED")

  ! INQUIRE by file name
  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', leading_zero='SUPPRESS')
  inquire(file=tmpfile, leading_zero=lz_val)
  call check("INQUIRE by file", lz_val, "SUPPRESS")
  close(10, status='delete')

  ! ---------------------------------------------------------------
  ! LEADING_ZERO= with NEWUNIT=
  ! ---------------------------------------------------------------
  open(newunit=u, file=tmpfile, status='replace', &
       form='formatted', leading_zero='SUPPRESS')
  write(u,'(F6.1)') 0.8
  close(u)
  open(newunit=u, file=tmpfile, status='old')
  read(u,'(A)') got
  call check("NEWUNIT SUPPRESS", got, "    .8")
  close(u, status='delete')

  ! ---------------------------------------------------------------
  ! LEADING_ZERO= changed on reopen
  ! ---------------------------------------------------------------
  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', leading_zero='PRINT')
  write(10,'(F6.1)') 0.9
  close(10)
  open(unit=10, file=tmpfile, status='old', &
       form='formatted', leading_zero='SUPPRESS')
  inquire(unit=10, leading_zero=lz_val)
  call check("reopen changed", lz_val, "SUPPRESS")
  close(10, status='delete')

  ! ---------------------------------------------------------------
  ! LEADING_ZERO= with list-directed output
  ! ---------------------------------------------------------------
  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', leading_zero='PRINT')
  write(10,*) 0.5
  close(10)
  open(unit=10, file=tmpfile, status='old')
  read(10,'(A)') got
  call check("OPEN PRINT list-dir", got, " .5")

  close(10, status='delete')

  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', leading_zero='SUPPRESS')
  write(10,*) 0.5
  close(10)
  open(unit=10, file=tmpfile, status='old')
  read(10,'(A)') got
  call check("OPEN SUPPRESS list-dir", got, " .5")
  close(10, status='delete')

  ! ---------------------------------------------------------------
  ! LEADING_ZERO= with non-advancing I/O
  ! ---------------------------------------------------------------
  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', leading_zero='SUPPRESS')
  write(10,'(F6.1)', advance='no') 0.1
  write(10,'(F6.1)') 0.2
  close(10)
  open(unit=10, file=tmpfile, status='old')
  read(10,'(A)') got
  call check("non-advancing SUPPRESS", got, "    .1    .2")
  close(10, status='delete')

  ! ---------------------------------------------------------------
  ! LEADING_ZERO= with direct-access formatted I/O
  ! ---------------------------------------------------------------
  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', access='direct', recl=20, leading_zero='SUPPRESS')
  write(10,'(F6.1)', rec=1) 0.3
  close(10)
  open(unit=10, file=tmpfile, status='old', &
       form='formatted', access='direct', recl=20)
  read(10,'(A)', rec=1) got
  call check("direct-access SUPPRESS", got, "    .3")
  close(10, status='delete')

  ! ---------------------------------------------------------------
  ! LEADING_ZERO= specifier in WRITE statement
  ! ---------------------------------------------------------------

  ! WRITE with LEADING_ZERO='PRINT'
  open(unit=10, file=tmpfile, status='replace', form='formatted')
  write(10,'(F6.1)', leading_zero='PRINT') 0.5
  close(10)
  open(unit=10, file=tmpfile, status='old')
  read(10,'(A)') got
  call check("WRITE PRINT F6.1", got, "   0.5")
  close(10, status='delete')

  ! WRITE with LEADING_ZERO='SUPPRESS'
  open(unit=10, file=tmpfile, status='replace', form='formatted')
  write(10,'(F6.1)', leading_zero='SUPPRESS') 0.5
  close(10)
  open(unit=10, file=tmpfile, status='old')
  read(10,'(A)') got
  call check("WRITE SUPPRESS F6.1", got, "    .5")
  close(10, status='delete')

  ! WRITE LEADING_ZERO= overrides OPEN LEADING_ZERO=
  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', leading_zero='SUPPRESS')
  write(10,'(F6.1)', leading_zero='PRINT') 0.6
  close(10)
  open(unit=10, file=tmpfile, status='old')
  read(10,'(A)') got
  call check("WRITE PRINT overrides OPEN SUPPRESS", got, "   0.6")
  close(10, status='delete')

  ! WRITE LEADING_ZERO= does not persist to next WRITE
  open(unit=10, file=tmpfile, status='replace', &
       form='formatted', leading_zero='PRINT')
  write(10,'(F6.1)', leading_zero='SUPPRESS') 0.7
  write(10,'(F6.1)') 0.7
  close(10)
  open(unit=10, file=tmpfile, status='old')
  read(10,'(A)') got
  call check("WRITE SUPPRESS temp", got, "    .7")
  read(10,'(A)') got
  call check("WRITE reverts to OPEN", got, "   0.7")
  close(10, status='delete')

  ! Edit descriptor in format overrides WRITE LEADING_ZERO=
  open(unit=10, file=tmpfile, status='replace', form='formatted')
  write(10,'(LZS,F6.1)', leading_zero='PRINT') 0.8
  close(10)
  open(unit=10, file=tmpfile, status='old')
  read(10,'(A)') got
  call check("LZS overrides WRITE PRINT", got, "    .8")
  close(10, status='delete')

  ! ---------------------------------------------------------------
  ! Summary
  ! ---------------------------------------------------------------
  write(*,'(A,I0,A,I0,A)') "Result: ", npass, " passed, ", nfail, " failed"
  if (nfail > 0) stop 1

contains
  subroutine check(name, actual, expected)
    character(len=*), intent(in) :: name, actual, expected
    if (trim(actual) == trim(expected)) then
      write(*,'(A,A)') "PASS: ", name
      npass = npass + 1
    else
      write(*,'(A,A)') "FAIL: ", name
      write(*,'(A,A,A)') "  Expected: [", trim(expected), "]"
      write(*,'(A,A,A)') "  Got:      [", trim(actual), "]"
      nfail = nfail + 1
    end if
  end subroutine

end program leading_zero_format
