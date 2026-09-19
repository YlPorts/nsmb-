#pragma once
#include "../ModelEntity.hpp"
#include "../../graphics/3d/model.hpp"
#include "../../Vec.hpp"
#include "../../Collision/Collider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 250  |  ov098  |  profile @ 0x02189478
class Object250 : public ModelEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	Vec2_32 _4a0[3]; /* 0x4A0 */
	Vec2_32 _4c4[9]; /* 0x4C4 */
	Vec2_32 _530; /* 0x530 */
	u8 _unrecovered_53c[0xc];
	Vec3_32 _548; /* 0x548 */
	u8 _unrecovered_558[0x34];
	Model _58c; /* 0x58C */
	Collider _61c; /* 0x61C */
	u8 _unrecovered_67c[0xc];
	Vec3_32 _688; /* 0x688 */
	Vec3_32 _698; /* 0x698 */
	Vec2_32 _6a8; /* 0x6A8 */
	u8 _unrecovered_6b4[0x4c];

	static void *create();
	inline Object250() {};
	inline ~Object250() {};
};
static_assert(sizeof(Object250) == 0x700);

extern ActorProfile Object250_Profile;

