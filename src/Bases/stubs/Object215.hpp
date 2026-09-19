#pragma once
#include "../../graphics/3d/model.hpp"
#include "../../Collision/platform.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 215  |  ov118  |  profile @ 0x0218fd88
class Object215 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	Model _3f4; /* 0x3F4 */
	RotatingPlatform _484; /* 0x484 */
	u8 _unrecovered_4f4[0x34];

	static void *create();
	inline Object215() {};
	inline ~Object215() {};
};
static_assert(sizeof(Object215) == 0x528);

extern ActorProfile Object215_Profile;

