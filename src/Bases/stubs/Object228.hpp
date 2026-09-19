#pragma once
#include "../../graphics/3d/model.hpp"
#include "../../Collision/platform.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 228  |  ov088  |  profile @ 0x02182050
class Object228 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	Model _3f4; /* 0x3F4 */
	RotatingPlatform _484; /* 0x484 */
	u8 _unrecovered_4f4[0x8];

	void pendingDestroy();
	static void *create();
	inline Object228() {};
	inline ~Object228() {};
};
static_assert(sizeof(Object228) == 0x4fc);

extern ActorProfile Object228_Profile;

