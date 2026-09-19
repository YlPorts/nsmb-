#pragma once
#include "../ModelAnmEntity.hpp"
#include "../../graphics/3d/animationctrl.hpp"
#include "../../Vec.hpp"
#include "../../Collision/platform.hpp"
#include "../../Collision/activecollider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 239  |  ov014  |  profile @ 0x021330e8
class Object239 : public ModelAnmEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	AnimationCtrl _4bc; /* 0x4BC */
	ActiveCollider _4e8; /* 0x4E8 */
	u8 _unrecovered_598[0x20];
	SegmentPlatform _5b8; /* 0x5B8 */
	SegmentPlatform _628; /* 0x628 */
	SegmentPlatform _698; /* 0x698 */
	Vec3_32 _708; /* 0x708 */
	Vec3_32 _718; /* 0x718 */
	Vec3_32 _728; /* 0x728 */
	Vec3_32 _738; /* 0x738 */
	u8 _unrecovered_748[0x98];

	void _30();
	void _25();
	void _22();
	void _27();
	void onStomped();
	static void *create();
	inline Object239() {};
	inline ~Object239() {};
};
static_assert(sizeof(Object239) == 0x7e0);

extern ActorProfile Object239_Profile;

