#include "Object151.hpp"

void *Object151::create()
{
	return new Object151();
}

// 0x0216cd90
ActorProfile Object151_Profile = { Object151::create, 151, 175, NULL /* TODO: 0x02153498 */ };

void Object151::pendingDestroy()
{
}

s32 Object151::onDestroy()
{
	return 1;
}
