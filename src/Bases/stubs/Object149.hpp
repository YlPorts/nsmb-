#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 149  |  ov026  |  profile @ 0x0213d878
class Object149 : public StageEntity {
public:
	s32 onDestroy();
	void pendingDestroy();
	static void *create();
	inline Object149() {};
	inline ~Object149() {};
};

extern ActorProfile Object149_Profile;

