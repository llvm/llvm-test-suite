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
	%bnode = type { short, double, [3 x double], int, int, [3 x double], [3 x double], [3 x double], double, \2 *, \2 * }
	%body = type { short, double, [3 x double], int, int, [3 x double], [3 x double], [3 x double], double, \2 *, \2 * }
	%bodyptr = type { short, double, [3 x double], int, int, [3 x double], [3 x double], [3 x double], double, \2, \2 } *
	%bool = type short
	%byte = type ubyte
	%cell = type { short, double, [3 x double], int, int, [8 x { short, double, [3 x double], int, int } *], \2 * }
	%cellptr = type { short, double, [3 x double], int, int, [8 x { short, double, [3 x double], int, int } *], \2 } *
	%char = type sbyte
	%cnode = type { short, double, [3 x double], int, int, [8 x { short, double, [3 x double], int, int } *], \2 * }
	%complex.double = type { double, double }
	%complex.float = type { float, float }
	%complex.int = type { int, int }
	%complex.long.double = type { double, double }
	%datapoints = type { [3 x double], [3 x double], { short, double, [3 x double], int, int, [3 x double], [3 x double], [3 x double], double, \2, \2 } *, { short, double, [3 x double], int, int, [3 x double], [3 x double], [3 x double], double, \2, \2 } * }
	%double = type double
	%dt1struct = type { { short, double, [3 x double], int, int } *, int, int }
	%dt3_struct = type { int, int, { short, double, [3 x double], int, int, [8 x { short, double, [3 x double], int, int } *], \2 } *, [8 x { short, double, [3 x double], int, int } *] }
	%dtstruct = type { { short, double, [3 x double], int, int } *, int }
	%fc_datapoints = type { { [3 x double], [3 x double], { short, double, [3 x double], int, int, [3 x double], [3 x double], [3 x double], double, \2, \2 } *, { short, double, [3 x double], int, int, [3 x double], [3 x double], [3 x double], double, \2, \2 } * } }
	%float = type float
	%fpos_t = type int
	%future_cell_datapoints = type { { [3 x double], [3 x double], { short, double, [3 x double], int, int, [3 x double], [3 x double], [3 x double], double, \2, \2 } *, { short, double, [3 x double], int, int, [3 x double], [3 x double], [3 x double], double, \2, \2 } * } }
	%hgsptr = type { { short, double, [3 x double], int, int, [3 x double], [3 x double], [3 x double], double, \2, \2 } *, [3 x double], double, [3 x double] } *
	%hgstruct = type { { short, double, [3 x double], int, int, [3 x double], [3 x double], [3 x double], double, \2, \2 } *, [3 x double], double, [3 x double] }
	%icstruct = type { [3 x int], short }
	%int = type int
	%iproc = type int (...) *
	%long.double = type double
	%long.int = type int
	%long.long.int = type long
	%long.long.unsigned.int = type ulong
	%long.unsigned.int = type uint
	%matrix = type [3 x [3 x double]]
	%node = type { short, double, [3 x double], int, int }
	%nodeptr = type { short, double, [3 x double], int, int } *
	%ostruct = type { double, [3 x double], [3 x [3 x double]], [3 x [3 x double]], [2 x [3 x double]], [3 x double] }
	%proc = type void (...) *
	%real = type double
	%realptr = type double *
	%rproc = type double (...) *
	%short.int = type short
	%short.unsigned.int = type ushort
	%signed.char = type sbyte
	%size_t = type uint
	%ssize_t = type int
	%stream = type { int, ubyte *, ubyte *, ubyte, ubyte, uint, uint, uint } *
	%string = type sbyte *
	%timeptr = type { double, double, int } *
	%timerecord = type { double, double, int }
	%tree = type { [3 x double], double, { short, double, [3 x double], int, int } *, [64 x { short, double, [3 x double], int, int, [3 x double], [3 x double], [3 x double], double, \2, \2 } *], [64 x { short, double, [3 x double], int, int, [3 x double], [3 x double], [3 x double], double, \2, \2 } *] }
	%treeptr = type { [3 x double], double, { short, double, [3 x double], int, int } *, [64 x { short, double, [3 x double], int, int, [3 x double], [3 x double], [3 x double], double, \2, \2 } *], [64 x { short, double, [3 x double], int, int, [3 x double], [3 x double], [3 x double], double, \2, \2 } *] } *
	%unsigned.char = type ubyte
	%unsigned.int = type uint
	%vecstruct = type { [3 x double] }
	%vector = type [3 x double]
	%void = type void
%__iob = uninitialized global [20 x %FILE]		; <[20 x %FILE] *>	[#uses=0]
%_sibuf = uninitialized global [ubyte]		; <[ubyte] *>	[#uses=0]
%_sobuf = uninitialized global [ubyte]		; <[ubyte] *>	[#uses=0]
%_bufendtab = uninitialized global [ubyte *]		; <[ubyte *] *>	[#uses=0]
%_lastbuf = uninitialized global %stream		; <%stream *>	[#uses=0]
%NumNodes = uninitialized global int		; <int *>	[#uses=8]
%root = uninitialized global %nodeptr		; <%nodeptr *>	[#uses=0]
%rmin = uninitialized global %vector		; <%vector *>	[#uses=0]
%rsize = uninitialized global double		; <double *>	[#uses=0]
%nbody = uninitialized global int		; <int *>	[#uses=7]
%exp = uninitialized global double		; <double *>	[#uses=0]
%log = uninitialized global double		; <double *>	[#uses=0]
%BhDebug = uninitialized global int		; <int *>	[#uses=0]
%arg1 = uninitialized global int		; <int *>	[#uses=0]
%__intern_LC0 = global [27 x sbyte] c"nbody = %d, numnodes = %d\0A\00"		; <[27 x sbyte] *>	[#uses=1]
%__intern_LC1 = global [16 x sbyte] c"bodies created \00"		; <[16 x sbyte] *>	[#uses=1]
%__intern_LC2 = global [20 x sbyte] c"Bodies per %d = %d\0A\00"		; <[20 x sbyte] *>	[#uses=1]
%__intern_LC3 = global double 0.012500		; <double *>	[#uses=0]
global double 0.012500		; <double *>:0	[#uses=0]
%__intern_LC4 = global double 2.001250		; <double *>	[#uses=0]
global double 2.001250		; <double *>:1	[#uses=0]
%__intern_LC5 = global [22 x sbyte] c"Assertion Failure #%d\00"		; <[22 x sbyte] *>	[#uses=19]
%EventCount = uninitialized global int		; <int *>	[#uses=0]
%cp_free_list = global %nodeptr null		; <%nodeptr *>	[#uses=4]
%bp_free_list = global %bodyptr null		; <%bodyptr *>	[#uses=2]
%__intern_LC6 = global [29 x sbyte] c"testdata: not enough memory\0A\00"		; <[29 x sbyte] *>	[#uses=1]
%__intern_LC7 = global double 1.000000		; <double *>	[#uses=0]
global double 1.000000		; <double *>:2	[#uses=0]
%__intern_LC8 = global double 4.000000		; <double *>	[#uses=0]
global double 4.000000		; <double *>:3	[#uses=0]
%ctab = global %cellptr null		; <%cellptr *>	[#uses=0]
%maxcell = uninitialized global int		; <int *>	[#uses=0]
%__intern_LC9 = global double 0.000000		; <double *>	[#uses=0]
global double 0.000000		; <double *>:4	[#uses=0]
%__intern_LC10 = global double 0.000000		; <double *>	[#uses=0]
global double 0.000000		; <double *>:5	[#uses=0]
%__intern_LC11 = global double 1.000000		; <double *>	[#uses=0]
global double 1.000000		; <double *>:6	[#uses=0]
%__intern_LC12 = global double 1073741824.000000		; <double *>	[#uses=0]
global double 1073741824.000000		; <double *>:7	[#uses=0]
%__intern_LC14 = global [24 x sbyte] c"%2d CELL@%x %f, %f, %f\0A\00"		; <[24 x sbyte] *>	[#uses=1]
%__intern_LC13 = global [24 x sbyte] c"%2d BODY@%x %f, %f, %f\0A\00"		; <[24 x sbyte] *>	[#uses=1]
%__intern_LC15 = global [15 x sbyte] c"%2d NULL TREE\0A\00"		; <[15 x sbyte] *>	[#uses=1]
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

declare double "sqrt"(double)

declare double "fabs"(double)

declare sbyte * "malloc"(...)

declare double "xrand"(...)

declare double "my_rand"(...)

declare double "pow"(...)

%icstruct * "intcoord"(%icstruct * %StructReturn, %bodyptr %p, %treeptr %t)
begin
bb0:					;[#uses=0]
	%ic = alloca %icstruct		; <%icstruct *>	[#uses=11]
	%pos = alloca %vector		; <%vector *>	[#uses=1]
	%cast4203 = cast %vector * %pos to double *		; <double *>	[#uses=5]
	br label %bb1

bb1:					;[#uses=1]
	store short 1, %icstruct * %ic, ubyte 1
	%reg111 = load %treeptr %t, ubyte 1		; <double>	[#uses=3]
	%eptr4687 = getelementptr %bodyptr %p, ubyte 2		; <%vector *>	[#uses=1]
	%cast4243 = cast %vector * %eptr4687 to double *		; <double *>	[#uses=1]
	%reg113 = load double * %cast4243		; <double>	[#uses=2]
	store double %reg113, double * %cast4203
	%cast4244 = cast ulong 24 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg4208 = add %bodyptr %p, %cast4244		; <%bodyptr>	[#uses=1]
	%cast4245 = cast %bodyptr %reg4208 to double *		; <double *>	[#uses=1]
	%reg114 = load double * %cast4245		; <double>	[#uses=1]
	%cast4246 = cast ulong 8 to double *		; <double *>	[#uses=1]
	%reg4209 = add double * %cast4203, %cast4246		; <double *>	[#uses=1]
	store double %reg114, double * %reg4209
	%cast4247 = cast ulong 32 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg4210 = add %bodyptr %p, %cast4247		; <%bodyptr>	[#uses=1]
	%cast4248 = cast %bodyptr %reg4210 to double *		; <double *>	[#uses=1]
	%reg115 = load double * %cast4248		; <double>	[#uses=1]
	%cast4249 = cast ulong 16 to double *		; <double *>	[#uses=1]
	%reg4211 = add double * %cast4203, %cast4249		; <double *>	[#uses=1]
	store double %reg115, double * %reg4211
	%cast4250 = cast %treeptr %t to double *		; <double *>	[#uses=1]
	%reg117 = load double * %cast4250		; <double>	[#uses=1]
	%reg118 = sub double %reg113, %reg117		; <double>	[#uses=1]
	%reg110 = div double %reg118, %reg111		; <double>	[#uses=3]
	%cast4255 = cast double %reg110 to long		; <long>	[#uses=1]
	%cast4256 = cast double 0.000000 to long		; <long>	[#uses=1]
	%cond4212 = setge long %cast4255, %cast4256		; <bool>	[#uses=1]
	br bool %cond4212, label %bb2, label %bb4

bb2:					;[#uses=1]
	%cast4257 = cast double %reg110 to long		; <long>	[#uses=1]
	%cast4258 = cast double 1.000000 to long		; <long>	[#uses=1]
	%cond4213 = setlt long %cast4257, %cast4258		; <bool>	[#uses=1]
	br bool %cond4213, label %bb3, label %bb4

bb3:					;[#uses=1]
	%reg122 = mul double %reg110, 1073741824.000000		; <double>	[#uses=1]
	%reg123 = call %rproc %floor( double %reg122 )		; <double>	[#uses=1]
	%cast124 = cast double %reg123 to int		; <int>	[#uses=1]
	%cast4214 = cast %icstruct * %ic to int *		; <int *>	[#uses=1]
	store int %cast124, int * %cast4214
	br label %bb5

bb4:					;[#uses=2]
	store short 0, %icstruct * %ic, ubyte 1
	br label %bb5

bb5:					;[#uses=2]
	%cast4260 = cast ulong 8 to double *		; <double *>	[#uses=1]
	%reg4217 = add double * %cast4203, %cast4260		; <double *>	[#uses=1]
	%reg126 = load double * %reg4217		; <double>	[#uses=1]
	%cast4261 = cast ulong 8 to %treeptr		; <%treeptr>	[#uses=1]
	%reg4218 = add %treeptr %t, %cast4261		; <%treeptr>	[#uses=1]
	%cast4262 = cast %treeptr %reg4218 to double *		; <double *>	[#uses=1]
	%reg127 = load double * %cast4262		; <double>	[#uses=1]
	%reg128 = sub double %reg126, %reg127		; <double>	[#uses=1]
	%reg150 = div double %reg128, %reg111		; <double>	[#uses=3]
	%cast4267 = cast double %reg150 to long		; <long>	[#uses=1]
	%cast4268 = cast double 0.000000 to long		; <long>	[#uses=1]
	%cond4219 = setge long %cast4267, %cast4268		; <bool>	[#uses=1]
	br bool %cond4219, label %bb6, label %bb8

bb6:					;[#uses=1]
	%cast4269 = cast double %reg150 to long		; <long>	[#uses=1]
	%cast4270 = cast double 1.000000 to long		; <long>	[#uses=1]
	%cond4220 = setlt long %cast4269, %cast4270		; <bool>	[#uses=1]
	br bool %cond4220, label %bb7, label %bb8

bb7:					;[#uses=1]
	%reg132 = mul double %reg150, 1073741824.000000		; <double>	[#uses=1]
	%reg133 = call %rproc %floor( double %reg132 )		; <double>	[#uses=1]
	%cast134 = cast double %reg133 to int		; <int>	[#uses=1]
	%cast4271 = cast ulong 4 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg4221 = add %icstruct * %ic, %cast4271		; <%icstruct *>	[#uses=1]
	%cast4222 = cast %icstruct * %reg4221 to int *		; <int *>	[#uses=1]
	store int %cast134, int * %cast4222
	br label %bb9

bb8:					;[#uses=2]
	store short 0, %icstruct * %ic, ubyte 1
	br label %bb9

bb9:					;[#uses=2]
	%cast4273 = cast ulong 16 to double *		; <double *>	[#uses=1]
	%reg4225 = add double * %cast4203, %cast4273		; <double *>	[#uses=1]
	%reg136 = load double * %reg4225		; <double>	[#uses=1]
	%cast4274 = cast ulong 16 to %treeptr		; <%treeptr>	[#uses=1]
	%reg4226 = add %treeptr %t, %cast4274		; <%treeptr>	[#uses=1]
	%cast4275 = cast %treeptr %reg4226 to double *		; <double *>	[#uses=1]
	%reg137 = load double * %cast4275		; <double>	[#uses=1]
	%reg138 = sub double %reg136, %reg137		; <double>	[#uses=1]
	%reg151 = div double %reg138, %reg111		; <double>	[#uses=3]
	%cast4280 = cast double %reg151 to long		; <long>	[#uses=1]
	%cast4281 = cast double 0.000000 to long		; <long>	[#uses=1]
	%cond4227 = setge long %cast4280, %cast4281		; <bool>	[#uses=1]
	br bool %cond4227, label %bb10, label %bb12

bb10:					;[#uses=1]
	%cast4282 = cast double %reg151 to long		; <long>	[#uses=1]
	%cast4283 = cast double 1.000000 to long		; <long>	[#uses=1]
	%cond4228 = setlt long %cast4282, %cast4283		; <bool>	[#uses=1]
	br bool %cond4228, label %bb11, label %bb12

bb11:					;[#uses=1]
	%reg142 = mul double %reg151, 1073741824.000000		; <double>	[#uses=1]
	%reg143 = call %rproc %floor( double %reg142 )		; <double>	[#uses=1]
	%cast144 = cast double %reg143 to int		; <int>	[#uses=1]
	%cast4284 = cast ulong 8 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg4229 = add %icstruct * %ic, %cast4284		; <%icstruct *>	[#uses=1]
	%cast4230 = cast %icstruct * %reg4229 to int *		; <int *>	[#uses=1]
	store int %cast144, int * %cast4230
	br label %bb13

bb12:					;[#uses=2]
	store short 0, %icstruct * %ic, ubyte 1
	br label %bb13

bb13:					;[#uses=2]
	%cast4286 = cast %icstruct * %ic to uint *		; <uint *>	[#uses=1]
	%reg146 = load uint * %cast4286		; <uint>	[#uses=1]
	%cast4287 = cast %icstruct * %StructReturn to uint *		; <uint *>	[#uses=1]
	store uint %reg146, uint * %cast4287
	%cast4288 = cast ulong 4 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg4233 = add %icstruct * %ic, %cast4288		; <%icstruct *>	[#uses=1]
	%cast4289 = cast %icstruct * %reg4233 to uint *		; <uint *>	[#uses=1]
	%reg147 = load uint * %cast4289		; <uint>	[#uses=1]
	%cast4290 = cast ulong 4 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg4234 = add %icstruct * %StructReturn, %cast4290		; <%icstruct *>	[#uses=1]
	%cast4291 = cast %icstruct * %reg4234 to uint *		; <uint *>	[#uses=1]
	store uint %reg147, uint * %cast4291
	%cast4292 = cast ulong 8 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg4235 = add %icstruct * %ic, %cast4292		; <%icstruct *>	[#uses=1]
	%cast4293 = cast %icstruct * %reg4235 to uint *		; <uint *>	[#uses=1]
	%reg148 = load uint * %cast4293		; <uint>	[#uses=1]
	%cast4294 = cast ulong 8 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg4236 = add %icstruct * %StructReturn, %cast4294		; <%icstruct *>	[#uses=1]
	%cast4295 = cast %icstruct * %reg4236 to uint *		; <uint *>	[#uses=1]
	store uint %reg148, uint * %cast4295
	%eptr4691 = getelementptr %icstruct * %ic, ubyte 1		; <short *>	[#uses=1]
	%cast4297 = cast short * %eptr4691 to uint *		; <uint *>	[#uses=1]
	%reg149 = load uint * %cast4297		; <uint>	[#uses=1]
	%eptr4692 = getelementptr %icstruct * %StructReturn, ubyte 1		; <short *>	[#uses=1]
	%cast4299 = cast short * %eptr4692 to uint *		; <uint *>	[#uses=1]
	store uint %reg149, uint * %cast4299
	ret %icstruct * %StructReturn

bb14:					;[#uses=0]
	%cast4300 = cast ulong 42 to %icstruct *		; <%icstruct *>	[#uses=1]
	ret %icstruct * %cast4300
end

void "computegrav"(%treeptr %t, int %nstep)
begin
bb1:					;[#uses=1]
	%reg110 = load %treeptr %t, ubyte 1		; <double>	[#uses=1]
	%reg114 = load int * %NumNodes		; <int>	[#uses=1]
	%reg109 = add int %reg114, -1		; <int>	[#uses=2]
	%cond2753 = setlt int %reg109, 0		; <bool>	[#uses=1]
	br bool %cond2753, label %bb3, label %bb2

bb2:					;[#uses=3]
	%reg121 = phi int [ %reg122, %bb2 ], [ %reg109, %bb1 ]		; <int>	[#uses=2]
	%cast2760 = cast int %reg121 to uint		; <uint>	[#uses=1]
	%reg112 = load %treeptr %t, ubyte 2		; <%nodeptr>	[#uses=1]
	%reg116 = shl uint %cast2760, ubyte 3		; <uint>	[#uses=1]
	%reg117 = add uint %reg116, 552		; <uint>	[#uses=1]
	%cast118 = cast uint %reg117 to %treeptr		; <%treeptr>	[#uses=1]
	%reg120 = add %treeptr %t, %cast118		; <%treeptr>	[#uses=1]
	%cast2761 = cast %treeptr %reg120 to %bodyptr *		; <%bodyptr *>	[#uses=1]
	%reg113 = load %bodyptr * %cast2761		; <%bodyptr>	[#uses=1]
	call void (double, %nodeptr, %bodyptr, int, double) * %grav( double %reg110, %nodeptr %reg112, %bodyptr %reg113, int %nstep, double 0.006250 )
	%reg122 = add int %reg121, -1		; <int>	[#uses=2]
	%cond2755 = setge int %reg122, 0		; <bool>	[#uses=1]
	br bool %cond2755, label %bb2, label %bb3

bb3:					;[#uses=2]
	ret void
end

%nodeptr "maketree"(%bodyptr %btab, int %nb, %treeptr %t, int %nsteps, int %proc)
begin
bb0:					;[#uses=0]
	%xqic = alloca %icstruct		; <%icstruct *>	[#uses=5]
	br label %bb1

bb1:					;[#uses=2]
	store %nodeptr null, %treeptr %t, ubyte 2
	store int %nb, int * %nbody
	%reg117 = load int * %NumNodes		; <int>	[#uses=1]
	%reg113 = add int %reg117, -1		; <int>	[#uses=2]
	%cond3563 = setlt int %reg113, 0		; <bool>	[#uses=1]
	br bool %cond3563, label %bb7, label %bb2

bb2:					;[#uses=3]
	%reg136 = phi int [ %reg140, %bb6 ], [ %reg113, %bb1 ]		; <int>	[#uses=2]
	%cast3584 = cast int %reg136 to uint		; <uint>	[#uses=1]
	%reg119 = shl uint %cast3584, ubyte 3		; <uint>	[#uses=1]
	%reg120 = add uint %reg119, 552		; <uint>	[#uses=1]
	%cast121 = cast uint %reg120 to %treeptr		; <%treeptr>	[#uses=1]
	%reg123 = add %treeptr %t, %cast121		; <%treeptr>	[#uses=1]
	%cast3585 = cast %treeptr %reg123 to ulong * *		; <ulong * *>	[#uses=1]
	%reg112 = load ulong * * %cast3585		; <ulong *>	[#uses=2]
	%cond3564 = seteq ulong * %reg112, null		; <bool>	[#uses=1]
	br bool %cond3564, label %bb6, label %bb3

bb3:					;[#uses=2]
	%reg137 = phi ulong * [ %reg139, %bb5 ], [ %reg112, %bb2 ]		; <ulong *>	[#uses=5]
	%cast3614 = cast ulong * %reg137 to ulong * *		; <ulong * *>	[#uses=1]
	%cast3610 = cast ulong * %reg137 to %bodyptr		; <%bodyptr>	[#uses=1]
	%cast3590 = cast ulong * %reg137 to %bodyptr		; <%bodyptr>	[#uses=1]
	%cast3589 = cast ulong * %reg137 to %bodyptr		; <%bodyptr>	[#uses=1]
	%cast3587 = cast ulong 8 to ulong *		; <ulong *>	[#uses=1]
	%reg3565 = add ulong * %reg137, %cast3587		; <ulong *>	[#uses=1]
	%cast3588 = cast ulong * %reg3565 to double *		; <double *>	[#uses=1]
	%reg124 = load double * %cast3588		; <double>	[#uses=1]
	%cond3566 = seteq double %reg124, 0.000000		; <bool>	[#uses=1]
	br bool %cond3566, label %bb5, label %bb4

bb4:					;[#uses=1]
	call void (%bodyptr, %treeptr, int, int) * %expandbox( %bodyptr %cast3589, %treeptr %t, int %nsteps, int %proc )
	call %icstruct * (%icstruct *, %bodyptr, %treeptr) * %intcoord( %icstruct * %xqic, %bodyptr %cast3590, %treeptr %t )		; <%icstruct *>:0	[#uses=0]
	%reg114 = load %treeptr %t, ubyte 2		; <%nodeptr>	[#uses=1]
	%cast3593 = cast %icstruct * %xqic to uint *		; <uint *>	[#uses=1]
	%reg127 = load uint * %cast3593		; <uint>	[#uses=1]
	%cast3594 = cast ulong 42 to uint *		; <uint *>	[#uses=1]
	%cast3595 = cast long -48 to uint *		; <uint *>	[#uses=1]
	%reg3568 = add uint * %cast3594, %cast3595		; <uint *>	[#uses=1]
	store uint %reg127, uint * %reg3568
	%cast3596 = cast ulong 4 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg3569 = add %icstruct * %xqic, %cast3596		; <%icstruct *>	[#uses=1]
	%cast3597 = cast %icstruct * %reg3569 to uint *		; <uint *>	[#uses=1]
	%reg128 = load uint * %cast3597		; <uint>	[#uses=1]
	%cast3598 = cast ulong 42 to uint *		; <uint *>	[#uses=1]
	%cast3599 = cast long -44 to uint *		; <uint *>	[#uses=1]
	%reg3570 = add uint * %cast3598, %cast3599		; <uint *>	[#uses=1]
	store uint %reg128, uint * %reg3570
	%cast3600 = cast ulong 8 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg3571 = add %icstruct * %xqic, %cast3600		; <%icstruct *>	[#uses=1]
	%cast3601 = cast %icstruct * %reg3571 to uint *		; <uint *>	[#uses=1]
	%reg129 = load uint * %cast3601		; <uint>	[#uses=1]
	%cast3602 = cast ulong 42 to uint *		; <uint *>	[#uses=1]
	%cast3603 = cast long -40 to uint *		; <uint *>	[#uses=1]
	%reg3572 = add uint * %cast3602, %cast3603		; <uint *>	[#uses=1]
	store uint %reg129, uint * %reg3572
	%eptr3625 = getelementptr %icstruct * %xqic, ubyte 1		; <short *>	[#uses=1]
	%cast3605 = cast short * %eptr3625 to uint *		; <uint *>	[#uses=1]
	%reg130 = load uint * %cast3605		; <uint>	[#uses=1]
	%cast3606 = cast ulong 42 to uint *		; <uint *>	[#uses=1]
	%cast3607 = cast long -36 to uint *		; <uint *>	[#uses=1]
	%reg3574 = add uint * %cast3606, %cast3607		; <uint *>	[#uses=1]
	store uint %reg130, uint * %reg3574
	%cast3608 = cast ulong 42 to %icstruct *		; <%icstruct *>	[#uses=1]
	%cast3609 = cast long -48 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg131 = add %icstruct * %cast3608, %cast3609		; <%icstruct *>	[#uses=1]
	%reg138 = call %nodeptr (%bodyptr, %icstruct *, %nodeptr, int, %treeptr) * %loadtree( %bodyptr %cast3610, %icstruct * %reg131, %nodeptr %reg114, int 536870912, %treeptr %t )		; <%nodeptr>	[#uses=1]
	store %nodeptr %reg138, %treeptr %t, ubyte 2
	br label %bb5

bb5:					;[#uses=3]
	%cast3613 = cast ulong 136 to ulong * *		; <ulong * *>	[#uses=1]
	%reg3576 = add ulong * * %cast3614, %cast3613		; <ulong * *>	[#uses=1]
	%reg139 = load ulong * * %reg3576		; <ulong *>	[#uses=2]
	%cond3577 = setne ulong * %reg139, null		; <bool>	[#uses=1]
	br bool %cond3577, label %bb3, label %bb6

bb6:					;[#uses=3]
	%reg140 = add int %reg136, -1		; <int>	[#uses=2]
	%cond3578 = setge int %reg140, 0		; <bool>	[#uses=1]
	br bool %cond3578, label %bb2, label %bb7

bb7:					;[#uses=2]
	%reg133 = load %treeptr %t, ubyte 2		; <%nodeptr>	[#uses=1]
	call double (%nodeptr) * %hackcofm( %nodeptr %reg133 )		; <double>:0	[#uses=0]
	%reg135 = load %treeptr %t, ubyte 2		; <%nodeptr>	[#uses=1]
	ret %nodeptr %reg135

bb8:					;[#uses=0]
	%cast3621 = cast ulong 42 to %nodeptr		; <%nodeptr>	[#uses=1]
	ret %nodeptr %cast3621
end

void "vp"(%bodyptr %q, int %nstep)
begin
bb0:					;[#uses=0]
	%acc1 = alloca %vector		; <%vector *>	[#uses=3]
	%dacc = alloca %vector		; <%vector *>	[#uses=2]
	%dvel = alloca %vector		; <%vector *>	[#uses=6]
	%vel1 = alloca %vector		; <%vector *>	[#uses=3]
	%dpos = alloca %vector		; <%vector *>	[#uses=3]
	br label %bb1

bb1:					;[#uses=2]
	%cond2779 = seteq %bodyptr %q, null		; <bool>	[#uses=1]
	br bool %cond2779, label %bb76, label %bb2

bb2:					;[#uses=3]
	%reg462 = phi %bodyptr [ %reg511, %bb75 ], [ %q, %bb1 ]		; <%bodyptr>	[#uses=23]
	%cond2780 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond2780, label %bb4, label %bb3

bb3:					;[#uses=3]
	%reg463 = phi int [ %reg464, %bb3 ], [ 0, %bb2 ]		; <int>	[#uses=2]
	%cast2868 = cast int %reg463 to uint		; <uint>	[#uses=1]
	%reg113 = shl uint %cast2868, ubyte 3		; <uint>	[#uses=2]
	%cast114 = cast uint %reg113 to ulong *		; <ulong *>	[#uses=1]
	%cast2869 = cast %vector * %acc1 to ulong *		; <ulong *>	[#uses=1]
	%reg118 = add ulong * %cast2869, %cast114		; <ulong *>	[#uses=1]
	%reg121 = add uint %reg113, 96		; <uint>	[#uses=1]
	%cast122 = cast uint %reg121 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg124 = add %bodyptr %reg462, %cast122		; <%bodyptr>	[#uses=1]
	%cast2870 = cast %bodyptr %reg124 to double *		; <double *>	[#uses=1]
	%reg125 = load double * %cast2870		; <double>	[#uses=1]
	%cast2871 = cast ulong * %reg118 to double *		; <double *>	[#uses=1]
	store double %reg125, double * %cast2871
	%reg464 = add int %reg463, 1		; <int>	[#uses=2]
	%cond2781 = setle int %reg464, 2		; <bool>	[#uses=1]
	br bool %cond2781, label %bb3, label %bb4

bb4:					;[#uses=2]
	%cond2782 = setle int %nstep, 0		; <bool>	[#uses=1]
	br bool %cond2782, label %bb13, label %bb5

bb5:					;[#uses=2]
	%cond2783 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond2783, label %bb7, label %bb6

bb6:					;[#uses=3]
	%reg465 = phi int [ %reg466, %bb6 ], [ 0, %bb5 ]		; <int>	[#uses=2]
	%cast2873 = cast int %reg465 to uint		; <uint>	[#uses=1]
	%reg128 = shl uint %cast2873, ubyte 3		; <uint>	[#uses=2]
	%cast129 = cast uint %reg128 to ulong *		; <ulong *>	[#uses=2]
	%cast2874 = cast %vector * %dacc to ulong *		; <ulong *>	[#uses=1]
	%reg133 = add ulong * %cast2874, %cast129		; <ulong *>	[#uses=1]
	%cast2875 = cast %vector * %acc1 to ulong *		; <ulong *>	[#uses=1]
	%reg140 = add ulong * %cast2875, %cast129		; <ulong *>	[#uses=1]
	%reg143 = add uint %reg128, 72		; <uint>	[#uses=1]
	%cast144 = cast uint %reg143 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg146 = add %bodyptr %reg462, %cast144		; <%bodyptr>	[#uses=1]
	%cast2876 = cast ulong * %reg140 to double *		; <double *>	[#uses=1]
	%reg147 = load double * %cast2876		; <double>	[#uses=1]
	%cast2877 = cast %bodyptr %reg146 to double *		; <double *>	[#uses=1]
	%reg148 = load double * %cast2877		; <double>	[#uses=1]
	%reg149 = sub double %reg147, %reg148		; <double>	[#uses=1]
	%cast2878 = cast ulong * %reg133 to double *		; <double *>	[#uses=1]
	store double %reg149, double * %cast2878
	%reg466 = add int %reg465, 1		; <int>	[#uses=2]
	%cond2784 = setle int %reg466, 2		; <bool>	[#uses=1]
	br bool %cond2784, label %bb6, label %bb7

bb7:					;[#uses=3]
	%cond2785 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond2785, label %bb9, label %bb8

bb8:					;[#uses=3]
	%reg467 = phi int [ %reg468, %bb8 ], [ 0, %bb7 ]		; <int>	[#uses=2]
	%cast2880 = cast int %reg467 to uint		; <uint>	[#uses=1]
	%reg152 = shl uint %cast2880, ubyte 3		; <uint>	[#uses=1]
	%cast153 = cast uint %reg152 to ulong *		; <ulong *>	[#uses=2]
	%cast2881 = cast %vector * %dvel to ulong *		; <ulong *>	[#uses=1]
	%reg157 = add ulong * %cast2881, %cast153		; <ulong *>	[#uses=1]
	%cast2882 = cast %vector * %dacc to ulong *		; <ulong *>	[#uses=1]
	%reg164 = add ulong * %cast2882, %cast153		; <ulong *>	[#uses=1]
	%cast2883 = cast ulong * %reg164 to double *		; <double *>	[#uses=1]
	%reg165 = load double * %cast2883		; <double>	[#uses=1]
	%reg166 = mul double %reg165, 0.006250		; <double>	[#uses=1]
	%cast2884 = cast ulong * %reg157 to double *		; <double *>	[#uses=1]
	store double %reg166, double * %cast2884
	%reg468 = add int %reg467, 1		; <int>	[#uses=2]
	%cond2786 = setle int %reg468, 2		; <bool>	[#uses=1]
	br bool %cond2786, label %bb8, label %bb9

bb9:					;[#uses=3]
	%cond2787 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond2787, label %bb11, label %bb10

bb10:					;[#uses=3]
	%reg469 = phi int [ %reg470, %bb10 ], [ 0, %bb9 ]		; <int>	[#uses=2]
	%cast2886 = cast int %reg469 to uint		; <uint>	[#uses=1]
	%reg169 = shl uint %cast2886, ubyte 3		; <uint>	[#uses=2]
	%cast170 = cast uint %reg169 to ulong *		; <ulong *>	[#uses=1]
	%cast2887 = cast %vector * %dvel to ulong *		; <ulong *>	[#uses=1]
	%reg174 = add ulong * %cast2887, %cast170		; <ulong *>	[#uses=2]
	%reg177 = add uint %reg169, 48		; <uint>	[#uses=1]
	%cast178 = cast uint %reg177 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg180 = add %bodyptr %reg462, %cast178		; <%bodyptr>	[#uses=1]
	%cast2888 = cast %bodyptr %reg180 to double *		; <double *>	[#uses=1]
	%reg188 = load double * %cast2888		; <double>	[#uses=1]
	%cast2889 = cast ulong * %reg174 to double *		; <double *>	[#uses=1]
	%reg189 = load double * %cast2889		; <double>	[#uses=1]
	%reg190 = add double %reg188, %reg189		; <double>	[#uses=1]
	%cast2890 = cast ulong * %reg174 to double *		; <double *>	[#uses=1]
	store double %reg190, double * %cast2890
	%reg470 = add int %reg469, 1		; <int>	[#uses=2]
	%cond2788 = setle int %reg470, 2		; <bool>	[#uses=1]
	br bool %cond2788, label %bb10, label %bb11

bb11:					;[#uses=3]
	%cond2789 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond2789, label %bb13, label %bb12

bb12:					;[#uses=3]
	%reg471 = phi int [ %reg472, %bb12 ], [ 0, %bb11 ]		; <int>	[#uses=2]
	%cast2892 = cast int %reg471 to uint		; <uint>	[#uses=1]
	%reg193 = shl uint %cast2892, ubyte 3		; <uint>	[#uses=2]
	%reg194 = add uint %reg193, 48		; <uint>	[#uses=1]
	%cast195 = cast uint %reg194 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg197 = add %bodyptr %reg462, %cast195		; <%bodyptr>	[#uses=1]
	%cast200 = cast uint %reg193 to ulong *		; <ulong *>	[#uses=1]
	%cast2893 = cast %vector * %dvel to ulong *		; <ulong *>	[#uses=1]
	%reg204 = add ulong * %cast2893, %cast200		; <ulong *>	[#uses=1]
	%cast2894 = cast ulong * %reg204 to double *		; <double *>	[#uses=1]
	%reg205 = load double * %cast2894		; <double>	[#uses=1]
	%cast2895 = cast %bodyptr %reg197 to double *		; <double *>	[#uses=1]
	store double %reg205, double * %cast2895
	%reg472 = add int %reg471, 1		; <int>	[#uses=2]
	%cond2790 = setle int %reg472, 2		; <bool>	[#uses=1]
	br bool %cond2790, label %bb12, label %bb13

bb13:					;[#uses=4]
	%eptr3037 = getelementptr %bodyptr %reg462, ubyte 2		; <%vector *>	[#uses=1]
	%cast2898 = cast %vector * %eptr3037 to double *		; <double *>	[#uses=1]
	%reg206 = load double * %cast2898		; <double>	[#uses=3]
	%cast2899 = cast ulong 24 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg2792 = add %bodyptr %reg462, %cast2899		; <%bodyptr>	[#uses=1]
	%cast2900 = cast %bodyptr %reg2792 to double *		; <double *>	[#uses=1]
	%reg207 = load double * %cast2900		; <double>	[#uses=3]
	%cast2901 = cast ulong 32 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg2793 = add %bodyptr %reg462, %cast2901		; <%bodyptr>	[#uses=1]
	%cast2902 = cast %bodyptr %reg2793 to double *		; <double *>	[#uses=1]
	%reg208 = load double * %cast2902		; <double>	[#uses=3]
	%cast2903 = cast double %reg206 to long		; <long>	[#uses=1]
	%cast2904 = cast double 0.000000 to long		; <long>	[#uses=1]
	%cond2794 = setge long %cast2903, %cast2904		; <bool>	[#uses=1]
	br bool %cond2794, label %bb15, label %bb14

bb14:					;[#uses=2]
	%cast2905 = cast ulong 0 to double		; <double>	[#uses=1]
	%reg473 = sub double %cast2905, %reg206		; <double>	[#uses=1]
	br label %bb15

bb15:					;[#uses=2]
	%reg474 = phi double [ %reg473, %bb14 ], [ %reg206, %bb13 ]		; <double>	[#uses=1]
	%cast2906 = cast double %reg474 to long		; <long>	[#uses=1]
	%cast2907 = cast double 10.000000 to long		; <long>	[#uses=1]
	%cond2795 = setlt long %cast2906, %cast2907		; <bool>	[#uses=1]
	br bool %cond2795, label %bb17, label %bb16

bb16:					;[#uses=1]
	%cast2796 = cast ulong 96 to uint		; <uint>	[#uses=1]
	%cast2908 = cast [22 x sbyte] * %__intern_LC5 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast2908, uint %cast2796 )		; <int>:0	[#uses=0]
	%cast2797 = cast ulong 0 to uint		; <uint>	[#uses=1]
	call %proc %exit( uint %cast2797 )
	br label %bb17

bb17:					;[#uses=3]
	%cast2909 = cast double %reg207 to long		; <long>	[#uses=1]
	%cast2910 = cast double 0.000000 to long		; <long>	[#uses=1]
	%cond2798 = setge long %cast2909, %cast2910		; <bool>	[#uses=1]
	br bool %cond2798, label %bb19, label %bb18

bb18:					;[#uses=2]
	%cast2911 = cast ulong 0 to double		; <double>	[#uses=1]
	%reg475 = sub double %cast2911, %reg207		; <double>	[#uses=1]
	br label %bb19

bb19:					;[#uses=2]
	%reg476 = phi double [ %reg475, %bb18 ], [ %reg207, %bb17 ]		; <double>	[#uses=1]
	%cast2912 = cast double %reg476 to long		; <long>	[#uses=1]
	%cast2913 = cast double 10.000000 to long		; <long>	[#uses=1]
	%cond2799 = setlt long %cast2912, %cast2913		; <bool>	[#uses=1]
	br bool %cond2799, label %bb21, label %bb20

bb20:					;[#uses=1]
	%cast2800 = cast ulong 95 to uint		; <uint>	[#uses=1]
	%cast2914 = cast [22 x sbyte] * %__intern_LC5 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast2914, uint %cast2800 )		; <int>:1	[#uses=0]
	%cast2801 = cast ulong 0 to uint		; <uint>	[#uses=1]
	call %proc %exit( uint %cast2801 )
	br label %bb21

bb21:					;[#uses=3]
	%cast2915 = cast double %reg208 to long		; <long>	[#uses=1]
	%cast2916 = cast double 0.000000 to long		; <long>	[#uses=1]
	%cond2802 = setge long %cast2915, %cast2916		; <bool>	[#uses=1]
	br bool %cond2802, label %bb23, label %bb22

bb22:					;[#uses=2]
	%cast2917 = cast ulong 0 to double		; <double>	[#uses=1]
	%reg477 = sub double %cast2917, %reg208		; <double>	[#uses=1]
	br label %bb23

bb23:					;[#uses=2]
	%reg478 = phi double [ %reg477, %bb22 ], [ %reg208, %bb21 ]		; <double>	[#uses=1]
	%cast2918 = cast double %reg478 to long		; <long>	[#uses=1]
	%cast2919 = cast double 10.000000 to long		; <long>	[#uses=1]
	%cond2803 = setlt long %cast2918, %cast2919		; <bool>	[#uses=1]
	br bool %cond2803, label %bb25, label %bb24

bb24:					;[#uses=1]
	%cast2804 = cast ulong 94 to uint		; <uint>	[#uses=1]
	%cast2920 = cast [22 x sbyte] * %__intern_LC5 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast2920, uint %cast2804 )		; <int>:2	[#uses=0]
	%cast2805 = cast ulong 0 to uint		; <uint>	[#uses=1]
	call %proc %exit( uint %cast2805 )
	br label %bb25

bb25:					;[#uses=3]
	%cond2806 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond2806, label %bb27, label %bb26

bb26:					;[#uses=3]
	%reg479 = phi int [ %reg480, %bb26 ], [ 0, %bb25 ]		; <int>	[#uses=2]
	%cast2921 = cast int %reg479 to uint		; <uint>	[#uses=1]
	%reg238 = shl uint %cast2921, ubyte 3		; <uint>	[#uses=2]
	%reg239 = add uint %reg238, 72		; <uint>	[#uses=1]
	%cast240 = cast uint %reg239 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg242 = add %bodyptr %reg462, %cast240		; <%bodyptr>	[#uses=1]
	%cast245 = cast uint %reg238 to ulong *		; <ulong *>	[#uses=1]
	%cast2922 = cast %vector * %acc1 to ulong *		; <ulong *>	[#uses=1]
	%reg249 = add ulong * %cast2922, %cast245		; <ulong *>	[#uses=1]
	%cast2923 = cast ulong * %reg249 to double *		; <double *>	[#uses=1]
	%reg250 = load double * %cast2923		; <double>	[#uses=1]
	%cast2924 = cast %bodyptr %reg242 to double *		; <double *>	[#uses=1]
	store double %reg250, double * %cast2924
	%reg480 = add int %reg479, 1		; <int>	[#uses=2]
	%cond2807 = setle int %reg480, 2		; <bool>	[#uses=1]
	br bool %cond2807, label %bb26, label %bb27

bb27:					;[#uses=3]
	%eptr3038 = getelementptr %bodyptr %reg462, ubyte 6		; <%vector *>	[#uses=1]
	%cast2927 = cast %vector * %eptr3038 to double *		; <double *>	[#uses=1]
	%reg251 = load double * %cast2927		; <double>	[#uses=3]
	%cast2928 = cast ulong 80 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg2809 = add %bodyptr %reg462, %cast2928		; <%bodyptr>	[#uses=1]
	%cast2929 = cast %bodyptr %reg2809 to double *		; <double *>	[#uses=1]
	%reg252 = load double * %cast2929		; <double>	[#uses=3]
	%cast2930 = cast ulong 88 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg2810 = add %bodyptr %reg462, %cast2930		; <%bodyptr>	[#uses=1]
	%cast2931 = cast %bodyptr %reg2810 to double *		; <double *>	[#uses=1]
	%reg253 = load double * %cast2931		; <double>	[#uses=3]
	%cast2932 = cast double %reg251 to long		; <long>	[#uses=1]
	%cast2933 = cast double 0.000000 to long		; <long>	[#uses=1]
	%cond2811 = setge long %cast2932, %cast2933		; <bool>	[#uses=1]
	br bool %cond2811, label %bb29, label %bb28

bb28:					;[#uses=2]
	%cast2934 = cast ulong 0 to double		; <double>	[#uses=1]
	%reg481 = sub double %cast2934, %reg251		; <double>	[#uses=1]
	br label %bb29

bb29:					;[#uses=2]
	%reg482 = phi double [ %reg481, %bb28 ], [ %reg251, %bb27 ]		; <double>	[#uses=1]
	%cast2935 = cast double %reg482 to long		; <long>	[#uses=1]
	%cast2936 = cast double 10000.000000 to long		; <long>	[#uses=1]
	%cond2812 = setlt long %cast2935, %cast2936		; <bool>	[#uses=1]
	br bool %cond2812, label %bb31, label %bb30

bb30:					;[#uses=1]
	%cast2813 = cast ulong 86 to uint		; <uint>	[#uses=1]
	%cast2937 = cast [22 x sbyte] * %__intern_LC5 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast2937, uint %cast2813 )		; <int>:3	[#uses=0]
	%cast2814 = cast ulong 0 to uint		; <uint>	[#uses=1]
	call %proc %exit( uint %cast2814 )
	br label %bb31

bb31:					;[#uses=3]
	%cast2938 = cast double %reg252 to long		; <long>	[#uses=1]
	%cast2939 = cast double 0.000000 to long		; <long>	[#uses=1]
	%cond2815 = setge long %cast2938, %cast2939		; <bool>	[#uses=1]
	br bool %cond2815, label %bb33, label %bb32

bb32:					;[#uses=2]
	%cast2940 = cast ulong 0 to double		; <double>	[#uses=1]
	%reg483 = sub double %cast2940, %reg252		; <double>	[#uses=1]
	br label %bb33

bb33:					;[#uses=2]
	%reg484 = phi double [ %reg483, %bb32 ], [ %reg252, %bb31 ]		; <double>	[#uses=1]
	%cast2941 = cast double %reg484 to long		; <long>	[#uses=1]
	%cast2942 = cast double 10000.000000 to long		; <long>	[#uses=1]
	%cond2816 = setlt long %cast2941, %cast2942		; <bool>	[#uses=1]
	br bool %cond2816, label %bb35, label %bb34

bb34:					;[#uses=1]
	%cast2817 = cast ulong 85 to uint		; <uint>	[#uses=1]
	%cast2943 = cast [22 x sbyte] * %__intern_LC5 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast2943, uint %cast2817 )		; <int>:4	[#uses=0]
	%cast2818 = cast ulong 0 to uint		; <uint>	[#uses=1]
	call %proc %exit( uint %cast2818 )
	br label %bb35

bb35:					;[#uses=3]
	%cast2944 = cast double %reg253 to long		; <long>	[#uses=1]
	%cast2945 = cast double 0.000000 to long		; <long>	[#uses=1]
	%cond2819 = setge long %cast2944, %cast2945		; <bool>	[#uses=1]
	br bool %cond2819, label %bb37, label %bb36

bb36:					;[#uses=2]
	%cast2946 = cast ulong 0 to double		; <double>	[#uses=1]
	%reg485 = sub double %cast2946, %reg253		; <double>	[#uses=1]
	br label %bb37

bb37:					;[#uses=2]
	%reg486 = phi double [ %reg485, %bb36 ], [ %reg253, %bb35 ]		; <double>	[#uses=1]
	%cast2947 = cast double %reg486 to long		; <long>	[#uses=1]
	%cast2948 = cast double 10000.000000 to long		; <long>	[#uses=1]
	%cond2820 = setlt long %cast2947, %cast2948		; <bool>	[#uses=1]
	br bool %cond2820, label %bb39, label %bb38

bb38:					;[#uses=1]
	%cast2821 = cast ulong 84 to uint		; <uint>	[#uses=1]
	%cast2949 = cast [22 x sbyte] * %__intern_LC5 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast2949, uint %cast2821 )		; <int>:5	[#uses=0]
	%cast2822 = cast ulong 0 to uint		; <uint>	[#uses=1]
	call %proc %exit( uint %cast2822 )
	br label %bb39

bb39:					;[#uses=3]
	%cond2823 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond2823, label %bb41, label %bb40

bb40:					;[#uses=3]
	%reg487 = phi int [ %reg488, %bb40 ], [ 0, %bb39 ]		; <int>	[#uses=2]
	%cast2950 = cast int %reg487 to uint		; <uint>	[#uses=1]
	%reg283 = shl uint %cast2950, ubyte 3		; <uint>	[#uses=2]
	%cast284 = cast uint %reg283 to ulong *		; <ulong *>	[#uses=1]
	%cast2951 = cast %vector * %dvel to ulong *		; <ulong *>	[#uses=1]
	%reg288 = add ulong * %cast2951, %cast284		; <ulong *>	[#uses=1]
	%reg291 = add uint %reg283, 72		; <uint>	[#uses=1]
	%cast292 = cast uint %reg291 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg294 = add %bodyptr %reg462, %cast292		; <%bodyptr>	[#uses=1]
	%cast2952 = cast %bodyptr %reg294 to double *		; <double *>	[#uses=1]
	%reg295 = load double * %cast2952		; <double>	[#uses=1]
	%reg296 = mul double %reg295, 0.006250		; <double>	[#uses=1]
	%cast2953 = cast ulong * %reg288 to double *		; <double *>	[#uses=1]
	store double %reg296, double * %cast2953
	%reg488 = add int %reg487, 1		; <int>	[#uses=2]
	%cond2824 = setle int %reg488, 2		; <bool>	[#uses=1]
	br bool %cond2824, label %bb40, label %bb41

bb41:					;[#uses=3]
	%eptr3039 = getelementptr %bodyptr %reg462, ubyte 5		; <%vector *>	[#uses=1]
	%cast2956 = cast %vector * %eptr3039 to double *		; <double *>	[#uses=1]
	%reg297 = load double * %cast2956		; <double>	[#uses=3]
	%cast2957 = cast ulong 56 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg2826 = add %bodyptr %reg462, %cast2957		; <%bodyptr>	[#uses=1]
	%cast2958 = cast %bodyptr %reg2826 to double *		; <double *>	[#uses=1]
	%reg298 = load double * %cast2958		; <double>	[#uses=3]
	%cast2959 = cast ulong 64 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg2827 = add %bodyptr %reg462, %cast2959		; <%bodyptr>	[#uses=1]
	%cast2960 = cast %bodyptr %reg2827 to double *		; <double *>	[#uses=1]
	%reg299 = load double * %cast2960		; <double>	[#uses=3]
	%cast2961 = cast double %reg297 to long		; <long>	[#uses=1]
	%cast2962 = cast double 0.000000 to long		; <long>	[#uses=1]
	%cond2828 = setge long %cast2961, %cast2962		; <bool>	[#uses=1]
	br bool %cond2828, label %bb43, label %bb42

bb42:					;[#uses=2]
	%cast2963 = cast ulong 0 to double		; <double>	[#uses=1]
	%reg489 = sub double %cast2963, %reg297		; <double>	[#uses=1]
	br label %bb43

bb43:					;[#uses=2]
	%reg490 = phi double [ %reg489, %bb42 ], [ %reg297, %bb41 ]		; <double>	[#uses=1]
	%cast2964 = cast double %reg490 to long		; <long>	[#uses=1]
	%cast2965 = cast double 10000.000000 to long		; <long>	[#uses=1]
	%cond2829 = setlt long %cast2964, %cast2965		; <bool>	[#uses=1]
	br bool %cond2829, label %bb45, label %bb44

bb44:					;[#uses=1]
	%cast2830 = cast ulong 76 to uint		; <uint>	[#uses=1]
	%cast2966 = cast [22 x sbyte] * %__intern_LC5 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast2966, uint %cast2830 )		; <int>:6	[#uses=0]
	%cast2831 = cast ulong 0 to uint		; <uint>	[#uses=1]
	call %proc %exit( uint %cast2831 )
	br label %bb45

bb45:					;[#uses=3]
	%cast2967 = cast double %reg298 to long		; <long>	[#uses=1]
	%cast2968 = cast double 0.000000 to long		; <long>	[#uses=1]
	%cond2832 = setge long %cast2967, %cast2968		; <bool>	[#uses=1]
	br bool %cond2832, label %bb47, label %bb46

bb46:					;[#uses=2]
	%cast2969 = cast ulong 0 to double		; <double>	[#uses=1]
	%reg491 = sub double %cast2969, %reg298		; <double>	[#uses=1]
	br label %bb47

bb47:					;[#uses=2]
	%reg492 = phi double [ %reg491, %bb46 ], [ %reg298, %bb45 ]		; <double>	[#uses=1]
	%cast2970 = cast double %reg492 to long		; <long>	[#uses=1]
	%cast2971 = cast double 10000.000000 to long		; <long>	[#uses=1]
	%cond2833 = setlt long %cast2970, %cast2971		; <bool>	[#uses=1]
	br bool %cond2833, label %bb49, label %bb48

bb48:					;[#uses=1]
	%cast2834 = cast ulong 75 to uint		; <uint>	[#uses=1]
	%cast2972 = cast [22 x sbyte] * %__intern_LC5 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast2972, uint %cast2834 )		; <int>:7	[#uses=0]
	%cast2835 = cast ulong 0 to uint		; <uint>	[#uses=1]
	call %proc %exit( uint %cast2835 )
	br label %bb49

bb49:					;[#uses=3]
	%cast2973 = cast double %reg299 to long		; <long>	[#uses=1]
	%cast2974 = cast double 0.000000 to long		; <long>	[#uses=1]
	%cond2836 = setge long %cast2973, %cast2974		; <bool>	[#uses=1]
	br bool %cond2836, label %bb51, label %bb50

bb50:					;[#uses=2]
	%cast2975 = cast ulong 0 to double		; <double>	[#uses=1]
	%reg493 = sub double %cast2975, %reg299		; <double>	[#uses=1]
	br label %bb51

bb51:					;[#uses=2]
	%reg494 = phi double [ %reg493, %bb50 ], [ %reg299, %bb49 ]		; <double>	[#uses=1]
	%cast2976 = cast double %reg494 to long		; <long>	[#uses=1]
	%cast2977 = cast double 10000.000000 to long		; <long>	[#uses=1]
	%cond2837 = setlt long %cast2976, %cast2977		; <bool>	[#uses=1]
	br bool %cond2837, label %bb53, label %bb52

bb52:					;[#uses=1]
	%cast2838 = cast ulong 74 to uint		; <uint>	[#uses=1]
	%cast2978 = cast [22 x sbyte] * %__intern_LC5 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast2978, uint %cast2838 )		; <int>:8	[#uses=0]
	%cast2839 = cast ulong 0 to uint		; <uint>	[#uses=1]
	call %proc %exit( uint %cast2839 )
	br label %bb53

bb53:					;[#uses=3]
	%cond2840 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond2840, label %bb55, label %bb54

bb54:					;[#uses=3]
	%reg495 = phi int [ %reg496, %bb54 ], [ 0, %bb53 ]		; <int>	[#uses=2]
	%cast2979 = cast int %reg495 to uint		; <uint>	[#uses=1]
	%reg329 = shl uint %cast2979, ubyte 3		; <uint>	[#uses=2]
	%cast330 = cast uint %reg329 to ulong *		; <ulong *>	[#uses=2]
	%cast2980 = cast %vector * %vel1 to ulong *		; <ulong *>	[#uses=1]
	%reg334 = add ulong * %cast2980, %cast330		; <ulong *>	[#uses=1]
	%reg337 = add uint %reg329, 48		; <uint>	[#uses=1]
	%cast338 = cast uint %reg337 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg340 = add %bodyptr %reg462, %cast338		; <%bodyptr>	[#uses=1]
	%cast2981 = cast %vector * %dvel to ulong *		; <ulong *>	[#uses=1]
	%reg347 = add ulong * %cast2981, %cast330		; <ulong *>	[#uses=1]
	%cast2982 = cast %bodyptr %reg340 to double *		; <double *>	[#uses=1]
	%reg348 = load double * %cast2982		; <double>	[#uses=1]
	%cast2983 = cast ulong * %reg347 to double *		; <double *>	[#uses=1]
	%reg349 = load double * %cast2983		; <double>	[#uses=1]
	%reg350 = add double %reg348, %reg349		; <double>	[#uses=1]
	%cast2984 = cast ulong * %reg334 to double *		; <double *>	[#uses=1]
	store double %reg350, double * %cast2984
	%reg496 = add int %reg495, 1		; <int>	[#uses=2]
	%cond2841 = setle int %reg496, 2		; <bool>	[#uses=1]
	br bool %cond2841, label %bb54, label %bb55

bb55:					;[#uses=3]
	%cond2842 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond2842, label %bb57, label %bb56

bb56:					;[#uses=3]
	%reg497 = phi int [ %reg498, %bb56 ], [ 0, %bb55 ]		; <int>	[#uses=2]
	%cast2986 = cast int %reg497 to uint		; <uint>	[#uses=1]
	%reg353 = shl uint %cast2986, ubyte 3		; <uint>	[#uses=1]
	%cast354 = cast uint %reg353 to ulong *		; <ulong *>	[#uses=2]
	%cast2987 = cast %vector * %dpos to ulong *		; <ulong *>	[#uses=1]
	%reg358 = add ulong * %cast2987, %cast354		; <ulong *>	[#uses=1]
	%cast2988 = cast %vector * %vel1 to ulong *		; <ulong *>	[#uses=1]
	%reg365 = add ulong * %cast2988, %cast354		; <ulong *>	[#uses=1]
	%cast2989 = cast ulong * %reg365 to double *		; <double *>	[#uses=1]
	%reg366 = load double * %cast2989		; <double>	[#uses=1]
	%reg368 = mul double %reg366, 0.012500		; <double>	[#uses=1]
	%cast2990 = cast ulong * %reg358 to double *		; <double *>	[#uses=1]
	store double %reg368, double * %cast2990
	%reg498 = add int %reg497, 1		; <int>	[#uses=2]
	%cond2843 = setle int %reg498, 2		; <bool>	[#uses=1]
	br bool %cond2843, label %bb56, label %bb57

bb57:					;[#uses=3]
	%cond2844 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond2844, label %bb59, label %bb58

bb58:					;[#uses=3]
	%reg499 = phi int [ %reg500, %bb58 ], [ 0, %bb57 ]		; <int>	[#uses=2]
	%cast2992 = cast int %reg499 to uint		; <uint>	[#uses=1]
	%reg371 = shl uint %cast2992, ubyte 3		; <uint>	[#uses=2]
	%cast372 = cast uint %reg371 to ulong *		; <ulong *>	[#uses=1]
	%cast2993 = cast %vector * %dpos to ulong *		; <ulong *>	[#uses=1]
	%reg376 = add ulong * %cast2993, %cast372		; <ulong *>	[#uses=2]
	%reg379 = add uint %reg371, 16		; <uint>	[#uses=1]
	%cast380 = cast uint %reg379 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg382 = add %bodyptr %reg462, %cast380		; <%bodyptr>	[#uses=1]
	%cast2994 = cast %bodyptr %reg382 to double *		; <double *>	[#uses=1]
	%reg390 = load double * %cast2994		; <double>	[#uses=1]
	%cast2995 = cast ulong * %reg376 to double *		; <double *>	[#uses=1]
	%reg391 = load double * %cast2995		; <double>	[#uses=1]
	%reg392 = add double %reg390, %reg391		; <double>	[#uses=1]
	%cast2996 = cast ulong * %reg376 to double *		; <double *>	[#uses=1]
	store double %reg392, double * %cast2996
	%reg500 = add int %reg499, 1		; <int>	[#uses=2]
	%cond2845 = setle int %reg500, 2		; <bool>	[#uses=1]
	br bool %cond2845, label %bb58, label %bb59

bb59:					;[#uses=3]
	%cond2846 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond2846, label %bb61, label %bb60

bb60:					;[#uses=3]
	%reg501 = phi int [ %reg502, %bb60 ], [ 0, %bb59 ]		; <int>	[#uses=2]
	%cast2998 = cast int %reg501 to uint		; <uint>	[#uses=1]
	%reg395 = shl uint %cast2998, ubyte 3		; <uint>	[#uses=2]
	%reg396 = add uint %reg395, 16		; <uint>	[#uses=1]
	%cast397 = cast uint %reg396 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg399 = add %bodyptr %reg462, %cast397		; <%bodyptr>	[#uses=1]
	%cast402 = cast uint %reg395 to ulong *		; <ulong *>	[#uses=1]
	%cast2999 = cast %vector * %dpos to ulong *		; <ulong *>	[#uses=1]
	%reg406 = add ulong * %cast2999, %cast402		; <ulong *>	[#uses=1]
	%cast3000 = cast ulong * %reg406 to double *		; <double *>	[#uses=1]
	%reg407 = load double * %cast3000		; <double>	[#uses=1]
	%cast3001 = cast %bodyptr %reg399 to double *		; <double *>	[#uses=1]
	store double %reg407, double * %cast3001
	%reg502 = add int %reg501, 1		; <int>	[#uses=2]
	%cond2847 = setle int %reg502, 2		; <bool>	[#uses=1]
	br bool %cond2847, label %bb60, label %bb61

bb61:					;[#uses=3]
	%cond2848 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond2848, label %bb63, label %bb62

bb62:					;[#uses=3]
	%reg503 = phi int [ %reg504, %bb62 ], [ 0, %bb61 ]		; <int>	[#uses=2]
	%cast3003 = cast int %reg503 to uint		; <uint>	[#uses=1]
	%reg410 = shl uint %cast3003, ubyte 3		; <uint>	[#uses=2]
	%reg411 = add uint %reg410, 48		; <uint>	[#uses=1]
	%cast412 = cast uint %reg411 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg414 = add %bodyptr %reg462, %cast412		; <%bodyptr>	[#uses=1]
	%cast417 = cast uint %reg410 to ulong *		; <ulong *>	[#uses=2]
	%cast3004 = cast %vector * %vel1 to ulong *		; <ulong *>	[#uses=1]
	%reg421 = add ulong * %cast3004, %cast417		; <ulong *>	[#uses=1]
	%cast3005 = cast %vector * %dvel to ulong *		; <ulong *>	[#uses=1]
	%reg428 = add ulong * %cast3005, %cast417		; <ulong *>	[#uses=1]
	%cast3006 = cast ulong * %reg421 to double *		; <double *>	[#uses=1]
	%reg429 = load double * %cast3006		; <double>	[#uses=1]
	%cast3007 = cast ulong * %reg428 to double *		; <double *>	[#uses=1]
	%reg430 = load double * %cast3007		; <double>	[#uses=1]
	%reg431 = add double %reg429, %reg430		; <double>	[#uses=1]
	%cast3008 = cast %bodyptr %reg414 to double *		; <double *>	[#uses=1]
	store double %reg431, double * %cast3008
	%reg504 = add int %reg503, 1		; <int>	[#uses=2]
	%cond2849 = setle int %reg504, 2		; <bool>	[#uses=1]
	br bool %cond2849, label %bb62, label %bb63

bb63:					;[#uses=3]
	%eptr3040 = getelementptr %bodyptr %reg462, ubyte 2		; <%vector *>	[#uses=1]
	%cast3011 = cast %vector * %eptr3040 to double *		; <double *>	[#uses=1]
	%reg432 = load double * %cast3011		; <double>	[#uses=3]
	%cast3012 = cast ulong 24 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg2851 = add %bodyptr %reg462, %cast3012		; <%bodyptr>	[#uses=1]
	%cast3013 = cast %bodyptr %reg2851 to double *		; <double *>	[#uses=1]
	%reg433 = load double * %cast3013		; <double>	[#uses=3]
	%cast3014 = cast ulong 32 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg2852 = add %bodyptr %reg462, %cast3014		; <%bodyptr>	[#uses=1]
	%cast3015 = cast %bodyptr %reg2852 to double *		; <double *>	[#uses=1]
	%reg434 = load double * %cast3015		; <double>	[#uses=3]
	%cast3016 = cast double %reg432 to long		; <long>	[#uses=1]
	%cast3017 = cast double 0.000000 to long		; <long>	[#uses=1]
	%cond2853 = setge long %cast3016, %cast3017		; <bool>	[#uses=1]
	br bool %cond2853, label %bb65, label %bb64

bb64:					;[#uses=2]
	%cast3018 = cast ulong 0 to double		; <double>	[#uses=1]
	%reg505 = sub double %cast3018, %reg432		; <double>	[#uses=1]
	br label %bb65

bb65:					;[#uses=2]
	%reg506 = phi double [ %reg505, %bb64 ], [ %reg432, %bb63 ]		; <double>	[#uses=1]
	%cast3019 = cast double %reg506 to long		; <long>	[#uses=1]
	%cast3020 = cast double 10000.000000 to long		; <long>	[#uses=1]
	%cond2854 = setlt long %cast3019, %cast3020		; <bool>	[#uses=1]
	br bool %cond2854, label %bb67, label %bb66

bb66:					;[#uses=1]
	%cast2855 = cast ulong 66 to uint		; <uint>	[#uses=1]
	%cast3021 = cast [22 x sbyte] * %__intern_LC5 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast3021, uint %cast2855 )		; <int>:9	[#uses=0]
	%cast2856 = cast ulong 0 to uint		; <uint>	[#uses=1]
	call %proc %exit( uint %cast2856 )
	br label %bb67

bb67:					;[#uses=3]
	%cast3022 = cast double %reg433 to long		; <long>	[#uses=1]
	%cast3023 = cast double 0.000000 to long		; <long>	[#uses=1]
	%cond2857 = setge long %cast3022, %cast3023		; <bool>	[#uses=1]
	br bool %cond2857, label %bb69, label %bb68

bb68:					;[#uses=2]
	%cast3024 = cast ulong 0 to double		; <double>	[#uses=1]
	%reg507 = sub double %cast3024, %reg433		; <double>	[#uses=1]
	br label %bb69

bb69:					;[#uses=2]
	%reg508 = phi double [ %reg507, %bb68 ], [ %reg433, %bb67 ]		; <double>	[#uses=1]
	%cast3025 = cast double %reg508 to long		; <long>	[#uses=1]
	%cast3026 = cast double 10000.000000 to long		; <long>	[#uses=1]
	%cond2858 = setlt long %cast3025, %cast3026		; <bool>	[#uses=1]
	br bool %cond2858, label %bb71, label %bb70

bb70:					;[#uses=1]
	%cast2859 = cast ulong 65 to uint		; <uint>	[#uses=1]
	%cast3027 = cast [22 x sbyte] * %__intern_LC5 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast3027, uint %cast2859 )		; <int>:10	[#uses=0]
	%cast2860 = cast ulong 0 to uint		; <uint>	[#uses=1]
	call %proc %exit( uint %cast2860 )
	br label %bb71

bb71:					;[#uses=3]
	%cast3028 = cast double %reg434 to long		; <long>	[#uses=1]
	%cast3029 = cast double 0.000000 to long		; <long>	[#uses=1]
	%cond2861 = setge long %cast3028, %cast3029		; <bool>	[#uses=1]
	br bool %cond2861, label %bb73, label %bb72

bb72:					;[#uses=2]
	%cast3030 = cast ulong 0 to double		; <double>	[#uses=1]
	%reg509 = sub double %cast3030, %reg434		; <double>	[#uses=1]
	br label %bb73

bb73:					;[#uses=2]
	%reg510 = phi double [ %reg509, %bb72 ], [ %reg434, %bb71 ]		; <double>	[#uses=1]
	%cast3031 = cast double %reg510 to long		; <long>	[#uses=1]
	%cast3032 = cast double 10000.000000 to long		; <long>	[#uses=1]
	%cond2862 = setlt long %cast3031, %cast3032		; <bool>	[#uses=1]
	br bool %cond2862, label %bb75, label %bb74

bb74:					;[#uses=1]
	%cast2863 = cast ulong 64 to uint		; <uint>	[#uses=1]
	%cast3033 = cast [22 x sbyte] * %__intern_LC5 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast3033, uint %cast2863 )		; <int>:11	[#uses=0]
	%cast2864 = cast ulong 0 to uint		; <uint>	[#uses=1]
	call %proc %exit( uint %cast2864 )
	br label %bb75

bb75:					;[#uses=3]
	%reg511 = load %bodyptr %reg462, ubyte 10		; <%bodyptr>	[#uses=2]
	%cond2866 = setne %bodyptr %reg511, null		; <bool>	[#uses=1]
	br bool %cond2866, label %bb2, label %bb76

bb76:					;[#uses=2]
	ret void
end

void "gravstep"(double %rsize, %nodeptr %rt, %bodyptr %p, int %nstep, double %dthf)
begin
bb1:					;[#uses=0]
	call void (%bodyptr, double, %nodeptr) * %hackgrav( %bodyptr %p, double %rsize, %nodeptr %rt )
	ret void
end

void "ptree"(%nodeptr %n, int %level)
begin
bb1:					;[#uses=0]
	%cond5456 = seteq %nodeptr %n, null		; <bool>	[#uses=1]
	br bool %cond5456, label %bb7, label %bb2

bb2:					;[#uses=1]
	%reg110 = load %nodeptr %n, ubyte 0		; <short>	[#uses=1]
	%cast110 = cast short %reg110 to ushort		; <ushort>	[#uses=1]
	%cond5457 = setne ushort %cast110, 1		; <bool>	[#uses=1]
	br bool %cond5457, label %bb4, label %bb3

bb3:					;[#uses=1]
	%eptr5488 = getelementptr %nodeptr %n, ubyte 2		; <%vector *>	[#uses=1]
	%cast5469 = cast %vector * %eptr5488 to double *		; <double *>	[#uses=1]
	%reg112 = load double * %cast5469		; <double>	[#uses=1]
	%cast5470 = cast ulong 24 to %nodeptr		; <%nodeptr>	[#uses=1]
	%reg5459 = add %nodeptr %n, %cast5470		; <%nodeptr>	[#uses=1]
	%cast5471 = cast %nodeptr %reg5459 to double *		; <double *>	[#uses=1]
	%reg113 = load double * %cast5471		; <double>	[#uses=1]
	%cast5472 = cast ulong 32 to %nodeptr		; <%nodeptr>	[#uses=1]
	%reg5460 = add %nodeptr %n, %cast5472		; <%nodeptr>	[#uses=1]
	%cast5473 = cast %nodeptr %reg5460 to double *		; <double *>	[#uses=1]
	%reg114 = load double * %cast5473		; <double>	[#uses=1]
	%cast5474 = cast [24 x sbyte] * %__intern_LC13 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast5474, int %level, %nodeptr %n, double %reg112, double %reg113, double %reg114 )		; <int>:0	[#uses=0]
	br label %bb8

bb4:					;[#uses=2]
	%eptr5489 = getelementptr %nodeptr %n, ubyte 2		; <%vector *>	[#uses=1]
	%cast5476 = cast %vector * %eptr5489 to double *		; <double *>	[#uses=1]
	%reg117 = load double * %cast5476		; <double>	[#uses=1]
	%cast5477 = cast ulong 24 to %nodeptr		; <%nodeptr>	[#uses=1]
	%reg5462 = add %nodeptr %n, %cast5477		; <%nodeptr>	[#uses=1]
	%cast5478 = cast %nodeptr %reg5462 to double *		; <double *>	[#uses=1]
	%reg118 = load double * %cast5478		; <double>	[#uses=1]
	%cast5479 = cast ulong 32 to %nodeptr		; <%nodeptr>	[#uses=1]
	%reg5463 = add %nodeptr %n, %cast5479		; <%nodeptr>	[#uses=1]
	%cast5480 = cast %nodeptr %reg5463 to double *		; <double *>	[#uses=1]
	%reg119 = load double * %cast5480		; <double>	[#uses=1]
	%cast5481 = cast [24 x sbyte] * %__intern_LC14 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast5481, int %level, %nodeptr %n, double %reg117, double %reg118, double %reg119 )		; <int>:1	[#uses=0]
	%cond5464 = setgt long 0, 7		; <bool>	[#uses=1]
	br bool %cond5464, label %bb8, label %bb5

bb5:					;[#uses=3]
	%reg129 = phi int [ %reg130, %bb5 ], [ 0, %bb4 ]		; <int>	[#uses=2]
	%cast5482 = cast int %reg129 to uint		; <uint>	[#uses=1]
	%reg121 = shl uint %cast5482, ubyte 3		; <uint>	[#uses=1]
	%reg122 = add uint %reg121, 48		; <uint>	[#uses=1]
	%cast123 = cast uint %reg122 to %nodeptr		; <%nodeptr>	[#uses=1]
	%reg125 = add %nodeptr %n, %cast123		; <%nodeptr>	[#uses=1]
	%cast5483 = cast %nodeptr %reg125 to %nodeptr *		; <%nodeptr *>	[#uses=1]
	%reg109 = load %nodeptr * %cast5483		; <%nodeptr>	[#uses=1]
	%reg127 = add int %level, 1		; <int>	[#uses=1]
	call void (%nodeptr, int) * %ptree( %nodeptr %reg109, int %reg127 )
	%reg130 = add int %reg129, 1		; <int>	[#uses=2]
	%cond5465 = setle int %reg130, 7		; <bool>	[#uses=1]
	br bool %cond5465, label %bb5, label %bb6

bb6:					;[#uses=1]
	br label %bb8

bb7:					;[#uses=1]
	%cast5485 = cast [15 x sbyte] * %__intern_LC15 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast5485, int %level )		; <int>:2	[#uses=0]
	br label %bb8

bb8:					;[#uses=4]
	ret void
end

declare %bodyptr "testdata"(...)

%datapoints * "uniform_testdata"(%datapoints * %StructReturn, int %proc, int %nbody, int %seedfactor)
begin
bb0:					;[#uses=0]
	%retval = alloca %datapoints		; <%datapoints *>	[#uses=14]
	br label %bb1

bb1:					;[#uses=2]
	%cast124 = cast int %seedfactor to double		; <double>	[#uses=1]
	%reg123 = mul double %cast124, 123.000000		; <double>	[#uses=1]
	%reg134 = call double (double) * %sqrt( double 1.697653 )		; <double>	[#uses=1]
	%cond1895 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond1895, label %bb3, label %bb2

bb2:					;[#uses=3]
	%reg299 = phi int [ %reg300, %bb2 ], [ 0, %bb1 ]		; <int>	[#uses=2]
	%cast1939 = cast int %reg299 to uint		; <uint>	[#uses=1]
	%reg137 = shl uint %cast1939, ubyte 3		; <uint>	[#uses=1]
	%cast138 = cast uint %reg137 to %datapoints *		; <%datapoints *>	[#uses=1]
	%reg142 = add %datapoints * %retval, %cast138		; <%datapoints *>	[#uses=1]
	%cast1940 = cast %datapoints * %reg142 to double *		; <double *>	[#uses=1]
	store double 0.000000, double * %cast1940
	%reg300 = add int %reg299, 1		; <int>	[#uses=2]
	%cond1896 = setle int %reg300, 2		; <bool>	[#uses=1]
	br bool %cond1896, label %bb2, label %bb3

bb3:					;[#uses=3]
	%cond1897 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond1897, label %bb5, label %bb4

bb4:					;[#uses=3]
	%reg301 = phi int [ %reg302, %bb4 ], [ 0, %bb3 ]		; <int>	[#uses=2]
	%cast1942 = cast int %reg301 to uint		; <uint>	[#uses=1]
	%reg146 = shl uint %cast1942, ubyte 3		; <uint>	[#uses=1]
	%reg147 = add uint %reg146, 24		; <uint>	[#uses=1]
	%cast148 = cast uint %reg147 to %datapoints *		; <%datapoints *>	[#uses=1]
	%reg152 = add %datapoints * %retval, %cast148		; <%datapoints *>	[#uses=1]
	%cast1943 = cast %datapoints * %reg152 to double *		; <double *>	[#uses=1]
	store double 0.000000, double * %cast1943
	%reg302 = add int %reg301, 1		; <int>	[#uses=2]
	%cond1898 = setle int %reg302, 2		; <bool>	[#uses=1]
	br bool %cond1898, label %bb4, label %bb5

bb5:					;[#uses=6]
	%reg117 = call %bodyptr (int) * %ubody_alloc( int %proc )		; <%bodyptr>	[#uses=3]
	%cond1899 = setge int 0, %nbody		; <bool>	[#uses=1]
	br bool %cond1899, label %bb24, label %bb6

bb6:					;[#uses=2]
	%reg303 = phi double [ %reg326, %bb23 ], [ %reg123, %bb5 ]		; <double>	[#uses=1]
	%reg304 = phi int [ %reg336, %bb23 ], [ 0, %bb5 ]		; <int>	[#uses=1]
	%reg305 = phi %bodyptr [ %reg118, %bb23 ], [ %reg117, %bb5 ]		; <%bodyptr>	[#uses=1]
	%reg118 = call %bodyptr (int) * %ubody_alloc( int %proc )		; <%bodyptr>	[#uses=12]
	%cond1900 = setne %bodyptr %reg118, null		; <bool>	[#uses=1]
	br bool %cond1900, label %bb8, label %bb7

bb7:					;[#uses=1]
	call %iproc %error( [29 x sbyte] * %__intern_LC6 )		; <int>:0	[#uses=0]
	br label %bb8

bb8:					;[#uses=6]
	store %bodyptr %reg118, %bodyptr %reg305, ubyte 9
	store short 1, %bodyptr %reg118, ubyte 0
	%cast2723 = cast int %nbody to double		; <double>	[#uses=1]
	%reg158 = div double 1.000000, %cast2723		; <double>	[#uses=1]
	store double %reg158, %bodyptr %reg118, ubyte 1
	%reg307 = call %rproc %my_rand( double %reg303 )		; <double>	[#uses=3]
	%reg122 = call %rproc %xrand( double 0.000000, double 0.999000, double %reg307 )		; <double>	[#uses=1]
	%reg162 = call %rproc %pow( double %reg122, double -0.666667 )		; <double>	[#uses=1]
	%reg121 = sub double %reg162, 1.000000		; <double>	[#uses=1]
	%reg165 = call double (double) * %sqrt( double %reg121 )		; <double>	[#uses=1]
	%reg113 = div double 1.000000, %reg165		; <double>	[#uses=1]
	%cond1903 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond1903, label %bb10, label %bb9

bb9:					;[#uses=6]
	%reg308 = phi int [ %reg312, %bb9 ], [ 0, %bb8 ]		; <int>	[#uses=2]
	%reg309 = phi double [ %reg310, %bb9 ], [ %reg307, %bb8 ]		; <double>	[#uses=1]
	%cast1959 = cast int %reg308 to uint		; <uint>	[#uses=1]
	%reg310 = call %rproc %my_rand( double %reg309 )		; <double>	[#uses=3]
	%reg311 = call %rproc %xrand( double 0.000000, double 0.999000, double %reg310 )		; <double>	[#uses=2]
	%reg170 = shl uint %cast1959, ubyte 3		; <uint>	[#uses=1]
	%reg171 = add uint %reg170, 16		; <uint>	[#uses=1]
	%cast172 = cast uint %reg171 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg174 = add %bodyptr %reg118, %cast172		; <%bodyptr>	[#uses=1]
	%reg175 = mul double 4.000000, %reg311		; <double>	[#uses=1]
	%cast1960 = cast %bodyptr %reg174 to double *		; <double *>	[#uses=1]
	store double %reg175, double * %cast1960
	%reg312 = add int %reg308, 1		; <int>	[#uses=2]
	%cond1904 = setle int %reg312, 2		; <bool>	[#uses=1]
	br bool %cond1904, label %bb9, label %bb10

bb10:					;[#uses=4]
	%reg313 = phi double [ %reg310, %bb9 ], [ %reg307, %bb8 ]		; <double>	[#uses=2]
	%reg314 = phi double [ %reg311, %bb9 ], [ %reg113, %bb8 ]		; <double>	[#uses=2]
	%cond1905 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond1905, label %bb12, label %bb11

bb11:					;[#uses=4]
	%reg315 = phi int [ %reg316, %bb11 ], [ 0, %bb10 ]		; <int>	[#uses=2]
	%cast1962 = cast int %reg315 to uint		; <uint>	[#uses=1]
	%reg178 = shl uint %cast1962, ubyte 3		; <uint>	[#uses=2]
	%cast179 = cast uint %reg178 to %datapoints *		; <%datapoints *>	[#uses=1]
	%reg183 = add %datapoints * %retval, %cast179		; <%datapoints *>	[#uses=2]
	%reg193 = add uint %reg178, 16		; <uint>	[#uses=1]
	%cast194 = cast uint %reg193 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg196 = add %bodyptr %reg118, %cast194		; <%bodyptr>	[#uses=1]
	%cast1963 = cast %datapoints * %reg183 to double *		; <double *>	[#uses=1]
	%reg197 = load double * %cast1963		; <double>	[#uses=1]
	%cast1964 = cast %bodyptr %reg196 to double *		; <double *>	[#uses=1]
	%reg198 = load double * %cast1964		; <double>	[#uses=1]
	%reg199 = add double %reg197, %reg198		; <double>	[#uses=1]
	%cast1965 = cast %datapoints * %reg183 to double *		; <double *>	[#uses=1]
	store double %reg199, double * %cast1965
	%reg316 = add int %reg315, 1		; <int>	[#uses=2]
	%cond1906 = setle int %reg316, 2		; <bool>	[#uses=1]
	br bool %cond1906, label %bb11, label %bb12

bb12:					;[#uses=4]
	%reg317 = phi double [ %reg319, %bb12 ], [ %reg313, %bb11 ], [ %reg313, %bb10 ]		; <double>	[#uses=1]
	%reg318 = call %rproc %my_rand( double %reg317 )		; <double>	[#uses=2]
	%reg115 = call %rproc %xrand( double 0.000000, double 1.000000, double %reg318 )		; <double>	[#uses=3]
	%reg319 = call %rproc %my_rand( double %reg318 )		; <double>	[#uses=3]
	%reg116 = call %rproc %xrand( double 0.000000, double 0.100000, double %reg319 )		; <double>	[#uses=1]
	%reg204 = mul double %reg115, %reg115		; <double>	[#uses=2]
	%reg207 = sub double 1.000000, %reg204		; <double>	[#uses=1]
	%reg209 = call %rproc %pow( double %reg207, double 3.500000 )		; <double>	[#uses=1]
	%reg210 = mul double %reg204, %reg209		; <double>	[#uses=1]
	%cast1967 = cast double %reg116 to long		; <long>	[#uses=1]
	%cast1968 = cast double %reg210 to long		; <long>	[#uses=1]
	%cond1907 = setgt long %cast1967, %cast1968		; <bool>	[#uses=1]
	br bool %cond1907, label %bb12, label %bb13

bb13:					;[#uses=2]
	%reg213 = call double (double) * %sqrt( double 2.000000 )		; <double>	[#uses=1]
	%reg214 = mul double %reg213, %reg115		; <double>	[#uses=1]
	%reg215 = mul double %reg314, %reg314		; <double>	[#uses=1]
	%reg217 = add double %reg215, 1.000000		; <double>	[#uses=1]
	%reg219 = call %rproc %pow( double %reg217, double 0.250000 )		; <double>	[#uses=1]
	%reg114 = div double %reg214, %reg219		; <double>	[#uses=1]
	%reg129 = mul double %reg134, %reg114		; <double>	[#uses=1]
	br label %bb14

bb14:					;[#uses=5]
	%reg320 = phi double [ %reg326, %bb18 ], [ %reg319, %bb13 ]		; <double>	[#uses=2]
	%cond1908 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond1908, label %bb16, label %bb15

bb15:					;[#uses=5]
	%reg322 = phi int [ %reg325, %bb15 ], [ 0, %bb14 ]		; <int>	[#uses=2]
	%reg323 = phi double [ %reg324, %bb15 ], [ %reg320, %bb14 ]		; <double>	[#uses=1]
	%cast1973 = cast int %reg322 to uint		; <uint>	[#uses=1]
	%reg324 = call %rproc %my_rand( double %reg323 )		; <double>	[#uses=3]
	%reg221 = shl uint %cast1973, ubyte 3		; <uint>	[#uses=1]
	%reg222 = add uint %reg221, 48		; <uint>	[#uses=1]
	%cast223 = cast uint %reg222 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg225 = add %bodyptr %reg118, %cast223		; <%bodyptr>	[#uses=1]
	%reg228 = call %rproc %xrand( double -1.000000, double 1.000000, double %reg324 )		; <double>	[#uses=1]
	%cast1974 = cast %bodyptr %reg225 to double *		; <double *>	[#uses=1]
	store double %reg228, double * %cast1974
	%reg325 = add int %reg322, 1		; <int>	[#uses=2]
	%cond1909 = setle int %reg325, 2		; <bool>	[#uses=1]
	br bool %cond1909, label %bb15, label %bb16

bb16:					;[#uses=5]
	%reg326 = phi double [ %reg324, %bb15 ], [ %reg320, %bb14 ]		; <double>	[#uses=2]
	%cond1910 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond1910, label %bb18, label %bb17

bb17:					;[#uses=5]
	%reg327 = phi int [ %reg330, %bb17 ], [ 0, %bb16 ]		; <int>	[#uses=2]
	%reg328 = phi double [ %reg329, %bb17 ], [ 0.000000, %bb16 ]		; <double>	[#uses=1]
	%cast1976 = cast int %reg327 to uint		; <uint>	[#uses=1]
	%reg231 = shl uint %cast1976, ubyte 3		; <uint>	[#uses=1]
	%reg232 = add uint %reg231, 48		; <uint>	[#uses=1]
	%cast233 = cast uint %reg232 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg235 = add %bodyptr %reg118, %cast233		; <%bodyptr>	[#uses=1]
	%cast1977 = cast %bodyptr %reg235 to double *		; <double *>	[#uses=1]
	%reg242 = load double * %cast1977		; <double>	[#uses=2]
	%reg244 = mul double %reg242, %reg242		; <double>	[#uses=1]
	%reg329 = add double %reg328, %reg244		; <double>	[#uses=2]
	%reg330 = add int %reg327, 1		; <int>	[#uses=2]
	%cond1911 = setle int %reg330, 2		; <bool>	[#uses=1]
	br bool %cond1911, label %bb17, label %bb18

bb18:					;[#uses=3]
	%reg331 = phi double [ %reg329, %bb17 ], [ 0.000000, %bb16 ]		; <double>	[#uses=2]
	%cast1979 = cast double %reg331 to long		; <long>	[#uses=1]
	%cast1980 = cast double 1.000000 to long		; <long>	[#uses=1]
	%cond1912 = setgt long %cast1979, %cast1980		; <bool>	[#uses=1]
	br bool %cond1912, label %bb14, label %bb19

bb19:					;[#uses=2]
	%reg247 = call double (double) * %sqrt( double %reg331 )		; <double>	[#uses=1]
	%reg128 = div double %reg129, %reg247		; <double>	[#uses=1]
	%cond1913 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond1913, label %bb21, label %bb20

bb20:					;[#uses=3]
	%reg332 = phi int [ %reg333, %bb20 ], [ 0, %bb19 ]		; <int>	[#uses=2]
	%cast1985 = cast int %reg332 to uint		; <uint>	[#uses=1]
	%reg250 = shl uint %cast1985, ubyte 3		; <uint>	[#uses=1]
	%reg251 = add uint %reg250, 48		; <uint>	[#uses=1]
	%cast252 = cast uint %reg251 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg254 = add %bodyptr %reg118, %cast252		; <%bodyptr>	[#uses=2]
	%cast1986 = cast %bodyptr %reg254 to double *		; <double *>	[#uses=1]
	%reg261 = load double * %cast1986		; <double>	[#uses=1]
	%reg262 = mul double %reg261, %reg128		; <double>	[#uses=1]
	%cast1987 = cast %bodyptr %reg254 to double *		; <double *>	[#uses=1]
	store double %reg262, double * %cast1987
	%reg333 = add int %reg332, 1		; <int>	[#uses=2]
	%cond1914 = setle int %reg333, 2		; <bool>	[#uses=1]
	br bool %cond1914, label %bb20, label %bb21

bb21:					;[#uses=3]
	%cond1915 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond1915, label %bb23, label %bb22

bb22:					;[#uses=3]
	%reg334 = phi int [ %reg335, %bb22 ], [ 0, %bb21 ]		; <int>	[#uses=2]
	%cast1989 = cast int %reg334 to uint		; <uint>	[#uses=1]
	%reg265 = shl uint %cast1989, ubyte 3		; <uint>	[#uses=2]
	%reg266 = add uint %reg265, 24		; <uint>	[#uses=1]
	%cast267 = cast uint %reg266 to %datapoints *		; <%datapoints *>	[#uses=1]
	%reg271 = add %datapoints * %retval, %cast267		; <%datapoints *>	[#uses=2]
	%reg282 = add uint %reg265, 48		; <uint>	[#uses=1]
	%cast283 = cast uint %reg282 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg285 = add %bodyptr %reg118, %cast283		; <%bodyptr>	[#uses=1]
	%cast1990 = cast %datapoints * %reg271 to double *		; <double *>	[#uses=1]
	%reg286 = load double * %cast1990		; <double>	[#uses=1]
	%cast1991 = cast %bodyptr %reg285 to double *		; <double *>	[#uses=1]
	%reg287 = load double * %cast1991		; <double>	[#uses=1]
	%reg288 = add double %reg286, %reg287		; <double>	[#uses=1]
	%cast1992 = cast %datapoints * %reg271 to double *		; <double *>	[#uses=1]
	store double %reg288, double * %cast1992
	%reg335 = add int %reg334, 1		; <int>	[#uses=2]
	%cond1916 = setle int %reg335, 2		; <bool>	[#uses=1]
	br bool %cond1916, label %bb22, label %bb23

bb23:					;[#uses=6]
	%reg336 = add int %reg304, 1		; <int>	[#uses=2]
	%cond1917 = setlt int %reg336, %nbody		; <bool>	[#uses=1]
	br bool %cond1917, label %bb6, label %bb24

bb24:					;[#uses=2]
	%reg337 = phi %bodyptr [ %reg118, %bb23 ], [ %reg117, %bb5 ]		; <%bodyptr>	[#uses=2]
	store %bodyptr null, %bodyptr %reg337, ubyte 9
	%reg290 = load %bodyptr %reg117, ubyte 9		; <%bodyptr>	[#uses=1]
	store %bodyptr %reg290, %datapoints * %retval, ubyte 2
	store %bodyptr %reg337, %datapoints * %retval, ubyte 3
	%cast2001 = cast %datapoints * %retval to ulong *		; <ulong *>	[#uses=1]
	%reg291 = load ulong * %cast2001		; <ulong>	[#uses=1]
	%cast2002 = cast %datapoints * %StructReturn to ulong *		; <ulong *>	[#uses=1]
	store ulong %reg291, ulong * %cast2002
	%cast2003 = cast ulong 8 to %datapoints *		; <%datapoints *>	[#uses=1]
	%reg1924 = add %datapoints * %retval, %cast2003		; <%datapoints *>	[#uses=1]
	%cast2004 = cast %datapoints * %reg1924 to ulong *		; <ulong *>	[#uses=1]
	%reg292 = load ulong * %cast2004		; <ulong>	[#uses=1]
	%cast2005 = cast ulong 8 to %datapoints *		; <%datapoints *>	[#uses=1]
	%reg1925 = add %datapoints * %StructReturn, %cast2005		; <%datapoints *>	[#uses=1]
	%cast2006 = cast %datapoints * %reg1925 to ulong *		; <ulong *>	[#uses=1]
	store ulong %reg292, ulong * %cast2006
	%cast2007 = cast ulong 16 to %datapoints *		; <%datapoints *>	[#uses=1]
	%reg1926 = add %datapoints * %retval, %cast2007		; <%datapoints *>	[#uses=1]
	%cast2008 = cast %datapoints * %reg1926 to ulong *		; <ulong *>	[#uses=1]
	%reg293 = load ulong * %cast2008		; <ulong>	[#uses=1]
	%cast2009 = cast ulong 16 to %datapoints *		; <%datapoints *>	[#uses=1]
	%reg1927 = add %datapoints * %StructReturn, %cast2009		; <%datapoints *>	[#uses=1]
	%cast2010 = cast %datapoints * %reg1927 to ulong *		; <ulong *>	[#uses=1]
	store ulong %reg293, ulong * %cast2010
	%eptr2744 = getelementptr %datapoints * %retval, ubyte 1		; <%vector *>	[#uses=1]
	%cast2012 = cast %vector * %eptr2744 to ulong *		; <ulong *>	[#uses=1]
	%reg294 = load ulong * %cast2012		; <ulong>	[#uses=1]
	%eptr2745 = getelementptr %datapoints * %StructReturn, ubyte 1		; <%vector *>	[#uses=1]
	%cast2014 = cast %vector * %eptr2745 to ulong *		; <ulong *>	[#uses=1]
	store ulong %reg294, ulong * %cast2014
	%cast2015 = cast ulong 32 to %datapoints *		; <%datapoints *>	[#uses=1]
	%reg1930 = add %datapoints * %retval, %cast2015		; <%datapoints *>	[#uses=1]
	%cast2016 = cast %datapoints * %reg1930 to ulong *		; <ulong *>	[#uses=1]
	%reg295 = load ulong * %cast2016		; <ulong>	[#uses=1]
	%cast2017 = cast ulong 32 to %datapoints *		; <%datapoints *>	[#uses=1]
	%reg1931 = add %datapoints * %StructReturn, %cast2017		; <%datapoints *>	[#uses=1]
	%cast2018 = cast %datapoints * %reg1931 to ulong *		; <ulong *>	[#uses=1]
	store ulong %reg295, ulong * %cast2018
	%cast2019 = cast ulong 40 to %datapoints *		; <%datapoints *>	[#uses=1]
	%reg1932 = add %datapoints * %retval, %cast2019		; <%datapoints *>	[#uses=1]
	%cast2020 = cast %datapoints * %reg1932 to ulong *		; <ulong *>	[#uses=1]
	%reg296 = load ulong * %cast2020		; <ulong>	[#uses=1]
	%cast2021 = cast ulong 40 to %datapoints *		; <%datapoints *>	[#uses=1]
	%reg1933 = add %datapoints * %StructReturn, %cast2021		; <%datapoints *>	[#uses=1]
	%cast2022 = cast %datapoints * %reg1933 to ulong *		; <ulong *>	[#uses=1]
	store ulong %reg296, ulong * %cast2022
	%reg297 = load %datapoints * %retval, ubyte 2		; <%bodyptr>	[#uses=1]
	store %bodyptr %reg297, %datapoints * %StructReturn, ubyte 2
	%reg298 = load %datapoints * %retval, ubyte 3		; <%bodyptr>	[#uses=1]
	store %bodyptr %reg298, %datapoints * %StructReturn, ubyte 3
	ret %datapoints * %StructReturn

bb25:					;[#uses=0]
	%cast2031 = cast ulong 42 to %datapoints *		; <%datapoints *>	[#uses=1]
	ret %datapoints * %cast2031
end

void "stepsystem"(%treeptr %t, int %nstep)
begin
bb1:					;[#uses=0]
	%reg118 = load %treeptr %t, ubyte 2		; <%nodeptr>	[#uses=2]
	%cond1816 = seteq %nodeptr %reg118, null		; <bool>	[#uses=1]
	br bool %cond1816, label %bb3, label %bb2

bb2:					;[#uses=1]
	call void (%nodeptr) * %freetree1( %nodeptr %reg118 )
	store %nodeptr null, %treeptr %t, ubyte 2
	br label %bb3

bb3:					;[#uses=2]
	%reg121 = load int * %nbody		; <int>	[#uses=1]
	%cast1818 = cast ulong 0 to int		; <int>	[#uses=1]
	%cast1827 = cast ulong 42 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg113 = call %nodeptr (%bodyptr, int, %treeptr, int, int) * %maketree( %bodyptr %cast1827, int %reg121, %treeptr %t, int %nstep, int %cast1818 )		; <%nodeptr>	[#uses=1]
	store %nodeptr %reg113, %treeptr %t, ubyte 2
	call void (%treeptr, int) * %computegrav( %treeptr %t, int %nstep )
	%eptr1836 = getelementptr %treeptr %t, ubyte 4		; <[64 x %bodyptr] *>	[#uses=1]
	%cast1831 = cast [64 x %bodyptr] * %eptr1836 to %bodyptr *		; <%bodyptr *>	[#uses=1]
	%reg123 = load %bodyptr * %cast1831		; <%bodyptr>	[#uses=1]
	call void (%bodyptr, int) * %vp( %bodyptr %reg123, int %nstep )
	ret void
end

declare %treeptr "old_main"(...)

void "my_free"(%nodeptr %n)
begin
bb1:					;[#uses=0]
	%reg108 = load %nodeptr %n, ubyte 0		; <short>	[#uses=1]
	%cast108 = cast short %reg108 to ushort		; <ushort>	[#uses=1]
	%cond1850 = setne ushort %cast108, 1		; <bool>	[#uses=1]
	br bool %cond1850, label %bb3, label %bb2

bb2:					;[#uses=1]
	%reg109 = load %bodyptr * %bp_free_list		; <%bodyptr>	[#uses=1]
	%cast1854 = cast ulong 128 to %nodeptr		; <%nodeptr>	[#uses=1]
	%reg1851 = add %nodeptr %n, %cast1854		; <%nodeptr>	[#uses=1]
	%cast1855 = cast %nodeptr %reg1851 to %bodyptr *		; <%bodyptr *>	[#uses=1]
	store %bodyptr %reg109, %bodyptr * %cast1855
	%cast1856 = cast %bodyptr * %bp_free_list to %nodeptr *		; <%nodeptr *>	[#uses=1]
	store %nodeptr %n, %nodeptr * %cast1856
	br label %bb4

bb3:					;[#uses=1]
	%reg110 = load %nodeptr * %cp_free_list		; <%nodeptr>	[#uses=1]
	%cast1857 = cast ulong 112 to %nodeptr		; <%nodeptr>	[#uses=1]
	%reg1852 = add %nodeptr %n, %cast1857		; <%nodeptr>	[#uses=1]
	%cast1858 = cast %nodeptr %reg1852 to %nodeptr *		; <%nodeptr *>	[#uses=1]
	store %nodeptr %reg110, %nodeptr * %cast1858
	store %nodeptr %n, %nodeptr * %cp_free_list
	br label %bb4

bb4:					;[#uses=2]
	ret void
end

%bodyptr "ubody_alloc"(int %p)
begin
bb1:					;[#uses=0]
	%cast1861 = cast ulong 144 to uint		; <uint>	[#uses=1]
	%reg110 = call sbyte * (...) * %malloc( uint %cast1861 )		; <sbyte *>	[#uses=5]
	%cast1866 = cast sbyte * %reg110 to ushort *		; <ushort *>	[#uses=1]
	store ushort 1, ushort * %cast1866
	%cast1867 = cast ulong 40 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1862 = add sbyte * %reg110, %cast1867		; <sbyte *>	[#uses=1]
	%cast1868 = cast sbyte * %reg1862 to int *		; <int *>	[#uses=1]
	store int %p, int * %cast1868
	%cast1869 = cast ulong 136 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1863 = add sbyte * %reg110, %cast1869		; <sbyte *>	[#uses=1]
	%cast1870 = cast sbyte * %reg1863 to ulong * *		; <ulong * *>	[#uses=1]
	store ulong * null, ulong * * %cast1870
	%cast1871 = cast ulong 44 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1864 = add sbyte * %reg110, %cast1871		; <sbyte *>	[#uses=1]
	%cast1872 = cast sbyte * %reg1864 to int *		; <int *>	[#uses=1]
	store int %p, int * %cast1872
	%cast1873 = cast sbyte * %reg110 to %bodyptr		; <%bodyptr>	[#uses=1]
	ret %bodyptr %cast1873

bb2:					;[#uses=0]
	%cast1874 = cast ulong 42 to %bodyptr		; <%bodyptr>	[#uses=1]
	ret %bodyptr %cast1874
end

declare %bodyptr "movebodies"(%bodyptr, int)

void "freetree"(%nodeptr %n)
begin
bb1:					;[#uses=0]
	%cond1837 = seteq %nodeptr %n, null		; <bool>	[#uses=1]
	br bool %cond1837, label %bb8, label %bb2

bb2:					;[#uses=1]
	%reg110 = load %nodeptr %n, ubyte 0		; <short>	[#uses=1]
	%cast110 = cast short %reg110 to ushort		; <ushort>	[#uses=1]
	%cond1838 = seteq ushort %cast110, 1		; <bool>	[#uses=1]
	br bool %cond1838, label %bb8, label %bb3

bb3:					;[#uses=2]
	%cond1839 = setlt long 7, 0		; <bool>	[#uses=1]
	br bool %cond1839, label %bb7, label %bb4

bb4:					;[#uses=2]
	%reg117 = phi int [ %reg118, %bb6 ], [ 7, %bb3 ]		; <int>	[#uses=2]
	%cast1844 = cast int %reg117 to uint		; <uint>	[#uses=1]
	%reg112 = shl uint %cast1844, ubyte 3		; <uint>	[#uses=1]
	%reg113 = add uint %reg112, 48		; <uint>	[#uses=1]
	%cast114 = cast uint %reg113 to %nodeptr		; <%nodeptr>	[#uses=1]
	%reg116 = add %nodeptr %n, %cast114		; <%nodeptr>	[#uses=1]
	%cast1845 = cast %nodeptr %reg116 to %nodeptr *		; <%nodeptr *>	[#uses=1]
	%reg108 = load %nodeptr * %cast1845		; <%nodeptr>	[#uses=2]
	%cond1840 = seteq %nodeptr %reg108, null		; <bool>	[#uses=1]
	br bool %cond1840, label %bb6, label %bb5

bb5:					;[#uses=1]
	call void (%nodeptr) * %freetree( %nodeptr %reg108 )
	br label %bb6

bb6:					;[#uses=3]
	%reg118 = add int %reg117, -1		; <int>	[#uses=2]
	%cond1841 = setge int %reg118, 0		; <bool>	[#uses=1]
	br bool %cond1841, label %bb4, label %bb7

bb7:					;[#uses=2]
	call void (%nodeptr) * %my_free( %nodeptr %n )
	br label %bb8

bb8:					;[#uses=3]
	ret void
end

void "freetree1"(%nodeptr %n)
begin
bb1:					;[#uses=0]
	call void (%nodeptr) * %freetree( %nodeptr %n )
	ret void
end

declare int "dealwithargs"(...)

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

int "main"(int %argc, sbyte * %argv)
begin
bb1:					;[#uses=0]
	call void () * %__main( )
	call %iproc %dealwithargs( int %argc, sbyte * %argv )		; <int>:0	[#uses=0]
	%reg111 = load int * %nbody		; <int>	[#uses=1]
	%reg112 = load int * %NumNodes		; <int>	[#uses=1]
	%cast1000 = cast [27 x sbyte] * %__intern_LC0 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast1000, int %reg111, int %reg112 )		; <int>:1	[#uses=0]
	call %treeptr (...) * %old_main( )		; <%treeptr>:0	[#uses=0]
	ret int 42
end

declare int "srand"(...)

declare int "old_subindex"(...)

declare int "error"(...)

%cellptr "cell_alloc"(int %p)
begin
bb1:					;[#uses=0]
	%reg110 = load %nodeptr * %cp_free_list		; <%nodeptr>	[#uses=3]
	%cast1884 = cast %nodeptr %reg110 to ulong * *		; <ulong * *>	[#uses=1]
	%cond1875 = seteq %nodeptr %reg110, null		; <bool>	[#uses=1]
	br bool %cond1875, label %bb3, label %bb2

bb2:					;[#uses=2]
	%cast1883 = cast ulong 112 to ulong * *		; <ulong * *>	[#uses=1]
	%reg1876 = add ulong * * %cast1884, %cast1883		; <ulong * *>	[#uses=1]
	%reg112 = load ulong * * %reg1876		; <ulong *>	[#uses=1]
	%cast1894 = cast %nodeptr * %cp_free_list to ulong * *		; <ulong * *>	[#uses=1]
	store ulong * %reg112, ulong * * %cast1894
	br label %bb4

bb3:					;[#uses=2]
	%cast1877 = cast ulong 120 to uint		; <uint>	[#uses=1]
	%reg114 = call sbyte * (...) * %malloc( uint %cast1877 )		; <sbyte *>	[#uses=1]
	br label %bb4

bb4:					;[#uses=3]
	%reg125 = phi sbyte * [ %reg114, %bb3 ], [ %cast1893, %bb2 ]		; <sbyte *>	[#uses=4]
	%cast1893 = cast %nodeptr %reg110 to sbyte *		; <sbyte *>	[#uses=1]
	%cast1891 = cast sbyte * %reg125 to %cellptr		; <%cellptr>	[#uses=1]
	%cast1889 = cast sbyte * %reg125 to ulong * *		; <ulong * *>	[#uses=1]
	%cast1887 = cast sbyte * %reg125 to int *		; <int *>	[#uses=1]
	%cast1885 = cast sbyte * %reg125 to ushort *		; <ushort *>	[#uses=1]
	store ushort 2, ushort * %cast1885
	%cast1886 = cast ulong 40 to int *		; <int *>	[#uses=1]
	%reg1878 = add int * %cast1887, %cast1886		; <int *>	[#uses=1]
	store int %p, int * %reg1878
	%cond1879 = setgt long 0, 7		; <bool>	[#uses=1]
	br bool %cond1879, label %bb6, label %bb5

bb5:					;[#uses=3]
	%reg126 = phi int [ %reg127, %bb5 ], [ 0, %bb4 ]		; <int>	[#uses=2]
	%cast1888 = cast int %reg126 to uint		; <uint>	[#uses=1]
	%reg117 = shl uint %cast1888, ubyte 3		; <uint>	[#uses=1]
	%reg118 = add uint %reg117, 48		; <uint>	[#uses=1]
	%cast119 = cast uint %reg118 to ulong * *		; <ulong * *>	[#uses=1]
	%reg121 = add ulong * * %cast1889, %cast119		; <ulong * *>	[#uses=1]
	store ulong * null, ulong * * %reg121
	%reg127 = add int %reg126, 1		; <int>	[#uses=2]
	%cond1880 = setle int %reg127, 7		; <bool>	[#uses=1]
	br bool %cond1880, label %bb5, label %bb6

bb6:					;[#uses=2]
	ret %cellptr %cast1891

bb7:					;[#uses=0]
	%cast1892 = cast ulong 42 to %cellptr		; <%cellptr>	[#uses=1]
	ret %cellptr %cast1892
end

%hgsptr "gravsub"(%hgsptr %StructReturn, %nodeptr %p, %hgsptr %hg)
begin
bb0:					;[#uses=0]
	%ai = alloca %vector		; <%vector *>	[#uses=2]
	%quaddr = alloca %vector		; <%vector *>	[#uses=0]
	%dr = alloca %vector		; <%vector *>	[#uses=3]
	br label %bb1

bb1:					;[#uses=2]
	%cond3140 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond3140, label %bb3, label %bb2

bb2:					;[#uses=3]
	%reg214 = phi int [ %reg215, %bb2 ], [ 0, %bb1 ]		; <int>	[#uses=2]
	%cast3165 = cast int %reg214 to uint		; <uint>	[#uses=1]
	%reg119 = shl uint %cast3165, ubyte 3		; <uint>	[#uses=3]
	%cast120 = cast uint %reg119 to ulong *		; <ulong *>	[#uses=1]
	%cast3166 = cast %vector * %dr to ulong *		; <ulong *>	[#uses=1]
	%reg124 = add ulong * %cast3166, %cast120		; <ulong *>	[#uses=1]
	%reg127 = add uint %reg119, 16		; <uint>	[#uses=1]
	%cast128 = cast uint %reg127 to %nodeptr		; <%nodeptr>	[#uses=1]
	%reg130 = add %nodeptr %p, %cast128		; <%nodeptr>	[#uses=1]
	%reg133 = add uint %reg119, 8		; <uint>	[#uses=1]
	%cast134 = cast uint %reg133 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg136 = add %hgsptr %hg, %cast134		; <%hgsptr>	[#uses=1]
	%cast3167 = cast %nodeptr %reg130 to double *		; <double *>	[#uses=1]
	%reg137 = load double * %cast3167		; <double>	[#uses=1]
	%reg138 = load %hgsptr %reg136, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast138 = cast %bodyptr %reg138 to double		; <double>	[#uses=1]
	%reg139 = sub double %reg137, %cast138		; <double>	[#uses=1]
	%cast3169 = cast ulong * %reg124 to double *		; <double *>	[#uses=1]
	store double %reg139, double * %cast3169
	%reg215 = add int %reg214, 1		; <int>	[#uses=2]
	%cond3141 = setle int %reg215, 2		; <bool>	[#uses=1]
	br bool %cond3141, label %bb2, label %bb3

bb3:					;[#uses=5]
	%cond3142 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond3142, label %bb5, label %bb4

bb4:					;[#uses=5]
	%reg216 = phi int [ %reg219, %bb4 ], [ 0, %bb3 ]		; <int>	[#uses=2]
	%reg217 = phi double [ %reg218, %bb4 ], [ 0.000000, %bb3 ]		; <double>	[#uses=1]
	%cast3171 = cast int %reg216 to uint		; <uint>	[#uses=1]
	%reg142 = shl uint %cast3171, ubyte 3		; <uint>	[#uses=1]
	%cast143 = cast uint %reg142 to ulong *		; <ulong *>	[#uses=1]
	%cast3172 = cast %vector * %dr to ulong *		; <ulong *>	[#uses=1]
	%reg147 = add ulong * %cast3172, %cast143		; <ulong *>	[#uses=1]
	%cast3173 = cast ulong * %reg147 to double *		; <double *>	[#uses=1]
	%reg155 = load double * %cast3173		; <double>	[#uses=2]
	%reg157 = mul double %reg155, %reg155		; <double>	[#uses=1]
	%reg218 = add double %reg217, %reg157		; <double>	[#uses=2]
	%reg219 = add int %reg216, 1		; <int>	[#uses=2]
	%cond3143 = setle int %reg219, 2		; <bool>	[#uses=1]
	br bool %cond3143, label %bb4, label %bb5

bb5:					;[#uses=3]
	%reg220 = phi double [ %reg218, %bb4 ], [ 0.000000, %bb3 ]		; <double>	[#uses=1]
	%reg221 = add double %reg220, 0.002500		; <double>	[#uses=2]
	%reg161 = call double (double) * %sqrt( double %reg221 )		; <double>	[#uses=1]
	%reg162 = load %nodeptr %p, ubyte 1		; <double>	[#uses=1]
	%reg111 = div double %reg162, %reg161		; <double>	[#uses=2]
	%reg163 = load %hgsptr %hg, ubyte 2		; <double>	[#uses=1]
	%reg164 = sub double %reg163, %reg111		; <double>	[#uses=1]
	store double %reg164, %hgsptr %hg, ubyte 2
	%reg112 = div double %reg111, %reg221		; <double>	[#uses=1]
	%cond3147 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond3147, label %bb7, label %bb6

bb6:					;[#uses=3]
	%reg222 = phi int [ %reg223, %bb6 ], [ 0, %bb5 ]		; <int>	[#uses=2]
	%cast3189 = cast int %reg222 to uint		; <uint>	[#uses=1]
	%reg167 = shl uint %cast3189, ubyte 3		; <uint>	[#uses=1]
	%cast168 = cast uint %reg167 to ulong *		; <ulong *>	[#uses=2]
	%cast3190 = cast %vector * %ai to ulong *		; <ulong *>	[#uses=1]
	%reg172 = add ulong * %cast3190, %cast168		; <ulong *>	[#uses=1]
	%cast3191 = cast %vector * %dr to ulong *		; <ulong *>	[#uses=1]
	%reg179 = add ulong * %cast3191, %cast168		; <ulong *>	[#uses=1]
	%cast3192 = cast ulong * %reg179 to double *		; <double *>	[#uses=1]
	%reg180 = load double * %cast3192		; <double>	[#uses=1]
	%reg181 = mul double %reg180, %reg112		; <double>	[#uses=1]
	%cast3193 = cast ulong * %reg172 to double *		; <double *>	[#uses=1]
	store double %reg181, double * %cast3193
	%reg223 = add int %reg222, 1		; <int>	[#uses=2]
	%cond3148 = setle int %reg223, 2		; <bool>	[#uses=1]
	br bool %cond3148, label %bb6, label %bb7

bb7:					;[#uses=3]
	%cond3149 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond3149, label %bb9, label %bb8

bb8:					;[#uses=3]
	%reg224 = phi int [ %reg225, %bb8 ], [ 0, %bb7 ]		; <int>	[#uses=2]
	%cast3195 = cast int %reg224 to uint		; <uint>	[#uses=1]
	%reg184 = shl uint %cast3195, ubyte 3		; <uint>	[#uses=2]
	%reg185 = add uint %reg184, 40		; <uint>	[#uses=1]
	%cast186 = cast uint %reg185 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg188 = add %hgsptr %hg, %cast186		; <%hgsptr>	[#uses=2]
	%cast197 = cast uint %reg184 to ulong *		; <ulong *>	[#uses=1]
	%cast3196 = cast %vector * %ai to ulong *		; <ulong *>	[#uses=1]
	%reg201 = add ulong * %cast3196, %cast197		; <ulong *>	[#uses=1]
	%reg202 = load %hgsptr %reg188, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast202 = cast %bodyptr %reg202 to double		; <double>	[#uses=1]
	%cast3198 = cast ulong * %reg201 to double *		; <double *>	[#uses=1]
	%reg203 = load double * %cast3198		; <double>	[#uses=1]
	%reg204 = add double %cast202, %reg203		; <double>	[#uses=1]
	%cast3199 = cast %hgsptr %reg188 to double *		; <double *>	[#uses=1]
	store double %reg204, double * %cast3199
	%reg225 = add int %reg224, 1		; <int>	[#uses=2]
	%cond3150 = setle int %reg225, 2		; <bool>	[#uses=1]
	br bool %cond3150, label %bb8, label %bb9

bb9:					;[#uses=2]
	%reg206 = load %hgsptr %hg, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast206 = cast %bodyptr %reg206 to ulong		; <ulong>	[#uses=1]
	%cast3202 = cast %hgsptr %StructReturn to ulong *		; <ulong *>	[#uses=1]
	store ulong %cast206, ulong * %cast3202
	%eptr3521 = getelementptr %hgsptr %hg, ubyte 1		; <%vector *>	[#uses=1]
	%cast3204 = cast %vector * %eptr3521 to ulong *		; <ulong *>	[#uses=1]
	%reg207 = load ulong * %cast3204		; <ulong>	[#uses=1]
	%eptr3522 = getelementptr %hgsptr %StructReturn, ubyte 1		; <%vector *>	[#uses=1]
	%cast3206 = cast %vector * %eptr3522 to ulong *		; <ulong *>	[#uses=1]
	store ulong %reg207, ulong * %cast3206
	%cast3207 = cast ulong 16 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg3153 = add %hgsptr %hg, %cast3207		; <%hgsptr>	[#uses=1]
	%reg208 = load %hgsptr %reg3153, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast208 = cast %bodyptr %reg208 to ulong		; <ulong>	[#uses=1]
	%cast3209 = cast ulong 16 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg3154 = add %hgsptr %StructReturn, %cast3209		; <%hgsptr>	[#uses=1]
	%cast3210 = cast %hgsptr %reg3154 to ulong *		; <ulong *>	[#uses=1]
	store ulong %cast208, ulong * %cast3210
	%cast3211 = cast ulong 24 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg3155 = add %hgsptr %hg, %cast3211		; <%hgsptr>	[#uses=1]
	%reg209 = load %hgsptr %reg3155, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast209 = cast %bodyptr %reg209 to ulong		; <ulong>	[#uses=1]
	%cast3213 = cast ulong 24 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg3156 = add %hgsptr %StructReturn, %cast3213		; <%hgsptr>	[#uses=1]
	%cast3214 = cast %hgsptr %reg3156 to ulong *		; <ulong *>	[#uses=1]
	store ulong %cast209, ulong * %cast3214
	%reg210 = load %hgsptr %hg, ubyte 2		; <double>	[#uses=1]
	store double %reg210, %hgsptr %StructReturn, ubyte 2
	%eptr3530 = getelementptr %hgsptr %hg, ubyte 3		; <%vector *>	[#uses=1]
	%cast3220 = cast %vector * %eptr3530 to ulong *		; <ulong *>	[#uses=1]
	%reg211 = load ulong * %cast3220		; <ulong>	[#uses=1]
	%eptr3531 = getelementptr %hgsptr %StructReturn, ubyte 3		; <%vector *>	[#uses=1]
	%cast3222 = cast %vector * %eptr3531 to ulong *		; <ulong *>	[#uses=1]
	store ulong %reg211, ulong * %cast3222
	%cast3223 = cast ulong 48 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg3161 = add %hgsptr %hg, %cast3223		; <%hgsptr>	[#uses=1]
	%reg212 = load %hgsptr %reg3161, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast212 = cast %bodyptr %reg212 to ulong		; <ulong>	[#uses=1]
	%cast3225 = cast ulong 48 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg3162 = add %hgsptr %StructReturn, %cast3225		; <%hgsptr>	[#uses=1]
	%cast3226 = cast %hgsptr %reg3162 to ulong *		; <ulong *>	[#uses=1]
	store ulong %cast212, ulong * %cast3226
	%cast3227 = cast ulong 56 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg3163 = add %hgsptr %hg, %cast3227		; <%hgsptr>	[#uses=1]
	%reg213 = load %hgsptr %reg3163, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast213 = cast %bodyptr %reg213 to ulong		; <ulong>	[#uses=1]
	%cast3229 = cast ulong 56 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg3164 = add %hgsptr %StructReturn, %cast3229		; <%hgsptr>	[#uses=1]
	%cast3230 = cast %hgsptr %reg3164 to ulong *		; <ulong *>	[#uses=1]
	store ulong %cast213, ulong * %cast3230
	ret %hgsptr %StructReturn

bb10:					;[#uses=0]
	%cast3231 = cast ulong 42 to %hgsptr		; <%hgsptr>	[#uses=1]
	ret %hgsptr %cast3231
end

declare %hgsptr "walksub"(%hgsptr, %nodeptr, double, double, %hgsptr, int)

short "subdivp"(%nodeptr %p, double %dsq, double %tolsq, %hgsptr %hg)
begin
bb0:					;[#uses=0]
	%dr = alloca %vector		; <%vector *>	[#uses=2]
	%pos = alloca %vector		; <%vector *>	[#uses=0]
	br label %bb1

bb1:					;[#uses=1]
	%reg113 = load %nodeptr %p, ubyte 0		; <short>	[#uses=1]
	%cast113 = cast short %reg113 to ushort		; <ushort>	[#uses=1]
	%cond3538 = setne ushort %cast113, 1		; <bool>	[#uses=1]
	br bool %cond3538, label %bb3, label %bb2

bb2:					;[#uses=1]
	ret short 0

bb3:					;[#uses=2]
	%cond3539 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond3539, label %bb5, label %bb4

bb4:					;[#uses=3]
	%reg159 = phi int [ %reg160, %bb4 ], [ 0, %bb3 ]		; <int>	[#uses=2]
	%cast3545 = cast int %reg159 to uint		; <uint>	[#uses=1]
	%reg118 = shl uint %cast3545, ubyte 3		; <uint>	[#uses=3]
	%cast119 = cast uint %reg118 to ulong *		; <ulong *>	[#uses=1]
	%cast3546 = cast %vector * %dr to ulong *		; <ulong *>	[#uses=1]
	%reg123 = add ulong * %cast3546, %cast119		; <ulong *>	[#uses=1]
	%reg126 = add uint %reg118, 16		; <uint>	[#uses=1]
	%cast127 = cast uint %reg126 to %nodeptr		; <%nodeptr>	[#uses=1]
	%reg129 = add %nodeptr %p, %cast127		; <%nodeptr>	[#uses=1]
	%reg132 = add uint %reg118, 8		; <uint>	[#uses=1]
	%cast133 = cast uint %reg132 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg135 = add %hgsptr %hg, %cast133		; <%hgsptr>	[#uses=1]
	%cast3547 = cast %nodeptr %reg129 to double *		; <double *>	[#uses=1]
	%reg136 = load double * %cast3547		; <double>	[#uses=1]
	%reg137 = load %hgsptr %reg135, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast137 = cast %bodyptr %reg137 to double		; <double>	[#uses=1]
	%reg138 = sub double %reg136, %cast137		; <double>	[#uses=1]
	%cast3549 = cast ulong * %reg123 to double *		; <double *>	[#uses=1]
	store double %reg138, double * %cast3549
	%reg160 = add int %reg159, 1		; <int>	[#uses=2]
	%cond3540 = setle int %reg160, 2		; <bool>	[#uses=1]
	br bool %cond3540, label %bb4, label %bb5

bb5:					;[#uses=5]
	%cond3541 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond3541, label %bb7, label %bb6

bb6:					;[#uses=5]
	%reg161 = phi int [ %reg164, %bb6 ], [ 0, %bb5 ]		; <int>	[#uses=2]
	%reg162 = phi double [ %reg163, %bb6 ], [ 0.000000, %bb5 ]		; <double>	[#uses=1]
	%cast3551 = cast int %reg161 to uint		; <uint>	[#uses=1]
	%reg141 = shl uint %cast3551, ubyte 3		; <uint>	[#uses=1]
	%cast142 = cast uint %reg141 to ulong *		; <ulong *>	[#uses=1]
	%cast3552 = cast %vector * %dr to ulong *		; <ulong *>	[#uses=1]
	%reg146 = add ulong * %cast3552, %cast142		; <ulong *>	[#uses=1]
	%cast3553 = cast ulong * %reg146 to double *		; <double *>	[#uses=1]
	%reg154 = load double * %cast3553		; <double>	[#uses=2]
	%reg156 = mul double %reg154, %reg154		; <double>	[#uses=1]
	%reg163 = add double %reg162, %reg156		; <double>	[#uses=2]
	%reg164 = add int %reg161, 1		; <int>	[#uses=2]
	%cond3542 = setle int %reg164, 2		; <bool>	[#uses=1]
	br bool %cond3542, label %bb6, label %bb7

bb7:					;[#uses=3]
	%reg165 = phi double [ %reg163, %bb6 ], [ 0.000000, %bb5 ]		; <double>	[#uses=1]
	%reg158 = mul double %tolsq, %reg165		; <double>	[#uses=1]
	%cast3555 = cast double %reg158 to long		; <long>	[#uses=1]
	%cast3556 = cast double %dsq to long		; <long>	[#uses=1]
	%cond3543 = setlt long %cast3555, %cast3556		; <bool>	[#uses=1]
	br bool %cond3543, label %bb8, label %bb9

bb8:					;[#uses=2]
	br label %bb9

bb9:					;[#uses=2]
	%reg167 = phi ushort [ 1, %bb8 ], [ 0, %bb7 ]		; <ushort>	[#uses=1]
	%cast3557 = cast ushort %reg167 to short		; <short>	[#uses=1]
	ret short %cast3557

bb10:					;[#uses=0]
	ret short 42
end

void "grav"(double %rsize, %nodeptr %rt, %bodyptr %bodies, int %nstep, double %dthf)
begin
bb1:					;[#uses=1]
	%cond2765 = seteq %bodyptr %bodies, null		; <bool>	[#uses=1]
	br bool %cond2765, label %bb3, label %bb2

bb2:					;[#uses=3]
	%reg116 = phi %bodyptr [ %reg117, %bb2 ], [ %bodies, %bb1 ]		; <%bodyptr>	[#uses=2]
	call void (double, %nodeptr, %bodyptr, int, double) * %gravstep( double %rsize, %nodeptr %rt, %bodyptr %reg116, int %nstep, double %dthf )
	%reg117 = load %bodyptr %reg116, ubyte 10		; <%bodyptr>	[#uses=2]
	%cond2767 = setne %bodyptr %reg117, null		; <bool>	[#uses=1]
	br bool %cond2767, label %bb2, label %bb3

bb3:					;[#uses=2]
	ret void
end

void "hackgrav"(%bodyptr %p, double %rsize, %nodeptr %rt)
begin
bb0:					;[#uses=0]
	%hg = alloca %hgstruct		; <%hgsptr>	[#uses=15]
	br label %bb1

bb1:					;[#uses=2]
	store %bodyptr %p, %hgsptr %hg, ubyte 0
	%cond3043 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond3043, label %bb3, label %bb2

bb2:					;[#uses=3]
	%reg167 = phi int [ %reg168, %bb2 ], [ 0, %bb1 ]		; <int>	[#uses=2]
	%cast3069 = cast int %reg167 to uint		; <uint>	[#uses=1]
	%reg113 = shl uint %cast3069, ubyte 3		; <uint>	[#uses=2]
	%reg114 = add uint %reg113, 8		; <uint>	[#uses=1]
	%cast115 = cast uint %reg114 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg119 = add %hgsptr %hg, %cast115		; <%hgsptr>	[#uses=1]
	%reg122 = add uint %reg113, 16		; <uint>	[#uses=1]
	%cast123 = cast uint %reg122 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg125 = add %bodyptr %p, %cast123		; <%bodyptr>	[#uses=1]
	%cast3070 = cast %bodyptr %reg125 to double *		; <double *>	[#uses=1]
	%reg126 = load double * %cast3070		; <double>	[#uses=1]
	%cast3071 = cast %hgsptr %reg119 to double *		; <double *>	[#uses=1]
	store double %reg126, double * %cast3071
	%reg168 = add int %reg167, 1		; <int>	[#uses=2]
	%cond3044 = setle int %reg168, 2		; <bool>	[#uses=1]
	br bool %cond3044, label %bb2, label %bb3

bb3:					;[#uses=3]
	store double 0.000000, %hgsptr %hg, ubyte 2
	%cond3047 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond3047, label %bb5, label %bb4

bb4:					;[#uses=3]
	%reg169 = phi int [ %reg170, %bb4 ], [ 0, %bb3 ]		; <int>	[#uses=2]
	%cast3074 = cast int %reg169 to uint		; <uint>	[#uses=1]
	%reg130 = shl uint %cast3074, ubyte 3		; <uint>	[#uses=1]
	%reg131 = add uint %reg130, 40		; <uint>	[#uses=1]
	%cast132 = cast uint %reg131 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg136 = add %hgsptr %hg, %cast132		; <%hgsptr>	[#uses=1]
	%cast3075 = cast %hgsptr %reg136 to double *		; <double *>	[#uses=1]
	store double 0.000000, double * %cast3075
	%reg170 = add int %reg169, 1		; <int>	[#uses=2]
	%cond3048 = setle int %reg170, 2		; <bool>	[#uses=1]
	br bool %cond3048, label %bb4, label %bb5

bb5:					;[#uses=3]
	%reg110 = mul double %rsize, %rsize		; <double>	[#uses=1]
	%reg139 = load %hgsptr %hg, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast139 = cast %bodyptr %reg139 to ulong		; <ulong>	[#uses=1]
	%cast3078 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast3079 = cast long -144 to ulong *		; <ulong *>	[#uses=1]
	%reg3049 = add ulong * %cast3078, %cast3079		; <ulong *>	[#uses=1]
	store ulong %cast139, ulong * %reg3049
	%eptr3121 = getelementptr %hgsptr %hg, ubyte 1		; <%vector *>	[#uses=1]
	%cast3081 = cast %vector * %eptr3121 to ulong *		; <ulong *>	[#uses=1]
	%reg140 = load ulong * %cast3081		; <ulong>	[#uses=1]
	%cast3082 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast3083 = cast long -136 to ulong *		; <ulong *>	[#uses=1]
	%reg3051 = add ulong * %cast3082, %cast3083		; <ulong *>	[#uses=1]
	store ulong %reg140, ulong * %reg3051
	%cast3084 = cast ulong 16 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg3052 = add %hgsptr %hg, %cast3084		; <%hgsptr>	[#uses=1]
	%reg141 = load %hgsptr %reg3052, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast141 = cast %bodyptr %reg141 to ulong		; <ulong>	[#uses=1]
	%cast3086 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast3087 = cast long -128 to ulong *		; <ulong *>	[#uses=1]
	%reg3053 = add ulong * %cast3086, %cast3087		; <ulong *>	[#uses=1]
	store ulong %cast141, ulong * %reg3053
	%cast3088 = cast ulong 24 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg3054 = add %hgsptr %hg, %cast3088		; <%hgsptr>	[#uses=1]
	%reg142 = load %hgsptr %reg3054, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast142 = cast %bodyptr %reg142 to ulong		; <ulong>	[#uses=1]
	%cast3090 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast3091 = cast long -120 to ulong *		; <ulong *>	[#uses=1]
	%reg3055 = add ulong * %cast3090, %cast3091		; <ulong *>	[#uses=1]
	store ulong %cast142, ulong * %reg3055
	%reg143 = load %hgsptr %hg, ubyte 2		; <double>	[#uses=1]
	%cast143 = cast double %reg143 to ulong		; <ulong>	[#uses=1]
	%cast3094 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast3095 = cast long -112 to ulong *		; <ulong *>	[#uses=1]
	%reg3057 = add ulong * %cast3094, %cast3095		; <ulong *>	[#uses=1]
	store ulong %cast143, ulong * %reg3057
	%eptr3127 = getelementptr %hgsptr %hg, ubyte 3		; <%vector *>	[#uses=1]
	%cast3097 = cast %vector * %eptr3127 to ulong *		; <ulong *>	[#uses=1]
	%reg144 = load ulong * %cast3097		; <ulong>	[#uses=1]
	%cast3098 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast3099 = cast long -104 to ulong *		; <ulong *>	[#uses=1]
	%reg3059 = add ulong * %cast3098, %cast3099		; <ulong *>	[#uses=1]
	store ulong %reg144, ulong * %reg3059
	%cast3100 = cast ulong 48 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg3060 = add %hgsptr %hg, %cast3100		; <%hgsptr>	[#uses=1]
	%reg145 = load %hgsptr %reg3060, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast145 = cast %bodyptr %reg145 to ulong		; <ulong>	[#uses=1]
	%cast3102 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast3103 = cast long -96 to ulong *		; <ulong *>	[#uses=1]
	%reg3061 = add ulong * %cast3102, %cast3103		; <ulong *>	[#uses=1]
	store ulong %cast145, ulong * %reg3061
	%cast3104 = cast ulong 56 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg3062 = add %hgsptr %hg, %cast3104		; <%hgsptr>	[#uses=1]
	%reg146 = load %hgsptr %reg3062, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast146 = cast %bodyptr %reg146 to ulong		; <ulong>	[#uses=1]
	%cast3106 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast3107 = cast long -88 to ulong *		; <ulong *>	[#uses=1]
	%reg3063 = add ulong * %cast3106, %cast3107		; <ulong *>	[#uses=1]
	store ulong %cast146, ulong * %reg3063
	%cast3108 = cast ulong 42 to %hgsptr		; <%hgsptr>	[#uses=1]
	%cast3109 = cast long -144 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg148 = add %hgsptr %cast3108, %cast3109		; <%hgsptr>	[#uses=1]
	%cast3064 = cast ulong 0 to int		; <int>	[#uses=1]
	call %hgsptr (%hgsptr, %nodeptr, double, double, %hgsptr, int) * %walksub( %hgsptr %hg, %nodeptr %rt, double %reg110, double 1.000000, %hgsptr %reg148, int %cast3064 )		; <%hgsptr>:0	[#uses=0]
	%reg150 = load %hgsptr %hg, ubyte 2		; <double>	[#uses=1]
	store double %reg150, %bodyptr %p, ubyte 8
	%cond3067 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond3067, label %bb7, label %bb6

bb6:					;[#uses=3]
	%reg171 = phi int [ %reg172, %bb6 ], [ 0, %bb5 ]		; <int>	[#uses=2]
	%cast3114 = cast int %reg171 to uint		; <uint>	[#uses=1]
	%reg153 = shl uint %cast3114, ubyte 3		; <uint>	[#uses=2]
	%reg154 = add uint %reg153, 96		; <uint>	[#uses=1]
	%cast155 = cast uint %reg154 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg157 = add %bodyptr %p, %cast155		; <%bodyptr>	[#uses=1]
	%reg160 = add uint %reg153, 40		; <uint>	[#uses=1]
	%cast161 = cast uint %reg160 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg165 = add %hgsptr %hg, %cast161		; <%hgsptr>	[#uses=1]
	%reg166 = load %hgsptr %reg165, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast166 = cast %bodyptr %reg166 to double		; <double>	[#uses=1]
	%cast3116 = cast %bodyptr %reg157 to double *		; <double *>	[#uses=1]
	store double %cast166, double * %cast3116
	%reg172 = add int %reg171, 1		; <int>	[#uses=2]
	%cond3068 = setle int %reg172, 2		; <bool>	[#uses=1]
	br bool %cond3068, label %bb6, label %bb7

bb7:					;[#uses=2]
	ret void
end

declare double "ceil"(...)

declare %bodyptr "body_alloc"(int, double, double, double, double, double, double, double, double, double, double, %bodyptr)

%nodeptr "loadtree"(%bodyptr %p, %icstruct * %xpic, %nodeptr %t, int %l, %treeptr %tr)
begin
bb0:					;[#uses=0]
	%pic = alloca %icstruct		; <%icstruct *>	[#uses=5]
	%tic = alloca %icstruct		; <%icstruct *>	[#uses=5]
	br label %bb1

bb1:					;[#uses=1]
	%cond3720 = setne %nodeptr %t, null		; <bool>	[#uses=1]
	br bool %cond3720, label %bb3, label %bb2

bb2:					;[#uses=1]
	%cast3747 = cast %bodyptr %p to %nodeptr		; <%nodeptr>	[#uses=1]
	ret %nodeptr %cast3747

bb3:					;[#uses=1]
	%cond3721 = setne int %l, 0		; <bool>	[#uses=1]
	br bool %cond3721, label %bb5, label %bb4

bb4:					;[#uses=1]
	%cast3722 = cast ulong 2 to uint		; <uint>	[#uses=1]
	%cast3748 = cast [22 x sbyte] * %__intern_LC5 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast3748, uint %cast3722 )		; <int>:0	[#uses=0]
	%cast3723 = cast ulong 0 to uint		; <uint>	[#uses=1]
	call %proc %exit( uint %cast3723 )
	br label %bb5

bb5:					;[#uses=3]
	%reg119 = load %nodeptr %t, ubyte 0		; <short>	[#uses=1]
	%cast119 = cast short %reg119 to ushort		; <ushort>	[#uses=1]
	%cond3724 = setne ushort %cast119, 1		; <bool>	[#uses=1]
	br bool %cond3724, label %bb7, label %bb6

bb6:					;[#uses=2]
	%cast3725 = cast ulong 0 to int		; <int>	[#uses=1]
	%reg113 = call %cellptr (int) * %cell_alloc( int %cast3725 )		; <%cellptr>	[#uses=2]
	%cast3750 = cast %nodeptr %t to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg112 = call int (%bodyptr, %treeptr, int) * %subindex( %bodyptr %cast3750, %treeptr %tr, int %l )		; <int>	[#uses=1]
	%reg123 = shl int %reg112, ubyte 3		; <int>	[#uses=1]
	%cast3751 = cast int %reg123 to uint		; <uint>	[#uses=1]
	%reg124 = add uint %cast3751, 48		; <uint>	[#uses=1]
	%cast125 = cast uint %reg124 to %cellptr		; <%cellptr>	[#uses=1]
	%reg127 = add %cellptr %reg113, %cast125		; <%cellptr>	[#uses=1]
	%cast3752 = cast %cellptr %reg127 to %nodeptr *		; <%nodeptr *>	[#uses=1]
	store %nodeptr %t, %nodeptr * %cast3752
	br label %bb7

bb7:					;[#uses=2]
	%reg154 = phi %cellptr [ %reg113, %bb6 ], [ %cast3753, %bb5 ]		; <%cellptr>	[#uses=2]
	%cast3776 = cast %cellptr %reg154 to %nodeptr		; <%nodeptr>	[#uses=1]
	%cast3765 = cast %cellptr %reg154 to %nodeptr *		; <%nodeptr *>	[#uses=1]
	%cast3753 = cast %nodeptr %t to %cellptr		; <%cellptr>	[#uses=1]
	%cast3754 = cast %icstruct * %xpic to uint *		; <uint *>	[#uses=1]
	%reg128 = load uint * %cast3754		; <uint>	[#uses=1]
	%cast3726 = cast %icstruct * %tic to uint *		; <uint *>	[#uses=1]
	store uint %reg128, uint * %cast3726
	%cast3755 = cast ulong 4 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg3727 = add %icstruct * %xpic, %cast3755		; <%icstruct *>	[#uses=1]
	%cast3756 = cast %icstruct * %reg3727 to uint *		; <uint *>	[#uses=1]
	%reg129 = load uint * %cast3756		; <uint>	[#uses=1]
	%cast3757 = cast ulong 4 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg3728 = add %icstruct * %tic, %cast3757		; <%icstruct *>	[#uses=1]
	%cast3729 = cast %icstruct * %reg3728 to uint *		; <uint *>	[#uses=1]
	store uint %reg129, uint * %cast3729
	%cast3758 = cast ulong 8 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg3730 = add %icstruct * %xpic, %cast3758		; <%icstruct *>	[#uses=1]
	%cast3759 = cast %icstruct * %reg3730 to uint *		; <uint *>	[#uses=1]
	%reg130 = load uint * %cast3759		; <uint>	[#uses=1]
	%cast3760 = cast ulong 8 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg3731 = add %icstruct * %tic, %cast3760		; <%icstruct *>	[#uses=1]
	%cast3732 = cast %icstruct * %reg3731 to uint *		; <uint *>	[#uses=1]
	store uint %reg130, uint * %cast3732
	%eptr3780 = getelementptr %icstruct * %xpic, ubyte 1		; <short *>	[#uses=1]
	%cast3762 = cast short * %eptr3780 to uint *		; <uint *>	[#uses=1]
	%reg131 = load uint * %cast3762		; <uint>	[#uses=1]
	%eptr3781 = getelementptr %icstruct * %tic, ubyte 1		; <short *>	[#uses=1]
	%cast3735 = cast short * %eptr3781 to uint *		; <uint *>	[#uses=1]
	store uint %reg131, uint * %cast3735
	%reg155 = call int (%icstruct *, int) * %old_subindex( %icstruct * %tic, int %l )		; <int>	[#uses=1]
	%reg134 = shl int %reg155, ubyte 3		; <int>	[#uses=1]
	%cast3764 = cast int %reg134 to uint		; <uint>	[#uses=1]
	%reg135 = add uint %cast3764, 48		; <uint>	[#uses=1]
	%cast136 = cast uint %reg135 to %nodeptr *		; <%nodeptr *>	[#uses=1]
	%reg138 = add %nodeptr * %cast3765, %cast136		; <%nodeptr *>	[#uses=2]
	%reg114 = load %nodeptr * %reg138		; <%nodeptr>	[#uses=1]
	%cast3766 = cast %icstruct * %xpic to uint *		; <uint *>	[#uses=1]
	%reg145 = load uint * %cast3766		; <uint>	[#uses=1]
	%cast3736 = cast %icstruct * %pic to uint *		; <uint *>	[#uses=1]
	store uint %reg145, uint * %cast3736
	%cast3767 = cast ulong 4 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg3737 = add %icstruct * %xpic, %cast3767		; <%icstruct *>	[#uses=1]
	%cast3768 = cast %icstruct * %reg3737 to uint *		; <uint *>	[#uses=1]
	%reg146 = load uint * %cast3768		; <uint>	[#uses=1]
	%cast3769 = cast ulong 4 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg3738 = add %icstruct * %pic, %cast3769		; <%icstruct *>	[#uses=1]
	%cast3739 = cast %icstruct * %reg3738 to uint *		; <uint *>	[#uses=1]
	store uint %reg146, uint * %cast3739
	%cast3770 = cast ulong 8 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg3740 = add %icstruct * %xpic, %cast3770		; <%icstruct *>	[#uses=1]
	%cast3771 = cast %icstruct * %reg3740 to uint *		; <uint *>	[#uses=1]
	%reg147 = load uint * %cast3771		; <uint>	[#uses=1]
	%cast3772 = cast ulong 8 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg3741 = add %icstruct * %pic, %cast3772		; <%icstruct *>	[#uses=1]
	%cast3742 = cast %icstruct * %reg3741 to uint *		; <uint *>	[#uses=1]
	store uint %reg147, uint * %cast3742
	%eptr3782 = getelementptr %icstruct * %xpic, ubyte 1		; <short *>	[#uses=1]
	%cast3774 = cast short * %eptr3782 to uint *		; <uint *>	[#uses=1]
	%reg148 = load uint * %cast3774		; <uint>	[#uses=1]
	%eptr3783 = getelementptr %icstruct * %pic, ubyte 1		; <short *>	[#uses=1]
	%cast3745 = cast short * %eptr3783 to uint *		; <uint *>	[#uses=1]
	store uint %reg148, uint * %cast3745
	%reg150 = shr int %l, ubyte 1		; <int>	[#uses=1]
	%reg151 = call %nodeptr (%bodyptr, %icstruct *, %nodeptr, int, %treeptr) * %loadtree( %bodyptr %p, %icstruct * %pic, %nodeptr %reg114, int %reg150, %treeptr %tr )		; <%nodeptr>	[#uses=1]
	store %nodeptr %reg151, %nodeptr * %reg138
	ret %nodeptr %cast3776

bb8:					;[#uses=0]
	%cast3777 = cast ulong 42 to %nodeptr		; <%nodeptr>	[#uses=1]
	ret %nodeptr %cast3777
end

void "expandbox"(%bodyptr %p, %treeptr %t, int %nsteps, int %proc)
begin
bb0:					;[#uses=0]
	%ic = alloca %icstruct		; <%icstruct *>	[#uses=6]
	%rmid = alloca %vector		; <%vector *>	[#uses=3]
	%cast3629 = cast %vector * %rmid to double *		; <double *>	[#uses=3]
	%tmp = alloca %tree		; <%treeptr>	[#uses=0]
	br label %bb1

bb1:					;[#uses=2]
	%reg114 = call int (%bodyptr, %treeptr) * %ic_test( %bodyptr %p, %treeptr %t )		; <int>	[#uses=2]
	%cond3630 = setne int %reg114, 0		; <bool>	[#uses=1]
	br bool %cond3630, label %bb15, label %bb2

bb2:					;[#uses=2]
	%reg189 = phi int [ %reg196, %bb14 ], [ %reg114, %bb1 ]		; <int>	[#uses=1]
	%reg113 = load %treeptr %t, ubyte 1		; <double>	[#uses=5]
	%cast3662 = cast double %reg113 to long		; <long>	[#uses=1]
	%cast3663 = cast double 1000.000000 to long		; <long>	[#uses=1]
	%cond3632 = setlt long %cast3662, %cast3663		; <bool>	[#uses=1]
	br bool %cond3632, label %bb4, label %bb3

bb3:					;[#uses=1]
	%cast3633 = cast ulong 999 to uint		; <uint>	[#uses=1]
	%cast3664 = cast [22 x sbyte] * %__intern_LC5 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast3664, uint %cast3633 )		; <int>:0	[#uses=0]
	%cast3634 = cast ulong 0 to uint		; <uint>	[#uses=1]
	call %proc %exit( uint %cast3634 )
	br label %bb4

bb4:					;[#uses=3]
	%cond3635 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond3635, label %bb6, label %bb5

bb5:					;[#uses=3]
	%reg190 = phi int [ %reg191, %bb5 ], [ 0, %bb4 ]		; <int>	[#uses=2]
	%cast3665 = cast int %reg190 to uint		; <uint>	[#uses=1]
	%reg121 = shl uint %cast3665, ubyte 3		; <uint>	[#uses=1]
	%cast122 = cast uint %reg121 to %treeptr		; <%treeptr>	[#uses=2]
	%cast3666 = cast %vector * %rmid to %treeptr		; <%treeptr>	[#uses=1]
	%reg126 = add %treeptr %cast3666, %cast122		; <%treeptr>	[#uses=1]
	%reg131 = add %treeptr %t, %cast122		; <%treeptr>	[#uses=1]
	%reg133 = mul double %reg113, 0.500000		; <double>	[#uses=1]
	%cast3667 = cast %treeptr %reg131 to double *		; <double *>	[#uses=1]
	%reg134 = load double * %cast3667		; <double>	[#uses=1]
	%reg135 = add double %reg134, %reg133		; <double>	[#uses=1]
	%cast3668 = cast %treeptr %reg126 to double *		; <double *>	[#uses=1]
	store double %reg135, double * %cast3668
	%reg191 = add int %reg190, 1		; <int>	[#uses=2]
	%cond3636 = setle int %reg191, 2		; <bool>	[#uses=1]
	br bool %cond3636, label %bb5, label %bb6

bb6:					;[#uses=3]
	%cond3637 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond3637, label %bb10, label %bb7

bb7:					;[#uses=2]
	%reg192 = phi int [ %reg193, %bb9 ], [ 0, %bb6 ]		; <int>	[#uses=2]
	%cast3670 = cast int %reg192 to uint		; <uint>	[#uses=1]
	%reg137 = shl uint %cast3670, ubyte 3		; <uint>	[#uses=2]
	%reg138 = add uint %reg137, 16		; <uint>	[#uses=1]
	%cast139 = cast uint %reg138 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg141 = add %bodyptr %p, %cast139		; <%bodyptr>	[#uses=1]
	%cast144 = cast uint %reg137 to %treeptr		; <%treeptr>	[#uses=2]
	%cast3671 = cast %vector * %rmid to %treeptr		; <%treeptr>	[#uses=1]
	%reg148 = add %treeptr %cast3671, %cast144		; <%treeptr>	[#uses=1]
	%cast3672 = cast %bodyptr %reg141 to double *		; <double *>	[#uses=1]
	%reg149 = load double * %cast3672		; <double>	[#uses=1]
	%cast3673 = cast %treeptr %reg148 to double *		; <double *>	[#uses=1]
	%reg150 = load double * %cast3673		; <double>	[#uses=1]
	%cast3674 = cast double %reg149 to long		; <long>	[#uses=1]
	%cast3675 = cast double %reg150 to long		; <long>	[#uses=1]
	%cond3638 = setlt long %cast3674, %cast3675		; <bool>	[#uses=1]
	br bool %cond3638, label %bb8, label %bb9

bb8:					;[#uses=1]
	%reg156 = add %treeptr %t, %cast144		; <%treeptr>	[#uses=2]
	%cast3676 = cast %treeptr %reg156 to double *		; <double *>	[#uses=1]
	%reg151 = load double * %cast3676		; <double>	[#uses=1]
	%reg162 = sub double %reg151, %reg113		; <double>	[#uses=1]
	%cast3677 = cast %treeptr %reg156 to double *		; <double *>	[#uses=1]
	store double %reg162, double * %cast3677
	br label %bb9

bb9:					;[#uses=3]
	%reg193 = add int %reg192, 1		; <int>	[#uses=2]
	%cond3639 = setle int %reg193, 2		; <bool>	[#uses=1]
	br bool %cond3639, label %bb7, label %bb10

bb10:					;[#uses=3]
	%reg164 = add double %reg113, %reg113		; <double>	[#uses=1]
	store double %reg164, %treeptr %t, ubyte 1
	%reg165 = load %treeptr %t, ubyte 2		; <%nodeptr>	[#uses=1]
	%cast165 = cast %nodeptr %reg165 to ulong *		; <ulong *>	[#uses=1]
	%cond3642 = seteq ulong * %cast165, null		; <bool>	[#uses=1]
	br bool %cond3642, label %bb14, label %bb11

bb11:					;[#uses=1]
	%cast3643 = cast ulong 0 to int		; <int>	[#uses=1]
	%reg112 = call %cellptr (int) * %cell_alloc( int %cast3643 )		; <%cellptr>	[#uses=2]
	%reg169 = load double * %cast3629		; <double>	[#uses=1]
	%cast3684 = cast ulong 8 to double *		; <double *>	[#uses=1]
	%reg3644 = add double * %cast3629, %cast3684		; <double *>	[#uses=1]
	%reg170 = load double * %reg3644		; <double>	[#uses=1]
	%cast3685 = cast ulong 16 to double *		; <double *>	[#uses=1]
	%reg3645 = add double * %cast3629, %cast3685		; <double *>	[#uses=1]
	%reg171 = load double * %reg3645		; <double>	[#uses=1]
	call %icstruct * (%icstruct *, double, double, double, %treeptr) * %intcoord1( %icstruct * %ic, double %reg169, double %reg170, double %reg171, %treeptr %t )		; <%icstruct *>:0	[#uses=0]
	%reg172 = load %icstruct * %ic, ubyte 1		; <short>	[#uses=1]
	%cast172 = cast short %reg172 to ushort		; <ushort>	[#uses=1]
	%cond3647 = setne ushort %cast172, 0		; <bool>	[#uses=1]
	br bool %cond3647, label %bb13, label %bb12

bb12:					;[#uses=1]
	%cast3648 = cast ulong 1 to uint		; <uint>	[#uses=1]
	%cast3688 = cast [22 x sbyte] * %__intern_LC5 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast3688, uint %cast3648 )		; <int>:1	[#uses=0]
	%cast3649 = cast ulong 0 to uint		; <uint>	[#uses=1]
	call %proc %exit( uint %cast3649 )
	br label %bb13

bb13:					;[#uses=3]
	%cast3689 = cast %icstruct * %ic to uint *		; <uint *>	[#uses=1]
	%reg176 = load uint * %cast3689		; <uint>	[#uses=1]
	%cast3690 = cast ulong 42 to uint *		; <uint *>	[#uses=1]
	%cast3691 = cast long -1136 to uint *		; <uint *>	[#uses=1]
	%reg3650 = add uint * %cast3690, %cast3691		; <uint *>	[#uses=1]
	store uint %reg176, uint * %reg3650
	%cast3692 = cast ulong 4 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg3651 = add %icstruct * %ic, %cast3692		; <%icstruct *>	[#uses=1]
	%cast3693 = cast %icstruct * %reg3651 to uint *		; <uint *>	[#uses=1]
	%reg177 = load uint * %cast3693		; <uint>	[#uses=1]
	%cast3694 = cast ulong 42 to uint *		; <uint *>	[#uses=1]
	%cast3695 = cast long -1132 to uint *		; <uint *>	[#uses=1]
	%reg3652 = add uint * %cast3694, %cast3695		; <uint *>	[#uses=1]
	store uint %reg177, uint * %reg3652
	%cast3696 = cast ulong 8 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg3653 = add %icstruct * %ic, %cast3696		; <%icstruct *>	[#uses=1]
	%cast3697 = cast %icstruct * %reg3653 to uint *		; <uint *>	[#uses=1]
	%reg178 = load uint * %cast3697		; <uint>	[#uses=1]
	%cast3698 = cast ulong 42 to uint *		; <uint *>	[#uses=1]
	%cast3699 = cast long -1128 to uint *		; <uint *>	[#uses=1]
	%reg3654 = add uint * %cast3698, %cast3699		; <uint *>	[#uses=1]
	store uint %reg178, uint * %reg3654
	%eptr3717 = getelementptr %icstruct * %ic, ubyte 1		; <short *>	[#uses=1]
	%cast3701 = cast short * %eptr3717 to uint *		; <uint *>	[#uses=1]
	%reg179 = load uint * %cast3701		; <uint>	[#uses=1]
	%cast3702 = cast ulong 42 to uint *		; <uint *>	[#uses=1]
	%cast3703 = cast long -1124 to uint *		; <uint *>	[#uses=1]
	%reg3656 = add uint * %cast3702, %cast3703		; <uint *>	[#uses=1]
	store uint %reg179, uint * %reg3656
	%cast3704 = cast ulong 42 to %icstruct *		; <%icstruct *>	[#uses=1]
	%cast3705 = cast long -1136 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg180 = add %icstruct * %cast3704, %cast3705		; <%icstruct *>	[#uses=1]
	%reg194 = call int (%icstruct *, int) * %old_subindex( %icstruct * %reg180, int 536870912 )		; <int>	[#uses=1]
	%reg183 = shl int %reg194, ubyte 3		; <int>	[#uses=1]
	%cast3706 = cast int %reg183 to uint		; <uint>	[#uses=1]
	%reg184 = add uint %cast3706, 48		; <uint>	[#uses=1]
	%cast185 = cast uint %reg184 to %cellptr		; <%cellptr>	[#uses=1]
	%reg187 = add %cellptr %reg112, %cast185		; <%cellptr>	[#uses=1]
	%cast3709 = cast %cellptr %reg187 to ulong * *		; <ulong * *>	[#uses=1]
	%reg188 = load %treeptr %t, ubyte 2		; <%nodeptr>	[#uses=1]
	%cast188 = cast %nodeptr %reg188 to ulong *		; <ulong *>	[#uses=1]
	store ulong * %cast188, ulong * * %cast3709
	%eptr3719 = getelementptr %treeptr %t, ubyte 2		; <%nodeptr *>	[#uses=1]
	%cast3711 = cast %nodeptr * %eptr3719 to %cellptr *		; <%cellptr *>	[#uses=1]
	store %cellptr %reg112, %cellptr * %cast3711
	%reg195 = call int (%bodyptr, %treeptr) * %ic_test( %bodyptr %p, %treeptr %t )		; <int>	[#uses=1]
	br label %bb14

bb14:					;[#uses=3]
	%reg196 = phi int [ %reg195, %bb13 ], [ %reg189, %bb10 ]		; <int>	[#uses=2]
	%cond3659 = seteq int %reg196, 0		; <bool>	[#uses=1]
	br bool %cond3659, label %bb2, label %bb15

bb15:					;[#uses=2]
	ret void
end

%icstruct * "intcoord1"(%icstruct * %StructReturn, double %rp0, double %rp1, double %rp2, %treeptr %t)
begin
bb0:					;[#uses=0]
	%ic = alloca %icstruct		; <%icstruct *>	[#uses=11]
	br label %bb1

bb1:					;[#uses=1]
	store short 1, %icstruct * %ic, ubyte 1
	%cast3815 = cast %treeptr %t to double *		; <double *>	[#uses=1]
	%reg114 = load double * %cast3815		; <double>	[#uses=1]
	%reg115 = sub double %rp0, %reg114		; <double>	[#uses=1]
	%reg116 = load %treeptr %t, ubyte 1		; <double>	[#uses=1]
	%reg112 = div double %reg115, %reg116		; <double>	[#uses=3]
	%cast3822 = cast double %reg112 to long		; <long>	[#uses=1]
	%cast3823 = cast double 0.000000 to long		; <long>	[#uses=1]
	%cond3787 = setge long %cast3822, %cast3823		; <bool>	[#uses=1]
	br bool %cond3787, label %bb2, label %bb4

bb2:					;[#uses=1]
	%cast3824 = cast double %reg112 to long		; <long>	[#uses=1]
	%cast3825 = cast double 1.000000 to long		; <long>	[#uses=1]
	%cond3788 = setlt long %cast3824, %cast3825		; <bool>	[#uses=1]
	br bool %cond3788, label %bb3, label %bb4

bb3:					;[#uses=1]
	%reg120 = mul double %reg112, 1073741824.000000		; <double>	[#uses=1]
	%reg121 = call %rproc %floor( double %reg120 )		; <double>	[#uses=1]
	%cast122 = cast double %reg121 to int		; <int>	[#uses=1]
	%cast3789 = cast %icstruct * %ic to int *		; <int *>	[#uses=1]
	store int %cast122, int * %cast3789
	br label %bb5

bb4:					;[#uses=2]
	store short 0, %icstruct * %ic, ubyte 1
	br label %bb5

bb5:					;[#uses=2]
	%cast3827 = cast ulong 8 to %treeptr		; <%treeptr>	[#uses=1]
	%reg3792 = add %treeptr %t, %cast3827		; <%treeptr>	[#uses=1]
	%cast3828 = cast %treeptr %reg3792 to double *		; <double *>	[#uses=1]
	%reg124 = load double * %cast3828		; <double>	[#uses=1]
	%reg125 = sub double %rp1, %reg124		; <double>	[#uses=1]
	%reg126 = load %treeptr %t, ubyte 1		; <double>	[#uses=1]
	%reg148 = div double %reg125, %reg126		; <double>	[#uses=3]
	%cast3835 = cast double %reg148 to long		; <long>	[#uses=1]
	%cast3836 = cast double 0.000000 to long		; <long>	[#uses=1]
	%cond3794 = setge long %cast3835, %cast3836		; <bool>	[#uses=1]
	br bool %cond3794, label %bb6, label %bb8

bb6:					;[#uses=1]
	%cast3837 = cast double %reg148 to long		; <long>	[#uses=1]
	%cast3838 = cast double 1.000000 to long		; <long>	[#uses=1]
	%cond3795 = setlt long %cast3837, %cast3838		; <bool>	[#uses=1]
	br bool %cond3795, label %bb7, label %bb8

bb7:					;[#uses=1]
	%reg130 = mul double %reg148, 1073741824.000000		; <double>	[#uses=1]
	%reg131 = call %rproc %floor( double %reg130 )		; <double>	[#uses=1]
	%cast132 = cast double %reg131 to int		; <int>	[#uses=1]
	%cast3839 = cast ulong 4 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg3796 = add %icstruct * %ic, %cast3839		; <%icstruct *>	[#uses=1]
	%cast3797 = cast %icstruct * %reg3796 to int *		; <int *>	[#uses=1]
	store int %cast132, int * %cast3797
	br label %bb9

bb8:					;[#uses=2]
	store short 0, %icstruct * %ic, ubyte 1
	br label %bb9

bb9:					;[#uses=2]
	%cast3841 = cast ulong 16 to %treeptr		; <%treeptr>	[#uses=1]
	%reg3800 = add %treeptr %t, %cast3841		; <%treeptr>	[#uses=1]
	%cast3842 = cast %treeptr %reg3800 to double *		; <double *>	[#uses=1]
	%reg134 = load double * %cast3842		; <double>	[#uses=1]
	%reg135 = sub double %rp2, %reg134		; <double>	[#uses=1]
	%reg136 = load %treeptr %t, ubyte 1		; <double>	[#uses=1]
	%reg149 = div double %reg135, %reg136		; <double>	[#uses=3]
	%cast3849 = cast double %reg149 to long		; <long>	[#uses=1]
	%cast3850 = cast double 0.000000 to long		; <long>	[#uses=1]
	%cond3802 = setge long %cast3849, %cast3850		; <bool>	[#uses=1]
	br bool %cond3802, label %bb10, label %bb12

bb10:					;[#uses=1]
	%cast3851 = cast double %reg149 to long		; <long>	[#uses=1]
	%cast3852 = cast double 1.000000 to long		; <long>	[#uses=1]
	%cond3803 = setlt long %cast3851, %cast3852		; <bool>	[#uses=1]
	br bool %cond3803, label %bb11, label %bb12

bb11:					;[#uses=1]
	%reg140 = mul double %reg149, 1073741824.000000		; <double>	[#uses=1]
	%reg141 = call %rproc %floor( double %reg140 )		; <double>	[#uses=1]
	%cast142 = cast double %reg141 to int		; <int>	[#uses=1]
	%cast3853 = cast ulong 8 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg3804 = add %icstruct * %ic, %cast3853		; <%icstruct *>	[#uses=1]
	%cast3805 = cast %icstruct * %reg3804 to int *		; <int *>	[#uses=1]
	store int %cast142, int * %cast3805
	br label %bb13

bb12:					;[#uses=2]
	store short 0, %icstruct * %ic, ubyte 1
	br label %bb13

bb13:					;[#uses=2]
	%cast3855 = cast %icstruct * %ic to uint *		; <uint *>	[#uses=1]
	%reg144 = load uint * %cast3855		; <uint>	[#uses=1]
	%cast3856 = cast %icstruct * %StructReturn to uint *		; <uint *>	[#uses=1]
	store uint %reg144, uint * %cast3856
	%cast3857 = cast ulong 4 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg3808 = add %icstruct * %ic, %cast3857		; <%icstruct *>	[#uses=1]
	%cast3858 = cast %icstruct * %reg3808 to uint *		; <uint *>	[#uses=1]
	%reg145 = load uint * %cast3858		; <uint>	[#uses=1]
	%cast3859 = cast ulong 4 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg3809 = add %icstruct * %StructReturn, %cast3859		; <%icstruct *>	[#uses=1]
	%cast3860 = cast %icstruct * %reg3809 to uint *		; <uint *>	[#uses=1]
	store uint %reg145, uint * %cast3860
	%cast3861 = cast ulong 8 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg3810 = add %icstruct * %ic, %cast3861		; <%icstruct *>	[#uses=1]
	%cast3862 = cast %icstruct * %reg3810 to uint *		; <uint *>	[#uses=1]
	%reg146 = load uint * %cast3862		; <uint>	[#uses=1]
	%cast3863 = cast ulong 8 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg3811 = add %icstruct * %StructReturn, %cast3863		; <%icstruct *>	[#uses=1]
	%cast3864 = cast %icstruct * %reg3811 to uint *		; <uint *>	[#uses=1]
	store uint %reg146, uint * %cast3864
	%eptr4201 = getelementptr %icstruct * %ic, ubyte 1		; <short *>	[#uses=1]
	%cast3866 = cast short * %eptr4201 to uint *		; <uint *>	[#uses=1]
	%reg147 = load uint * %cast3866		; <uint>	[#uses=1]
	%eptr4202 = getelementptr %icstruct * %StructReturn, ubyte 1		; <short *>	[#uses=1]
	%cast3868 = cast short * %eptr4202 to uint *		; <uint *>	[#uses=1]
	store uint %reg147, uint * %cast3868
	ret %icstruct * %StructReturn

bb14:					;[#uses=0]
	%cast3869 = cast ulong 42 to %icstruct *		; <%icstruct *>	[#uses=1]
	ret %icstruct * %cast3869
end

int "ic_test"(%bodyptr %p, %treeptr %t)
begin
bb0:					;[#uses=0]
	%pos = alloca %vector		; <%vector *>	[#uses=1]
	%cast4693 = cast %vector * %pos to double *		; <double *>	[#uses=5]
	br label %bb1

bb1:					;[#uses=1]
	%eptr4896 = getelementptr %bodyptr %p, ubyte 2		; <%vector *>	[#uses=1]
	%cast4711 = cast %vector * %eptr4896 to double *		; <double *>	[#uses=1]
	%reg112 = load double * %cast4711		; <double>	[#uses=2]
	store double %reg112, double * %cast4693
	%cast4712 = cast ulong 24 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg4695 = add %bodyptr %p, %cast4712		; <%bodyptr>	[#uses=1]
	%cast4713 = cast %bodyptr %reg4695 to double *		; <double *>	[#uses=1]
	%reg113 = load double * %cast4713		; <double>	[#uses=1]
	%cast4714 = cast ulong 8 to double *		; <double *>	[#uses=1]
	%reg4696 = add double * %cast4693, %cast4714		; <double *>	[#uses=1]
	store double %reg113, double * %reg4696
	%cast4715 = cast ulong 32 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg4697 = add %bodyptr %p, %cast4715		; <%bodyptr>	[#uses=1]
	%cast4716 = cast %bodyptr %reg4697 to double *		; <double *>	[#uses=1]
	%reg114 = load double * %cast4716		; <double>	[#uses=1]
	%cast4717 = cast ulong 16 to double *		; <double *>	[#uses=1]
	%reg4698 = add double * %cast4693, %cast4717		; <double *>	[#uses=1]
	store double %reg114, double * %reg4698
	%reg110 = load %treeptr %t, ubyte 1		; <double>	[#uses=3]
	%cast4720 = cast %treeptr %t to double *		; <double *>	[#uses=1]
	%reg116 = load double * %cast4720		; <double>	[#uses=1]
	%reg117 = sub double %reg112, %reg116		; <double>	[#uses=1]
	%reg109 = div double %reg117, %reg110		; <double>	[#uses=2]
	%cast4725 = cast double %reg109 to long		; <long>	[#uses=1]
	%cast4726 = cast double 0.000000 to long		; <long>	[#uses=1]
	%cond4700 = setge long %cast4725, %cast4726		; <bool>	[#uses=1]
	br bool %cond4700, label %bb2, label %bb3

bb2:					;[#uses=2]
	%cast4727 = cast double %reg109 to long		; <long>	[#uses=1]
	%cast4728 = cast double 1.000000 to long		; <long>	[#uses=1]
	%cond4701 = setlt long %cast4727, %cast4728		; <bool>	[#uses=1]
	br bool %cond4701, label %bb4, label %bb3

bb3:					;[#uses=3]
	br label %bb4

bb4:					;[#uses=2]
	%reg132 = phi uint [ 0, %bb3 ], [ 1, %bb2 ]		; <uint>	[#uses=1]
	%cast4729 = cast ulong 8 to double *		; <double *>	[#uses=1]
	%reg4702 = add double * %cast4693, %cast4729		; <double *>	[#uses=1]
	%reg120 = load double * %reg4702		; <double>	[#uses=1]
	%cast4730 = cast ulong 8 to %treeptr		; <%treeptr>	[#uses=1]
	%reg4703 = add %treeptr %t, %cast4730		; <%treeptr>	[#uses=1]
	%cast4731 = cast %treeptr %reg4703 to double *		; <double *>	[#uses=1]
	%reg121 = load double * %cast4731		; <double>	[#uses=1]
	%reg122 = sub double %reg120, %reg121		; <double>	[#uses=1]
	%reg133 = div double %reg122, %reg110		; <double>	[#uses=2]
	%cast4736 = cast double %reg133 to long		; <long>	[#uses=1]
	%cast4737 = cast double 0.000000 to long		; <long>	[#uses=1]
	%cond4704 = setge long %cast4736, %cast4737		; <bool>	[#uses=1]
	br bool %cond4704, label %bb5, label %bb6

bb5:					;[#uses=2]
	%cast4738 = cast double %reg133 to long		; <long>	[#uses=1]
	%cast4739 = cast double 1.000000 to long		; <long>	[#uses=1]
	%cond4705 = setlt long %cast4738, %cast4739		; <bool>	[#uses=1]
	br bool %cond4705, label %bb7, label %bb6

bb6:					;[#uses=3]
	br label %bb7

bb7:					;[#uses=2]
	%reg135 = phi uint [ 0, %bb6 ], [ %reg132, %bb5 ]		; <uint>	[#uses=1]
	%cast4740 = cast ulong 16 to double *		; <double *>	[#uses=1]
	%reg4706 = add double * %cast4693, %cast4740		; <double *>	[#uses=1]
	%reg125 = load double * %reg4706		; <double>	[#uses=1]
	%cast4741 = cast ulong 16 to %treeptr		; <%treeptr>	[#uses=1]
	%reg4707 = add %treeptr %t, %cast4741		; <%treeptr>	[#uses=1]
	%cast4742 = cast %treeptr %reg4707 to double *		; <double *>	[#uses=1]
	%reg126 = load double * %cast4742		; <double>	[#uses=1]
	%reg127 = sub double %reg125, %reg126		; <double>	[#uses=1]
	%reg136 = div double %reg127, %reg110		; <double>	[#uses=2]
	%cast4747 = cast double %reg136 to long		; <long>	[#uses=1]
	%cast4748 = cast double 0.000000 to long		; <long>	[#uses=1]
	%cond4708 = setge long %cast4747, %cast4748		; <bool>	[#uses=1]
	br bool %cond4708, label %bb8, label %bb9

bb8:					;[#uses=2]
	%cast4749 = cast double %reg136 to long		; <long>	[#uses=1]
	%cast4750 = cast double 1.000000 to long		; <long>	[#uses=1]
	%cond4709 = setlt long %cast4749, %cast4750		; <bool>	[#uses=1]
	br bool %cond4709, label %bb10, label %bb9

bb9:					;[#uses=3]
	br label %bb10

bb10:					;[#uses=2]
	%reg138 = phi uint [ 0, %bb9 ], [ %reg135, %bb8 ]		; <uint>	[#uses=1]
	%cast4751 = cast uint %reg138 to int		; <int>	[#uses=1]
	ret int %cast4751

bb11:					;[#uses=0]
	ret int 42
end

int "subindex"(%bodyptr %p, %treeptr %t, int %l)
begin
bb0:					;[#uses=0]
	%xp = alloca [3 x int]		; <[3 x int] *>	[#uses=1]
	%cast4898 = cast [3 x int] * %xp to int *		; <int *>	[#uses=4]
	%pos = alloca %vector		; <%vector *>	[#uses=1]
	%cast4899 = cast %vector * %pos to double *		; <double *>	[#uses=5]
	br label %bb1

bb1:					;[#uses=1]
	%eptr5291 = getelementptr %bodyptr %p, ubyte 2		; <%vector *>	[#uses=1]
	%cast4929 = cast %vector * %eptr5291 to double *		; <double *>	[#uses=1]
	%reg114 = load double * %cast4929		; <double>	[#uses=2]
	store double %reg114, double * %cast4899
	%cast4930 = cast ulong 24 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg4901 = add %bodyptr %p, %cast4930		; <%bodyptr>	[#uses=1]
	%cast4931 = cast %bodyptr %reg4901 to double *		; <double *>	[#uses=1]
	%reg115 = load double * %cast4931		; <double>	[#uses=1]
	%cast4932 = cast ulong 8 to double *		; <double *>	[#uses=1]
	%reg4902 = add double * %cast4899, %cast4932		; <double *>	[#uses=1]
	store double %reg115, double * %reg4902
	%cast4933 = cast ulong 32 to %bodyptr		; <%bodyptr>	[#uses=1]
	%reg4903 = add %bodyptr %p, %cast4933		; <%bodyptr>	[#uses=1]
	%cast4934 = cast %bodyptr %reg4903 to double *		; <double *>	[#uses=1]
	%reg116 = load double * %cast4934		; <double>	[#uses=1]
	%cast4935 = cast ulong 16 to double *		; <double *>	[#uses=1]
	%reg4904 = add double * %cast4899, %cast4935		; <double *>	[#uses=1]
	store double %reg116, double * %reg4904
	%reg112 = load %treeptr %t, ubyte 1		; <double>	[#uses=3]
	%cast4938 = cast %treeptr %t to double *		; <double *>	[#uses=1]
	%reg118 = load double * %cast4938		; <double>	[#uses=1]
	%reg119 = sub double %reg114, %reg118		; <double>	[#uses=1]
	%reg113 = div double %reg119, %reg112		; <double>	[#uses=3]
	%cast4943 = cast double %reg113 to long		; <long>	[#uses=1]
	%cast4944 = cast double 0.000000 to long		; <long>	[#uses=1]
	%cond4906 = setge long %cast4943, %cast4944		; <bool>	[#uses=1]
	br bool %cond4906, label %bb2, label %bb3

bb2:					;[#uses=1]
	%cast4945 = cast double %reg113 to long		; <long>	[#uses=1]
	%cast4946 = cast double 1.000000 to long		; <long>	[#uses=1]
	%cond4907 = setlt long %cast4945, %cast4946		; <bool>	[#uses=1]
	br bool %cond4907, label %bb4, label %bb3

bb3:					;[#uses=2]
	%cast4908 = cast ulong 5 to uint		; <uint>	[#uses=1]
	%cast4947 = cast [22 x sbyte] * %__intern_LC5 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast4947, uint %cast4908 )		; <int>:0	[#uses=0]
	%cast4909 = cast ulong 0 to uint		; <uint>	[#uses=1]
	call %proc %exit( uint %cast4909 )
	br label %bb4

bb4:					;[#uses=2]
	%reg126 = mul double %reg113, 1073741824.000000		; <double>	[#uses=1]
	%reg127 = call %rproc %floor( double %reg126 )		; <double>	[#uses=1]
	%cast128 = cast double %reg127 to int		; <int>	[#uses=1]
	store int %cast128, int * %cast4898
	%cast4948 = cast ulong 8 to double *		; <double *>	[#uses=1]
	%reg4910 = add double * %cast4899, %cast4948		; <double *>	[#uses=1]
	%reg129 = load double * %reg4910		; <double>	[#uses=1]
	%cast4949 = cast ulong 8 to %treeptr		; <%treeptr>	[#uses=1]
	%reg4911 = add %treeptr %t, %cast4949		; <%treeptr>	[#uses=1]
	%cast4950 = cast %treeptr %reg4911 to double *		; <double *>	[#uses=1]
	%reg130 = load double * %cast4950		; <double>	[#uses=1]
	%reg131 = sub double %reg129, %reg130		; <double>	[#uses=1]
	%reg166 = div double %reg131, %reg112		; <double>	[#uses=3]
	%cast4955 = cast double %reg166 to long		; <long>	[#uses=1]
	%cast4956 = cast double 0.000000 to long		; <long>	[#uses=1]
	%cond4912 = setge long %cast4955, %cast4956		; <bool>	[#uses=1]
	br bool %cond4912, label %bb5, label %bb6

bb5:					;[#uses=1]
	%cast4957 = cast double %reg166 to long		; <long>	[#uses=1]
	%cast4958 = cast double 1.000000 to long		; <long>	[#uses=1]
	%cond4913 = setlt long %cast4957, %cast4958		; <bool>	[#uses=1]
	br bool %cond4913, label %bb7, label %bb6

bb6:					;[#uses=2]
	%cast4914 = cast ulong 6 to uint		; <uint>	[#uses=1]
	%cast4959 = cast [22 x sbyte] * %__intern_LC5 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast4959, uint %cast4914 )		; <int>:1	[#uses=0]
	%cast4915 = cast ulong 0 to uint		; <uint>	[#uses=1]
	call %proc %exit( uint %cast4915 )
	br label %bb7

bb7:					;[#uses=2]
	%reg138 = mul double %reg166, 1073741824.000000		; <double>	[#uses=1]
	%reg139 = call %rproc %floor( double %reg138 )		; <double>	[#uses=1]
	%cast140 = cast double %reg139 to int		; <int>	[#uses=1]
	%cast4960 = cast ulong 4 to int *		; <int *>	[#uses=1]
	%reg4916 = add int * %cast4898, %cast4960		; <int *>	[#uses=1]
	store int %cast140, int * %reg4916
	%cast4961 = cast ulong 16 to double *		; <double *>	[#uses=1]
	%reg4917 = add double * %cast4899, %cast4961		; <double *>	[#uses=1]
	%reg141 = load double * %reg4917		; <double>	[#uses=1]
	%cast4962 = cast ulong 16 to %treeptr		; <%treeptr>	[#uses=1]
	%reg4918 = add %treeptr %t, %cast4962		; <%treeptr>	[#uses=1]
	%cast4963 = cast %treeptr %reg4918 to double *		; <double *>	[#uses=1]
	%reg142 = load double * %cast4963		; <double>	[#uses=1]
	%reg143 = sub double %reg141, %reg142		; <double>	[#uses=1]
	%reg167 = div double %reg143, %reg112		; <double>	[#uses=3]
	%cast4968 = cast double %reg167 to long		; <long>	[#uses=1]
	%cast4969 = cast double 0.000000 to long		; <long>	[#uses=1]
	%cond4919 = setge long %cast4968, %cast4969		; <bool>	[#uses=1]
	br bool %cond4919, label %bb8, label %bb9

bb8:					;[#uses=1]
	%cast4970 = cast double %reg167 to long		; <long>	[#uses=1]
	%cast4971 = cast double 1.000000 to long		; <long>	[#uses=1]
	%cond4920 = setlt long %cast4970, %cast4971		; <bool>	[#uses=1]
	br bool %cond4920, label %bb10, label %bb9

bb9:					;[#uses=2]
	%cast4921 = cast ulong 7 to uint		; <uint>	[#uses=1]
	%cast4972 = cast [22 x sbyte] * %__intern_LC5 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast4972, uint %cast4921 )		; <int>:2	[#uses=0]
	%cast4922 = cast ulong 0 to uint		; <uint>	[#uses=1]
	call %proc %exit( uint %cast4922 )
	br label %bb10

bb10:					;[#uses=5]
	%reg150 = mul double %reg167, 1073741824.000000		; <double>	[#uses=1]
	%reg151 = call %rproc %floor( double %reg150 )		; <double>	[#uses=1]
	%cast152 = cast double %reg151 to int		; <int>	[#uses=1]
	%cast4973 = cast ulong 8 to int *		; <int *>	[#uses=1]
	%reg4923 = add int * %cast4898, %cast4973		; <int *>	[#uses=1]
	store int %cast152, int * %reg4923
	%cond4924 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond4924, label %bb14, label %bb11

bb11:					;[#uses=3]
	%reg168 = phi int [ %reg172, %bb13 ], [ 0, %bb10 ]		; <int>	[#uses=3]
	%reg169 = phi int [ %reg171, %bb13 ], [ 0, %bb10 ]		; <int>	[#uses=2]
	%cast4974 = cast int %reg168 to uint		; <uint>	[#uses=1]
	%reg154 = shl uint %cast4974, ubyte 2		; <uint>	[#uses=1]
	%cast155 = cast uint %reg154 to int *		; <int *>	[#uses=1]
	%reg159 = add int * %cast4898, %cast155		; <int *>	[#uses=1]
	%reg160 = load int * %reg159		; <int>	[#uses=1]
	%reg161 = and int %reg160, %l		; <int>	[#uses=1]
	%cond4925 = seteq int %reg161, 0		; <bool>	[#uses=1]
	br bool %cond4925, label %bb13, label %bb12

bb12:					;[#uses=2]
	%reg162 = add int %reg168, 1		; <int>	[#uses=1]
	%cast4927 = cast int %reg162 to ubyte		; <ubyte>	[#uses=1]
	%reg163 = shr int 8, ubyte %cast4927		; <int>	[#uses=1]
	%reg170 = add int %reg169, %reg163		; <int>	[#uses=1]
	br label %bb13

bb13:					;[#uses=5]
	%reg171 = phi int [ %reg170, %bb12 ], [ %reg169, %bb11 ]		; <int>	[#uses=2]
	%reg172 = add int %reg168, 1		; <int>	[#uses=2]
	%cond4926 = setle int %reg172, 2		; <bool>	[#uses=1]
	br bool %cond4926, label %bb11, label %bb14

bb14:					;[#uses=2]
	%reg173 = phi int [ %reg171, %bb13 ], [ 0, %bb10 ]		; <int>	[#uses=1]
	ret int %reg173

bb15:					;[#uses=0]
	ret int 42
end

int "old_subindex"(%icstruct * %ic, int %l)
begin
bb1:					;[#uses=3]
	%cond5293 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond5293, label %bb5, label %bb2

bb2:					;[#uses=3]
	%reg122 = phi int [ %reg126, %bb4 ], [ 0, %bb1 ]		; <int>	[#uses=3]
	%reg123 = phi int [ %reg125, %bb4 ], [ 0, %bb1 ]		; <int>	[#uses=2]
	%cast5297 = cast int %reg122 to uint		; <uint>	[#uses=1]
	%reg112 = shl uint %cast5297, ubyte 2		; <uint>	[#uses=1]
	%cast113 = cast uint %reg112 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg115 = add %icstruct * %ic, %cast113		; <%icstruct *>	[#uses=1]
	%cast5298 = cast %icstruct * %reg115 to int *		; <int *>	[#uses=1]
	%reg116 = load int * %cast5298		; <int>	[#uses=1]
	%reg117 = and int %reg116, %l		; <int>	[#uses=1]
	%cond5294 = seteq int %reg117, 0		; <bool>	[#uses=1]
	br bool %cond5294, label %bb4, label %bb3

bb3:					;[#uses=2]
	%reg118 = add int %reg122, 1		; <int>	[#uses=1]
	%cast5296 = cast int %reg118 to ubyte		; <ubyte>	[#uses=1]
	%reg119 = shr int 8, ubyte %cast5296		; <int>	[#uses=1]
	%reg124 = add int %reg123, %reg119		; <int>	[#uses=1]
	br label %bb4

bb4:					;[#uses=5]
	%reg125 = phi int [ %reg124, %bb3 ], [ %reg123, %bb2 ]		; <int>	[#uses=2]
	%reg126 = add int %reg122, 1		; <int>	[#uses=2]
	%cond5295 = setle int %reg126, 2		; <bool>	[#uses=1]
	br bool %cond5295, label %bb2, label %bb5

bb5:					;[#uses=2]
	%reg127 = phi int [ %reg125, %bb4 ], [ 0, %bb1 ]		; <int>	[#uses=1]
	ret int %reg127

bb6:					;[#uses=0]
	ret int 42
end

double "hackcofm"(%nodeptr %q)
begin
bb0:					;[#uses=0]
	%tmpv = alloca %vector		; <%vector *>	[#uses=2]
	%tmp_pos = alloca %vector		; <%vector *>	[#uses=3]
	%cast5304 = cast %vector * %tmp_pos to double *		; <double *>	[#uses=3]
	br label %bb1

bb1:					;[#uses=1]
	%reg112 = load %nodeptr %q, ubyte 0		; <short>	[#uses=1]
	%cast112 = cast short %reg112 to ushort		; <ushort>	[#uses=1]
	%cond5305 = setne ushort %cast112, 2		; <bool>	[#uses=1]
	br bool %cond5305, label %bb14, label %bb2

bb2:					;[#uses=2]
	%cond5306 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond5306, label %bb4, label %bb3

bb3:					;[#uses=3]
	%reg190 = phi int [ %reg191, %bb3 ], [ 0, %bb2 ]		; <int>	[#uses=2]
	%cast5326 = cast int %reg190 to uint		; <uint>	[#uses=1]
	%reg115 = shl uint %cast5326, ubyte 3		; <uint>	[#uses=1]
	%cast116 = cast uint %reg115 to ulong *		; <ulong *>	[#uses=1]
	%cast5327 = cast %vector * %tmp_pos to ulong *		; <ulong *>	[#uses=1]
	%reg120 = add ulong * %cast5327, %cast116		; <ulong *>	[#uses=1]
	%cast5328 = cast ulong * %reg120 to double *		; <double *>	[#uses=1]
	store double 0.000000, double * %cast5328
	%reg191 = add int %reg190, 1		; <int>	[#uses=2]
	%cond5307 = setle int %reg191, 2		; <bool>	[#uses=1]
	br bool %cond5307, label %bb3, label %bb4

bb4:					;[#uses=5]
	%cond5308 = setgt long 0, 7		; <bool>	[#uses=1]
	br bool %cond5308, label %bb11, label %bb5

bb5:					;[#uses=3]
	%reg192 = phi double [ %reg199, %bb10 ], [ 0.000000, %bb4 ]		; <double>	[#uses=2]
	%reg193 = phi int [ %reg200, %bb10 ], [ 0, %bb4 ]		; <int>	[#uses=2]
	%cast5330 = cast int %reg193 to uint		; <uint>	[#uses=1]
	%reg123 = shl uint %cast5330, ubyte 3		; <uint>	[#uses=1]
	%reg124 = add uint %reg123, 48		; <uint>	[#uses=1]
	%cast125 = cast uint %reg124 to %nodeptr		; <%nodeptr>	[#uses=1]
	%reg127 = add %nodeptr %q, %cast125		; <%nodeptr>	[#uses=1]
	%cast5331 = cast %nodeptr %reg127 to %nodeptr *		; <%nodeptr *>	[#uses=1]
	%reg109 = load %nodeptr * %cast5331		; <%nodeptr>	[#uses=3]
	%cond5309 = seteq %nodeptr %reg109, null		; <bool>	[#uses=1]
	br bool %cond5309, label %bb10, label %bb6

bb6:					;[#uses=2]
	%reg111 = call double (%nodeptr) * %hackcofm( %nodeptr %reg109 )		; <double>	[#uses=2]
	%reg194 = add double %reg192, %reg111		; <double>	[#uses=2]
	%cond5310 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond5310, label %bb8, label %bb7

bb7:					;[#uses=3]
	%reg195 = phi int [ %reg196, %bb7 ], [ 0, %bb6 ]		; <int>	[#uses=2]
	%cast5333 = cast int %reg195 to uint		; <uint>	[#uses=1]
	%reg130 = shl uint %cast5333, ubyte 3		; <uint>	[#uses=2]
	%cast131 = cast uint %reg130 to ulong *		; <ulong *>	[#uses=1]
	%cast5334 = cast %vector * %tmpv to ulong *		; <ulong *>	[#uses=1]
	%reg135 = add ulong * %cast5334, %cast131		; <ulong *>	[#uses=1]
	%reg138 = add uint %reg130, 16		; <uint>	[#uses=1]
	%cast139 = cast uint %reg138 to %nodeptr		; <%nodeptr>	[#uses=1]
	%reg141 = add %nodeptr %reg109, %cast139		; <%nodeptr>	[#uses=1]
	%cast5335 = cast %nodeptr %reg141 to double *		; <double *>	[#uses=1]
	%reg142 = load double * %cast5335		; <double>	[#uses=1]
	%reg143 = mul double %reg142, %reg111		; <double>	[#uses=1]
	%cast5336 = cast ulong * %reg135 to double *		; <double *>	[#uses=1]
	store double %reg143, double * %cast5336
	%reg196 = add int %reg195, 1		; <int>	[#uses=2]
	%cond5311 = setle int %reg196, 2		; <bool>	[#uses=1]
	br bool %cond5311, label %bb7, label %bb8

bb8:					;[#uses=4]
	%cond5312 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond5312, label %bb10, label %bb9

bb9:					;[#uses=4]
	%reg197 = phi int [ %reg198, %bb9 ], [ 0, %bb8 ]		; <int>	[#uses=2]
	%cast5338 = cast int %reg197 to uint		; <uint>	[#uses=1]
	%reg146 = shl uint %cast5338, ubyte 3		; <uint>	[#uses=1]
	%cast147 = cast uint %reg146 to ulong *		; <ulong *>	[#uses=2]
	%cast5339 = cast %vector * %tmp_pos to ulong *		; <ulong *>	[#uses=1]
	%reg151 = add ulong * %cast5339, %cast147		; <ulong *>	[#uses=2]
	%cast5340 = cast %vector * %tmpv to ulong *		; <ulong *>	[#uses=1]
	%reg165 = add ulong * %cast5340, %cast147		; <ulong *>	[#uses=1]
	%cast5341 = cast ulong * %reg151 to double *		; <double *>	[#uses=1]
	%reg166 = load double * %cast5341		; <double>	[#uses=1]
	%cast5342 = cast ulong * %reg165 to double *		; <double *>	[#uses=1]
	%reg167 = load double * %cast5342		; <double>	[#uses=1]
	%reg168 = add double %reg166, %reg167		; <double>	[#uses=1]
	%cast5343 = cast ulong * %reg151 to double *		; <double *>	[#uses=1]
	store double %reg168, double * %cast5343
	%reg198 = add int %reg197, 1		; <int>	[#uses=2]
	%cond5313 = setle int %reg198, 2		; <bool>	[#uses=1]
	br bool %cond5313, label %bb9, label %bb10

bb10:					;[#uses=6]
	%reg199 = phi double [ %reg194, %bb9 ], [ %reg194, %bb8 ], [ %reg192, %bb5 ]		; <double>	[#uses=2]
	%reg200 = add int %reg193, 1		; <int>	[#uses=2]
	%cond5314 = setle int %reg200, 7		; <bool>	[#uses=1]
	br bool %cond5314, label %bb5, label %bb11

bb11:					;[#uses=3]
	%reg201 = phi double [ %reg199, %bb10 ], [ 0.000000, %bb4 ]		; <double>	[#uses=2]
	store double %reg201, %nodeptr %q, ubyte 1
	%reg169 = load double * %cast5304		; <double>	[#uses=1]
	%eptr5452 = getelementptr %nodeptr %q, ubyte 2		; <%vector *>	[#uses=1]
	%cast5349 = cast %vector * %eptr5452 to double *		; <double *>	[#uses=1]
	store double %reg169, double * %cast5349
	%cast5350 = cast ulong 8 to double *		; <double *>	[#uses=1]
	%reg5317 = add double * %cast5304, %cast5350		; <double *>	[#uses=1]
	%reg170 = load double * %reg5317		; <double>	[#uses=1]
	%cast5351 = cast ulong 24 to %nodeptr		; <%nodeptr>	[#uses=1]
	%reg5318 = add %nodeptr %q, %cast5351		; <%nodeptr>	[#uses=1]
	%cast5352 = cast %nodeptr %reg5318 to double *		; <double *>	[#uses=1]
	store double %reg170, double * %cast5352
	%cast5353 = cast ulong 16 to double *		; <double *>	[#uses=1]
	%reg5319 = add double * %cast5304, %cast5353		; <double *>	[#uses=1]
	%reg171 = load double * %reg5319		; <double>	[#uses=1]
	%cast5354 = cast ulong 32 to %nodeptr		; <%nodeptr>	[#uses=1]
	%reg5320 = add %nodeptr %q, %cast5354		; <%nodeptr>	[#uses=1]
	%cast5355 = cast %nodeptr %reg5320 to double *		; <double *>	[#uses=1]
	store double %reg171, double * %cast5355
	%cond5321 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond5321, label %bb13, label %bb12

bb12:					;[#uses=3]
	%reg202 = phi int [ %reg203, %bb12 ], [ 0, %bb11 ]		; <int>	[#uses=2]
	%cast5356 = cast int %reg202 to uint		; <uint>	[#uses=1]
	%reg174 = shl uint %cast5356, ubyte 3		; <uint>	[#uses=1]
	%reg175 = add uint %reg174, 16		; <uint>	[#uses=1]
	%cast176 = cast uint %reg175 to %nodeptr		; <%nodeptr>	[#uses=1]
	%reg178 = add %nodeptr %q, %cast176		; <%nodeptr>	[#uses=2]
	%cast5357 = cast %nodeptr %reg178 to double *		; <double *>	[#uses=1]
	%reg185 = load double * %cast5357		; <double>	[#uses=1]
	%reg186 = load %nodeptr %q, ubyte 1		; <double>	[#uses=1]
	%reg187 = div double %reg185, %reg186		; <double>	[#uses=1]
	%cast5364 = cast %nodeptr %reg178 to double *		; <double *>	[#uses=1]
	store double %reg187, double * %cast5364
	%reg203 = add int %reg202, 1		; <int>	[#uses=2]
	%cond5323 = setle int %reg203, 2		; <bool>	[#uses=1]
	br bool %cond5323, label %bb12, label %bb13

bb13:					;[#uses=2]
	ret double %reg201

bb14:					;[#uses=1]
	%reg204 = load %nodeptr %q, ubyte 1		; <double>	[#uses=1]
	ret double %reg204

bb15:					;[#uses=0]
	%cast5368 = cast ulong 42 to double		; <double>	[#uses=1]
	ret double %cast5368
end

int "dis2_number"(%nodeptr %n, int %prev_bodies, int %tnperproc)
begin
bb1:					;[#uses=0]
	%cond5503 = setne %nodeptr %n, null		; <bool>	[#uses=1]
	br bool %cond5503, label %bb3, label %bb2

bb2:					;[#uses=1]
	ret int %prev_bodies

bb3:					;[#uses=1]
	%reg111 = load %nodeptr %n, ubyte 0		; <short>	[#uses=1]
	%cast111 = cast short %reg111 to ushort		; <ushort>	[#uses=1]
	%cond5504 = setne ushort %cast111, 1		; <bool>	[#uses=1]
	br bool %cond5504, label %bb5, label %bb4

bb4:					;[#uses=1]
	%reg112 = add int %prev_bodies, 1		; <int>	[#uses=2]
	%reg114 = div int %reg112, %tnperproc		; <int>	[#uses=1]
	store int %reg114, %nodeptr %n, ubyte 4
	ret int %reg112

bb5:					;[#uses=4]
	%cond5506 = setgt long 0, 7		; <bool>	[#uses=1]
	br bool %cond5506, label %bb7, label %bb6

bb6:					;[#uses=5]
	%reg125 = phi int [ %reg128, %bb6 ], [ 0, %bb5 ]		; <int>	[#uses=2]
	%reg126 = phi int [ %reg127, %bb6 ], [ %prev_bodies, %bb5 ]		; <int>	[#uses=1]
	%cast5512 = cast int %reg125 to uint		; <uint>	[#uses=1]
	%reg119 = shl uint %cast5512, ubyte 3		; <uint>	[#uses=1]
	%reg120 = add uint %reg119, 48		; <uint>	[#uses=1]
	%cast121 = cast uint %reg120 to %nodeptr		; <%nodeptr>	[#uses=1]
	%reg123 = add %nodeptr %n, %cast121		; <%nodeptr>	[#uses=1]
	%cast5513 = cast %nodeptr %reg123 to %nodeptr *		; <%nodeptr *>	[#uses=1]
	%reg117 = load %nodeptr * %cast5513		; <%nodeptr>	[#uses=1]
	%reg127 = call int (%nodeptr, int, int) * %dis2_number( %nodeptr %reg117, int %reg126, int %tnperproc )		; <int>	[#uses=2]
	%reg128 = add int %reg125, 1		; <int>	[#uses=2]
	%cond5507 = setle int %reg128, 7		; <bool>	[#uses=1]
	br bool %cond5507, label %bb6, label %bb7

bb7:					;[#uses=2]
	%reg129 = phi int [ %reg127, %bb6 ], [ %prev_bodies, %bb5 ]		; <int>	[#uses=1]
	ret int %reg129

bb8:					;[#uses=0]
	ret int 42
end

void "dis_number"(%nodeptr %n)
begin
bb1:					;[#uses=0]
	%reg110 = load int * %nbody		; <int>	[#uses=1]
	%reg112 = load int * %NumNodes		; <int>	[#uses=1]
	%cast5501 = cast int %reg110 to double		; <double>	[#uses=1]
	%cast5502 = cast int %reg112 to double		; <double>	[#uses=1]
	%reg113 = div double %cast5501, %cast5502		; <double>	[#uses=1]
	%reg114 = call %rproc %ceil( double %reg113 )		; <double>	[#uses=1]
	%cast108 = cast double %reg114 to int		; <int>	[#uses=1]
	%cast5490 = cast long -1 to int		; <int>	[#uses=1]
	call int (%nodeptr, int, int) * %dis2_number( %nodeptr %n, int %cast5490, int %cast108 )		; <int>:0	[#uses=0]
	ret void
end

declare double "floor"(...)

void "printtree"(%nodeptr %n)
begin
bb1:					;[#uses=0]
	%cast5455 = cast ulong 0 to int		; <int>	[#uses=1]
	call void (%nodeptr, int) * %ptree( %nodeptr %n, int %cast5455 )
	ret void
end

%treeptr "old_main"()
begin
bb0:					;[#uses=0]
	%cmr = alloca %vector		; <%vector *>	[#uses=4]
	%cmv = alloca %vector		; <%vector *>	[#uses=4]
	%bodiesper = alloca [64 x int]		; <[64 x int] *>	[#uses=1]
	%cast1003 = cast [64 x int] * %bodiesper to int *		; <int *>	[#uses=3]
	%ptrper = alloca [64 x %bodyptr]		; <[64 x %bodyptr] *>	[#uses=1]
	%cast1004 = cast [64 x %bodyptr] * %ptrper to %bodyptr *		; <%bodyptr *>	[#uses=3]
	%fc = alloca [32 x %fc_datapoints]		; <[32 x %fc_datapoints] *>	[#uses=0]
	%points = alloca %datapoints		; <%datapoints *>	[#uses=5]
	%xqic = alloca %icstruct		; <%icstruct *>	[#uses=9]
	br label %bb1

bb1:					;[#uses=2]
	%reg120 = load int * %NumNodes		; <int>	[#uses=1]
	%reg119 = div int 64, %reg120		; <int>	[#uses=1]
	%cast1006 = cast ulong 123 to uint		; <uint>	[#uses=1]
	call %iproc %srand( uint %cast1006 )		; <int>:0	[#uses=0]
	%cast1007 = cast ulong 1064 to uint		; <uint>	[#uses=1]
	%reg123 = call sbyte * (...) * %malloc( uint %cast1007 )		; <sbyte *>	[#uses=11]
	%cast1065 = cast ulong 32 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1008 = add sbyte * %reg123, %cast1065		; <sbyte *>	[#uses=1]
	%cast1066 = cast sbyte * %reg1008 to ulong * *		; <ulong * *>	[#uses=1]
	store ulong * null, ulong * * %cast1066
	%cast1067 = cast sbyte * %reg123 to double *		; <double *>	[#uses=1]
	store double -2.000000, double * %cast1067
	%cast1068 = cast ulong 8 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1009 = add sbyte * %reg123, %cast1068		; <sbyte *>	[#uses=1]
	%cast1069 = cast sbyte * %reg1009 to double *		; <double *>	[#uses=1]
	store double -2.000000, double * %cast1069
	%cast1070 = cast ulong 16 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1010 = add sbyte * %reg123, %cast1070		; <sbyte *>	[#uses=1]
	%cast1071 = cast sbyte * %reg1010 to double *		; <double *>	[#uses=1]
	store double -2.000000, double * %cast1071
	%cast1072 = cast ulong 24 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1011 = add sbyte * %reg123, %cast1072		; <sbyte *>	[#uses=1]
	%cast1073 = cast sbyte * %reg1011 to double *		; <double *>	[#uses=1]
	store double 4.000000, double * %cast1073
	%cond1012 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond1012, label %bb3, label %bb2

bb2:					;[#uses=3]
	%reg399 = phi int [ %reg400, %bb2 ], [ 0, %bb1 ]		; <int>	[#uses=2]
	%cast1074 = cast int %reg399 to uint		; <uint>	[#uses=1]
	%reg131 = shl uint %cast1074, ubyte 3		; <uint>	[#uses=1]
	%cast132 = cast uint %reg131 to ulong *		; <ulong *>	[#uses=1]
	%cast1075 = cast %vector * %cmr to ulong *		; <ulong *>	[#uses=1]
	%reg136 = add ulong * %cast1075, %cast132		; <ulong *>	[#uses=1]
	%cast1076 = cast ulong * %reg136 to double *		; <double *>	[#uses=1]
	store double 0.000000, double * %cast1076
	%reg400 = add int %reg399, 1		; <int>	[#uses=2]
	%cond1013 = setle int %reg400, 2		; <bool>	[#uses=1]
	br bool %cond1013, label %bb2, label %bb3

bb3:					;[#uses=3]
	%cond1014 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond1014, label %bb5, label %bb4

bb4:					;[#uses=3]
	%reg401 = phi int [ %reg402, %bb4 ], [ 0, %bb3 ]		; <int>	[#uses=2]
	%cast1078 = cast int %reg401 to uint		; <uint>	[#uses=1]
	%reg140 = shl uint %cast1078, ubyte 3		; <uint>	[#uses=1]
	%cast141 = cast uint %reg140 to ulong *		; <ulong *>	[#uses=1]
	%cast1079 = cast %vector * %cmv to ulong *		; <ulong *>	[#uses=1]
	%reg145 = add ulong * %cast1079, %cast141		; <ulong *>	[#uses=1]
	%cast1080 = cast ulong * %reg145 to double *		; <double *>	[#uses=1]
	store double 0.000000, double * %cast1080
	%reg402 = add int %reg401, 1		; <int>	[#uses=2]
	%cond1015 = setle int %reg402, 2		; <bool>	[#uses=1]
	br bool %cond1015, label %bb4, label %bb5

bb5:					;[#uses=4]
	%cond1016 = setgt long 0, 31		; <bool>	[#uses=1]
	br bool %cond1016, label %bb15, label %bb6

bb6:					;[#uses=3]
	%reg403 = phi ulong * [ %cast407, %bb14 ], [ null, %bb5 ]		; <ulong *>	[#uses=2]
	%reg404 = phi int [ %reg412, %bb14 ], [ 0, %bb5 ]		; <int>	[#uses=4]
	%cast1091 = cast ulong * %reg403 to ulong * *		; <ulong * *>	[#uses=1]
	%cast1085 = cast int %reg404 to uint		; <uint>	[#uses=1]
	%reg149 = load int * %NumNodes		; <int>	[#uses=1]
	%reg150 = div int 32, %reg149		; <int>	[#uses=1]
	%reg147 = div int %reg404, %reg150		; <int>	[#uses=1]
	%reg154 = load int * %nbody		; <int>	[#uses=3]
	%cond1017 = setge int %reg154, 0		; <bool>	[#uses=1]
	br bool %cond1017, label %bb8, label %bb7

bb7:					;[#uses=2]
	%reg405 = add int %reg154, 31		; <int>	[#uses=1]
	br label %bb8

bb8:					;[#uses=2]
	%reg406 = phi int [ %reg405, %bb7 ], [ %reg154, %bb6 ]		; <int>	[#uses=1]
	%reg152 = shr int %reg406, ubyte 5		; <int>	[#uses=1]
	%reg155 = add int %reg404, 1		; <int>	[#uses=1]
	call %datapoints * (%datapoints *, int, int, int) * %uniform_testdata( %datapoints * %points, int %reg147, int %reg152, int %reg155 )		; <%datapoints *>:0	[#uses=0]
	%reg157 = shl uint %cast1085, ubyte 3		; <uint>	[#uses=1]
	%reg158 = add uint %reg157, 40		; <uint>	[#uses=1]
	%cast159 = cast uint %reg158 to sbyte *		; <sbyte *>	[#uses=1]
	%reg161 = add sbyte * %reg123, %cast159		; <sbyte *>	[#uses=1]
	%cast1088 = cast sbyte * %reg161 to ulong * *		; <ulong * *>	[#uses=1]
	%reg162 = load %datapoints * %points, ubyte 2		; <%bodyptr>	[#uses=1]
	%cast162 = cast %bodyptr %reg162 to ulong *		; <ulong *>	[#uses=2]
	store ulong * %cast162, ulong * * %cast1088
	%cond1019 = seteq ulong * %reg403, null		; <bool>	[#uses=1]
	br bool %cond1019, label %bb10, label %bb9

bb9:					;[#uses=1]
	%cast1090 = cast ulong 128 to ulong * *		; <ulong * *>	[#uses=1]
	%reg1020 = add ulong * * %cast1091, %cast1090		; <ulong * *>	[#uses=1]
	store ulong * %cast162, ulong * * %reg1020
	br label %bb10

bb10:					;[#uses=3]
	%reg407 = load %datapoints * %points, ubyte 3		; <%bodyptr>	[#uses=1]
	%cast407 = cast %bodyptr %reg407 to ulong *		; <ulong *>	[#uses=1]
	%cond1022 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond1022, label %bb12, label %bb11

bb11:					;[#uses=3]
	%reg408 = phi int [ %reg409, %bb11 ], [ 0, %bb10 ]		; <int>	[#uses=2]
	%cast1094 = cast int %reg408 to uint		; <uint>	[#uses=1]
	%reg166 = shl uint %cast1094, ubyte 3		; <uint>	[#uses=1]
	%cast167 = cast uint %reg166 to %datapoints *		; <%datapoints *>	[#uses=2]
	%cast1095 = cast %vector * %cmr to %datapoints *		; <%datapoints *>	[#uses=1]
	%reg171 = add %datapoints * %cast1095, %cast167		; <%datapoints *>	[#uses=2]
	%reg185 = add %datapoints * %points, %cast167		; <%datapoints *>	[#uses=1]
	%cast1096 = cast %datapoints * %reg171 to double *		; <double *>	[#uses=1]
	%reg186 = load double * %cast1096		; <double>	[#uses=1]
	%cast1097 = cast %datapoints * %reg185 to double *		; <double *>	[#uses=1]
	%reg187 = load double * %cast1097		; <double>	[#uses=1]
	%reg188 = add double %reg186, %reg187		; <double>	[#uses=1]
	%cast1098 = cast %datapoints * %reg171 to double *		; <double *>	[#uses=1]
	store double %reg188, double * %cast1098
	%reg409 = add int %reg408, 1		; <int>	[#uses=2]
	%cond1023 = setle int %reg409, 2		; <bool>	[#uses=1]
	br bool %cond1023, label %bb11, label %bb12

bb12:					;[#uses=3]
	%cond1024 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond1024, label %bb14, label %bb13

bb13:					;[#uses=3]
	%reg410 = phi int [ %reg411, %bb13 ], [ 0, %bb12 ]		; <int>	[#uses=2]
	%cast1100 = cast int %reg410 to uint		; <uint>	[#uses=1]
	%reg191 = shl uint %cast1100, ubyte 3		; <uint>	[#uses=2]
	%cast192 = cast uint %reg191 to ulong *		; <ulong *>	[#uses=1]
	%cast1101 = cast %vector * %cmv to ulong *		; <ulong *>	[#uses=1]
	%reg196 = add ulong * %cast1101, %cast192		; <ulong *>	[#uses=2]
	%reg206 = add uint %reg191, 24		; <uint>	[#uses=1]
	%cast207 = cast uint %reg206 to %datapoints *		; <%datapoints *>	[#uses=1]
	%reg211 = add %datapoints * %points, %cast207		; <%datapoints *>	[#uses=1]
	%cast1102 = cast ulong * %reg196 to double *		; <double *>	[#uses=1]
	%reg212 = load double * %cast1102		; <double>	[#uses=1]
	%cast1103 = cast %datapoints * %reg211 to double *		; <double *>	[#uses=1]
	%reg213 = load double * %cast1103		; <double>	[#uses=1]
	%reg214 = add double %reg212, %reg213		; <double>	[#uses=1]
	%cast1104 = cast ulong * %reg196 to double *		; <double *>	[#uses=1]
	store double %reg214, double * %cast1104
	%reg411 = add int %reg410, 1		; <int>	[#uses=2]
	%cond1025 = setle int %reg411, 2		; <bool>	[#uses=1]
	br bool %cond1025, label %bb13, label %bb14

bb14:					;[#uses=4]
	%reg412 = add int %reg404, 1		; <int>	[#uses=2]
	%cond1026 = setle int %reg412, 31		; <bool>	[#uses=1]
	br bool %cond1026, label %bb6, label %bb15

bb15:					;[#uses=3]
	%cast1107 = cast [16 x sbyte] * %__intern_LC1 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *) * %puts( sbyte * %cast1107 )		; <int>:1	[#uses=0]
	%cond1027 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond1027, label %bb17, label %bb16

bb16:					;[#uses=3]
	%reg413 = phi int [ %reg414, %bb16 ], [ 0, %bb15 ]		; <int>	[#uses=2]
	%cast1108 = cast int %reg413 to uint		; <uint>	[#uses=1]
	%reg218 = shl uint %cast1108, ubyte 3		; <uint>	[#uses=1]
	%cast219 = cast uint %reg218 to ulong *		; <ulong *>	[#uses=1]
	%cast1109 = cast %vector * %cmr to ulong *		; <ulong *>	[#uses=1]
	%reg223 = add ulong * %cast1109, %cast219		; <ulong *>	[#uses=2]
	%reg232 = load int * %nbody		; <int>	[#uses=1]
	%cast1110 = cast ulong * %reg223 to double *		; <double *>	[#uses=1]
	%reg233 = load double * %cast1110		; <double>	[#uses=1]
	%cast1799 = cast int %reg232 to double		; <double>	[#uses=1]
	%reg234 = div double %reg233, %cast1799		; <double>	[#uses=1]
	%cast1115 = cast ulong * %reg223 to double *		; <double *>	[#uses=1]
	store double %reg234, double * %cast1115
	%reg414 = add int %reg413, 1		; <int>	[#uses=2]
	%cond1028 = setle int %reg414, 2		; <bool>	[#uses=1]
	br bool %cond1028, label %bb16, label %bb17

bb17:					;[#uses=3]
	%cond1029 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond1029, label %bb19, label %bb18

bb18:					;[#uses=3]
	%reg415 = phi int [ %reg416, %bb18 ], [ 0, %bb17 ]		; <int>	[#uses=2]
	%cast1117 = cast int %reg415 to uint		; <uint>	[#uses=1]
	%reg237 = shl uint %cast1117, ubyte 3		; <uint>	[#uses=1]
	%cast238 = cast uint %reg237 to ulong *		; <ulong *>	[#uses=1]
	%cast1118 = cast %vector * %cmv to ulong *		; <ulong *>	[#uses=1]
	%reg242 = add ulong * %cast1118, %cast238		; <ulong *>	[#uses=2]
	%reg251 = load int * %nbody		; <int>	[#uses=1]
	%cast1119 = cast ulong * %reg242 to double *		; <double *>	[#uses=1]
	%reg252 = load double * %cast1119		; <double>	[#uses=1]
	%cast1803 = cast int %reg251 to double		; <double>	[#uses=1]
	%reg253 = div double %reg252, %cast1803		; <double>	[#uses=1]
	%cast1124 = cast ulong * %reg242 to double *		; <double *>	[#uses=1]
	store double %reg253, double * %cast1124
	%reg416 = add int %reg415, 1		; <int>	[#uses=2]
	%cond1030 = setle int %reg416, 2		; <bool>	[#uses=1]
	br bool %cond1030, label %bb18, label %bb19

bb19:					;[#uses=3]
	%cond1031 = setgt long 0, 63		; <bool>	[#uses=1]
	br bool %cond1031, label %bb21, label %bb20

bb20:					;[#uses=3]
	%reg417 = phi int [ %reg418, %bb20 ], [ 0, %bb19 ]		; <int>	[#uses=3]
	%cast1127 = cast int %reg417 to uint		; <uint>	[#uses=1]
	%cast1126 = cast int %reg417 to uint		; <uint>	[#uses=1]
	%reg255 = shl uint %cast1126, ubyte 2		; <uint>	[#uses=1]
	%cast256 = cast uint %reg255 to int *		; <int *>	[#uses=1]
	%reg260 = add int * %cast1003, %cast256		; <int *>	[#uses=1]
	store int 0, int * %reg260
	%reg263 = shl uint %cast1127, ubyte 3		; <uint>	[#uses=1]
	%cast264 = cast uint %reg263 to %bodyptr *		; <%bodyptr *>	[#uses=1]
	%reg268 = add %bodyptr * %cast1004, %cast264		; <%bodyptr *>	[#uses=1]
	store %bodyptr null, %bodyptr * %reg268
	%reg418 = add int %reg417, 1		; <int>	[#uses=2]
	%cond1032 = setle int %reg418, 63		; <bool>	[#uses=1]
	br bool %cond1032, label %bb20, label %bb21

bb21:					;[#uses=3]
	%cast1129 = cast ulong 40 to sbyte *		; <sbyte *>	[#uses=1]
	%reg1033 = add sbyte * %reg123, %cast1129		; <sbyte *>	[#uses=1]
	%cast1130 = cast sbyte * %reg1033 to ulong * *		; <ulong * *>	[#uses=1]
	%reg114 = load ulong * * %cast1130		; <ulong *>	[#uses=2]
	%cond1034 = seteq ulong * %reg114, null		; <bool>	[#uses=1]
	br bool %cond1034, label %bb27, label %bb22

bb22:					;[#uses=3]
	%reg419 = phi ulong * [ %reg426, %bb26 ], [ %reg114, %bb21 ]		; <ulong *>	[#uses=7]
	%cast1187 = cast ulong * %reg419 to ulong * *		; <ulong * *>	[#uses=1]
	%cast1185 = cast ulong * %reg419 to int *		; <int *>	[#uses=1]
	%cast1183 = cast ulong * %reg419 to %bodyptr *		; <%bodyptr *>	[#uses=1]
	%cast1144 = cast ulong * %reg419 to %bodyptr		; <%bodyptr>	[#uses=1]
	%cond1035 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond1035, label %bb24, label %bb23

bb23:					;[#uses=3]
	%reg420 = phi int [ %reg421, %bb23 ], [ 0, %bb22 ]		; <int>	[#uses=2]
	%cast1132 = cast int %reg420 to uint		; <uint>	[#uses=1]
	%reg272 = shl uint %cast1132, ubyte 3		; <uint>	[#uses=2]
	%reg273 = add uint %reg272, 16		; <uint>	[#uses=1]
	%cast274 = cast uint %reg273 to ulong *		; <ulong *>	[#uses=1]
	%reg276 = add ulong * %reg419, %cast274		; <ulong *>	[#uses=2]
	%cast285 = cast uint %reg272 to ulong *		; <ulong *>	[#uses=1]
	%cast1133 = cast %vector * %cmr to ulong *		; <ulong *>	[#uses=1]
	%reg289 = add ulong * %cast1133, %cast285		; <ulong *>	[#uses=1]
	%cast1134 = cast ulong * %reg276 to double *		; <double *>	[#uses=1]
	%reg290 = load double * %cast1134		; <double>	[#uses=1]
	%cast1135 = cast ulong * %reg289 to double *		; <double *>	[#uses=1]
	%reg291 = load double * %cast1135		; <double>	[#uses=1]
	%reg292 = sub double %reg290, %reg291		; <double>	[#uses=1]
	%cast1136 = cast ulong * %reg276 to double *		; <double *>	[#uses=1]
	store double %reg292, double * %cast1136
	%reg421 = add int %reg420, 1		; <int>	[#uses=2]
	%cond1036 = setle int %reg421, 2		; <bool>	[#uses=1]
	br bool %cond1036, label %bb23, label %bb24

bb24:					;[#uses=3]
	%cond1037 = setgt long 0, 2		; <bool>	[#uses=1]
	br bool %cond1037, label %bb26, label %bb25

bb25:					;[#uses=3]
	%reg422 = phi int [ %reg423, %bb25 ], [ 0, %bb24 ]		; <int>	[#uses=2]
	%cast1138 = cast int %reg422 to uint		; <uint>	[#uses=1]
	%reg295 = shl uint %cast1138, ubyte 3		; <uint>	[#uses=2]
	%reg296 = add uint %reg295, 48		; <uint>	[#uses=1]
	%cast297 = cast uint %reg296 to ulong *		; <ulong *>	[#uses=1]
	%reg299 = add ulong * %reg419, %cast297		; <ulong *>	[#uses=2]
	%cast308 = cast uint %reg295 to ulong *		; <ulong *>	[#uses=1]
	%cast1139 = cast %vector * %cmv to ulong *		; <ulong *>	[#uses=1]
	%reg312 = add ulong * %cast1139, %cast308		; <ulong *>	[#uses=1]
	%cast1140 = cast ulong * %reg299 to double *		; <double *>	[#uses=1]
	%reg313 = load double * %cast1140		; <double>	[#uses=1]
	%cast1141 = cast ulong * %reg312 to double *		; <double *>	[#uses=1]
	%reg314 = load double * %cast1141		; <double>	[#uses=1]
	%reg315 = sub double %reg313, %reg314		; <double>	[#uses=1]
	%cast1142 = cast ulong * %reg299 to double *		; <double *>	[#uses=1]
	store double %reg315, double * %cast1142
	%reg423 = add int %reg422, 1		; <int>	[#uses=2]
	%cond1038 = setle int %reg423, 2		; <bool>	[#uses=1]
	br bool %cond1038, label %bb25, label %bb26

bb26:					;[#uses=3]
	%cast1145 = cast sbyte * %reg123 to %treeptr		; <%treeptr>	[#uses=1]
	call %icstruct * (%icstruct *, %bodyptr, %treeptr) * %intcoord( %icstruct * %xqic, %bodyptr %cast1144, %treeptr %cast1145 )		; <%icstruct *>:0	[#uses=0]
	%cast1146 = cast %icstruct * %xqic to uint *		; <uint *>	[#uses=1]
	%reg317 = load uint * %cast1146		; <uint>	[#uses=1]
	%cast1147 = cast label %bb30 to uint *		; <uint *>	[#uses=1]
	%cast1148 = cast long -2976 to uint *		; <uint *>	[#uses=1]
	%reg1039 = add uint * %cast1147, %cast1148		; <uint *>	[#uses=1]
	store uint %reg317, uint * %reg1039
	%cast1149 = cast ulong 4 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg1040 = add %icstruct * %xqic, %cast1149		; <%icstruct *>	[#uses=1]
	%cast1150 = cast %icstruct * %reg1040 to uint *		; <uint *>	[#uses=1]
	%reg318 = load uint * %cast1150		; <uint>	[#uses=1]
	%cast1151 = cast label %bb30 to uint *		; <uint *>	[#uses=1]
	%cast1152 = cast long -2972 to uint *		; <uint *>	[#uses=1]
	%reg1041 = add uint * %cast1151, %cast1152		; <uint *>	[#uses=1]
	store uint %reg318, uint * %reg1041
	%cast1153 = cast ulong 8 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg1042 = add %icstruct * %xqic, %cast1153		; <%icstruct *>	[#uses=1]
	%cast1154 = cast %icstruct * %reg1042 to uint *		; <uint *>	[#uses=1]
	%reg319 = load uint * %cast1154		; <uint>	[#uses=1]
	%cast1155 = cast label %bb30 to uint *		; <uint *>	[#uses=1]
	%cast1156 = cast long -2968 to uint *		; <uint *>	[#uses=1]
	%reg1043 = add uint * %cast1155, %cast1156		; <uint *>	[#uses=1]
	store uint %reg319, uint * %reg1043
	%eptr1807 = getelementptr %icstruct * %xqic, ubyte 1		; <short *>	[#uses=1]
	%cast1158 = cast short * %eptr1807 to uint *		; <uint *>	[#uses=1]
	%reg320 = load uint * %cast1158		; <uint>	[#uses=1]
	%cast1159 = cast label %bb30 to uint *		; <uint *>	[#uses=1]
	%cast1160 = cast long -2964 to uint *		; <uint *>	[#uses=1]
	%reg1045 = add uint * %cast1159, %cast1160		; <uint *>	[#uses=1]
	store uint %reg320, uint * %reg1045
	%cast1161 = cast label %bb30 to ulong *		; <ulong *>	[#uses=1]
	%cast1162 = cast long -2976 to ulong *		; <ulong *>	[#uses=1]
	%reg321 = add ulong * %cast1161, %cast1162		; <ulong *>	[#uses=1]
	%reg323 = call %iproc %old_subindex( ulong * %reg321, uint 536870912 )		; <int>	[#uses=1]
	%reg324 = shl int %reg323, ubyte 3		; <int>	[#uses=1]
	%cast1163 = cast %icstruct * %xqic to uint *		; <uint *>	[#uses=1]
	%reg325 = load uint * %cast1163		; <uint>	[#uses=1]
	%cast1164 = cast label %bb30 to uint *		; <uint *>	[#uses=1]
	%cast1165 = cast long -2992 to uint *		; <uint *>	[#uses=1]
	%reg1046 = add uint * %cast1164, %cast1165		; <uint *>	[#uses=1]
	store uint %reg325, uint * %reg1046
	%cast1166 = cast ulong 4 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg1047 = add %icstruct * %xqic, %cast1166		; <%icstruct *>	[#uses=1]
	%cast1167 = cast %icstruct * %reg1047 to uint *		; <uint *>	[#uses=1]
	%reg326 = load uint * %cast1167		; <uint>	[#uses=1]
	%cast1168 = cast label %bb30 to uint *		; <uint *>	[#uses=1]
	%cast1169 = cast long -2988 to uint *		; <uint *>	[#uses=1]
	%reg1048 = add uint * %cast1168, %cast1169		; <uint *>	[#uses=1]
	store uint %reg326, uint * %reg1048
	%cast1170 = cast ulong 8 to %icstruct *		; <%icstruct *>	[#uses=1]
	%reg1049 = add %icstruct * %xqic, %cast1170		; <%icstruct *>	[#uses=1]
	%cast1171 = cast %icstruct * %reg1049 to uint *		; <uint *>	[#uses=1]
	%reg327 = load uint * %cast1171		; <uint>	[#uses=1]
	%cast1172 = cast label %bb30 to uint *		; <uint *>	[#uses=1]
	%cast1173 = cast long -2984 to uint *		; <uint *>	[#uses=1]
	%reg1050 = add uint * %cast1172, %cast1173		; <uint *>	[#uses=1]
	store uint %reg327, uint * %reg1050
	%eptr1808 = getelementptr %icstruct * %xqic, ubyte 1		; <short *>	[#uses=1]
	%cast1175 = cast short * %eptr1808 to uint *		; <uint *>	[#uses=1]
	%reg328 = load uint * %cast1175		; <uint>	[#uses=1]
	%cast1176 = cast label %bb30 to uint *		; <uint *>	[#uses=1]
	%cast1177 = cast long -2980 to uint *		; <uint *>	[#uses=1]
	%reg1052 = add uint * %cast1176, %cast1177		; <uint *>	[#uses=1]
	store uint %reg328, uint * %reg1052
	%cast1178 = cast label %bb30 to ulong *		; <ulong *>	[#uses=1]
	%cast1179 = cast long -2992 to ulong *		; <ulong *>	[#uses=1]
	%reg329 = add ulong * %cast1178, %cast1179		; <ulong *>	[#uses=1]
	%reg331 = call %iproc %old_subindex( ulong * %reg329, uint 268435456 )		; <int>	[#uses=1]
	%reg424 = add int %reg324, %reg331		; <int>	[#uses=1]
	%reg425 = div int %reg424, %reg119		; <int>	[#uses=3]
	%cast1181 = cast int %reg425 to uint		; <uint>	[#uses=1]
	%cast1180 = cast int %reg425 to uint		; <uint>	[#uses=1]
	%reg333 = shl uint %cast1180, ubyte 2		; <uint>	[#uses=1]
	%cast334 = cast uint %reg333 to int *		; <int *>	[#uses=1]
	%reg345 = add int * %cast1003, %cast334		; <int *>	[#uses=2]
	%reg353 = load int * %reg345		; <int>	[#uses=1]
	%reg354 = add int %reg353, 1		; <int>	[#uses=1]
	store int %reg354, int * %reg345
	%reg356 = shl uint %cast1181, ubyte 3		; <uint>	[#uses=1]
	%cast357 = cast uint %reg356 to %bodyptr *		; <%bodyptr *>	[#uses=1]
	%reg361 = add %bodyptr * %cast1004, %cast357		; <%bodyptr *>	[#uses=2]
	%reg362 = load %bodyptr * %reg361		; <%bodyptr>	[#uses=1]
	%cast1182 = cast ulong 136 to %bodyptr *		; <%bodyptr *>	[#uses=1]
	%reg1053 = add %bodyptr * %cast1183, %cast1182		; <%bodyptr *>	[#uses=1]
	store %bodyptr %reg362, %bodyptr * %reg1053
	%cast1491 = cast %bodyptr * %reg361 to ulong * *		; <ulong * *>	[#uses=1]
	store ulong * %reg419, ulong * * %cast1491
	%cast1184 = cast ulong 40 to int *		; <int *>	[#uses=1]
	%reg1054 = add int * %cast1185, %cast1184		; <int *>	[#uses=1]
	store int %reg425, int * %reg1054
	%cast1186 = cast ulong 128 to ulong * *		; <ulong * *>	[#uses=1]
	%reg1055 = add ulong * * %cast1187, %cast1186		; <ulong * *>	[#uses=1]
	%reg426 = load ulong * * %reg1055		; <ulong *>	[#uses=2]
	%cond1056 = setne ulong * %reg426, null		; <bool>	[#uses=1]
	br bool %cond1056, label %bb22, label %bb27

bb27:					;[#uses=3]
	%reg397 = load int * %NumNodes		; <int>	[#uses=1]
	%cond1057 = setge int 0, %reg397		; <bool>	[#uses=1]
	br bool %cond1057, label %bb29, label %bb28

bb28:					;[#uses=3]
	%reg428 = phi int [ %reg429, %bb28 ], [ 0, %bb27 ]		; <int>	[#uses=4]
	%cast1191 = cast int %reg428 to uint		; <uint>	[#uses=1]
	%cast1189 = cast int %reg428 to uint		; <uint>	[#uses=1]
	%reg373 = shl uint %cast1189, ubyte 2		; <uint>	[#uses=1]
	%cast374 = cast uint %reg373 to int *		; <int *>	[#uses=1]
	%reg378 = add int * %cast1003, %cast374		; <int *>	[#uses=1]
	%reg379 = load int * %reg378		; <int>	[#uses=1]
	%cast1190 = cast [20 x sbyte] * %__intern_LC2 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast1190, int %reg428, int %reg379 )		; <int>:2	[#uses=0]
	%reg381 = shl uint %cast1191, ubyte 3		; <uint>	[#uses=2]
	%reg382 = add uint %reg381, 552		; <uint>	[#uses=1]
	%cast383 = cast uint %reg382 to sbyte *		; <sbyte *>	[#uses=1]
	%reg385 = add sbyte * %reg123, %cast383		; <sbyte *>	[#uses=1]
	%cast1192 = cast sbyte * %reg385 to %bodyptr *		; <%bodyptr *>	[#uses=1]
	%cast388 = cast uint %reg381 to %bodyptr *		; <%bodyptr *>	[#uses=1]
	%reg392 = add %bodyptr * %cast1004, %cast388		; <%bodyptr *>	[#uses=1]
	%reg393 = load %bodyptr * %reg392		; <%bodyptr>	[#uses=1]
	store %bodyptr %reg393, %bodyptr * %cast1192
	%reg429 = add int %reg428, 1		; <int>	[#uses=2]
	%reg370 = load int * %NumNodes		; <int>	[#uses=1]
	%cond1058 = setlt int %reg429, %reg370		; <bool>	[#uses=1]
	br bool %cond1058, label %bb28, label %bb29

bb29:					;[#uses=4]
	%cond1059 = setge long 0, 10		; <bool>	[#uses=1]
	br bool %cond1059, label %bb32, label %bb30

bb30:					;[#uses=12]
	%reg431 = phi int [ %reg434, %bb31 ], [ 0, %bb29 ]		; <int>	[#uses=2]
	%reg432 = phi double [ %reg433, %bb31 ], [ 0.000000, %bb29 ]		; <double>	[#uses=1]
	%cast1194 = cast sbyte * %reg123 to %treeptr		; <%treeptr>	[#uses=1]
	call void (%treeptr, int) * %stepsystem( %treeptr %cast1194, int %reg431 )
	%reg433 = add double %reg432, 0.012500		; <double>	[#uses=2]
	%reg434 = add int %reg431, 1		; <int>	[#uses=2]
	%cast1196 = cast double %reg433 to long		; <long>	[#uses=1]
	%cast1197 = cast double 2.001250 to long		; <long>	[#uses=1]
	%cond1060 = setlt long %cast1196, %cast1197		; <bool>	[#uses=1]
	br bool %cond1060, label %bb31, label %bb32

bb31:					;[#uses=3]
	%cond1061 = setlt int %reg434, 10		; <bool>	[#uses=1]
	br bool %cond1061, label %bb30, label %bb32

bb32:					;[#uses=3]
	%cast1199 = cast sbyte * %reg123 to %treeptr		; <%treeptr>	[#uses=1]
	ret %treeptr %cast1199

bb33:					;[#uses=0]
	%cast1200 = cast ulong 42 to %treeptr		; <%treeptr>	[#uses=1]
	ret %treeptr %cast1200
end

%bodyptr "testdata"()
begin
bb0:					;[#uses=0]
	%cmr = alloca %vector		; <%vector *>	[#uses=0]
	%cmv = alloca %vector		; <%vector *>	[#uses=0]
	br label %bb1

bb1:					;[#uses=1]
	%cast1811 = cast ulong 99 to uint		; <uint>	[#uses=1]
	%cast1813 = cast [22 x sbyte] * %__intern_LC5 to sbyte *		; <sbyte *>	[#uses=1]
	call int (sbyte *, ...) * %printf( sbyte * %cast1813, uint %cast1811 )		; <int>:0	[#uses=0]
	%cast1812 = cast ulong 0 to uint		; <uint>	[#uses=1]
	call %proc %exit( uint %cast1812 )
	%cast1814 = cast ulong 42 to %bodyptr		; <%bodyptr>	[#uses=1]
	ret %bodyptr %cast1814
end
