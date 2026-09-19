#pragma once
#include "../../graphics/3d/texture.hpp"
#include "../../Vec.hpp"
#include "../../Collision/platform.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 105  |  ov090  |  profile @ 0x02185478
class Object105 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	u8 _unrecovered_3f4[0x10];
	Vec3_32 _404; /* 0x404 */
	Vec3_32 _414; /* 0x414 */
	u8 _unrecovered_424[0x4];
	Texture _428; /* 0x428 */
	u8 _unrecovered_430[0x50];
	Vec3_32 _480; /* 0x480 */
	u8 _unrecovered_490[0x4];
	SegmentPlatform _494[3]; /* 0x494 */
	Vec2_32 _5e4[4]; /* 0x5E4 */
	Texture _614; /* 0x614 */
	u8 _unrecovered_61c[0x10];

	s32 onDestroy();
	void pendingDestroy();
	static void *create();
	inline Object105() {};
	inline ~Object105() {};
};
static_assert(sizeof(Object105) == 0x62c);

extern ActorProfile Object105_Profile;

