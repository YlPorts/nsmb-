#pragma once
#include "../../graphics/3d/model.hpp"
#include "../../Vec.hpp"
#include "../../Collision/platform.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 210  |  ov118  |  profile @ 0x0218feec
class Object210 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	Model _3f4; /* 0x3F4 */
	RotatingPlatform _484; /* 0x484 */
	Vec3_16 _4f4; /* 0x4F4 */
	Vec3_16 _500; /* 0x500 */
	Vec3_32 _50c; /* 0x50C */
	u8 _unrecovered_51c[0x10];
	Vec3_32 _52c; /* 0x52C */
	Vec3_16 _53c; /* 0x53C */
	Vec3_32 _548[7]; /* 0x548 */
	u8 _unrecovered_5b8[0x24];

	static void *create();
	inline Object210() {};
	inline ~Object210() {};
};
static_assert(sizeof(Object210) == 0x5dc);

extern ActorProfile Object210_Profile;

