#pragma once
#include "../ModelAnmEntity.hpp"
#include "../../graphics/3d/animation.hpp"
#include "../../Vec.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 114  |  ov040  |  profile @ 0x02146720
class Object114 : public ModelAnmEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	Animation _4bc; /* 0x4BC */
	u8 _unrecovered_4dc[0x1c];
	Vec3_32 _4f8; /* 0x4F8 */
	u8 _unrecovered_508[0x38];

	s32 onDestroy();
	void pendingDestroy();
	void _23();
	static void *create();
	inline Object114() {};
	inline ~Object114() {};
};
static_assert(sizeof(Object114) == 0x540);

extern ActorProfile Object114_Profile;

