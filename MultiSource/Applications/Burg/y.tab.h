#define ERROR 257
#define K_TERM 258
#define K_GRAM 259
#define K_START 260
#define K_PPERCENT 261
#define INT 262
#define ID 263
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
extern YYSTYPE yylval;
