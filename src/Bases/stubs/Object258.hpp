#pragma once
#include "../ModelEntity.hpp"
#include "../../graphics/3d/model.hpp"
#include "../../Vec.hpp"
#include "../../Collision/Collider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 258  |  ov098  |  profile @ 0x021895d4
class Object258 : public ModelEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	struct Unk4A0 {
		Vec3_32 vec;
		Vec2_32 points[62];
	};
	Unk4A0 _4a0; /* 0x4A0 */
	u8 _unrecovered_798[0x194];
	Model _92c; /* 0x92C */
	u8 _unrecovered_9bc[0x8];
	Collider _9c4; /* 0x9C4 */
	u8 _unrecovered_a24[0x10];
	Vec3_32 _a34; /* 0xA34 */
	Vec2_32 _a44; /* 0xA44 */
	Vec2_32 _a50; /* 0xA50 */
	u8 _unrecovered_a5c[0x44];

	static void *create();
	inline Object258() {};
	inline ~Object258() {};
};
static_assert(sizeof(Object258) == 0xaa0);

extern ActorProfile Object258_Profile;

