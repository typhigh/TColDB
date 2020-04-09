#include <string.h>
#include <cstdio>
#include "Parser/SQLParser.h"

int main(int argc, char *argv[])
{
	using namespace Parser;
	SQLParserResult* result = new SQLParserResult();
	SQLParser::Parse("", result);
	delete result;
	return 0;
	
}