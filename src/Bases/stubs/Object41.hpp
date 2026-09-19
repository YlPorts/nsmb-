#pragma once
#include "../ModelAnmEntity.hpp"
#include "../../graphics/3d/animationctrl.hpp"
#include "../../Vec.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 41  |  ov071  |  profile @ 0x02179378
class Object41 : public ModelAnmEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	AnimationCtrl _4bc; /* 0x4BC */
	u8 _unrecovered_4e8[0x10];
	Vec3_32 _4f8; /* 0x4F8 */
	Vec3_32 _508; /* 0x508 */
	Vec3_32 _518; /* 0x518 */
	Vec3_32 _528; /* 0x528 */
	Vec3_32 _538; /* 0x538 */
	u8 _unrecovered_548[0x68];

	static void *create();
	inline Object41() {};
	inline ~Object41() {};
};
static_assert(sizeof(Object41) == 0x5b0);

extern ActorProfile Object41_Profile;

// MainProfileTable slot 42  |  ov071  |  profile @ 0x02179384
class Object42 : public StageEntity {
public:
	static void *create();
	inline Object42() {};
	inline ~Object42() {};
};

extern ActorProfile Object42_Profile;

