#pragma once
#include "../../graphics/3d/model.hpp"
#include "../../Vec.hpp"
#include "../../Collision/Collider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 213  |  ov117  |  profile @ 0x0218e0b0
class Object213 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	Model _3f4[2]; /* 0x3F4 */
	Vec3_16 _514; /* 0x514 */
	Collider _520; /* 0x520 */
	u8 _unrecovered_580[0x20];

	static void *create();
	inline Object213() {};
	inline ~Object213() {};
};
static_assert(sizeof(Object213) == 0x5a0);

extern ActorProfile Object213_Profile;

