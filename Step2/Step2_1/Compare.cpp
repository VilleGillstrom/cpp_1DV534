#include "Compare.h"
#include <cstring>


Compare::Compare()
{
}


Compare::~Compare()
{
}

bool Compare::equal(const char* strA, const char* strB) const
{
	return strcmp(strA, strB) == 0;
}
