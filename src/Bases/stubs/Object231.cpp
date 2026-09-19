#include "Object231.hpp"

void *Object231::create()
{
	return new Object231();
}

// 0x02188830
ActorProfile Object231_Profile = { Object231::create, 231, 194, NULL /* TODO: 0x02185790 */ };

s32 Object231::onDestroy()
{
	return 1;
}

void Object231::pendingDestroy()
{
}
