	%_Bool = type bool
	%__builtin_ptrdiff_t = type int
	%__builtin_size_t = type uint
	%__builtin_va_list = type sbyte *
	%__g77_integer = type int
	%__g77_longint = type long
	%__g77_uinteger = type uint
	%__g77_ulongint = type ulong
	%char = type sbyte
	%complex.double = type { double, double }
	%complex.float = type { float, float }
	%complex.int = type { int, int }
	%complex.long.double = type { double, double }
	%double = type double
	%float = type float
	%int = type int
	%long.double = type double
	%long.int = type int
	%long.long.int = type long
	%long.long.unsigned.int = type ulong
	%long.unsigned.int = type uint
	%short.int = type short
	%short.unsigned.int = type ushort
	%signed.char = type sbyte
	%unsigned.char = type ubyte
	%unsigned.int = type uint
	%void = type void
%NumNodes = uninitialized global int		; <int *>	[#uses=2]
%nbody = uninitialized global int		; <int *>	[#uses=2]
implementation

declare void "__main"()

declare int "atoi"(...)

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

declare int "putchar"(int)

declare int "puts"(sbyte *)

declare int "printf"(sbyte *, ...)

declare int "fprintf"(sbyte *, sbyte *, ...)

declare uint "fwrite"(sbyte *, uint, uint, sbyte *)

declare int "fputc"(int, sbyte *)

declare int "fputs"(sbyte *, sbyte *)

declare int "fputs"(...)

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

int "dealwithargs"(int %argc, sbyte * * %argv)
begin
bb1:					;[#uses=0]
	%cond1000 = setle int %argc, 2		; <bool>	[#uses=1]
	br bool %cond1000, label %bb3, label %bb2

bb2:					;[#uses=1]
	%cast1004 = cast ulong 16 to sbyte * *		; <sbyte * *>	[#uses=1]
	%reg1001 = add sbyte * * %argv, %cast1004		; <sbyte * *>	[#uses=1]
	%reg110 = load sbyte * * %reg1001		; <sbyte *>	[#uses=1]
	%reg111 = call int (...) * %atoi( sbyte * %reg110 )		; <int>	[#uses=1]
	store int %reg111, int * %NumNodes
	br label %bb4

bb3:					;[#uses=1]
	store int 4, int * %NumNodes
	br label %bb4

bb4:					;[#uses=2]
	%cond1002 = setle int %argc, 1		; <bool>	[#uses=1]
	br bool %cond1002, label %bb6, label %bb5

bb5:					;[#uses=1]
	%cast1005 = cast ulong 8 to sbyte * *		; <sbyte * *>	[#uses=1]
	%reg1003 = add sbyte * * %argv, %cast1005		; <sbyte * *>	[#uses=1]
	%reg113 = load sbyte * * %reg1003		; <sbyte *>	[#uses=1]
	%reg114 = call int (...) * %atoi( sbyte * %reg113 )		; <int>	[#uses=1]
	store int %reg114, int * %nbody
	br label %bb7

bb6:					;[#uses=1]
	store int 2048, int * %nbody
	br label %bb7

bb7:					;[#uses=2]
	ret int 42

bb8:					;[#uses=0]
	ret int 42
end
