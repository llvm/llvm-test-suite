	%BlueReturn = type { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int }
	%FILE = type { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint }
	%Graph = type { [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } *
	%Hash = type { { uint, sbyte *, \2 } * *, int (uint) *, int } *
	%HashEntry = type { uint, sbyte *, \2 } *
	%Vertex = type { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *
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
	%blue_return = type { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int }
	%char = type sbyte
	%complex.double = type { double, double }
	%complex.float = type { float, float }
	%complex.int = type { int, int }
	%complex.long.double = type { double, double }
	%double = type double
	%fc_br = type { { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } }
	%float = type float
	%fpos_t = type int
	%future_cell_BlueReturn = type { { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } }
	%graph_st = type { [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] }
	%hash = type { { uint, sbyte *, \2 } * *, int (uint) *, int }
	%hash_entry = type { uint, sbyte *, \2 * }
	%int = type int
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
	%unsigned.char = type ubyte
	%unsigned.int = type uint
	%vert_st = type { int, \2 *, { { uint, sbyte *, \2 } * *, int (uint) *, int } * }
	%void = type void
%__iob = uninitialized global [20 x { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint }]		; <[20 x { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint }] *>	[#uses=0]
%_sibuf = uninitialized global [ubyte]		; <[ubyte] *>	[#uses=0]
%_sobuf = uninitialized global [ubyte]		; <[ubyte] *>	[#uses=0]
%_bufendtab = uninitialized global [ubyte *]		; <[ubyte *] *>	[#uses=0]
%_lastbuf = uninitialized global { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *		; <{ int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } * *>	[#uses=0]
%NumNodes = uninitialized global int		; <int *>	[#uses=2]
%__intern_LC0 = global [10 x sbyte] c"Not found\00"		; <[10 x sbyte] *>	[#uses=2]
%MyVertexList = global { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * null		; <{ int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * *>	[#uses=5]
%__intern_LC1 = global [16 x sbyte] c"Compute phase 1\00"		; <[16 x sbyte] *>	[#uses=1]
%__intern_LC2 = global [16 x sbyte] c"Compute phase 2\00"		; <[16 x sbyte] *>	[#uses=1]
%__intern_LC3 = global [25 x sbyte] c"Making graph of size %d\0A\00"		; <[25 x sbyte] *>	[#uses=1]
%__intern_LC4 = global [16 x sbyte] c"Graph completed\00"		; <[16 x sbyte] *>	[#uses=1]
%__intern_LC5 = global [22 x sbyte] c"About to compute mst \00"		; <[22 x sbyte] *>	[#uses=1]
%__intern_LC6 = global [17 x sbyte] c"MST has cost %d\0A\00"		; <[17 x sbyte] *>	[#uses=1]
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

declare { { uint, sbyte *, \2 } * *, int (uint) *, int } * "MakeHash"(int, int (uint) *)

declare sbyte * "HashLookup"(uint, { { uint, sbyte *, \2 } * *, int (uint) *, int } *)

declare void "HashInsert"(sbyte *, uint, { { uint, sbyte *, \2 } * *, int (uint) *, int } *)

declare void "HashDelete"(uint, { { uint, sbyte *, \2 } * *, int (uint) *, int } *)

declare { [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } * "MakeGraph"(int, int)

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

{ { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * "BlueRule"({ { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %StructReturn, { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %inserted, { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %vlist)
begin
bb0:					;[#uses=0]
	%retval = alloca { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int }		; <{ { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } *>	[#uses=12]
	br label %bb1

bb1:					;[#uses=1]
	%cond1000 = setne { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %vlist, null		; <bool>	[#uses=1]
	br bool %cond1000, label %bb3, label %bb2

bb2:					;[#uses=1]
	store int 999999, { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %retval, ubyte 1
	%reg117 = load { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %retval, ubyte 0		; <{ int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *>	[#uses=1]
	%cast117 = cast { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %reg117 to ulong		; <ulong>	[#uses=1]
	%cast1039 = cast { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %StructReturn to ulong *		; <ulong *>	[#uses=1]
	store ulong %cast117, ulong * %cast1039
	%eptr1084 = getelementptr { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %retval, ubyte 1		; <int *>	[#uses=1]
	%cast1041 = cast int * %eptr1084 to ulong *		; <ulong *>	[#uses=1]
	%reg118 = load ulong * %cast1041		; <ulong>	[#uses=1]
	%eptr1085 = getelementptr { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %StructReturn, ubyte 1		; <int *>	[#uses=1]
	%cast1043 = cast int * %eptr1085 to ulong *		; <ulong *>	[#uses=1]
	store ulong %reg118, ulong * %cast1043
	br label %bb18

bb3:					;[#uses=1]
	store { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %vlist, { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %retval, ubyte 0
	%reg119 = load { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %vlist, ubyte 0		; <int>	[#uses=1]
	store int %reg119, { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %retval, ubyte 1
	%reg112 = load { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %vlist, ubyte 2		; <{ { uint, sbyte *, \2 } * *, int (uint) *, int } *>	[#uses=1]
	%cast1031 = cast { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %inserted to uint		; <uint>	[#uses=1]
	%reg121 = call sbyte * (uint, { { uint, sbyte *, \2 } * *, int (uint) *, int } *) * %HashLookup( uint %cast1031, { { uint, sbyte *, \2 } * *, int (uint) *, int } * %reg112 )		; <sbyte *>	[#uses=3]
	%cast113 = cast sbyte * %reg121 to int		; <int>	[#uses=2]
	%cond1009 = seteq int %cast113, 0		; <bool>	[#uses=1]
	br bool %cond1009, label %bb6, label %bb4

bb4:					;[#uses=1]
	%reg123 = load { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %retval, ubyte 1		; <int>	[#uses=1]
	%cond1011 = setge int %cast113, %reg123		; <bool>	[#uses=1]
	br bool %cond1011, label %bb7, label %bb5

bb5:					;[#uses=1]
	%cast1032 = cast sbyte * %reg121 to uint		; <uint>	[#uses=1]
	%cast1050 = cast { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %vlist to uint *		; <uint *>	[#uses=1]
	store uint %cast1032, uint * %cast1050
	%cast1092 = cast sbyte * %reg121 to int		; <int>	[#uses=1]
	store int %cast1092, { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %retval, ubyte 1
	br label %bb7

bb6:					;[#uses=1]
	%cast1052 = cast [10 x sbyte] * %__intern_LC0 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *) * %puts( sbyte * %cast1052 )		; <int>:0	[#uses=0]
	br label %bb7

bb7:					;[#uses=5]
	%reg110 = load { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %vlist, ubyte 1		; <{ int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *>	[#uses=1]
	%cast110 = cast { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %reg110 to ulong *		; <ulong *>	[#uses=2]
	%cond1015 = seteq ulong * %cast110, null		; <bool>	[#uses=1]
	br bool %cond1015, label %bb17, label %bb8

bb8:					;[#uses=2]
	%reg133 = phi { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * [ %cast1079, %bb16 ], [ %vlist, %bb7 ]		; <{ int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *>	[#uses=1]
	%reg134 = phi ulong * [ %reg140, %bb16 ], [ %cast110, %bb7 ]		; <ulong *>	[#uses=8]
	%cast1080 = cast ulong * %reg134 to { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *		; <{ int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *>	[#uses=1]
	%cast1079 = cast ulong * %reg134 to { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *		; <{ int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *>	[#uses=1]
	%cast1070 = cast ulong * %reg134 to ulong * *		; <ulong * *>	[#uses=1]
	%cast1063 = cast ulong * %reg134 to uint *		; <uint *>	[#uses=1]
	%cast1062 = cast ulong * %reg134 to int *		; <int *>	[#uses=1]
	%cast1061 = cast ulong * %reg134 to { { uint, sbyte *, \2 } * *, int (uint) *, int } * *		; <{ { uint, sbyte *, \2 } * *, int (uint) *, int } * *>	[#uses=1]
	%cast1057 = cast ulong * %reg134 to ulong * *		; <ulong * *>	[#uses=1]
	%cond1016 = setne { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %cast1080, %inserted		; <bool>	[#uses=1]
	br bool %cond1016, label %bb10, label %bb9

bb9:					;[#uses=1]
	%cast1056 = cast ulong 8 to ulong * *		; <ulong * *>	[#uses=1]
	%reg1017 = add ulong * * %cast1057, %cast1056		; <ulong * *>	[#uses=1]
	%reg125 = load ulong * * %reg1017		; <ulong *>	[#uses=1]
	%cast1058 = cast ulong 8 to ulong * *		; <ulong * *>	[#uses=0]
	%eptr1094 = getelementptr { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %reg133, ubyte 1		; <{ int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * *>	[#uses=1]
	%cast1018 = cast { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * * %eptr1094 to ulong * *		; <ulong * *>	[#uses=1]
	store ulong * %reg125, ulong * * %cast1018
	br label %bb16

bb10:					;[#uses=1]
	%cast1060 = cast ulong 16 to { { uint, sbyte *, \2 } * *, int (uint) *, int } * *		; <{ { uint, sbyte *, \2 } * *, int (uint) *, int } * *>	[#uses=1]
	%reg1019 = add { { uint, sbyte *, \2 } * *, int (uint) *, int } * * %cast1061, %cast1060		; <{ { uint, sbyte *, \2 } * *, int (uint) *, int } * *>	[#uses=1]
	%reg135 = load { { uint, sbyte *, \2 } * *, int (uint) *, int } * * %reg1019		; <{ { uint, sbyte *, \2 } * *, int (uint) *, int } *>	[#uses=1]
	%reg114 = load int * %cast1062		; <int>	[#uses=3]
	%cast1034 = cast { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %inserted to uint		; <uint>	[#uses=1]
	%reg127 = call sbyte * (uint, { { uint, sbyte *, \2 } * *, int (uint) *, int } *) * %HashLookup( uint %cast1034, { { uint, sbyte *, \2 } * *, int (uint) *, int } * %reg135 )		; <sbyte *>	[#uses=3]
	%cast136 = cast sbyte * %reg127 to int		; <int>	[#uses=2]
	%cond1020 = seteq int %cast136, 0		; <bool>	[#uses=1]
	br bool %cond1020, label %bb13, label %bb11

bb11:					;[#uses=2]
	%cond1021 = setge int %cast136, %reg114		; <bool>	[#uses=1]
	br bool %cond1021, label %bb14, label %bb12

bb12:					;[#uses=2]
	%cast1035 = cast sbyte * %reg127 to uint		; <uint>	[#uses=1]
	store uint %cast1035, uint * %cast1063
	%cast137 = cast sbyte * %reg127 to int		; <int>	[#uses=1]
	br label %bb14

bb13:					;[#uses=2]
	%cast1064 = cast [10 x sbyte] * %__intern_LC0 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *) * %puts( sbyte * %cast1064 )		; <int>:1	[#uses=0]
	br label %bb14

bb14:					;[#uses=3]
	%reg138 = phi int [ %reg114, %bb13 ], [ %cast137, %bb12 ], [ %reg114, %bb11 ]		; <int>	[#uses=2]
	%reg130 = load { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %retval, ubyte 1		; <int>	[#uses=1]
	%cond1023 = setge int %reg138, %reg130		; <bool>	[#uses=1]
	br bool %cond1023, label %bb16, label %bb15

bb15:					;[#uses=1]
	%cast1024 = cast { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %retval to ulong * *		; <ulong * *>	[#uses=1]
	store ulong * %reg134, ulong * * %cast1024
	store int %reg138, { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %retval, ubyte 1
	br label %bb16

bb16:					;[#uses=5]
	%cast1069 = cast ulong 8 to ulong * *		; <ulong * *>	[#uses=1]
	%reg1027 = add ulong * * %cast1070, %cast1069		; <ulong * *>	[#uses=1]
	%reg140 = load ulong * * %reg1027		; <ulong *>	[#uses=2]
	%cond1028 = setne ulong * %reg140, null		; <bool>	[#uses=1]
	br bool %cond1028, label %bb8, label %bb17

bb17:					;[#uses=2]
	%reg131 = load { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %retval, ubyte 0		; <{ int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *>	[#uses=1]
	%cast131 = cast { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %reg131 to ulong		; <ulong>	[#uses=1]
	%cast1073 = cast { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %StructReturn to ulong *		; <ulong *>	[#uses=1]
	store ulong %cast131, ulong * %cast1073
	%eptr1099 = getelementptr { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %retval, ubyte 1		; <int *>	[#uses=1]
	%cast1075 = cast int * %eptr1099 to ulong *		; <ulong *>	[#uses=1]
	%reg132 = load ulong * %cast1075		; <ulong>	[#uses=1]
	%eptr1100 = getelementptr { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %StructReturn, ubyte 1		; <int *>	[#uses=1]
	%cast1077 = cast int * %eptr1100 to ulong *		; <ulong *>	[#uses=1]
	store ulong %reg132, ulong * %cast1077
	br label %bb18

bb18:					;[#uses=2]
	ret { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %StructReturn

bb19:					;[#uses=0]
	%cast1078 = cast ulong 42 to { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } *		; <{ { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } *>	[#uses=1]
	ret { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %cast1078
end

void "SetMyVertexList"({ int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %v)
begin
bb1:					;[#uses=0]
	store { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %v, { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * * %MyVertexList
	ret void
end

{ { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * "Do_all_BlueRule"({ { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %StructReturn, { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %inserted, int %nproc, int %pn)
begin
bb0:					;[#uses=0]
	%fcleft = alloca { { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } }		; <{ { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } } *>	[#uses=3]
	%retright = alloca { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int }		; <{ { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } *>	[#uses=6]
	br label %bb1

bb1:					;[#uses=1]
	%cond1102 = setle int %nproc, 1		; <bool>	[#uses=1]
	br bool %cond1102, label %bb5, label %bb2

bb2:					;[#uses=1]
	%reg113 = shr int %nproc, ubyte 31		; <int>	[#uses=1]
	%cast1113 = cast int %reg113 to uint		; <uint>	[#uses=1]
	%reg114 = shr uint %cast1113, ubyte 31		; <uint>	[#uses=1]
	%cast1114 = cast uint %reg114 to int		; <int>	[#uses=1]
	%reg115 = add int %nproc, %cast1114		; <int>	[#uses=1]
	%reg112 = shr int %reg115, ubyte 1		; <int>	[#uses=3]
	%reg120 = add int %pn, %reg112		; <int>	[#uses=1]
	%eptr1115 = getelementptr { { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } } * %fcleft, ubyte 0		; <{ { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } *>	[#uses=1]
	call { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * ({ { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } *, { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int, int) * %Do_all_BlueRule( { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %eptr1115, { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %inserted, int %reg112, int %reg120 )		; <{ { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } *>:0	[#uses=0]
	call { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * ({ { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } *, { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int, int) * %Do_all_BlueRule( { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %retright, { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %inserted, int %reg112, int %pn )		; <{ { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } *>:1	[#uses=0]
	%reg126 = load { { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } } * %fcleft, ubyte 0, ubyte 1		; <int>	[#uses=2]
	%reg127 = load { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %retright, ubyte 1		; <int>	[#uses=1]
	%cond1105 = setge int %reg126, %reg127		; <bool>	[#uses=1]
	br bool %cond1105, label %bb4, label %bb3

bb3:					;[#uses=1]
	store int %reg126, { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %retright, ubyte 1
	%reg129 = load { { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } } * %fcleft, ubyte 0, ubyte 0		; <{ int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *>	[#uses=1]
	%cast129 = cast { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %reg129 to ulong *		; <ulong *>	[#uses=1]
	%cast1108 = cast { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %retright to ulong * *		; <ulong * *>	[#uses=1]
	store ulong * %cast129, ulong * * %cast1108
	br label %bb4

bb4:					;[#uses=2]
	%reg130 = load { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %retright, ubyte 0		; <{ int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *>	[#uses=1]
	%cast130 = cast { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %reg130 to ulong		; <ulong>	[#uses=1]
	%cast1123 = cast { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %StructReturn to ulong *		; <ulong *>	[#uses=1]
	store ulong %cast130, ulong * %cast1123
	%eptr1140 = getelementptr { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %retright, ubyte 1		; <int *>	[#uses=1]
	%cast1125 = cast int * %eptr1140 to ulong *		; <ulong *>	[#uses=1]
	%reg131 = load ulong * %cast1125		; <ulong>	[#uses=1]
	%eptr1141 = getelementptr { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %StructReturn, ubyte 1		; <int *>	[#uses=1]
	%cast1127 = cast int * %eptr1141 to ulong *		; <ulong *>	[#uses=1]
	store ulong %reg131, ulong * %cast1127
	br label %bb8

bb5:					;[#uses=1]
	%reg132 = load { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * * %MyVertexList		; <{ int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *>	[#uses=1]
	%cond1111 = setne { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %inserted, %reg132		; <bool>	[#uses=1]
	br bool %cond1111, label %bb7, label %bb6

bb6:					;[#uses=1]
	%reg134 = load { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %inserted, ubyte 1		; <{ int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *>	[#uses=1]
	store { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %reg134, { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * * %MyVertexList
	br label %bb7

bb7:					;[#uses=2]
	%reg135 = load { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * * %MyVertexList		; <{ int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *>	[#uses=1]
	call { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * ({ { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } *, { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *) * %BlueRule( { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %StructReturn, { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %inserted, { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %reg135 )		; <{ { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } *>:2	[#uses=0]
	br label %bb8

bb8:					;[#uses=2]
	ret { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %StructReturn

bb9:					;[#uses=0]
	%cast1130 = cast ulong 42 to { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } *		; <{ { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } *>	[#uses=1]
	ret { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %cast1130
end

int "ComputeMst"({ [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } * %graph, int %numproc, int %numvert)
begin
bb0:					;[#uses=0]
	%br = alloca { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int }		; <{ { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } *>	[#uses=3]
	br label %bb1

bb1:					;[#uses=5]
	%cast1149 = cast [16 x sbyte] * %__intern_LC1 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *) * %puts( sbyte * %cast1149 )		; <int>:0	[#uses=0]
	%cast1150 = cast { [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } * %graph to ulong * * *		; <ulong * * *>	[#uses=1]
	%reg111 = load ulong * * * %cast1150		; <ulong * *>	[#uses=2]
	%cast1151 = cast ulong 8 to ulong * *		; <ulong * *>	[#uses=1]
	%reg1144 = add ulong * * %reg111, %cast1151		; <ulong * *>	[#uses=1]
	%reg112 = load ulong * * %reg1144		; <ulong *>	[#uses=2]
	%cast1152 = cast { [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } * %graph to ulong * *		; <ulong * *>	[#uses=1]
	store ulong * %reg112, ulong * * %cast1152
	%cast1159 = cast { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * * %MyVertexList to ulong * *		; <ulong * *>	[#uses=1]
	store ulong * %reg112, ulong * * %cast1159
	%reg121 = add int %numvert, -1		; <int>	[#uses=2]
	%cast1153 = cast [16 x sbyte] * %__intern_LC2 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *) * %puts( sbyte * %cast1153 )		; <int>:1	[#uses=0]
	%cond1145 = seteq int %reg121, 0		; <bool>	[#uses=1]
	br bool %cond1145, label %bb3, label %bb2

bb2:					;[#uses=6]
	%reg122 = phi uint [ %reg127, %bb2 ], [ 0, %bb1 ]		; <uint>	[#uses=1]
	%reg123 = phi ulong * * [ %cast125, %bb2 ], [ %reg111, %bb1 ]		; <ulong * *>	[#uses=1]
	%cast1154 = cast ulong * * %reg123 to { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *		; <{ int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *>	[#uses=1]
	%reg124 = phi int [ %reg126, %bb2 ], [ %reg121, %bb1 ]		; <int>	[#uses=1]
	%cast1146 = cast ulong 0 to int		; <int>	[#uses=1]
	call { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * ({ { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } *, { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int, int) * %Do_all_BlueRule( { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %br, { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %cast1154, int %numproc, int %cast1146 )		; <{ { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } *>:0	[#uses=0]
	%reg125 = load { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %br, ubyte 0		; <{ int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *>	[#uses=1]
	%cast125 = cast { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %reg125 to ulong * *		; <ulong * *>	[#uses=1]
	%reg115 = load { { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *, int } * %br, ubyte 1		; <int>	[#uses=1]
	%cast115 = cast int %reg115 to uint		; <uint>	[#uses=1]
	%reg126 = add int %reg124, -1		; <int>	[#uses=2]
	%reg127 = add uint %reg122, %cast115		; <uint>	[#uses=2]
	%cond1148 = setne int %reg126, 0		; <bool>	[#uses=1]
	br bool %cond1148, label %bb2, label %bb3

bb3:					;[#uses=2]
	%reg128 = phi uint [ %reg127, %bb2 ], [ 0, %bb1 ]		; <uint>	[#uses=1]
	%cast1158 = cast uint %reg128 to int		; <int>	[#uses=1]
	ret int %cast1158

bb4:					;[#uses=0]
	ret int 42
end

declare int "dealwithargs"(...)

int "main"(int %argc, sbyte * * %argv)
begin
bb1:					;[#uses=0]
	call void () * %__main( )
	%reg111 = call int (...) * %dealwithargs( int %argc, sbyte * * %argv )		; <int>	[#uses=3]
	%cast1165 = cast [25 x sbyte] * %__intern_LC3 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast1165, int %reg111 )		; <int>:0	[#uses=0]
	%reg113 = load int * %NumNodes		; <int>	[#uses=1]
	%reg109 = call { [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } * (int, int) * %MakeGraph( int %reg111, int %reg113 )		; <{ [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } *>	[#uses=1]
	%cast1166 = cast [16 x sbyte] * %__intern_LC4 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *) * %puts( sbyte * %cast1166 )		; <int>:1	[#uses=0]
	%cast1167 = cast [22 x sbyte] * %__intern_LC5 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *) * %puts( sbyte * %cast1167 )		; <int>:2	[#uses=0]
	%reg116 = load int * %NumNodes		; <int>	[#uses=1]
	%reg110 = call int ({ [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } *, int, int) * %ComputeMst( { [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } * %reg109, int %reg116, int %reg111 )		; <int>	[#uses=1]
	%cast1168 = cast [17 x sbyte] * %__intern_LC6 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast1168, int %reg110 )		; <int>:3	[#uses=0]
	%cast1164 = cast ulong 0 to uint		; <uint>	[#uses=1]
	call void (...) * %exit( uint %cast1164 )
	ret int 42
end
