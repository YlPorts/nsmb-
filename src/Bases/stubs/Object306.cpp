#include "Object306.hpp"

void *Object306::create()
{
	return new Object306();
}

// 0x020dac58
ActorProfile Object306_Profile = { Object306::create, 306, 297, NULL /* TODO: 0x020d5330 */ };

s32 Object306::onDestroy()
{
	return 1;
}

void Object306::pendingDestroy()
{
}
