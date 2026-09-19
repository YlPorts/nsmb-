#pragma once
#include "../ModelEntity.hpp"
#include "../../Vec.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 124  |  ov110  |  profile @ 0x0218a800
class Object124 : public ModelEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	u8 _unrecovered_4a0[0x4];
	Vec2_32 _4a4[2]; /* 0x4A4 */
	u8 _unrecovered_4bc[0x1c];

	static void *create();
	inline Object124() {};
	inline ~Object124() {};
};
static_assert(sizeof(Object124) == 0x4d8);

extern ActorProfile Object124_Profile;

