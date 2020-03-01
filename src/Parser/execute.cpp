#include <cstdio>
#include <cstdlib>
#include "execute.h"

namespace Parser {

void execute_switch_output(const char *output_filename)
{
    puts("execute_switch_output");
}

void execute_create_table(const ASTTableDef *table)
{
	puts("execute_create_table");
}

void execute_create_database(const char *db_name)
{
    puts("execute_create_database");
}

void execute_use_database(const char *db_name)
{
    puts("execute_use_database");
}

void execute_drop_database(const char *db_name)
{
    puts("execute_drop_database");
}  

void execute_show_database(const char *db_name)
{
	puts("execute_show_database");
}

void execute_drop_table(const char *table_name)
{
	puts("execute_drop_table");
}

void execute_show_table(const char *table_name)
{
	puts("execute_show_table");
}

void execute_insert(const ASTInsertInfo *insert_info)
{
	puts("execute_insert");
}

void execute_delete(const ASTDeleteInfo *delete_info)
{
	
}

void execute_select(const ASTSelectInfo *select_info)
{

}

void execute_update(const ASTUpdateInfo *update_info)
{

}

void execute_create_index(const char *table_name, const char *col_name)
{
	
}

void execute_drop_index(const char *table_name, const char *col_name)
{
	
}

void execute_quit()
{
	
}


}