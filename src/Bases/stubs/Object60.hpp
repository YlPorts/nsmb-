#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 60  |  ov025  |  profile @ 0x021416b0
class Object60 : public StageEntity {
public:

	u8 _pad_3f4[0xc];
	Vec3_32 _400; /* 0x400 */
	Vec3_32 _410; /* 0x410 */
	u8 _pad_420[0x20];

	static void *create();
	inline Object60() {};
	inline ~Object60() {};
};
static_assert(sizeof(Object60) == 0x440);

extern ActorProfile Object60_Profile;

