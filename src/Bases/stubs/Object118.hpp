#pragma once
#include "../ModelAnmEntity.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 118  |  ov080  |  profile @ 0x0217d968
class Object118 : public ModelAnmEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	u8 _unrecovered_4bc[0x20];

	static void *create();
	inline Object118() {};
	inline ~Object118() {};
};
static_assert(sizeof(Object118) == 0x4dc);

extern ActorProfile Object118_Profile;

