#include "Object101.hpp"

void *Object101::create()
{
	return new Object101();
}

void *Object101::create2()
{
	return new Object101();
}

// 0x0217b884
ActorProfile Object101_Profile = { Object101::create, 101, 229, NULL /* TODO: 0x0217b554 */ };

// 0x0217b890
ActorProfile Object102_Profile = { Object101::create2, 102, 230, NULL /* TODO: 0x0217b554 */ };

void Object101::pendingDestroy()
{
}
