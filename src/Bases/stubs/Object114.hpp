#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 114  |  ov040  |  profile @ 0x02146720
class Object114 : public StageEntity {
public:
	s32 onDestroy();
	void pendingDestroy();
	void _23();
	static void *create();
	inline Object114() {};
	inline ~Object114() {};
};

extern ActorProfile Object114_Profile;

