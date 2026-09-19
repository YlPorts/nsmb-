#pragma once
#include "../../graphics/3d/model.hpp"
#include "../../graphics/3d/animation.hpp"
#include "../../Vec.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 151  |  ov054  |  profile @ 0x0216cd90
class Object151 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	Model _3f4; /* 0x3F4 */
	Animation _484; /* 0x484 */
	u8 _unrecovered_4a4[0x10];
	Vec2_32 _4b4[2]; /* 0x4B4 */
	Vec2_32 _4cc[2]; /* 0x4CC */
	u8 _unrecovered_4e4[0x8];

	s32 onDestroy();
	void pendingDestroy();
	static void *create();
	inline Object151() {};
	inline ~Object151() {};
};
static_assert(sizeof(Object151) == 0x4ec);

extern ActorProfile Object151_Profile;

