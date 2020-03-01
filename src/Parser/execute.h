#ifndef __TRIVIALDB_PARSER_EXECUTE__
#define __TRIVIALDB_PARSER_EXECUTE__

#include "defs.h"
namespace Parser {

void execute_create_database(const char *db_name);
void execute_use_database(const char *db_name);
void execute_drop_database(const char *db_name);
void execute_show_database(const char *db_name);
void execute_create_table(const ASTTableDef *table);
void execute_drop_table(const char *table_name);
void execute_show_table(const char *table_name);
void execute_insert(const ASTInsertInfo *insert_info);
void execute_delete(const ASTDeleteInfo *delete_info);
void execute_select(const ASTSelectInfo *select_info);
void execute_update(const ASTUpdateInfo *update_info);
void execute_create_index(const char *table_name, const char *col_name);
void execute_drop_index(const char *table_name, const char *col_name);
void execute_switch_output(const char *output_filename);
void execute_quit();

}

#endif
