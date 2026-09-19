#include "Object241.hpp"

void *Object241::create()
{
	return new Object241();
}

// 0x021245a8
ActorProfile Object241_Profile = { Object241::create, 241, 277, NULL };

void Object241::_21()
{
}

s32 Object241::onRender()
{
	return 1;
}

void Object241::pendingDestroy()
{
}
