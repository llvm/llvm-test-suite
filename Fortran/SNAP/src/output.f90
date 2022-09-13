!-----------------------------------------------------------------------
!
! MODULE: output_module
!> @brief
!> This module controls final solution output.
!
!-----------------------------------------------------------------------

MODULE output_module

  USE global_module, ONLY: i_knd, r_knd, ounit, zero

  USE geom_module, ONLY: nx, ny, nz, nz_gl, ny_gl

  USE sn_module, ONLY: cmom

  USE data_module, ONLY: ng, src_opt

  USE control_module, ONLY: fluxp, soloutp, kplane

  USE utils_module, ONLY: open_file, close_file, print_error, stop_run

  USE solvar_module, ONLY: flux0, fluxm

  USE mms_module, ONLY: mms_verify_1

  USE time_module, ONLY: tout, wtime

  USE plib_module, ONLY: iproc, root, zproc, bcast, comm_snap,         &
    comm_space, sproc, cartrank, npey, psend, precv, barrier

  IMPLICIT NONE

  PRIVATE

  PUBLIC :: output


  CONTAINS


  SUBROUTINE output

!-----------------------------------------------------------------------
!
! Print the scalar flux output to the output file.
!
!-----------------------------------------------------------------------
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    CHARACTER(LEN=1) :: star='*'

    CHARACTER(LEN=64) :: error

    INTEGER(i_knd) :: i, j, k, g, is, ii, ierr, klb, kub, mtag, jp,    &
      kloc, rank, jlb, jub

    INTEGER(i_knd), DIMENSION(2) :: co

    REAL(r_knd) :: t1, t2

    REAL(r_knd), ALLOCATABLE, DIMENSION(:,:) :: fprnt
!_______________________________________________________________________

    CALL wtime ( t1 )

    ierr = 0
    error = ' '
!_______________________________________________________________________
!
!   Get global indices of local PE bounds.
!_______________________________________________________________________

    klb = zproc*nz + 1
    kub = (zproc+1) * nz
!_______________________________________________________________________
!
!   Only if requested, print solution at mid-plane.
!_______________________________________________________________________

    IF ( soloutp == 1 ) THEN

      IF ( iproc == root ) THEN
        WRITE( ounit, 301 ) ( star, i = 1, 80 )
        ALLOCATE( fprnt(nx,ny_gl), STAT=ierr )
        fprnt = zero
      END IF

      CALL bcast ( ierr, comm_snap, root )
      IF ( ierr /= 0 ) THEN
        error = '***ERROR: OUTPUT: Allocation error'
        CALL print_error ( ounit, error )
        CALL stop_run ( 1, 4, 2, 0 )
      END IF
!_______________________________________________________________________
!
!     Choose the mid-plane. If user specified a k-plane via kplane
!     input, use that value instead. Determine k local index.
!_______________________________________________________________________

      k = nz_gl/2 + 1
      IF ( kplane /= 0 ) k = kplane
      kloc = MOD( k-1, nz ) + 1
!_______________________________________________________________________
!
!     Loops over groups. Send/Recv message. Print flux.
!_______________________________________________________________________

      g_loop: DO g = 1, ng
!_______________________________________________________________________
!
!       If global k index is within proc's bounds, send message to root
!       of flux on that plane
!_______________________________________________________________________

        IF ( klb<=k .AND. k<=kub ) THEN
          mtag = g
          CALL output_send ( mtag, flux0(:,:,kloc,g) )
        END IF
!_______________________________________________________________________
!
!       Presets the printed flux to its own value if there is only one
!       proc or npez=1. Receives messages in order for proper printing.
!_______________________________________________________________________

        IF ( iproc == root ) THEN

          co(1) = (k-1)/nz
          fprnt(:,1:ny) = flux0(:,:,kloc,g)
          WRITE( ounit, 302 ) ( star, i = 1, 35 ), g, k,               &
            ( star, i = 1, 35 )

          DO jp = 0, npey-1
            jlb = jp*ny + 1
            jub = (jp+1) * ny
            co(2) = jp
            CALL cartrank ( co, rank, comm_space )
            mtag = g
            CALL output_recv ( mtag, rank, fprnt(:,jlb:jub) )
          END DO

          DO i = 1, nx, 6
            is = i + 6 - 1
            IF ( is > nx ) is = nx
            WRITE( ounit, FMT=303, ADVANCE='NO' )
            DO ii = i, is
              WRITE( ounit, FMT=304, ADVANCE='NO' ) ii
            END DO
            WRITE( ounit, FMT=305, ADVANCE='YES' )
            DO j = ny_gl, 1, -1
              WRITE( ounit, 306 ) j, ( fprnt(ii,j), ii = i, is )
            END DO
          END DO

          WRITE( ounit, 307 ) ( star, i = 1, 80 )

        END IF

      END DO g_loop
!_______________________________________________________________________
!
!     Cleanup
!_______________________________________________________________________

      IF ( iproc == root ) DEALLOCATE( fprnt )

    END IF
!_______________________________________________________________________
!
!   Print flux to file if requested
!_______________________________________________________________________

    call barrier ( comm_snap )

    IF ( fluxp > 0 ) CALL output_flux_file ( klb, kub )
!_______________________________________________________________________
!
!   If MMS solution, verify compared to ref_flux
!_______________________________________________________________________

    IF ( src_opt == 3 ) CALL mms_verify_1 ( flux0 )

    CALL wtime ( t2 )
    tout = t2 - t1
!_______________________________________________________________________

    301 FORMAT( 10X, 'keyword Scalar Flux Solution', /, 80A )
    302 FORMAT( /, 1X, 35A, /, 2X, 'Group= ', I3, 2X, ' Z Mid-Plane= ',&
                I4, /, 1X, 35A )
    303 FORMAT( /, 5X, 'y' )
    304 FORMAT( 4X, 'x ', I4, 2X )
    305 FORMAT( 1X )
    306 FORMAT( 2X, I4, 6(1X, ES11.4) )
    307 FORMAT( /, 80A, / )
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE output


  SUBROUTINE output_send ( mtag, fprnt )

!-----------------------------------------------------------------------
!
! Send root chunk of flux data for printing
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: mtag

    REAL(r_knd), DIMENSION(nx,ny), INTENT(IN) :: fprnt
!_______________________________________________________________________

    CALL psend ( root, sproc, nx, ny, fprnt, comm_space, mtag )
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE output_send


  SUBROUTINE output_recv ( mtag, proc, fprnt )

!-----------------------------------------------------------------------
!
! Receive flux message for output
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: mtag, proc

    REAL(r_knd), DIMENSION(nx,ny), INTENT(INOUT) :: fprnt
!_______________________________________________________________________

    CALL precv ( proc, sproc, nx, ny, fprnt, comm_space, mtag )
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE output_recv


  SUBROUTINE output_flux_file ( klb, kub )

!-----------------------------------------------------------------------
!
!   Print fluxes to file. Either print just first moment or all moments.
!   Root does printing.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: klb, kub
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    CHARACTER(LEN=16) :: fn='flux'

    CHARACTER(LEN=64) :: error

    INTEGER(i_knd) :: i, j, k, g, l, ierr, fu=16, mtag, jp, jlb, jub,  &
      kloc, rank

    INTEGER(i_knd), DIMENSION(2) :: co

    REAL(r_knd), ALLOCATABLE, DIMENSION(:,:) :: fprnt
!_______________________________________________________________________
!
!   Root opens the file, allocates the space for fprnt
!_______________________________________________________________________

    ierr = 0
    error = ' '
    CALL open_file ( fu, fn, 'REPLACE', 'WRITE', ierr, error )
    CALL bcast ( ierr, comm_snap, root )
    IF ( ierr /= 0 ) THEN
      CALL print_error (ounit, error )
      CALL stop_run ( 1, 4, 2, 0 )
    END IF

    IF ( iproc == root ) THEN
      ALLOCATE( fprnt(nx,ny_gl), STAT=ierr )
      fprnt = zero
    END IF
    CALL bcast ( ierr, comm_snap, root )
    IF ( ierr /= 0 ) THEN
      error = '***ERROR: OUTPUT_FLUX_FILE: Allocation error'
      CALL print_error ( ounit, error )
      CALL stop_run ( 1, 4, 2, 0 )
    END IF
!_______________________________________________________________________
!
!   Root does all printing. Start with file header comment.
!_______________________________________________________________________

    IF ( iproc == root ) THEN
      IF ( fluxp == 1 ) THEN
        WRITE( fu, 321 )
      ELSE
        WRITE( fu, 322 )
      END IF
    END IF
!_______________________________________________________________________
!
!   Print data from first moment. Use similar technique as mid-plane,
!   but now loop over all planes and all groups. Store all the data of
!   a k-plane, group in one array and print that all at once.
!_______________________________________________________________________

    DO l = 1, MAX( 1, (fluxp-1)*cmom )

      IF ( iproc == root ) WRITE( fu, 323 ) l

      DO g = 1, ng
        DO k = 1, nz_gl

          kloc = MOD( k-1, nz ) + 1
          IF ( klb<=k .AND. k<=kub ) THEN
            mtag = l*ng*nz + (g-1)*nz + kloc
            IF ( l == 1 ) THEN
              CALL output_send ( mtag, flux0(:,:,kloc,g) )
            ELSE
              CALL output_send ( mtag, fluxm(l-1,:,:,kloc,g) )
            END IF
          END IF
     

          IF ( iproc == root ) THEN
            co(1) = (k-1)/nz
            fprnt(:,1:ny) = flux0(:,:,kloc,g)
            DO jp = 0, npey-1
              jlb = jp*ny + 1
              jub = (jp+1) * ny
              co(2) = jp
              CALL cartrank ( co, rank, comm_space )
              mtag = l*ng*nz + (g-1)*nz + kloc
              CALL output_recv ( mtag, rank, fprnt(:,jlb:jub) )
            END DO
            WRITE( fu, 324 ) ( ( fprnt(i,j), i = 1, nx ), j = 1, ny_gl )
          END IF

        END DO
      END DO

    END DO
!_______________________________________________________________________
!
!   Cleanup
!_______________________________________________________________________

    IF ( iproc == root ) DEALLOCATE( fprnt )

    CALL close_file ( fu, ierr, error )
    CALL bcast ( ierr, comm_snap, root )
    IF ( ierr /= 0 ) THEN
      CALL print_error ( ounit, error )
      CALL stop_run ( 1, 4, 2, 0 )
    END IF
!_______________________________________________________________________

    321 FORMAT( 1X, 'flux(nx,ny,nz,ng) echo', /, 1X, 'Column-order ',  &
                'loops: x-cells (fastest), y-cells, z-cells, groups ', &
                '(slowest)' )
    322 FORMAT( 1X, 'flux(nx,ny,nz,ng) and fluxm(cmom-1,nx,ny,nz,ng)', &
                ' echo', /, 1X, 'Column-order loops by moment:', /,    &
                1X, 'x-cells (fastest), y-cells, z-cells, groups, ',   &
                'moments (slowest)' )
    323 FORMAT( /, 2X, 'Moment = ', I1 )
    324 FORMAT( 4(2X, ES17.10) )
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE output_flux_file


END MODULE output_module
