#pragma once
#include "../Actor.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 317  |  ov008  |  profile @ 0x020e59a8
class Object317 : public Actor {
public:
	void pendingDestroy();
	s32 onDestroy();
	static void *create();
	inline Object317() {};
	inline ~Object317() {};
};

extern ActorProfile Object317_Profile;

