#include "Object97.hpp"

void *Object97::create()
{
	return new Object97();
}

// 0x02133d08
ActorProfile Object97_Profile = { Object97::create, 97, 253, NULL };

s32 Object97::onRender()
{
	return 1;
}

void Object97::pendingDestroy()
{
}

s32 Object97::onDestroy()
{
	return 1;
}
