#pragma once
#include "../ModelAnmEntity.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 73  |  ov034  |  profile @ 0x02145388
class Object73 : public ModelAnmEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	u8 _unrecovered_4bc[0x60];

	void _36();
	static void *create();
	inline Object73() {};
	inline ~Object73() {};
};
static_assert(sizeof(Object73) == 0x51c);

extern ActorProfile Object73_Profile;

