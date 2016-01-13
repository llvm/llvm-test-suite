#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140101

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "gram.y"
char rcsid_gram[] = "$Id$";

#include <stdio.h>
#include "b.h"
#include "fe.h"
#line 9 "gram.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int y_int;
	char *y_string;
	Arity y_arity;
	Binding y_binding;
	PatternAST y_patternAST;
	RuleAST y_ruleAST;
	List y_list;
	IntList y_intlist;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 43 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define ERROR 257
#define K_TERM 258
#define K_GRAM 259
#define K_START 260
#define K_PPERCENT 261
#define INT 262
#define ID 263
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,   11,    7,    7,    1,    1,    1,   10,   10,
    9,    9,    2,    8,    8,    5,    6,    6,    6,    3,
    3,    4,    4,    4,
};
static const short yylen[] = {                            2,
    1,    2,    3,    0,    2,    2,    2,    2,    0,    2,
    0,    2,    3,    0,    2,    7,    1,    4,    6,    0,
    4,    0,    3,    2,
};
static const short yydefred[] = {                         4,
    0,    0,    0,   11,    9,    0,   14,    5,    2,    0,
    0,    8,    0,    0,   12,   10,    0,   15,    0,    0,
   13,    0,    0,    0,    0,    0,    0,   18,    0,    0,
    0,    0,    0,   16,   19,    0,    0,    0,   24,    0,
   21,   23,
};
static const short yydgoto[] = {                          1,
    8,   15,   31,   38,   18,   23,    2,   13,   10,   11,
    3,
};
static const short yysindex[] = {                         0,
    0, -247, -252,    0,    0, -244,    0,    0,    0, -242,
 -236,    0, -234,  -41,    0,    0,  -28,    0, -231, -230,
    0,  -12,  -29, -230, -228,  -37,   -5,    0, -230, -226,
  -22,   -3,  -44,    0,    0,  -44, -223,   -1,    0,  -44,
    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,   41,    0,    0,    0,    0,    0,    0, -243,
 -235,    0,    1,    0,    0,    0,    0,    0,    0,    0,
    0,  -39,    0,    0,    0,    0,  -17,    0,    0,    0,
    0,    0,    2,    0,    0,    2,    0,    0,    0,    2,
    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,    0,  -30,    0,  -21,    0,    0,    0,    0,
    0,
};
#define YYTABLESIZE 262
static const short yytable[] = {                         37,
    3,   17,   26,   28,   17,   39,   29,   32,    9,   42,
    4,    5,    6,    7,    6,    6,    6,    6,   12,   19,
   14,   17,    7,    7,    7,    7,   16,   24,   17,   20,
   21,   25,   22,   27,   30,   33,   34,   35,   40,   41,
    1,   20,   22,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   36,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    3,
};
static const short yycheck[] = {                         44,
    0,   41,   24,   41,   44,   36,   44,   29,  261,   40,
  258,  259,  260,  261,  258,  259,  260,  261,  263,   61,
  263,   61,  258,  259,  260,  261,  263,   40,  263,   58,
  262,   61,  263,  262,   40,  262,   59,   41,  262,   41,
    0,   59,   41,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  261,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 263
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,"':'","';'",0,"'='",
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ERROR",
"K_TERM","K_GRAM","K_START","K_PPERCENT","INT","ID","illegal-symbol",
};
static const char *yyrule[] = {
"$accept : full",
"full : spec",
"full : spec K_PPERCENT",
"spec : decls K_PPERCENT rules",
"decls :",
"decls : decls decl",
"decl : K_TERM bindinglist",
"decl : K_GRAM grammarlist",
"decl : K_START ID",
"grammarlist :",
"grammarlist : grammarlist ID",
"bindinglist :",
"bindinglist : bindinglist binding",
"binding : ID '=' INT",
"rules :",
"rules : rules rule",
"rule : ID ':' pattern '=' INT cost ';'",
"pattern : ID",
"pattern : ID '(' pattern ')'",
"pattern : ID '(' pattern ',' pattern ')'",
"cost :",
"cost : '(' INT costtail ')'",
"costtail :",
"costtail : ',' INT costtail",
"costtail : INT costtail",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 2:
#line 44 "gram.y"
	{ yyfinished(); }
break;
case 3:
#line 48 "gram.y"
	{ doSpec(yystack.l_mark[-2].y_list, yystack.l_mark[0].y_list); }
break;
case 4:
#line 51 "gram.y"
	{ yyval.y_list = 0; }
break;
case 5:
#line 52 "gram.y"
	{ yyval.y_list = newList(yystack.l_mark[0].y_arity, yystack.l_mark[-1].y_list); }
break;
case 6:
#line 55 "gram.y"
	{ yyval.y_arity = newArity(-1, yystack.l_mark[0].y_list); }
break;
case 7:
#line 56 "gram.y"
	{ yyval.y_arity = 0; doGram(yystack.l_mark[0].y_list); }
break;
case 8:
#line 57 "gram.y"
	{ yyval.y_arity = 0; doStart(yystack.l_mark[0].y_string); }
break;
case 9:
#line 60 "gram.y"
	{ yyval.y_list = 0; }
break;
case 10:
#line 61 "gram.y"
	{ yyval.y_list = newList(yystack.l_mark[0].y_string, yystack.l_mark[-1].y_list); }
break;
case 11:
#line 64 "gram.y"
	{ yyval.y_list = 0; }
break;
case 12:
#line 65 "gram.y"
	{ yyval.y_list = newList(yystack.l_mark[0].y_binding, yystack.l_mark[-1].y_list); }
break;
case 13:
#line 68 "gram.y"
	{ yyval.y_binding = newBinding(yystack.l_mark[-2].y_string, yystack.l_mark[0].y_int); }
break;
case 14:
#line 71 "gram.y"
	{ yyval.y_list = 0; }
break;
case 15:
#line 72 "gram.y"
	{ yyval.y_list = newList(yystack.l_mark[0].y_ruleAST, yystack.l_mark[-1].y_list); }
break;
case 16:
#line 75 "gram.y"
	{ yyval.y_ruleAST = newRuleAST(yystack.l_mark[-6].y_string, yystack.l_mark[-4].y_patternAST, yystack.l_mark[-2].y_int, yystack.l_mark[-1].y_intlist); }
break;
case 17:
#line 78 "gram.y"
	{ yyval.y_patternAST = newPatternAST(yystack.l_mark[0].y_string, 0); }
break;
case 18:
#line 79 "gram.y"
	{ yyval.y_patternAST = newPatternAST(yystack.l_mark[-3].y_string, newList(yystack.l_mark[-1].y_patternAST,0)); }
break;
case 19:
#line 80 "gram.y"
	{ yyval.y_patternAST = newPatternAST(yystack.l_mark[-5].y_string, newList(yystack.l_mark[-3].y_patternAST, newList(yystack.l_mark[-1].y_patternAST, 0))); }
break;
case 20:
#line 83 "gram.y"
	{ yyval.y_intlist = 0; }
break;
case 21:
#line 84 "gram.y"
	{ yyval.y_intlist = newIntList(yystack.l_mark[-2].y_int, yystack.l_mark[-1].y_intlist); }
break;
case 22:
#line 87 "gram.y"
	{ yyval.y_intlist = 0; }
break;
case 23:
#line 88 "gram.y"
	{ yyval.y_intlist = newIntList(yystack.l_mark[-1].y_int, yystack.l_mark[0].y_intlist); }
break;
case 24:
#line 89 "gram.y"
	{ yyval.y_intlist = newIntList(yystack.l_mark[-1].y_int, yystack.l_mark[0].y_intlist); }
break;
#line 555 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
