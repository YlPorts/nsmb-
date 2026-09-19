#pragma once
#include "../../Minigame/MGScene.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 336  |  ov130  |  profile @ 0x02138d90
class Object336 : public MGScene {
public:
	void pendingDestroy();
	s32 onDestroy();
	static void *create();
	inline Object336() {};
	inline ~Object336() {};
};

extern ActorProfile Object336_Profile;

