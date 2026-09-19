#pragma once
#include "../ModelAnmEntity.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 120  |  ov108  |  profile @ 0x0218aef0
class Object120 : public ModelAnmEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	u8 _unrecovered_4bc[0x70];

	void _36();
	static void *create();
	inline Object120() {};
	inline ~Object120() {};
};
static_assert(sizeof(Object120) == 0x52c);

extern ActorProfile Object120_Profile;

