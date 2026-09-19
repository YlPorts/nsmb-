#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 350  |  ov128  |  profile @ 0x02100000
class Object350 : public StageEntity {
public:
	u8 _unrecovered_3f4[0x2ab8];
	static void *create();
	inline Object350() {};
	inline ~Object350() {};
};

extern ObjectProfile Object350_Profile;


static_assert(sizeof(Object350) == 0x2eac);
