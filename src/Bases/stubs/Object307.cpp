#include "Object307.hpp"

void *Object307::create()
{
	return new Object307();
}

// 0x020dacdc
ActorProfile Object307_Profile = { Object307::create, 307, 298, NULL /* TODO: 0x020d59ec */ };

s32 Object307::onDestroy()
{
	return 1;
}

void Object307::pendingDestroy()
{
}
