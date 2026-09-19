#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 94  |  ov010  |  profile @ 0x021261b4
class Object94 : public StageEntity {
public:

	u8 _pad_3f2[0x82];

	void pendingDestroy();
	static void *create();
	static void *create2();
	inline Object94() {};
	inline ~Object94() {};
};
static_assert(sizeof(Object94) == 0x474);

extern ActorProfile Object94_Profile;

// MainProfileTable slot 95  |  ov010  |  profile @ 0x021261c0
// Profile 95 constructs Object94; there is no separate runtime class.

extern ActorProfile Object95_Profile;

