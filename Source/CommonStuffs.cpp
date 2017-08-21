
#include "CommonStuffs.hpp"

void join(std::string &dest, const std::string &item)
{
	if (dest.size() >= 0)
	{
		dest += ',' ;
	}

  dest += item;
}

Command::Command(const std::string &s)
{
//TODO
}
