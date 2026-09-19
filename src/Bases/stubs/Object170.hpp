#pragma once
#include "../../graphics/3d/model.hpp"
#include "../../Collision/platform.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 170  |  ov048  |  profile @ 0x02148920
class Object170 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	u8 _unrecovered_3f4[0x8];
	Model _3fc; /* 0x3FC */
	RotatingPlatform _48c; /* 0x48C */
	u8 _unrecovered_4fc[0xc];

	static void *create();
	inline Object170() {};
	inline ~Object170() {};
};
static_assert(sizeof(Object170) == 0x508);

extern ActorProfile Object170_Profile;

