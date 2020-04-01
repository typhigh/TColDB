#include <string.h>
#include <cstdio>
#include "Parser/SQLParser.h"

int main(int argc, char *argv[])
{
	using namespace Parser;
	SQLParserResult* result;
	SQLParser::Parse("", result);
	return 0;
	
}