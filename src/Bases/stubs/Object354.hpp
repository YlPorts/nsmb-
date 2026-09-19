#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 354  |  ov128  |  profile @ 0x021005f0
class Object354 : public StageEntity {
public:
	u8 _unrecovered_3f4[0x26f4];
	static void *create();
	inline Object354() {};
	inline ~Object354() {};
};

extern ObjectProfile Object354_Profile;


static_assert(sizeof(Object354) == 0x2ae8);
