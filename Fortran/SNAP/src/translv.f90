SUBROUTINE translv ( ndpwds )

!-----------------------------------------------------------------------
!
! Solution driver. Contains the time and outer loops. Calls for outer
! iteration work. Checks convergence and handles eventual output.
!
!-----------------------------------------------------------------------

  USE global_module, ONLY: i_knd, r_knd, ounit, zero, half, one, two

  USE plib_module, ONLY: glmax, comm_snap, iproc, root, ichunk,        &
    nthreads, thread_num

  USE geom_module, ONLY: geom_allocate, dinv, geom_param_calc, nx,     &
    ny_gl, nz_gl

  USE sn_module, ONLY: nang, noct, mu, eta, xi, nmom

  USE data_module, ONLY: ng, v, vdelt, mat, sigt, siga, slgg, src_opt, &
    qim

  USE control_module, ONLY: nsteps, timedep, dt, oitm, otrdone, dfmxo, &
    it_det, popout, swp_typ, angcpy, update_ptr, iitm

  USE utils_module, ONLY: print_error, stop_run

  USE solvar_module, ONLY: solvar_allocate, ptr_in, ptr_out, t_xs,     &
    a_xs, s_xs, flux0, fluxm

  USE expxs_module, ONLY: expxs_reg

  USE outer_module, ONLY: outer

  USE time_module, ONLY: tslv, wtime, tgrind, tparam

  USE thrd_comm_module, ONLY: assign_thrd_set

  USE analyze_module, ONLY: analyze_pop_calc

  IMPLICIT NONE

!-----------------------------------------------------------------------
!
! Dummy arguments
!
!-----------------------------------------------------------------------

  INTEGER, INTENT(INOUT) :: ndpwds
!_______________________________________________________________________
!
! Local variables
!_______________________________________________________________________

  CHARACTER(LEN=1) :: star='*'

  CHARACTER(LEN=64) :: error

  INTEGER(i_knd) :: cy, otno, ierr, g, l, i, tot_iits, cy_iits,        &
    out_iits, t, ng_per_thrd, n, nnstd_used

  INTEGER(i_knd), DIMENSION(ng) :: iits, do_grp

  INTEGER(i_knd), DIMENSION(ng,nthreads) :: grp_act

  REAL(r_knd) :: sf, time, t1, t2, t3, t4, t5, tmp

  REAL(r_knd), DIMENSION(:,:,:,:,:,:), POINTER :: ptr_tmp
!_______________________________________________________________________
!
! Call for data allocations. Some allocations depend on the problem
! type being requested.
!_______________________________________________________________________

  CALL wtime ( t1 )

  ierr = 0
  error = ' '

  CALL geom_allocate ( nang, ng, swp_typ, ichunk, ndpwds, ierr )
  CALL glmax ( ierr, comm_snap )
  IF ( ierr /= 0 ) THEN
    error = '***ERROR: GEOM_ALLOC: Allocation error of sweep parameters'
    CALL print_error ( ounit, error )
    CALL stop_run ( 1, 4, 0, 0 )
  END IF

  CALL solvar_allocate ( ndpwds, ierr )
  CALL glmax ( ierr, comm_snap )
  IF ( ierr /= 0 ) THEN
    error = '***ERROR: SOLVAR_ALLOC: Allocation error of solution ' // &
            'arrays'
    CALL print_error ( ounit, error )
    CALL stop_run ( 1, 4, 1, 0 )
  END IF

  CALL wtime ( t2 )
  tparam = tparam + t2 - t1
!_______________________________________________________________________
!
! The time loop solves the problem for nsteps. If static, there is
! only one step, and it does not have any time-absorption or -source
! terms. Set the pointers to angular flux arrays. Set time to one for
! static for proper multiplication in octsweep.
!_______________________________________________________________________

  IF ( iproc == root ) THEN
    WRITE( *, 201)     ( star, i = 1, 80 )
    WRITE( ounit, 201) ( star, i = 1, 80 )
  END IF

  tot_iits = 0

  time_loop: DO cy = 1, nsteps
!_______________________________________________________________________
!
!   Initialize the single threaded region that will span the entirety
!   of the transport solution per time step.
!_______________________________________________________________________

  !$OMP PARALLEL NUM_THREADS(nthreads) IF(nthreads>1) PROC_BIND(SPREAD)&
  !$OMP& DEFAULT(SHARED) PRIVATE(t,g,otno)

    t = thread_num() + 1
!_______________________________________________________________________
!
!   A single thread does initial setup.
!_______________________________________________________________________

  !$OMP MASTER

    CALL wtime ( t3 )

    vdelt = zero
    time = one
    update_ptr = .TRUE.
    IF ( timedep == 1 ) THEN
      IF ( iproc == root ) THEN
        WRITE( *, 202 )     ( star, i = 1, 30 ), cy
        WRITE( ounit, 202 ) ( star, i = 1, 30 ), cy
      END IF
      vdelt = two / ( dt * v )
      time = dt * ( REAL( cy, r_knd ) - half )
      IF ( angcpy == 1 ) update_ptr = .FALSE.
    END IF

    IF ( cy>1 .AND. src_opt==3 )                                       &
      sf = REAL( 2*cy - 1, r_knd ) / REAL( 2*cy-3, r_knd )

    IF ( cy > 1 ) THEN
      ptr_tmp => ptr_out
      ptr_out => ptr_in
      ptr_in  => ptr_tmp
      NULLIFY( ptr_tmp )
    END IF
!_______________________________________________________________________
!
!   Some additional parameter setup work will be done with threads over
!   the groups. Each thread gets a set of groups. Nested threads, if
!   available will further parallelize the work over each set.
!_______________________________________________________________________

    do_grp = 1
    CALL assign_thrd_set ( do_grp, ng, ng_per_thrd, 0, nnstd_used,     &
      grp_act )

  !$OMP END MASTER
  !$OMP BARRIER
!_______________________________________________________________________
!
!   Prepare some cross sections: total, in-group scattering, absorption.
!   Keep in the time loop for better consistency with PARTISN. Set up
!   geometric sweep parameters. Reset flux moments to zero at start of
!   each time step.
!_______________________________________________________________________

  !$OMP PARALLEL DO SCHEDULE(STATIC,1) NUM_THREADS(nnstd_used)         &
  !$OMP& IF(nnstd_used>1) PROC_BIND(CLOSE) DEFAULT(SHARED)             &
  !$OMP& PRIVATE(n,g,l)
    DO n = 1, ng_per_thrd

      g = grp_act(n,t)
      IF ( g == 0 ) CYCLE

      CALL expxs_reg ( siga(:,g), mat, a_xs(:,:,:,g) )
      CALL expxs_reg ( sigt(:,g), mat, t_xs(:,:,:,g) )
      CALL geom_param_calc ( nang, ichunk, mu, eta, xi, t_xs(:,:,:,g), &
        vdelt(g), dinv(:,:,:,:,:,g) )
      DO l = 1, nmom
        CALL expxs_reg ( slgg(:,l,g,g), mat, s_xs(:,:,:,l,g) )
      END DO

      flux0(:,:,:,g) = zero
      fluxm(:,:,:,:,g) = zero
!_______________________________________________________________________
!
!     Scale the manufactured source for time.
!_______________________________________________________________________

      IF ( src_opt == 3 ) THEN
        IF ( cy == 1 ) THEN
          qim(:,:,:,:,:,g) = time*qim(:,:,:,:,:,g)
        ELSE
          qim(:,:,:,:,:,g) = qim(:,:,:,:,:,g)*sf
        END IF
      END IF

    END DO
  !$OMP END PARALLEL DO
!_______________________________________________________________________
!
!   Using Jacobi iterations in energy, and the work in the outer loop
!   will be parallelized with threads.
!_______________________________________________________________________

  !$OMP MASTER

    otrdone = .FALSE.

    cy_iits = 0

    IF ( iproc==root .AND. it_det==0 ) THEN
      WRITE( *, 203 )
      WRITE( ounit, 203 )
    END IF

    CALL wtime ( t4 )
    tparam = tparam + t4 - t3

  !$OMP END MASTER
  !$OMP BARRIER

    outer_loop: DO otno = 1, oitm

  !$OMP MASTER
      IF ( iproc==root .AND. it_det==1 ) THEN
        WRITE( *, 204 )     ( star, i = 1, 20 ), otno
        WRITE( ounit, 204 ) ( star, i = 1, 20 ), otno
      END IF
  !$OMP END MASTER
!_______________________________________________________________________
!
!     Perform an outer iteration. Add up inners. Check convergence.
!_______________________________________________________________________

      CALL outer ( iits, otno, t, do_grp, ng_per_thrd, nnstd_used, &
        grp_act, iitm )
  !$OMP BARRIER

  !$OMP MASTER

      out_iits = SUM( iits )
      cy_iits = cy_iits + out_iits

      IF ( iproc == root ) THEN
        WRITE( *, 205 )     otno, dfmxo, out_iits
        WRITE( ounit, 205 ) otno, dfmxo, out_iits
      END IF

  !$OMP END MASTER
  !$OMP BARRIER

      IF ( otrdone ) EXIT outer_loop

    END DO outer_loop
!_______________________________________________________________________
!
!   Manually call for another outer if angcpy is 1 to update the
!   outgoing time-edge angular flux. This is done regardless of
!   convergence.
!_______________________________________________________________________

    IF ( angcpy == 1 ) THEN

      IF ( otno > oitm ) THEN
        otno = oitm + 1
      ELSE
        otno = otno + 1
      END IF

  !$OMP MASTER
      update_ptr = .TRUE.
      do_grp = 1
      CALL assign_thrd_set ( do_grp, ng, ng_per_thrd, 0, nnstd_used,   &
        grp_act )
      IF ( iproc==root .AND. it_det==1 ) THEN
        WRITE( *, 204 )     ( star, i = 1, 20 ), otno
        WRITE( ounit, 204 ) ( star, i = 1, 20 ), otno
      END IF
  !$OMP END MASTER
  !$OMP BARRIER

      CALL outer ( iits, otno, t, do_grp, ng_per_thrd, nnstd_used,     &
        grp_act, 1 )
  !$OMP BARRIER

  !$OMP MASTER
      out_iits = SUM( iits )
      cy_iits = cy_iits + out_iits
      IF ( iproc == root ) THEN
        WRITE( *, 205 )     otno, dfmxo, out_iits
        WRITE( ounit, 205 ) otno, dfmxo, out_iits
      END IF
  !$OMP END MASTER
  !$OMP BARRIER

    END IF
!_______________________________________________________________________
!
!   Master thread computes and prints the particle spectrum every cycle.
!_______________________________________________________________________

  !$OMP MASTER

    IF ( popout == 2 ) CALL analyze_pop_calc ( cy, time )
!_______________________________________________________________________
!
!   Print the time cycle details. Add time cycle iterations. End the
!   main parallel thread region.
!_______________________________________________________________________

    IF ( iproc == root ) THEN
      IF ( timedep == 1 ) THEN
        IF ( otrdone ) THEN
          WRITE( *, 206 )     cy, time, otno, cy_iits
          WRITE( ounit, 206 ) cy, time, otno, cy_iits
        ELSE
          WRITE( *, 207 )     cy, time, otno-1, cy_iits
          WRITE( ounit, 207 ) cy, time, otno-1, cy_iits
        END IF
      ELSE
        IF ( otrdone ) THEN
          WRITE( *, 208 )     otno, cy_iits
          WRITE( ounit, 208 ) otno, cy_iits
        ELSE
          WRITE( *, 209 )     otno-1, cy_iits
          WRITE( ounit, 209 ) otno-1, cy_iits
        END IF
      END IF
    END IF

    tot_iits = tot_iits + cy_iits

  !$OMP END MASTER

  !$OMP END PARALLEL

  END DO time_loop
!_______________________________________________________________________
!
!   Compute and print the particle spectrum only at end of calc.
!_______________________________________________________________________

    IF ( popout == 1 ) CALL analyze_pop_calc ( cy, time )
!_______________________________________________________________________
!
!   Final prints.
!_______________________________________________________________________

  IF ( iproc == root ) THEN
    IF ( timedep == 1 ) THEN
      WRITE( *, 210 )     ( star, i = 1, 30 ), tot_iits
      WRITE( ounit, 210 ) ( star, i = 1, 30 ), tot_iits
    END IF
    WRITE( *, 211 )     ( star, i = 1, 80 )
    WRITE( ounit, 211 ) ( star, i = 1, 80 )
  END IF

  CALL wtime ( t5 )
  tslv = t5 - t1
  tmp = REAL( nx, r_knd ) * REAL( ny_gl, r_knd ) * REAL( nz_gl, r_knd )&
        * REAL( nang, r_knd ) * REAL( noct, r_knd )                    &
        * REAL( tot_iits, r_knd )
  tgrind = tslv*1.0E9_r_knd / tmp
!_______________________________________________________________________

  201 FORMAT( 10X, 'keyword Iteration Monitor', /, 80A )
  202 FORMAT( /, 1X, 30A, /, 2X, 'Time Cycle ', I3 )
  203 FORMAT( 2X, 'Outer' )
  204 FORMAT( 1X, 20A, /, 2X, 'Outer ', I3 )
  205 FORMAT( 2X, I3, 4X, 'Dfmxo=', ES11.4, 4X, 'No. Inners=', I5 )
  206 FORMAT( /, 2X, 'Cycle=', I4, 4X, 'Time=', ES11.4, 4X, 'No. ',    &
              'Outers=', I4, 4X, 'No. Inners=', I5 )
  207 FORMAT( /, 2X, '*WARNING: Unconverged outer iterations', /, 2X,  &
             'Cycle=', I4, 4X, 'Time=', ES11.4, 4X, 'No. Outers=', I4, &
             4X, 'No. Inners=', I5, / )
  208 FORMAT( /, 2X, 'No. Outers=', I4, 4X, 'No. Inners=', I5 )
  209 FORMAT( /, 2X, '*WARNING: Unconverged outer iteration!', /, 2X,  &
              'No. Outers=', I4, 4X, 'No. Inners=', I5, / )
  210 FORMAT( /, 1X, 30A, /, 2X, 'Total inners for all time steps, ',  &
              'outers = ', I6 )
  211 FORMAT( /, 80A, / )
!_______________________________________________________________________
!_______________________________________________________________________

END SUBROUTINE translv
