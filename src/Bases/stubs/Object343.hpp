#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 343  |  ov128  |  profile @ 0x020ffda8
class Object343 : public StageEntity {
public:
	u8 _unrecovered_3f4[0x3148];
	static void *create();
	inline Object343() {};
	inline ~Object343() {};
};

extern ObjectProfile Object343_Profile;


static_assert(sizeof(Object343) == 0x353c);
