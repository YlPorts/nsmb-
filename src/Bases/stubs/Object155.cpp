#include "Object155.hpp"

void *Object155::create()
{
	return new Object155();
}

// 0x0217baa8
ActorProfile Object155_Profile = { Object155::create, 155, 180, NULL /* TODO: 0x0217b0bc */ };

void Object155::pendingDestroy()
{
}

s32 Object155::onDestroy()
{
	return 1;
}
