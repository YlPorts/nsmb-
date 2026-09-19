#pragma once
#include "../../graphics/3d/model.hpp"
#include "../../Collision/platform.hpp"
#include "../../Collision/activecollider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 27  |  ov042  |  profile @ 0x02151fb0
class Object27 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	Model _3f4; /* 0x3F4 */
	SegmentPlatform _484; /* 0x484 */
	ActiveCollider _4f4; /* 0x4F4 */
	u8 _unrecovered_5a4[0x40];

	void pendingDestroy();
	static void *create();
	inline Object27() {};
	inline ~Object27() {};
};
static_assert(sizeof(Object27) == 0x5e4);

extern ActorProfile Object27_Profile;

// MainProfileTable slot 238  |  ov042  |  profile @ 0x02151fbc
class Object238 : public StageEntity {
public:
	static void *create();
	inline Object238() {};
	inline ~Object238() {};
};

extern ActorProfile Object238_Profile;

