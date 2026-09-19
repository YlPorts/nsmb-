#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 74  |  ov078  |  profile @ 0x0217b390
class Object74 : public StageEntity {
public:
	void pendingDestroy();
	static void *create();
	inline Object74() {};
	inline ~Object74() {};
};

extern ActorProfile Object74_Profile;

