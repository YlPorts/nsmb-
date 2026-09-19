#pragma once
#include "../ModelAnmEntity.hpp"
#include "../../Vec.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 28  |  ov025  |  profile @ 0x02141800
class Object28 : public ModelAnmEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	u8 _unrecovered_4bc[0x18];
	Vec3_32 _4d4; /* 0x4D4 */
	u8 _unrecovered_4e4[0x86c];

	s32 onDestroy();
	void pendingDestroy();
	static void *create();
	inline Object28() {};
	inline ~Object28() {};
};
static_assert(sizeof(Object28) == 0xd50);

extern ActorProfile Object28_Profile;

// MainProfileTable slot 30  |  ov025  |  profile @ 0x0214180c
class Object30 : public StageEntity {
public:
	static void *create();
	inline Object30() {};
	inline ~Object30() {};
};

extern ActorProfile Object30_Profile;

