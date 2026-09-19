#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 128  |  ov016  |  profile @ 0x02133a88
class Object128 : public StageEntity {
public:
	s32 onDestroy();
	void _22();
	void _24();
	void _25();
	void _26();
	void _27();
	void entityCollision();
	static void *create();
	inline Object128() {};
	inline ~Object128() {};
};

extern ActorProfile Object128_Profile;

