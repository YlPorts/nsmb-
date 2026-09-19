#include "Object214.hpp"

void *Object214::create()
{
	return new Object214();
}

// 0x0218c638
ActorProfile Object214_Profile = { Object214::create, 214, 276, NULL /* TODO: 0x0218b7e0 */ };

bool Object214::onHeapCreated()
{
	return true;
}

void Object214::pendingDestroy()
{
}

bool Object214::_01()
{
	return false;
}
