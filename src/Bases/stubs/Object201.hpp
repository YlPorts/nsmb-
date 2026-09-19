#pragma once
#include "../../graphics/3d/texture.hpp"
#include "../../Vec.hpp"
#include "../../Collision/platform.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 201  |  ov060  |  profile @ 0x021734e0
class Object201 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	Texture _3f4; /* 0x3F4 */
	u8 _unrecovered_3fc[0x20];
	SegmentPlatform _41c[35]; /* 0x41C */
	Vec2_32 _136c[36]; /* 0x136C */
	Vec2_32 _151c[36]; /* 0x151C */
	Vec2_32 _16cc[137]; /* 0x16CC */
	u8 _unrecovered_1d38[0x138];

	static void *create();
	inline Object201() {};
	inline ~Object201() {};
};
static_assert(sizeof(Object201) == 0x1e70);

extern ActorProfile Object201_Profile;

