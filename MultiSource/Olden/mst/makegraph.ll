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
	%char = type sbyte
	%complex.double = type { double, double }
	%complex.float = type { float, float }
	%complex.int = type { int, int }
	%complex.long.double = type { double, double }
	%double = type double
	%float = type float
	%fpos_t = type int
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
%NumNodes = uninitialized global int		; <int *>	[#uses=0]
%HashRange = uninitialized global int		; <int *>	[#uses=2]
%__intern_LC0 = global [13 x sbyte] c"Make phase 2\00"		; <[13 x sbyte] *>	[#uses=1]
%__intern_LC1 = global [13 x sbyte] c"Make phase 3\00"		; <[13 x sbyte] *>	[#uses=1]
%__intern_LC2 = global [13 x sbyte] c"Make phase 4\00"		; <[13 x sbyte] *>	[#uses=1]
%__intern_LC3 = global [15 x sbyte] c"Make returning\00"		; <[15 x sbyte] *>	[#uses=1]
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

{ [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } * "MakeGraph"(int %numvert, int %numproc)
begin
bb1:					;[#uses=1]
	%reg109 = div int %numvert, %numproc		; <int>	[#uses=7]
	%cast1042 = cast ulong 8 to uint		; <uint>	[#uses=1]
	%reg118 = call int (...) * %malloc( uint %cast1042 )		; <int>	[#uses=3]
	%cast116 = cast int %reg118 to uint * *		; <uint * *>	[#uses=2]
	%cond1043 = setgt long 0, 0		; <bool>	[#uses=1]
	br bool %cond1043, label %bb3, label %bb2

bb2:					;[#uses=3]
	%reg157 = phi int [ %reg158, %bb2 ], [ 0, %bb1 ]		; <int>	[#uses=2]
	%cast1058 = cast int %reg157 to uint		; <uint>	[#uses=1]
	%reg121 = shl uint %cast1058, ubyte 3		; <uint>	[#uses=1]
	%cast122 = cast uint %reg121 to uint * *		; <uint * *>	[#uses=1]
	%reg124 = add uint * * %cast116, %cast122		; <uint * *>	[#uses=1]
	store uint * null, uint * * %reg124
	%reg158 = add int %reg157, 1		; <int>	[#uses=2]
	%cond1044 = setle int %reg158, 0		; <bool>	[#uses=1]
	br bool %cond1044, label %bb2, label %bb3

bb3:					;[#uses=3]
	%cast1060 = cast [13 x sbyte] * %__intern_LC0 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *) * %puts( sbyte * %cast1060 )		; <int>:0	[#uses=0]
	%reg111 = add int %numproc, -1		; <int>	[#uses=2]
	%cond1045 = setlt int %reg111, 0		; <bool>	[#uses=1]
	br bool %cond1045, label %bb9, label %bb4

bb4:					;[#uses=5]
	%reg159 = phi int [ %reg168, %bb8 ], [ %reg111, %bb3 ]		; <int>	[#uses=2]
	%cast1071 = cast int %reg159 to uint		; <uint>	[#uses=1]
	%reg128 = shl int %reg109, ubyte 1		; <int>	[#uses=1]
	%reg129 = add int %reg128, %reg109		; <int>	[#uses=1]
	%reg130 = shl int %reg129, ubyte 3		; <int>	[#uses=1]
	%reg131 = call int (...) * %malloc( int %reg130 )		; <int>	[#uses=1]
	%cast115 = cast int %reg131 to uint *		; <uint *>	[#uses=1]
	%cond1046 = setge int 0, %reg109		; <bool>	[#uses=1]
	br bool %cond1046, label %bb8, label %bb5

bb5:					;[#uses=3]
	%reg161 = phi uint * [ %reg114, %bb7 ], [ null, %bb4 ]		; <uint *>	[#uses=1]
	%reg162 = phi int [ %reg166, %bb7 ], [ 0, %bb4 ]		; <int>	[#uses=2]
	%reg133 = sub int %reg109, %reg162		; <int>	[#uses=2]
	%cast1062 = cast int %reg133 to uint		; <uint>	[#uses=1]
	%cast1061 = cast int %reg133 to uint		; <uint>	[#uses=1]
	%reg135 = shl uint %cast1061, ubyte 1		; <uint>	[#uses=1]
	%reg136 = add uint %reg135, %cast1062		; <uint>	[#uses=1]
	%reg137 = shl uint %reg136, ubyte 3		; <uint>	[#uses=1]
	%cast139 = cast uint %reg137 to uint *		; <uint *>	[#uses=1]
	%reg140 = add uint * %cast115, %cast139		; <uint *>	[#uses=2]
	%cast1063 = cast long -24 to uint *		; <uint *>	[#uses=1]
	%reg114 = add uint * %reg140, %cast1063		; <uint *>	[#uses=4]
	%cast1069 = cast uint * %reg114 to uint * *		; <uint * *>	[#uses=1]
	%cast1067 = cast uint * %reg114 to { { uint, sbyte *, \2 } * *, int (uint) *, int } * *		; <{ { uint, sbyte *, \2 } * *, int (uint) *, int } * *>	[#uses=1]
	%cond1047 = setge int %numvert, 0		; <bool>	[#uses=1]
	br bool %cond1047, label %bb7, label %bb6

bb6:					;[#uses=2]
	%reg163 = add int %numvert, 3		; <int>	[#uses=1]
	br label %bb7

bb7:					;[#uses=5]
	%reg164 = phi int [ %reg163, %bb6 ], [ %numvert, %bb5 ]		; <int>	[#uses=1]
	%reg141 = shr int %reg164, ubyte 2		; <int>	[#uses=2]
	store int %reg141, int * %HashRange
	%cast1065 = cast long -24 to uint *		; <uint *>	[#uses=1]
	%reg1048 = add uint * %reg140, %cast1065		; <uint *>	[#uses=1]
	store uint 9999999, uint * %reg1048
	%reg147 = call { { uint, sbyte *, \2 } * *, int (uint) *, int } * (int, int (uint) *) * %MakeHash( int %reg141, int (uint) * %hashfunc )		; <{ { uint, sbyte *, \2 } * *, int (uint) *, int } *>	[#uses=1]
	%cast1066 = cast ulong 16 to { { uint, sbyte *, \2 } * *, int (uint) *, int } * *		; <{ { uint, sbyte *, \2 } * *, int (uint) *, int } * *>	[#uses=1]
	%reg1049 = add { { uint, sbyte *, \2 } * *, int (uint) *, int } * * %cast1067, %cast1066		; <{ { uint, sbyte *, \2 } * *, int (uint) *, int } * *>	[#uses=1]
	store { { uint, sbyte *, \2 } * *, int (uint) *, int } * %reg147, { { uint, sbyte *, \2 } * *, int (uint) *, int } * * %reg1049
	%cast1068 = cast ulong 8 to uint * *		; <uint * *>	[#uses=1]
	%reg1050 = add uint * * %cast1069, %cast1068		; <uint * *>	[#uses=1]
	store uint * %reg161, uint * * %reg1050
	%reg166 = add int %reg162, 1		; <int>	[#uses=2]
	%cond1051 = setlt int %reg166, %reg109		; <bool>	[#uses=1]
	br bool %cond1051, label %bb5, label %bb8

bb8:					;[#uses=3]
	%reg167 = phi uint * [ %reg114, %bb7 ], [ null, %bb4 ]		; <uint *>	[#uses=1]
	%reg149 = shl uint %cast1071, ubyte 3		; <uint>	[#uses=1]
	%cast150 = cast uint %reg149 to uint * *		; <uint * *>	[#uses=1]
	%reg152 = add uint * * %cast116, %cast150		; <uint * *>	[#uses=1]
	store uint * %reg167, uint * * %reg152
	%reg168 = add int %reg159, -1		; <int>	[#uses=2]
	%cond1052 = setge int %reg168, 0		; <bool>	[#uses=1]
	br bool %cond1052, label %bb4, label %bb9

bb9:					;[#uses=3]
	%cast1073 = cast [13 x sbyte] * %__intern_LC1 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *) * %puts( sbyte * %cast1073 )		; <int>:1	[#uses=0]
	%reg169 = add int %numproc, -1		; <int>	[#uses=2]
	%cond1053 = setlt int %reg169, 0		; <bool>	[#uses=1]
	br bool %cond1053, label %bb11, label %bb10

bb10:					;[#uses=3]
	%reg170 = phi int [ %reg171, %bb10 ], [ %reg169, %bb9 ]		; <int>	[#uses=3]
	%reg112 = mul int %reg170, %reg109		; <int>	[#uses=1]
	%cast1075 = cast int %reg118 to { [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } *		; <{ [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } *>	[#uses=1]
	call void (int, { [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } *, int, int, int, int) * %AddEdges( int %reg112, { [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } * %cast1075, int %numproc, int %reg109, int %numvert, int %reg170 )
	%reg171 = add int %reg170, -1		; <int>	[#uses=2]
	%cond1054 = setge int %reg171, 0		; <bool>	[#uses=1]
	br bool %cond1054, label %bb10, label %bb11

bb11:					;[#uses=2]
	%cast1078 = cast [13 x sbyte] * %__intern_LC2 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *) * %puts( sbyte * %cast1078 )		; <int>:2	[#uses=0]
	%cast1079 = cast [15 x sbyte] * %__intern_LC3 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *) * %puts( sbyte * %cast1079 )		; <int>:3	[#uses=0]
	%cast1080 = cast int %reg118 to { [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } *		; <{ [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } *>	[#uses=1]
	ret { [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } * %cast1080

bb12:					;[#uses=0]
	%cast1081 = cast ulong 42 to { [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } *		; <{ [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } *>	[#uses=1]
	ret { [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } * %cast1081
end

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

int "mult"(int %p, int %q)
begin
bb1:					;[#uses=0]
	%cast113 = cast int %p to ulong		; <ulong>	[#uses=1]
	%reg114 = mul ulong %cast113, 1759218605		; <ulong>	[#uses=1]
	%reg115 = shr ulong %reg114, ubyte 32		; <ulong>	[#uses=1]
	%cast1000 = cast ulong %reg115 to int		; <int>	[#uses=1]
	%reg116 = shr int %cast1000, ubyte 12		; <int>	[#uses=1]
	%reg117 = shr int %p, ubyte 31		; <int>	[#uses=1]
	%reg109 = sub int %reg116, %reg117		; <int>	[#uses=2]
	%reg123 = mul int %reg109, 10000		; <int>	[#uses=1]
	%reg110 = sub int %p, %reg123		; <int>	[#uses=2]
	%cast124 = cast int %q to ulong		; <ulong>	[#uses=1]
	%reg125 = mul ulong %cast124, 1759218605		; <ulong>	[#uses=1]
	%reg126 = shr ulong %reg125, ubyte 32		; <ulong>	[#uses=1]
	%cast1001 = cast ulong %reg126 to int		; <int>	[#uses=1]
	%reg127 = shr int %cast1001, ubyte 12		; <int>	[#uses=1]
	%reg128 = shr int %q, ubyte 31		; <int>	[#uses=1]
	%reg111 = sub int %reg127, %reg128		; <int>	[#uses=2]
	%reg134 = mul int %reg111, 10000		; <int>	[#uses=1]
	%reg112 = sub int %q, %reg134		; <int>	[#uses=2]
	%reg136 = mul int %reg110, %reg111		; <int>	[#uses=1]
	%reg137 = mul int %reg109, %reg112		; <int>	[#uses=1]
	%reg138 = add int %reg136, %reg137		; <int>	[#uses=3]
	%cast140 = cast int %reg138 to ulong		; <ulong>	[#uses=1]
	%reg141 = mul ulong %cast140, 1759218605		; <ulong>	[#uses=1]
	%reg142 = shr ulong %reg141, ubyte 32		; <ulong>	[#uses=1]
	%cast1002 = cast ulong %reg142 to int		; <int>	[#uses=1]
	%reg143 = shr int %cast1002, ubyte 12		; <int>	[#uses=1]
	%reg144 = shr int %reg138, ubyte 31		; <int>	[#uses=1]
	%reg139 = sub int %reg143, %reg144		; <int>	[#uses=1]
	%reg145 = mul int %reg139, 10000		; <int>	[#uses=1]
	%reg146 = sub int %reg138, %reg145		; <int>	[#uses=1]
	%reg147 = mul int %reg146, 10000		; <int>	[#uses=1]
	%reg148 = mul int %reg110, %reg112		; <int>	[#uses=1]
	%reg135 = add int %reg147, %reg148		; <int>	[#uses=1]
	ret int %reg135

bb2:					;[#uses=0]
	ret int 42
end

int "random"(int %seed)
begin
bb1:					;[#uses=0]
	%reg110 = call int (int, int) * %mult( int %seed, int 31415821 )		; <int>	[#uses=1]
	%reg108 = add int %reg110, 1		; <int>	[#uses=1]
	ret int %reg108

bb2:					;[#uses=0]
	ret int 42
end

int "compute_dist"(int %i, int %j, int %numvert)
begin
bb1:					;[#uses=0]
	%cond1003 = setge int %i, %j		; <bool>	[#uses=1]
	br bool %cond1003, label %bb3, label %bb2

bb2:					;[#uses=3]
	br label %bb4

bb3:					;[#uses=3]
	br label %bb4

bb4:					;[#uses=3]
	%reg124 = phi int [ %i, %bb3 ], [ %j, %bb2 ]		; <int>	[#uses=1]
	%reg125 = phi int [ %j, %bb3 ], [ %i, %bb2 ]		; <int>	[#uses=1]
	%reg113 = mul int %reg125, %numvert		; <int>	[#uses=1]
	%reg114 = add int %reg113, %reg124		; <int>	[#uses=1]
	%reg116 = call int (int) * %random( int %reg114 )		; <int>	[#uses=4]
	%cond1004 = setge int %reg116, 0		; <bool>	[#uses=1]
	br bool %cond1004, label %bb6, label %bb5

bb5:					;[#uses=2]
	%reg126 = add int %reg116, 2047		; <int>	[#uses=1]
	br label %bb6

bb6:					;[#uses=2]
	%reg127 = phi int [ %reg126, %bb5 ], [ %reg116, %bb4 ]		; <int>	[#uses=1]
	%reg117 = shr int %reg127, ubyte 11		; <int>	[#uses=1]
	%reg120 = shl int %reg117, ubyte 11		; <int>	[#uses=1]
	%reg121 = sub int %reg116, %reg120		; <int>	[#uses=1]
	%reg112 = add int %reg121, 1		; <int>	[#uses=1]
	ret int %reg112

bb7:					;[#uses=0]
	ret int 42
end

int "hashfunc"(uint %key)
begin
bb1:					;[#uses=0]
	%reg109 = shr uint %key, ubyte 3		; <uint>	[#uses=2]
	%reg116 = load int * %HashRange		; <int>	[#uses=2]
	%cast1008 = cast int %reg116 to uint		; <uint>	[#uses=1]
	%reg117 = div uint %reg109, %cast1008		; <uint>	[#uses=1]
	%cast1010 = cast int %reg116 to uint		; <uint>	[#uses=1]
	%reg119 = mul uint %reg117, %cast1010		; <uint>	[#uses=1]
	%reg108 = sub uint %reg109, %reg119		; <uint>	[#uses=1]
	%cast1009 = cast uint %reg108 to int		; <int>	[#uses=1]
	ret int %cast1009

bb2:					;[#uses=0]
	ret int 42
end

void "AddEdges"(int %count1, { [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } * %retval, int %numproc, int %perproc, int %numvert, int %j)
begin
bb0:					;[#uses=0]
	%helper = alloca [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *]		; <[1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] *>	[#uses=1]
	%cast1011 = cast [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] * %helper to { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * *		; <{ int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * *>	[#uses=2]
	br label %bb1

bb1:					;[#uses=2]
	%cond1012 = setge int 0, %numproc		; <bool>	[#uses=1]
	br bool %cond1012, label %bb3, label %bb2

bb2:					;[#uses=3]
	%reg162 = phi int [ %reg163, %bb2 ], [ 0, %bb1 ]		; <int>	[#uses=2]
	%cast1022 = cast int %reg162 to uint		; <uint>	[#uses=1]
	%reg118 = shl uint %cast1022, ubyte 3		; <uint>	[#uses=2]
	%cast119 = cast uint %reg118 to { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * *		; <{ int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * *>	[#uses=1]
	%reg121 = add { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * * %cast119, %cast1011		; <{ int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * *>	[#uses=1]
	%cast1040 = cast uint %reg118 to { [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } *		; <{ [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } *>	[#uses=1]
	%reg126 = add { [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } * %retval, %cast1040		; <{ [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } *>	[#uses=1]
	%cast1023 = cast { [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } * %reg126 to ulong * *		; <ulong * *>	[#uses=1]
	%reg127 = load ulong * * %cast1023		; <ulong *>	[#uses=1]
	%cast1041 = cast { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * * %reg121 to ulong * *		; <ulong * *>	[#uses=1]
	store ulong * %reg127, ulong * * %cast1041
	%reg163 = add int %reg162, 1		; <int>	[#uses=2]
	%cond1013 = setlt int %reg163, %numproc		; <bool>	[#uses=1]
	br bool %cond1013, label %bb2, label %bb3

bb3:					;[#uses=4]
	%reg129 = shl int %j, ubyte 3		; <int>	[#uses=1]
	%cast130 = cast int %reg129 to { [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } *		; <{ [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } *>	[#uses=1]
	%reg132 = add { [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } * %retval, %cast130		; <{ [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } *>	[#uses=1]
	%cast1026 = cast { [1 x { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *] } * %reg132 to ulong * *		; <ulong * *>	[#uses=1]
	%reg113 = load ulong * * %cast1026		; <ulong *>	[#uses=2]
	%cond1014 = seteq ulong * %reg113, null		; <bool>	[#uses=1]
	br bool %cond1014, label %bb9, label %bb4

bb4:					;[#uses=3]
	%reg164 = phi ulong * [ %reg170, %bb8 ], [ %reg113, %bb3 ]		; <ulong *>	[#uses=2]
	%cast1038 = cast ulong * %reg164 to ulong * *		; <ulong * *>	[#uses=1]
	%cast1035 = cast ulong * %reg164 to { { uint, sbyte *, \2 } * *, int (uint) *, int } * *		; <{ { uint, sbyte *, \2 } * *, int (uint) *, int } * *>	[#uses=1]
	%reg165 = phi int [ %reg169, %bb8 ], [ %count1, %bb3 ]		; <int>	[#uses=3]
	%reg159 = mul int %numproc, %perproc		; <int>	[#uses=1]
	%cond1015 = setge int 0, %reg159		; <bool>	[#uses=1]
	br bool %cond1015, label %bb8, label %bb5

bb5:					;[#uses=2]
	%reg167 = phi int [ %reg168, %bb7 ], [ 0, %bb4 ]		; <int>	[#uses=5]
	%cast1032 = cast int %reg167 to uint		; <uint>	[#uses=1]
	%cond1016 = seteq int %reg167, %reg165		; <bool>	[#uses=1]
	br bool %cond1016, label %bb7, label %bb6

bb6:					;[#uses=1]
	%reg139 = call int (int, int, int) * %compute_dist( int %reg167, int %reg165, int %numvert )		; <int>	[#uses=1]
	%reg134 = div int %reg167, %perproc		; <int>	[#uses=2]
	%cast1031 = cast int %reg134 to uint		; <uint>	[#uses=1]
	%reg143 = mul int %reg134, %perproc		; <int>	[#uses=1]
	%cast1033 = cast int %reg143 to uint		; <uint>	[#uses=1]
	%reg135 = sub uint %cast1032, %cast1033		; <uint>	[#uses=2]
	%reg145 = shl uint %cast1031, ubyte 3		; <uint>	[#uses=1]
	%cast146 = cast uint %reg145 to { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * *		; <{ int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * *>	[#uses=1]
	%reg148 = add { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * * %cast146, %cast1011		; <{ int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * *>	[#uses=1]
	%reg150 = shl uint %reg135, ubyte 1		; <uint>	[#uses=1]
	%reg151 = add uint %reg150, %reg135		; <uint>	[#uses=1]
	%reg152 = shl uint %reg151, ubyte 3		; <uint>	[#uses=1]
	%cast154 = cast uint %reg152 to { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *		; <{ int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *>	[#uses=1]
	%reg155 = load { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * * %reg148		; <{ int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *>	[#uses=1]
	%reg137 = add { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %reg155, %cast154		; <{ int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } *>	[#uses=1]
	%cast1034 = cast ulong 16 to { { uint, sbyte *, \2 } * *, int (uint) *, int } * *		; <{ { uint, sbyte *, \2 } * *, int (uint) *, int } * *>	[#uses=1]
	%reg1017 = add { { uint, sbyte *, \2 } * *, int (uint) *, int } * * %cast1035, %cast1034		; <{ { uint, sbyte *, \2 } * *, int (uint) *, int } * *>	[#uses=1]
	%reg138 = load { { uint, sbyte *, \2 } * *, int (uint) *, int } * * %reg1017		; <{ { uint, sbyte *, \2 } * *, int (uint) *, int } *>	[#uses=1]
	%cast157 = cast int %reg139 to sbyte *		; <sbyte *>	[#uses=1]
	%cast1021 = cast { int, \2, { { uint, sbyte *, \2 } * *, int (uint) *, int } * } * %reg137 to uint		; <uint>	[#uses=1]
	call void (sbyte *, uint, { { uint, sbyte *, \2 } * *, int (uint) *, int } *) * %HashInsert( sbyte * %cast157, uint %cast1021, { { uint, sbyte *, \2 } * *, int (uint) *, int } * %reg138 )
	br label %bb7

bb7:					;[#uses=3]
	%reg168 = add int %reg167, 1		; <int>	[#uses=2]
	%reg133 = mul int %numproc, %perproc		; <int>	[#uses=1]
	%cond1018 = setlt int %reg168, %reg133		; <bool>	[#uses=1]
	br bool %cond1018, label %bb5, label %bb8

bb8:					;[#uses=4]
	%reg169 = add int %reg165, 1		; <int>	[#uses=1]
	%cast1037 = cast ulong 8 to ulong * *		; <ulong * *>	[#uses=1]
	%reg1019 = add ulong * * %cast1038, %cast1037		; <ulong * *>	[#uses=1]
	%reg170 = load ulong * * %reg1019		; <ulong *>	[#uses=2]
	%cond1020 = setne ulong * %reg170, null		; <bool>	[#uses=1]
	br bool %cond1020, label %bb4, label %bb9

bb9:					;[#uses=2]
	ret void
end

declare int "malloc"(...)
