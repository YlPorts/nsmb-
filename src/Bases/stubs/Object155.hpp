#pragma once
#include "../../graphics/3d/modelanm.hpp"
#include "../../graphics/3d/model.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 155  |  ov082  |  profile @ 0x0217baa8
class Object155 : public StageEntity {
public:

	ModelAnm _3f4; /* 0x3F4 */
	Model _49c; /* 0x49C */
	u8 _pad_52c[0x10];
	Vec3_32 _53c; /* 0x53C */
	Vec3_32 _54c; /* 0x54C */
	Vec3_32 _55c; /* 0x55C */
	Vec3_32 _56c; /* 0x56C */
	Vec3_32 _57c; /* 0x57C */
	Vec2_32 _58c; /* 0x58C */
	u8 _pad_598[0x8];

	s32 onDestroy();
	void pendingDestroy();
	static void *create();
	inline Object155() {};
	inline ~Object155() {};
};
NTR_SIZE_GUARD(Object155, 0x5A0);

extern ActorProfile Object155_Profile;

