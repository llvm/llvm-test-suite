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
	%_h_val = type { [2 x uint], double }
	%char = type sbyte
	%complex.double = type { double, double }
	%complex.float = type { float, float }
	%complex.int = type { int, int }
	%complex.long.double = type { double, double }
	%div_t = type { int, int }
	%double = type double
	%fc_pointer = type { uint * }
	%fc_results = type { { float, float, float } }
	%float = type float
	%fpos_t = type int
	%future_cell_pointer = type { uint * }
	%future_cell_results = type { { float, float, float } }
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
	%word_t = type uint
%__iob = uninitialized global [20 x { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint }]		; <[20 x { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint }] *>	[#uses=0]
%_sibuf = uninitialized global [ubyte]		; <[ubyte] *>	[#uses=0]
%_sobuf = uninitialized global [ubyte]		; <[ubyte] *>	[#uses=0]
%_bufendtab = uninitialized global [ubyte *]		; <[ubyte *] *>	[#uses=0]
%_lastbuf = uninitialized global { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *		; <{ int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } * *>	[#uses=0]
%__ctype = uninitialized global [ubyte]		; <[ubyte] *>	[#uses=0]
%__huge_val = uninitialized global { [2 x uint], double }		; <{ [2 x uint], double } *>	[#uses=0]
%max_level = uninitialized global int		; <int *>	[#uses=1]
%max_time = uninitialized global int		; <int *>	[#uses=2]
%seed = uninitialized global int		; <int *>	[#uses=1]
%__intern_LC0 = global float 2147483648.000000		; <float *>	[#uses=0]
global float 2147483648.000000		; <float *>:0	[#uses=0]
%__intern_LC1 = global double 0.100000		; <double *>	[#uses=0]
global double 0.100000		; <double *>:0	[#uses=0]
%__intern_LC2 = global [39 x sbyte] c"\0A\0A    Columbian Health Care Simulator\0A\00"		; <[39 x sbyte] *>	[#uses=1]
%__intern_LC3 = global [11 x sbyte] c"Working...\00"		; <[11 x sbyte] *>	[#uses=1]
%__intern_LC4 = global [4 x sbyte] c"%d\0A\00"		; <[4 x sbyte] *>	[#uses=1]
%__intern_LC5 = global [7 x sbyte] c"Done.\0A\00"		; <[7 x sbyte] *>	[#uses=1]
%__intern_LC6 = global [45 x sbyte] c"# of people treated:              %f people\0A\00"		; <[45 x sbyte] *>	[#uses=1]
%__intern_LC7 = global [49 x sbyte] c"Average length of stay:           %f time units\0A\00"		; <[49 x sbyte] *>	[#uses=1]
%__intern_LC8 = global [49 x sbyte] c"Average # of hospitals visited:   %f hospitals\0A\0A\00"		; <[49 x sbyte] *>	[#uses=1]
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

declare double "acos"(double)

declare double "asin"(double)

declare double "atan"(double)

declare double "atan2"(double, double)

declare double "cos"(double)

declare double "sin"(double)

declare double "tan"(double)

declare double "cosh"(double)

declare double "sinh"(double)

declare double "tanh"(double)

declare double "exp"(double)

declare double "frexp"(double, int *)

declare double "ldexp"(double, int)

declare double "log"(double)

declare double "log10"(double)

declare double "modf"(double, double *)

declare double "pow"(double, double)

declare double "sqrt"(double)

declare double "ceil"(double)

declare double "fabs"(double)

declare double "floor"(double)

declare double "fmod"(double, double)

declare int "dealwithargs"(int, sbyte * *)

declare float "my_rand"(int)

{ int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * "generate_patient"({ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village)
begin
bb1:					;[#uses=0]
	%reg108 = load { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, ubyte 5		; <int>	[#uses=1]
	%reg111 = call float (int) * %my_rand( int %reg108 )		; <float>	[#uses=2]
	%reg114 = mul float %reg111, 2147483648.000000		; <float>	[#uses=1]
	%cast1414 = cast float %reg114 to int		; <int>	[#uses=1]
	store int %cast1414, { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, ubyte 5
	%cast1400 = cast float %reg111 to long		; <long>	[#uses=1]
	%cast1401 = cast double 0.666000 to long		; <long>	[#uses=1]
	%cond1390 = setgt long %cast1400, %cast1401		; <bool>	[#uses=1]
	br bool %cond1390, label %bb2, label %bb3

bb2:					;[#uses=1]
	%cast1391 = cast ulong 24 to uint		; <uint>	[#uses=1]
	%reg119 = call sbyte * (uint) * %malloc( uint %cast1391 )		; <sbyte *>	[#uses=5]
	%cast1402 = cast sbyte * %reg119 to uint *		; <uint *>	[#uses=1]
	store uint 0, uint * %cast1402
	%cast1403 = cast ulong 4 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1392 = add sbyte * %reg119, %cast1403		; <sbyte *>	[#uses=1]
	%cast1404 = cast sbyte * %reg1392 to uint *		; <uint *>	[#uses=1]
	store uint 0, uint * %cast1404
	%cast1405 = cast ulong 8 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1393 = add sbyte * %reg119, %cast1405		; <sbyte *>	[#uses=1]
	%cast1406 = cast sbyte * %reg1393 to uint *		; <uint *>	[#uses=1]
	store uint 0, uint * %cast1406
	%cast1407 = cast ulong 16 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1394 = add sbyte * %reg119, %cast1407		; <sbyte *>	[#uses=1]
	%cast1408 = cast sbyte * %reg1394 to { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * *		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * *>	[#uses=1]
	store { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * * %cast1408
	%cast1409 = cast sbyte * %reg119 to { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } *		; <{ int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } *>	[#uses=1]
	ret { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %cast1409

bb3:					;[#uses=1]
	ret { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * null

bb4:					;[#uses=0]
	%cast1411 = cast ulong 42 to { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } *		; <{ int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } *>	[#uses=1]
	ret { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %cast1411
end

void "put_in_hosp"({ int, int, int, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * } } * %hosp, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %patient)
begin
bb1:					;[#uses=0]
	%reg110 = load { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %patient, ubyte 0		; <int>	[#uses=1]
	%cast110 = cast int %reg110 to uint		; <uint>	[#uses=1]
	%reg111 = add uint %cast110, 1		; <uint>	[#uses=1]
	%cast1364 = cast { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %patient to uint *		; <uint *>	[#uses=1]
	store uint %reg111, uint * %cast1364
	%reg112 = load { int, int, int, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * } } * %hosp, ubyte 1		; <int>	[#uses=2]
	%cond1358 = setle int %reg112, 0		; <bool>	[#uses=1]
	br bool %cond1358, label %bb3, label %bb2

bb2:					;[#uses=1]
	%reg113 = add int %reg112, -1		; <int>	[#uses=1]
	store int %reg113, { int, int, int, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * } } * %hosp, ubyte 1
	%eptr1370 = getelementptr { int, int, int, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * } } * %hosp, ubyte 4		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>	[#uses=1]
	call void ({ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } *) * %addList( { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %eptr1370, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %patient )
	store int 3, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %patient, ubyte 2
	%reg116 = load { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %patient, ubyte 1		; <int>	[#uses=1]
	%cast116 = cast int %reg116 to uint		; <uint>	[#uses=1]
	%reg115 = add uint %cast116, 3		; <uint>	[#uses=1]
	%eptr1386 = getelementptr { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %patient, ubyte 1		; <int *>	[#uses=1]
	%cast1376 = cast int * %eptr1386 to uint *		; <uint *>	[#uses=1]
	store uint %reg115, uint * %cast1376
	br label %bb4

bb3:					;[#uses=1]
	%eptr1378 = getelementptr { int, int, int, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * } } * %hosp, ubyte 3		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>	[#uses=1]
	call void ({ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } *) * %addList( { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %eptr1378, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %patient )
	br label %bb4

bb4:					;[#uses=2]
	ret void
end

declare void "addList"({ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } *)

declare void "removeList"({ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } *)

{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * "sim"({ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village)
begin
bb0:					;[#uses=0]
	%val = alloca [4 x { uint * }]		; <[4 x { uint * }] *>	[#uses=2]
	%cast1500 = cast [4 x { uint * }] * %val to { uint * } *		; <{ uint * } *>	[#uses=3]
	br label %bb1

bb1:					;[#uses=1]
	%cond1501 = setne { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, null		; <bool>	[#uses=1]
	br bool %cond1501, label %bb3, label %bb2

bb2:					;[#uses=1]
	ret { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * null

bb3:					;[#uses=2]
	%cond1502 = setle long 3, 0		; <bool>	[#uses=1]
	br bool %cond1502, label %bb5, label %bb4

bb4:					;[#uses=3]
	%reg149 = phi int [ %reg150, %bb4 ], [ 3, %bb3 ]		; <int>	[#uses=2]
	%cast1517 = cast int %reg149 to uint		; <uint>	[#uses=1]
	%reg119 = shl uint %cast1517, ubyte 3		; <uint>	[#uses=2]
	%cast120 = cast uint %reg119 to { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *>	[#uses=1]
	%reg122 = add { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, %cast120		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *>	[#uses=1]
	%cast1518 = cast { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %reg122 to { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * *		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * *>	[#uses=1]
	%reg113 = load { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * * %cast1518		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *>	[#uses=1]
	%cast1545 = cast uint %reg119 to { uint * } *		; <{ uint * } *>	[#uses=1]
	%reg129 = add { uint * } * %cast1500, %cast1545		; <{ uint * } *>	[#uses=1]
	%cast1519 = cast { uint * } * %reg129 to { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * *		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * *>	[#uses=1]
	%reg130 = call { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * ({ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *) * %sim( { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %reg113 )		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>	[#uses=1]
	store { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %reg130, { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * * %cast1519
	%reg150 = add int %reg149, -1		; <int>	[#uses=2]
	%cond1503 = setgt int %reg150, 0		; <bool>	[#uses=1]
	br bool %cond1503, label %bb4, label %bb5

bb5:					;[#uses=3]
	%cast1521 = cast { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village to { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * *		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * *>	[#uses=1]
	%reg151 = load { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * * %cast1521		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *>	[#uses=1]
	%reg131 = call { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * ({ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *) * %sim( { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %reg151 )		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>	[#uses=1]
	%cast1504 = cast [4 x { uint * }] * %val to { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * *		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * *>	[#uses=1]
	store { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %reg131, { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * * %cast1504
	%eptr1529 = getelementptr { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, ubyte 3		; <{ int, int, int, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * } } *>	[#uses=1]
	%cond1505 = setlt long 3, 0		; <bool>	[#uses=1]
	br bool %cond1505, label %bb10, label %bb6

bb6:					;[#uses=2]
	%reg153 = phi int [ %reg157, %bb9 ], [ 3, %bb5 ]		; <int>	[#uses=3]
	%cast1531 = cast int %reg153 to uint		; <uint>	[#uses=1]
	%cast1523 = cast int %reg153 to uint		; <uint>	[#uses=1]
	%reg133 = shl uint %cast1523, ubyte 3		; <uint>	[#uses=1]
	%cast134 = cast uint %reg133 to { uint * } *		; <{ uint * } *>	[#uses=1]
	%reg138 = add { uint * } * %cast1500, %cast134		; <{ uint * } *>	[#uses=1]
	%reg111 = load { uint * } * %reg138, ubyte 0		; <uint *>	[#uses=1]
	%cast111 = cast uint * %reg111 to ulong * *		; <ulong * *>	[#uses=2]
	%cond1506 = seteq ulong * * %cast111, null		; <bool>	[#uses=1]
	br bool %cond1506, label %bb9, label %bb7

bb7:					;[#uses=2]
	%reg154 = load ulong * * %cast111		; <ulong *>	[#uses=2]
	%cond1507 = seteq ulong * %reg154, null		; <bool>	[#uses=1]
	br bool %cond1507, label %bb9, label %bb8

bb8:					;[#uses=3]
	%reg155 = phi ulong * [ %reg156, %bb8 ], [ %reg154, %bb7 ]		; <ulong *>	[#uses=2]
	%cast1530 = cast ulong * %reg155 to ulong * *		; <ulong * *>	[#uses=1]
	%cast1528 = cast ulong * %reg155 to { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * *		; <{ int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * *>	[#uses=1]
	%cast1527 = cast ulong 8 to { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * *		; <{ int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * *>	[#uses=1]
	%reg1508 = add { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * * %cast1528, %cast1527		; <{ int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * *>	[#uses=1]
	%reg110 = load { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * * %reg1508		; <{ int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } *>	[#uses=2]
	call void ({ int, int, int, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * } } *, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } *) * %put_in_hosp( { int, int, int, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * } } * %eptr1529, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %reg110 )
	%reg156 = load ulong * * %cast1530		; <ulong *>	[#uses=2]
	%reg140 = shl uint %cast1531, ubyte 3		; <uint>	[#uses=1]
	%cast141 = cast uint %reg140 to { uint * } *		; <{ uint * } *>	[#uses=1]
	%reg145 = add { uint * } * %cast1500, %cast141		; <{ uint * } *>	[#uses=1]
	%reg146 = load { uint * } * %reg145, ubyte 0		; <uint *>	[#uses=1]
	%cast146 = cast uint * %reg146 to { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>	[#uses=1]
	call void ({ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } *) * %removeList( { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %cast146, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %reg110 )
	%cond1509 = setne ulong * %reg156, null		; <bool>	[#uses=1]
	br bool %cond1509, label %bb8, label %bb9

bb9:					;[#uses=4]
	%reg157 = add int %reg153, -1		; <int>	[#uses=2]
	%cond1510 = setge int %reg157, 0		; <bool>	[#uses=1]
	br bool %cond1510, label %bb6, label %bb10

bb10:					;[#uses=2]
	%reg158 = load { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, ubyte 3, ubyte 5, ubyte 0		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>	[#uses=1]
	call void ({ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *, { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *) * %check_patients_inside( { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %reg158 )
	%reg159 = load { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, ubyte 3, ubyte 4, ubyte 0		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>	[#uses=1]
	%reg112 = call { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * ({ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *, { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *) * %check_patients_assess( { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %reg159 )		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>	[#uses=1]
	%reg160 = load { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, ubyte 3, ubyte 3, ubyte 0		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>	[#uses=1]
	call void ({ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *, { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *) * %check_patients_waiting( { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %reg160 )
	%reg109 = call { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * ({ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *) * %generate_patient( { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village )		; <{ int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } *>	[#uses=2]
	%cond1514 = seteq { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %reg109, null		; <bool>	[#uses=1]
	br bool %cond1514, label %bb12, label %bb11

bb11:					;[#uses=1]
	%eptr1543 = getelementptr { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, ubyte 3		; <{ int, int, int, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * } } *>	[#uses=1]
	call void ({ int, int, int, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * } } *, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } *) * %put_in_hosp( { int, int, int, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * }, { \2 *, { int, int, int, { [4 x \3], \2, \5, \6, int, int } * } *, \2 * } } * %eptr1543, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %reg109 )
	br label %bb12

bb12:					;[#uses=2]
	ret { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %reg112

bb13:					;[#uses=0]
	%cast1544 = cast ulong 42 to { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>	[#uses=1]
	ret { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %cast1544
end

void "check_patients_inside"({ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %list)
begin
bb1:					;[#uses=1]
	%cond1210 = seteq { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %list, null		; <bool>	[#uses=1]
	br bool %cond1210, label %bb5, label %bb2

bb2:					;[#uses=2]
	%reg116 = phi { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * [ %reg119, %bb4 ], [ %list, %bb1 ]		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>	[#uses=2]
	%reg110 = load { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %reg116, ubyte 1		; <{ int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } *>	[#uses=4]
	%reg112 = load { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %reg110, ubyte 2		; <int>	[#uses=1]
	%reg113 = add int %reg112, -1		; <int>	[#uses=2]
	store int %reg113, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %reg110, ubyte 2
	%cond1214 = setne int %reg113, 0		; <bool>	[#uses=1]
	br bool %cond1214, label %bb4, label %bb3

bb3:					;[#uses=1]
	%reg117 = load { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, ubyte 3, ubyte 1		; <int>	[#uses=1]
	%cast117 = cast int %reg117 to uint		; <uint>	[#uses=1]
	%reg115 = add uint %cast117, 1		; <uint>	[#uses=1]
	%eptr1239 = getelementptr { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, ubyte 3, ubyte 1		; <int *>	[#uses=1]
	%cast1226 = cast int * %eptr1239 to uint *		; <uint *>	[#uses=1]
	store uint %reg115, uint * %cast1226
	%eptr1228 = getelementptr { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, ubyte 3, ubyte 5		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>	[#uses=1]
	call void ({ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } *) * %removeList( { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %eptr1228, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %reg110 )
	%eptr1231 = getelementptr { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, ubyte 2		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>	[#uses=1]
	call void ({ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } *) * %addList( { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %eptr1231, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %reg110 )
	br label %bb4

bb4:					;[#uses=3]
	%reg119 = load { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %reg116, ubyte 0		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>	[#uses=2]
	%cond1217 = setne { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %reg119, null		; <bool>	[#uses=1]
	br bool %cond1217, label %bb2, label %bb5

bb5:					;[#uses=2]
	ret void
end

{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * "check_patients_assess"({ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %list)
begin
bb1:					;[#uses=3]
	%cond1242 = seteq { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %list, null		; <bool>	[#uses=1]
	br bool %cond1242, label %bb8, label %bb2

bb2:					;[#uses=3]
	%reg130 = phi { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * [ %reg137, %bb7 ], [ null, %bb1 ]		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *>	[#uses=2]
	%reg131 = phi { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * [ %reg138, %bb7 ], [ %list, %bb1 ]		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>	[#uses=2]
	%reg110 = load { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %reg131, ubyte 1		; <{ int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } *>	[#uses=9]
	%reg116 = load { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %reg110, ubyte 2		; <int>	[#uses=1]
	%reg119 = add int %reg116, -1		; <int>	[#uses=2]
	store int %reg119, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %reg110, ubyte 2
	%cond1246 = setne int %reg119, 0		; <bool>	[#uses=1]
	br bool %cond1246, label %bb7, label %bb3

bb3:					;[#uses=1]
	%reg114 = load { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, ubyte 5		; <int>	[#uses=1]
	%reg109 = call float (int) * %my_rand( int %reg114 )		; <float>	[#uses=2]
	%reg122 = mul float %reg109, 2147483648.000000		; <float>	[#uses=1]
	%cast1305 = cast float %reg122 to int		; <int>	[#uses=1]
	store int %cast1305, { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, ubyte 5
	%reg115 = load { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, ubyte 4		; <int>	[#uses=1]
	%cast115 = cast int %reg115 to uint		; <uint>	[#uses=1]
	%cast1272 = cast float %reg109 to long		; <long>	[#uses=1]
	%cast1273 = cast double 0.100000 to long		; <long>	[#uses=1]
	%cond1250 = setgt long %cast1272, %cast1273		; <bool>	[#uses=1]
	br bool %cond1250, label %bb5, label %bb4

bb4:					;[#uses=1]
	%cond1251 = setne uint %cast115, 0		; <bool>	[#uses=1]
	br bool %cond1251, label %bb6, label %bb5

bb5:					;[#uses=3]
	%eptr1275 = getelementptr { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, ubyte 3, ubyte 4		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>	[#uses=1]
	call void ({ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } *) * %removeList( { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %eptr1275, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %reg110 )
	%eptr1278 = getelementptr { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, ubyte 3, ubyte 5		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>	[#uses=1]
	call void ({ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } *) * %addList( { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %eptr1278, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %reg110 )
	store int 10, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %reg110, ubyte 2
	%reg136 = load { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %reg110, ubyte 1		; <int>	[#uses=1]
	%reg127 = add int %reg136, 10		; <int>	[#uses=1]
	store int %reg127, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %reg110, ubyte 1
	br label %bb7

bb6:					;[#uses=2]
	%reg132 = load { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, ubyte 3, ubyte 1		; <int>	[#uses=1]
	%cast132 = cast int %reg132 to uint		; <uint>	[#uses=1]
	%reg128 = add uint %cast132, 1		; <uint>	[#uses=1]
	%eptr1313 = getelementptr { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, ubyte 3, ubyte 1		; <int *>	[#uses=1]
	%cast1286 = cast int * %eptr1313 to uint *		; <uint *>	[#uses=1]
	store uint %reg128, uint * %cast1286
	%eptr1289 = getelementptr { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, ubyte 3, ubyte 4		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>	[#uses=1]
	%cast1288 = cast ulong 152 to { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *>	[#uses=0]
	%eptr1315 = getelementptr { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, ubyte 3, ubyte 6, ubyte 0		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * *>	[#uses=1]
	%cast133 = cast { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * * %eptr1315 to { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *>	[#uses=1]
	%eptr1291 = getelementptr { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, ubyte 3, ubyte 6		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>	[#uses=1]
	call void ({ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } *) * %removeList( { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %eptr1289, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %reg110 )
	call void ({ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } *) * %addList( { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %eptr1291, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %reg110 )
	br label %bb7

bb7:					;[#uses=6]
	%reg137 = phi { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * [ %cast133, %bb6 ], [ %reg130, %bb5 ], [ %reg130, %bb2 ]		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *>	[#uses=2]
	%reg138 = load { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %reg131, ubyte 0		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>	[#uses=2]
	%cond1257 = setne { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %reg138, null		; <bool>	[#uses=1]
	br bool %cond1257, label %bb2, label %bb8

bb8:					;[#uses=2]
	%reg139 = phi { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * [ %reg137, %bb7 ], [ null, %bb1 ]		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *>	[#uses=1]
	%cast1295 = cast { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %reg139 to { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>	[#uses=1]
	ret { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %cast1295

bb9:					;[#uses=0]
	%cast1296 = cast ulong 42 to { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>	[#uses=1]
	ret { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %cast1296
end

void "check_patients_waiting"({ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %list)
begin
bb1:					;[#uses=1]
	%cond1316 = seteq { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %list, null		; <bool>	[#uses=1]
	br bool %cond1316, label %bb6, label %bb2

bb2:					;[#uses=2]
	%reg117 = phi { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * [ %reg121, %bb5 ], [ %list, %bb1 ]		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>	[#uses=2]
	%reg109 = load { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, ubyte 3, ubyte 1		; <int>	[#uses=2]
	%reg112 = load { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %reg117, ubyte 1		; <{ int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } *>	[#uses=7]
	%cond1319 = setle int %reg109, 0		; <bool>	[#uses=1]
	br bool %cond1319, label %bb4, label %bb3

bb3:					;[#uses=1]
	%reg113 = add int %reg109, -1		; <int>	[#uses=1]
	store int %reg113, { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, ubyte 3, ubyte 1
	store int 3, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %reg112, ubyte 2
	%reg118 = load { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %reg112, ubyte 1		; <int>	[#uses=1]
	%cast118 = cast int %reg118 to uint		; <uint>	[#uses=1]
	%reg115 = add uint %cast118, 3		; <uint>	[#uses=1]
	%cast1336 = cast ulong 4 to uint *		; <uint *>	[#uses=0]
	%eptr1352 = getelementptr { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %reg112, ubyte 1		; <int *>	[#uses=1]
	%cast1323 = cast int * %eptr1352 to uint *		; <uint *>	[#uses=1]
	store uint %reg115, uint * %cast1323
	%eptr1338 = getelementptr { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, ubyte 3, ubyte 3		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>	[#uses=1]
	call void ({ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } *) * %removeList( { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %eptr1338, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %reg112 )
	%eptr1341 = getelementptr { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, ubyte 3, ubyte 4		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>	[#uses=1]
	call void ({ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } *) * %addList( { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %eptr1341, { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %reg112 )
	br label %bb5

bb4:					;[#uses=1]
	%reg120 = load { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %reg112, ubyte 1		; <int>	[#uses=1]
	%cast120 = cast int %reg120 to uint		; <uint>	[#uses=1]
	%reg116 = add uint %cast120, 1		; <uint>	[#uses=1]
	%cast1344 = cast ulong 4 to uint *		; <uint *>	[#uses=0]
	%eptr1356 = getelementptr { int, int, int, { [4 x \3], \2, { \2 *, \5, \2 * }, { int, int, int, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * }, { \2 *, \6, \2 * } }, int, int } * } * %reg112, ubyte 1		; <int *>	[#uses=1]
	%cast1325 = cast int * %eptr1356 to uint *		; <uint *>	[#uses=1]
	store uint %reg116, uint * %cast1325
	br label %bb5

bb5:					;[#uses=3]
	%reg121 = load { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %reg117, ubyte 0		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>	[#uses=2]
	%cond1326 = setne { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %reg121, null		; <bool>	[#uses=1]
	br bool %cond1326, label %bb2, label %bb6

bb6:					;[#uses=2]
	ret void
end

declare float "get_num_people"({ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *)

declare float "get_total_time"({ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *)

declare float "get_total_hosps"({ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *)

{ float, float, float } * "get_results"({ float, float, float } * %StructReturn, { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village)
begin
bb0:					;[#uses=0]
	%fval = alloca [4 x { { float, float, float } }]		; <[4 x { { float, float, float } }] *>	[#uses=2]
	%cast1081 = cast [4 x { { float, float, float } }] * %fval to { { float, float, float } } *		; <{ { float, float, float } } *>	[#uses=4]
	%r1 = alloca { float, float, float }		; <{ float, float, float } *>	[#uses=21]
	%r2 = alloca { float, float, float }		; <{ float, float, float } *>	[#uses=0]
	br label %bb1

bb1:					;[#uses=1]
	store float 0.000000, { float, float, float } * %r1, ubyte 2
	store float 0.000000, { float, float, float } * %r1, ubyte 0
	store float 0.000000, { float, float, float } * %r1, ubyte 1
	%cond1087 = setne { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, null		; <bool>	[#uses=1]
	br bool %cond1087, label %bb3, label %bb2

bb2:					;[#uses=1]
	%reg118 = load { float, float, float } * %r1, ubyte 0		; <float>	[#uses=1]
	%cast118 = cast float %reg118 to uint		; <uint>	[#uses=1]
	%cast1123 = cast { float, float, float } * %StructReturn to uint *		; <uint *>	[#uses=1]
	store uint %cast118, uint * %cast1123
	%reg119 = load { float, float, float } * %r1, ubyte 1		; <float>	[#uses=1]
	store float %reg119, { float, float, float } * %StructReturn, ubyte 1
	%reg120 = load { float, float, float } * %r1, ubyte 2		; <float>	[#uses=1]
	store float %reg120, { float, float, float } * %StructReturn, ubyte 2
	br label %bb10

bb3:					;[#uses=2]
	%cond1092 = setle long 3, 0		; <bool>	[#uses=1]
	br bool %cond1092, label %bb5, label %bb4

bb4:					;[#uses=3]
	%reg188 = phi int [ %reg189, %bb4 ], [ 3, %bb3 ]		; <int>	[#uses=4]
	%cast1135 = cast int %reg188 to uint		; <uint>	[#uses=1]
	%cast1134 = cast int %reg188 to uint		; <uint>	[#uses=1]
	%cast1132 = cast int %reg188 to uint		; <uint>	[#uses=1]
	%reg122 = shl uint %cast1132, ubyte 3		; <uint>	[#uses=1]
	%cast123 = cast uint %reg122 to { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *>	[#uses=1]
	%reg125 = add { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, %cast123		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *>	[#uses=1]
	%cast1133 = cast { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %reg125 to { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * *		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * *>	[#uses=1]
	%reg114 = load { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * * %cast1133		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *>	[#uses=1]
	%reg127 = shl uint %cast1134, ubyte 1		; <uint>	[#uses=1]
	%reg128 = add uint %reg127, %cast1135		; <uint>	[#uses=1]
	%reg129 = shl uint %reg128, ubyte 2		; <uint>	[#uses=1]
	%cast130 = cast uint %reg129 to { { float, float, float } } *		; <{ { float, float, float } } *>	[#uses=1]
	%reg133 = add { { float, float, float } } * %cast1081, %cast130		; <{ { float, float, float } } *>	[#uses=1]
	%eptr1136 = getelementptr { { float, float, float } } * %reg133, ubyte 0		; <{ float, float, float } *>	[#uses=1]
	call { float, float, float } * ({ float, float, float } *, { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *) * %get_results( { float, float, float } * %eptr1136, { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %reg114 )		; <{ float, float, float } *>:0	[#uses=0]
	%reg189 = add int %reg188, -1		; <int>	[#uses=2]
	%cond1093 = setgt int %reg189, 0		; <bool>	[#uses=1]
	br bool %cond1093, label %bb4, label %bb5

bb5:					;[#uses=3]
	%cast1138 = cast { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village to { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * *		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * *>	[#uses=1]
	%reg190 = load { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * * %cast1138		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *>	[#uses=1]
	%cast1139 = cast [4 x { { float, float, float } }] * %fval to { float, float, float } *		; <{ float, float, float } *>	[#uses=1]
	call { float, float, float } * ({ float, float, float } *, { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *) * %get_results( { float, float, float } * %cast1139, { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %reg190 )		; <{ float, float, float } *>:1	[#uses=0]
	%cond1094 = setlt long 3, 0		; <bool>	[#uses=1]
	br bool %cond1094, label %bb7, label %bb6

bb6:					;[#uses=3]
	%reg192 = phi int [ %reg193, %bb6 ], [ 3, %bb5 ]		; <int>	[#uses=3]
	%cast1141 = cast int %reg192 to uint		; <uint>	[#uses=1]
	%cast1140 = cast int %reg192 to uint		; <uint>	[#uses=1]
	%reg136 = shl uint %cast1140, ubyte 1		; <uint>	[#uses=1]
	%reg137 = add uint %reg136, %cast1141		; <uint>	[#uses=1]
	%reg138 = shl uint %reg137, ubyte 2		; <uint>	[#uses=2]
	%reg139 = add uint %reg138, 8		; <uint>	[#uses=1]
	%cast140 = cast uint %reg139 to { { float, float, float } } *		; <{ { float, float, float } } *>	[#uses=1]
	%reg144 = add { { float, float, float } } * %cast1081, %cast140		; <{ { float, float, float } } *>	[#uses=1]
	%reg145 = load { float, float, float } * %r1, ubyte 2		; <float>	[#uses=1]
	%reg146 = load { { float, float, float } } * %reg144, ubyte 0, ubyte 0		; <float>	[#uses=1]
	%reg147 = add float %reg145, %reg146		; <float>	[#uses=1]
	store float %reg147, { float, float, float } * %r1, ubyte 2
	%cast152 = cast uint %reg138 to { { float, float, float } } *		; <{ { float, float, float } } *>	[#uses=2]
	%reg156 = add { { float, float, float } } * %cast1081, %cast152		; <{ { float, float, float } } *>	[#uses=1]
	%reg157 = load { float, float, float } * %r1, ubyte 0		; <float>	[#uses=1]
	%reg158 = load { { float, float, float } } * %reg156, ubyte 0, ubyte 0		; <float>	[#uses=1]
	%reg159 = add float %reg157, %reg158		; <float>	[#uses=1]
	store float %reg159, { float, float, float } * %r1, ubyte 0
	%cast1148 = cast ulong 4 to { { float, float, float } } *		; <{ { float, float, float } } *>	[#uses=0]
	%eptr1194 = getelementptr { { float, float, float } } * %cast1081, ubyte 0, ubyte 1		; <float *>	[#uses=1]
	%cast167 = cast float * %eptr1194 to { { float, float, float } } *		; <{ { float, float, float } } *>	[#uses=1]
	%reg168 = add { { float, float, float } } * %cast167, %cast152		; <{ { float, float, float } } *>	[#uses=1]
	%reg169 = load { float, float, float } * %r1, ubyte 1		; <float>	[#uses=1]
	%reg170 = load { { float, float, float } } * %reg168, ubyte 0, ubyte 0		; <float>	[#uses=1]
	%reg171 = add float %reg169, %reg170		; <float>	[#uses=1]
	store float %reg171, { float, float, float } * %r1, ubyte 1
	%reg193 = add int %reg192, -1		; <int>	[#uses=2]
	%cond1102 = setge int %reg193, 0		; <bool>	[#uses=1]
	br bool %cond1102, label %bb6, label %bb7

bb7:					;[#uses=3]
	%reg112 = load { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %village, ubyte 2, ubyte 0		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>	[#uses=1]
	%cast112 = cast { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * %reg112 to ulong *		; <ulong *>	[#uses=2]
	%cond1104 = seteq ulong * %cast112, null		; <bool>	[#uses=1]
	br bool %cond1104, label %bb9, label %bb8

bb8:					;[#uses=3]
	%reg194 = phi ulong * [ %reg195, %bb8 ], [ %cast112, %bb7 ]		; <ulong *>	[#uses=2]
	%cast1169 = cast ulong * %reg194 to ulong * *		; <ulong * *>	[#uses=1]
	%cast1158 = cast ulong * %reg194 to int * *		; <int * *>	[#uses=1]
	%cast1157 = cast ulong 8 to int * *		; <int * *>	[#uses=1]
	%reg1105 = add int * * %cast1158, %cast1157		; <int * *>	[#uses=1]
	%reg113 = load int * * %reg1105		; <int *>	[#uses=2]
	%reg173 = load int * %reg113		; <int>	[#uses=1]
	%cast172 = cast int %reg173 to float		; <float>	[#uses=1]
	%reg174 = load { float, float, float } * %r1, ubyte 2		; <float>	[#uses=1]
	%reg175 = add float %reg174, %cast172		; <float>	[#uses=1]
	store float %reg175, { float, float, float } * %r1, ubyte 2
	%cast1162 = cast ulong 4 to int *		; <int *>	[#uses=1]
	%reg1109 = add int * %reg113, %cast1162		; <int *>	[#uses=1]
	%reg177 = load int * %reg1109		; <int>	[#uses=1]
	%cast176 = cast int %reg177 to float		; <float>	[#uses=1]
	%reg178 = load { float, float, float } * %r1, ubyte 1		; <float>	[#uses=1]
	%reg179 = add float %reg178, %cast176		; <float>	[#uses=1]
	store float %reg179, { float, float, float } * %r1, ubyte 1
	%reg181 = load { float, float, float } * %r1, ubyte 0		; <float>	[#uses=1]
	%cast180 = cast float %reg181 to double		; <double>	[#uses=1]
	%reg183 = add double %cast180, 1.000000		; <double>	[#uses=1]
	%cast184 = cast double %reg183 to float		; <float>	[#uses=1]
	store float %cast184, { float, float, float } * %r1, ubyte 0
	%reg195 = load ulong * * %cast1169		; <ulong *>	[#uses=2]
	%cond1114 = setne ulong * %reg195, null		; <bool>	[#uses=1]
	br bool %cond1114, label %bb8, label %bb9

bb9:					;[#uses=2]
	%reg185 = load { float, float, float } * %r1, ubyte 0		; <float>	[#uses=1]
	%cast185 = cast float %reg185 to uint		; <uint>	[#uses=1]
	%cast1172 = cast { float, float, float } * %StructReturn to uint *		; <uint *>	[#uses=1]
	store uint %cast185, uint * %cast1172
	%reg186 = load { float, float, float } * %r1, ubyte 1		; <float>	[#uses=1]
	store float %reg186, { float, float, float } * %StructReturn, ubyte 1
	%reg187 = load { float, float, float } * %r1, ubyte 2		; <float>	[#uses=1]
	store float %reg187, { float, float, float } * %StructReturn, ubyte 2
	br label %bb10

bb10:					;[#uses=2]
	ret { float, float, float } * %StructReturn

bb11:					;[#uses=0]
	%cast1181 = cast ulong 42 to { float, float, float } *		; <{ float, float, float } *>	[#uses=1]
	ret { float, float, float } * %cast1181
end

declare void "__eprintf"(sbyte *, sbyte *, uint, sbyte *)

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

declare double "sqrtl"(double)

declare float "sinf"(float)

declare double "sinl"(double)

declare float "cosf"(float)

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

{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * "alloc_tree"(int %level, int %lo, int %proc, int %label, { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %back)
begin
bb0:					;[#uses=0]
	%fval = alloca [4 x { uint * }]		; <[4 x { uint * }] *>	[#uses=2]
	%cast1000 = cast [4 x { uint * }] * %fval to { uint * } *		; <{ uint * } *>	[#uses=2]
	br label %bb1

bb1:					;[#uses=1]
	%cond1001 = setne int %level, 0		; <bool>	[#uses=1]
	br bool %cond1001, label %bb3, label %bb2

bb2:					;[#uses=1]
	ret { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * null

bb3:					;[#uses=2]
	%cast1002 = cast ulong 184 to uint		; <uint>	[#uses=1]
	%reg118 = call sbyte * (uint) * %malloc( uint %cast1002 )		; <sbyte *>	[#uses=18]
	%cond1003 = setle long 3, 0		; <bool>	[#uses=1]
	br bool %cond1003, label %bb9, label %bb4

bb4:					;[#uses=3]
	%reg194 = phi int [ %reg199, %bb8 ], [ 3, %bb3 ]		; <int>	[#uses=4]
	%cast1034 = cast int %reg194 to uint		; <uint>	[#uses=1]
	%reg120 = shl uint %cast1034, ubyte 3		; <uint>	[#uses=1]
	%cast121 = cast uint %reg120 to { uint * } *		; <{ uint * } *>	[#uses=1]
	%reg125 = add { uint * } * %cast1000, %cast121		; <{ uint * } *>	[#uses=1]
	%cast1040 = cast { uint * } * %reg125 to { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * *		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * *>	[#uses=1]
	%reg137 = add int %level, -1		; <int>	[#uses=1]
	%reg140 = mul int %proc, %reg194		; <int>	[#uses=3]
	%cond1004 = setge int %reg140, 0		; <bool>	[#uses=1]
	br bool %cond1004, label %bb6, label %bb5

bb5:					;[#uses=2]
	%reg195 = add int %reg140, 3		; <int>	[#uses=1]
	br label %bb6

bb6:					;[#uses=3]
	%reg196 = phi int [ %reg195, %bb5 ], [ %reg140, %bb4 ]		; <int>	[#uses=1]
	%reg139 = shr int %reg196, ubyte 2		; <int>	[#uses=1]
	%reg141 = add int %lo, %reg139		; <int>	[#uses=1]
	%cond1005 = setge int %proc, 0		; <bool>	[#uses=1]
	br bool %cond1005, label %bb8, label %bb7

bb7:					;[#uses=2]
	%reg197 = add int %proc, 3		; <int>	[#uses=1]
	br label %bb8

bb8:					;[#uses=3]
	%reg198 = phi int [ %reg197, %bb7 ], [ %proc, %bb6 ]		; <int>	[#uses=1]
	%reg142 = shr int %reg198, ubyte 2		; <int>	[#uses=1]
	%reg145 = shl int %label, ubyte 2		; <int>	[#uses=1]
	%reg146 = add int %reg145, %reg194		; <int>	[#uses=1]
	%reg147 = add int %reg146, 1		; <int>	[#uses=1]
	%cast1039 = cast sbyte * %reg118 to { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *>	[#uses=1]
	%reg148 = call { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * (int, int, int, int, { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *) * %alloc_tree( int %reg137, int %reg141, int %reg142, int %reg147, { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %cast1039 )		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *>	[#uses=1]
	store { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %reg148, { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * * %cast1040
	%reg199 = add int %reg194, -1		; <int>	[#uses=2]
	%cond1006 = setgt int %reg199, 0		; <bool>	[#uses=1]
	br bool %cond1006, label %bb4, label %bb9

bb9:					;[#uses=3]
	%reg155 = add int %level, -1		; <int>	[#uses=2]
	%cond1007 = setge int %proc, 0		; <bool>	[#uses=1]
	br bool %cond1007, label %bb11, label %bb10

bb10:					;[#uses=2]
	%reg200 = add int %proc, 3		; <int>	[#uses=1]
	br label %bb11

bb11:					;[#uses=3]
	%reg201 = phi int [ %reg200, %bb10 ], [ %proc, %bb9 ]		; <int>	[#uses=1]
	%reg156 = shr int %reg201, ubyte 2		; <int>	[#uses=1]
	%reg159 = shl int %label, ubyte 2		; <int>	[#uses=1]
	%reg160 = add int %reg159, 1		; <int>	[#uses=1]
	%cast1043 = cast sbyte * %reg118 to { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *>	[#uses=1]
	%reg161 = call { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * (int, int, int, int, { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *) * %alloc_tree( int %reg155, int %lo, int %reg156, int %reg160, { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %cast1043 )		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *>	[#uses=1]
	%cast1008 = cast [4 x { uint * }] * %fval to { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * *		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * *>	[#uses=1]
	store { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %reg161, { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * * %cast1008
	%cast1044 = cast ulong 32 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1009 = add sbyte * %reg118, %cast1044		; <sbyte *>	[#uses=1]
	%cast1045 = cast sbyte * %reg1009 to { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * *		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * *>	[#uses=1]
	store { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %back, { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * * %cast1045
	%cast1046 = cast ulong 176 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1010 = add sbyte * %reg118, %cast1046		; <sbyte *>	[#uses=1]
	%cast1047 = cast sbyte * %reg1010 to int *		; <int *>	[#uses=1]
	store int %label, int * %cast1047
	%reg162 = load int * %seed		; <int>	[#uses=1]
	%reg163 = add int %reg162, 127773		; <int>	[#uses=1]
	%reg164 = mul int %label, %reg163		; <int>	[#uses=1]
	%cast1048 = cast ulong 180 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1011 = add sbyte * %reg118, %cast1048		; <sbyte *>	[#uses=1]
	%cast1049 = cast sbyte * %reg1011 to int *		; <int *>	[#uses=1]
	store int %reg164, int * %cast1049
	%cast167 = cast int %reg155 to double		; <double>	[#uses=1]
	%reg168 = call double (double, double) * %pow( double 2.000000, double %cast167 )		; <double>	[#uses=1]
	%cast169 = cast double %reg168 to int		; <int>	[#uses=2]
	%cast1050 = cast ulong 64 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1012 = add sbyte * %reg118, %cast1050		; <sbyte *>	[#uses=1]
	%cast1051 = cast sbyte * %reg1012 to int *		; <int *>	[#uses=1]
	store int %cast169, int * %cast1051
	%cast1052 = cast ulong 68 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1013 = add sbyte * %reg118, %cast1052		; <sbyte *>	[#uses=1]
	%cast1053 = cast sbyte * %reg1013 to int *		; <int *>	[#uses=1]
	store int %cast169, int * %cast1053
	%cast1054 = cast ulong 72 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1014 = add sbyte * %reg118, %cast1054		; <sbyte *>	[#uses=1]
	%cast1055 = cast sbyte * %reg1014 to uint *		; <uint *>	[#uses=1]
	store uint 0, uint * %cast1055
	%cast1056 = cast ulong 104 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1015 = add sbyte * %reg118, %cast1056		; <sbyte *>	[#uses=1]
	%cast1057 = cast sbyte * %reg1015 to ulong * *		; <ulong * *>	[#uses=1]
	store ulong * null, ulong * * %cast1057
	%cast1058 = cast ulong 120 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1016 = add sbyte * %reg118, %cast1058		; <sbyte *>	[#uses=1]
	%cast1059 = cast sbyte * %reg1016 to ulong * *		; <ulong * *>	[#uses=1]
	store ulong * null, ulong * * %cast1059
	%cast1060 = cast ulong 80 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1017 = add sbyte * %reg118, %cast1060		; <sbyte *>	[#uses=1]
	%cast1061 = cast sbyte * %reg1017 to ulong * *		; <ulong * *>	[#uses=1]
	store ulong * null, ulong * * %cast1061
	%cast1062 = cast ulong 96 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1018 = add sbyte * %reg118, %cast1062		; <sbyte *>	[#uses=1]
	%cast1063 = cast sbyte * %reg1018 to ulong * *		; <ulong * *>	[#uses=1]
	store ulong * null, ulong * * %cast1063
	%cast1064 = cast ulong 128 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1019 = add sbyte * %reg118, %cast1064		; <sbyte *>	[#uses=1]
	%cast1065 = cast sbyte * %reg1019 to ulong * *		; <ulong * *>	[#uses=1]
	store ulong * null, ulong * * %cast1065
	%cast1066 = cast ulong 144 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1020 = add sbyte * %reg118, %cast1066		; <sbyte *>	[#uses=1]
	%cast1067 = cast sbyte * %reg1020 to ulong * *		; <ulong * *>	[#uses=1]
	store ulong * null, ulong * * %cast1067
	%cast1068 = cast ulong 56 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1021 = add sbyte * %reg118, %cast1068		; <sbyte *>	[#uses=1]
	%cast1069 = cast sbyte * %reg1021 to ulong * *		; <ulong * *>	[#uses=1]
	store ulong * null, ulong * * %cast1069
	%cast1070 = cast ulong 40 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1022 = add sbyte * %reg118, %cast1070		; <sbyte *>	[#uses=1]
	%cast1071 = cast sbyte * %reg1022 to ulong * *		; <ulong * *>	[#uses=1]
	store ulong * null, ulong * * %cast1071
	%cond1023 = setgt long 0, 3		; <bool>	[#uses=1]
	br bool %cond1023, label %bb13, label %bb12

bb12:					;[#uses=3]
	%reg203 = phi int [ %reg204, %bb12 ], [ 0, %bb11 ]		; <int>	[#uses=2]
	%cast1072 = cast int %reg203 to uint		; <uint>	[#uses=1]
	%reg181 = shl uint %cast1072, ubyte 3		; <uint>	[#uses=2]
	%cast182 = cast uint %reg181 to sbyte *		; <sbyte *>	[#uses=1]
	%reg184 = add sbyte * %reg118, %cast182		; <sbyte *>	[#uses=1]
	%cast1074 = cast sbyte * %reg184 to ulong * *		; <ulong * *>	[#uses=1]
	%cast1078 = cast uint %reg181 to { uint * } *		; <{ uint * } *>	[#uses=1]
	%reg191 = add { uint * } * %cast1000, %cast1078		; <{ uint * } *>	[#uses=1]
	%reg192 = load { uint * } * %reg191, ubyte 0		; <uint *>	[#uses=1]
	%cast192 = cast uint * %reg192 to ulong *		; <ulong *>	[#uses=1]
	store ulong * %cast192, ulong * * %cast1074
	%reg204 = add int %reg203, 1		; <int>	[#uses=2]
	%cond1024 = setle int %reg204, 3		; <bool>	[#uses=1]
	br bool %cond1024, label %bb12, label %bb13

bb13:					;[#uses=2]
	%cast1076 = cast sbyte * %reg118 to { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *>	[#uses=1]
	ret { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %cast1076

bb14:					;[#uses=0]
	%cast1077 = cast ulong 42 to { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *>	[#uses=1]
	ret { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %cast1077
end

int "main"(int %argc, sbyte * * %argv)
begin
bb0:					;[#uses=0]
	%results = alloca { float, float, float }		; <{ float, float, float } *>	[#uses=4]
	br label %bb1

bb1:					;[#uses=2]
	call void () * %__main( )
	call int (int, sbyte * *) * %dealwithargs( int %argc, sbyte * * %argv )		; <int>:0	[#uses=0]
	%reg114 = load int * %max_level		; <int>	[#uses=1]
	%cast1415 = cast ulong 0 to int		; <int>	[#uses=1]
	%cast1416 = cast ulong 0 to int		; <int>	[#uses=1]
	%cast1417 = cast ulong 0 to int		; <int>	[#uses=1]
	%reg109 = call { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * (int, int, int, int, { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *) * %alloc_tree( int %reg114, int %cast1417, int %cast1416, int %cast1415, { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %reg109 )		; <{ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *>	[#uses=3]
	%cast1424 = cast [39 x sbyte] * %__intern_LC2 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *) * %puts( sbyte * %cast1424 )		; <int>:1	[#uses=0]
	%cast1425 = cast [11 x sbyte] * %__intern_LC3 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *) * %puts( sbyte * %cast1425 )		; <int>:2	[#uses=0]
	%reg140 = load int * %max_time		; <int>	[#uses=1]
	%cond1418 = setge int 0, %reg140		; <bool>	[#uses=1]
	br bool %cond1418, label %bb5, label %bb2

bb2:					;[#uses=2]
	%reg141 = phi int [ %reg142, %bb4 ], [ 0, %bb1 ]		; <int>	[#uses=5]
	%cast122 = cast int %reg141 to ulong		; <ulong>	[#uses=1]
	%reg123 = mul ulong %cast122, 1374389535		; <ulong>	[#uses=1]
	%reg124 = shr ulong %reg123, ubyte 32		; <ulong>	[#uses=1]
	%cast1423 = cast ulong %reg124 to int		; <int>	[#uses=1]
	%reg125 = shr int %cast1423, ubyte 4		; <int>	[#uses=1]
	%reg126 = shr int %reg141, ubyte 31		; <int>	[#uses=1]
	%reg121 = sub int %reg125, %reg126		; <int>	[#uses=1]
	%reg127 = mul int %reg121, 50		; <int>	[#uses=1]
	%reg128 = sub int %reg141, %reg127		; <int>	[#uses=1]
	%cond1419 = setne int %reg128, 0		; <bool>	[#uses=1]
	br bool %cond1419, label %bb4, label %bb3

bb3:					;[#uses=1]
	%cast1428 = cast [4 x sbyte] * %__intern_LC4 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast1428, int %reg141 )		; <int>:3	[#uses=0]
	br label %bb4

bb4:					;[#uses=3]
	call { \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } * ({ [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *) * %sim( { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %reg109 )		; <{ \2, { int, int, int, { [4 x \3], \2, \5, { int, int, int, \6, \6, \6, \6 }, int, int } * } *, \2 } *>:0	[#uses=0]
	%reg142 = add int %reg141, 1		; <int>	[#uses=2]
	%reg120 = load int * %max_time		; <int>	[#uses=1]
	%cond1420 = setlt int %reg142, %reg120		; <bool>	[#uses=1]
	br bool %cond1420, label %bb2, label %bb5

bb5:					;[#uses=2]
	call { float, float, float } * ({ float, float, float } *, { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } *) * %get_results( { float, float, float } * %results, { [4 x \3], \2, { \2 *, { int, int, int, \5 } *, \2 * }, { int, int, int, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * }, { \2 *, { int, int, int, \6 } *, \2 * } }, int, int } * %reg109 )		; <{ float, float, float } *>:0	[#uses=0]
	%reg112 = load { float, float, float } * %results, ubyte 0		; <float>	[#uses=3]
	%reg111 = load { float, float, float } * %results, ubyte 1		; <float>	[#uses=1]
	%reg113 = load { float, float, float } * %results, ubyte 2		; <float>	[#uses=1]
	%cast1435 = cast [7 x sbyte] * %__intern_LC5 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *) * %puts( sbyte * %cast1435 )		; <int>:4	[#uses=0]
	%cast133 = cast float %reg112 to double		; <double>	[#uses=1]
	%cast1437 = cast [45 x sbyte] * %__intern_LC6 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast1437, double %cast133 )		; <int>:5	[#uses=0]
	%reg135 = div float %reg111, %reg112		; <float>	[#uses=1]
	%cast136 = cast float %reg135 to double		; <double>	[#uses=1]
	%cast1443 = cast [49 x sbyte] * %__intern_LC7 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast1443, double %cast136 )		; <int>:6	[#uses=0]
	%reg138 = div float %reg113, %reg112		; <float>	[#uses=1]
	%cast139 = cast float %reg138 to double		; <double>	[#uses=1]
	%cast1449 = cast [49 x sbyte] * %__intern_LC8 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast1449, double %cast139 )		; <int>:7	[#uses=0]
	ret int 42
end
