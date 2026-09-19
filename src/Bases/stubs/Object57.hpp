#pragma once
#include "../../Vec.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 57  |  ov048  |  profile @ 0x02148a48
class Object57 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	u8 _unrecovered_3f4[0x4];
	Vec3_32 _3f8[8]; /* 0x3F8 */
	u8 _unrecovered_478[0x64];

	static void *create();
	inline Object57() {};
	inline ~Object57() {};
};
static_assert(sizeof(Object57) == 0x4dc);

extern ActorProfile Object57_Profile;

