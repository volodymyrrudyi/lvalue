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
     TELSE = 262,
     TCOLON = 263,
     TCEQ = 264,
     TCNE = 265,
     TCLT = 266,
     TCLE = 267,
     TCGT = 268,
     TCGE = 269,
     TEQUAL = 270,
     TDO = 271,
     TEND = 272,
     TLPAREN = 273,
     TRPAREN = 274,
     TLBRACE = 275,
     TRBRACE = 276,
     TCOMMA = 277,
     TDOT = 278,
     TWHILE = 279,
     TIF = 280,
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
#define TELSE 262
#define TCOLON 263
#define TCEQ 264
#define TCNE 265
#define TCLT 266
#define TCLE 267
#define TCGT 268
#define TCGE 269
#define TEQUAL 270
#define TDO 271
#define TEND 272
#define TLPAREN 273
#define TRPAREN 274
#define TLBRACE 275
#define TRBRACE 276
#define TCOMMA 277
#define TDOT 278
#define TWHILE 279
#define TIF 280
#define TDEF 281
#define TPLUS 282
#define TMINUS 283
#define TMUL 284
#define TDIV 285




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 69 "parse.ypp"
{
    AST_Node *node;
    AST_Block *block;
    AST_Expression *expr;
    AST_Statement *stmt;
    AST_Identifier *ident;
    AST_VariableDeclaration *var_decl;
    std::vector<AST_VariableDeclaration*> *varvec;
    std::vector<AST_Expression*> *exprvec;
    std::string *string;
    int token;
}
/* Line 1529 of yacc.c.  */
#line 122 "parse.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

