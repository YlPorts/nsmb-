#pragma once
#include "../../graphics/3d/animationctrl.hpp"
#include "../../graphics/3d/model.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 78  |  ov013  |  profile @ 0x0213bbec
class Object78 : public StageEntity {
public:

	Model _3f4; /* 0x3F4 */
	AnimationCtrl _484; /* 0x484 */
	u8 _pad_4b0[0x1c];
	Vec2_32 _4cc; /* 0x4CC */
	Vec2_32 _4d8; /* 0x4D8 */
	u8 _pad_4e4[0x10];

	bool _01();
	s32 onDestroy();
	void pendingDestroy();
	static void *create();
	inline Object78() {};
	inline ~Object78() {};
};
static_assert(sizeof(Object78) == 0x4f4);

extern ActorProfile Object78_Profile;

