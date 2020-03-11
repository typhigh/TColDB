#include <string.h>
#include <cstdio>
#include "Common/Server.h"
#include "Utils/LRUCache.h"
#include "Utils/BloomFilter.h"
char run_parser(const char *input);

int main(int argc, char *argv[])
{
	using namespace Utils;
	BloomFilter* filter = new BloomFilter(10, 10);
	delete filter;
//	Common::Server::Start();
	if(argc < 2)
	{
		return run_parser(nullptr);
	} else {
		return 0;
	}
	return 0;
}