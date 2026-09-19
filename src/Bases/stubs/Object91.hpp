#pragma once
#include "../ModelAnmEntity.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 91  |  ov036  |  profile @ 0x02143770
class Object91 : public ModelAnmEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	u8 _unrecovered_4bc[0x40];

	void _25();
	void _30();
	void _27();
	static void *create();
	inline Object91() {};
	inline ~Object91() {};
};
static_assert(sizeof(Object91) == 0x4fc);

extern ActorProfile Object91_Profile;

