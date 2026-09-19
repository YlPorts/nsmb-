#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 49  |  ov010  |  profile @ 0x02125088
class Object49 : public StageEntity {
public:
	s32 onRender();
	void pendingDestroy();
	s32 onDestroy();
	u8 _pad0[0x24];

	static void *create();
	inline Object49() {};
	inline ~Object49() {};
};

extern ActorProfile Object49_Profile;

