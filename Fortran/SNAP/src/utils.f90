!-----------------------------------------------------------------------
!
! MODULE: utils_module
!> @brief
!> This module contains utility subroutines for handling file
!> open/close, errors, command line reading, and program termination.
!
!-----------------------------------------------------------------------

MODULE utils_module

  USE global_module, ONLY: i_knd, ifile, ofile

  USE dealloc_module

  USE plib_module, ONLY: iproc, root, pend, plock_omp, nthreads

  USE control_module, ONLY: swp_typ

  IMPLICIT NONE

  PUBLIC


  CONTAINS


  SUBROUTINE cmdarg ( ierr, error )

!-----------------------------------------------------------------------
!
! Read the command line for the input and output file names.
!
!-----------------------------------------------------------------------

    CHARACTER(LEN=64), INTENT(OUT) :: error

    INTEGER(i_knd), INTENT(OUT) :: ierr
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    CHARACTER(LEN=64) :: arg

    INTEGER(i_knd) :: narg, n
!_______________________________________________________________________
!
!   Return if not root. Loop over the first two command line arguments
!   to get i/o file names.
!_______________________________________________________________________

    IF ( iproc /= root ) RETURN

    ierr = 0
    error = ''

    narg = COMMAND_ARGUMENT_COUNT ( )

    IF ( narg /= 2 ) THEN
      ierr = 1
      error = '***ERROR: CMDARG: Missing command line entry'
      RETURN
    END IF

    DO n = 1, 2

      CALL GET_COMMAND_ARGUMENT ( n, arg )
      arg = ADJUSTL( arg )
      IF ( arg(1:1)=='-' .OR. arg(1:1)=='<' .OR. arg(1:1)=='>' ) THEN
        ierr = 1
        error = '***ERROR: CMDARG: Bad command line entry, arg:'
        WRITE( error, '(A,A,I2)') TRIM( error ), ' ', n
      ELSE IF ( n == 1 ) THEN
        ifile = arg
      ELSE IF ( n == 2 ) THEN
        ofile = arg
      END IF

    END DO
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE cmdarg


  SUBROUTINE open_file ( funit, fname, fstat, faction, ierr, error )

!-----------------------------------------------------------------------
!
! Open a file.
!
!-----------------------------------------------------------------------

    CHARACTER(LEN=*), INTENT(IN) :: fstat, faction

    CHARACTER(LEN=*), INTENT(IN) :: fname

    CHARACTER(LEN=64), INTENT(OUT) :: error

    INTEGER(i_knd), INTENT(IN) :: funit

    INTEGER(i_knd), INTENT(OUT) :: ierr
!_______________________________________________________________________
!
!   Local variables.
!_______________________________________________________________________

    CHARACTER(LEN=64) :: tname
!_______________________________________________________________________
!
!   Return if not root. Open the file with specified unit, name, status,
!   action.
!_______________________________________________________________________

    ierr = 0
    error = ''

    IF ( iproc /= root ) RETURN

    tname = TRIM( fname )

    OPEN( UNIT=funit, FILE=tname, STATUS=fstat, ACCESS='SEQUENTIAL',   &
          ACTION=faction, IOSTAT=ierr )

    IF ( ierr /= 0 ) THEN
      error = '***ERROR: OPEN_FILE: Unable to open file, unit:'
      WRITE( error, '(A,A,I2)') TRIM( error ), ' ', funit
    END IF
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE open_file


  SUBROUTINE close_file ( funit, ierr, error )

!-----------------------------------------------------------------------
!
! Close a file.
!
!-----------------------------------------------------------------------

    CHARACTER(LEN=64), INTENT(OUT) :: error

    INTEGER(i_knd), INTENT(IN) :: funit

    INTEGER(i_knd), INTENT(OUT) :: ierr
!_______________________________________________________________________
!
!   Close the file of specified unit number.
!_______________________________________________________________________

    ierr = 0
    error = ''

    IF ( iproc /= root ) RETURN

    CLOSE( UNIT=funit, IOSTAT=ierr )

    IF ( ierr /= 0 ) THEN
      error = '***ERROR: CLOSE_FILE: Unable to close file, unit:'
      WRITE( error, '(A,A,I2)') TRIM( error ), ' ', funit
    END IF
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE close_file


  SUBROUTINE print_error ( funit, error )

!-----------------------------------------------------------------------
!
! Print an error message to standard out or to file.
!
!-----------------------------------------------------------------------

    CHARACTER(LEN=*), INTENT(IN) :: error

    INTEGER(i_knd), INTENT(IN) :: funit
!_______________________________________________________________________
!
!   Print the error message.
!_______________________________________________________________________

    IF ( iproc /= root ) RETURN

    WRITE( *, 101 ) error
    IF ( funit > 0 ) WRITE( funit, 101 ) error
!_______________________________________________________________________

    101 FORMAT( 3X, A, / )
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE print_error


  SUBROUTINE stop_run ( flg1, flg2, flg3, flg4 )

!-----------------------------------------------------------------------
!
! Safely end program execution.
!
!-----------------------------------------------------------------------

   INTEGER(i_knd), INTENT(IN) :: flg1, flg2, flg3, flg4
!_______________________________________________________________________
!
!   Local Variables
!_______________________________________________________________________
!_______________________________________________________________________
!
!   Deallocate if necessary. Depends on flg1, 0/1=no/yes deallocate.
!_______________________________________________________________________

    IF ( flg1 > 0 ) CALL plock_omp ( 'destroy', nthreads )

    IF ( flg2 > 0 ) CALL dealloc_input ( flg2 )

    IF ( flg3 > 0 ) CALL dealloc_solve ( swp_typ, flg3 )

    IF ( iproc == root ) THEN
      IF ( flg4 == 0 ) THEN
        WRITE( *, '(1X,A)') 'Aww SNAP. Program failed. Try again.'
      ELSE IF ( flg4 == 1 ) THEN
        WRITE( *, '(1X,A)') 'Success! Done in a SNAP!'
      ELSE IF ( flg4 == 2 ) THEN
        WRITE( *, '(1X,A)') 'Oh SNAP. That did not converge. But ' //  &
          'take a look at the Timing Summary anyway!'
      END IF
    END IF

    CALL pend

    CALL EXIT ( 0 )

    !STOP
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE stop_run


END MODULE utils_module
