#pragma once
#include "../../graphics/3d/modelanm.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 81  |  ov035  |  profile @ 0x02143af0
class Object81 : public StageEntity {
public:

	ModelAnm _3f4; /* 0x3F4 */
	u8 _pad_49c[0x8];
	Vec3_32 _4a4; /* 0x4A4 */
	u8 _pad_4b4[0x8];

	void _21();
	s32 onDestroy();
	static void *create();
	inline Object81() {};
	inline ~Object81() {};
};
NTR_SIZE_GUARD(Object81, 0x4BC);

extern ActorProfile Object81_Profile;

