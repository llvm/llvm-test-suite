! Test for SPLIT Fortran 2023 Standard intrinsic subroutine (16.9.197).
!
! SPLIT(STRING, SET, POS [, BACK]) finds successive tokens in STRING
! delimited by characters in SET. POS is updated on each call to allow
! iterating through all tokens.

SUBROUTINE DO_TESTS (STRING, SET, NOTE)
  CHARACTER (LEN=:), ALLOCATABLE :: STRING, SET, NOTE
  INTEGER :: CASES = 0;
  INTEGER P, ISTART, IEND
  SAVE CASES

  CASES = CASES + 1
  PRINT *, "==== Case ", CASES, ": ", NOTE, " ===="
  PRINT *, ' STRING = "', STRING, '"'
  PRINT *, ' SET = "', SET, '"'
  PRINT *, ''

  PRINT *, "  ---- Test", CASES, "- 1: SPLIT without BACK ----"
  P=0
  DO
    IF (P > LEN (STRING)) EXIT
    ISTART = P + 1
    CALL SPLIT (STRING, SET, P)
    IEND = P - 1
    PRINT 10, STRING (ISTART:IEND)
  END DO

  PRINT *, "  ---- Test", CASES, "- 2: SPLIT with BACK=.FALSE. ----"
  P=0
  DO
    IF (P > LEN (STRING)) EXIT
    ISTART = P + 1
    CALL SPLIT (STRING, SET, P, .FALSE.)
    IEND = P - 1
    PRINT 10, STRING (ISTART:IEND)
  END DO

  PRINT *, "  ---- Test", CASES, "- 3: SPLIT with BACK=.TRUE. ----"
  P = LEN (STRING) + 1
  DO
    IF (P < 1) EXIT
    IEND = P - 1
    CALL SPLIT (STRING, SET, P, .TRUE.)
    ISTART = P + 1
    PRINT 10, STRING (ISTART:IEND)
  END DO

  10 FORMAT (T7, '"', A, '"')

END

PROGRAM SPLIT01
  CHARACTER (LEN=:), ALLOCATABLE :: STRING, SET, NOTE

  INTERFACE
    SUBROUTINE DO_TESTS (STRING, SET, NOTE)
      CHARACTER(LEN=:), ALLOCATABLE :: STRING, SET, NOTE
    ENDSUBROUTINE
  ENDINTERFACE

! Case 1
  STRING = "first,seconds third"
  SET = ", :;"
  NOTE = "common case"
  CALL DO_TESTS (STRING, SET, NOTE)
  DEALLOCATE(STRING, NOTE)

! Case 2
  STRING = ",first,seconds third;"
  NOTE = "first and last characters are delimiters"
  CALL DO_TESTS (STRING, SET, NOTE)
  DEALLOCATE(STRING, NOTE)

! Case 3
  STRING = ",first,seconds; ,:;third,"
  NOTE = "multiple delimiters in a row"
  CALL DO_TESTS (STRING, SET, NOTE)
  DEALLOCATE(STRING, NOTE)

! Case 4
  STRING = ",first,seconds;third_third"
  NOTE = "the last token is the longest"
  CALL DO_TESTS (STRING, SET, NOTE)
  DEALLOCATE(SET, NOTE)

! Case 5
  SET = ""
  NOTE = "SET is zero size"
  CALL DO_TESTS (STRING, SET, NOTE)
  DEALLOCATE(STRING, SET, NOTE)

! Case 6
  STRING = "f,s;t"
  SET = ", :;"
  NOTE = "one character tokens"
  CALL DO_TESTS (STRING, SET, NOTE)
  DEALLOCATE(STRING, NOTE)

! Case 7
  STRING = ""
  NOTE = "STRING is zero size"
  CALL DO_TESTS (STRING, SET, NOTE)
  DEALLOCATE(STRING, SET, NOTE)

! Case 8
  STRING = ""
  SET = ""
  NOTE = "both STRING and SET are zero size"
  CALL DO_TESTS (STRING, SET, NOTE)
  DEALLOCATE(STRING, SET, NOTE)
END PROGRAM SPLIT01
