#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 344  |  ov128  |  profile @ 0x020fed84
class Object344 : public StageEntity {
public:
	u8 _unrecovered_3f4[0x3dc4];
	static void *create();
	inline Object344() {};
	inline ~Object344() {};
};

extern ObjectProfile Object344_Profile;


static_assert(sizeof(Object344) == 0x41b8);
