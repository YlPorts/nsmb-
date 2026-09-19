#include "Object23.hpp"

void *Object23::create()
{
	return new Object23();
}

void *Object23::create2()
{
	return new Object23();
}

void *Object23::create3()
{
	return new Object23();
}

void *Object23::create4()
{
	return new Object23();
}

// 0x021439c8
ActorProfile Object23_Profile = { Object23::create, 23, 31, NULL /* TODO: 0x02143678 */ };

// 0x021439d4
ActorProfile Object24_Profile = { Object23::create2, 24, 32, NULL /* TODO: 0x02143678 */ };

// 0x021439e0
ActorProfile Object25_Profile = { Object23::create3, 25, 33, NULL /* TODO: 0x02143678 */ };

// 0x021439ec
ActorProfile Object26_Profile = { Object23::create4, 26, 34, NULL /* TODO: 0x02143678 */ };

void Object23::pendingDestroy()
{
}

void Object23::_21()
{
}
