#pragma once
#include "../../graphics/3d/model.hpp"
#include "../../Vec.hpp"
#include "../../Collision/Collider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 262  |  ov042  |  profile @ 0x02152238
class Object262 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	Collider _3f4; /* 0x3F4 */
	u8 _unrecovered_454[0x14];
	Vec3_32 _468[8]; /* 0x468 */
	Vec3_32 _4e8[8]; /* 0x4E8 */
	Model _568[2]; /* 0x568 */
	u8 _unrecovered_688[0x94];

	void pendingDestroy();
	static void *create();
	inline Object262() {};
	inline ~Object262() {};
};
static_assert(sizeof(Object262) == 0x71c);

extern ActorProfile Object262_Profile;

