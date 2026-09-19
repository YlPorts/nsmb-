#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 249  |  ov042  |  profile @ 0x02151d68
class Object249 : public StageEntity {
public:
	u8 _unrecovered_3f4[0x650];
	static void *create();
	inline Object249() {};
	inline ~Object249() {};
};

extern ActorProfile Object249_Profile;


static_assert(sizeof(Object249) == 0xa44);
