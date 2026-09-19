#pragma once
#include "../../graphics/3d/texture.hpp"
#include "../../graphics/3d/model.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slots 47, 48 share this class.
// ov100  |  vtable @ 0x02189798
class Object47 : public StageEntity {
public:

	Texture _3f4; /* 0x3F4 */
	u8 _pad_3fc[0x30];
	Model _42c; /* 0x42C */
	Model _4bc; /* 0x4BC */
	u8 _pad_54c[0x84];
	Vec3_32 _5d0; /* 0x5D0 */
	Vec3_32 _5e0; /* 0x5E0 */
	u8 _pad_5f0[0x114];

	s32 onDestroy();
	void pendingDestroy();
	static void *create();
	static void *create2();
	inline Object47() {};
	inline ~Object47() {};
};
NTR_SIZE_GUARD(Object47, 0x704);

extern ActorProfile Object48_Profile;
extern ActorProfile Object47_Profile;
