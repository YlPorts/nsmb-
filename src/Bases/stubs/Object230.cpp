#include "Object230.hpp"

void *Object230::create()
{
	return new Object230();
}

// 0x02181f00
ActorProfile Object230_Profile = { Object230::create, 230, 193, NULL /* TODO: 0x0217dcb8 */ };

s32 Object230::onDestroy()
{
	return 1;
}

void Object230::pendingDestroy()
{
}
