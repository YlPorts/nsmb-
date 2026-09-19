#pragma once
#include "../../graphics/3d/modelanm.hpp"
#include "../../graphics/3d/model.hpp"
#include "../../graphics/3d/animation.hpp"
#include "../../Vec.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 108  |  ov070  |  profile @ 0x02177620
class Object108 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	ModelAnm _3f4; /* 0x3F4 */
	Model _49c; /* 0x49C */
	Animation _52c; /* 0x52C */
	Vec2_32 _54c[64]; /* 0x54C */
	u8 _unrecovered_84c[0x10];

	static void *create();
	inline Object108() {};
	inline ~Object108() {};
};
static_assert(sizeof(Object108) == 0x85c);

extern ActorProfile Object108_Profile;

