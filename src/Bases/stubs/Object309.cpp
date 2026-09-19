#include "Object309.hpp"

void *Object309::create()
{
	return new Object309();
}

// 0x020daf4c
ActorProfile Object309_Profile = { Object309::create, 309, 300, NULL /* TODO: 0x020d7740 */ };

s32 Object309::onDestroy()
{
	return 1;
}

void Object309::pendingDestroy()
{
}
