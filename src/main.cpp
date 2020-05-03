#include <string.h>
#include <cstdio>
#include <iostream>
#include <snappy.h>
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

	string s;
	snappy::Compress("aaa", 3, &s);
	return 0;
	
}