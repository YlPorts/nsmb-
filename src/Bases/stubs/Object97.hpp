#pragma once
#include "../../Vec.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 97  |  ov017  |  profile @ 0x02133d08
class Object97 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	u8 _unrecovered_3f4[0xc];
	Vec3_32 _400[2]; /* 0x400 */
	u8 _unrecovered_420[0x40];

	s32 onDestroy();
	void pendingDestroy();
	s32 onRender();
	static void *create();
	inline Object97() {};
	inline ~Object97() {};
};
static_assert(sizeof(Object97) == 0x460);

extern ActorProfile Object97_Profile;

