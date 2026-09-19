#pragma once
#include "../../Collision/Collider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 211  |  ov010  |  profile @ 0x0212704c
class Object211 : public StageEntity {
public:

	u8 _pad_3f4[0x1ec];
	Collider _5e0; /* 0x5E0 */
	u8 _pad_640[0xc];
	Vec3_32 _64c; /* 0x64C */
	Vec3_32 _65c; /* 0x65C */
	u8 _pad_66c[0x38];
	Vec3_32 _6a4; /* 0x6A4 */
	u8 _pad_6b4[0x4];

	static void *create();
	inline Object211() {};
	inline ~Object211() {};
};
NTR_SIZE_GUARD(Object211, 0x6B8);

extern ActorProfile Object211_Profile;

