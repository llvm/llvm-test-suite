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
	%double = type double
	%float = type float
	%fpos_t = type int
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
%NumNodes = uninitialized global int		; <int *>	[#uses=0]
%root = uninitialized global %nodeptr		; <%nodeptr *>	[#uses=0]
%rmin = uninitialized global %vector		; <%vector *>	[#uses=0]
%rsize = uninitialized global double		; <double *>	[#uses=0]
%nbody = uninitialized global int		; <int *>	[#uses=0]
%__intern_LC0 = global double 0.250000		; <double *>	[#uses=0]
global double 0.250000		; <double *>:0	[#uses=0]
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

declare short "subdivp"(%nodeptr, double, double, %hgsptr)

%hgsptr "walksub"(%hgsptr %StructReturn, %nodeptr %p, double %dsq, double %tolsq, %hgsptr %hg, int %level)
begin
bb0:					;[#uses=0]
	%tmp = alloca [8 x %nodeptr]		; <[8 x %nodeptr] *>	[#uses=0]
	br label %bb1

bb1:					;[#uses=1]
	%reg116 = load %hgsptr %hg, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast116 = cast %bodyptr %reg116 to ulong		; <ulong>	[#uses=1]
	%cast1066 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast1067 = cast long -144 to ulong *		; <ulong *>	[#uses=1]
	%reg1001 = add ulong * %cast1066, %cast1067		; <ulong *>	[#uses=1]
	store ulong %cast116, ulong * %reg1001
	%eptr1202 = getelementptr %hgsptr %hg, ubyte 1		; <%vector *>	[#uses=1]
	%cast1069 = cast %vector * %eptr1202 to ulong *		; <ulong *>	[#uses=1]
	%reg117 = load ulong * %cast1069		; <ulong>	[#uses=1]
	%cast1070 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast1071 = cast long -136 to ulong *		; <ulong *>	[#uses=1]
	%reg1003 = add ulong * %cast1070, %cast1071		; <ulong *>	[#uses=1]
	store ulong %reg117, ulong * %reg1003
	%cast1072 = cast ulong 16 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg1004 = add %hgsptr %hg, %cast1072		; <%hgsptr>	[#uses=1]
	%reg118 = load %hgsptr %reg1004, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast118 = cast %bodyptr %reg118 to ulong		; <ulong>	[#uses=1]
	%cast1074 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast1075 = cast long -128 to ulong *		; <ulong *>	[#uses=1]
	%reg1005 = add ulong * %cast1074, %cast1075		; <ulong *>	[#uses=1]
	store ulong %cast118, ulong * %reg1005
	%cast1076 = cast ulong 24 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg1006 = add %hgsptr %hg, %cast1076		; <%hgsptr>	[#uses=1]
	%reg119 = load %hgsptr %reg1006, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast119 = cast %bodyptr %reg119 to ulong		; <ulong>	[#uses=1]
	%cast1078 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast1079 = cast long -120 to ulong *		; <ulong *>	[#uses=1]
	%reg1007 = add ulong * %cast1078, %cast1079		; <ulong *>	[#uses=1]
	store ulong %cast119, ulong * %reg1007
	%reg120 = load %hgsptr %hg, ubyte 2		; <double>	[#uses=1]
	%cast120 = cast double %reg120 to ulong		; <ulong>	[#uses=1]
	%cast1082 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast1083 = cast long -112 to ulong *		; <ulong *>	[#uses=1]
	%reg1009 = add ulong * %cast1082, %cast1083		; <ulong *>	[#uses=1]
	store ulong %cast120, ulong * %reg1009
	%eptr1208 = getelementptr %hgsptr %hg, ubyte 3		; <%vector *>	[#uses=1]
	%cast1085 = cast %vector * %eptr1208 to ulong *		; <ulong *>	[#uses=1]
	%reg121 = load ulong * %cast1085		; <ulong>	[#uses=1]
	%cast1086 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast1087 = cast long -104 to ulong *		; <ulong *>	[#uses=1]
	%reg1011 = add ulong * %cast1086, %cast1087		; <ulong *>	[#uses=1]
	store ulong %reg121, ulong * %reg1011
	%cast1088 = cast ulong 48 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg1012 = add %hgsptr %hg, %cast1088		; <%hgsptr>	[#uses=1]
	%reg122 = load %hgsptr %reg1012, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast122 = cast %bodyptr %reg122 to ulong		; <ulong>	[#uses=1]
	%cast1090 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast1091 = cast long -96 to ulong *		; <ulong *>	[#uses=1]
	%reg1013 = add ulong * %cast1090, %cast1091		; <ulong *>	[#uses=1]
	store ulong %cast122, ulong * %reg1013
	%cast1092 = cast ulong 56 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg1014 = add %hgsptr %hg, %cast1092		; <%hgsptr>	[#uses=1]
	%reg123 = load %hgsptr %reg1014, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast123 = cast %bodyptr %reg123 to ulong		; <ulong>	[#uses=1]
	%cast1094 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast1095 = cast long -88 to ulong *		; <ulong *>	[#uses=1]
	%reg1015 = add ulong * %cast1094, %cast1095		; <ulong *>	[#uses=1]
	store ulong %cast123, ulong * %reg1015
	%cast1096 = cast ulong 42 to %hgsptr		; <%hgsptr>	[#uses=1]
	%cast1097 = cast long -144 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg124 = add %hgsptr %cast1096, %cast1097		; <%hgsptr>	[#uses=1]
	%reg125 = call short (%nodeptr, double, double, %hgsptr) * %subdivp( %nodeptr %p, double %dsq, double %tolsq, %hgsptr %reg124 )		; <short>	[#uses=1]
	%cond1016 = seteq short %reg125, 0		; <bool>	[#uses=1]
	br bool %cond1016, label %bb7, label %bb2

bb2:					;[#uses=2]
	%cond1017 = setgt long 0, 7		; <bool>	[#uses=1]
	br bool %cond1017, label %bb9, label %bb3

bb3:					;[#uses=2]
	%reg162 = phi int [ %reg163, %bb5 ], [ 0, %bb2 ]		; <int>	[#uses=2]
	%cast1098 = cast int %reg162 to uint		; <uint>	[#uses=1]
	%reg127 = shl uint %cast1098, ubyte 3		; <uint>	[#uses=1]
	%reg128 = add uint %reg127, 48		; <uint>	[#uses=1]
	%cast129 = cast uint %reg128 to %nodeptr		; <%nodeptr>	[#uses=1]
	%reg131 = add %nodeptr %p, %cast129		; <%nodeptr>	[#uses=1]
	%cast1099 = cast %nodeptr %reg131 to %nodeptr *		; <%nodeptr *>	[#uses=1]
	%reg115 = load %nodeptr * %cast1099		; <%nodeptr>	[#uses=2]
	%cond1018 = seteq %nodeptr %reg115, null		; <bool>	[#uses=1]
	br bool %cond1018, label %bb5, label %bb4

bb4:					;[#uses=1]
	%reg132 = load %hgsptr %hg, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast132 = cast %bodyptr %reg132 to ulong		; <ulong>	[#uses=1]
	%cast1102 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast1103 = cast long -208 to ulong *		; <ulong *>	[#uses=1]
	%reg1019 = add ulong * %cast1102, %cast1103		; <ulong *>	[#uses=1]
	store ulong %cast132, ulong * %reg1019
	%eptr1215 = getelementptr %hgsptr %hg, ubyte 1		; <%vector *>	[#uses=1]
	%cast1105 = cast %vector * %eptr1215 to ulong *		; <ulong *>	[#uses=1]
	%reg133 = load ulong * %cast1105		; <ulong>	[#uses=1]
	%cast1106 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast1107 = cast long -200 to ulong *		; <ulong *>	[#uses=1]
	%reg1021 = add ulong * %cast1106, %cast1107		; <ulong *>	[#uses=1]
	store ulong %reg133, ulong * %reg1021
	%cast1108 = cast ulong 16 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg1022 = add %hgsptr %hg, %cast1108		; <%hgsptr>	[#uses=1]
	%reg134 = load %hgsptr %reg1022, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast134 = cast %bodyptr %reg134 to ulong		; <ulong>	[#uses=1]
	%cast1110 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast1111 = cast long -192 to ulong *		; <ulong *>	[#uses=1]
	%reg1023 = add ulong * %cast1110, %cast1111		; <ulong *>	[#uses=1]
	store ulong %cast134, ulong * %reg1023
	%cast1112 = cast ulong 24 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg1024 = add %hgsptr %hg, %cast1112		; <%hgsptr>	[#uses=1]
	%reg135 = load %hgsptr %reg1024, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast135 = cast %bodyptr %reg135 to ulong		; <ulong>	[#uses=1]
	%cast1114 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast1115 = cast long -184 to ulong *		; <ulong *>	[#uses=1]
	%reg1025 = add ulong * %cast1114, %cast1115		; <ulong *>	[#uses=1]
	store ulong %cast135, ulong * %reg1025
	%reg136 = load %hgsptr %hg, ubyte 2		; <double>	[#uses=1]
	%cast136 = cast double %reg136 to ulong		; <ulong>	[#uses=1]
	%cast1118 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast1119 = cast long -176 to ulong *		; <ulong *>	[#uses=1]
	%reg1027 = add ulong * %cast1118, %cast1119		; <ulong *>	[#uses=1]
	store ulong %cast136, ulong * %reg1027
	%eptr1221 = getelementptr %hgsptr %hg, ubyte 3		; <%vector *>	[#uses=1]
	%cast1121 = cast %vector * %eptr1221 to ulong *		; <ulong *>	[#uses=1]
	%reg137 = load ulong * %cast1121		; <ulong>	[#uses=1]
	%cast1122 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast1123 = cast long -168 to ulong *		; <ulong *>	[#uses=1]
	%reg1029 = add ulong * %cast1122, %cast1123		; <ulong *>	[#uses=1]
	store ulong %reg137, ulong * %reg1029
	%cast1124 = cast ulong 48 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg1030 = add %hgsptr %hg, %cast1124		; <%hgsptr>	[#uses=1]
	%reg138 = load %hgsptr %reg1030, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast138 = cast %bodyptr %reg138 to ulong		; <ulong>	[#uses=1]
	%cast1126 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast1127 = cast long -160 to ulong *		; <ulong *>	[#uses=1]
	%reg1031 = add ulong * %cast1126, %cast1127		; <ulong *>	[#uses=1]
	store ulong %cast138, ulong * %reg1031
	%cast1128 = cast ulong 56 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg1032 = add %hgsptr %hg, %cast1128		; <%hgsptr>	[#uses=1]
	%reg139 = load %hgsptr %reg1032, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast139 = cast %bodyptr %reg139 to ulong		; <ulong>	[#uses=1]
	%cast1130 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast1131 = cast long -152 to ulong *		; <ulong *>	[#uses=1]
	%reg1033 = add ulong * %cast1130, %cast1131		; <ulong *>	[#uses=1]
	store ulong %cast139, ulong * %reg1033
	%cast1132 = cast ulong 42 to %hgsptr		; <%hgsptr>	[#uses=1]
	%cast1133 = cast long -208 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg140 = add %hgsptr %cast1132, %cast1133		; <%hgsptr>	[#uses=1]
	%reg142 = mul double %dsq, 0.250000		; <double>	[#uses=1]
	%reg143 = add int %level, 1		; <int>	[#uses=1]
	call %hgsptr (%hgsptr, %nodeptr, double, double, %hgsptr, int) * %walksub( %hgsptr %hg, %nodeptr %reg115, double %reg142, double %tolsq, %hgsptr %reg140, int %reg143 )		; <%hgsptr>:0	[#uses=0]
	br label %bb5

bb5:					;[#uses=3]
	%reg163 = add int %reg162, 1		; <int>	[#uses=2]
	%cond1034 = setle int %reg163, 7		; <bool>	[#uses=1]
	br bool %cond1034, label %bb3, label %bb6

bb6:					;[#uses=1]
	br label %bb9

bb7:					;[#uses=1]
	%reg144 = load %hgsptr %hg, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast144 = cast %bodyptr %reg144 to %nodeptr		; <%nodeptr>	[#uses=1]
	%cond1035 = seteq %nodeptr %p, %cast144		; <bool>	[#uses=1]
	br bool %cond1035, label %bb9, label %bb8

bb8:					;[#uses=1]
	%reg145 = load %hgsptr %hg, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast145 = cast %bodyptr %reg145 to ulong		; <ulong>	[#uses=1]
	%cast1137 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast1138 = cast long -272 to ulong *		; <ulong *>	[#uses=1]
	%reg1036 = add ulong * %cast1137, %cast1138		; <ulong *>	[#uses=1]
	store ulong %cast145, ulong * %reg1036
	%eptr1230 = getelementptr %hgsptr %hg, ubyte 1		; <%vector *>	[#uses=1]
	%cast1140 = cast %vector * %eptr1230 to ulong *		; <ulong *>	[#uses=1]
	%reg146 = load ulong * %cast1140		; <ulong>	[#uses=1]
	%cast1141 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast1142 = cast long -264 to ulong *		; <ulong *>	[#uses=1]
	%reg1038 = add ulong * %cast1141, %cast1142		; <ulong *>	[#uses=1]
	store ulong %reg146, ulong * %reg1038
	%cast1143 = cast ulong 16 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg1039 = add %hgsptr %hg, %cast1143		; <%hgsptr>	[#uses=1]
	%reg147 = load %hgsptr %reg1039, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast147 = cast %bodyptr %reg147 to ulong		; <ulong>	[#uses=1]
	%cast1145 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast1146 = cast long -256 to ulong *		; <ulong *>	[#uses=1]
	%reg1040 = add ulong * %cast1145, %cast1146		; <ulong *>	[#uses=1]
	store ulong %cast147, ulong * %reg1040
	%cast1147 = cast ulong 24 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg1041 = add %hgsptr %hg, %cast1147		; <%hgsptr>	[#uses=1]
	%reg148 = load %hgsptr %reg1041, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast148 = cast %bodyptr %reg148 to ulong		; <ulong>	[#uses=1]
	%cast1149 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast1150 = cast long -248 to ulong *		; <ulong *>	[#uses=1]
	%reg1042 = add ulong * %cast1149, %cast1150		; <ulong *>	[#uses=1]
	store ulong %cast148, ulong * %reg1042
	%reg149 = load %hgsptr %hg, ubyte 2		; <double>	[#uses=1]
	%cast149 = cast double %reg149 to ulong		; <ulong>	[#uses=1]
	%cast1153 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast1154 = cast long -240 to ulong *		; <ulong *>	[#uses=1]
	%reg1044 = add ulong * %cast1153, %cast1154		; <ulong *>	[#uses=1]
	store ulong %cast149, ulong * %reg1044
	%eptr1236 = getelementptr %hgsptr %hg, ubyte 3		; <%vector *>	[#uses=1]
	%cast1156 = cast %vector * %eptr1236 to ulong *		; <ulong *>	[#uses=1]
	%reg150 = load ulong * %cast1156		; <ulong>	[#uses=1]
	%cast1157 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast1158 = cast long -232 to ulong *		; <ulong *>	[#uses=1]
	%reg1046 = add ulong * %cast1157, %cast1158		; <ulong *>	[#uses=1]
	store ulong %reg150, ulong * %reg1046
	%cast1159 = cast ulong 48 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg1047 = add %hgsptr %hg, %cast1159		; <%hgsptr>	[#uses=1]
	%reg151 = load %hgsptr %reg1047, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast151 = cast %bodyptr %reg151 to ulong		; <ulong>	[#uses=1]
	%cast1161 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast1162 = cast long -224 to ulong *		; <ulong *>	[#uses=1]
	%reg1048 = add ulong * %cast1161, %cast1162		; <ulong *>	[#uses=1]
	store ulong %cast151, ulong * %reg1048
	%cast1163 = cast ulong 56 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg1049 = add %hgsptr %hg, %cast1163		; <%hgsptr>	[#uses=1]
	%reg152 = load %hgsptr %reg1049, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast152 = cast %bodyptr %reg152 to ulong		; <ulong>	[#uses=1]
	%cast1165 = cast ulong 42 to ulong *		; <ulong *>	[#uses=1]
	%cast1166 = cast long -216 to ulong *		; <ulong *>	[#uses=1]
	%reg1050 = add ulong * %cast1165, %cast1166		; <ulong *>	[#uses=1]
	store ulong %cast152, ulong * %reg1050
	%cast1167 = cast ulong 42 to %hgsptr		; <%hgsptr>	[#uses=1]
	%cast1168 = cast long -272 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg153 = add %hgsptr %cast1167, %cast1168		; <%hgsptr>	[#uses=1]
	call %hgsptr (%hgsptr, %nodeptr, %hgsptr) * %gravsub( %hgsptr %hg, %nodeptr %p, %hgsptr %reg153 )		; <%hgsptr>:1	[#uses=0]
	br label %bb9

bb9:					;[#uses=4]
	%reg154 = load %hgsptr %hg, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast154 = cast %bodyptr %reg154 to ulong		; <ulong>	[#uses=1]
	%cast1170 = cast %hgsptr %StructReturn to ulong *		; <ulong *>	[#uses=1]
	store ulong %cast154, ulong * %cast1170
	%eptr1243 = getelementptr %hgsptr %hg, ubyte 1		; <%vector *>	[#uses=1]
	%cast1172 = cast %vector * %eptr1243 to ulong *		; <ulong *>	[#uses=1]
	%reg155 = load ulong * %cast1172		; <ulong>	[#uses=1]
	%eptr1244 = getelementptr %hgsptr %StructReturn, ubyte 1		; <%vector *>	[#uses=1]
	%cast1174 = cast %vector * %eptr1244 to ulong *		; <ulong *>	[#uses=1]
	store ulong %reg155, ulong * %cast1174
	%cast1175 = cast ulong 16 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg1053 = add %hgsptr %hg, %cast1175		; <%hgsptr>	[#uses=1]
	%reg156 = load %hgsptr %reg1053, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast156 = cast %bodyptr %reg156 to ulong		; <ulong>	[#uses=1]
	%cast1177 = cast ulong 16 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg1054 = add %hgsptr %StructReturn, %cast1177		; <%hgsptr>	[#uses=1]
	%cast1178 = cast %hgsptr %reg1054 to ulong *		; <ulong *>	[#uses=1]
	store ulong %cast156, ulong * %cast1178
	%cast1179 = cast ulong 24 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg1055 = add %hgsptr %hg, %cast1179		; <%hgsptr>	[#uses=1]
	%reg157 = load %hgsptr %reg1055, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast157 = cast %bodyptr %reg157 to ulong		; <ulong>	[#uses=1]
	%cast1181 = cast ulong 24 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg1056 = add %hgsptr %StructReturn, %cast1181		; <%hgsptr>	[#uses=1]
	%cast1182 = cast %hgsptr %reg1056 to ulong *		; <ulong *>	[#uses=1]
	store ulong %cast157, ulong * %cast1182
	%reg158 = load %hgsptr %hg, ubyte 2		; <double>	[#uses=1]
	store double %reg158, %hgsptr %StructReturn, ubyte 2
	%eptr1252 = getelementptr %hgsptr %hg, ubyte 3		; <%vector *>	[#uses=1]
	%cast1188 = cast %vector * %eptr1252 to ulong *		; <ulong *>	[#uses=1]
	%reg159 = load ulong * %cast1188		; <ulong>	[#uses=1]
	%eptr1253 = getelementptr %hgsptr %StructReturn, ubyte 3		; <%vector *>	[#uses=1]
	%cast1190 = cast %vector * %eptr1253 to ulong *		; <ulong *>	[#uses=1]
	store ulong %reg159, ulong * %cast1190
	%cast1191 = cast ulong 48 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg1061 = add %hgsptr %hg, %cast1191		; <%hgsptr>	[#uses=1]
	%reg160 = load %hgsptr %reg1061, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast160 = cast %bodyptr %reg160 to ulong		; <ulong>	[#uses=1]
	%cast1193 = cast ulong 48 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg1062 = add %hgsptr %StructReturn, %cast1193		; <%hgsptr>	[#uses=1]
	%cast1194 = cast %hgsptr %reg1062 to ulong *		; <ulong *>	[#uses=1]
	store ulong %cast160, ulong * %cast1194
	%cast1195 = cast ulong 56 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg1063 = add %hgsptr %hg, %cast1195		; <%hgsptr>	[#uses=1]
	%reg161 = load %hgsptr %reg1063, ubyte 0		; <%bodyptr>	[#uses=1]
	%cast161 = cast %bodyptr %reg161 to ulong		; <ulong>	[#uses=1]
	%cast1197 = cast ulong 56 to %hgsptr		; <%hgsptr>	[#uses=1]
	%reg1064 = add %hgsptr %StructReturn, %cast1197		; <%hgsptr>	[#uses=1]
	%cast1198 = cast %hgsptr %reg1064 to ulong *		; <ulong *>	[#uses=1]
	store ulong %cast161, ulong * %cast1198
	ret %hgsptr %StructReturn

bb10:					;[#uses=0]
	%cast1199 = cast ulong 42 to %hgsptr		; <%hgsptr>	[#uses=1]
	ret %hgsptr %cast1199
end

declare %hgsptr "gravsub"(%hgsptr, %nodeptr, %hgsptr)

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
