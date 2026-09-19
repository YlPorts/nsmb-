#include "Object331.hpp"

void *Object331::create()
{
	return new Object331();
}

// 0x02138c20
ObjectProfile Object331_Profile = { Object331::create, 331, 331 };

s32 Object331::onDestroy()
{
	return 1;
}
