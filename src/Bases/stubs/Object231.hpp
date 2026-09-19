#pragma once
#include "../../graphics/3d/texture.hpp"
#include "../../Vec.hpp"
#include "../../Collision/platform.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 231  |  ov097  |  profile @ 0x02188830
class Object231 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	SegmentPlatform _3f4[11]; /* 0x3F4 */
	Vec2_32 _8c4[12]; /* 0x8C4 */
	Vec2_32 _954[12]; /* 0x954 */
	u8 _unrecovered_9e4[0x20];
	Texture _a04; /* 0xA04 */
	u8 _unrecovered_a0c[0x24];

	void pendingDestroy();
	s32 onDestroy();
	static void *create();
	inline Object231() {};
	inline ~Object231() {};
};
static_assert(sizeof(Object231) == 0xa30);

extern ActorProfile Object231_Profile;

