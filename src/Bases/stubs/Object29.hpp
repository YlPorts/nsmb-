#pragma once
#include "../ModelAnmEntity.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 29  |  ov067  |  profile @ 0x02176770
class Object29 : public ModelAnmEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	u8 _unrecovered_4bc[0x18];

	s32 onDestroy();
	static void *create();
	inline Object29() {};
	inline ~Object29() {};
};
static_assert(sizeof(Object29) == 0x4d4);

extern ActorProfile Object29_Profile;

