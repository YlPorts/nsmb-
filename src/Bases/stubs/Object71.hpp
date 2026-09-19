#pragma once
#include "../../Collision/Collider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 71  |  ov054  |  profile @ 0x02170538
class Object71 : public StageEntity {
public:

	u8 _pad_3f4[0x4];
	Collider _3f8; /* 0x3F8 */
	u8 _pad_458[0xc];
	Vec3_32 _464; /* 0x464 */
	u8 _pad_474[0x10];

	void _11();
	static void *create();
	inline Object71() {};
	inline ~Object71() {};
};
static_assert(sizeof(Object71) == 0x484);

extern ActorProfile Object71_Profile;

