#pragma once
#include "../ModelAnmEntity.hpp"
#include "../../Vec.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 134  |  ov123  |  profile @ 0x0218f3e8
class Object134 : public ModelAnmEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	u8 _unrecovered_4bc[0x4];
	Vec3_32 _4c0; /* 0x4C0 */
	u8 _unrecovered_4d0[0x54];

	static void *create();
	inline Object134() {};
	inline ~Object134() {};
};
static_assert(sizeof(Object134) == 0x524);

extern ActorProfile Object134_Profile;

