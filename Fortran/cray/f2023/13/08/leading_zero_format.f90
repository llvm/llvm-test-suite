! Execution tests for LZ, LZP, and LZS edit descriptors (Fortran 2023).
! LZ  = processor-defined leading zero (flang prints the zero)
! LZP = always print the optional leading zero
! LZS = suppress the optional leading zero
program leading_zero_format
  implicit none
  real :: val

  ! === LZP tests (print leading zero) ===
  ! F descriptor
  write(*,'(A)') "LZP with F descriptor:"
  write(*,'(LZP,F6.1)') 0.2
  write(*,'(LZP,F10.3)') 0.2
  write(*,'(LZP,F4.1)') 0.1

  ! E descriptor
  write(*,'(A)') "LZP with E descriptor:"
  write(*,'(LZP,E10.3)') 0.2
  write(*,'(LZP,E12.5)') 0.2

  ! D descriptor
  write(*,'(A)') "LZP with D descriptor:"
  write(*,'(LZP,D10.3)') 0.2d0

  ! G descriptor (F-path: value in range)
  write(*,'(A)') "LZP with G descriptor (F-path):"
  write(*,'(LZP,G10.3)') 0.2

  ! G descriptor (E-path: value out of range)
  write(*,'(A)') "LZP with G descriptor (E-path):"
  write(*,'(LZP,G10.3)') 0.0002

  ! === LZS tests (suppress leading zero) ===
  ! F descriptor
  write(*,'(A)') "LZS with F descriptor:"
  write(*,'(LZS,F6.1)') 0.2
  write(*,'(LZS,F10.3)') 0.2
  write(*,'(LZS,F4.1)') 0.1

  ! E descriptor
  write(*,'(A)') "LZS with E descriptor:"
  write(*,'(LZS,E10.3)') 0.2
  write(*,'(LZS,E12.5)') 0.2

  ! D descriptor
  write(*,'(A)') "LZS with D descriptor:"
  write(*,'(LZS,D10.3)') 0.2d0

  ! G descriptor (F-path)
  write(*,'(A)') "LZS with G descriptor (F-path):"
  write(*,'(LZS,G10.3)') 0.2

  ! G descriptor (E-path)
  write(*,'(A)') "LZS with G descriptor (E-path):"
  write(*,'(LZS,G10.3)') 0.0002

  ! === LZ tests (processor-defined, flang prints the zero) ===
  write(*,'(A)') "LZ with F descriptor:"
  write(*,'(LZ,F6.1)') 0.2

  ! === Negative values less than 1 ===
  write(*,'(A)') "Negative values:"
  write(*,'(LZP,F7.1)') -0.2
  write(*,'(LZS,F7.1)') -0.2

  ! === Values >= 1 (leading zero control has no effect) ===
  write(*,'(A)') "Values >= 1 (no effect):"
  write(*,'(LZP,F6.1)') 1.2
  write(*,'(LZS,F6.1)') 1.2

  ! === Zero value ===
  write(*,'(A)') "Zero value:"
  write(*,'(LZP,F6.1)') 0.0
  write(*,'(LZS,F6.1)') 0.0

  ! === Switching mid-format ===
  write(*,'(A)') "Switch mid-format:"
  write(*,'(LZP,F6.1,LZS,F6.1)') 0.5, 0.5

  ! === With 1P scale factor (no effect on leading zero) ===
  write(*,'(A)') "With 1P scale (no effect):"
  write(*,'(LZP,1P,E10.3)') 0.2
  write(*,'(LZS,1P,E10.3)') 0.2

  ! === Without comma separator ===
  write(*,'(A)') "Without comma separator:"
  write(*,'(LZPF6.1)') 0.2
  write(*,'(LZSF6.1)') 0.2

  ! === Spaces between characters of the edit descriptors ===
  write(*,'(A)') "Spaces in descriptors:"
  write(*,'(L ZP,F6.1)') 0.2
  write(*,'(L ZS,F6.1)') 0.2
  write(*,'(LZ P,F6.1)') 0.2
  write(*,'(LZ S,F6.1)') 0.2
  write(*,'(L Z P,F6.1)') 0.2
  write(*,'(L Z S,F6.1)') 0.2
  write(*,'(L Z,F6.1)') 0.2
  write(*,'(L  Z  P,F6.1)') 0.2
  write(*,'(L  Z  S,F6.1)') 0.2

end program leading_zero_format
