#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 259  |  ov069  |  profile @ 0x02178438
class Object259 : public StageEntity {
public:
	void _23();
	void _30();
	static void *create();
	inline Object259() {};
	inline ~Object259() {};
};

extern ActorProfile Object259_Profile;

