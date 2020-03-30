/* A Bison parser, made by GNU Bison 3.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_HOME_TYPHIGH_DESKTOP_OPENSOURCE_TCOLDB_BUILD_SRC_PARSER_SQL_TAB_HH_INCLUDED
# define YY_YY_HOME_TYPHIGH_DESKTOP_OPENSOURCE_TCOLDB_BUILD_SRC_PARSER_SQL_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 44 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"


#include <stdio.h>
#include <stdlib.h>
#include "ASTCreateIndexInfo.h"
#include "ASTCreateInfo.h"
#include "ASTCreator.h"
#include "ASTDeleteInfo.h"
#include "ASTDropIndexInfo.h"
#include "ASTDropTableInfo.h"
#include "ASTExit.h"
#include "ASTInsertInfo.h"
#include "ASTSelectInfo.h"
#include "ASTSetOutput.h"
#include "ASTShowTableInfo.h"
#include "ASTUpdateInfo.h"
#include "ColumnRef.h"
#include "defs.h"
#include "ExprNode.h"
#include "FieldDef.h"
#include "IAST.h"
#include "IASTNeedPlan.h"
#include "IASTNotNeedPlan.h"
#include "SQLParser.h"
#include "SQLParserResult.h"
#include "TableConstraint.h"
#include "TableFrom.h"
#include <iostream>
#include <memory>
#include <vector>


#line 81 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.hh"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TRUE = 258,
    FALSE = 259,
    NULL_TOKEN = 260,
    MIN = 261,
    MAX = 262,
    SUM = 263,
    AVG = 264,
    COUNT = 265,
    LIKE = 266,
    IS = 267,
    OR = 268,
    AND = 269,
    NOT = 270,
    NEQ = 271,
    GEQ = 272,
    LEQ = 273,
    INTEGER = 274,
    DOUBLE = 275,
    FLOAT = 276,
    CHAR = 277,
    VARCHAR = 278,
    DATE = 279,
    BOOL = 280,
    INTO = 281,
    FROM = 282,
    WHERE = 283,
    VALUES = 284,
    JOIN = 285,
    INNER = 286,
    OUTER = 287,
    LEFT = 288,
    RIGHT = 289,
    FULL = 290,
    ASC = 291,
    DESC = 292,
    ORDER = 293,
    BY = 294,
    IN = 295,
    ON = 296,
    AS = 297,
    DISTINCT = 298,
    GROUP = 299,
    USING = 300,
    INDEX = 301,
    TABLE = 302,
    DATABASE = 303,
    DEFAULT = 304,
    UNIQUE = 305,
    PRIMARY = 306,
    FOREIGN = 307,
    REFERENCES = 308,
    CHECK = 309,
    KEY = 310,
    OUTPUT = 311,
    USE = 312,
    CREATE = 313,
    DROP = 314,
    SELECT = 315,
    INSERT = 316,
    UPDATE = 317,
    DELETE = 318,
    SHOW = 319,
    SET = 320,
    EXIT = 321,
    IDENTIFIER = 322,
    DATE_LITERAL = 323,
    STRING_LITERAL = 324,
    FLOAT_LITERAL = 325,
    INT_LITERAL = 326
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 78 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"

//	std::string val_name;
	char *val_s;
	int   val_i;
	float val_f;
	bool  val_b;
	Parser::FieldType_t					field_type;				
	Parser::FieldDef*					field_def;
	Parser::FieldDefList*				field_defs;
	Parser::IAST*						ast;
	Parser::IASTNeedPlan*				ast_plan;
	Parser::IASTNotNeedPlan*			ast_noplan;
	Parser::ColumnRef*					column_ref;
	Parser::ColumnRefList*				column_refs;
	Parser::TableConstraint*			constraint;
	Parser::TableConstraintList*		constraints;
	Parser::ASTCreateInfo*				table_def;
	Parser::ASTDeleteInfo*				delete_info;
	Parser::ASTDropTableInfo*			table_drop;
	Parser::ASTExit*					exit;		
	Parser::ASTInsertInfo*				insert;
	Parser::ASTSelectInfo*				select_info;
	Parser::ASTSetOutput*				set_path;
	Parser::ASTShowTableInfo*			table_show;
	Parser::ASTUpdateInfo*				update_info;
	Parser::TableFrom*					join_info;
	Parser::TableFromList*				join_infos;
	Parser::ExprNode*					expr;
	Parser::ExprNodeList*		 		exprs;

#line 195 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.hh"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (Parser::SQLParserResult* thisptr);

#endif /* !YY_YY_HOME_TYPHIGH_DESKTOP_OPENSOURCE_TCOLDB_BUILD_SRC_PARSER_SQL_TAB_HH_INCLUDED  */
