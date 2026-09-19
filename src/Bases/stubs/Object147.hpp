#pragma once
#include "../../graphics/3d/modelanm.hpp"
#include "../../Vec.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 147  |  ov068  |  profile @ 0x021792c0
class Object147 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	ModelAnm _3f4; /* 0x3F4 */
	u8 _unrecovered_49c[0x8];
	Vec3_32 _4a4; /* 0x4A4 */
	Vec2_32 _4b4[64]; /* 0x4B4 */
	u8 _unrecovered_7b4[0xc];

	s32 onDestroy();
	void pendingDestroy();
	static void *create();
	inline Object147() {};
	inline ~Object147() {};
};
static_assert(sizeof(Object147) == 0x7c0);

extern ActorProfile Object147_Profile;

