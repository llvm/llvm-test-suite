	%FILE = type { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint }
	%Hosp = type { int, int, int, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * } }
	%List = type { \2 *, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 * }
	%Patient = type { int, int, int, { [4 x \3], \2, { \2 *, \5 *, \2 * }, { int, int, int, { \2 *, \6 *, \2 * }, { \2 *, \6 *, \2 * }, { \2 *, \6 *, \2 * }, { \2 *, \6 *, \2 * } }, int, int } * }
	%Results = type { float, float, float }
	%Village = type { [4 x \3 *], \2 *, { \2 *, { int, int, int, \5 * } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 * } *, \2 * }, { \2 *, { int, int, int, \6 * } *, \2 * }, { \2 *, { int, int, int, \6 * } *, \2 * }, { \2 *, { int, int, int, \6 * } *, \2 * } }, int, int }
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
	%char = type sbyte
	%complex.double = type { double, double }
	%complex.float = type { float, float }
	%complex.int = type { int, int }
	%complex.long.double = type { double, double }
	%div_t = type { int, int }
	%double = type double
	%float = type float
	%fpos_t = type int
	%int = type int
	%ldiv_t = type { int, int }
	%long.double = type double
	%long.int = type int
	%long.long.int = type long
	%long.long.unsigned.int = type ulong
	%long.unsigned.int = type uint
	%short.int = type short
	%short.unsigned.int = type ushort
	%signed.char = type sbyte
	%size_t = type uint
	%ssize_t = type int
	%uid_t = type int
	%unsigned.char = type ubyte
	%unsigned.int = type uint
	%void = type void
	%wchar_t = type int
%__iob = uninitialized global [20 x { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint }]		; <[20 x { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint }] *>	[#uses=0]
%_sibuf = uninitialized global [ubyte]		; <[ubyte] *>	[#uses=0]
%_sobuf = uninitialized global [ubyte]		; <[ubyte] *>	[#uses=0]
%_bufendtab = uninitialized global [ubyte *]		; <[ubyte *] *>	[#uses=0]
%_lastbuf = uninitialized global { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *		; <{ int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } * *>	[#uses=0]
%__ctype = uninitialized global [ubyte]		; <[ubyte] *>	[#uses=0]
%max_level = uninitialized global int		; <int *>	[#uses=2]
%max_time = uninitialized global int		; <int *>	[#uses=2]
%seed = uninitialized global int		; <int *>	[#uses=1]
%__intern_LC0 = global [40 x sbyte] c"usage:  health <# levels> <time> <seed>\00"		; <[40 x sbyte] *>	[#uses=1]
%__intern_LC1 = global [39 x sbyte] c"max_level=%d  max_time=%ld  seed=%ld \0A\00"		; <[39 x sbyte] *>	[#uses=1]
implementation

declare void "__main"()

declare int "remove"(sbyte *)

declare int "rename"(sbyte *, sbyte *)

declare { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } * "tmpfile"()

declare sbyte * "tmpnam"(sbyte *)

declare int "fclose"({ int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *)

declare int "fflush"({ int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *)

declare { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } * "fopen"(sbyte *, sbyte *)

declare { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } * "freopen"(sbyte *, sbyte *, { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *)

declare void "setbuf"({ int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *, sbyte *)

declare int "setvbuf"({ int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *, sbyte *, int, uint)

declare int "fprintf"({ int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *, sbyte *, ...)

declare int "fscanf"({ int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *, sbyte *, ...)

declare int "printf"(sbyte *, ...)

declare int "scanf"(sbyte *, ...)

declare int "sprintf"(sbyte *, sbyte *, ...)

declare int "sscanf"(sbyte *, sbyte *, ...)

declare int "vfprintf"({ int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *, sbyte *, sbyte *)

declare int "vprintf"(sbyte *, sbyte *)

declare int "vsprintf"(sbyte *, sbyte *, sbyte *)

declare int "fgetc"({ int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *)

declare sbyte * "fgets"(sbyte *, int, { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *)

declare int "fputc"(int, { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *)

declare int "fputs"(...)

declare int "getc"({ int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *)

declare int "putc"(int, { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *)

declare int "getchar"()

declare int "putchar"(int)

declare sbyte * "gets"(sbyte *)

declare int "puts"(sbyte *)

declare int "ungetc"(int, { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *)

declare uint "fread"(sbyte *, uint, uint, { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *)

declare uint "fwrite"(sbyte *, uint, uint, { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *)

declare int "fgetpos"({ int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *, int *)

declare int "fseek"({ int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *, int, int)

declare int "fsetpos"({ int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *, int *)

declare int "ftell"({ int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *)

declare void "rewind"({ int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *)

declare void "clearerr"({ int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *)

declare int "feof"({ int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *)

declare int "ferror"({ int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *)

declare void "perror"(sbyte *)

declare int "__filbuf"({ int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *)

declare int "__flsbuf"(int, { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *)

declare void "abort"()

declare int "abs"(int)

declare int "atexit"(void () *)

declare double "atof"(sbyte *)

declare int "atoi"(sbyte *)

declare int "atol"(sbyte *)

declare sbyte * "bsearch"(sbyte *, sbyte *, uint, uint, int (sbyte *, sbyte *) *)

declare sbyte * "calloc"(uint, uint)

declare { int, int } * "div"({ int, int } *, int, int)

declare void "exit"(int)

declare void "free"(sbyte *)

declare sbyte * "getenv"(sbyte *)

declare int "labs"(int)

declare { int, int } * "ldiv"({ int, int } *, int, int)

declare sbyte * "malloc"(uint)

declare int "mblen"(sbyte *, uint)

declare uint "mbstowcs"(int *, sbyte *, uint)

declare int "mbtowc"(int *, sbyte *, uint)

declare void "qsort"(sbyte *, uint, uint, int (sbyte *, sbyte *) *)

declare int "rand"()

declare sbyte * "realloc"(sbyte *, uint)

declare void "srand"(uint)

declare double "strtod"(sbyte *, sbyte * *)

declare int "strtol"(sbyte *, sbyte * *, int)

declare uint "strtoul"(sbyte *, sbyte * *, int)

declare int "system"(sbyte *)

declare int "wctomb"(sbyte *, int)

declare uint "wcstombs"(sbyte *, int *, uint)

declare void "_exithandle"()

declare int "mkstemp"(sbyte *)

int "dealwithargs"(int %argc, sbyte * * %argv)
begin
bb1:					;[#uses=0]
	%cond1000 = setgt int %argc, 3		; <bool>	[#uses=1]
	br bool %cond1000, label %bb3, label %bb2

bb2:					;[#uses=1]
	%cast1005 = cast [40 x sbyte] * %__intern_LC0 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *) * %puts( sbyte * %cast1005 )		; <int>:0	[#uses=0]
	%cast1001 = cast ulong 1 to int		; <int>	[#uses=1]
	call void (int) * %exit( int %cast1001 )
	br label %bb3

bb3:					;[#uses=2]
	%cast1006 = cast ulong 8 to sbyte * *		; <sbyte * *>	[#uses=1]
	%reg1002 = add sbyte * * %argv, %cast1006		; <sbyte * *>	[#uses=1]
	%reg111 = load sbyte * * %reg1002		; <sbyte *>	[#uses=1]
	%reg112 = call int (sbyte *) * %atoi( sbyte * %reg111 )		; <int>	[#uses=1]
	store int %reg112, int * %max_level
	%cast1007 = cast ulong 16 to sbyte * *		; <sbyte * *>	[#uses=1]
	%reg1003 = add sbyte * * %argv, %cast1007		; <sbyte * *>	[#uses=1]
	%reg113 = load sbyte * * %reg1003		; <sbyte *>	[#uses=1]
	%reg114 = call int (sbyte *) * %atol( sbyte * %reg113 )		; <int>	[#uses=1]
	store int %reg114, int * %max_time
	%cast1008 = cast ulong 24 to sbyte * *		; <sbyte * *>	[#uses=1]
	%reg1004 = add sbyte * * %argv, %cast1008		; <sbyte * *>	[#uses=1]
	%reg115 = load sbyte * * %reg1004		; <sbyte *>	[#uses=1]
	%reg116 = call int (sbyte *) * %atol( sbyte * %reg115 )		; <int>	[#uses=2]
	store int %reg116, int * %seed
	%reg118 = load int * %max_level		; <int>	[#uses=1]
	%reg119 = load int * %max_time		; <int>	[#uses=1]
	%cast1009 = cast [39 x sbyte] * %__intern_LC1 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast1009, int %reg118, int %reg119, int %reg116 )		; <int>:1	[#uses=0]
	ret int 42
end

declare float "my_rand"(int)

declare { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * "generate_patient"({ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *)

declare void "put_in_hosp"({ int, int, int, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * } } *, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } *)

declare void "addList"({ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } *)

declare void "removeList"({ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } *)

declare { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * "sim"({ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *)

declare void "check_patients_inside"({ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *, { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *)

declare { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * "check_patients_assess"({ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *, { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *)

declare void "check_patients_waiting"({ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *, { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *)

declare float "get_num_people"({ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *)

declare float "get_total_time"({ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *)

declare float "get_total_hosps"({ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *)

declare { float, float, float } * "get_results"({ float, float, float } *, { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *)

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

declare float "__builtin_fabsf"(float)

declare float "fabsf"(float)

declare double "__builtin_fabs"(double)

declare double "fabs"(double)

declare double "__builtin_fabsl"(double)

declare double "fabsl"(double)

declare int "__builtin_labs"(int)

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

declare sbyte * "__builtin_apply"(void (...) *, sbyte *, uint)

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

declare { float, float } * "__builtin_conjf"({ float, float } *, { float, float } *)

declare { float, float } * "conjf"({ float, float } *, { float, float } *)

declare { double, double } * "__builtin_conj"({ double, double } *, { double, double } *)

declare { double, double } * "conj"({ double, double } *, { double, double } *)

declare { double, double } * "__builtin_conjl"({ double, double } *, { double, double } *)

declare { double, double } * "conjl"({ double, double } *, { double, double } *)

declare float "__builtin_crealf"({ float, float } *)

declare float "crealf"({ float, float } *)

declare double "__builtin_creal"({ double, double } *)

declare double "creal"({ double, double } *)

declare double "__builtin_creall"({ double, double } *)

declare double "creall"({ double, double } *)

declare float "__builtin_cimagf"({ float, float } *)

declare float "cimagf"({ float, float } *)

declare double "__builtin_cimag"({ double, double } *)

declare double "cimag"({ double, double } *)

declare double "__builtin_cimagl"({ double, double } *)

declare double "cimagl"({ double, double } *)

declare int "fprintf"(sbyte *, sbyte *, ...)

declare uint "fwrite"(sbyte *, uint, uint, sbyte *)

declare int "fputc"(int, sbyte *)

declare int "fputs"(sbyte *, sbyte *)

declare sbyte * "__builtin_aggregate_incoming_address"(...)

declare void "__builtin_unwind_init"()

declare sbyte * "__builtin_dwarf_cfa"()

declare uint "__builtin_dwarf_fp_regnum"()

declare void "__builtin_init_dwarf_reg_size_table"(sbyte *)

declare sbyte * "__builtin_frob_return_addr"(sbyte *)

declare sbyte * "__builtin_extract_return_addr"(sbyte *)

declare void "__builtin_eh_return"(sbyte *, sbyte *)
