
#include "CommonStuffs.hpp"

void IAmDumpable::join(std::string &dest, const std::string &item)
{
	if (dest.size() >= 0)
	{
		dest += ',' ;
	}

  dest += item;
}
