!-----------------------------------------------------------------------
!
! MODULE: input_module
!> @brief
!> This module controls the reading of the input file and checking the
!> input parameters for acceptable values.
!
!-----------------------------------------------------------------------

MODULE input_module

  USE global_module, ONLY: i_knd, r_knd, iunit, ounit, zero, one

  USE plib_module, ONLY: npey, npez, ichunk, nthreads, iproc, root,    &
    comm_snap, bcast, nproc, barrier, nnested

  USE geom_module, ONLY: ndimen, nx, ny, nz, lx, ly, lz

  USE sn_module, ONLY: nang, nmom

  USE data_module, ONLY: ng, mat_opt, src_opt, scatp

  USE control_module, ONLY: epsi, iitm, oitm, timedep, tf, nsteps,     &
    swp_typ, multiswp, angcpy, it_det, fluxp, fixup, soloutp, kplane,  &
    popout

  USE utils_module, ONLY: print_error, stop_run

  USE time_module, ONLY: tinp, wtime

  IMPLICIT NONE

  PRIVATE

  PUBLIC :: input_read


  CONTAINS


  SUBROUTINE input_read

!-----------------------------------------------------------------------
!
! Read the input file.
!
!-----------------------------------------------------------------------
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    CHARACTER(LEN=64) :: error

    INTEGER(i_knd) :: ierr

    REAL(r_knd) :: t1, t2

    NAMELIST / invar / npey, npez, ichunk, nthreads, ndimen, nx, ny,   &
      nz, lx, ly, lz, nmom, nang, ng, epsi, iitm, oitm, timedep, tf,   &
      nsteps, mat_opt, src_opt, scatp, swp_typ, multiswp, it_det,      &
      fluxp, fixup, nnested, soloutp, kplane, popout, angcpy
!_______________________________________________________________________
!
!   Read the input file. Echo to output file. Call for an input variable
!   check. Only root reads, echoes, checks input.
!_______________________________________________________________________

    CALL wtime ( t1 )

    ierr = 0

    IF ( iproc == root ) READ( iunit, NML=invar, IOSTAT=ierr )
    CALL bcast ( ierr, comm_snap, root )
    IF ( ierr /= 0 ) THEN
      error = '***ERROR: READ_INPUT: Problem reading input file'
      CALL print_error ( 0, error )
      CALL print_error ( ounit, error )
      CALL stop_run ( 0, 0, 0, 0 )
    END IF

    IF ( iproc == root ) THEN
      CALL input_echo
      CALL input_check ( ierr )
    END IF

    CALL bcast ( ierr, comm_snap, root )
    IF ( ierr /= 0 ) THEN
      error = '***ERROR: READ_INPUT: Input file errors'
      CALL print_error ( ounit, error )
      CALL stop_run ( 0, 0, 0, 0 )
    END IF
!_______________________________________________________________________
!
!   Broadcast the data to all processes.
!_______________________________________________________________________

    CALL input_var_bcast

    CALL wtime ( t2 )
    tinp = t2 - t1
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE input_read


  SUBROUTINE input_echo

!-----------------------------------------------------------------------
!
! Print the input variables to the output file.
!
!-----------------------------------------------------------------------
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    CHARACTER(LEN=1) :: star='*'

    INTEGER(i_knd) :: i
!_______________________________________________________________________

    WRITE( ounit, 121 ) ( star, i = 1, 80 )
    WRITE( ounit, 122 ) ( star, i = 1, 80 )
    WRITE( ounit, 123 )
    WRITE( ounit, 124 ) npey, npez, ichunk, nthreads, nnested
    WRITE( ounit, 125 ) ndimen, nx, ny, nz
    WRITE( ounit, 126 ) lx, ly, lz
    WRITE( ounit, 127 ) nmom, nang
    WRITE( ounit, 128 ) ng, mat_opt, src_opt, scatp
    WRITE( ounit, 129 ) epsi, iitm, oitm, timedep, tf, nsteps, swp_typ,&
      multiswp, angcpy, it_det, soloutp, kplane, popout, fluxp, fixup
    WRITE( ounit, 121 ) ( star, i = 1, 80 )
!_______________________________________________________________________

    121 FORMAT( /, 80A, / )
    122 FORMAT( 10X,                                                   &
                'keyword Input Echo - Values from input or default', /,&
                80A, / )

    123 FORMAT( 2X, 'NML=invar' )

    124 FORMAT( 5X, 'npey= ', I5, /,                                   &
                5X, 'npez= ', I5, /,                                   &
                5X, 'ichunk= ', I5, /,                                 &
                5X, 'nthreads= ', I5, /,                               &
                5X, 'nnested= ', I3 )

    125 FORMAT( 5X, 'ndimen= ', I2, /,                                 &
                5X, 'nx= ', I5, /,                                     &
                5X, 'ny= ', I5, /,                                     &
                5X, 'nz= ', I5 )

    126 FORMAT( 5X, 'lx= ', ES11.4, /,                                 &
                5X, 'ly= ', ES11.4, /,                                 &
                5X, 'lz= ', ES11.4 )

    127 FORMAT( 5X, 'nmom= ', I3, /,                                   &
                5X, 'nang= ', I4 )

    128 FORMAT( 5X, 'ng= ', I4, /,                                     &
                5X, 'mat_opt= ', I2, /,                                &
                5X, 'src_opt= ', I2, /,                                &
                5X, 'scatp= ', I2 )

    129 FORMAT( 5X, 'epsi= ', ES11.4, /,                               &
                5X, 'iitm= ', I3, /,                                   &
                5X, 'oitm= ', I4, /,                                   &
                5X, 'timedep= ', I2, /,                                &
                5X, 'tf= ', ES11.4, /,                                 &
                5X, 'nsteps= ', I5, /,                                 &
                5X, 'swp_typ= ', I2, /,                                &
                5X, 'multiswp= ', I2, /,                               &
                5X, 'angcpy= ', I2, /,                                 &
                5X, 'it_det= ', I2, /,                                 &
                5X, 'soloutp= ', I2, /,                                &
                5X, 'kplane= ', I4, /,                                 &
                5X, 'popout= ', I2, /,                                 &
                5X, 'fluxp= ', I2, /,                                  &
                5X, 'fixup= ', I2 )
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE input_echo


  SUBROUTINE input_check ( ierr )

!-----------------------------------------------------------------------
!
! Checks input for valid entries
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(INOUT) :: ierr
!_______________________________________________________________________
!
!   Local Variables
!_______________________________________________________________________

    CHARACTER(LEN=64) :: error
!_______________________________________________________________________
!
!   Check the parallel environment variables
!_______________________________________________________________________

    ierr = 0
!_______________________________________________________________________
!
!   Parallel processing inputs.
!_______________________________________________________________________

    IF ( npey < 1 ) THEN
      ierr = ierr + 1
      error = '***ERROR: INPUT_CHECK: NPEY must be positive'
      CALL print_error ( ounit, error )
    END IF

    IF ( npez < 1 ) THEN
      ierr = ierr + 1
      error = '***ERROR: INPUT_CHECK: NPEZ must be positive'
      CALL print_error ( ounit, error )
    END IF

    IF ( ndimen>1 .AND. MOD( ny, npey )/=0 ) THEN
      ierr = ierr + 1
      error = '***ERROR: INPUT_CHECK: NPEY must divide evenly into NY'
      CALL print_error ( ounit, error )
    END IF

    IF ( ndimen>2 .AND. MOD( nz, npez )/=0 ) THEN
      ierr = ierr + 1
      error = '***ERROR: INPUT_CHECK: NPEZ must divide evenly into NZ'
      CALL print_error ( ounit, error )
    END IF

    IF ( ndimen<2 .AND. npey/=1 ) THEN
      ierr = ierr + 1
      error = '***ERROR: INPUT_CHECK: NPEY must be 1 if not 2-D problem'
      CALL print_error ( ounit, error )
    END IF

    IF ( ndimen<3 .AND. npez/=1 ) THEN
      ierr = ierr + 1
      error = '***ERROR: INPUT_CHECK: NPEZ must be 1 if not 3-D problem'
      CALL print_error ( ounit, error )
    END IF

    IF ( npey*npez /= nproc ) THEN
      ierr = ierr + 1
      error = '***ERROR: INPUT_CHECK: NPEY*NPEZ must equal MPI NPROC'
      CALL print_error ( ounit, error )
    END IF

    IF ( ichunk > nx ) THEN
      ichunk = nx
      error = '*WARNING: INPUT_CHECK: ICHUNK cannot exceed NX; ' //    &
              'reset to NX'
      CALL print_error ( ounit, error )
    END IF

    IF ( ndimen==1 .AND. ichunk/=nx ) ichunk = nx

    IF ( MOD( nx, ichunk ) /= 0 ) THEN
      ierr = ierr + 1
      error = '***ERROR: INPUT_CHECK: ICHUNK must divide evenly into NX'
      CALL print_error ( ounit, error )
    END IF

    IF ( nthreads < 1 ) THEN
      nthreads = 1
      error = '*WARNING: INPUT_CHECK: NTHREADS must be positive; ' //  &
              'reset to 1'
      CALL print_error ( ounit, error )
    END IF

    IF ( nnested < 1 ) THEN
      nnested = 1
      error = '*WARNING: INPUT_CHECK: NNESTED must be positive; ' //   &
              'reset to 1'
      CALL print_error ( ounit, error )
    END IF

    IF ( multiswp/=0 .AND. nproc==1 ) THEN
      multiswp = 0
      error = '*WARNING: INPUT_CHECK: MULTISWP reset to 0 for serial'
      CALL print_error ( ounit, error )
    END IF
!_______________________________________________________________________
!
!   Geometry inputs.
!_______________________________________________________________________

    IF ( ndimen<1 .OR. ndimen>3 ) THEN
      ierr = ierr + 1
      error = '***ERROR: INPUT_CHECK: NDIMEN must be 1, 2, or 3'
      CALL print_error ( ounit, error )
    END IF

!    IF ( nx < 4 ) THEN
!      ierr = ierr + 1
!      error = '***ERROR: INPUT_CHECK: NX must be at least 4'
!      CALL print_error ( ounit, error )
!    END IF

!    IF ( ny<4 .AND. ndimen>1 ) THEN
!      ierr = ierr + 1
!      error = '***ERROR: INPUT_CHECK: NY must be at least 4'
!      CALL print_error ( ounit, error )
!    END IF

!    IF ( nz<4 .AND. ndimen>2 ) THEN
!      ierr = ierr + 1
!      error = '***ERROR: INPUT_CHECK: NZ must be at least 4'
!      CALL print_error ( ounit, error )
!    END IF

    IF ( lx <= zero ) THEN
      ierr = ierr + 1
      error = '***ERROR: INPUT_CHECK: LX must be positive'
      CALL print_error ( ounit, error )
    END IF

    IF ( ly <= zero ) THEN
      ierr = ierr + 1
      error = '***ERROR: INPUT_CHECK: LY must be positive'
      CALL print_error ( ounit, error )
    END IF

    IF ( lz <= zero ) THEN
      ierr = ierr + 1
      error = '***ERROR: INPUT_CHECK: LZ must be positive'
      CALL print_error ( ounit, error )
    END IF

    IF ( ndimen<2 .AND. ( ny>1 .OR. ly/=one ) ) THEN
      ny = 1
      ly = zero
      error = '*WARNING: INPUT_CHECK: NY and LY reset for 1-D problem'
      CALL print_error ( ounit, error )
    END IF

    IF ( ndimen<3 .AND. ( nz>1 .OR. lz/=one ) ) THEN
      nz = 1
      lz = zero
      error = '*WARNING: INPUT_CHECK: NZ and LZ reset for 1/2-D problem'
      CALL print_error ( ounit, error )
    END IF
!_______________________________________________________________________
!
!   Sn inputs.
!_______________________________________________________________________

    IF ( nmom<1 .OR. nmom>4 ) THEN
      ierr = ierr + 1
      error = '***ERROR: INPUT_CHECK: NMOM must be positive and ' //   &
              'less than 5'
      CALL print_error ( ounit, error )
    END IF

    IF ( nang < 1 ) THEN
      ierr = ierr + 1
      error = '***ERROR: INPUT_CHECK: NANG must be positive'
      CALL print_error ( ounit, error )
    END IF
!_______________________________________________________________________
!
!   Data inputs.
!_______________________________________________________________________

    IF ( ng < 1 ) THEN
      ierr = ierr + 1
      error = '***ERROR: INPUT_CHECK: NG must be positive'
      CALL print_error ( ounit, error )
    END IF

    IF ( nthreads > ng ) THEN
      nthreads = ng
      error = '*WARNING: INPUT_CHECK: NTHREADS should be <= NG; ' //   &
              'reset to NG'
      CALL print_error ( ounit, error )
    END IF

    IF ( mat_opt<0 .OR. mat_opt>2) THEN
      ierr = ierr + 1
      error = '***ERROR: INPUT_CHECK: MAT_OPT must be 0/1/2'
      CALL print_error ( ounit, error )
    END IF

    IF ( src_opt<0 .OR. src_opt>3) THEN
      ierr = ierr + 1
      error = '***ERROR: INPUT_CHECK: SRC_OPT must be 0/1/2/3'
      CALL print_error ( ounit, error )
    END IF

!    IF ( src_opt==3 .AND. mat_opt/=0 ) THEN
!      mat_opt = 0
!      error = '*WARNING: INPUT_CHECK: MAT_OPT must be 0 for SRC_OPT=3'
!      CALL print_error ( ounit, error )
!    END IF

    IF ( scatp/=0 .AND. scatp/=1 ) THEN
      scatp = 0
      error = '*WARNING: INPUT_CHECK: SCATP must be 0/1; reset to 0'
      CALL print_error ( ounit, error )
    END IF
!_______________________________________________________________________
!
!   Control inputs.
!_______________________________________________________________________

    IF ( epsi<=zero .OR. epsi>=1.0E-2_r_knd ) THEN
      ierr = ierr + 1
      error = '***ERROR: INPUT_CHECK: EPSI must be positive, less ' // &
              'than 1.0E-2'
      CALL print_error ( ounit, error )
    END IF

    IF ( iitm < 1 ) THEN
      ierr = ierr + 1
      error = '***ERROR: INPUT_CHECK: IITM must be positive'
      CALL print_error ( ounit, error )
    END IF

    IF ( oitm < 1 ) THEN
      ierr = ierr + 1
      error = '***ERROR: INPUT_CHECK: OITM must be positive'
      CALL print_error ( ounit, error )
    END IF

    IF ( timedep/=0 .AND. timedep/=1 ) THEN
      timedep = 0
      error = '*WARNING: INPUT_CHECK: TIMEDEP must be 0/1; reset to 0'
      CALL print_error ( ounit, error )
    END IF

    IF ( timedep==1 .AND. tf<=zero ) THEN
      ierr = ierr + 1
      error = '***ERROR: INPUT_CHECK: TF must be positive'
      CALL print_error ( ounit, error )
    END IF

    IF ( timedep==1 .AND. nsteps<1 ) THEN
      ierr = ierr + 1
      error = '***ERROR: INPUT_CHECK: NSTEPS must be positive'
      CALL print_error ( ounit, error )
    END IF

    IF ( timedep==0 .AND. nsteps/=1 ) THEN
      nsteps = 1
      error = '*WARNING: INPUT_CHECK: NSTEPS reset to 1 for ' //       &
              'static calc'
      CALL print_error ( ounit, error )
    END IF

    IF ( swp_typ/=0 .AND. swp_typ/=1 ) THEN
      swp_typ = 0
      error = '*WARNING: INPUT_CHECK: SWP_TYP must equal 0/1; ' //     &
              'reset to 0'
      CALL print_error ( ounit, error )
    END IF

    IF ( swp_typ/=0 .AND. ndimen==1 ) THEN
      swp_typ = 0
      error = '*WARNING: INPUT_CHECK: SWP_TYP must be 0 for 1-D; ' //  &
              'reset to 0'
      CALL print_error ( ounit, error )
    END IF

    IF ( nnested>1 .AND. swp_typ==0 ) THEN
      ierr = ierr + 1
      error = '***ERROR: INPUT_CHECK: SWP_TYP must be 1 for nested' // &
              ' threading'
      CALL print_error ( ounit, error )
    END IF

!    IF ( nproc>1 .AND. nnested>1 .AND. swp_typ==0 ) THEN
!      ierr = ierr + 1
!      error = '***ERROR: INPUT_CHECK: SWP_TYP=0 + NNESTED>1 ' //       &
!              'requires NPROC=1'
!      CALL print_error ( ounit, error )
!    END IF

    IF ( multiswp/=0 .AND. multiswp/=1 ) THEN
      multiswp = 0
      error = '*WARNING: INPUT_CHECK: MULTISWP must equal 0/1; ' //    &
              'reset to 0'
      CALL print_error ( ounit, error )
    END IF

    IF ( ndimen==1 .AND. multiswp==1 ) THEN
      multiswp = 0
      error = '*WARNING: INPUT_CHECK: MULTISWP must equal 0 in 1D;' // &
              ' reset to 0'
      CALL print_error ( ounit, error )
    END IF

    IF ( multiswp==1 .AND. swp_typ==1 ) THEN
      ierr = ierr + 1
      error = '***ERROR: INPUT_CHECK: MULTISWP must equal 0 if ' //    &
              'SWP_TYP is 1'
      CALL print_error ( ounit, error )
    END IF

    IF ( angcpy/=1 .AND. angcpy/=2 ) THEN
      angcpy = 1
      error = '*WARNING: INPUT_CHECK: ANGCPY must be 1 or 2; ' //      &
              'reset to 1'
      CALL print_error ( ounit, error )
    END IF

    IF ( it_det/=0 .AND. it_det/=1 ) THEN
      it_det = 0
      error = '*WARNING: INPUT_CHECK: IT_DET must equal 0/1; ' //      &
              'reset to 0'
      CALL print_error ( ounit, error )
    END IF

    IF ( fluxp<0 .OR. fluxp>2 ) THEN
      fluxp = 0
      error = '*WARNING: INPUT_CHECK: FLUXP must equal 0/1/2; ' //     &
              'reset to 0'
      CALL print_error ( ounit, error )
    END IF

    IF ( fixup/=0 .AND. fixup/=1 ) THEN
      fixup = 0
      error = '*WARNING: INPUT_CHECK: FIXUP must equal 0/1; ' //       &
              'reset to 0'
      CALL print_error ( ounit, error )
    END IF

    IF ( soloutp/=0 .AND. soloutp/=1 ) THEN
      soloutp = 0
      error = '*WARNING: INPUT_CHECK: SOLOUTP must equal 0/1; ' //     &
              'reset to 0'
      CALL print_error ( ounit, error )
    END IF

    IF ( kplane<0 .OR. kplane>nz ) THEN
      kplane = 0
      error = '*WARNING: INPUT_CHECK: KPLANE must be in the range ' // &
              '0 to NZ; reset to 0'
      CALL print_error ( ounit, error )
    END IF

    IF ( popout<0 .OR. popout>2 ) THEN
      popout = 0
      error = '*WARNING: INPUT_CHECK: POPOUT must equal 0/1/2; ' //    &
              'reset to 0'
      call print_error ( ounit, error )
    END IF
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE input_check


  SUBROUTINE input_var_bcast

!-----------------------------------------------------------------------
!
! Broadcast input variables from root to all other procs
!
!-----------------------------------------------------------------------
!_______________________________________________________________________
!
!   Local Variables
!_______________________________________________________________________

    INTEGER(i_knd) :: ilen, dlen

    INTEGER(i_knd), DIMENSION(30) :: ipak

    REAL(r_knd), DIMENSION(15) :: dpak
!_______________________________________________________________________
!
!   Pack the input variables into arrays before broadcasting
!_______________________________________________________________________

    ipak = 0
    dpak = zero

    IF ( iproc == root ) THEN

      ipak(1) = npey
      ipak(2) = npez
      ipak(3) = ichunk
      ipak(4) = nthreads
      ipak(5) = ndimen
      ipak(6) = nx
      ipak(7) = ny
      ipak(8) = nz
      ipak(9) = nmom
      ipak(10) = nang
      ipak(11) = ng
      ipak(12) = timedep
      ipak(13) = nsteps
      ipak(14) = iitm
      ipak(15) = oitm
      ipak(16) = mat_opt
      ipak(17) = src_opt
      ipak(18) = scatp
      ipak(19) = swp_typ
      ipak(20) = multiswp
      ipak(21) = angcpy
      ipak(22) = it_det
      ipak(23) = fluxp
      ipak(24) = fixup
      ipak(25) = nnested
      ipak(26) = soloutp
      ipak(27) = kplane
      ipak(28) = popout

      dpak(1) = lx
      dpak(2) = ly
      dpak(3) = lz
      dpak(4) = tf
      dpak(5) = epsi

    END IF
!_______________________________________________________________________
!
!   Broadcast data
!_______________________________________________________________________

    ilen = SIZE( ipak )
    dlen = SIZE( dpak )
    CALL bcast ( ipak, ilen, comm_snap, root )
    CALL bcast ( dpak, dlen, comm_snap, root )
!_______________________________________________________________________
!
!   Unpack
!_______________________________________________________________________

    IF ( iproc /= root ) THEN

      npey      = ipak(1)
      npez      = ipak(2)
      ichunk    = ipak(3)
      nthreads  = ipak(4)
      ndimen    = ipak(5)
      nx        = ipak(6)
      ny        = ipak(7)
      nz        = ipak(8)
      nmom      = ipak(9)
      nang      = ipak(10)
      ng        = ipak(11)
      timedep   = ipak(12)
      nsteps    = ipak(13)
      iitm      = ipak(14)
      oitm      = ipak(15)
      mat_opt   = ipak(16)
      src_opt   = ipak(17)
      scatp     = ipak(18)
      swp_typ   = ipak(19)
      multiswp  = ipak(20)
      angcpy    = ipak(21)
      it_det    = ipak(22)
      fluxp     = ipak(23)
      fixup     = ipak(24)
      nnested   = ipak(25)
      soloutp   = ipak(26)
      kplane    = ipak(27)
      popout    = ipak(28)

      lx     = dpak(1)
      ly     = dpak(2)
      lz     = dpak(3)
      tf     = dpak(4)
      epsi   = dpak(5)

    END IF

    CALL barrier ( comm_snap )
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE input_var_bcast


END MODULE input_module
