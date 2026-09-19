#pragma once
#include "../ModelAnmEntity.hpp"
#include "../../graphics/3d/model.hpp"
#include "../../graphics/3d/animationctrl.hpp"
#include "../../Vec.hpp"
#include "../../Collision/platform.hpp"
#include "../../Collision/Collider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 259  |  ov069  |  profile @ 0x02178438
class Object259 : public ModelAnmEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	Model _4bc; /* 0x4BC */
	AnimationCtrl _54c; /* 0x54C */
	AnimationCtrl _578; /* 0x578 */
	RotatingPlatform _5a4; /* 0x5A4 */
	u8 _unrecovered_614[0x8];
	Collider _61c; /* 0x61C */
	u8 _unrecovered_67c[0x48];
	Vec3_32 _6c4; /* 0x6C4 */
	u8 _unrecovered_6d4[0x34];

	void _23();
	void _30();
	static void *create();
	inline Object259() {};
	inline ~Object259() {};
};
static_assert(sizeof(Object259) == 0x708);

extern ActorProfile Object259_Profile;

