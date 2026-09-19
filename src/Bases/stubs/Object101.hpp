#pragma once
#include "../../Collision/activecollider.hpp"
#include "../../graphics/3d/modelanm.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 101  |  ov081  |  profile @ 0x0217b884
class Object101 : public StageEntity {
public:

	ModelAnm _3f4; /* 0x3F4 */
	u8 _pad_49c[0x8];
	ActiveCollider _4a4; /* 0x4A4 */
	u8 _pad_554[0x1c];
	Vec3_32 _570; /* 0x570 */
	Vec3_32 _580; /* 0x580 */
	u8 _pad_590[0x8];

	void pendingDestroy();
	static void *create();
	static void *create2();
	inline Object101() {};
	inline ~Object101() {};
};
static_assert(sizeof(Object101) == 0x598);

extern ActorProfile Object101_Profile;

// MainProfileTable slot 102  |  ov081  |  profile @ 0x0217b890
// Profile 102 constructs Object101; there is no separate runtime class.

extern ActorProfile Object102_Profile;

