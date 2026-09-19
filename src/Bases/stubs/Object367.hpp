#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 367  |  ov129  |  profile @ 0x021193ac
class Object367 : public StageEntity {
public:
	u8 _unrecovered_3f4[0x1438];
	static void *create();
	inline Object367() {};
	inline ~Object367() {};
};

extern ObjectProfile Object367_Profile;


static_assert(sizeof(Object367) == 0x182c);
