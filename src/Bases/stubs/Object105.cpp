#include "Object105.hpp"

void *Object105::create()
{
	return new Object105();
}

// 0x02185478
ActorProfile Object105_Profile = { Object105::create, 105, 165, NULL /* TODO: 0x02184364 */ };

void Object105::pendingDestroy()
{
}

s32 Object105::onDestroy()
{
	return 1;
}
