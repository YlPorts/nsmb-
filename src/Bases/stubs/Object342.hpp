#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 342  |  ov128  |  profile @ 0x020ffbb0
class Object342 : public StageEntity {
public:
	u8 _unrecovered_3f4[0x3704];
	static void *create();
	inline Object342() {};
	inline ~Object342() {};
};

extern ObjectProfile Object342_Profile;


static_assert(sizeof(Object342) == 0x3af8);
