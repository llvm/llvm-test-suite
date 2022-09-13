PROGRAM snap_main

!-----------------------------------------------------------------------
! 
!    SNAP - SN Application Proxy
!
!    Parallel programming model based on PARTISN
!
!
!    SNAP: SN (Discrete Ordinates) Application Proxy
!    Version 1.x (C13087)
!    LA-CC-13-016
!
!    This code is Unclassified, and contains no Unclassified Controlled
!    Nuclear Information
!
!    Copyright (c) 2013, Triad National Security, LLC
!    All rights reserved.
!
!    This program was produced under U.S. Government contract
!    89233218CNA000001 for Los Alamos National Laboratory (LANL), which
!    is operated by Triad National Security, LLC for the U.S. Department
!    of Energy/National Nuclear Secuirty Administration.
!
!    All rights in the program are reserved by Triad National Security,
!    LLC and the U.S. Department of Energy/National Nuclear Security
!    Administration. The Government is granted for itself and others
!    acting on its behalf a nonexclusive, paid-up, irrevocable worldwide
!    license in this material to reproduce, prepare derivative works,
!    distribute copies to the public, perform publicly and display
!    publicly, and to permit others to do so.
!
!    NEITHER THE GOVERNMENT NOR TRIAD NATIONAL SECURITY, LLC MAKES ANY
!    WARRANTY, EXPRESS OR IMPLIED, OR ASSUMES ANY LIABILITY FOR THE USE
!    OF THIS SOFTWARE.
!
!    This is open source software; you can redistribute it and/or
!    modify it under the terms of the 3-Clause BSD License. If software
!    is modified to produce derivative works, such modified software
!    should be clearly marked, so as not to confuse it with the version
!    available from LANL. Full text of the 3-Clause BSD License is given
!    below.
!
!
!    3-Clause BSD License:
!
!    Redistribution and use in source and binary forms, with or without
!    modification, are permitted provided that the following conditions
!    are met:
!
!    1. Redistributions of source code must retain the above copyright
!       notice, this list of conditions and the following disclaimer.
!
!    2. Redistributions in binary form must reproduce the above
!       copyright notice, this list of conditions and the following
!       disclaimer in the documentation and/or other materials provided
!       with the distribution.
!
!    3. Neither the name of Triad National Security, LLC, Los Alamos
!       National Laboratory, LANL, the U.S. Government, nor the names of
!       its contributors may be used to endorse or promote products
!       derived from this software without specific prior written
!       permission.
!
!    THIS SOFTWARE IS PROVIDED BY TRIAD NATIONAL SECURITY, LLC AND
!    CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
!    INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
!    MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
!    DISCLAIMED. IN NO EVENT SHALL TRIAD NATIONAL SECURITY, LLC OR
!    CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
!    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
!    LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
!    USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
!    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
!    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
!    OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
!    SUCH DAMAGE.
!
!-----------------------------------------------------------------------

  USE global_module, ONLY: i_knd, r_knd, ifile, ofile, iunit, ounit, one

  USE utils_module

  USE version_module, ONLY: version_print

  USE input_module, ONLY: input_read

  USE setup_module, ONLY: setup

  USE output_module, ONLY: output

  USE time_module, ONLY: tsnap, wtime, tparset, time_summ, tgrind

  USE dealloc_module

  USE plib_module, ONLY: pinit, iproc, root, comm_snap, bcast,         &
    pcomm_set, pinit_omp

  USE control_module, ONLY: otrdone, swp_typ

  IMPLICIT NONE
!_______________________________________________________________________
!
! Local variables
!_______________________________________________________________________

  CHARACTER(LEN=1) :: star='*'

  CHARACTER(LEN=64) :: error

  INTEGER(i_knd) :: ierr, i, ndpwds

  REAL(r_knd) :: t1, t2, t3, t4, t5
!_______________________________________________________________________
!
! Perform calls that set up the parallel environment in MPI and
! OpenMP. Also starts the timer. Update parallel setup time.
!_______________________________________________________________________

  ierr = 0
  ndpwds = 0
  error = ' '

  CALL pinit ( t1 )

  CALL wtime ( t2 )
  tparset = tparset + t2 - t1
!_______________________________________________________________________
!
! Read the command line arguments to get i/o file names. Open the two
! files.
!_______________________________________________________________________

  CALL cmdarg ( ierr, error )
  CALL bcast ( ierr, comm_snap, root )
  IF ( ierr /= 0 ) THEN
    CALL print_error ( 0, error )
    CALL stop_run ( 0, 0, 0, 0 )
  END IF

  CALL open_file ( iunit, ifile, 'OLD', 'READ', ierr, error )
  CALL bcast ( ierr, comm_snap, root )
  IF ( ierr /= 0 ) THEN
    CALL print_error ( 0, error )
    CALL stop_run ( 0, 0, 0, 0 )
  END IF

  CALL open_file ( ounit, ofile, 'REPLACE', 'WRITE', ierr, error )
  CALL bcast ( ierr, comm_snap, root )
  IF ( ierr /= 0 ) THEN
    CALL print_error ( 0, error )
    CALL stop_run ( 0, 0, 0, 0 )
  END IF
!_______________________________________________________________________
!
! Write code version and execution time to output.
!_______________________________________________________________________

  IF ( iproc == root ) CALL version_print
!_______________________________________________________________________
!
! Read input
!_______________________________________________________________________

  CALL input_read

  CALL close_file ( iunit, ierr, error )
  CALL bcast ( ierr, comm_snap, root )
  IF ( ierr /= 0 ) THEN
    CALL print_error ( ounit, error )
    CALL stop_run ( 0, 0, 0, 0 )
  END IF
!_______________________________________________________________________
!
! Get nthreads for each proc. Print the warning about resetting nthreads
! if necessary. Don't stop run. Set up the SDD MPI topology.
!_______________________________________________________________________

  CALL wtime ( t3 )

  CALL pinit_omp ( ierr, error )
  IF ( ierr /= 0 ) CALL print_error ( 0, error )

  CALL pcomm_set

  CALL wtime ( t4 )
  tparset = tparset + t4 - t3
!_______________________________________________________________________
!
! Setup problem
!_______________________________________________________________________

  CALL setup ( ndpwds )
!_______________________________________________________________________
!
! Call for the problem solution
!_______________________________________________________________________

  CALL translv ( ndpwds )
!_______________________________________________________________________
!
! Output the results. Print the timing summary.
!_______________________________________________________________________

  CALL output
  IF ( iproc == root ) CALL time_summ
!_______________________________________________________________________
!
! Final cleanup: deallocate, close output file, end the program
!_______________________________________________________________________

  CALL dealloc_input ( 4 )
  CALL dealloc_solve ( swp_typ, 2 )

  CALL wtime ( t5 )
  tsnap = t5 - t1

  IF ( iproc == root ) THEN
    WRITE( ounit, 501 ) tsnap
!    WRITE( ounit, 502 ) tgrind, ( star, i = 1, 80 )
    WRITE( ounit, 502 ) tgrind
    WRITE( ounit, 504 ) one/tgrind, ( star, i = 1, 80 )
    WRITE( ounit, 503 ) ndpwds, ( star, i = 1, 80 )
  END IF

  CALL close_file ( ounit, ierr, error )
  CALL bcast ( ierr, comm_snap, root )
  IF ( ierr /= 0 ) THEN
    CALL print_error ( 0, error )
    CALL stop_run ( 1, 0, 0, 0 )
  END IF

  IF ( otrdone ) THEN
    CALL stop_run ( 1, 0, 0, 1 )
  ELSE
    CALL stop_run ( 1, 0, 0, 2 )
  END IF
!_______________________________________________________________________

  501 FORMAT( 2X, 'Total Execution time', T41, ES11.4, / )
  502 FORMAT( 2X, 'Grind Time (nanoseconds)', 8X, ES11.4, / )
  504 FORMAT( 2X, 'Inverse Grind Time FOM (1/ns)', 8X, ES11.4, /, /,   &
                80A )
  503 FORMAT( /, 'Allocated words (double precision) per rank',   &
                T61, I15, /, /, 80A )
!_______________________________________________________________________
!_______________________________________________________________________

END PROGRAM snap_main
