#pragma once
#include "../ModelEntity.hpp"
#include "../../graphics/3d/animationctrl.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 37  |  ov024  |  profile @ 0x0213f6d0
class Object37 : public ModelEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	AnimationCtrl _4a0; /* 0x4A0 */
	u8 _unrecovered_4cc[0x28];

	s32 onDestroy();
	static void *create();
	inline Object37() {};
	inline ~Object37() {};
};
static_assert(sizeof(Object37) == 0x4f4);

extern ActorProfile Object37_Profile;

// MainProfileTable slot 38  |  ov024  |  profile @ 0x0213f6dc
class Object38 : public StageEntity {
public:
	static void *create();
	inline Object38() {};
	inline ~Object38() {};
};

extern ActorProfile Object38_Profile;

