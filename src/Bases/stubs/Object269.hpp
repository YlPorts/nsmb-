#pragma once
#include "../../graphics/3d/modelanm.hpp"
#include "../../graphics/3d/animationctrl.hpp"
#include "../../Vec.hpp"
#include "../../Collision/platform.hpp"
#include "../../Collision/Collider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 269  |  ov089  |  profile @ 0x0217fcf0
class Object269 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	AnimationCtrl _3f4; /* 0x3F4 */
	Collider _420; /* 0x420 */
	u8 _unrecovered_480[0xc];
	ModelAnm _48c; /* 0x48C */
	Vec3_32 _534; /* 0x534 */
	Vec3_32 _544; /* 0x544 */
	Vec3_32 _554; /* 0x554 */
	SegmentPlatform _564; /* 0x564 */
	SegmentPlatform _5d4; /* 0x5D4 */
	SegmentPlatform _644; /* 0x644 */
	u8 _unrecovered_6b4[0x44];

	void pendingDestroy();
	void _11();
	static void *create();
	inline Object269() {};
	inline ~Object269() {};
};
static_assert(sizeof(Object269) == 0x6f8);

extern ActorProfile Object269_Profile;

