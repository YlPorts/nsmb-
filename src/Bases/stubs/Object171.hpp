#pragma once
#include "../../graphics/3d/model.hpp"
#include "../../Collision/platform.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 171  |  ov089  |  profile @ 0x0217fba0
class Object171 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	Model _3f4; /* 0x3F4 */
	RotatingPlatform _484; /* 0x484 */
	u8 _unrecovered_4f4[0x18];

	static void *create();
	inline Object171() {};
	inline ~Object171() {};
};
static_assert(sizeof(Object171) == 0x50c);

extern ActorProfile Object171_Profile;

