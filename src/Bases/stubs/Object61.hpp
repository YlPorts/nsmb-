#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 61  |  ov078  |  profile @ 0x0217b4c0
class Object61 : public StageEntity {
public:

	Vec3_32 _3f4; /* 0x3F4 */
	u8 _pad_404[0x24];

	static void *create();
	inline Object61() {};
	inline ~Object61() {};
};
static_assert(sizeof(Object61) == 0x428);

extern ActorProfile Object61_Profile;

