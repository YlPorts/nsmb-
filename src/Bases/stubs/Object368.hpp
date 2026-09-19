#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 368  |  ov129  |  profile @ 0x02119598
class Object368 : public StageEntity {
public:
	u8 _unrecovered_3f4[0x288];
	static void *create();
	inline Object368() {};
	inline ~Object368() {};
};

extern ObjectProfile Object368_Profile;


static_assert(sizeof(Object368) == 0x67c);
