#pragma once
#include "../../Collision/activecollider.hpp"
#include "../../graphics/3d/modelanm.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 23  |  ov032  |  profile @ 0x021439c8
class Object23 : public StageEntity {
public:

	ModelAnm _3f4; /* 0x3F4 */
	u8 _pad_49c[0x8];
	Vec3_32 _4a4; /* 0x4A4 */
	Vec3_32 _4b4; /* 0x4B4 */
	Vec2_32 _4c4; /* 0x4C4 */
	Vec2_32 _4d0; /* 0x4D0 */
	ActiveCollider _4dc; /* 0x4DC */
	u8 _pad_58c[0x10];

	void _21();
	void pendingDestroy();
	static void *create();
	static void *create2();
	static void *create3();
	static void *create4();
	inline Object23() {};
	inline ~Object23() {};
};
static_assert(sizeof(Object23) == 0x59c);

extern ActorProfile Object23_Profile;

// MainProfileTable slot 24  |  ov032  |  profile @ 0x021439d4
// Profile 24 constructs Object23; there is no separate runtime class.

extern ActorProfile Object24_Profile;

// MainProfileTable slot 25  |  ov032  |  profile @ 0x021439e0
// Profile 25 constructs Object23; there is no separate runtime class.

extern ActorProfile Object25_Profile;

// MainProfileTable slot 26  |  ov032  |  profile @ 0x021439ec
// Profile 26 constructs Object23; there is no separate runtime class.

extern ActorProfile Object26_Profile;

