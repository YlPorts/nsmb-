#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 75  |  ov079  |  profile @ 0x0217c1c0
class Object75 : public StageEntity {
public:
	void pendingDestroy();
	void _21();
	void _23();
	static void *create();
	inline Object75() {};
	inline ~Object75() {};
};

extern ActorProfile Object75_Profile;

// MainProfileTable slot 76  |  ov079  |  profile @ 0x0217c1cc
class Object76 : public StageEntity {
public:
	u8 _unrecovered_3f4[0xa34];
	static void *create();
	inline Object76() {};
	inline ~Object76() {};
};

extern ActorProfile Object76_Profile;


static_assert(sizeof(Object76) == 0xe28);
