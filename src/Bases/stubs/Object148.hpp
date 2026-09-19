#pragma once
#include "../../graphics/3d/modelanm.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 148  |  ov038  |  profile @ 0x02143368
class Object148 : public StageEntity {
public:

	ModelAnm _3f4; /* 0x3F4 */
	u8 _pad_49c[0x2c];
	Vec3_32 _4c8; /* 0x4C8 */
	u8 _pad_4d8[0x10];

	s32 onDestroy();
	void pendingDestroy();
	static void *create();
	inline Object148() {};
	inline ~Object148() {};
};
NTR_SIZE_GUARD(Object148, 0x4E8);

extern ActorProfile Object148_Profile;

