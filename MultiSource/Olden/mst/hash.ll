	%FILE = type { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint }
	%Hash = type { { uint, sbyte *, \2 } * *, int (uint) *, int } *
	%HashEntry = type { uint, sbyte *, \2 } *
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
	%void = type void
%__iob = uninitialized global [20 x { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint }]		; <[20 x { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint }] *>	[#uses=0]
%_sibuf = uninitialized global [ubyte]		; <[ubyte] *>	[#uses=0]
%_sobuf = uninitialized global [ubyte]		; <[ubyte] *>	[#uses=0]
%_bufendtab = uninitialized global [ubyte *]		; <[ubyte *] *>	[#uses=0]
%_lastbuf = uninitialized global { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *		; <{ int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } * *>	[#uses=0]
%remaining = global int 0		; <int *>	[#uses=4]
%temp = uninitialized global sbyte *		; <sbyte * *>	[#uses=3]
%__intern_LC0 = global [27 x sbyte] c"Error! malloc returns null\00"		; <[27 x sbyte] *>	[#uses=1]
%__intern_LC1 = global [30 x sbyte] c"Assertion failure:%d in hash\0A\00"		; <[30 x sbyte] *>	[#uses=4]
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

{ { uint, sbyte *, \2 } * *, int (uint) *, int } * "MakeHash"(int %size, int (uint) * %map)
begin
bb1:					;[#uses=1]
	%cast1009 = cast ulong 24 to int		; <int>	[#uses=1]
	%reg109 = call sbyte * (int) * %localmalloc( int %cast1009 )		; <sbyte *>	[#uses=5]
	%reg113 = shl int %size, ubyte 3		; <int>	[#uses=1]
	%reg114 = call sbyte * (int) * %localmalloc( int %reg113 )		; <sbyte *>	[#uses=1]
	%cast1015 = cast sbyte * %reg109 to sbyte * *		; <sbyte * *>	[#uses=1]
	store sbyte * %reg114, sbyte * * %cast1015
	%cond1010 = setge int 0, %size		; <bool>	[#uses=1]
	br bool %cond1010, label %bb3, label %bb2

bb2:					;[#uses=3]
	%reg123 = phi int [ %reg124, %bb2 ], [ 0, %bb1 ]		; <int>	[#uses=2]
	%cast1016 = cast int %reg123 to uint		; <uint>	[#uses=1]
	%reg116 = shl uint %cast1016, ubyte 3		; <uint>	[#uses=1]
	%cast118 = cast uint %reg116 to ulong * *		; <ulong * *>	[#uses=1]
	%cast1017 = cast sbyte * %reg109 to ulong * * *		; <ulong * * *>	[#uses=1]
	%reg119 = load ulong * * * %cast1017		; <ulong * *>	[#uses=1]
	%reg120 = add ulong * * %reg119, %cast118		; <ulong * *>	[#uses=1]
	store ulong * null, ulong * * %reg120
	%reg124 = add int %reg123, 1		; <int>	[#uses=2]
	%cond1011 = setlt int %reg124, %size		; <bool>	[#uses=1]
	br bool %cond1011, label %bb2, label %bb3

bb3:					;[#uses=2]
	%cast1019 = cast ulong 8 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1012 = add sbyte * %reg109, %cast1019		; <sbyte *>	[#uses=1]
	%cast1020 = cast sbyte * %reg1012 to int (uint) * *		; <int (uint) * *>	[#uses=1]
	store int (uint) * %map, int (uint) * * %cast1020
	%cast1021 = cast ulong 16 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1013 = add sbyte * %reg109, %cast1021		; <sbyte *>	[#uses=1]
	%cast1022 = cast sbyte * %reg1013 to int *		; <int *>	[#uses=1]
	store int %size, int * %cast1022
	%cast1023 = cast sbyte * %reg109 to { { uint, sbyte *, \2 } * *, int (uint) *, int } *		; <{ { uint, sbyte *, \2 } * *, int (uint) *, int } *>	[#uses=1]
	ret { { uint, sbyte *, \2 } * *, int (uint) *, int } * %cast1023

bb4:					;[#uses=0]
	%cast1024 = cast ulong 42 to { { uint, sbyte *, \2 } * *, int (uint) *, int } *		; <{ { uint, sbyte *, \2 } * *, int (uint) *, int } *>	[#uses=1]
	ret { { uint, sbyte *, \2 } * *, int (uint) *, int } * %cast1024
end

sbyte * "HashLookup"(uint %key, { { uint, sbyte *, \2 } * *, int (uint) *, int } * %hash)
begin
bb1:					;[#uses=0]
	%reg111 = load { { uint, sbyte *, \2 } * *, int (uint) *, int } * %hash, ubyte 1		; <int (uint) *>	[#uses=1]
	%cast111 = cast int (uint) * %reg111 to int (...) *		; <int (...) *>	[#uses=1]
	%reg109 = call int (...) * %cast111( uint %key )		; <int>	[#uses=3]
	%cond1026 = setge int %reg109, 0		; <bool>	[#uses=1]
	br bool %cond1026, label %bb3, label %bb2

bb2:					;[#uses=1]
	%cast1027 = cast ulong 1 to uint		; <uint>	[#uses=1]
	%cast1042 = cast [30 x sbyte] * %__intern_LC1 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast1042, uint %cast1027 )		; <int>:0	[#uses=0]
	%cast1028 = cast long -1 to uint		; <uint>	[#uses=1]
	call void (...) * %exit( uint %cast1028 )
	br label %bb3

bb3:					;[#uses=2]
	%reg115 = load { { uint, sbyte *, \2 } * *, int (uint) *, int } * %hash, ubyte 2		; <int>	[#uses=1]
	%cond1030 = setlt int %reg109, %reg115		; <bool>	[#uses=1]
	br bool %cond1030, label %bb5, label %bb4

bb4:					;[#uses=1]
	%cast1031 = cast ulong 2 to uint		; <uint>	[#uses=1]
	%cast1045 = cast [30 x sbyte] * %__intern_LC1 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast1045, uint %cast1031 )		; <int>:1	[#uses=0]
	%cast1032 = cast long -1 to uint		; <uint>	[#uses=1]
	call void (...) * %exit( uint %cast1032 )
	br label %bb5

bb5:					;[#uses=3]
	%reg120 = shl int %reg109, ubyte 3		; <int>	[#uses=1]
	%cast122 = cast int %reg120 to uint * *		; <uint * *>	[#uses=1]
	%reg123 = load { { uint, sbyte *, \2 } * *, int (uint) *, int } * %hash, ubyte 0		; <{ uint, sbyte *, \2 } * *>	[#uses=1]
	%cast123 = cast { uint, sbyte *, \2 } * * %reg123 to uint * *		; <uint * *>	[#uses=1]
	%reg124 = add uint * * %cast123, %cast122		; <uint * *>	[#uses=1]
	%reg110 = load uint * * %reg124		; <uint *>	[#uses=5]
	%cond1033 = seteq uint * %reg110, null		; <bool>	[#uses=1]
	br bool %cond1033, label %bb9, label %bb6

bb6:					;[#uses=3]
	%reg130 = load uint * %reg110		; <uint>	[#uses=1]
	%cond1034 = seteq uint %reg130, %key		; <bool>	[#uses=1]
	br bool %cond1034, label %bb9, label %bb7

bb7:					;[#uses=3]
	%reg131 = phi uint * [ %reg132, %bb8 ], [ %reg110, %bb6 ]		; <uint *>	[#uses=1]
	%cast1050 = cast uint * %reg131 to uint * *		; <uint * *>	[#uses=1]
	%cast1049 = cast ulong 16 to uint * *		; <uint * *>	[#uses=1]
	%reg1035 = add uint * * %cast1050, %cast1049		; <uint * *>	[#uses=1]
	%reg132 = load uint * * %reg1035		; <uint *>	[#uses=5]
	%cond1036 = seteq uint * %reg132, null		; <bool>	[#uses=1]
	br bool %cond1036, label %bb9, label %bb8

bb8:					;[#uses=3]
	%reg125 = load uint * %reg132		; <uint>	[#uses=1]
	%cond1037 = setne uint %reg125, %key		; <bool>	[#uses=1]
	br bool %cond1037, label %bb7, label %bb9

bb9:					;[#uses=4]
	%reg133 = phi uint * [ %reg132, %bb8 ], [ %reg132, %bb7 ], [ %reg110, %bb6 ], [ %reg110, %bb5 ]		; <uint *>	[#uses=2]
	%cast1054 = cast uint * %reg133 to sbyte * *		; <sbyte * *>	[#uses=1]
	%cond1038 = seteq uint * %reg133, null		; <bool>	[#uses=1]
	br bool %cond1038, label %bb11, label %bb10

bb10:					;[#uses=1]
	%cast1053 = cast ulong 8 to sbyte * *		; <sbyte * *>	[#uses=1]
	%reg1039 = add sbyte * * %cast1054, %cast1053		; <sbyte * *>	[#uses=1]
	%reg127 = load sbyte * * %reg1039		; <sbyte *>	[#uses=1]
	ret sbyte * %reg127

bb11:					;[#uses=1]
	ret sbyte * null

bb12:					;[#uses=0]
	%cast1056 = cast ulong 42 to sbyte *		; <sbyte *>	[#uses=1]
	ret sbyte * %cast1056
end

void "HashInsert"(sbyte * %entry, uint %key, { { uint, sbyte *, \2 } * *, int (uint) *, int } * %hash)
begin
bb1:					;[#uses=0]
	%reg112 = call sbyte * (uint, { { uint, sbyte *, \2 } * *, int (uint) *, int } *) * %HashLookup( uint %key, { { uint, sbyte *, \2 } * *, int (uint) *, int } * %hash )		; <sbyte *>	[#uses=1]
	%cond1061 = seteq sbyte * %reg112, null		; <bool>	[#uses=1]
	br bool %cond1061, label %bb3, label %bb2

bb2:					;[#uses=1]
	%cast1062 = cast ulong 3 to uint		; <uint>	[#uses=1]
	%cast1069 = cast [30 x sbyte] * %__intern_LC1 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast1069, uint %cast1062 )		; <int>:0	[#uses=0]
	%cast1063 = cast long -1 to uint		; <uint>	[#uses=1]
	call void (...) * %exit( uint %cast1063 )
	br label %bb3

bb3:					;[#uses=2]
	%reg116 = load { { uint, sbyte *, \2 } * *, int (uint) *, int } * %hash, ubyte 1		; <int (uint) *>	[#uses=1]
	%cast116 = cast int (uint) * %reg116 to uint (...) *		; <uint (...) *>	[#uses=1]
	%reg111 = call uint (...) * %cast116( uint %key )		; <uint>	[#uses=1]
	%cast1065 = cast ulong 24 to int		; <int>	[#uses=1]
	%reg110 = call sbyte * (int) * %localmalloc( int %cast1065 )		; <sbyte *>	[#uses=4]
	%reg119 = shl uint %reg111, ubyte 3		; <uint>	[#uses=1]
	%cast121 = cast uint %reg119 to sbyte * *		; <sbyte * *>	[#uses=1]
	%reg122 = load { { uint, sbyte *, \2 } * *, int (uint) *, int } * %hash, ubyte 0		; <{ uint, sbyte *, \2 } * *>	[#uses=1]
	%cast122 = cast { uint, sbyte *, \2 } * * %reg122 to sbyte * *		; <sbyte * *>	[#uses=1]
	%reg123 = add sbyte * * %cast122, %cast121		; <sbyte * *>	[#uses=2]
	%reg124 = load sbyte * * %reg123		; <sbyte *>	[#uses=1]
	%cast1073 = cast ulong 16 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1066 = add sbyte * %reg110, %cast1073		; <sbyte *>	[#uses=1]
	%cast1074 = cast sbyte * %reg1066 to sbyte * *		; <sbyte * *>	[#uses=1]
	store sbyte * %reg124, sbyte * * %cast1074
	store sbyte * %reg110, sbyte * * %reg123
	%cast1075 = cast sbyte * %reg110 to uint *		; <uint *>	[#uses=1]
	store uint %key, uint * %cast1075
	%cast1076 = cast ulong 8 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1067 = add sbyte * %reg110, %cast1076		; <sbyte *>	[#uses=1]
	%cast1077 = cast sbyte * %reg1067 to sbyte * *		; <sbyte * *>	[#uses=1]
	store sbyte * %entry, sbyte * * %cast1077
	ret void
end

void "HashDelete"(uint %key, { { uint, sbyte *, \2 } * *, int (uint) *, int } * %hash)
begin
bb1:					;[#uses=1]
	%reg112 = load { { uint, sbyte *, \2 } * *, int (uint) *, int } * %hash, ubyte 1		; <int (uint) *>	[#uses=1]
	%cast112 = cast int (uint) * %reg112 to uint (...) *		; <uint (...) *>	[#uses=1]
	%reg111 = call uint (...) * %cast112( uint %key )		; <uint>	[#uses=1]
	%reg114 = shl uint %reg111, ubyte 3		; <uint>	[#uses=1]
	%cast116 = cast uint %reg114 to uint * *		; <uint * *>	[#uses=1]
	%reg117 = load { { uint, sbyte *, \2 } * *, int (uint) *, int } * %hash, ubyte 0		; <{ uint, sbyte *, \2 } * *>	[#uses=1]
	%cast117 = cast { uint, sbyte *, \2 } * * %reg117 to uint * *		; <uint * *>	[#uses=1]
	%reg109 = add uint * * %cast117, %cast116		; <uint * *>	[#uses=4]
	%reg128 = load uint * * %reg109		; <uint *>	[#uses=2]
	%cond1082 = seteq uint * %reg128, null		; <bool>	[#uses=1]
	br bool %cond1082, label %bb5, label %bb2

bb2:					;[#uses=3]
	%reg130 = load uint * %reg128		; <uint>	[#uses=1]
	%cond1083 = seteq uint %reg130, %key		; <bool>	[#uses=1]
	br bool %cond1083, label %bb5, label %bb3

bb3:					;[#uses=3]
	%reg131 = phi uint * * [ %reg132, %bb4 ], [ %reg109, %bb2 ]		; <uint * *>	[#uses=1]
	%cast1095 = cast uint * * %reg131 to uint * * *		; <uint * * *>	[#uses=1]
	%reg121 = load uint * * * %cast1095		; <uint * *>	[#uses=2]
	%cast1096 = cast ulong 16 to uint * *		; <uint * *>	[#uses=1]
	%reg132 = add uint * * %reg121, %cast1096		; <uint * *>	[#uses=3]
	%cast1097 = cast ulong 16 to uint * *		; <uint * *>	[#uses=1]
	%reg1084 = add uint * * %reg121, %cast1097		; <uint * *>	[#uses=1]
	%reg118 = load uint * * %reg1084		; <uint *>	[#uses=2]
	%cond1085 = seteq uint * %reg118, null		; <bool>	[#uses=1]
	br bool %cond1085, label %bb5, label %bb4

bb4:					;[#uses=3]
	%reg120 = load uint * %reg118		; <uint>	[#uses=1]
	%cond1086 = setne uint %reg120, %key		; <bool>	[#uses=1]
	br bool %cond1086, label %bb3, label %bb5

bb5:					;[#uses=4]
	%reg133 = phi uint * * [ %reg132, %bb4 ], [ %reg132, %bb3 ], [ %reg109, %bb2 ], [ %reg109, %bb1 ]		; <uint * *>	[#uses=2]
	%cast1103 = cast uint * * %reg133 to ulong * *		; <ulong * *>	[#uses=1]
	%cast1099 = cast uint * * %reg133 to ulong * * *		; <ulong * * *>	[#uses=1]
	%reg122 = load ulong * * * %cast1099		; <ulong * *>	[#uses=2]
	%cond1087 = setne ulong * * %reg122, null		; <bool>	[#uses=1]
	br bool %cond1087, label %bb7, label %bb6

bb6:					;[#uses=1]
	%cast1088 = cast ulong 4 to uint		; <uint>	[#uses=1]
	%cast1101 = cast [30 x sbyte] * %__intern_LC1 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast1101, uint %cast1088 )		; <int>:0	[#uses=0]
	%cast1089 = cast long -1 to uint		; <uint>	[#uses=1]
	call void (...) * %exit( uint %cast1089 )
	br label %bb7

bb7:					;[#uses=2]
	%cast1102 = cast ulong 16 to ulong * *		; <ulong * *>	[#uses=1]
	%reg1090 = add ulong * * %reg122, %cast1102		; <ulong * *>	[#uses=1]
	%reg127 = load ulong * * %reg1090		; <ulong *>	[#uses=1]
	store ulong * %reg127, ulong * * %cast1103
	ret void
end

declare int "malloc"(...)

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

sbyte * "localmalloc"(int %size)
begin
bb1:					;[#uses=0]
	%reg109 = load int * %remaining		; <int>	[#uses=1]
	%cond1000 = setle int %size, %reg109		; <bool>	[#uses=1]
	br bool %cond1000, label %bb5, label %bb2

bb2:					;[#uses=1]
	%reg111 = call int (...) * %malloc( int 32768 )		; <int>	[#uses=2]
	%cast113 = cast int %reg111 to ulong *		; <ulong *>	[#uses=1]
	%cast1008 = cast int %reg111 to sbyte *		; <sbyte *>	[#uses=1]
	store sbyte * %cast1008, sbyte * * %temp
	%cond1001 = setne ulong * %cast113, null		; <bool>	[#uses=1]
	br bool %cond1001, label %bb4, label %bb3

bb3:					;[#uses=1]
	%cast1003 = cast [27 x sbyte] * %__intern_LC0 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *) * %puts( sbyte * %cast1003 )		; <int>:0	[#uses=0]
	br label %bb4

bb4:					;[#uses=2]
	store int 32768, int * %remaining
	br label %bb5

bb5:					;[#uses=2]
	%reg108 = load sbyte * * %temp		; <sbyte *>	[#uses=2]
	%cast118 = cast int %size to sbyte *		; <sbyte *>	[#uses=1]
	%reg120 = add sbyte * %reg108, %cast118		; <sbyte *>	[#uses=1]
	store sbyte * %reg120, sbyte * * %temp
	%reg121 = load int * %remaining		; <int>	[#uses=1]
	%reg122 = sub int %reg121, %size		; <int>	[#uses=1]
	store int %reg122, int * %remaining
	ret sbyte * %reg108

bb6:					;[#uses=0]
	%cast1005 = cast ulong 42 to sbyte *		; <sbyte *>	[#uses=1]
	ret sbyte * %cast1005
end
