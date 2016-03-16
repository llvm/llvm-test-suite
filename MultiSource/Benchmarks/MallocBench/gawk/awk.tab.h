/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */

	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

