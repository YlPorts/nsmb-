#pragma once
#include "../../graphics/3d/modelanm.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 90  |  ov027  |  profile @ 0x0213cd18
class Object90 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	ModelAnm _3f4[2]; /* 0x3F4 */
	u8 _unrecovered_544[0x10];

	static void *create();
	inline Object90() {};
	inline ~Object90() {};
};
static_assert(sizeof(Object90) == 0x554);

extern ActorProfile Object90_Profile;

