#pragma once
#include "../../graphics/3d/model.hpp"
#include "../../Collision/platform.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 208  |  ov096  |  profile @ 0x02188208
class Object208 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	Model _3f4; /* 0x3F4 */
	u8 _unrecovered_484[0x28];
	RotatingPlatform _4ac; /* 0x4AC */

	static void *create();
	inline Object208() {};
	inline ~Object208() {};
};
static_assert(sizeof(Object208) == 0x51c);

extern ActorProfile Object208_Profile;

