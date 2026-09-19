#pragma once
#include "../ModelEntity.hpp"
#include "../../Vec.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 237  |  ov054  |  profile @ 0x0216d154
class Object237 : public ModelEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	u8 _unrecovered_4a0[0x14];
	Vec3_32 _4b4; /* 0x4B4 */
	u8 _unrecovered_4c4[0x44];

	void _15();
	void _37();
	void _36();
	static void *create();
	inline Object237() {};
	inline ~Object237() {};
};
static_assert(sizeof(Object237) == 0x508);

extern ActorProfile Object237_Profile;

