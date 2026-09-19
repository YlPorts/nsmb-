#include "Object114.hpp"

void *Object114::create()
{
	return new Object114();
}

// 0x02146720
ActorProfile Object114_Profile = { Object114::create, 114, 132, NULL /* TODO: 0x02143b04 */ };

void Object114::_23()
{
}

void Object114::pendingDestroy()
{
}

s32 Object114::onDestroy()
{
	return 1;
}
