#pragma once
#include "../../Collision/Collider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 72  |  ov054  |  profile @ 0x0217067c
class Object72 : public StageEntity {
public:

	u8 _pad_3f4[0x4];
	Collider _3f8; /* 0x3F8 */
	u8 _pad_458[0xc];
	Vec3_32 _464; /* 0x464 */
	u8 _pad_474[0xc];

	static void *create();
	inline Object72() {};
	inline ~Object72() {};
};
NTR_SIZE_GUARD(Object72, 0x480);

extern ActorProfile Object72_Profile;

