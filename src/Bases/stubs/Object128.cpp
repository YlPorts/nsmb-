#include "Object128.hpp"

void *Object128::create()
{
	return new Object128();
}

// 0x02133a88
ActorProfile Object128_Profile = { Object128::create, 128, 146, NULL /* TODO: 0x021335d0 */ };

void Object128::entityCollision()
{
}

void Object128::_27()
{
}

void Object128::_26()
{
}

void Object128::_25()
{
}

void Object128::_24()
{
}

void Object128::_22()
{
}

s32 Object128::onDestroy()
{
	return 1;
}
