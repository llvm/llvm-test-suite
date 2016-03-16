/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     FUNC_CALL = 258,
     NAME = 259,
     REGEXP = 260,
     ERROR = 261,
     NUMBER = 262,
     YSTRING = 263,
     RELOP = 264,
     APPEND_OP = 265,
     ASSIGNOP = 266,
     MATCHOP = 267,
     NEWLINE = 268,
     CONCAT_OP = 269,
     LEX_BEGIN = 270,
     LEX_END = 271,
     LEX_IF = 272,
     LEX_ELSE = 273,
     LEX_RETURN = 274,
     LEX_DELETE = 275,
     LEX_WHILE = 276,
     LEX_DO = 277,
     LEX_FOR = 278,
     LEX_BREAK = 279,
     LEX_CONTINUE = 280,
     LEX_PRINT = 281,
     LEX_PRINTF = 282,
     LEX_NEXT = 283,
     LEX_EXIT = 284,
     LEX_FUNCTION = 285,
     LEX_GETLINE = 286,
     LEX_IN = 287,
     LEX_AND = 288,
     LEX_OR = 289,
     INCREMENT = 290,
     DECREMENT = 291,
     LEX_BUILTIN = 292,
     LEX_LENGTH = 293,
     UNARY = 294
   };
#endif
/* Tokens.  */
#define FUNC_CALL 258
#define NAME 259
#define REGEXP 260
#define ERROR 261
#define NUMBER 262
#define YSTRING 263
#define RELOP 264
#define APPEND_OP 265
#define ASSIGNOP 266
#define MATCHOP 267
#define NEWLINE 268
#define CONCAT_OP 269
#define LEX_BEGIN 270
#define LEX_END 271
#define LEX_IF 272
#define LEX_ELSE 273
#define LEX_RETURN 274
#define LEX_DELETE 275
#define LEX_WHILE 276
#define LEX_DO 277
#define LEX_FOR 278
#define LEX_BREAK 279
#define LEX_CONTINUE 280
#define LEX_PRINT 281
#define LEX_PRINTF 282
#define LEX_NEXT 283
#define LEX_EXIT 284
#define LEX_FUNCTION 285
#define LEX_GETLINE 286
#define LEX_IN 287
#define LEX_AND 288
#define LEX_OR 289
#define INCREMENT 290
#define DECREMENT 291
#define LEX_BUILTIN 292
#define LEX_LENGTH 293
#define UNARY 294




/* Copy the first part of user declarations.  */


#ifdef DEBUG
#define YYDEBUG 12
#endif

#include "gawk.h"

/*
 * This line is necessary since the Bison parser skeleton uses bcopy.
 * Systems without memcpy should use -DMEMCPY_MISSING, per the Makefile.
 * It should not hurt anything if Yacc is being used instead of Bison.
 */
#define bcopy(s,d,n)	memcpy((d),(s),(n))

extern void msg(char * message, ...);
extern struct re_pattern_buffer *mk_re_parse();

NODE *node();
NODE *lookup();
NODE *install();

static NODE *snode();
static NODE *mkrangenode();
static FILE *pathopen();
static NODE *make_for_loop();
static NODE *append_right();
static void func_install();
static NODE *make_param();
static int hashf();
static void pop_params();
static void pop_var();
static int yylex ();
static void yyerror(char * msg, ...);

static int want_regexp;		/* lexical scanning kludge */
static int want_assign;		/* lexical scanning kludge */
static int can_return;		/* lexical scanning kludge */
static int io_allowed = 1;	/* lexical scanning kludge */
static int lineno = 1;		/* for error msgs */
static char *lexptr;		/* pointer to next char during parsing */
static char *lexptr_begin;	/* keep track of where we were for error msgs */
static int curinfile = -1;	/* index into sourcefiles[] */
static int param_counter;

NODE *variables[HASHSIZE];

extern int errcount;
extern NODE *begin_block;
extern NODE *end_block;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE

{
	long lval;
	AWKNUM fval;
	NODE *nodeval;
	NODETYPE nodetypeval;
	char *sval;
	NODE *(*ptrval)();
}
/* Line 193 of yacc.c.  */

	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */


#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1912

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  155
/* YYNRULES -- Number of states.  */
#define YYNSTATES  298

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,     2,    52,    48,     2,     2,
      53,    54,    46,    44,    60,    45,     2,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    59,
      41,     2,    42,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,    43,    58,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     9,    12,    14,    17,    18,    22,
      23,    27,    30,    33,    36,    38,    41,    44,    46,    48,
      49,    57,    61,    63,    67,    68,    73,    77,    82,    84,
      87,    89,    92,    94,    97,   100,   103,   107,   109,   116,
     125,   134,   145,   155,   158,   161,   168,   173,   174,   178,
     182,   183,   188,   195,   198,   200,   202,   209,   219,   221,
     224,   225,   227,   228,   231,   232,   235,   238,   241,   242,
     244,   246,   250,   252,   255,   259,   260,   262,   263,   265,
     267,   271,   273,   276,   280,   284,   285,   287,   289,   293,
     295,   298,   302,   306,   307,   312,   318,   323,   327,   331,
     335,   339,   341,   344,   348,   352,   356,   360,   366,   368,
     371,   372,   377,   381,   385,   389,   391,   394,   398,   402,
     406,   412,   414,   417,   420,   424,   429,   434,   436,   441,
     444,   447,   450,   453,   455,   457,   459,   463,   467,   471,
     475,   479,   483,   486,   489,   490,   492,   494,   499,   502,
     505,   508,   510,   511,   513,   515
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      62,     0,    -1,    83,    63,    83,    -1,    64,    -1,    63,
      64,    -1,     1,    -1,    63,     1,    -1,    -1,    15,    65,
      74,    -1,    -1,    16,    66,    74,    -1,    15,    76,    -1,
      16,    76,    -1,    71,    74,    -1,    74,    -1,    71,    76,
      -1,    68,    70,    -1,     4,    -1,     3,    -1,    -1,    30,
      69,    67,    53,    86,   102,    83,    -1,   100,    75,   101,
      -1,    93,    -1,    93,   105,    93,    -1,    -1,    47,    73,
       5,    47,    -1,   100,   101,   103,    -1,   100,    75,   101,
     103,    -1,    77,    -1,    75,    77,    -1,     1,    -1,    75,
       1,    -1,    82,    -1,   104,    83,    -1,   104,    83,    -1,
     100,   101,    -1,   100,    75,   101,    -1,    81,    -1,    21,
      53,    93,   102,    83,    77,    -1,    22,    83,    77,    21,
      53,    93,   102,    83,    -1,    23,    53,     4,    32,     4,
     102,    83,    77,    -1,    23,    53,    88,   104,    93,   104,
      88,   102,    83,    77,    -1,    23,    53,    88,   104,   104,
      88,   102,    83,    77,    -1,    24,    76,    -1,    25,    76,
      -1,    80,    53,    92,   102,    85,    76,    -1,    80,    89,
      85,    76,    -1,    -1,    28,    78,    76,    -1,    29,    88,
      76,    -1,    -1,    19,    79,    88,    76,    -1,    20,     4,
      55,    92,    56,    76,    -1,    93,    76,    -1,    26,    -1,
      27,    -1,    17,    53,    93,   102,    83,    77,    -1,    17,
      53,    93,   102,    83,    77,    18,    83,    77,    -1,    13,
      -1,    82,    13,    -1,    -1,    82,    -1,    -1,    41,    97,
      -1,    -1,    42,    93,    -1,    10,    93,    -1,    43,    93,
      -1,    -1,    87,    -1,     4,    -1,    87,   105,     4,    -1,
       1,    -1,    87,     1,    -1,    87,   105,     1,    -1,    -1,
      93,    -1,    -1,    90,    -1,    95,    -1,    90,   105,    95,
      -1,     1,    -1,    90,     1,    -1,    90,     1,    95,    -1,
      90,   105,     1,    -1,    -1,    92,    -1,    93,    -1,    92,
     105,    93,    -1,     1,    -1,    92,     1,    -1,    92,     1,
      93,    -1,    92,   105,     1,    -1,    -1,    99,    11,    94,
      93,    -1,    53,    92,   102,    32,     4,    -1,    93,    43,
      31,    98,    -1,    31,    98,    84,    -1,    93,    33,    93,
      -1,    93,    34,    93,    -1,    93,    12,    93,    -1,    72,
      -1,    49,    72,    -1,    93,    32,     4,    -1,    93,     9,
      93,    -1,    93,    41,    93,    -1,    93,    42,    93,    -1,
      93,    39,    93,    40,    93,    -1,    97,    -1,    93,    93,
      -1,    -1,    99,    11,    96,    95,    -1,    95,    33,    95,
      -1,    95,    34,    95,    -1,    31,    98,    84,    -1,    72,
      -1,    49,    72,    -1,    95,    12,    95,    -1,    95,    32,
       4,    -1,    95,     9,    95,    -1,    95,    39,    95,    40,
      95,    -1,    97,    -1,    95,    95,    -1,    49,    97,    -1,
      53,    93,   102,    -1,    37,    53,    91,   102,    -1,    38,
      53,    91,   102,    -1,    38,    -1,     3,    53,    91,   102,
      -1,    35,    99,    -1,    36,    99,    -1,    99,    35,    -1,
      99,    36,    -1,    99,    -1,     7,    -1,     8,    -1,    97,
      51,    97,    -1,    97,    46,    97,    -1,    97,    47,    97,
      -1,    97,    48,    97,    -1,    97,    44,    97,    -1,    97,
      45,    97,    -1,    45,    97,    -1,    44,    97,    -1,    -1,
      99,    -1,     4,    -1,     4,    55,    92,    56,    -1,    52,
      97,    -1,    57,    83,    -1,    58,    83,    -1,    54,    -1,
      -1,   104,    -1,    59,    -1,    60,    83,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   136,   136,   141,   149,   165,   166,   170,   170,   186,
     186,   202,   208,   214,   216,   218,   220,   229,   231,   237,
     236,   248,   257,   259,   269,   268,   281,   286,   291,   293,
     301,   303,   308,   310,   316,   318,   320,   322,   324,   326,
     328,   333,   337,   342,   345,   348,   350,   353,   352,   356,
     359,   358,   362,   364,   369,   371,   376,   381,   388,   390,
     396,   397,   403,   404,   410,   411,   413,   415,   421,   422,
     427,   429,   431,   433,   435,   442,   443,   449,   450,   455,
     457,   463,   465,   467,   469,   475,   476,   481,   483,   489,
     491,   493,   495,   501,   500,   504,   506,   511,   520,   522,
     524,   526,   528,   530,   532,   534,   536,   538,   540,   542,
     548,   547,   551,   553,   555,   564,   566,   568,   570,   572,
     574,   576,   578,   583,   585,   587,   589,   591,   593,   597,
     599,   601,   603,   605,   607,   609,   613,   615,   617,   619,
     621,   623,   625,   627,   633,   634,   639,   641,   643,   648,
     652,   656,   659,   661,   665,   668
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FUNC_CALL", "NAME", "REGEXP", "ERROR",
  "NUMBER", "YSTRING", "RELOP", "APPEND_OP", "ASSIGNOP", "MATCHOP",
  "NEWLINE", "CONCAT_OP", "LEX_BEGIN", "LEX_END", "LEX_IF", "LEX_ELSE",
  "LEX_RETURN", "LEX_DELETE", "LEX_WHILE", "LEX_DO", "LEX_FOR",
  "LEX_BREAK", "LEX_CONTINUE", "LEX_PRINT", "LEX_PRINTF", "LEX_NEXT",
  "LEX_EXIT", "LEX_FUNCTION", "LEX_GETLINE", "LEX_IN", "LEX_AND", "LEX_OR",
  "INCREMENT", "DECREMENT", "LEX_BUILTIN", "LEX_LENGTH", "'?'", "':'",
  "'<'", "'>'", "'|'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UNARY",
  "'^'", "'$'", "'('", "')'", "'['", "']'", "'{'", "'}'", "';'", "','",
  "$accept", "start", "program", "rule", "@1", "@2", "func_name",
  "function_prologue", "@3", "function_body", "pattern", "regexp", "@4",
  "action", "statements", "statement_term", "statement", "@5", "@6",
  "print", "if_statement", "nls", "opt_nls", "input_redir", "output_redir",
  "opt_param_list", "param_list", "opt_exp", "opt_rexpression_list",
  "rexpression_list", "opt_expression_list", "expression_list", "exp",
  "@7", "rexp", "@8", "simp_exp", "opt_variable", "variable", "l_brace",
  "r_brace", "r_paren", "opt_semi", "semi", "comma", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,    63,
      58,    60,    62,   124,    43,    45,    42,    47,    37,    33,
     294,    94,    36,    40,    41,    91,    93,   123,   125,    59,
      44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    63,    63,    63,    63,    65,    64,    66,
      64,    64,    64,    64,    64,    64,    64,    67,    67,    69,
      68,    70,    71,    71,    73,    72,    74,    74,    75,    75,
      75,    75,    76,    76,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    78,    77,    77,
      79,    77,    77,    77,    80,    80,    81,    81,    82,    82,
      83,    83,    84,    84,    85,    85,    85,    85,    86,    86,
      87,    87,    87,    87,    87,    88,    88,    89,    89,    90,
      90,    90,    90,    90,    90,    91,    91,    92,    92,    92,
      92,    92,    92,    94,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      96,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    98,    98,    99,    99,    99,   100,
     101,   102,   103,   103,   104,   105
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     2,     1,     2,     0,     3,     0,
       3,     2,     2,     2,     1,     2,     2,     1,     1,     0,
       7,     3,     1,     3,     0,     4,     3,     4,     1,     2,
       1,     2,     1,     2,     2,     2,     3,     1,     6,     8,
       8,    10,     9,     2,     2,     6,     4,     0,     3,     3,
       0,     4,     6,     2,     1,     1,     6,     9,     1,     2,
       0,     1,     0,     2,     0,     2,     2,     2,     0,     1,
       1,     3,     1,     2,     3,     0,     1,     0,     1,     1,
       3,     1,     2,     3,     3,     0,     1,     1,     3,     1,
       2,     3,     3,     0,     4,     5,     4,     3,     3,     3,
       3,     1,     2,     3,     3,     3,     3,     5,     1,     2,
       0,     4,     3,     3,     3,     1,     2,     3,     3,     3,
       5,     1,     2,     2,     3,     4,     4,     1,     4,     2,
       2,     2,     2,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     2,     2,     0,     1,     1,     4,     2,     2,
       2,     1,     0,     1,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      60,    58,     0,    61,     0,     1,    59,     5,     0,   146,
     134,   135,     7,     9,    19,   144,     0,     0,     0,   127,
       0,     0,    24,     0,     0,     0,    60,     0,     3,     0,
       0,   101,    14,    22,   108,   133,     0,     0,     0,   154,
       0,    11,    32,    60,     0,    12,     0,    62,   145,   129,
     130,     0,     0,     0,     0,   143,   133,   142,     0,   102,
     123,   148,    89,     0,    87,   149,     6,     4,     2,    16,
       0,    13,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    60,   109,     0,     0,     0,     0,     0,     0,
       0,    93,   131,   132,    30,     0,    50,     0,     0,    60,
       0,     0,     0,    54,    55,    47,    75,    60,     0,    28,
       0,    37,     0,     0,   152,    60,     0,     0,    87,     0,
       8,    33,    10,    18,    17,     0,     0,    97,     0,     0,
       0,     0,    90,   151,     0,     0,   124,     0,   104,   100,
     103,    98,    99,     0,   105,   106,   144,   155,    23,   140,
     141,   137,   138,   139,   136,     0,     0,    75,     0,     0,
       0,    75,    43,    44,     0,     0,    76,   150,    31,    29,
     152,    81,   144,     0,     0,   115,    64,     0,    79,   121,
     133,    53,     0,    35,    26,   153,    34,   128,   147,     0,
      63,   125,   126,    25,    91,     0,    92,    88,    21,     0,
      96,    94,     0,     0,     0,     0,     0,   146,     0,    48,
      49,    27,    62,   116,     0,     0,     0,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,   122,   110,    36,
      72,    70,     0,     0,    95,   107,    60,    51,     0,    60,
       0,     0,     0,   114,    64,    66,    65,    67,    46,    83,
      84,    80,   119,   117,   118,   112,   113,     0,     0,    60,
      73,     0,     0,     0,     0,     0,     0,     0,    75,     0,
       0,   111,    20,    74,    71,    56,    52,    38,     0,    60,
      75,     0,    45,   120,    60,    60,     0,     0,    60,     0,
      39,    40,    60,     0,    57,     0,    42,    41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    27,    28,    40,    44,   125,    29,    46,    69,
      30,    31,    58,    32,   108,    41,   109,   164,   157,   110,
     111,     3,     4,   127,   218,   232,   233,   165,   176,   177,
     116,   117,    83,   155,   227,   258,    34,    47,    35,   113,
     114,   136,   184,   115,   135
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -154
static const yytype_int16 yypact[] =
{
      17,  -154,    22,    36,  1021,  -154,  -154,  -154,   -16,     0,
    -154,  -154,    18,    18,  -154,    15,    15,    15,   -14,    -2,
    1758,  1758,  -154,  1739,  1758,  1113,    17,   541,  -154,    14,
      41,  -154,  -154,   817,   143,    84,   613,  1093,  1113,  -154,
      14,  -154,    36,    17,    14,  -154,    25,    16,  -154,  -154,
    -154,  1093,  1093,  1758,  1626,    28,    71,    28,    78,  -154,
      28,  -154,  -154,     2,  1226,  -154,  -154,  -154,  -154,  -154,
     707,  -154,  -154,  1626,  1626,    83,  1626,  1626,  1626,  1626,
    1626,    68,    17,   301,  1626,  1758,  1758,  1758,  1758,  1758,
    1758,  -154,  -154,  -154,  -154,    39,  -154,    99,    63,    17,
      64,    18,    18,  -154,  -154,  -154,  1626,    17,   660,  -154,
     764,  -154,   921,   613,    55,    17,    80,     5,  1325,     8,
    -154,  -154,  -154,  -154,  -154,    65,  1758,  -154,    80,    80,
    1226,    75,  1626,  -154,   100,  1160,  -154,   660,  1812,  1797,
    -154,  1466,  1372,  1278,  1812,  1812,    15,  -154,  1325,   157,
     157,    28,    28,    28,    28,  1626,  1626,  1626,    88,  1626,
     864,  1673,  -154,  -154,    18,    18,  1325,  -154,  -154,  -154,
      55,  -154,    15,  1739,  1113,  -154,    10,     1,  1513,   143,
     113,  -154,   660,  -154,  -154,  -154,  -154,  -154,  -154,     9,
     143,  -154,  -154,  -154,  1325,   135,  -154,  1325,  -154,  1626,
    -154,  1325,  1226,    18,  1113,  1226,   123,   -15,    55,  -154,
    -154,  -154,    16,  -154,     2,  1626,  1626,  1626,    18,  1692,
    1179,  1692,  1692,   146,  1692,  1692,  1692,   940,  -154,  -154,
    -154,  -154,    80,    24,  -154,  1325,    17,  -154,    26,    17,
      94,   160,  1046,  -154,    10,  1325,  1325,  1325,  -154,  1513,
    -154,  1513,   783,  1859,  -154,  1607,  1560,  1419,  1692,    17,
    -154,    34,   864,    18,   864,  1626,    80,   974,  1626,    18,
    1692,  1513,  -154,  -154,  -154,   149,  -154,  -154,  1226,    17,
    1626,    80,  -154,  1513,    17,    17,   864,    80,    17,   864,
    -154,  -154,    17,   864,  -154,   864,  -154,  -154
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -154,  -154,  -154,   144,  -154,  -154,  -154,  -154,  -154,  -154,
    -154,   200,  -154,    61,   -55,    11,   224,  -154,  -154,  -154,
    -154,   362,   103,   -40,   -71,  -154,  -154,  -153,  -154,  -154,
      -6,   -20,    -4,  -154,   -84,  -154,   145,  -130,    73,    81,
    -101,   318,     7,   328,   -32
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -87
static const yytype_int16 yytable[] =
{
      33,    84,   219,   132,   203,    63,   132,   170,   208,   132,
     230,   -78,   183,   231,   -78,   137,   200,   241,   119,     9,
     215,    64,     5,    33,    45,   260,   178,   132,   123,   124,
       1,     1,   112,   118,   118,   273,   198,    37,   274,    51,
      38,    72,   212,   -78,   -78,   128,   129,   118,   118,     6,
     130,    52,   216,   217,     1,    38,   133,   126,   182,   -86,
     -78,    82,    82,   -68,   188,    82,   112,    24,    82,   138,
     139,    26,   141,   142,   143,   144,   145,    39,   -69,    90,
     148,   229,   263,   131,    82,    36,    82,   140,    48,    49,
      50,    71,   156,    56,    56,    91,    56,    56,    26,   146,
      39,   120,   166,   158,   112,   122,    92,    93,    36,   112,
      70,    36,   162,   163,    39,   281,   159,   161,   189,    92,
      93,    36,   193,   181,   228,    36,    56,   287,   194,    65,
      68,   197,   195,   112,   133,   249,   251,   252,   253,   234,
     255,   256,   257,   204,   240,   220,   121,   265,    92,    93,
     254,   201,   202,   166,   214,   205,   112,   166,    56,    56,
      56,    56,    56,    56,   266,    55,    57,   284,    60,    61,
      64,    67,   243,   269,   271,   209,   210,   211,   112,     0,
       0,     0,     0,   180,   238,   147,   283,    85,    86,    87,
      88,    89,     0,     0,    90,   235,     0,     0,    60,    56,
     118,   261,   160,    87,    88,    89,     0,     0,    90,     0,
     167,   245,   246,   247,   237,     0,     0,     0,   186,    48,
       0,     0,     0,    59,     0,     0,     0,     0,     0,   248,
     149,   150,   151,   152,   153,   154,     0,     0,   267,     0,
       0,     0,     0,     0,     0,    48,    56,     0,     0,     0,
       0,   180,     0,     0,     0,   179,     0,     0,   112,     0,
     112,   278,     0,     0,   166,     0,     0,     0,     0,     0,
       0,   190,     0,     0,   276,     0,   166,     0,     0,     0,
     282,     0,   112,     0,     0,   112,     0,     0,     0,   112,
       0,   112,   180,   180,   180,   180,     0,   180,   180,   180,
     180,     0,     0,     0,     0,     9,     0,     0,    10,    11,
     175,     0,     0,     0,     0,     0,     0,     0,    60,     0,
       0,     0,   180,   179,   180,   180,   180,     0,   180,   180,
     180,   180,   169,     0,     0,     0,    16,    17,     0,   262,
      43,    43,   264,   180,   180,    20,    21,     0,    22,     0,
      23,     0,     0,    24,    25,     0,   180,     0,    43,     0,
       0,   169,   272,     0,   179,   179,   179,   179,     0,   179,
     179,   179,   179,   213,    42,    42,     0,     0,   175,     0,
       0,   134,   286,     0,   206,     0,     0,   289,   290,     0,
       0,   293,    42,     0,   179,   295,   179,   179,   179,     0,
     179,   179,   179,   179,     0,     0,   169,     0,     0,     0,
       0,     0,     0,     0,     0,   179,   179,     0,     0,   175,
     175,   175,   175,     0,   175,   175,   175,   175,   179,    43,
      43,     0,     0,     0,   187,     0,     0,     0,     0,     0,
      43,     0,   185,     0,     0,     0,   191,   192,     0,   175,
       0,   175,   175,   175,     0,   175,   175,   175,   175,     0,
       0,     0,     0,    42,    42,     0,     0,     0,     0,     0,
     175,   175,     0,     0,    42,     0,     0,     0,     0,     0,
       0,     0,     0,   175,     0,     0,   275,     0,   277,     0,
       0,     0,    43,    43,     0,     0,     0,     0,   185,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     291,     0,     0,   294,     0,     0,     0,   296,     0,   297,
     236,     0,     0,   239,     0,     0,    42,    42,     0,     0,
       0,    43,   244,     0,     0,     0,   242,     0,     0,     0,
       0,   -60,    66,     0,     8,     9,    43,     0,    10,    11,
     259,     0,     0,     0,     1,     0,    12,    13,     0,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,     0,
     268,    14,    15,     0,     0,     0,    16,    17,    18,    19,
      42,     0,     0,     0,   279,    20,    21,     0,    22,     0,
      23,    43,     0,    24,    25,   280,   285,    43,    26,   288,
       0,     0,     0,     0,     0,   292,     0,     0,     0,     0,
       0,     0,     0,     0,    94,     0,     8,     9,     0,     0,
      10,    11,     0,     0,     0,    42,     0,     0,     0,     0,
      95,    42,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,     0,    15,     0,     0,     0,    16,    17,
      18,    19,     0,     0,     0,     0,     0,    20,    21,     0,
      22,   168,    23,     8,     9,    24,    25,    10,    11,     0,
      26,   107,    39,     0,     0,     0,     0,    95,     0,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
       0,    15,     0,     0,     0,    16,    17,    18,    19,     0,
       0,     0,     0,     0,    20,    21,     0,    22,    94,    23,
       8,     9,    24,    25,    10,    11,     0,    26,   107,    39,
       0,     0,     0,     0,    95,     0,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,     0,    15,     0,
       0,     0,    16,    17,    18,    19,     0,     0,     0,     0,
       0,    20,    21,     0,    22,     0,    23,     0,     0,    24,
      25,     0,     0,     0,    26,   171,    39,     8,     9,     0,
       0,    10,    11,     0,   -77,     0,     0,   -77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,     0,     0,
      10,    11,   -87,     0,     0,   172,     0,     0,     0,    16,
      17,    18,    19,     0,     0,     0,   -77,   -77,    20,    21,
       0,    22,     0,   173,     0,     0,    24,   174,    16,    17,
       8,     9,     0,   -77,    10,    11,    73,    20,    21,    74,
      22,     0,   173,     0,     0,    24,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,    75,
      76,    77,    16,    17,    18,    19,    78,     0,    79,    80,
      81,    20,    21,     0,    22,     0,    23,     8,     9,    24,
      25,    10,    11,     0,     0,     0,     0,    82,     0,     0,
       0,    95,     0,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,     0,    15,     0,     0,     0,    16,
      17,    18,    19,     0,     0,     0,     0,     0,    20,    21,
       0,    22,     0,    23,     0,     0,    24,    25,     0,     0,
       0,    26,     0,    39,     8,     9,     0,     0,    10,    11,
      73,     0,     0,    74,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     9,     0,     0,    10,    11,     0,
       0,     0,    15,    75,    76,    77,    16,    17,    18,    19,
      78,     0,    79,    80,    81,    20,    21,     0,    22,     0,
      23,     0,     0,    24,    25,    16,    17,     8,     9,     0,
      39,    10,    11,    73,    20,    21,    74,    22,     0,   173,
       0,     0,    24,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,    75,    76,    77,    16,
      17,    18,    19,    78,     0,    79,    80,    81,    20,    21,
       0,    22,     7,    23,     8,     9,    24,    25,    10,    11,
       0,     0,     0,    39,     0,     0,    12,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       9,    14,    15,    10,    11,     0,    16,    17,    18,    19,
       0,     0,     0,     0,     0,    20,    21,     0,    22,     0,
      23,     0,     0,    24,    25,     0,     0,    15,    26,     0,
       0,    16,    17,    18,    19,     0,     0,     0,     0,     0,
      20,    21,     0,    22,    62,    23,     8,     9,    24,    25,
      10,    11,     0,     0,     0,    39,     0,     0,     0,     0,
       0,     0,     0,     0,    62,     0,     8,     9,     0,     0,
      10,    11,     0,     0,    15,     0,     0,     0,    16,    17,
      18,    19,     0,     0,     0,     0,     0,    20,    21,     0,
      22,     0,    23,     0,    15,    24,    25,   -85,    16,    17,
      18,    19,     0,     0,     0,     0,     0,    20,    21,     0,
      22,   196,    23,     8,     9,    24,    25,    10,    11,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     250,     0,     8,     9,     0,     0,    10,    11,     0,     0,
       0,    15,     0,     0,     0,    16,    17,    18,    19,     0,
       0,     0,     0,     0,    20,    21,     0,    22,     0,    23,
     172,     0,    24,    25,    16,    17,    18,    19,     0,     0,
       0,     0,     0,    20,    21,     0,    22,     0,   173,     8,
       9,    24,    54,    10,    11,    73,     0,     0,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,    75,    76,
      77,    16,    17,    18,    19,    78,     0,    79,    80,    81,
      20,    21,     0,    22,     0,    23,     0,     0,    24,    25,
     133,     8,     9,     0,     0,    10,    11,    73,     0,     0,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
      75,    76,    77,    16,    17,    18,    19,    78,   199,    79,
      80,    81,    20,    21,     0,    22,     0,    23,     8,     9,
      24,    25,    10,    11,    73,     0,     0,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    75,    76,    77,
      16,    17,    18,    19,    78,     0,    79,    80,    81,    20,
      21,     0,    22,     0,    23,     8,     9,    24,    25,    10,
      11,    73,     0,     0,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,    75,    76,     0,    16,    17,    18,
      19,     0,     0,    79,    80,    81,    20,    21,     0,    22,
       0,    23,     8,     9,    24,    25,    10,    11,   221,     0,
       0,   222,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     172,   223,   224,   225,    16,    17,    18,    19,   226,   270,
       0,     0,     0,    20,    21,     0,    22,     0,   173,     8,
       9,    24,    54,    10,    11,    73,     0,     0,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,    75,     0,
       0,    16,    17,    18,    19,     0,     0,    79,    80,    81,
      20,    21,     0,    22,     0,    23,     8,     9,    24,    25,
      10,    11,   221,     0,     0,   222,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   172,   223,   224,   225,    16,    17,
      18,    19,   226,     0,     0,     0,     0,    20,    21,     0,
      22,     0,   173,     8,     9,    24,    54,    10,    11,   221,
       0,     0,   222,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   172,   223,   224,     0,    16,    17,    18,    19,     0,
       0,     0,     0,     0,    20,    21,     0,    22,     0,   173,
       8,     9,    24,    54,    10,    11,   221,     0,     0,   222,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       9,     0,     0,    10,    11,     0,     0,     0,   172,   223,
       0,     0,    16,    17,    18,    19,     0,     0,     0,     0,
       0,    20,    21,     0,    22,     0,   173,    15,     0,    24,
      54,    16,    17,    18,    19,     0,     0,     0,     0,     0,
      20,    21,     0,    22,     0,    23,     8,   207,    24,    25,
      10,    11,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     8,     9,     0,     0,    10,
      11,     0,     0,     0,    15,     0,     0,     0,    16,    17,
      18,    19,     0,     0,     0,     0,     0,    20,    21,     0,
      22,     0,    23,   172,     0,    24,    25,    16,    17,    18,
      19,     0,     0,     0,     0,     0,    20,    21,     0,    22,
       0,   173,     8,     9,    24,    54,    10,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     8,     9,     0,     0,    10,    11,     0,     0,     0,
       0,     0,     0,     0,    16,    17,    18,    19,     0,     0,
       0,     0,     0,    20,    21,     0,    22,     0,    53,     0,
       0,    24,    54,    16,    17,    18,    19,     0,     0,     0,
       0,     9,    20,    21,    10,    11,    73,    53,     0,   -87,
      24,    54,     0,     0,     0,     0,     9,     0,     0,    10,
      11,   -87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,    17,     0,     0,     0,     0,    79,    80,
      81,    20,    21,     0,    22,     0,    23,    16,    17,    24,
      25,     0,     0,   -87,   -87,   -87,    20,    21,     0,    22,
       0,    23,     0,     9,    24,    25,    10,    11,   221,     0,
       0,   -87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,     0,     0,     0,     0,
       0,     0,     0,    20,    21,     0,    22,     0,   173,     0,
       0,    24,    54
};

static const yytype_int16 yycheck[] =
{
       4,    33,     1,     1,   157,    25,     1,   108,   161,     1,
       1,    10,   113,     4,    13,    70,   146,    32,    38,     4,
      10,    25,     0,    27,    13,     1,   110,     1,     3,     4,
      13,    13,    36,    37,    38,     1,   137,    53,     4,    53,
      55,    30,   172,    42,    43,    51,    52,    51,    52,    13,
      54,    53,    42,    43,    13,    55,    54,    41,   113,    54,
      59,    60,    60,    54,    56,    60,    70,    52,    60,    73,
      74,    57,    76,    77,    78,    79,    80,    59,    54,    51,
      84,   182,    56,     5,    60,     4,    60,     4,    15,    16,
      17,    30,    53,    20,    21,    11,    23,    24,    57,    31,
      59,    40,   106,     4,   108,    44,    35,    36,    27,   113,
      29,    30,   101,   102,    59,   268,    53,    53,    53,    35,
      36,    40,    47,   112,    11,    44,    53,   280,   132,    26,
      27,   135,    32,   137,    54,   219,   220,   221,   222,     4,
     224,   225,   226,    55,    21,   177,    43,    53,    35,    36,
       4,   155,   156,   157,   174,   159,   160,   161,    85,    86,
      87,    88,    89,    90,     4,    20,    21,    18,    23,    24,
     174,    27,   212,   244,   258,   164,   165,   170,   182,    -1,
      -1,    -1,    -1,   110,   204,    82,   270,    44,    45,    46,
      47,    48,    -1,    -1,    51,   199,    -1,    -1,    53,   126,
     204,   233,    99,    46,    47,    48,    -1,    -1,    51,    -1,
     107,   215,   216,   217,   203,    -1,    -1,    -1,   115,   146,
      -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,   218,
      85,    86,    87,    88,    89,    90,    -1,    -1,   242,    -1,
      -1,    -1,    -1,    -1,    -1,   172,   173,    -1,    -1,    -1,
      -1,   178,    -1,    -1,    -1,   110,    -1,    -1,   262,    -1,
     264,   265,    -1,    -1,   268,    -1,    -1,    -1,    -1,    -1,
      -1,   126,    -1,    -1,   263,    -1,   280,    -1,    -1,    -1,
     269,    -1,   286,    -1,    -1,   289,    -1,    -1,    -1,   293,
      -1,   295,   219,   220,   221,   222,    -1,   224,   225,   226,
     227,    -1,    -1,    -1,    -1,     4,    -1,    -1,     7,     8,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,   249,   178,   251,   252,   253,    -1,   255,   256,
     257,   258,   108,    -1,    -1,    -1,    35,    36,    -1,   236,
      12,    13,   239,   270,   271,    44,    45,    -1,    47,    -1,
      49,    -1,    -1,    52,    53,    -1,   283,    -1,    30,    -1,
      -1,   137,   259,    -1,   219,   220,   221,   222,    -1,   224,
     225,   226,   227,   173,    12,    13,    -1,    -1,   178,    -1,
      -1,    63,   279,    -1,   160,    -1,    -1,   284,   285,    -1,
      -1,   288,    30,    -1,   249,   292,   251,   252,   253,    -1,
     255,   256,   257,   258,    -1,    -1,   182,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   270,   271,    -1,    -1,   219,
     220,   221,   222,    -1,   224,   225,   226,   227,   283,   101,
     102,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
     112,    -1,   114,    -1,    -1,    -1,   128,   129,    -1,   249,
      -1,   251,   252,   253,    -1,   255,   256,   257,   258,    -1,
      -1,    -1,    -1,   101,   102,    -1,    -1,    -1,    -1,    -1,
     270,   271,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   283,    -1,    -1,   262,    -1,   264,    -1,
      -1,    -1,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     286,    -1,    -1,   289,    -1,    -1,    -1,   293,    -1,   295,
     202,    -1,    -1,   205,    -1,    -1,   164,   165,    -1,    -1,
      -1,   203,   214,    -1,    -1,    -1,   208,    -1,    -1,    -1,
      -1,     0,     1,    -1,     3,     4,   218,    -1,     7,     8,
     232,    -1,    -1,    -1,    13,    -1,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,
     242,    30,    31,    -1,    -1,    -1,    35,    36,    37,    38,
     218,    -1,    -1,    -1,   266,    44,    45,    -1,    47,    -1,
      49,   263,    -1,    52,    53,   267,   278,   269,    57,   281,
      -1,    -1,    -1,    -1,    -1,   287,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,    -1,    -1,
       7,     8,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,
      17,   269,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    -1,    -1,    -1,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,
      47,     1,    49,     3,     4,    52,    53,     7,     8,    -1,
      57,    58,    59,    -1,    -1,    -1,    -1,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    -1,    -1,    -1,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    44,    45,    -1,    47,     1,    49,
       3,     4,    52,    53,     7,     8,    -1,    57,    58,    59,
      -1,    -1,    -1,    -1,    17,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    -1,
      -1,    -1,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    44,    45,    -1,    47,    -1,    49,    -1,    -1,    52,
      53,    -1,    -1,    -1,    57,     1,    59,     3,     4,    -1,
      -1,     7,     8,    -1,    10,    -1,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,
       7,     8,     9,    -1,    -1,    31,    -1,    -1,    -1,    35,
      36,    37,    38,    -1,    -1,    -1,    42,    43,    44,    45,
      -1,    47,    -1,    49,    -1,    -1,    52,    53,    35,    36,
       3,     4,    -1,    59,     7,     8,     9,    44,    45,    12,
      47,    -1,    49,    -1,    -1,    52,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    41,    42,
      43,    44,    45,    -1,    47,    -1,    49,     3,     4,    52,
      53,     7,     8,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    -1,    -1,    -1,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    44,    45,
      -1,    47,    -1,    49,    -1,    -1,    52,    53,    -1,    -1,
      -1,    57,    -1,    59,     3,     4,    -1,    -1,     7,     8,
       9,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,    -1,    -1,     7,     8,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    41,    42,    43,    44,    45,    -1,    47,    -1,
      49,    -1,    -1,    52,    53,    35,    36,     3,     4,    -1,
      59,     7,     8,     9,    44,    45,    12,    47,    -1,    49,
      -1,    -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    41,    42,    43,    44,    45,
      -1,    47,     1,    49,     3,     4,    52,    53,     7,     8,
      -1,    -1,    -1,    59,    -1,    -1,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    30,    31,     7,     8,    -1,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,    -1,
      49,    -1,    -1,    52,    53,    -1,    -1,    31,    57,    -1,
      -1,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      44,    45,    -1,    47,     1,    49,     3,     4,    52,    53,
       7,     8,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,    -1,    -1,
       7,     8,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,
      47,    -1,    49,    -1,    31,    52,    53,    54,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,
      47,     1,    49,     3,     4,    52,    53,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,    -1,    -1,     7,     8,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    44,    45,    -1,    47,    -1,    49,
      31,    -1,    52,    53,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    44,    45,    -1,    47,    -1,    49,     3,
       4,    52,    53,     7,     8,     9,    -1,    -1,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    41,    42,    43,
      44,    45,    -1,    47,    -1,    49,    -1,    -1,    52,    53,
      54,     3,     4,    -1,    -1,     7,     8,     9,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    47,    -1,    49,     3,     4,
      52,    53,     7,     8,     9,    -1,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    41,    42,    43,    44,
      45,    -1,    47,    -1,    49,     3,     4,    52,    53,     7,
       8,     9,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    -1,    35,    36,    37,
      38,    -1,    -1,    41,    42,    43,    44,    45,    -1,    47,
      -1,    49,     3,     4,    52,    53,     7,     8,     9,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    44,    45,    -1,    47,    -1,    49,     3,
       4,    52,    53,     7,     8,     9,    -1,    -1,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    35,    36,    37,    38,    -1,    -1,    41,    42,    43,
      44,    45,    -1,    47,    -1,    49,     3,     4,    52,    53,
       7,     8,     9,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    44,    45,    -1,
      47,    -1,    49,     3,     4,    52,    53,     7,     8,     9,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,    -1,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    44,    45,    -1,    47,    -1,    49,
       3,     4,    52,    53,     7,     8,     9,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,    -1,     7,     8,    -1,    -1,    -1,    31,    32,
      -1,    -1,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    44,    45,    -1,    47,    -1,    49,    31,    -1,    52,
      53,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      44,    45,    -1,    47,    -1,    49,     3,     4,    52,    53,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,     7,
       8,    -1,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,
      47,    -1,    49,    31,    -1,    52,    53,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,
      -1,    49,     3,     4,    52,    53,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,    -1,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    44,    45,    -1,    47,    -1,    49,    -1,
      -1,    52,    53,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,     4,    44,    45,     7,     8,     9,    49,    -1,    12,
      52,    53,    -1,    -1,    -1,    -1,     4,    -1,    -1,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    41,    42,
      43,    44,    45,    -1,    47,    -1,    49,    35,    36,    52,
      53,    -1,    -1,    41,    42,    43,    44,    45,    -1,    47,
      -1,    49,    -1,     4,    52,    53,     7,     8,     9,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    -1,    47,    -1,    49,    -1,
      -1,    52,    53
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    62,    82,    83,     0,    13,     1,     3,     4,
       7,     8,    15,    16,    30,    31,    35,    36,    37,    38,
      44,    45,    47,    49,    52,    53,    57,    63,    64,    68,
      71,    72,    74,    93,    97,    99,   100,    53,    55,    59,
      65,    76,    82,   104,    66,    76,    69,    98,    99,    99,
      99,    53,    53,    49,    53,    97,    99,    97,    73,    72,
      97,    97,     1,    92,    93,    83,     1,    64,    83,    70,
     100,    74,    76,     9,    12,    32,    33,    34,    39,    41,
      42,    43,    60,    93,   105,    44,    45,    46,    47,    48,
      51,    11,    35,    36,     1,    17,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    58,    75,    77,
      80,    81,    93,   100,   101,   104,    91,    92,    93,    92,
      74,    83,    74,     3,     4,    67,    41,    84,    91,    91,
      93,     5,     1,    54,   102,   105,   102,    75,    93,    93,
       4,    93,    93,    93,    93,    93,    31,    83,    93,    97,
      97,    97,    97,    97,    97,    94,    53,    79,     4,    53,
      83,    53,    76,    76,    78,    88,    93,    83,     1,    77,
     101,     1,    31,    49,    53,    72,    89,    90,    95,    97,
      99,    76,    75,   101,   103,   104,    83,   102,    56,    53,
      97,   102,   102,    47,    93,    32,     1,    93,   101,    40,
      98,    93,    93,    88,    55,    93,    77,     4,    88,    76,
      76,   103,    98,    72,    92,    10,    42,    43,    85,     1,
     105,     9,    12,    32,    33,    34,    39,    95,    11,   101,
       1,     4,    86,    87,     4,    93,   102,    76,    92,   102,
      21,    32,   104,    84,   102,    93,    93,    93,    76,    95,
       1,    95,    95,    95,     4,    95,    95,    95,    96,   102,
       1,   105,    83,    56,    83,    53,     4,    93,   104,    85,
      40,    95,    83,     1,     4,    77,    76,    77,    93,   102,
     104,    88,    76,    95,    18,   102,    83,    88,   102,    83,
      83,    77,   102,    83,    77,    83,    77,    77
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

    { expression_value = (yyvsp[(2) - (3)].nodeval); ;}
    break;

  case 3:

    { 
			if ((yyvsp[(1) - (1)].nodeval) != NULL)
				(yyval.nodeval) = (yyvsp[(1) - (1)].nodeval);
			else
				(yyval.nodeval) = NULL;
			yyerrok;
		;}
    break;

  case 4:

    {
			if ((yyvsp[(2) - (2)].nodeval) == NULL)
				(yyval.nodeval) = (yyvsp[(1) - (2)].nodeval);
			else if ((yyvsp[(1) - (2)].nodeval) == NULL)
				(yyval.nodeval) = (yyvsp[(2) - (2)].nodeval);
			else {
				if ((yyvsp[(1) - (2)].nodeval)->type != Node_rule_list)
					(yyvsp[(1) - (2)].nodeval) = node((yyvsp[(1) - (2)].nodeval), Node_rule_list,
						(NODE*)NULL);
				(yyval.nodeval) = append_right ((yyvsp[(1) - (2)].nodeval),
				   node((yyvsp[(2) - (2)].nodeval), Node_rule_list,(NODE *) NULL));
			}
			yyerrok;
		;}
    break;

  case 5:

    { (yyval.nodeval) = NULL; ;}
    break;

  case 6:

    { (yyval.nodeval) = NULL; ;}
    break;

  case 7:

    { io_allowed = 0; ;}
    break;

  case 8:

    {
		if (begin_block) {
			if (begin_block->type != Node_rule_list)
				begin_block = node(begin_block, Node_rule_list,
					(NODE *)NULL);
			append_right (begin_block, node(
			    node((NODE *)NULL, Node_rule_node, (yyvsp[(3) - (3)].nodeval)),
			    Node_rule_list, (NODE *)NULL) );
		} else
			begin_block = node((NODE *)NULL, Node_rule_node, (yyvsp[(3) - (3)].nodeval));
		(yyval.nodeval) = NULL;
		io_allowed = 1;
		yyerrok;
	  ;}
    break;

  case 9:

    { io_allowed = 0; ;}
    break;

  case 10:

    {
		if (end_block) {
			if (end_block->type != Node_rule_list)
				end_block = node(end_block, Node_rule_list,
					(NODE *)NULL);
			append_right (end_block, node(
			    node((NODE *)NULL, Node_rule_node, (yyvsp[(3) - (3)].nodeval)),
			    Node_rule_list, (NODE *)NULL));
		} else
			end_block = node((NODE *)NULL, Node_rule_node, (yyvsp[(3) - (3)].nodeval));
		(yyval.nodeval) = NULL;
		io_allowed = 1;
		yyerrok;
	  ;}
    break;

  case 11:

    {
		msg ("error near line %d: BEGIN blocks must have an action part", lineno);
		errcount++;
		yyerrok;
	  ;}
    break;

  case 12:

    {
		msg ("error near line %d: END blocks must have an action part", lineno);
		errcount++;
		yyerrok;
	  ;}
    break;

  case 13:

    { (yyval.nodeval) = node ((yyvsp[(1) - (2)].nodeval), Node_rule_node, (yyvsp[(2) - (2)].nodeval)); yyerrok; ;}
    break;

  case 14:

    { (yyval.nodeval) = node ((NODE *)NULL, Node_rule_node, (yyvsp[(1) - (1)].nodeval)); yyerrok; ;}
    break;

  case 15:

    { if((yyvsp[(1) - (2)].nodeval)) (yyval.nodeval) = node ((yyvsp[(1) - (2)].nodeval), Node_rule_node, (NODE *)NULL); yyerrok; ;}
    break;

  case 16:

    {
			func_install((yyvsp[(1) - (2)].nodeval), (yyvsp[(2) - (2)].nodeval));
			(yyval.nodeval) = NULL;
			yyerrok;
		;}
    break;

  case 17:

    { (yyval.sval) = (yyvsp[(1) - (1)].sval); ;}
    break;

  case 18:

    { (yyval.sval) = (yyvsp[(1) - (1)].sval); ;}
    break;

  case 19:

    {
			param_counter = 0;
		;}
    break;

  case 20:

    {
			(yyval.nodeval) = append_right(make_param((yyvsp[(3) - (7)].sval)), (yyvsp[(5) - (7)].nodeval));
			can_return = 1;
		;}
    break;

  case 21:

    {
		(yyval.nodeval) = (yyvsp[(2) - (3)].nodeval);
		can_return = 0;
	  ;}
    break;

  case 22:

    { (yyval.nodeval) = (yyvsp[(1) - (1)].nodeval); ;}
    break;

  case 23:

    { (yyval.nodeval) = mkrangenode ( node((yyvsp[(1) - (3)].nodeval), Node_cond_pair, (yyvsp[(3) - (3)].nodeval)) ); ;}
    break;

  case 24:

    { ++want_regexp; ;}
    break;

  case 25:

    {
		  want_regexp = 0;
		  (yyval.nodeval) = node((NODE *)NULL,Node_regex,(NODE *)mk_re_parse((yyvsp[(3) - (4)].sval), 0));
		  (yyval.nodeval) -> re_case = 0;
		  emalloc ((yyval.nodeval) -> re_text, char *, strlen((yyvsp[(3) - (4)].sval))+1, "regexp");
		  strcpy ((yyval.nodeval) -> re_text, (yyvsp[(3) - (4)].sval));
		;}
    break;

  case 26:

    {
			/* empty actions are different from missing actions */
			(yyval.nodeval) = node ((NODE *) NULL, Node_illegal, (NODE *) NULL);
		;}
    break;

  case 27:

    { (yyval.nodeval) = (yyvsp[(2) - (4)].nodeval) ; ;}
    break;

  case 28:

    { (yyval.nodeval) = (yyvsp[(1) - (1)].nodeval); ;}
    break;

  case 29:

    {
			if ((yyvsp[(1) - (2)].nodeval) == NULL || (yyvsp[(1) - (2)].nodeval)->type != Node_statement_list)
				(yyvsp[(1) - (2)].nodeval) = node((yyvsp[(1) - (2)].nodeval), Node_statement_list,(NODE *)NULL);
	    		(yyval.nodeval) = append_right((yyvsp[(1) - (2)].nodeval),
				node( (yyvsp[(2) - (2)].nodeval), Node_statement_list, (NODE *)NULL));
	    		yyerrok;
		;}
    break;

  case 30:

    { (yyval.nodeval) = NULL; ;}
    break;

  case 31:

    { (yyval.nodeval) = NULL; ;}
    break;

  case 32:

    { (yyval.nodetypeval) = Node_illegal; ;}
    break;

  case 33:

    { (yyval.nodetypeval) = Node_illegal; ;}
    break;

  case 34:

    { (yyval.nodeval) = NULL; ;}
    break;

  case 35:

    { (yyval.nodeval) = NULL; ;}
    break;

  case 36:

    { (yyval.nodeval) = (yyvsp[(2) - (3)].nodeval); ;}
    break;

  case 37:

    { (yyval.nodeval) = (yyvsp[(1) - (1)].nodeval); ;}
    break;

  case 38:

    { (yyval.nodeval) = node ((yyvsp[(3) - (6)].nodeval), Node_K_while, (yyvsp[(6) - (6)].nodeval)); ;}
    break;

  case 39:

    { (yyval.nodeval) = node ((yyvsp[(6) - (8)].nodeval), Node_K_do, (yyvsp[(3) - (8)].nodeval)); ;}
    break;

  case 40:

    {
		(yyval.nodeval) = node ((yyvsp[(8) - (8)].nodeval), Node_K_arrayfor, make_for_loop(variable((yyvsp[(3) - (8)].sval)),
			(NODE *)NULL, variable((yyvsp[(5) - (8)].sval))));
	  ;}
    break;

  case 41:

    {
		(yyval.nodeval) = node((yyvsp[(10) - (10)].nodeval), Node_K_for, (NODE *)make_for_loop((yyvsp[(3) - (10)].nodeval), (yyvsp[(5) - (10)].nodeval), (yyvsp[(7) - (10)].nodeval)));
	  ;}
    break;

  case 42:

    {
		(yyval.nodeval) = node ((yyvsp[(9) - (9)].nodeval), Node_K_for,
			(NODE *)make_for_loop((yyvsp[(3) - (9)].nodeval), (NODE *)NULL, (yyvsp[(6) - (9)].nodeval)));
	  ;}
    break;

  case 43:

    { (yyval.nodeval) = node ((NODE *)NULL, Node_K_break, (NODE *)NULL); ;}
    break;

  case 44:

    { (yyval.nodeval) = node ((NODE *)NULL, Node_K_continue, (NODE *)NULL); ;}
    break;

  case 45:

    { (yyval.nodeval) = node ((yyvsp[(3) - (6)].nodeval), (yyvsp[(1) - (6)].nodetypeval), (yyvsp[(5) - (6)].nodeval)); ;}
    break;

  case 46:

    { (yyval.nodeval) = node ((yyvsp[(2) - (4)].nodeval), (yyvsp[(1) - (4)].nodetypeval), (yyvsp[(3) - (4)].nodeval)); ;}
    break;

  case 47:

    { if (! io_allowed) yyerror("next used in BEGIN or END action"); ;}
    break;

  case 48:

    { (yyval.nodeval) = node ((NODE *)NULL, Node_K_next, (NODE *)NULL); ;}
    break;

  case 49:

    { (yyval.nodeval) = node ((yyvsp[(2) - (3)].nodeval), Node_K_exit, (NODE *)NULL); ;}
    break;

  case 50:

    { if (! can_return) yyerror("return used outside function context"); ;}
    break;

  case 51:

    { (yyval.nodeval) = node ((yyvsp[(3) - (4)].nodeval), Node_K_return, (NODE *)NULL); ;}
    break;

  case 52:

    { (yyval.nodeval) = node (variable((yyvsp[(2) - (6)].sval)), Node_K_delete, (yyvsp[(4) - (6)].nodeval)); ;}
    break;

  case 53:

    { (yyval.nodeval) = (yyvsp[(1) - (2)].nodeval); ;}
    break;

  case 54:

    { (yyval.nodetypeval) = (yyvsp[(1) - (1)].nodetypeval); ;}
    break;

  case 55:

    { (yyval.nodetypeval) = (yyvsp[(1) - (1)].nodetypeval); ;}
    break;

  case 56:

    {
		(yyval.nodeval) = node((yyvsp[(3) - (6)].nodeval), Node_K_if, 
			node((yyvsp[(6) - (6)].nodeval), Node_if_branches, (NODE *)NULL));
	  ;}
    break;

  case 57:

    { (yyval.nodeval) = node ((yyvsp[(3) - (9)].nodeval), Node_K_if,
				node ((yyvsp[(6) - (9)].nodeval), Node_if_branches, (yyvsp[(9) - (9)].nodeval))); ;}
    break;

  case 58:

    { (yyval.nodetypeval) = 0; ;}
    break;

  case 59:

    { (yyval.nodetypeval) = 0; ;}
    break;

  case 60:

    { (yyval.nodetypeval) = 0; ;}
    break;

  case 61:

    { (yyval.nodetypeval) = 0; ;}
    break;

  case 62:

    { (yyval.nodeval) = NULL; ;}
    break;

  case 63:

    { (yyval.nodeval) = node ((yyvsp[(2) - (2)].nodeval), Node_redirect_input, (NODE *)NULL); ;}
    break;

  case 64:

    { (yyval.nodeval) = NULL; ;}
    break;

  case 65:

    { (yyval.nodeval) = node ((yyvsp[(2) - (2)].nodeval), Node_redirect_output, (NODE *)NULL); ;}
    break;

  case 66:

    { (yyval.nodeval) = node ((yyvsp[(2) - (2)].nodeval), Node_redirect_append, (NODE *)NULL); ;}
    break;

  case 67:

    { (yyval.nodeval) = node ((yyvsp[(2) - (2)].nodeval), Node_redirect_pipe, (NODE *)NULL); ;}
    break;

  case 68:

    { (yyval.nodeval) = NULL; ;}
    break;

  case 69:

    { (yyval.nodeval) = (yyvsp[(1) - (1)].nodeval); ;}
    break;

  case 70:

    { (yyval.nodeval) = make_param((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 71:

    { (yyval.nodeval) = append_right((yyvsp[(1) - (3)].nodeval), make_param((yyvsp[(3) - (3)].sval))); yyerrok; ;}
    break;

  case 72:

    { (yyval.nodeval) = NULL; ;}
    break;

  case 73:

    { (yyval.nodeval) = NULL; ;}
    break;

  case 74:

    { (yyval.nodeval) = NULL; ;}
    break;

  case 75:

    { (yyval.nodeval) = NULL; ;}
    break;

  case 76:

    { (yyval.nodeval) = (yyvsp[(1) - (1)].nodeval); ;}
    break;

  case 77:

    { (yyval.nodeval) = NULL; ;}
    break;

  case 78:

    { (yyval.nodeval) = (yyvsp[(1) - (1)].nodeval); ;}
    break;

  case 79:

    { (yyval.nodeval) = node ((yyvsp[(1) - (1)].nodeval), Node_expression_list, (NODE *)NULL); ;}
    break;

  case 80:

    {
		(yyval.nodeval) = append_right((yyvsp[(1) - (3)].nodeval),
			node( (yyvsp[(3) - (3)].nodeval), Node_expression_list, (NODE *)NULL));
		yyerrok;
	  ;}
    break;

  case 81:

    { (yyval.nodeval) = NULL; ;}
    break;

  case 82:

    { (yyval.nodeval) = NULL; ;}
    break;

  case 83:

    { (yyval.nodeval) = NULL; ;}
    break;

  case 84:

    { (yyval.nodeval) = NULL; ;}
    break;

  case 85:

    { (yyval.nodeval) = NULL; ;}
    break;

  case 86:

    { (yyval.nodeval) = (yyvsp[(1) - (1)].nodeval); ;}
    break;

  case 87:

    { (yyval.nodeval) = node ((yyvsp[(1) - (1)].nodeval), Node_expression_list, (NODE *)NULL); ;}
    break;

  case 88:

    {
			(yyval.nodeval) = append_right((yyvsp[(1) - (3)].nodeval),
				node( (yyvsp[(3) - (3)].nodeval), Node_expression_list, (NODE *)NULL));
			yyerrok;
		;}
    break;

  case 89:

    { (yyval.nodeval) = NULL; ;}
    break;

  case 90:

    { (yyval.nodeval) = NULL; ;}
    break;

  case 91:

    { (yyval.nodeval) = NULL; ;}
    break;

  case 92:

    { (yyval.nodeval) = NULL; ;}
    break;

  case 93:

    { want_assign = 0; ;}
    break;

  case 94:

    { (yyval.nodeval) = node ((yyvsp[(1) - (4)].nodeval), (yyvsp[(2) - (4)].nodetypeval), (yyvsp[(4) - (4)].nodeval)); ;}
    break;

  case 95:

    { (yyval.nodeval) = node (variable((yyvsp[(5) - (5)].sval)), Node_in_array, (yyvsp[(2) - (5)].nodeval)); ;}
    break;

  case 96:

    {
		  (yyval.nodeval) = node ((yyvsp[(4) - (4)].nodeval), Node_K_getline,
			 node ((yyvsp[(1) - (4)].nodeval), Node_redirect_pipein, (NODE *)NULL));
		;}
    break;

  case 97:

    {
		  /* "too painful to do right" */
		  /*
		  if (! io_allowed && $3 == NULL)
			yyerror("non-redirected getline illegal inside BEGIN or END action");
		  */
		  (yyval.nodeval) = node ((yyvsp[(2) - (3)].nodeval), Node_K_getline, (yyvsp[(3) - (3)].nodeval));
		;}
    break;

  case 98:

    { (yyval.nodeval) = node ((yyvsp[(1) - (3)].nodeval), Node_and, (yyvsp[(3) - (3)].nodeval)); ;}
    break;

  case 99:

    { (yyval.nodeval) = node ((yyvsp[(1) - (3)].nodeval), Node_or, (yyvsp[(3) - (3)].nodeval)); ;}
    break;

  case 100:

    { (yyval.nodeval) = node ((yyvsp[(1) - (3)].nodeval), (yyvsp[(2) - (3)].nodetypeval), (yyvsp[(3) - (3)].nodeval)); ;}
    break;

  case 101:

    { (yyval.nodeval) = (yyvsp[(1) - (1)].nodeval); ;}
    break;

  case 102:

    { (yyval.nodeval) = node((NODE *) NULL, Node_nomatch, (yyvsp[(2) - (2)].nodeval)); ;}
    break;

  case 103:

    { (yyval.nodeval) = node (variable((yyvsp[(3) - (3)].sval)), Node_in_array, (yyvsp[(1) - (3)].nodeval)); ;}
    break;

  case 104:

    { (yyval.nodeval) = node ((yyvsp[(1) - (3)].nodeval), (yyvsp[(2) - (3)].nodetypeval), (yyvsp[(3) - (3)].nodeval)); ;}
    break;

  case 105:

    { (yyval.nodeval) = node ((yyvsp[(1) - (3)].nodeval), Node_less, (yyvsp[(3) - (3)].nodeval)); ;}
    break;

  case 106:

    { (yyval.nodeval) = node ((yyvsp[(1) - (3)].nodeval), Node_greater, (yyvsp[(3) - (3)].nodeval)); ;}
    break;

  case 107:

    { (yyval.nodeval) = node((yyvsp[(1) - (5)].nodeval), Node_cond_exp, node((yyvsp[(3) - (5)].nodeval), Node_if_branches, (yyvsp[(5) - (5)].nodeval)));;}
    break;

  case 108:

    { (yyval.nodeval) = (yyvsp[(1) - (1)].nodeval); ;}
    break;

  case 109:

    { (yyval.nodeval) = node ((yyvsp[(1) - (2)].nodeval), Node_concat, (yyvsp[(2) - (2)].nodeval)); ;}
    break;

  case 110:

    { want_assign = 0; ;}
    break;

  case 111:

    { (yyval.nodeval) = node ((yyvsp[(1) - (4)].nodeval), (yyvsp[(2) - (4)].nodetypeval), (yyvsp[(4) - (4)].nodeval)); ;}
    break;

  case 112:

    { (yyval.nodeval) = node ((yyvsp[(1) - (3)].nodeval), Node_and, (yyvsp[(3) - (3)].nodeval)); ;}
    break;

  case 113:

    { (yyval.nodeval) = node ((yyvsp[(1) - (3)].nodeval), Node_or, (yyvsp[(3) - (3)].nodeval)); ;}
    break;

  case 114:

    {
		  /* "too painful to do right" */
		  /*
		  if (! io_allowed && $3 == NULL)
			yyerror("non-redirected getline illegal inside BEGIN or END action");
		  */
		  (yyval.nodeval) = node ((yyvsp[(2) - (3)].nodeval), Node_K_getline, (yyvsp[(3) - (3)].nodeval));
		;}
    break;

  case 115:

    { (yyval.nodeval) = (yyvsp[(1) - (1)].nodeval); ;}
    break;

  case 116:

    { (yyval.nodeval) = node((NODE *) NULL, Node_nomatch, (yyvsp[(2) - (2)].nodeval)); ;}
    break;

  case 117:

    { (yyval.nodeval) = node ((yyvsp[(1) - (3)].nodeval), (yyvsp[(2) - (3)].nodetypeval), (yyvsp[(3) - (3)].nodeval)); ;}
    break;

  case 118:

    { (yyval.nodeval) = node (variable((yyvsp[(3) - (3)].sval)), Node_in_array, (yyvsp[(1) - (3)].nodeval)); ;}
    break;

  case 119:

    { (yyval.nodeval) = node ((yyvsp[(1) - (3)].nodeval), (yyvsp[(2) - (3)].nodetypeval), (yyvsp[(3) - (3)].nodeval)); ;}
    break;

  case 120:

    { (yyval.nodeval) = node((yyvsp[(1) - (5)].nodeval), Node_cond_exp, node((yyvsp[(3) - (5)].nodeval), Node_if_branches, (yyvsp[(5) - (5)].nodeval)));;}
    break;

  case 121:

    { (yyval.nodeval) = (yyvsp[(1) - (1)].nodeval); ;}
    break;

  case 122:

    { (yyval.nodeval) = node ((yyvsp[(1) - (2)].nodeval), Node_concat, (yyvsp[(2) - (2)].nodeval)); ;}
    break;

  case 123:

    { (yyval.nodeval) = node ((yyvsp[(2) - (2)].nodeval), Node_not,(NODE *) NULL); ;}
    break;

  case 124:

    { (yyval.nodeval) = (yyvsp[(2) - (3)].nodeval); ;}
    break;

  case 125:

    { (yyval.nodeval) = snode ((yyvsp[(3) - (4)].nodeval), Node_builtin, (yyvsp[(1) - (4)].ptrval)); ;}
    break;

  case 126:

    { (yyval.nodeval) = snode ((yyvsp[(3) - (4)].nodeval), Node_builtin, (yyvsp[(1) - (4)].ptrval)); ;}
    break;

  case 127:

    { (yyval.nodeval) = snode ((NODE *)NULL, Node_builtin, (yyvsp[(1) - (1)].ptrval)); ;}
    break;

  case 128:

    {
		(yyval.nodeval) = node ((yyvsp[(3) - (4)].nodeval), Node_func_call, make_string((yyvsp[(1) - (4)].sval), strlen((yyvsp[(1) - (4)].sval))));
	  ;}
    break;

  case 129:

    { (yyval.nodeval) = node ((yyvsp[(2) - (2)].nodeval), Node_preincrement, (NODE *)NULL); ;}
    break;

  case 130:

    { (yyval.nodeval) = node ((yyvsp[(2) - (2)].nodeval), Node_predecrement, (NODE *)NULL); ;}
    break;

  case 131:

    { (yyval.nodeval) = node ((yyvsp[(1) - (2)].nodeval), Node_postincrement, (NODE *)NULL); ;}
    break;

  case 132:

    { (yyval.nodeval) = node ((yyvsp[(1) - (2)].nodeval), Node_postdecrement, (NODE *)NULL); ;}
    break;

  case 133:

    { (yyval.nodeval) = (yyvsp[(1) - (1)].nodeval); ;}
    break;

  case 134:

    { (yyval.nodeval) = (yyvsp[(1) - (1)].nodeval); ;}
    break;

  case 135:

    { (yyval.nodeval) = (yyvsp[(1) - (1)].nodeval); ;}
    break;

  case 136:

    { (yyval.nodeval) = node ((yyvsp[(1) - (3)].nodeval), Node_exp, (yyvsp[(3) - (3)].nodeval)); ;}
    break;

  case 137:

    { (yyval.nodeval) = node ((yyvsp[(1) - (3)].nodeval), Node_times, (yyvsp[(3) - (3)].nodeval)); ;}
    break;

  case 138:

    { (yyval.nodeval) = node ((yyvsp[(1) - (3)].nodeval), Node_quotient, (yyvsp[(3) - (3)].nodeval)); ;}
    break;

  case 139:

    { (yyval.nodeval) = node ((yyvsp[(1) - (3)].nodeval), Node_mod, (yyvsp[(3) - (3)].nodeval)); ;}
    break;

  case 140:

    { (yyval.nodeval) = node ((yyvsp[(1) - (3)].nodeval), Node_plus, (yyvsp[(3) - (3)].nodeval)); ;}
    break;

  case 141:

    { (yyval.nodeval) = node ((yyvsp[(1) - (3)].nodeval), Node_minus, (yyvsp[(3) - (3)].nodeval)); ;}
    break;

  case 142:

    { (yyval.nodeval) = node ((yyvsp[(2) - (2)].nodeval), Node_unary_minus, (NODE *)NULL); ;}
    break;

  case 143:

    { (yyval.nodeval) = (yyvsp[(2) - (2)].nodeval); ;}
    break;

  case 144:

    { (yyval.nodeval) = NULL; ;}
    break;

  case 145:

    { (yyval.nodeval) = (yyvsp[(1) - (1)].nodeval); ;}
    break;

  case 146:

    { want_assign = 1; (yyval.nodeval) = variable ((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 147:

    { want_assign = 1; (yyval.nodeval) = node (variable((yyvsp[(1) - (4)].sval)), Node_subscript, (yyvsp[(3) - (4)].nodeval)); ;}
    break;

  case 148:

    { want_assign = 1; (yyval.nodeval) = node ((yyvsp[(2) - (2)].nodeval), Node_field_spec, (NODE *)NULL); ;}
    break;

  case 150:

    { yyerrok; ;}
    break;

  case 151:

    { (yyval.nodetypeval) = Node_illegal; yyerrok; ;}
    break;

  case 154:

    { yyerrok; ;}
    break;

  case 155:

    { (yyval.nodetypeval) = Node_illegal; yyerrok; ;}
    break;


/* Line 1267 of yacc.c.  */

      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}





struct token {
	char *operator;		/* text to match */
	NODETYPE value;		/* node type */
	int class;		/* lexical class */
	short nostrict;		/* ignore if in strict compatibility mode */
	NODE *(*ptr) ();	/* function that implements this keyword */
};

extern NODE
	*do_exp(),	*do_getline(),	*do_index(),	*do_length(),
	*do_sqrt(),	*do_log(),	*do_sprintf(),	*do_substr(),
	*do_split(),	*do_system(),	*do_int(),	*do_close(),
	*do_atan2(),	*do_sin(),	*do_cos(),	*do_rand(),
	*do_srand(),	*do_match(),	*do_tolower(),	*do_toupper(),
	*do_sub(),	*do_gsub();

/* Special functions for debugging */
#ifdef DEBUG
NODE *do_prvars(), *do_bp();
#endif

/* Tokentab is sorted ascii ascending order, so it can be binary searched. */

static struct token tokentab[] = {
	{ "BEGIN",	Node_illegal,		LEX_BEGIN,	0,	0 },
	{ "END",	Node_illegal,		LEX_END,	0,	0 },
	{ "atan2",	Node_builtin,		LEX_BUILTIN,	0,	do_atan2 },
#ifdef DEBUG
	{ "bp",		Node_builtin,		LEX_BUILTIN,	0,	do_bp },
#endif
	{ "break",	Node_K_break,		LEX_BREAK,	0,	0 },
	{ "close",	Node_builtin,		LEX_BUILTIN,	0,	do_close },
	{ "continue",	Node_K_continue,	LEX_CONTINUE,	0,	0 },
	{ "cos",	Node_builtin,		LEX_BUILTIN,	0,	do_cos },
	{ "delete",	Node_K_delete,		LEX_DELETE,	0,	0 },
	{ "do",		Node_K_do,		LEX_DO,		0,	0 },
	{ "else",	Node_illegal,		LEX_ELSE,	0,	0 },
	{ "exit",	Node_K_exit,		LEX_EXIT,	0,	0 },
	{ "exp",	Node_builtin,		LEX_BUILTIN,	0,	do_exp },
	{ "for",	Node_K_for,		LEX_FOR,	0,	0 },
	{ "func",	Node_K_function,	LEX_FUNCTION,	0,	0 },
	{ "function",	Node_K_function,	LEX_FUNCTION,	0,	0 },
	{ "getline",	Node_K_getline,		LEX_GETLINE,	0,	0 },
	{ "gsub",	Node_builtin,		LEX_BUILTIN,	0,	do_gsub },
	{ "if",		Node_K_if,		LEX_IF,		0,	0 },
	{ "in",		Node_illegal,		LEX_IN,		0,	0 },
	{ "index",	Node_builtin,		LEX_BUILTIN,	0,	do_index },
	{ "int",	Node_builtin,		LEX_BUILTIN,	0,	do_int },
	{ "length",	Node_builtin,		LEX_LENGTH,	0,	do_length },
	{ "log",	Node_builtin,		LEX_BUILTIN,	0,	do_log },
	{ "match",	Node_builtin,		LEX_BUILTIN,	0,	do_match },
	{ "next",	Node_K_next,		LEX_NEXT,	0,	0 },
	{ "print",	Node_K_print,		LEX_PRINT,	0,	0 },
	{ "printf",	Node_K_printf,		LEX_PRINTF,	0,	0 },
#ifdef DEBUG
	{ "prvars",	Node_builtin,		LEX_BUILTIN,	0,	do_prvars },
#endif
	{ "rand",	Node_builtin,		LEX_BUILTIN,	0,	do_rand },
	{ "return",	Node_K_return,		LEX_RETURN,	0,	0 },
	{ "sin",	Node_builtin,		LEX_BUILTIN,	0,	do_sin },
	{ "split",	Node_builtin,		LEX_BUILTIN,	0,	do_split },
	{ "sprintf",	Node_builtin,		LEX_BUILTIN,	0,	do_sprintf },
	{ "sqrt",	Node_builtin,		LEX_BUILTIN,	0,	do_sqrt },
	{ "srand",	Node_builtin,		LEX_BUILTIN,	0,	do_srand },
	{ "sub",	Node_builtin,		LEX_BUILTIN,	0,	do_sub },
	{ "substr",	Node_builtin,		LEX_BUILTIN,	0,	do_substr },
	{ "system",	Node_builtin,		LEX_BUILTIN,	0,	do_system },
	{ "tolower",	Node_builtin,		LEX_BUILTIN,	0,	do_tolower },
	{ "toupper",	Node_builtin,		LEX_BUILTIN,	0,	do_toupper },
	{ "while",	Node_K_while,		LEX_WHILE,	0,	0 },
};

static char *token_start;

/* VARARGS0 */
static void
yyerror(char * the_msg, ...)
{
	va_list args;
	char *mesg;
	register char *ptr, *beg;
	char *scan;

	errcount++;
	/* Find the current line in the input file */
	if (! lexptr) {
		beg = "(END OF FILE)";
		ptr = beg + 13;
	} else {
		if (*lexptr == '\n' && lexptr != lexptr_begin)
			--lexptr;
		for (beg = lexptr; beg != lexptr_begin && *beg != '\n'; --beg)
			;
		/* NL isn't guaranteed */
		for (ptr = lexptr; *ptr && *ptr != '\n'; ptr++)
			;
		if (beg != lexptr_begin)
			beg++;
	}
	msg("syntax error near line %d:\n%.*s", lineno, ptr - beg, beg);
	scan = beg;
	while (scan < token_start)
		if (*scan++ == '\t')
			putc('\t', stderr);
		else
			putc(' ', stderr);
	putc('^', stderr);
	putc(' ', stderr);
	va_start(args, the_msg);
	mesg = va_arg(args, char *);
	vfprintf(stderr, mesg, args);
	va_end(args);
	putc('\n', stderr);
	exit(1);
}

/*
 * Parse a C escape sequence.  STRING_PTR points to a variable containing a
 * pointer to the string to parse.  That pointer is updated past the
 * characters we use.  The value of the escape sequence is returned. 
 *
 * A negative value means the sequence \ newline was seen, which is supposed to
 * be equivalent to nothing at all. 
 *
 * If \ is followed by a null character, we return a negative value and leave
 * the string pointer pointing at the null character. 
 *
 * If \ is followed by 000, we return 0 and leave the string pointer after the
 * zeros.  A value of 0 does not mean end of string.  
 */

int
parse_escape(string_ptr)
char **string_ptr;
{
	register int c = *(*string_ptr)++;
	register int i;
	register int count;

	switch (c) {
	case 'a':
		return BELL;
	case 'b':
		return '\b';
	case 'f':
		return '\f';
	case 'n':
		return '\n';
	case 'r':
		return '\r';
	case 't':
		return '\t';
	case 'v':
		return '\v';
	case '\n':
		return -2;
	case 0:
		(*string_ptr)--;
		return -1;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
		i = c - '0';
		count = 0;
		while (++count < 3) {
			if ((c = *(*string_ptr)++) >= '0' && c <= '7') {
				i *= 8;
				i += c - '0';
			} else {
				(*string_ptr)--;
				break;
			}
		}
		return i;
	case 'x':
		i = 0;
		while (1) {
			if (isxdigit((c = *(*string_ptr)++))) {
				if (isdigit(c))
					i += c - '0';
				else if (isupper(c))
					i += c - 'A' + 10;
				else
					i += c - 'a' + 10;
			} else {
				(*string_ptr)--;
				break;
			}
		}
		return i;
	default:
		return c;
	}
}

/*
 * Read the input and turn it into tokens. Input is now read from a file
 * instead of from malloc'ed memory. The main program takes a program
 * passed as a command line argument and writes it to a temp file. Otherwise
 * the file name is made available in an external variable.
 */

static int
yylex()
{
	register int c;
	register int namelen;
	register char *tokstart;
	char *tokkey;
	static did_newline = 0;	/* the grammar insists that actions end
				 * with newlines.  This was easier than
				 * hacking the grammar. */
	int seen_e = 0;		/* These are for numbers */
	int seen_point = 0;
	int esc_seen;
	extern char **sourcefile;
	extern int tempsource, numfiles;
	static int file_opened = 0;
	static FILE *fin;
	static char cbuf[BUFSIZ];
	int low, mid, high;
#ifdef DEBUG
	extern int debugging;
#endif

	if (! file_opened) {
		file_opened = 1;
#ifdef DEBUG
		if (debugging) {
			int i;

			for (i = 0; i <= numfiles; i++)
				fprintf (stderr, "sourcefile[%d] = %s\n", i,
						sourcefile[i]);
		}
#endif
	nextfile:
		if ((fin = pathopen (sourcefile[++curinfile])) == NULL)
			fatal("cannot open `%s' for reading (%s)",
				sourcefile[curinfile],
				strerror(errno));
		*(lexptr = cbuf) = '\0';
		/*
		 * immediately unlink the tempfile so that it will
		 * go away cleanly if we bomb.
		 */
		if (tempsource && curinfile == 0)
			(void) unlink (sourcefile[curinfile]);
	}

retry:
	if (! *lexptr)
		if (fgets (cbuf, sizeof cbuf, fin) == NULL) {
			if (fin != NULL)
				fclose (fin);	/* be neat and clean */
			if (curinfile < numfiles)
				goto nextfile;
			return 0;
		} else
			lexptr = lexptr_begin = cbuf;

	if (want_regexp) {
		int in_brack = 0;

		want_regexp = 0;
		token_start = tokstart = lexptr;
		while (c = *lexptr++) {
			switch (c) {
			case '[':
				in_brack = 1;
				break;
			case ']':
				in_brack = 0;
				break;
			case '\\':
				if (*lexptr++ == '\0') {
					yyerror("unterminated regexp ends with \\");
					return ERROR;
				} else if (lexptr[-1] == '\n')
					goto retry;
				break;
			case '/':	/* end of the regexp */
				if (in_brack)
					break;

				lexptr--;
				yylval.sval = tokstart;
				return REGEXP;
			case '\n':
				lineno++;
			case '\0':
				lexptr--;	/* so error messages work */
				yyerror("unterminated regexp");
				return ERROR;
			}
		}
	}

	if (*lexptr == '\n') {
		lexptr++;
		lineno++;
		return NEWLINE;
	}

	while (*lexptr == ' ' || *lexptr == '\t')
		lexptr++;

	token_start = tokstart = lexptr;

	switch (c = *lexptr++) {
	case 0:
		return 0;

	case '\n':
		lineno++;
		return NEWLINE;

	case '#':		/* it's a comment */
		while (*lexptr != '\n' && *lexptr != '\0')
			lexptr++;
		goto retry;

	case '\\':
		if (*lexptr == '\n') {
			lineno++;
			lexptr++;
			goto retry;
		} else
			break;
	case ')':
	case ']':
	case '(':	
	case '[':
	case '$':
	case ';':
	case ':':
	case '?':

		/*
		 * set node type to ILLEGAL because the action should set it
		 * to the right thing 
		 */
		yylval.nodetypeval = Node_illegal;
		return c;

	case '{':
	case ',':
		yylval.nodetypeval = Node_illegal;
		return c;

	case '*':
		if (*lexptr == '=') {
			yylval.nodetypeval = Node_assign_times;
			lexptr++;
			return ASSIGNOP;
		} else if (*lexptr == '*') {	/* make ** and **= aliases
						 * for ^ and ^= */
			if (lexptr[1] == '=') {
				yylval.nodetypeval = Node_assign_exp;
				lexptr += 2;
				return ASSIGNOP;
			} else {
				yylval.nodetypeval = Node_illegal;
				lexptr++;
				return '^';
			}
		}
		yylval.nodetypeval = Node_illegal;
		return c;

	case '/':
		if (want_assign && *lexptr == '=') {
			yylval.nodetypeval = Node_assign_quotient;
			lexptr++;
			return ASSIGNOP;
		}
		yylval.nodetypeval = Node_illegal;
		return c;

	case '%':
		if (*lexptr == '=') {
			yylval.nodetypeval = Node_assign_mod;
			lexptr++;
			return ASSIGNOP;
		}
		yylval.nodetypeval = Node_illegal;
		return c;

	case '^':
		if (*lexptr == '=') {
			yylval.nodetypeval = Node_assign_exp;
			lexptr++;
			return ASSIGNOP;
		}
		yylval.nodetypeval = Node_illegal;
		return c;

	case '+':
		if (*lexptr == '=') {
			yylval.nodetypeval = Node_assign_plus;
			lexptr++;
			return ASSIGNOP;
		}
		if (*lexptr == '+') {
			yylval.nodetypeval = Node_illegal;
			lexptr++;
			return INCREMENT;
		}
		yylval.nodetypeval = Node_illegal;
		return c;

	case '!':
		if (*lexptr == '=') {
			yylval.nodetypeval = Node_notequal;
			lexptr++;
			return RELOP;
		}
		if (*lexptr == '~') {
			yylval.nodetypeval = Node_nomatch;
			lexptr++;
			return MATCHOP;
		}
		yylval.nodetypeval = Node_illegal;
		return c;

	case '<':
		if (*lexptr == '=') {
			yylval.nodetypeval = Node_leq;
			lexptr++;
			return RELOP;
		}
		yylval.nodetypeval = Node_less;
		return c;

	case '=':
		if (*lexptr == '=') {
			yylval.nodetypeval = Node_equal;
			lexptr++;
			return RELOP;
		}
		yylval.nodetypeval = Node_assign;
		return ASSIGNOP;

	case '>':
		if (*lexptr == '=') {
			yylval.nodetypeval = Node_geq;
			lexptr++;
			return RELOP;
		} else if (*lexptr == '>') {
			yylval.nodetypeval = Node_redirect_append;
			lexptr++;
			return APPEND_OP;
		}
		yylval.nodetypeval = Node_greater;
		return c;

	case '~':
		yylval.nodetypeval = Node_match;
		return MATCHOP;

	case '}':
		/*
		 * Added did newline stuff.  Easier than
		 * hacking the grammar
		 */
		if (did_newline) {
			did_newline = 0;
			return c;
		}
		did_newline++;
		--lexptr;
		return NEWLINE;

	case '"':
		esc_seen = 0;
		while (*lexptr != '\0') {
			switch (*lexptr++) {
			case '\\':
				esc_seen = 1;
				if (*lexptr == '\n')
					yyerror("newline in string");
				if (*lexptr++ != '\0')
					break;
				/* fall through */
			case '\n':
				lexptr--;
				yyerror("unterminated string");
				return ERROR;
			case '"':
				yylval.nodeval = make_str_node(tokstart + 1,
						lexptr-tokstart-2, esc_seen);
				yylval.nodeval->flags |= PERM;
				return YSTRING;
			}
		}
		return ERROR;

	case '-':
		if (*lexptr == '=') {
			yylval.nodetypeval = Node_assign_minus;
			lexptr++;
			return ASSIGNOP;
		}
		if (*lexptr == '-') {
			yylval.nodetypeval = Node_illegal;
			lexptr++;
			return DECREMENT;
		}
		yylval.nodetypeval = Node_illegal;
		return c;

	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case '.':
		/* It's a number */
		for (namelen = 0; (c = tokstart[namelen]) != '\0'; namelen++) {
			switch (c) {
			case '.':
				if (seen_point)
					goto got_number;
				++seen_point;
				break;
			case 'e':
			case 'E':
				if (seen_e)
					goto got_number;
				++seen_e;
				if (tokstart[namelen + 1] == '-' ||
				    tokstart[namelen + 1] == '+')
					namelen++;
				break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				break;
			default:
				goto got_number;
			}
		}

got_number:
		lexptr = tokstart + namelen;
		/*
		yylval.nodeval = make_string(tokstart, namelen);
		(void) force_number(yylval.nodeval);
		*/
		yylval.nodeval = make_number(atof(tokstart));
		yylval.nodeval->flags |= PERM;
		return NUMBER;

	case '&':
		if (*lexptr == '&') {
			yylval.nodetypeval = Node_and;
			while (c = *++lexptr) {
				if (c == '#')
					while ((c = *++lexptr) != '\n'
					       && c != '\0')
						;
				if (c == '\n')
					lineno++;
				else if (! isspace(c))
					break;
			}
			return LEX_AND;
		}
		return ERROR;

	case '|':
		if (*lexptr == '|') {
			yylval.nodetypeval = Node_or;
			while (c = *++lexptr) {
				if (c == '#')
					while ((c = *++lexptr) != '\n'
					       && c != '\0')
						;
				if (c == '\n')
					lineno++;
				else if (! isspace(c))
					break;
			}
			return LEX_OR;
		}
		yylval.nodetypeval = Node_illegal;
		return c;
	}

	if (c != '_' && ! isalpha(c)) {
		yyerror("Invalid char '%c' in expression\n", c);
		return ERROR;
	}

	/* it's some type of name-type-thing.  Find its length */
	for (namelen = 0; is_identchar(tokstart[namelen]); namelen++)
		/* null */ ;
	emalloc(tokkey, char *, namelen+1, "yylex");
	memcpy(tokkey, tokstart, namelen);
	tokkey[namelen] = '\0';

	/* See if it is a special token.  */
	low = 0;
	high = (sizeof (tokentab) / sizeof (tokentab[0])) - 1;
	while (low <= high) {
		int i, c;

		mid = (low + high) / 2;
		c = *tokstart - tokentab[mid].operator[0];
		i = c ? c : strcmp (tokkey, tokentab[mid].operator);

		if (i < 0) {		/* token < mid */
			high = mid - 1;
		} else if (i > 0) {	/* token > mid */
			low = mid + 1;
		} else {
			lexptr = tokstart + namelen;
			if (strict && tokentab[mid].nostrict)
				break;
			if (tokentab[mid].class == LEX_BUILTIN
			    || tokentab[mid].class == LEX_LENGTH)
				yylval.ptrval = tokentab[mid].ptr;
			else
				yylval.nodetypeval = tokentab[mid].value;
			return tokentab[mid].class;
		}
	}

	/* It's a name.  See how long it is.  */
	yylval.sval = tokkey;
	lexptr = tokstart + namelen;
	if (*lexptr == '(')
		return FUNC_CALL;
	else
		return NAME;
}

#ifndef DEFPATH
#ifdef MSDOS
#define DEFPATH	"."
#define ENVSEP	';'
#else
#define DEFPATH	".:/usr/lib/awk:/usr/local/lib/awk"
#define ENVSEP	':'
#endif
#endif

static FILE *
pathopen (file)
char *file;
{
	static char *savepath = DEFPATH;
	static int first = 1;
	char *awkpath, *cp;
	char trypath[BUFSIZ];
	FILE *fp;
#ifdef DEBUG
	extern int debugging;
#endif
	int fd;

	if (strcmp (file, "-") == 0)
		return (stdin);

	if (strict)
		return (fopen (file, "r"));

	if (first) {
		first = 0;
		if ((awkpath = getenv ("AWKPATH")) != NULL && *awkpath)
			savepath = awkpath;	/* used for restarting */
	}
	awkpath = savepath;

	/* some kind of path name, no search */
#ifndef MSDOS
	if (strchr (file, '/') != NULL)
#else
	if (strchr (file, '/') != NULL || strchr (file, '\\') != NULL
			|| strchr (file, ':') != NULL)
#endif
		return ( (fd = devopen (file, "r")) >= 0 ?
				fdopen(fd, "r") :
				NULL);

	do {
		trypath[0] = '\0';
		/* this should take into account limits on size of trypath */
		for (cp = trypath; *awkpath && *awkpath != ENVSEP; )
			*cp++ = *awkpath++;

		if (cp != trypath) {	/* nun-null element in path */
			*cp++ = '/';
			strcpy (cp, file);
		} else
			strcpy (trypath, file);
#ifdef DEBUG
		if (debugging)
			fprintf(stderr, "trying: %s\n", trypath);
#endif
		if ((fd = devopen (trypath, "r")) >= 0
		    && (fp = fdopen(fd, "r")) != NULL)
			return (fp);

		/* no luck, keep going */
		if(*awkpath == ENVSEP && awkpath[1] != '\0')
			awkpath++;	/* skip colon */
	} while (*awkpath);
#ifdef MSDOS
	/*
	 * Under DOS (and probably elsewhere) you might have one of the awk
	 * paths defined, WITHOUT the current working directory in it.
	 * Therefore you should try to open the file in the current directory.
	 */
	return ( (fd = devopen(file, "r")) >= 0 ? fdopen(fd, "r") : NULL);
#else
	return (NULL);
#endif
}

static NODE *
node_common(op)
NODETYPE op;
{
	register NODE *r;
	extern int numfiles;
	extern int tempsource;
	extern char **sourcefile;

	r = newnode(op);
	r->source_line = lineno;
	if (numfiles > -1 && ! tempsource)
		r->source_file = sourcefile[curinfile];
	else
		r->source_file = NULL;
	return r;
}

/*
 * This allocates a node with defined lnode and rnode. 
 * This should only be used by yyparse+co while reading in the program 
 */
NODE *
node(left, op, right)
NODE *left, *right;
NODETYPE op;
{
	register NODE *r;

	r = node_common(op);
	r->lnode = left;
	r->rnode = right;
	return r;
}

/*
 * This allocates a node with defined subnode and proc
 * Otherwise like node()
 */
static NODE *
snode(subn, op, procp)
NODETYPE op;
NODE *(*procp) ();
NODE *subn;
{
	register NODE *r;

	r = node_common(op);
	r->subnode = subn;
	r->proc = procp;
	return r;
}

/*
 * This allocates a Node_line_range node with defined condpair and
 * zeroes the trigger word to avoid the temptation of assuming that calling
 * 'node( foo, Node_line_range, 0)' will properly initialize 'triggered'. 
 */
/* Otherwise like node() */
static NODE *
mkrangenode(cpair)
NODE *cpair;
{
	register NODE *r;

	r = newnode(Node_line_range);
	r->condpair = cpair;
	r->triggered = 0;
	return r;
}

/* Build a for loop */
static NODE *
make_for_loop(init, cond, incr)
NODE *init, *cond, *incr;
{
	register FOR_LOOP_HEADER *r;
	NODE *n;

	emalloc(r, FOR_LOOP_HEADER *, sizeof(FOR_LOOP_HEADER), "make_for_loop");
	n = newnode(Node_illegal);
	r->init = init;
	r->cond = cond;
	r->incr = incr;
	n->sub.nodep.r.hd = r;
	return n;
}

/*
 * Install a name in the hash table specified, even if it is already there.
 * Name stops with first non alphanumeric. Caller must check against
 * redefinition if that is desired. 
 */
NODE *
install(table, name, value)
NODE **table;
char *name;
NODE *value;
{
	register NODE *hp;
	register int len, bucket;
	register char *p;

	len = 0;
	p = name;
	while (is_identchar(*p))
		p++;
	len = p - name;

	hp = newnode(Node_hashnode);
	bucket = hashf(name, len, HASHSIZE);
	hp->hnext = table[bucket];
	table[bucket] = hp;
	hp->hlength = len;
	hp->hvalue = value;
	emalloc(hp->hname, char *, len + 1, "install");
	memcpy(hp->hname, name, len);
	hp->hname[len] = '\0';
	return hp->hvalue;
}

/*
 * find the most recent hash node for name name (ending with first
 * non-identifier char) installed by install 
 */
NODE *
lookup(table, name)
NODE **table;
char *name;
{
	register char *bp;
	register NODE *bucket;
	register int len;

	for (bp = name; is_identchar(*bp); bp++)
		;
	len = bp - name;
	bucket = table[hashf(name, len, HASHSIZE)];
	while (bucket) {
		if (bucket->hlength == len && STREQN(bucket->hname, name, len))
			return bucket->hvalue;
		bucket = bucket->hnext;
	}
	return NULL;
}

#define HASHSTEP(old, c) ((old << 1) + c)
#define MAKE_POS(v) (v & ~0x80000000)	/* make number positive */

/*
 * return hash function on name.
 */
static int
hashf(name, len, hashsize)
register char *name;
register int len;
int hashsize;
{
	register int r = 0;

	while (len--)
		r = HASHSTEP(r, *name++);

	r = MAKE_POS(r) % hashsize;
	return r;
}

/*
 * Add new to the rightmost branch of LIST.  This uses n^2 time, so we make
 * a simple attempt at optimizing it.
 */
static NODE *
append_right(list, new)
NODE *list, *new;

{
	register NODE *oldlist;
	static NODE *savefront = NULL, *savetail = NULL;

	oldlist = list;
	if (savefront == oldlist) {
		savetail = savetail->rnode = new;
		return oldlist;
	} else
		savefront = oldlist;
	while (list->rnode != NULL)
		list = list->rnode;
	savetail = list->rnode = new;
	return oldlist;
}

/*
 * check if name is already installed;  if so, it had better have Null value,
 * in which case def is added as the value. Otherwise, install name with def
 * as value. 
 */
static void
func_install(params, def)
NODE *params;
NODE *def;
{
	NODE *r;

	pop_params(params->rnode);
	pop_var(params, 0);
	r = lookup(variables, params->param);
	if (r != NULL) {
		fatal("function name `%s' previously defined", params->param);
	} else
		(void) install(variables, params->param,
			node(params, Node_func, def));
}

static void
pop_var(np, freeit)
NODE *np;
int freeit;
{
	register char *bp;
	register NODE *bucket, **save;
	register int len;
	char *name;

	name = np->param;
	for (bp = name; is_identchar(*bp); bp++)
		;
	len = bp - name;
	save = &(variables[hashf(name, len, HASHSIZE)]);
	bucket = *save;
	while (bucket != NULL) {
	        NODE *next = bucket->hnext;
	    
/*	for (bucket = *save; bucket; bucket = bucket->hnext) {
*/
	    
		if (len == bucket->hlength && STREQN(bucket->hname, name, len)) {
			*save = bucket->hnext;
			save = &(bucket->hnext);
			free(bucket->hname);
			freenode(bucket);
			if (freeit)
				free(np->param);
			return;
		} else {
			save = &(bucket->hnext);
		}
		bucket = next;
	}
}

static void
pop_params(params)
NODE *params;
{
	register NODE *np;

	for (np = params; np != NULL; np = np->rnode)
		pop_var(np, 1);
}

static NODE *
make_param(name)
char *name;
{
	NODE *r;

	r = newnode(Node_param_list);
	r->param = name;
	r->rnode = NULL;
	r->param_cnt = param_counter++;
	return (install(variables, name, r));
}

/* Name points to a variable name.  Make sure its in the symbol table */
NODE *
variable(name)
char *name;
{
	register NODE *r;

	if ((r = lookup(variables, name)) == NULL)
		r = install(variables, name,
			node(Nnull_string, Node_var, (NODE *) NULL));
	return r;
}

