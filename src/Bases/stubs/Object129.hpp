#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 129  |  ov017  |  profile @ 0x02133bd0
class Object129 : public StageEntity {
public:
	void _22();
	void _24();
	void _25();
	void _26();
	void _27();
	void entityCollision();
	static void *create();
	inline Object129() {};
	inline ~Object129() {};
};

extern ActorProfile Object129_Profile;

