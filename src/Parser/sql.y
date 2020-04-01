/* Modified from https://raw.githubusercontent.com/thinkpad20/sql/master/src/yacc/sql.y
             and https://github.com/Harry-Chen/SimpleDB
 * Grammar: http://h2database.com/html/grammar.html#select */

%define parse.error verbose

%{
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
using namespace Parser;
using namespace std;

void yyerror(Parser::SQLParserResult* result, const char *s);

#include "sql.yy.cc"
%}

%code requires {

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

}

%parse-param {Parser::SQLParserResult* thisptr}
%union {
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
}

%token TRUE FALSE NULL_TOKEN MIN MAX SUM AVG COUNT
%token LIKE IS OR AND NOT NEQ GEQ LEQ
%token INTEGER DOUBLE FLOAT CHAR VARCHAR DATE BOOL
%token INTO FROM WHERE VALUES JOIN INNER OUTER
%token LEFT RIGHT FULL ASC DESC ORDER BY IN ON AS
%token DISTINCT GROUP USING INDEX TABLE DATABASE
%token DEFAULT UNIQUE PRIMARY FOREIGN REFERENCES CHECK KEY OUTPUT
%token USE CREATE DROP SELECT INSERT UPDATE DELETE SHOW SET EXIT

%token IDENTIFIER
%token DATE_LITERAL
%token STRING_LITERAL
%token FLOAT_LITERAL
%token INT_LITERAL

%type <val_s> IDENTIFIER STRING_LITERAL DATE_LITERAL
%type <val_f> FLOAT_LITERAL
%type <val_i> INT_LITERAL
%type <val_b> BOOL_LITERAL

%type <val_i> field_width field_flag field_flags
%type <val_s> table_name database_name
%type <val_s> create_database_stmt use_database_stmt drop_database_stmt show_database_stmt 

%type <field_type> field_type
%type <field_def> table_field
%type <field_defs> table_fields
%type <table_def> create_table_stmt
%type <column_ref> column_ref
%type <column_refs> column_list
%type <constraint> table_extra_option 
%type <constraints> table_extra_options table_extra_option_list
%type <ast> sql_stmt
%type <ast_plan> sql_plan_stmt
%type <ast_noplan> sql_noplan_stmt
%type <insert> insert_stmt insert_columns
%type <update_info> update_stmt
%type <delete_info> delete_stmt
%type <select_info> select_stmt
%type <table_drop> drop_table_stmt
%type <table_show> show_table_stmt
%type <exit> exit_stmt
%type <set_path> setpath_stmt
%type <expr> expr factor term condition cond_term where_clause literal literal_list_expr
%type <expr> aggregate_expr aggregate_term select_expr default_expr
%type <exprs> insert_values expr_list literal_list select_expr_list select_expr_list_s
%type <val_i> logical_op compare_op aggregate_op
%type <join_info> table_item
%type <join_infos> table_refs

%start sql_start

%%
sql_start  :  sql_stmt 				   { thisptr->Set($1);}
		   ;

sql_stmt   : sql_plan_stmt					{ $$ = $1;}
		   | sql_noplan_stmt 				{ $$ = $1;}
		   ;

sql_plan_stmt   :  update_stmt ';'          { $$ = $1;}
		   		|  delete_stmt ';'          { $$ = $1;}
		   		|  select_stmt ';'          { $$ = $1;}
		   		;



sql_noplan_stmt	:  create_table_stmt ';'	{ $$ = $1;}
				|  create_database_stmt ';' {}
				|  use_database_stmt ';'	{}
				|  show_database_stmt ';'	{}
				|  drop_database_stmt ';'	{}
				|  show_table_stmt ';'		{ $$ = $1;}
				|  drop_table_stmt ';'		{ $$ = $1;}
				|  insert_stmt ';'			{ $$ = $1;}
				|  exit_stmt ';'			{ $$ = $1;}
				|  setpath_stmt ';'			{ $$ = $1;}
				;

create_table_stmt : CREATE TABLE table_name '(' table_fields table_extra_options ')' {
				  	$$ = new ASTCreateInfo();
					$$->name = $3;
					$$->fields = $5;
					$$->constraints = $6;
				  }
				  ;

create_database_stmt : CREATE DATABASE database_name   { $$ = $3; };
use_database_stmt    : USE database_name               { $$ = $2; };
drop_database_stmt   : DROP DATABASE database_name     { $$ = $3; };
show_database_stmt   : SHOW DATABASE database_name     { $$ = $3; };

drop_table_stmt      : DROP TABLE table_name           { 
						$$ = new ASTDropTableInfo();
						$$->table = $3;
					 }
					 ;

show_table_stmt      : SHOW TABLE table_name           { 
						$$ = new ASTShowTableInfo();
						$$->table = $3; 
					 }
					 ;

insert_stmt          : INSERT INTO insert_columns VALUES insert_values {
					 	$$ = $3;
						$$->values = $5;
					 }
					 ;

insert_values        : '(' expr_list ')' {
					 	$$ = new ExprNodeList ();
						ExprNode* newNode = new ExprNode();
						newNode->literal_list = $2;
						$$->push_back(newNode);
					 }
					 | insert_values ',' '(' expr_list ')' {
						ExprNode* newNode = new ExprNode();
						newNode->literal_list = $4;
					 	$1->push_back(newNode);
						$$ = $1;
					 }
					 ;

insert_columns       : table_name {
					 	$$ = new ASTInsertInfo();
						$$->table   = $1;
						$$->columns = NULL;
						$$->values  = NULL;
					 }
					 | table_name '(' column_list ')' {
					 	$$ = new ASTInsertInfo();
						$$->table   = $1;
						$$->columns = $3;
						$$->values  = NULL;
					 }
					 ;

delete_stmt         : DELETE FROM table_name where_clause {
					 	$$ = new ASTDeleteInfo();
						$$->table = $3;
						$$->where = $4;
					}
					;

update_stmt         : UPDATE table_name SET column_ref '=' expr where_clause {
					 	$$ = new ASTUpdateInfo();
						$$->table = $2;
						$$->value = $6;
						$$->where = $7;
						$$->column_ref = $4;
					}
					;

select_stmt         : SELECT select_expr_list_s FROM table_refs where_clause {
					 	$$ = new ASTSelectInfo();
						$$->tables = $4;
						$$->exprs  = $2;
						$$->where  = $5;
					}
					;
					
exit_stmt			: EXIT                  	{ $$ = new ASTExit(); }
					;

setpath_stmt		: SET OUTPUT '=' STRING_LITERAL { 
			   			ASTSetOutput* node = new ASTSetOutput();
			   			node->path = $4;
			   			$$ = node; 
		   			}
		   			;

table_refs          : table_refs ',' table_item {
						$1->push_back($3);
						$$ = $1;
					}
					| table_item {
						$$ = new TableFromList();
						$$->push_back($1);
					}
					;

table_item          : table_name {
					 	$$ = new TableFrom();
						$$->join_type = TABLE_JOIN_NONE;
						$$->table = $1;
					}
				    | table_name AS IDENTIFIER {
					 	$$ = new TableFrom();
						$$->join_type = TABLE_JOIN_NONE;
						$$->table = $1;
						$$->alias = $3;
					}
					;

select_expr_list_s  : select_expr_list { $$ = $1; }
					| '*'              { $$ = NULL; }

select_expr_list    : select_expr_list ',' select_expr {
						$1->push_back($3);
						$$ = $1;
					}
					| select_expr {
						$$ = new ExprNodeList();
						$$->push_back($1);
					}
					;

select_expr         : condition       { $$ = $1; }
					| aggregate_expr  { $$ = $1; }

aggregate_expr      : aggregate_op '(' aggregate_term ')' {
						$$ = new ExprNode();
						$$->left  = $3;
						$$->op    = (operator_type_t) $1;
					}
					| COUNT '(' aggregate_term ')' {
						$$ = new ExprNode();
						$$->left  = $3;
						$$->op    = OPERATOR_COUNT;
					}
					| COUNT '(' '*' ')' {
						$$ = new ExprNode();
						$$->left  = NULL;
						$$->op    = OPERATOR_COUNT;
					}
					;

aggregate_term      : column_ref {
						$$ = new ExprNode();
						$$->column_ref = $1;
						$$->term_type  = TERM_COLUMN_REF;
					}
					;

aggregate_op        : SUM   { $$ = OPERATOR_SUM; }
					| AVG   { $$ = OPERATOR_AVG; }
					| MIN   { $$ = OPERATOR_MIN; }
					| MAX   { $$ = OPERATOR_MAX; }
					;

where_clause        : WHERE condition { $$ = $2; }
					| /* empty */     { $$ = NULL; }
					;

table_extra_options : ',' table_extra_option_list  { $$ = $2; }
					| /* empty */                  { $$ = NULL; }
					;

table_extra_option_list : table_extra_option_list ',' table_extra_option {
							$1->push_back($3);
							$$ = $1;
						}
						| table_extra_option {
							$$ = new vector<TableConstraint*> ();
							$$->push_back($1);
						}
						;

table_extra_option : PRIMARY KEY '(' IDENTIFIER ')' {
					$$ = new TableConstraint();
					$$->column_ref = (ColumnRef*)malloc(sizeof(ColumnRef));
					$$->column_ref->table = NULL;
					$$->column_ref->column = $4;
					$$->type = TABLE_CONSTRAINT_PRIMARY_KEY;
				   }
				   | FOREIGN KEY '(' IDENTIFIER ')' REFERENCES IDENTIFIER '(' IDENTIFIER ')' {
				   	$$ = new TableConstraint();
					$$->column_ref = (ColumnRef*)malloc(sizeof(ColumnRef));
					$$->column_ref->table = NULL;
					$$->column_ref->column = $4;
					$$->foreign_column_ref = (ColumnRef*)malloc(sizeof(ColumnRef));
					$$->foreign_column_ref->table = $7;
					$$->foreign_column_ref->column = $9;
					$$->type = TABLE_CONSTRAINT_FOREIGN_KEY;
				   }
				   | UNIQUE '(' column_ref ')' {
				   	$$ = new TableConstraint();
					$$->type = TABLE_CONSTRAINT_UNIQUE;
					$$->column_ref = $3;
				   }
				   | CHECK '(' condition ')' {
				   	$$ = new TableConstraint();
					$$->type = TABLE_CONSTRAINT_CHECK;
					$$->check_cond = $3;
				   }
				   ;

column_ref   : IDENTIFIER {
				$$ = new ColumnRef();
				$$->table  = NULL;
				$$->column = $1;
			 }
			 | table_name '.' IDENTIFIER {
			 	$$ = new ColumnRef();
				$$->table  = $1;
				$$->column = $3;
			 }
			 ;

column_list  : column_list ',' column_ref {
				$1->push_back($3);
				$$ = $1;
			 }
			 | column_ref {
			 	$$ = new ColumnRefList();
				$$->push_back($1);
			 }
			 ;


table_fields : table_field { 
				$$ = new vector<FieldDef*>(); 
				$$->push_back($1);
			 }
			 | table_fields ',' table_field { 
				$1->push_back($3); 
				$$ = $1;
			 }
			 | {$$ = NULL;}
			 ;

table_field  : IDENTIFIER field_type field_width field_flags default_expr {
			 	$$ = new FieldDef();
				$$->name = $1;
				$$->type = $2;
				$$->width = $3;
				$$->flags = $4;
				$$->default_value = $5;
			 }
			 ;

default_expr : DEFAULT literal { $$ = $2; }
			 | /* empty */     { $$ = NULL; }

field_flags : field_flags field_flag  { $$ = $1 | $2; }
			| /* empty */             { $$ = 0; }
			;

field_flag  : NOT NULL_TOKEN  { $$ = FIELD_FLAG_NOTNULL; }
			| UNIQUE          { $$ = FIELD_FLAG_UNIQUE; }
			| PRIMARY KEY     { $$ = FIELD_FLAG_PRIMARY; }
			;

field_width : '(' INT_LITERAL ')'  { $$ = $2; }
			| /* empty */          { $$ = 0; }
			;

field_type  : INTEGER { $$ = FIELD_TYPE_INT; }
		    | FLOAT   { $$ = FIELD_TYPE_FLOAT; }
		    | DOUBLE  { $$ = FIELD_TYPE_FLOAT; }
		    | CHAR    { $$ = FIELD_TYPE_CHAR; }
		    | DATE    { $$ = FIELD_TYPE_DATE; }
		    | VARCHAR { $$ = FIELD_TYPE_VARCHAR; }
			| BOOL    { $$ = FIELD_TYPE_BOOL; }
		    ;

logical_op : AND  { $$ = OPERATOR_AND; }
		   | OR   { $$ = OPERATOR_OR; }

compare_op : '='  { $$ = OPERATOR_EQ; }
		   | '<'  { $$ = OPERATOR_LT; }
		   | '>'  { $$ = OPERATOR_GT; }
		   | LEQ  { $$ = OPERATOR_LEQ; }
		   | GEQ  { $$ = OPERATOR_GEQ; }
		   | NEQ  { $$ = OPERATOR_NEQ; }
		   | LIKE { $$ = OPERATOR_LIKE; }
		   ;

condition  : condition logical_op cond_term {
				$$ = new ExprNode();
				$$->left  = $1;
				$$->right = $3;
				$$->op    = (operator_type_t) $2;
		   }
		   | cond_term { $$ = $1; } 
		   ;

cond_term  : expr compare_op expr {
		   		$$ = new ExprNode();
				$$->left  = $1;
				$$->right = $3;
				$$->op    = (operator_type_t) $2;
		   }
		   | expr IN '(' literal_list_expr ')' {
		   		$$ = new ExprNode();
				$$->left  = $1;
				$$->right = $4;
				$$->op    = OPERATOR_IN;
		   }
		   | expr IS NULL_TOKEN {
		   		$$ = new ExprNode();
				$$->left  = $1;
				$$->op    = OPERATOR_ISNULL;
		   }
		   | expr IS NOT NULL_TOKEN {
		   		$$ = new ExprNode();
				$$->left  = $1;
				$$->op    = OPERATOR_NOTNULL;
		   }
		   | NOT cond_term {
		   		$$ = new ExprNode();
				$$->left  = $2;
				$$->op    = OPERATOR_NOT;
		   }
		   | '(' condition ')' { $$ = $2; }
		   | BOOL_LITERAL {
			   $$ = new ExprNode();
			   $$->val_b	   = $1;
			   $$->term_type   = TERM_BOOL; 
		   }
		   ;

expr_list  : expr_list ',' expr {
				$1->push_back($3);
				$$ = $1;
		   }
		   | expr {
				$$ = new ExprNodeList();
				$$->push_back($1);
		   }
		   ;

expr       : expr '+' factor {
		   		$$ = new ExprNode();
				$$->left  = $1;
				$$->right = $3;
				$$->op    = OPERATOR_ADD;
		   }
		   | expr '-' factor {
		   		$$ = new ExprNode();
				$$->left  = $1;
				$$->right = $3;
				$$->op    = OPERATOR_MINUS;
		   }
		   | factor { $$ = $1; }
		   ;

factor     : factor '*' term {
		   		$$ = new ExprNode();
				$$->left  = $1;
				$$->right = $3;
				$$->op    = OPERATOR_MUL;
		   }
		   | factor '/' term {
		   		$$ = new ExprNode();
				$$->left  = $1;
				$$->right = $3;
				$$->op    = OPERATOR_DIV;
		   }
		   | term { $$ = $1; }
		   ;

term       : column_ref {
		   		$$ = new ExprNode();
				$$->column_ref = $1;
				$$->term_type  = TERM_COLUMN_REF;
		   }
		   | '-' term {
		   		$$ = new ExprNode();
				$$->left  = $2;
				$$->op    = OPERATOR_NEGATE;
		   }
		   | literal      { $$ = $1; }
		   | NULL_TOKEN {
		   		$$ = new ExprNode();
				$$->term_type  = TERM_NULL;
		   }
		   | '(' expr ')' { $$ = $2; }
		   ;

literal    : INT_LITERAL {
		   		$$ = new ExprNode();
				$$->val_i      = $1;
				$$->term_type  = TERM_INT;
		   }
		   | FLOAT_LITERAL {
		   		$$ = new ExprNode();
				$$->val_f      = $1;
				$$->term_type  = TERM_FLOAT;
		   }
		   | DATE_LITERAL {
		   		$$ = new ExprNode();
				$$->val_s      = $1;
				$$->term_type  = TERM_DATE;
		   }
		   | STRING_LITERAL {
		   		$$ = new ExprNode();
				$$->val_s      = $1;
				$$->term_type  = TERM_STRING;
		   }
		   ;

BOOL_LITERAL : TRUE 	{$$ = true;} 
			 | FALSE	{$$ = false;}
			 ;

literal_list : literal_list ',' literal {
				$1->push_back($3);
				$$ = $1;
			 }
			 | literal {
				$$ = new ExprNodeList();
				$$->push_back($1);
			 }
			 ;

literal_list_expr : literal_list {
					$$ = new ExprNode();
					$$->literal_list = $1;
					$$->term_type    = TERM_LITERAL_LIST;
				  }

table_name : IDENTIFIER          { $$ = $1; }
		   | '`' IDENTIFIER '`'  { $$ = $2; }
		   ;

database_name : IDENTIFIER       { $$ = $1; }
			  ;

%%

void yyerror(Parser::SQLParserResult* result, const char *msg)
{
	result->SetError(msg);
//	fprintf(stderr, "[Error] %s\n", msg);
}

int yywrap()
{
	return 1;
}

char run_parser(const char *input, Parser::SQLParserResult* result)
{
	char ret;
	if(input) {
		YY_BUFFER_STATE buf = yy_scan_string(input);
		yy_switch_to_buffer(buf);
		ret = yyparse(result);
		yy_delete_buffer(buf);
	} else {
		ret = yyparse(result);
	}

	return ret;
}
