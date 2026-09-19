#pragma once
#include "../../graphics/3d/texture.hpp"
#include "../../Collision/platform.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 198  |  ov088  |  profile @ 0x021822e0
class Object198 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	Texture _3f4; /* 0x3F4 */
	u8 _unrecovered_3fc[0x50];
	RotatingPlatform _44c; /* 0x44C */
	u8 _unrecovered_4bc[0x1c];

	static void *create();
	inline Object198() {};
	inline ~Object198() {};
};
static_assert(sizeof(Object198) == 0x4d8);

extern ActorProfile Object198_Profile;

