!-----------------------------------------------------------------------
!
! MODULE: setup_module
!> @brief
!> This module controls problem setup, including geometry setup, angular
!> domain setup, data setup, material and source layouts. Calls for
!> data allocation.
!
!-----------------------------------------------------------------------

MODULE setup_module

  USE global_module, ONLY: i_knd, r_knd, ounit, zero, half, one, two

  USE geom_module, ONLY: ndimen, nx, ny, nz, lx, ly, lz, dx, dy, dz,   &
    ny_gl, nz_gl, jlb, jub, klb, kub, nc, jdim, kdim

  USE sn_module, ONLY: nang, mu, eta, xi, w, nmom, noct, sn_allocate,  &
    sn_expcoeff

  USE data_module, ONLY: ng, v, mat_opt, mat, src_opt, scatp, qi, nmat,&
    sigt, siga, sigs, slgg, data_allocate

  USE control_module, ONLY: epsi, iitm, oitm, timedep, tf, nsteps, dt, &
    swp_typ, it_det, fluxp, fixup, soloutp, kplane, popout, ncor, nops,&
    last_oct, corner_sch, multiswp, yzstg, corner_loop_order, angcpy,  &
    control_allocate

  USE mms_module, ONLY: mms_setup

  USE utils_module, ONLY: print_error, stop_run, open_file, close_file

  USE time_module, ONLY: tset, wtime

  USE plib_module, ONLY: npey, npez, glmax, comm_snap, yproc, zproc,   &
    iproc, root, nthreads, thread_level, thread_single,                &
    thread_funneled, thread_serialized, thread_multiple, nnested,      &
    do_nested, ichunk, pce

  IMPLICIT NONE

  PRIVATE

  PUBLIC :: setup


  CONTAINS


  SUBROUTINE setup ( ndpwds )

!-----------------------------------------------------------------------
!
! Control the setup process.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(INOUT) :: ndpwds
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    CHARACTER(LEN=64) :: error

    INTEGER(i_knd) :: flg, ierr, i, idle, hnpy, hnpz, mgpt, stgs, mis, &
      mie, mjs, mje, mks, mke, qis, qie, qjs, qje, qks, qke

    REAL(r_knd) :: t1, t2
!_______________________________________________________________________
!
!   First put input ny and nz into ny_gl and nz_gl respectively. Use ny
!   and nz for local sizes. Determine global indices of local bounds.
!   Set the number of spatial work chunks, nc. Set number of sweep
!   directions in y/z, jdim/kdim.
!_______________________________________________________________________

    CALL wtime ( t1 )

    ny_gl = ny
    nz_gl = nz
    ny = ny_gl / npey
    nz = nz_gl / npez

    jlb = yproc*ny + 1
    jub = (yproc+1) * ny
    klb = zproc*nz + 1
    kub = (zproc+1) * nz

    nc = nx/ichunk

    jdim = MIN( ndimen, 2 )
    kdim = MAX( ndimen-1, 1 )
    ncor = jdim*kdim
!_______________________________________________________________________
!
!   Allocate needed arrays
!_______________________________________________________________________

    CALL setup_alloc ( ndpwds, flg, ierr, error )
    IF ( ierr /= 0 ) THEN
      CALL print_error ( ounit, error )
      CALL stop_run ( 1, flg, 0, 0 )
    END IF
!_______________________________________________________________________
!
!   Set up the corner schedule for 3-D problems. Choose the order that
!   minimizes the number of stages based on npey and npez.
!_______________________________________________________________________

    corner_sch = 0
    IF ( ndimen == 3 ) THEN
      IF ( npey <= npez ) THEN
        last_oct = 6
        corner_sch(:,1) = (/ 1, 1 /)
        corner_sch(:,2) = (/ 2, 1 /)
        corner_sch(:,3) = (/ 2, 2 /)
        corner_sch(:,4) = (/ 1, 2 /)
      ELSE
        last_oct = 4
        corner_sch(:,1) = (/ 1, 1 /)
        corner_sch(:,2) = (/ 1, 2 /)
        corner_sch(:,3) = (/ 2, 2 /)
        corner_sch(:,4) = (/ 2, 1 /)
      END IF
    ELSE
      last_oct = 2**ndimen
      corner_sch(:,1) = (/ 1, 1 /)
      corner_sch(:,2) = (/ 2, 1 /)
    END IF
!_______________________________________________________________________
!
!   Set up the concurrent octant mesh sweeps control information. Force
!   normal sweeper swp_typ=0 for now. Set nops. Compute an array that
!   determines each KBA stage's relative position in the full sweep,
!   yzstg, and the number of stages per octant pair. Set up the corner
!   loop priority to avoid wasted request comparisons on messages not
!   likely to be received.
!_______________________________________________________________________

    yzstg = 0
    corner_loop_order = 0

    IF ( multiswp == 1 ) THEN

      nops = ng*ncor*2*nc
      swp_typ=0

      yzstg(1) = npey - (yproc + 1) + npez - (zproc + 1)
      yzstg(2) = yproc + npez - (zproc + 1)
      yzstg(3) = npey - (yproc + 1) + zproc
      yzstg(4) = yproc + zproc

      IF ( ndimen == 1 ) THEN
        i = 1
      ELSE IF ( ndimen == 2 ) THEN
        i = MINLOC( yzstg(1:2), 1 )
      ELSE
        i = MINLOC( yzstg, 1 )
      END IF

      SELECT CASE ( i )
        CASE ( 1 )
          IF ( ndimen == 1 ) THEN
            corner_loop_order = (/ 1, 0, 0, 0 /)
          ELSE IF ( ndimen == 2 ) THEN
            corner_loop_order = (/ 1, 2, 0, 0 /)
          ELSE          
            corner_loop_order = (/ 1, 2, 3, 4 /)
          END IF
        CASE ( 2 )
          IF ( ndimen == 2 ) THEN
            corner_loop_order = (/ 2, 1, 0, 0 /)
          ELSE
            corner_loop_order = (/ 2, 1, 4, 3 /)
          END IF
        CASE ( 3 )
          corner_loop_order = (/ 3, 4, 1, 2 /)
        CASE ( 4 )
          corner_loop_order = (/ 4, 3, 2, 1 /)
      END SELECT

    END IF
!_______________________________________________________________________
!
!   Compute PCE. The corner sweeps PCE is a guess as to the best-case
!   scenario: effectively that additional corner starts a dimension
!   compared to a single corner start.
!_______________________________________________________________________

    IF ( multiswp == 0 ) THEN
      IF ( npey <= npez ) THEN
        idle = 3*(npey-1) + 2*(npez-1)
      ELSE
        idle = 2*(npey-1) + 3*(npez-1)
      END IF
    ELSE
      hnpy = CEILING( REAL( npey, r_knd ) / two )
      hnpz = CEILING( REAL( npez, r_knd ) / two )
      idle = 2 * ( hnpy + hnpz - 2 )
    END IF

    mgpt = CEILING( REAL( ng, r_knd ) / REAL( nthreads, r_knd ) )
    stgs = nc*noct*mgpt + idle

    pce = REAL( nc*noct*ng, r_knd ) / REAL( nthreads*stgs, r_knd )
!_______________________________________________________________________
!
!   Progress through setups. _delta sets cell and step sizes, _vel sets
!   velocity array, _angle sets the ordinates/weights, _mat sets the
!   material identifiers, _src sets fixed source, _data sets the
!   mock cross section arrays, and sn_expcoeff sets up the scattering
!   expansion basis function array.
!_______________________________________________________________________

    CALL setup_delta

    CALL setup_vel

    CALL setup_angle

    CALL setup_mat ( mis, mie, mjs, mje, mks, mke )

    CALL setup_data

    CALL sn_expcoeff ( ndimen )

    CALL setup_src ( qis, qie, qjs, qje, qks, qke, ierr, error )
    IF ( ierr /= 0 ) THEN
      CALL print_error ( ounit, error )
      CALL stop_run ( 1, 3, 0, 0 )
    END IF
!_______________________________________________________________________
!
!   Echo the data from this module to the output file. If requested via
!   scatp, print the full scattering matrix to file.
!_______________________________________________________________________

    IF ( iproc == root ) THEN
      CALL setup_echo ( mis, mie, mjs, mje, mks, mke, qis, qie, qjs,   &
      qje, qks, qke )
      IF ( scatp == 1 ) CALL setup_scatp ( ierr, error )
    END IF

    CALL glmax ( ierr, comm_snap )
    IF ( ierr /= 0 ) THEN
      CALL print_error ( ounit, error )
      CALL stop_run ( 1, 4, 0, 0 )
    END IF

    CALL wtime ( t2 )
    tset = t2 - t1
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE setup


  SUBROUTINE setup_alloc ( ndpwds, flg, ierr, error )

!-----------------------------------------------------------------------
!
! Call for individual allocation routines to size the run-time arrays.
!
!-----------------------------------------------------------------------

    CHARACTER(LEN=64), INTENT(OUT) :: error

    INTEGER(i_knd), INTENT(INOUT) :: ndpwds

    INTEGER(i_knd), INTENT(OUT) :: flg, ierr
!_______________________________________________________________________

    flg = 0
    ierr = 0
    error = ' '

    CALL sn_allocate ( ndimen, ndpwds, ierr )
    CALL glmax ( ierr, comm_snap )
    IF ( ierr /= 0 ) THEN
      error = '***ERROR: SETUP_ALLOC: Allocation error in SN_ALLOCATE'
      RETURN
    END IF

    CALL data_allocate ( nx, ny, nz, nmom, nang, noct, timedep,        &
                         ndpwds, ierr )
    CALL glmax ( ierr, comm_snap )
    IF ( ierr /= 0 ) THEN
      flg = 1
      error = '***ERROR: SETUP_ALLOC: Allocation error in DATA_ALLOCATE'
      RETURN
    END IF

    CALL control_allocate ( ng, ndpwds, ierr )
    CALL glmax ( ierr, comm_snap )
    IF ( ierr /= 0 ) THEN
      flg = 2
      error = '***ERROR: CONTROL_ALLOC: Allocation error of control '//&
              'arrays'
      RETURN
    END IF

!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE setup_alloc


  SUBROUTINE setup_delta

!-----------------------------------------------------------------------
!
! Spatial cell and time step size computation.
!
!-----------------------------------------------------------------------
!_______________________________________________________________________
!_______________________________________________________________________

    dx = lx / REAL( nx, r_knd )
    IF ( ndimen > 1 ) dy = ly / REAL( ny_gl, r_knd )
    IF ( ndimen > 2 ) dz = lz / REAL( nz_gl, r_knd )

    IF ( timedep == 1 ) dt = tf / REAL( nsteps, r_knd )
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE setup_delta


  SUBROUTINE setup_vel

!-----------------------------------------------------------------------
!
! Setup a simple mock velocity array for time-dependent calcs
!
!-----------------------------------------------------------------------
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: g, t
!_______________________________________________________________________
!
!   Loop over groups. Set velocities simply according to ng.
!_______________________________________________________________________

    IF ( timedep == 0 ) RETURN

    DO g = 1, ng
      t = ng - g + 1
      v(g) = REAL( t, r_knd )
    END DO
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE setup_vel


  SUBROUTINE setup_angle

!-----------------------------------------------------------------------
!
! Create the mock quadrature sets for 1-D, 2-D, and 3-D problems.
!
!-----------------------------------------------------------------------
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: m

    REAL(r_knd) :: dm

    REAL(r_knd), DIMENSION(nang) :: t
!_______________________________________________________________________
!
!   Arrays allocated according to dimensionality. So do loops by ndimen.
!_______________________________________________________________________

    dm = one/REAL( nang, r_knd )
    t = zero

    mu(1) = half*dm
    DO m = 2, nang
      mu(m) = mu(m-1) + dm
    END DO

    IF ( ndimen > 1 ) THEN
      eta(1) = one - half*dm
      DO m = 2, nang
        eta(m) = eta(m-1) - dm
      END DO

      IF ( ndimen > 2 ) THEN
        t = mu**2 + eta**2
        DO m = 1, nang
          xi(m) = SQRT( one - t(m) )
        END DO
      END IF

    END IF
!_______________________________________________________________________
!
!   Give all weights same value.
!_______________________________________________________________________

    IF ( ndimen == 1 ) THEN
      w = half / REAL( nang, r_knd )
    ELSE IF ( ndimen == 2 ) THEN
      w = 0.25_r_knd / REAL( nang, r_knd )
    ELSE
      w = 0.125_r_knd / REAL( nang, r_knd )
    END IF
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE setup_angle


  SUBROUTINE setup_mat ( i1, i2, j1, j2, k1, k2 )

!-----------------------------------------------------------------------
!
! Setup the material according to mat_opt.
!
! There are only two materials max; one per cell. mat_opt defines the
! material layout and has a similar meaning for 1-D, 2-D, 3-D problems.
!
! 0 = Homogeneous (mat1) problem, regardless of dimension
! 1 = Center. mat1 is the base. 1-D: 25%mat1/50%mat2/25%mat1
!     2/D: same as 1-D but in two dimensions, so mat2 region is a square
!     3/D: same as 1-D but in three dimensions, so mat2 is a cube
! 2 = Corner. Same concept as 1, but move slab/square/cube to origin
!
! Return starting/ending indices for printint an echo.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(OUT) :: i1, i2, j1, j2, k1, k2
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: i, j, k, jj, kk
!_______________________________________________________________________
!
!   Form the base with mat1. Use dimension and mat_opt to determine
!   the rest of the layout.
!_______________________________________________________________________

    mat = 1

    i1 = 1; i2 = 1
    j1 = 1; j2 = 1
    k1 = 1; k2 = 1
    IF ( mat_opt == 1 ) THEN
      i1 = nx/4 + 1
      i2 = 3*nx/4
      IF ( ndimen > 1 ) THEN
        j1 = ny_gl/4 + 1
        j2 = 3*ny_gl/4
        IF ( ndimen > 2 ) THEN
          k1 = nz_gl/4 + 1
          k2 = 3*nz_gl/4
        END IF
      END IF
    ELSE IF ( mat_opt == 2 ) THEN
      i2 = nx/2
      IF ( ndimen > 1 ) THEN
        j2 = ny_gl/2
        IF ( ndimen > 2 ) k2 = nz_gl/2
      END IF
    END IF

    IF ( mat_opt > 0 ) THEN
      DO k = k1, k2
        IF ( klb<=k .AND. k<=kub ) THEN
          kk = MOD( k-1, nz ) + 1
          DO j = j1, j2
            IF ( jlb<=j .AND. j<=jub ) THEN
              jj = MOD( j-1, ny ) + 1
              DO i = i1, i2
                mat(i,jj,kk) = 2
              END DO
            END IF
          END DO
        END IF
      END DO
    END IF
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE setup_mat


  SUBROUTINE setup_src ( i1, i2, j1, j2, k1, k2, ierr, error )

!-----------------------------------------------------------------------
!
! Setup the material according to src_opt.
!
! Source is either on at strength 1.0 or off, per cell. src_opt defines
! the layout and has a similar meaning for 1-D, 2-D, 3-D problems.
!
! 0 = Source everywhere, regardless of dimension
! 1 = Source occupies the slab/square/cube center of the problem
!     1/D: 25%/50%/25% = source off/on/off
!     2/D: same as 1-D but in two dimensions
!     3/D: same as 1-D but in three dimensions
! 2 = Corner. Same concept as 1, but move slab/square/cube to origin
! 3 = MMS option, f = sin(pi*x/lx)
! All options isotropic source
!
! Return starting/ending indices for printing an echo.
!
!-----------------------------------------------------------------------

    CHARACTER(LEN=64), INTENT(OUT) :: error

    INTEGER(i_knd), INTENT(OUT) :: i1, i2, j1, j2, k1, k2, ierr
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: i, j, k, jj, kk
!_______________________________________________________________________
!
!   Form the base by setting the src to 0 to start. Then assign src to
!   spatial cells according to ndimen and src_opt.
!_______________________________________________________________________

    IF ( src_opt == 3 ) THEN
      CALL mms_setup ( ierr, error )
      RETURN
    END IF
!_______________________________________________________________________
!
!   If src_opt is 0, source is everywhere
!_______________________________________________________________________

    i1 = 1; i2 = nx
    j1 = 1; j2 = ny_gl
    k1 = 1; k2 = nz_gl
!_______________________________________________________________________
!
!   IF src_opt is not 0, reset indices for source's spatial range
!_______________________________________________________________________

    IF ( src_opt == 1 ) THEN
      i1 = nx/4 + 1
      i2 = 3*nx/4
      IF ( ndimen > 1 ) THEN
        j1 = ny_gl/4 + 1
        j2 = 3*ny_gl/4
        IF ( ndimen > 2 ) THEN
          k1 = nz_gl/4 + 1
          k2 = 3*nz_gl/4
        END IF
      END IF
    ELSE IF ( src_opt == 2 ) THEN
      i2 = nx/2
      IF ( ndimen > 1 ) THEN
        j2 = ny_gl/2
        IF ( ndimen > 2 ) k2 = nz_gl/2
      END IF
    END IF
!_______________________________________________________________________
!
!   Indices are all known, so set the source to unity for that range
!_______________________________________________________________________

    DO k = k1, k2
      IF ( klb<=k .AND. k<=kub ) THEN
        kk = MOD( k-1, nz ) + 1
        DO j = j1, j2
          IF ( jlb<=j .AND. j<=jub ) THEN
            jj = MOD( j-1, ny ) + 1
            DO i = i1, i2
              qi(i,jj,kk,:) = one
            END DO
          END IF
        END DO
      END IF
    END DO
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE setup_src


  SUBROUTINE setup_data

!-----------------------------------------------------------------------
!
! Setup the data arrays according to simple rules/functions to scale
! to arbitrary number of groups, moments. Fixed at a library for two
! materials only. Fixed group-to-group coupling properties.
!
!-----------------------------------------------------------------------
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    INTEGER(i_knd) :: g, n

    REAL(r_knd) :: t
!_______________________________________________________________________
!
!   Set the group 1 data for material 1 and material 2 (if present).
!_______________________________________________________________________

    sigt(1,1) = one
    siga(1,1) = half
    sigs(1,1) = half

    IF ( nmat == 2 ) THEN
      sigt(2,1) = two
      siga(2,1) = 0.8_r_knd
      sigs(2,1) = 1.2_r_knd
    END IF
!_______________________________________________________________________
!
!   Scale these values for increasing number of groups by adding 0.01
!   to sigt for each additional group. Split that 0.01 evenly among
!   siga and sigs.
!_______________________________________________________________________

    DO g = 2, ng
      sigt(:,g) = sigt(:,g-1) + 0.01_r_knd
      siga(:,g) = siga(:,g-1) + 0.005_r_knd
      sigs(:,g) = sigs(:,g-1) + 0.005_r_knd
    END DO
!_______________________________________________________________________
!
!   For material 1, upscattering from a given group to all above groups
!   is 10% of total scattering. 20% is in group. 70% is down-scattering.
!   For group 1/ng, no up/down-scattering, so self-scattering takes the
!   remaining fraction.
!_______________________________________________________________________

    DO g = 1, ng

      IF ( ng == 1 ) THEN
        slgg(1,1,1,1) = sigs(1,g)
        EXIT
      END IF

      slgg(1,1,g,g) = 0.2_r_knd*sigs(1,g)

      IF ( g > 1 ) THEN
        t = one / REAL( g-1, r_knd )
        slgg(1,1,g,1:(g-1)) = 0.1_r_knd*sigs(1,g)*t
      ELSE
        slgg(1,1,1,1) = 0.3_r_knd*sigs(1,1)
      END IF

      IF ( g < ng ) THEN
        t = one / REAL( ng-g, r_knd )
        slgg(1,1,g,(g+1):ng) = 0.7_r_knd*sigs(1,g)*t
      ELSE
        slgg(1,1,ng,ng) = 0.9_r_knd*sigs(1,ng)
      END IF

    END DO

    IF ( nmat == 2 ) THEN
!_______________________________________________________________________
!
!     Repeat for material 2. Up-scattering is 10%. In-scattering is 50%.
!     Down-scattering is 40%.
!_______________________________________________________________________

      DO g = 1, ng

        IF ( ng == 1 ) THEN
          slgg(2,1,1,1) = sigs(2,g)
          EXIT
        END IF

        slgg(2,1,g,g) = 0.5_r_knd*sigs(2,g)

        IF ( g > 1 ) THEN
          t = one / REAL( g-1, r_knd )
          slgg(2,1,g,1:(g-1)) = 0.1_r_knd*sigs(2,g)*t
        ELSE
          slgg(2,1,1,1) = 0.6_r_knd*sigs(2,1)
        END IF

        IF ( g < ng ) THEN
          t = one / REAL( ng-g, r_knd )
          slgg(2,1,g,(g+1):ng) = 0.4_r_knd*sigs(2,g)*t
        ELSE
          slgg(2,1,ng,ng) = 0.9_r_knd*sigs(2,ng)
        END IF

      END DO

    END IF
!_______________________________________________________________________
!
!   Set group-to-group scattering moments. Allowed up 4 moments. For
!   material 1, start with the base above. Divide by 10 to get next
!   moment's data. Repeat that by 2 continuously, up to nmom or 4.
!_______________________________________________________________________

    IF ( nmom > 1 ) THEN
      slgg(1,2,:,:) = 0.1_r_knd*slgg(1,1,:,:)
      DO n = 3, nmom
        slgg(1,n,:,:) = half*slgg(1,n-1,:,:)
      END DO
    END IF
!_______________________________________________________________________
!
!   Similar procedure for material 2, but first multiply by 0.8. Then
!   reduce the data magnitudes by 0.6 for each successive moment.
!_______________________________________________________________________

    IF ( nmat==2 .AND. nmom>1 ) THEN
      slgg(2,2,:,:) = 0.8_r_knd*slgg(2,1,:,:)
      DO n = 3, nmom
        slgg(2,n,:,:) = 0.6_r_knd*slgg(2,n-1,:,:)
      END DO
    END IF
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE setup_data


  SUBROUTINE setup_echo ( mis, mie, mjs, mje, mks, mke, qis, qie, qjs, &
    qje, qks, qke )

!-----------------------------------------------------------------------
!
! Print run-time variables setup in this module to the output file.
!
!-----------------------------------------------------------------------

    INTEGER(i_knd), INTENT(IN) :: mis, mie, mjs, mje, mks, mke, qis,   &
      qie, qjs, qje, qks, qke
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    CHARACTER(LEN=1) :: star='*'

    INTEGER(i_knd) :: i, j
!_______________________________________________________________________

    WRITE( ounit, 131 ) ( star, i = 1, 80 )

    WRITE( ounit, 132 )
    WRITE( ounit, 133 ) ndimen, nx, ny_gl, nz_gl, lx, ly, lz, dx, dy, dz

    WRITE( ounit, 134 )
    WRITE( ounit, 135 ) nmom, nang, noct, w(1)
    WRITE( ounit, 136 )
    SELECT CASE ( ndimen )
     CASE ( 1 )
      WRITE( ounit, 137 ) ( mu(i), i = 1, nang )
     CASE ( 2 )
      WRITE( ounit, 138 ) ( mu(i), eta(i), i = 1, nang )
     CASE ( 3 )
      WRITE( ounit, 139 ) ( mu(i), eta(i), xi(i), i = 1, nang )
    END SELECT

    WRITE( ounit, 140 )
    WRITE( ounit, 141 ) mat_opt, nmat
    WRITE( ounit, 142 )
    IF( mat_opt > 0 ) WRITE( ounit, 143 ) mis, mjs, mks, mie, mje, mke

    WRITE( ounit, 144 )
    WRITE( ounit, 145 ) src_opt
    IF ( src_opt < 3 ) THEN
      WRITE( ounit, 146 )
      WRITE( ounit, 147 ) qis, qjs, qks, qie, qje, qke
    ELSE
      WRITE( ounit, 1471 )
    END IF

    WRITE( ounit, 148 )
    WRITE( ounit, 149 ) ng
    DO j = 1, nmat
      WRITE( ounit, 150 ) j
      WRITE( ounit, 151 )
      WRITE( ounit, 152 ) ( i, sigt(j,i), siga(j,i), sigs(j,i),        &
                            i = 1, ng )
    END DO

    IF ( timedep == 1 ) THEN
      WRITE( ounit, 153 )
      WRITE( ounit, 154 ) tf, nsteps, dt
      WRITE( ounit, 155 )
      WRITE( ounit, 156 ) ( i, v(i), i = 1, ng )
    END IF

    WRITE( ounit, 157 )
    WRITE( ounit, 158 ) epsi, iitm, oitm, timedep, swp_typ, multiswp,  &
      angcpy, it_det, soloutp, kplane, popout, fluxp, fixup

    WRITE( ounit, 181 )
    WRITE( ounit, 182 ) npey, npez, nthreads
    WRITE( ounit, 183 ) thread_single, thread_funneled,                &
      thread_serialized, thread_multiple
    WRITE( ounit, 184 ) thread_level
    IF ( do_nested ) THEN
      WRITE( ounit, 185 ) nnested
    ELSE
      WRITE( ounit, 186 ) nnested
    END IF
    WRITE ( ounit, 187 ) pce

    WRITE( ounit, 159 ) ( star, i = 1, 80 )
!_______________________________________________________________________

    131 FORMAT( 10X, 'keyword Calculation Run-time Parameters Echo', /,&
                80A, / )

    132 FORMAT( 2X, 'Geometry' )
    133 FORMAT( 4X, 'ndimen = ', I1, /, 4X, 'nx = ', I5, /, 4X,        &
                'ny = ', I5, /, 4X, 'nz = ', I5, /, 4X, 'lx = ',       &
                ES11.4, /, 4X, 'ly = ', ES11.4, /, 4X, 'lz = ', ES11.4,&
                /, 4X, 'dx = ', ES11.4, /, 4X, 'dy = ', ES11.4, /, 4X, &
                'dz = ', ES11.4, / )

    134 FORMAT( 2X, 'Sn' )
    135 FORMAT( 4X, 'nmom = ', I1, /, 4X, 'nang = ', I4, /, 4X,        &
                'noct = ', I1, /, /, 4X, 'w = ', ES11.4,               &
                '   ... uniform weights', / )
    136 FORMAT( 4X, '      mu              eta               xi')
    137 FORMAT( 4X, ES15.8 )
    138 FORMAT( 4X, ES15.8, 2X, ES15.8 )
    139 FORMAT( 4X, ES15.8, 2X, ES15.8, 2X, ES15.8 )

    140 FORMAT( /, 2X, 'Material Map' )
    141 FORMAT( 4X, 'mat_opt = ', I1, '   -->   nmat = ', I1 )
    142 FORMAT( 4X, 'Base material (default for every cell) = 1' )
    143 FORMAT( 4X, 'Material 2 present:', /, 8X, 'Starting cell: ( ', &
                I5, ', ', I5, ', ', I5, ' )', /, 8X,                   &
                'Ending cell:   ( ', I5, ', ', I5, ', ', I5, ' )' )

    144 FORMAT( /, 2X, 'Source Map' )
    145 FORMAT( 4X, 'src_opt = ', I1 )
    146 FORMAT( 4X, 'Source strength per cell (where applied) = 1.0' )
    147 FORMAT( 4X, 'Source map:', /, 8X, 'Starting cell: ( ', I5,     &
                ', ', I5, ', ', I5, ' )', /, 8X, 'Ending cell:   ( ',  &
                I5, ', ', I5, ', ', I5, ' )', / )
    1471 FORMAT( 4X, 'MMS-generated source', / )

    148 FORMAT( 2X, 'Pseudo Cross Sections Data' )
    149 FORMAT( 4X, 'ng = ', I3 )
    150 FORMAT( /, 4X, 'Material ', I1 )
    151 FORMAT( 4X, 'Group         Total         Absorption      ',    &
               'Scattering' )
    152 FORMAT( 5X, I3, 6X, ES13.6, 3X, ES13.6, 3X, ES13.6 )

    153 FORMAT( /, 2X, 'Time-Dependent Calculation Data' )
    154 FORMAT( 4X, 'tf = ', ES11.4, /, 4X, 'nsteps = ', I4, /, 4X,    &
                'dt = ', ES11.4, / )
    155 FORMAT( 4X, 'Group        Speed' )
    156 FORMAT( 5X, I3, 6X, ES11.4 )

    157 FORMAT( /, 2X, 'Solution Control Parameters' )
    158 FORMAT( 4X, 'epsi = ', ES11.4, /, 4X, 'iitm = ', I3, /,        &
                4X, 'oitm = ', I4, /, 4X, 'timedep = ', I1, /,         &
                4X, 'swp_typ = ', I1, /, 4X, 'multiswp = ', I1, /,     &
                4X, 'angcpy = ', I1, /,  4X, 'it_det = ', I1, /,       &
                4X, 'soloutp = ', I1, /, 4X, 'kplane = ', I4, /,       &
                4X, 'popout = ', I1, /, 4X, 'fluxp = ', I1, /,         &
                4X, 'fixup = ', I1, / )

    181 FORMAT( /, 2X, 'Parallelization Parameters' )
    182 FORMAT( 4X, 'npey = ', I5, /, 4X, 'npez = ', I5, /, 4X,        &
                'nthreads = ', I4, / )
    183 FORMAT( 10X, 'Thread Support Level', /,                        &
                10X, I2, ' - MPI_THREAD_SINGLE', /,                    &
                10X, I2, ' - MPI_THREAD_FUNNELED', /,                  &
                10X, I2, ' - MPI_THREAD_SERIALIZED', /,                &
                10X, I2, ' - MPI_THREAD_MULTIPLE' )
    184 FORMAT( 4X, 'thread_level = ', I2, / )
    185 FORMAT( 4X, '.TRUE. nested threading', /, 6X, 'nnested = ',    &
                I4, / )
    186 FORMAT( 4X, '.FALSE. nested threading', /, 6X, 'nnested = ',   &
                I4, / )
    187 FORMAT( 4X, 'Parallel Computational Efficiency = ', F6.4, / )

    159 FORMAT( 80A, / )
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE setup_echo


  SUBROUTINE setup_scatp ( ierr, error )

!-----------------------------------------------------------------------
!
! Print the slgg (scattering matrix) array to special file 'slgg'.
!
!-----------------------------------------------------------------------

    CHARACTER(LEN=64), INTENT(OUT) :: error

    INTEGER(i_knd), INTENT(OUT) :: ierr
!_______________________________________________________________________
!
!   Local variables
!_______________________________________________________________________

    CHARACTER(LEN=16) :: fn='slgg'

    INTEGER(i_knd) :: l, g1, g2, n, fu=15
!_______________________________________________________________________
!
!   Open the 'slgg' file
!_______________________________________________________________________

    ierr = 0
    error = ' '
    CALL open_file ( fu, fn, 'REPLACE', 'WRITE', ierr, error )
    IF ( ierr /= 0 ) RETURN
!_______________________________________________________________________
!
!   Write out the matrix in standard Fortran column-ordering
!_______________________________________________________________________

    WRITE( fu, 161 )
    WRITE( fu, 162 ) ( ( ( ( slgg(n,l,g1,g2), n = 1, nmat ),           &
                      l = 1, nmom ), g1 = 1, ng ), g2 = 1, ng )
!_______________________________________________________________________
!
!   Close file
!_______________________________________________________________________

    CALL close_file ( fu, ierr, error )
!_______________________________________________________________________

    161 FORMAT( 'slgg(nmat,nmom,ng,ng) echo', /, 'Column-order loops:',&
                ' Mats (fastest ), Moments, Groups, Groups (slowest)' )
    162 FORMAT( 2X, ES15.8, 2X, ES15.8, 2X, ES15.8, 2X, ES15.8 )
!_______________________________________________________________________
!_______________________________________________________________________

  END SUBROUTINE setup_scatp


END MODULE setup_module
