#pragma once
#include "../../graphics/3d/model.hpp"
#include "../../graphics/3d/animationctrl.hpp"
#include "../../Vec.hpp"
#include "../../Collision/activecollider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 65  |  ov024  |  profile @ 0x0213f928
class Object65 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	Model _3f4; /* 0x3F4 */
	AnimationCtrl _484; /* 0x484 */
	u8 _unrecovered_4b0[0x4];
	ActiveCollider _4b4[32]; /* 0x4B4 */
	Vec3_32 _1ab4[32]; /* 0x1AB4 */
	u8 _unrecovered_1cb4[0x10];

	void pendingDestroy();
	void _31();
	static void *create();
	inline Object65() {};
	inline ~Object65() {};
};
static_assert(sizeof(Object65) == 0x1cc4);

extern ActorProfile Object65_Profile;

