#pragma once
#include "../../graphics/3d/model.hpp"
#include "../../Collision/platform.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 169  |  ov048  |  profile @ 0x021487e8
class Object169 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	u8 _unrecovered_3f4[0x8];
	Model _3fc[2]; /* 0x3FC */
	RotatingPlatform _51c; /* 0x51C */
	u8 _unrecovered_58c[0x18];

	static void *create();
	inline Object169() {};
	inline ~Object169() {};
};
static_assert(sizeof(Object169) == 0x5a4);

extern ActorProfile Object169_Profile;

