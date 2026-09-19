#pragma once
#include "../../graphics/3d/animationctrl.hpp"
#include "../../graphics/3d/modelanm.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 135  |  ov018  |  profile @ 0x021324f8
class Object135 : public StageEntity {
public:

	ModelAnm _3f4; /* 0x3F4 */
	AnimationCtrl _49c; /* 0x49C */
	Vec3_32 _4c8; /* 0x4C8 */
	Vec3_32 _4d8; /* 0x4D8 */
	u8 _pad_4e8[0x98];
	Vec3_32 _580; /* 0x580 */
	u8 _pad_590[0xc];

	static void *create();
	inline Object135() {};
	inline ~Object135() {};
};
static_assert(sizeof(Object135) == 0x59c);

extern ActorProfile Object135_Profile;

