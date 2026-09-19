#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 105  |  ov090  |  profile @ 0x02185478
class Object105 : public StageEntity {
public:
	s32 onDestroy();
	void pendingDestroy();
	static void *create();
	inline Object105() {};
	inline ~Object105() {};
};

extern ActorProfile Object105_Profile;

