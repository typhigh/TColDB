#include <string.h>
#include <cstdio>
#include "Common/Server.h"
char run_parser(const char *input);

int main(int argc, char *argv[])
{
//	Common::Server::Start();
	if(argc < 2)
	{
		return run_parser(nullptr);
	} else {
		return 0;
	}
	return 0;
}