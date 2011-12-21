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
     TIDENTIFIER = 258,
     TINTEGER = 259,
     TDOUBLE = 260,
     TSTRING = 261,
     TIF = 262,
     TELSIF = 263,
     TELSE = 264,
     TCOLON = 265,
     TCEQ = 266,
     TCNE = 267,
     TCLT = 268,
     TCLE = 269,
     TCGT = 270,
     TCGE = 271,
     TEQUAL = 272,
     TDO = 273,
     TEND = 274,
     TLPAREN = 275,
     TRPAREN = 276,
     TLBRACE = 277,
     TRBRACE = 278,
     TCOMMA = 279,
     TDOT = 280,
     TDEF = 281,
     TPLUS = 282,
     TMINUS = 283,
     TMUL = 284,
     TDIV = 285
   };
#endif
/* Tokens.  */
#define TIDENTIFIER 258
#define TINTEGER 259
#define TDOUBLE 260
#define TSTRING 261
#define TIF 262
#define TELSIF 263
#define TELSE 264
#define TCOLON 265
#define TCEQ 266
#define TCNE 267
#define TCLT 268
#define TCLE 269
#define TCGT 270
#define TCGE 271
#define TEQUAL 272
#define TDO 273
#define TEND 274
#define TLPAREN 275
#define TRPAREN 276
#define TLBRACE 277
#define TRBRACE 278
#define TCOMMA 279
#define TDOT 280
#define TDEF 281
#define TPLUS 282
#define TMINUS 283
#define TMUL 284
#define TDIV 285




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 11 "parser.ypp"
{
    Node *node;
    NBlock *block;
    NExpression *expr;
    NStatement *stmt;
    NIdentifier *ident;
    NVariableDeclaration *var_decl;
    std::vector<NVariableDeclaration*> *varvec;
    std::vector<NExpression*> *exprvec;
    std::string *string;
    int token;
}
/* Line 1529 of yacc.c.  */
#line 122 "src/lvalue/lvalue-parser.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

