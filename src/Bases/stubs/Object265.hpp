#pragma once
#include "../../Collision/Collider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 265  |  ov013  |  profile @ 0x0213bd2c
class Object265 : public StageEntity {
public:

	Collider _3f4; /* 0x3F4 */
	u8 _pad_454[0xc];
	Vec3_32 _460; /* 0x460 */
	Vec3_32 _470; /* 0x470 */
	u8 _pad_480[0x34];

	static void *create();
	inline Object265() {};
	inline ~Object265() {};
};
NTR_SIZE_GUARD(Object265, 0x4B4);

extern ActorProfile Object265_Profile;

