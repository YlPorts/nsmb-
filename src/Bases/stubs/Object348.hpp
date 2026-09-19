#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 348  |  ov128  |  profile @ 0x020ff0e0
class Object348 : public StageEntity {
public:
	u8 _unrecovered_3f4[0x2d70];
	static void *create();
	inline Object348() {};
	inline ~Object348() {};
};

extern ObjectProfile Object348_Profile;


static_assert(sizeof(Object348) == 0x3164);
