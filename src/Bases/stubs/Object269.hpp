#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 269  |  ov089  |  profile @ 0x0217fcf0
class Object269 : public StageEntity {
public:
	void pendingDestroy();
	void _11();
	static void *create();
	inline Object269() {};
	inline ~Object269() {};
};

extern ActorProfile Object269_Profile;

