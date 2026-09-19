#pragma once
#include "../../graphics/3d/texture.hpp"
#include "../../Vec.hpp"
#include "../../Collision/platform.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 200  |  ov116  |  profile @ 0x0218efc0
class Object200 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	Texture _3f4; /* 0x3F4 */
	u8 _unrecovered_3fc[0x18];
	SegmentPlatform _414[33]; /* 0x414 */
	Vec2_32 _1284[34]; /* 0x1284 */
	Vec2_32 _141c[34]; /* 0x141C */
	Vec2_32 _15b4[129]; /* 0x15B4 */
	u8 _unrecovered_1bc0[0x128];

	static void *create();
	inline Object200() {};
	inline ~Object200() {};
};
static_assert(sizeof(Object200) == 0x1ce8);

extern ActorProfile Object200_Profile;

