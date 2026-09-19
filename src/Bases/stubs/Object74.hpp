#pragma once
#include "../ModelAnmEntity.hpp"
#include "../../Collision/activecollider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 74  |  ov078  |  profile @ 0x0217b390
class Object74 : public ModelAnmEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	ActiveCollider _4bc; /* 0x4BC */
	u8 _unrecovered_56c[0x54];

	void pendingDestroy();
	static void *create();
	inline Object74() {};
	inline ~Object74() {};
};
static_assert(sizeof(Object74) == 0x5c0);

extern ActorProfile Object74_Profile;

