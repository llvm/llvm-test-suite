	%FILE = type { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint }
	%_Bool = type bool
	%__FILE = type { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint }
	%__builtin_ptrdiff_t = type int
	%__builtin_size_t = type uint
	%__builtin_va_list = type sbyte *
	%__g77_integer = type int
	%__g77_longint = type long
	%__g77_uinteger = type uint
	%__g77_ulongint = type ulong
	%__va_list = type sbyte *
	%_label_t = type { [2 x int] }
	%_once = type { [4 x ulong] }
	%_pthread_attr = type { sbyte * }
	%_pthread_cond = type { { [4 x ubyte], uint }, ulong }
	%_pthread_condattr = type { sbyte * }
	%_pthread_mutex = type { { ushort, ubyte, ubyte, uint }, { { [8 x ubyte] }, ulong }, ulong }
	%_pthread_mutexattr = type { sbyte * }
	%_pthread_rwlock = type { int, ushort, ushort, [3 x ulong], [2 x ulong], [2 x ulong] }
	%_pthread_rwlockattr = type { sbyte * }
	%_quad = type { [2 x int] }
	%blkcnt_t = type int
	%blksize_t = type int
	%bool = type short
	%boolean_t = type int
	%bufcall_id_t = type sbyte *
	%byte = type ubyte
	%caddr_t = type sbyte *
	%char = type sbyte
	%clock_t = type int
	%clockid_t = type int
	%cnt_t = type short
	%complex.double = type { double, double }
	%complex.float = type { float, float }
	%complex.int = type { int, int }
	%complex.long.double = type { double, double }
	%daddr_t = type int
	%dev_t = type uint
	%diskaddr_t = type long
	%double = type double
	%fd_mask = type int
	%fd_set = type { [32 x int] }
	%fds_mask = type int
	%float = type float
	%fpos_t = type int
	%fsblkcnt_t = type uint
	%fsfilcnt_t = type uint
	%gid_t = type int
	%hrtime_t = type long
	%id_t = type int
	%index_t = type short
	%ino_t = type uint
	%int = type int
	%int16_t = type short
	%int32_t = type int
	%int64_t = type long
	%int8_t = type sbyte
	%int_least16_t = type short
	%int_least32_t = type int
	%int_least8_t = type sbyte
	%intmax_t = type int
	%intptr_t = type int
	%iproc = type int (...) *
	%itimerval = type { { int, int }, { int, int } }
	%k_fltset_t = type uint
	%key_t = type int
	%label_t = type { [2 x int] }
	%len_t = type ulong
	%lldaddr_t = type { long, { int, int } }
	%lloff_t = type { long, { int, int } }
	%lock_t = type ubyte
	%long.double = type double
	%long.int = type int
	%long.long.int = type long
	%long.long.unsigned.int = type ulong
	%long.unsigned.int = type uint
	%longlong_t = type long
	%major_t = type uint
	%minor_t = type uint
	%mode_t = type uint
	%nlink_t = type uint
	%o_dev_t = type short
	%o_gid_t = type ushort
	%o_ino_t = type ushort
	%o_mode_t = type ushort
	%o_nlink_t = type short
	%o_pid_t = type short
	%o_uid_t = type ushort
	%off_t = type int
	%offset_t = type long
	%pad64_t = type long
	%pfn_t = type uint
	%pgcnt_t = type uint
	%pid_t = type int
	%pri_t = type short
	%proc = type void (...) *
	%projid_t = type int
	%pthread_attr_t = type { sbyte * }
	%pthread_cond_t = type { { [4 x ubyte], uint }, ulong }
	%pthread_condattr_t = type { sbyte * }
	%pthread_key_t = type uint
	%pthread_mutex_t = type { { ushort, ubyte, ubyte, uint }, { { [8 x ubyte] }, ulong }, ulong }
	%pthread_mutexattr_t = type { sbyte * }
	%pthread_once_t = type { [4 x ulong] }
	%pthread_rwlock_t = type { int, ushort, ushort, [3 x ulong], [2 x ulong], [2 x ulong] }
	%pthread_rwlockattr_t = type { sbyte * }
	%pthread_t = type uint
	%ptrdiff_t = type int
	%quad = type { [2 x int] }
	%quad_t = type { [2 x int] }
	%real = type double
	%realptr = type double *
	%rproc = type double (...) *
	%short.int = type short
	%short.unsigned.int = type ushort
	%signed.char = type sbyte
	%size_t = type uint
	%spgcnt_t = type int
	%ssize_t = type int
	%stream = type { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *
	%string = type sbyte *
	%suseconds_t = type int
	%sysid_t = type short
	%t_scalar_t = type int
	%t_uscalar_t = type uint
	%taskid_t = type int
	%time_t = type int
	%timeout_id_t = type sbyte *
	%timer_t = type int
	%timeval = type { int, int }
	%timezone = type { int, int }
	%tm = type { int, int, int, int, int, int, int, int, int }
	%tms = type { int, int, int, int }
	%u_char = type ubyte
	%u_int = type uint
	%u_long = type uint
	%u_longlong_t = type ulong
	%u_offset_t = type ulong
	%u_short = type ushort
	%uchar_t = type ubyte
	%uid_t = type int
	%uint = type uint
	%uint16_t = type ushort
	%uint32_t = type uint
	%uint64_t = type ulong
	%uint8_t = type ubyte
	%uint_least16_t = type ushort
	%uint_least32_t = type uint
	%uint_least8_t = type ubyte
	%uint_t = type uint
	%uintmax_t = type uint
	%uintptr_t = type uint
	%ulong = type uint
	%ulong_t = type uint
	%unchar = type ubyte
	%unsigned.char = type ubyte
	%unsigned.int = type uint
	%upad64_t = type ulong
	%use_t = type ubyte
	%useconds_t = type uint
	%ushort = type ushort
	%ushort_t = type ushort
	%void = type void
%__iob = uninitialized global [20 x %FILE]		; <[20 x %FILE] *>	[#uses=1]
%_sibuf = uninitialized global [ubyte]		; <[ubyte] *>	[#uses=0]
%_sobuf = uninitialized global [ubyte]		; <[ubyte] *>	[#uses=0]
%_bufendtab = uninitialized global [ubyte *]		; <[ubyte *] *>	[#uses=0]
%_lastbuf = uninitialized global %stream		; <%stream *>	[#uses=0]
%__intern_LC0 = global double 2147483647.000000		; <double *>	[#uses=0]
global double 2147483647.000000		; <double *>:0	[#uses=0]
%__intern_LC1 = global [21 x sbyte] c"times() call failed\0A\00"		; <[21 x sbyte] *>	[#uses=1]
%errno = uninitialized global int		; <int *>	[#uses=1]
%__intern_LC2 = global [6 x sbyte] c"Error\00"		; <[6 x sbyte] *>	[#uses=1]
implementation

declare void "__main"()

declare int "remove"(sbyte *)

declare int "rename"(sbyte *, sbyte *)

declare %stream "tmpfile"()

declare sbyte * "tmpnam"(sbyte *)

declare int "fclose"(%stream)

declare int "fflush"(%stream)

declare %stream "fopen"(sbyte *, sbyte *)

declare %stream "freopen"(sbyte *, sbyte *, %stream)

declare void "setbuf"(%stream, sbyte *)

declare int "setvbuf"(%stream, sbyte *, int, uint)

declare int "fprintf"(%stream, sbyte *, ...)

declare int "fscanf"(%stream, sbyte *, ...)

declare int "printf"(sbyte *, ...)

declare int "scanf"(sbyte *, ...)

declare int "sprintf"(sbyte *, sbyte *, ...)

declare int "sscanf"(sbyte *, sbyte *, ...)

declare int "vfprintf"(%stream, sbyte *, sbyte *)

declare int "vprintf"(sbyte *, sbyte *)

declare int "vsprintf"(sbyte *, sbyte *, sbyte *)

declare int "fgetc"(%stream)

declare sbyte * "fgets"(sbyte *, int, %stream)

declare int "fputc"(int, %stream)

declare int "fputs"(...)

declare int "getc"(%stream)

declare int "putc"(int, %stream)

declare int "getchar"()

declare int "putchar"(int)

declare sbyte * "gets"(sbyte *)

declare int "puts"(sbyte *)

declare int "ungetc"(int, %stream)

declare uint "fread"(sbyte *, uint, uint, %stream)

declare uint "fwrite"(sbyte *, uint, uint, %stream)

declare int "fgetpos"(%stream, int *)

declare int "fseek"(%stream, int, int)

declare int "fsetpos"(%stream, int *)

declare int "ftell"(%stream)

declare void "rewind"(%stream)

declare void "clearerr"(%stream)

declare int "feof"(%stream)

declare int "ferror"(%stream)

declare void "perror"(sbyte *)

declare int "__filbuf"(%stream)

declare int "__flsbuf"(int, %stream)

declare double "floor"(...)

declare int "__builtin_constant_p"(...)

declare sbyte * "__builtin_return_address"(uint)

declare sbyte * "__builtin_frame_address"(uint)

declare int "__builtin_eh_return_data_regno"(int)

declare sbyte * "alloca"(uint)

declare int "__builtin_ffs"(int)

declare int "ffs"(int)

declare void "_exit"(int)

declare void "_Exit"(int)

declare sbyte * "index"(sbyte *, int)

declare sbyte * "rindex"(sbyte *, int)

declare void "bzero"(sbyte *, uint)

declare void "bzero"(...)

declare int "bcmp"(sbyte *, sbyte *, uint)

declare int "bcmp"(...)

declare int "__builtin_abs"(int)

declare int "abs"(int)

declare float "__builtin_fabsf"(float)

declare float "fabsf"(float)

declare double "__builtin_fabs"(double)

declare double "fabs"(double)

declare double "__builtin_fabsl"(double)

declare double "fabsl"(double)

declare int "__builtin_labs"(int)

declare int "labs"(int)

declare long "__builtin_llabs"(long)

declare long "llabs"(long)

declare long "__builtin_imaxabs"(long)

declare long "imaxabs"(long)

declare sbyte * "__builtin_saveregs"(...)

declare int "__builtin_classify_type"(...)

declare sbyte * "__builtin_next_arg"(...)

declare int "__builtin_args_info"(int)

declare int "__builtin_setjmp"(sbyte *)

declare void "__builtin_longjmp"(sbyte *, int)

declare void "__builtin_trap"()

declare int "__builtin_isgreater"(...)

declare int "__builtin_isgreaterequal"(...)

declare int "__builtin_isless"(...)

declare int "__builtin_islessequal"(...)

declare int "__builtin_islessgreater"(...)

declare int "__builtin_isunordered"(...)

declare sbyte * "__builtin_apply_args"(...)

declare sbyte * "__builtin_apply"(%proc, sbyte *, uint)

declare void "__builtin_return"(sbyte *)

declare void "__builtin_varargs_start"(sbyte * *)

declare void "__builtin_stdarg_start"(sbyte * *, ...)

declare void "__builtin_va_end"(sbyte * *)

declare void "__builtin_va_copy"(sbyte * *, sbyte *)

declare int "__builtin_expect"(int, int)

declare sbyte * "memcpy"(sbyte *, sbyte *, uint)

declare int "memcmp"(sbyte *, sbyte *, uint)

declare sbyte * "memset"(sbyte *, int, uint)

declare int "strcmp"(sbyte *, sbyte *)

declare int "strncmp"(sbyte *, sbyte *, uint)

declare sbyte * "strstr"(sbyte *, sbyte *)

declare sbyte * "strpbrk"(sbyte *, sbyte *)

declare sbyte * "strchr"(sbyte *, int)

declare sbyte * "strrchr"(sbyte *, int)

declare sbyte * "strcpy"(sbyte *, sbyte *)

declare sbyte * "strncpy"(sbyte *, sbyte *, uint)

declare sbyte * "strcat"(sbyte *, sbyte *)

declare sbyte * "strncat"(sbyte *, sbyte *, uint)

declare uint "strspn"(sbyte *, sbyte *)

declare uint "strcspn"(sbyte *, sbyte *)

declare uint "strlen"(sbyte *)

declare float "sqrtf"(float)

declare double "sqrt"(double)

declare double "sqrtl"(double)

declare float "sinf"(float)

declare double "sin"(double)

declare double "sinl"(double)

declare float "cosf"(float)

declare double "cos"(double)

declare double "cosl"(double)

declare %complex.float * "__builtin_conjf"(%complex.float *, %complex.float *)

declare %complex.float * "conjf"(%complex.float *, %complex.float *)

declare %complex.double * "__builtin_conj"(%complex.double *, %complex.double *)

declare %complex.double * "conj"(%complex.double *, %complex.double *)

declare %complex.double * "__builtin_conjl"(%complex.double *, %complex.double *)

declare %complex.double * "conjl"(%complex.double *, %complex.double *)

declare float "__builtin_crealf"(%complex.float *)

declare float "crealf"(%complex.float *)

declare double "__builtin_creal"(%complex.double *)

declare double "creal"(%complex.double *)

declare double "__builtin_creall"(%complex.double *)

declare double "creall"(%complex.double *)

declare float "__builtin_cimagf"(%complex.float *)

declare float "cimagf"(%complex.float *)

declare double "__builtin_cimag"(%complex.double *)

declare double "cimag"(%complex.double *)

declare double "__builtin_cimagl"(%complex.double *)

declare double "cimagl"(%complex.double *)

declare int "fprintf"(sbyte *, sbyte *, ...)

declare uint "fwrite"(sbyte *, uint, uint, sbyte *)

declare int "fputc"(int, sbyte *)

declare int "fputs"(sbyte *, sbyte *)

declare void "abort"(...)

declare void "exit"(...)

declare sbyte * "__builtin_aggregate_incoming_address"(...)

declare void "__builtin_unwind_init"()

declare sbyte * "__builtin_dwarf_cfa"()

declare uint "__builtin_dwarf_fp_regnum"()

declare void "__builtin_init_dwarf_reg_size_table"(sbyte *)

declare sbyte * "__builtin_frob_return_addr"(sbyte *)

declare sbyte * "__builtin_extract_return_addr"(sbyte *)

declare void "__builtin_eh_return"(sbyte *, sbyte *)

double "my_rand"(double %seed)
begin
bb1:					;[#uses=0]
	%reg110 = mul double %seed, 16807.000000		; <double>	[#uses=1]
	%reg108 = add double %reg110, 1.000000		; <double>	[#uses=2]
	%reg113 = div double %reg108, 2147483647.000000		; <double>	[#uses=1]
	%reg114 = call %rproc %floor( double %reg113 )		; <double>	[#uses=1]
	%reg116 = mul double %reg114, 2147483647.000000		; <double>	[#uses=1]
	%reg118 = sub double %reg108, %reg116		; <double>	[#uses=1]
	ret double %reg118

bb2:					;[#uses=0]
	%cast1004 = cast ulong 42 to double		; <double>	[#uses=1]
	ret double %cast1004
end

double "xrand"(double %xl, double %xh, double %r)
begin
bb1:					;[#uses=0]
	%reg111 = sub double %xh, %xl		; <double>	[#uses=1]
	%reg112 = mul double %reg111, %r		; <double>	[#uses=1]
	%reg114 = div double %reg112, 2147483647.000000		; <double>	[#uses=1]
	%reg110 = add double %xl, %reg114		; <double>	[#uses=1]
	ret double %reg110

bb2:					;[#uses=0]
	%cast1017 = cast ulong 42 to double		; <double>	[#uses=1]
	ret double %cast1017
end

declare int "adjtime"(%complex.int *, %complex.int *)

declare int "getitimer"(int, %itimerval *)

declare int "utimes"(sbyte *, %complex.int *)

declare int "setitimer"(int, %itimerval *, %itimerval *)

declare int "settimeofday"(%complex.int *, sbyte *)

declare long "gethrtime"()

declare long "gethrvtime"()

declare int "gettimeofday"(%complex.int *, sbyte *)

declare sbyte * "asctime"(%tm *)

declare int "clock"()

declare sbyte * "ctime"(int *)

declare double "difftime"(int, int)

declare %tm * "gmtime"(int *)

declare %tm * "localtime"(int *)

declare int "mktime"(%tm *)

declare int "time"(int *)

declare uint "strftime"(sbyte *, uint, sbyte *, %tm *)

declare int "select"(int, %fd_set *, %fd_set *, %fd_set *, %complex.int *)

declare int "times"(%tms *)

declare int "error"(...)

declare double "cputime"(...)

int "error"(sbyte * %msg, sbyte * %a1, sbyte * %a2, sbyte * %a3, sbyte * %a4)
begin
bb1:					;[#uses=0]
	%cast1043 = cast ulong 64 to [20 x %FILE] *		; <[20 x %FILE] *>	[#uses=1]
	%reg112 = add [20 x %FILE] * %__iob, %cast1043		; <[20 x %FILE] *>	[#uses=1]
	%cast1044 = cast [20 x %FILE] * %reg112 to %stream		; <%stream>	[#uses=1]
	call int (%stream, sbyte *, ...) * %fprintf( %stream %cast1044, sbyte * %msg, sbyte * %a1, sbyte * %a2, sbyte * %a3, sbyte * %a4 )		; <int>:0	[#uses=0]
	%reg114 = load int * %errno		; <int>	[#uses=1]
	%cond1041 = seteq int %reg114, 0		; <bool>	[#uses=1]
	br bool %cond1041, label %bb3, label %bb2

bb2:					;[#uses=1]
	%cast1045 = cast [6 x sbyte] * %__intern_LC2 to sbyte *		; <sbyte *>	[#uses=1]
	call void (sbyte *) * %perror( sbyte * %cast1045 )
	br label %bb3

bb3:					;[#uses=2]
	%cast1042 = cast ulong 0 to uint		; <uint>	[#uses=1]
	call %proc %exit( uint %cast1042 )
	ret int 42
end

double "cputime"()
begin
bb0:					;[#uses=0]
	%buffer = alloca %tms		; <%tms *>	[#uses=2]
	br label %bb1

bb1:					;[#uses=1]
	%reg108 = call int (%tms *) * %times( %tms * %buffer )		; <int>	[#uses=1]
	%cond1026 = setne int %reg108, -1		; <bool>	[#uses=1]
	br bool %cond1026, label %bb3, label %bb2

bb2:					;[#uses=1]
	call %iproc %error( [21 x sbyte] * %__intern_LC1 )		; <int>:0	[#uses=0]
	br label %bb3

bb3:					;[#uses=2]
	%reg112 = load %tms * %buffer, ubyte 0		; <int>	[#uses=1]
	%cast1039 = cast int %reg112 to double		; <double>	[#uses=1]
	%reg110 = div double %cast1039, 3600.000000		; <double>	[#uses=1]
	ret double %reg110

bb4:					;[#uses=0]
	%cast1032 = cast ulong 42 to double		; <double>	[#uses=1]
	ret double %cast1032
end
