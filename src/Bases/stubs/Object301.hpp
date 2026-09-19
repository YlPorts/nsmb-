#pragma once
#include "../ModelAnmEntity.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 301  |  ov025  |  profile @ 0x02141a50
class Object301 : public ModelAnmEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.

	static void *create();
	inline Object301() {};
	inline ~Object301() {};
};
static_assert(sizeof(Object301) == 0x4bc);

extern ActorProfile Object301_Profile;

