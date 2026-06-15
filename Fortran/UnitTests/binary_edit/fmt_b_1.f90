! extension allows B edit descriptors for logical input/output
!
  program fmt_b_1
    integer :: ios
    logical :: x, y, z
    logical, parameter :: f = .false., t = .true.
    character(len=64) :: s

    write (s,'(b32)') f
    if (s .ne. '                               0') stop 1
    x = .true.
    read (s,'(b32)') x
    if (x .neqv. .false.) stop 2

    write (s,'(b32)') t
    if (s .ne. '                               1') stop 3
    x = .false.
    read (s,'(b32)') x
    if (x .neqv. .true.) stop 4

    write (s,'(B16)') f
    if (s .ne. '               0') stop 5
    x = .true.
    read (s,'(B16)') x
    if (x .neqv. .false.) stop 6
    write (s,'(B16)') t
    if (s .ne. '               1') stop 7
    x = .false.
    read (s,'(B16)') x
    if (x .neqv. .true.) stop 8

    write (s,'(B9)') f
    if (s .ne. '        0') stop 9
    x = .true.
    read (s,'(B9)') x
    if (x .neqv. .false.) stop 10

    write (s,'(B9)') t
    if (s .ne. '        1') stop 11
    x = .false.
    read (s,'(B9)') x
    if (x .neqv. .true.) stop 12

    write (s,'(B2)') f
    if (s .ne. ' 0') stop 13
    x = .true.
    read (s,'(B2)') x
    if (x .neqv. .false.) stop 14

    write (s,'(B2)') t
    if (s .ne. ' 1') stop 15
    x = .false.
    read (s,'(B2)') x
    if (x .neqv. .true.) stop 16

    write (s,'(B1)') f
    if (s .ne. '0') stop 17
    x = .true.
    read (s,'(B1)') x
    if (x .neqv. .false.) stop 18

    write (s,'(B1)') t
    if (s .ne. '1') stop 19
    x = .false.
    read (s,'(B1)') x
    if (x .neqv. .true.) stop 20

    write (s,'(2B1)') f, t
    if (s .ne. '01') stop 21
    x = .true.
    y = .false.
    read (s,'(2B1)') x, y
    if (x .neqv. .false.) stop 22
    if (y .neqv. .true.) stop 23

    write (s,'(2B1)') t, f
    if (s .ne. '10') stop 24
    x = .false.
    y = .true.
    read (s,'(2B1)') x, y
    if (x .neqv. .true.) stop 25
    if (y .neqv. .false.) stop 26

    write (s,'(2B2)') f, t
    if (s .ne. ' 0 1') stop 27
    x = .true.
    y = .false.
    read (s,'(2B2)') x, y
    if (x .neqv. .false.) stop 28
    if (y .neqv. .true.) stop 29

    write (s,'(2B2)') t, f
    if (s .ne. ' 1 0') stop 30
    x = .false.
    y = .true.
    read (s,'(2B2)') x, y
    if (x .neqv. .true.) stop 31
    if (y .neqv. .false.) stop 32

    write (s,'(3B1)') t, f, t
    if (s .ne. '101') stop 33
    x = .false.
    y = .true.
    z = .false.
    read (s,'(3B1)') x, y, z
    if (x .neqv. .true.) stop 34
    if (y .neqv. .false.) stop 35
    if (z .neqv. .true.) stop 36

    write (s,'(3B1)') f, t, f
    if (s .ne. '010') stop 37
    x = .true.
    y = .false.
    z = .true.
    read (s,'(3B1)') x, y, z
    if (x .neqv. .false.) stop 38
    if (y .neqv. .true.) stop 39
    if (z .neqv. .false.) stop 40

    write (s,'(3B2)') f, t, f
    if (s .ne. ' 0 1 0') stop 41
    x = .true.
    y = .false.
    z = .true.
    read (s,'(3B2)') x, y, z
    if (x .neqv. .false.) stop 42
    if (y .neqv. .true.) stop 43
    if (z .neqv. .false.) stop 44

    write (s,'(3B2)') t, f, t
    if (s .ne. ' 1 0 1') stop 45
    x = .false.
    y = .true.
    z = .false.
    read (s,'(3B2)') x, y, z
    if (x .neqv. .true.) stop 46
    if (y .neqv. .false.) stop 47
    if (z .neqv. .true.) stop 48

    s = '.0'
    read (s, '(B2)', iostat=ios) x
    if (ios .eq. 0) stop 49     ! '.' must be rejected for B
    s = '.T'
    read (s, '(B2)', iostat=ios) x
    if (ios .eq. 0) stop 50
    s = '.F'
    read (s, '(B2)', iostat=ios) x
    if (ios .eq. 0) stop 51
    s = 'X'
    read (s, '(B1)', iostat=ios) x
    if (ios .eq. 0) stop 52     ! invalid binary char must be rejected
    s = '2'
    read (s, '(B1)', iostat=ios) x
    if (ios .eq. 0) stop 53     ! '2' is not a binary digit
  end program fmt_b_1
