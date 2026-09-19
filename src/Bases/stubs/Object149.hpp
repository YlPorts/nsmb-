#pragma once
#include "../../graphics/3d/modelanm.hpp"
#include "../../graphics/3d/animation.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 149  |  ov026  |  profile @ 0x0213d878
class Object149 : public StageEntity {
public:

	ModelAnm _3f4; /* 0x3F4 */
	Animation _49c; /* 0x49C */
	u8 _pad_4bc[0x10];
	Vec3_32 _4cc; /* 0x4CC */
	u8 _pad_4dc[0x1c];

	s32 onDestroy();
	void pendingDestroy();
	static void *create();
	inline Object149() {};
	inline ~Object149() {};
};
NTR_SIZE_GUARD(Object149, 0x4F8);

extern ActorProfile Object149_Profile;

