#include <string.h>
#include <cstdio>
#include <iostream>
#include "Parser/SQLParser.h"
using namespace std;

int main(int argc, char *argv[])
{
	using namespace Parser;
	SQLParserResult* result = new SQLParserResult();
	SQLParser::Parse("", result);
	IAST* ret = result->Get();
	cout << ret->ToString() << endl;
	delete ret;
	delete result;
	return 0;
	
}