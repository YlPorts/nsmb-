#include "Object103.hpp"

void *Object103::create()
{
	return new Object103();
}

// 0x0218dfa8
ActorProfile Object103_Profile = { Object103::create, 103, 224, NULL /* TODO: 0x0218d250 */ };

void Object103::pendingDestroy()
{
}

s32 Object103::onDestroy()
{
	return 1;
}

void Object103::_21()
{
}
