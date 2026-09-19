#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 63  |  ov080  |  profile @ 0x0217d810
class Object63 : public StageEntity {
public:

	Vec3_32 _3f4; /* 0x3F4 */
	u8 _pad_404[0x10];

	static void *create();
	inline Object63() {};
	inline ~Object63() {};
};
NTR_SIZE_GUARD(Object63, 0x414);

extern ActorProfile Object63_Profile;

