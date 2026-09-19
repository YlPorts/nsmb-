#pragma once
#include "../ModelEntity.hpp"
#include "../../Vec.hpp"
#include "../../Collision/Collider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 80  |  ov054  |  profile @ 0x0216cec8
class Object80 : public ModelEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	u8 _unrecovered_4a0[0x4];
	Collider _4a4; /* 0x4A4 */
	u8 _unrecovered_504[0xc];
	Vec2_32 _510; /* 0x510 */
	u8 _unrecovered_51c[0x1c];

	static void *create();
	inline Object80() {};
	inline ~Object80() {};
};
static_assert(sizeof(Object80) == 0x538);

extern ActorProfile Object80_Profile;

