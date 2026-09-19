#pragma once
#include "../../graphics/3d/model.hpp"
#include "../../Collision/platform.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 227  |  ov087  |  profile @ 0x0217f600
class Object227 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	Model _3f4; /* 0x3F4 */
	RotatingPlatform _484; /* 0x484 */
	u8 _unrecovered_4f4[0x8];

	void pendingDestroy();
	static void *create();
	inline Object227() {};
	inline ~Object227() {};
};
static_assert(sizeof(Object227) == 0x4fc);

extern ActorProfile Object227_Profile;

