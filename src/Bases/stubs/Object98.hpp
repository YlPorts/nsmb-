#pragma once
#include "../../graphics/3d/model.hpp"
#include "../../Vec.hpp"
#include "../../Collision/activecollider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 98  |  ov023  |  profile @ 0x0213ebf0
class Object98 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	Model _3f4[9]; /* 0x3F4 */
	Vec3_32 _904[9]; /* 0x904 */
	ActiveCollider _994[9]; /* 0x994 */
	u8 _unrecovered_fc4[0x38];
	Vec2_32 _ffc[9]; /* 0xFFC */
	u8 _unrecovered_1068[0x48];

	void pendingDestroy();
	static void *create();
	inline Object98() {};
	inline ~Object98() {};
};
static_assert(sizeof(Object98) == 0x10b0);

extern ActorProfile Object98_Profile;

