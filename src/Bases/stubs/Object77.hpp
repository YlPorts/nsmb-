#pragma once
#include "../ModelEntity.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 77  |  ov012  |  profile @ 0x021321ec
class Object77 : public ModelEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	u8 _unrecovered_4a0[0x8];

	s32 onDestroy();
	void pendingDestroy();
	static void *create();
	inline Object77() {};
	inline ~Object77() {};
};
static_assert(sizeof(Object77) == 0x4a8);

extern ActorProfile Object77_Profile;

