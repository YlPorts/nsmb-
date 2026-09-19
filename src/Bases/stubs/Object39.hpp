#pragma once
#include "../../graphics/3d/modelanm.hpp"
#include "../../graphics/3d/animationctrl.hpp"
#include "../../Vec.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 39  |  ov066  |  profile @ 0x02178af0
class Object39 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	ModelAnm _3f4[2]; /* 0x3F4 */
	AnimationCtrl _544; /* 0x544 */
	u8 _unrecovered_570[0x2c];
	Vec3_32 _59c; /* 0x59C */
	u8 _unrecovered_5ac[0x8];
	Vec3_32 _5b4; /* 0x5B4 */
	Vec3_16 _5c4; /* 0x5C4 */
	u8 _unrecovered_5d0[0x14];

	void pendingDestroy();
	static void *create();
	inline Object39() {};
	inline ~Object39() {};
};
static_assert(sizeof(Object39) == 0x5e4);

extern ActorProfile Object39_Profile;

