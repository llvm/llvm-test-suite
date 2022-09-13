!-----------------------------------------------------------------------
!
! MODULE: thrd_comm_module
!> @brief
!> This module contains the subroutines that setup/handle the
!> communications in the presence of threads. This includes making
!> thread sets that allows synchronized, ordered work as wide as the
!> number of threads; assigning groups to threads within these thread
!> sets; and the communication routines themselves.
!
!-----------------------------------------------------------------------

MODULE thrd_comm_module

  USE global_module, ONLY: i_knd, l_knd, r_knd

  USE plib_module, ONLY: nthreads, nnested, plock_omp, ycomm, zcomm,   &
    precv, ylop, yhip, zlop, zhip, firsty, firstz, lasty, lastz,       &
    use_lock, waitall, isend, yproc, zproc, irecv, waitsome, testsome, &
    waits, tests

  IMPLICIT NONE

  PRIVATE

  PUBLIC :: assign_thrd_set, no_op_lock_control, sweep_recv_bdry,      &
    sweep_send_bdry, multiswp_recv_bdry, multiswp_test_pick,           &
    multiswp_send_bdry, lock_control

  SAVE
!_______________________________________________________________________
!
! Run-time variables
!
! g_off     - group offset for message tags
!_______________________________________________________________________

  INTEGER(i_knd), PARAMETER :: g_off = 2**14, c_off = 2**12


  CONTAINS


  SUBROUTINE assign_thrd_set ( do_task, tlen, tasks_per_thrd, nlen,    &
    nstd_set_size, task_act )

!-----------------------------------------------------------------------
!
! Set up thread sets and assign tasks (i.e., groups) to threads.
!  tasks_per_thrd: number of tasks each thread will perform
!  nstd_set_size:  number of nested threads that will be spawned
!  task_act: the array that tells each thread what to do
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: tlen, nlen

    INTEGER(i_knd), INTENT(OUT) :: tasks_per_thrd, nstd_set_size

    INTEGER(i_knd), DIMENSION(tlen), INTENT(INOUT) :: do_task

    INTEGER(i_knd), DIMENSION(tlen,nthreads), INTENT(OUT) :: task_act
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: thrd_set_size, ntasks, n, t, next
!_______________________________________________________________________
!
!   Initialize outgoing variables. Set thread set size and number of
!   groups per set. Return if no tasks.
!_______________________________________________________________________

    nstd_set_size  = 0
    tasks_per_thrd = 0

    ntasks = COUNT( do_task > 0 )
    thrd_set_size = MIN( ntasks, nthreads )

    IF ( thrd_set_size == 0 ) THEN
      tasks_per_thrd = 0
      nstd_set_size  = 0
      RETURN
    END IF

    tasks_per_thrd = (ntasks-1)/thrd_set_size + 1

    task_act = 0
!_______________________________________________________________________
!
!   Assign tasks to threads in the set sequentially
!_______________________________________________________________________

    n_loop: DO n = 1, tasks_per_thrd
      DO t = 1, thrd_set_size
        next = MAXLOC( do_task, 1 )
        IF ( do_task(next) == 0 ) EXIT n_loop
        task_act(n,t) = next
        do_task(next) = 0
      END DO
    END DO n_loop
!_______________________________________________________________________
!
!   Set the number of nested threads. If provided nlen is zero, apply
!   nested threads to main thread tasks. If nlen is non-zero, set the
!   nested thread set size according to width of nested work.
!_______________________________________________________________________

    IF ( nlen == 0 ) THEN
      nstd_set_size = MIN( tasks_per_thrd, nnested )
    ELSE
      nstd_set_size = MIN( nlen, nnested )
    END IF
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE assign_thrd_set


  SUBROUTINE no_op_lock_control ( t )

!-----------------------------------------------------------------------
!
! Control threaded communication that lack thread_multiple thread level
! with locks. If a thread does not have group sweep to perform, must
! still set/unset locks.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: t
!_______________________________________________________________________
!
!   If locks are unnecessary, return immediately
!_______________________________________________________________________

    IF ( .NOT.use_lock ) RETURN
!_______________________________________________________________________
!
!   Each thread sets its own lock. If a thread's lock is already set, it
!   must wait until another thread unlocks it: work is suspended until
!   it can set its lock and proceed. Then thread unsets next thread's
!   lock.
!_______________________________________________________________________

    CALL lock_control ( 'set', t )

    CALL lock_control ( 'unset', t )
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE no_op_lock_control


  SUBROUTINE sweep_recv_bdry ( g, jd, kd, iop, t, reqs, szreq, nc,     &
    nang, ichunk, ny, nz, jb_in, kb_in )

!-----------------------------------------------------------------------
!
! Receive jb_in and kb_in flux from upstream boundaries
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: g, jd, kd, iop, t, szreq, nc, nang,  &
      ichunk, ny, nz

    INTEGER(i_knd), DIMENSION(szreq), INTENT(INOUT) :: reqs

    REAL(r_knd), DIMENSION(nang,ichunk,nz), INTENT(OUT) :: jb_in

    REAL(r_knd), DIMENSION(nang,ichunk,ny), INTENT(OUT) :: kb_in
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: yp_rcv, zp_rcv, mtag

    LOGICAL(l_knd) :: incomingy, outgoingy, incomingz, outgoingz
!_______________________________________________________________________
!
!   Determine sender of message and set tag if a message is to be
!   received (g/=0). Tag is set to offset by group, octant, and spatial
!   work chunk.
!_______________________________________________________________________

    IF ( jd == 1 ) THEN
      yp_rcv = yhip
      incomingy = .NOT.lasty
      outgoingy = .NOT.firsty
    ELSE
      yp_rcv = ylop
      incomingy = .NOT.firsty
      outgoingy = .NOT.lasty
    END IF

    IF ( kd == 1 ) THEN
      zp_rcv = zhip
      incomingz = .NOT.lastz
      outgoingz = .NOT.firstz
    ELSE
      zp_rcv = zlop
      incomingz = .NOT.firstz
      outgoingz = .NOT.lastz
    END IF

    mtag = g*g_off + 2*nc*(jd-1 + 2*(kd-1)) + iop
!_______________________________________________________________________
!
!   If locks are used to control threaded communications, each thread
!   sets its own lock. If a thread's lock is already set, it must wait
!   until another thread unlocks it: work is suspended until it can set
!   its lock and proceed.
!_______________________________________________________________________

    IF ( use_lock ) CALL lock_control ( 'set', t )
!_______________________________________________________________________
!
!   Call to receive upstream data. Call for a wait on previous
!   asynchronous send operations.
!_______________________________________________________________________

    IF ( incomingy ) CALL precv ( yp_rcv, yproc, nang, ichunk, nz,     &
                                  jb_in, ycomm, mtag )
    IF ( incomingz ) CALL precv ( zp_rcv, zproc, nang, ichunk, ny,     &
                                  kb_in, zcomm, mtag )
    IF ( outgoingy .OR. outgoingz ) CALL waitall ( reqs, szreq )
!_______________________________________________________________________
!
!   If locks are used, unset the lock of another thread to allow it to
!   perform its communications
!_______________________________________________________________________

    IF ( use_lock ) CALL lock_control ( 'unset', t )
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE sweep_recv_bdry


  SUBROUTINE sweep_send_bdry ( g, jd, kd, iop, t, reqs, szreq, nc,     &
    nang, ichunk, ny, nz, jb_out, kb_out )

!-----------------------------------------------------------------------
!
! Send flux to downstream boundaries
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: g, jd, kd, iop, t, szreq, nc, nang,  &
      ichunk, ny, nz

    INTEGER(i_knd), DIMENSION(szreq), INTENT(INOUT) :: reqs

    REAL(r_knd), DIMENSION(nang,ichunk,nz), INTENT(IN) :: jb_out

    REAL(r_knd), DIMENSION(nang,ichunk,ny), INTENT(IN) :: kb_out
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: yp_snd, zp_snd, mtag

    LOGICAL(l_knd) :: outgoingy, outgoingz
!_______________________________________________________________________
!
!   Determine recipient of message and set tag Tag is set to offset by
!   group, octant, and spatial work chunk.
!_______________________________________________________________________

    IF ( jd == 1 ) THEN
      yp_snd = ylop
      outgoingy = .NOT.firsty
    ELSE
      yp_snd = yhip
      outgoingy = .NOT.lasty
    END IF

    IF ( kd == 1 ) THEN
      zp_snd = zlop
      outgoingz = .NOT.firstz
    ELSE
      zp_snd = zhip
      outgoingz = .NOT.lastz
    END IF

    mtag = g*g_off + 2*nc*(jd-1 + 2*(kd-1)) + iop
!_______________________________________________________________________
!
!   If locks are used to control threaded communications, each thread
!   sets its own lock. If a thread's lock is already set, it must wait
!   until another thread unlocks it: work is suspended until it can set
!   its lock and proceed.
!_______________________________________________________________________

    IF ( use_lock ) CALL lock_control ( 'set', t )
!_______________________________________________________________________
!
!   Call to send data downstream. Use non-blocking send.
!_______________________________________________________________________

    IF ( outgoingy ) CALL isend ( yp_snd, yproc, nang, ichunk, nz,     &
                                  jb_out, ycomm, mtag, reqs(1) )
    IF ( outgoingz ) CALL isend ( zp_snd, zproc, nang, ichunk, ny,     &
                                  kb_out, zcomm, mtag, reqs(2) )
!_______________________________________________________________________
!
!   If locks are used, unset the lock of another thread to allow it to
!   perform its communications
!_______________________________________________________________________

    IF ( use_lock ) CALL lock_control ( 'unset', t )
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE sweep_send_bdry


  SUBROUTINE multiswp_recv_bdry ( jdim, kdim, ncor, ng, ic_op,         &
    grp_act, gc, callrecv, mtag, reqr, szreq, nang, ichunk, ny, nz,    &
    jb_in, kb_in )

!-----------------------------------------------------------------------
!
! Receive jb_in and kb_in flux from upstream boundaries for one or all
! starting corner sweeps.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: jdim, kdim, ncor, ng, szreq, nang,   &
      ichunk, ny, nz

    INTEGER(i_knd), DIMENSION(ncor), INTENT(IN) :: ic_op, gc

    INTEGER(i_knd), DIMENSION(ng), INTENT(IN) :: grp_act

    INTEGER(i_knd), DIMENSION(ncor), INTENT(OUT) :: mtag

    INTEGER(i_knd), DIMENSION(szreq), INTENT(INOUT) :: reqr

    LOGICAL(l_knd), DIMENSION(ncor), INTENT(INOUT) :: callrecv

    REAL(r_knd), DIMENSION(nang,ichunk,nz,ncor,ng), INTENT(OUT) :: jb_in

    REAL(r_knd), DIMENSION(nang,ichunk,ny,ncor,ng), INTENT(OUT) :: kb_in
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: icor, jd, kd, g, yp_rcv, zp_rcv
!_______________________________________________________________________
!_______________________________________________________________________

    IF ( ncor == 1 ) RETURN
!_______________________________________________________________________
!
!   Loop over corners, check callrecv flag, set tag
!_______________________________________________________________________

    icor = 0

    DO kd = 1, kdim
    DO jd = 1, jdim

      icor = icor + 1
      IF ( .NOT.callrecv(icor) ) CYCLE
      callrecv(icor) = .FALSE.
      g = grp_act(gc(icor))
      mtag(icor) = g_off*g + c_off*(icor-1) + ic_op(icor)
!_______________________________________________________________________
!
!     Set up the communication basics
!_______________________________________________________________________

      IF ( jd == 1 ) THEN
        yp_rcv = yhip
      ELSE
        yp_rcv = ylop
      END IF

      IF ( kd == 1 ) THEN
        zp_rcv = zhip
      ELSE
        zp_rcv = zlop
      END IF
!_______________________________________________________________________
!
!     Make asynchronous calls to receive data
!_______________________________________________________________________

      IF ( use_lock ) CALL plock_omp ( 'set', 1 )

      CALL irecv ( yp_rcv, yproc, nang, ichunk, nz,                    &
                   jb_in(:,:,:,icor,g), ycomm, mtag(icor), reqr(icor) )

      CALL irecv ( zp_rcv, zproc, nang, ichunk, ny,                    &
                   kb_in(:,:,:,icor,g), zcomm, mtag(icor),             &
                   reqr(ncor+icor) )

      IF ( use_lock ) CALL plock_omp ( 'unset', 1 )
!_______________________________________________________________________
!
!   End the loops
!_______________________________________________________________________

    END DO
    END DO
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE multiswp_recv_bdry


  SUBROUTINE multiswp_test_pick ( ncor, corner_loop_order, yzstg, nstg,&
    nulreq, g_op, reqr, szreqr, done, reqs, szreqs, cor )

!-----------------------------------------------------------------------
!
! Determine the next corner that shall be swept. Wait until a message is
! received, indicating that the corresponding corner sweep is set to
! advance. Then check that the send buffers are also clear. If yes,
! proceed with sweep. If not, use skip_corner to find a different corner
! to sweep. Exit once a suitable corner is found with received incoming
! information and send buffers safe to overwrite.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: ncor, nstg, nulreq, szreqr, szreqs

    INTEGER(i_knd), INTENT(OUT) :: cor

    INTEGER(i_knd), DIMENSION(ncor), INTENT(IN) :: corner_loop_order,  &
      yzstg, g_op

    INTEGER(i_knd), DIMENSION(szreqr), INTENT(INOUT) :: reqr

    INTEGER(i_knd), DIMENSION(szreqs), INTENT(INOUT) :: reqs

    LOGICAL(l_knd), DIMENSION(ncor), INTENT(IN) :: done
!_______________________________________________________________________
!
!   Local variables.
!_______________________________________________________________________

    INTEGER(i_knd) :: i, j, outcount

    INTEGER(i_knd), DIMENSION(ncor) :: tcor, skip_cor

    INTEGER(i_knd), DIMENSION(szreqr) :: indx
!_______________________________________________________________________
!_______________________________________________________________________

    IF ( ncor == 1 ) THEN
      cor = 1
      RETURN
    END IF
!_______________________________________________________________________
!
!   Loop over send and receive buffers to find suitable next task
!_______________________________________________________________________

    cor = 0
    skip_cor = 0

    send_cor_loop: DO

      indx = 0
      tcor = -1
!_______________________________________________________________________
!
!     Loop over starting corners to see if any messages arrived,
!     according to reqr values. Determine remaining number of stages for
!     prioritizing next task
!_______________________________________________________________________

      recv_cor_loop: DO

        IF ( use_lock ) CALL plock_omp ( 'set', 1 )

        CALL testsome ( reqr, indx, szreqr, outcount )

        IF ( use_lock ) CALL plock_omp ( 'unset', 1 )

        DO j = 1, ncor
          i = corner_loop_order(j)
          IF ( skip_cor(i) == 1 ) CYCLE
          IF ( done(i) ) CYCLE
          IF ( reqr(i)==nulreq .AND. reqr(ncor+i)==nulreq )            &
            tcor(i) = nstg - g_op(i) - yzstg(i)
        END DO
!_______________________________________________________________________
!
!       Take corner with most stages to go or check against allowed
!       repeat of corner. Clean the skip_cor flag if need to re-test.
!_______________________________________________________________________

        IF ( ANY( tcor >= 0 ) ) THEN
          cor = MAXLOC( tcor, 1 )
          EXIT recv_cor_loop
        ELSE
          skip_cor = 0
        END IF

      END DO recv_cor_loop
!_______________________________________________________________________
!
!     For selected corner, test if the send buffer is also free. Exit if
!     so and return to receive side if not.
!_______________________________________________________________________

      IF ( use_lock ) CALL plock_omp ( 'set', 1 )

      CALL tests ( reqs(cor) )
      CALL tests ( reqs(ncor+cor) )

      IF ( use_lock ) CALL plock_omp ( 'unset', 1 )

      IF ( reqs(cor)==nulreq .AND. reqs(ncor+cor)==nulreq ) THEN
        EXIT send_cor_loop
      ELSE
        skip_cor(cor) = 1
      END If

    END DO send_cor_loop
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE multiswp_test_pick


  SUBROUTINE multiswp_send_bdry ( ncor, jd, kd, nang, ichunk, ny, nz,  &
    mtag, reqy, reqz, jb_out, kb_out )

!-----------------------------------------------------------------------
!
! Transmit outgoing edge fluxes to downstream PE's.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: ncor, jd, kd, nang, ichunk, ny, nz,  &
      mtag

    INTEGER(i_knd), INTENT(INOUT) :: reqy, reqz

    REAL(r_knd), DIMENSION(nang,ichunk,nz), INTENT(IN) :: jb_out

    REAL(r_knd), DIMENSION(nang,ichunk,ny), INTENT(IN) :: kb_out

!-----------------------------------------------------------------------
!
!   Local variables.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd) :: yp_snd, zp_snd
!_______________________________________________________________________
!_______________________________________________________________________

    IF ( ncor == 1 ) RETURN
!_______________________________________________________________________
!
!   Set up the communication basics
!_______________________________________________________________________

    IF ( jd == 1 ) THEN
      yp_snd = ylop
    ELSE
      yp_snd = yhip
    END IF

    IF ( kd == 1 ) THEN
      zp_snd = zlop
    ELSE
      zp_snd = zhip
    END IF
!_______________________________________________________________________
!
!   Make asynchronous calls to send data
!_______________________________________________________________________

    IF ( use_lock ) CALL plock_omp ( 'set', 1 )

    CALL isend ( yp_snd, yproc, nang, ichunk, nz, jb_out, ycomm, mtag, &
                 reqy )

    CALL isend ( zp_snd, zproc, nang, ichunk, ny, kb_out, zcomm, mtag, &
                 reqz )

    IF ( use_lock ) CALL plock_omp ( 'unset', 1 )
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE multiswp_send_bdry


  SUBROUTINE lock_control ( op, t )

!-----------------------------------------------------------------------
!
! Set/unset array of locks used by threads with MPI_THREAD_SERIALIZED.
!
!-----------------------------------------------------------------------

    CHARACTER(LEN=*), INTENT(IN) :: op

    INTEGER(i_knd), INTENT(IN) :: t
!_______________________________________________________________________
!_______________________________________________________________________

    SELECT CASE ( op )

      CASE ( 'set' )

  !$OMP BARRIER
        IF ( t < nthreads ) CALL plock_omp ( 'set', t+1 )
  !$OMP BARRIER
        CALL plock_omp ( 'set', t )

      CASE ( 'unset' )

        IF ( t < nthreads ) CALL plock_omp ( 'unset', t+1 )
        CALL plock_omp ( 'unset', t )

      CASE DEFAULT

        RETURN

    END SELECT
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE lock_control


END MODULE thrd_comm_module
