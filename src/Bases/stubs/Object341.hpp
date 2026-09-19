#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 341  |  ov128  |  profile @ 0x020ff560
class Object341 : public StageEntity {
public:
	u8 _unrecovered_3f4[0x2f24];
	static void *create();
	inline Object341() {};
	inline ~Object341() {};
};

extern ObjectProfile Object341_Profile;


static_assert(sizeof(Object341) == 0x3318);
