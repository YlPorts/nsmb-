#pragma once
#include "../../graphics/3d/blendmodelanm.hpp"
#include "../../Vec.hpp"
#include "../../Collision/platform.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 119  |  ov015  |  profile @ 0x02134728
class Object119 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	BlendModelAnm _3f4; /* 0x3F4 */
	RotatingPlatform _4b8; /* 0x4B8 */
	RotatingPlatform _528; /* 0x528 */
	RotatingPlatform _598; /* 0x598 */
	u8 _unrecovered_608[0x10];
	Vec3_32 _618; /* 0x618 */
	Vec3_32 _628; /* 0x628 */
	Vec3_32 _638; /* 0x638 */
	Vec3_32 _648; /* 0x648 */
	Vec2_32 _658; /* 0x658 */
	u8 _unrecovered_664[0x48];
	Vec3_16 _6ac; /* 0x6AC */
	Vec3_16 _6b8; /* 0x6B8 */
	Vec3_16 _6c4; /* 0x6C4 */
	u8 _unrecovered_6d0[0x4c];
	Vec3_32 _71c; /* 0x71C */

	static void *create();
	inline Object119() {};
	inline ~Object119() {};
};
static_assert(sizeof(Object119) == 0x72c);

extern ActorProfile Object119_Profile;

