#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 214  |  ov109  |  profile @ 0x0218c638
class Object214 : public StageEntity {
public:
	bool _01();
	void pendingDestroy();
	bool onHeapCreated();
	static void *create();
	inline Object214() {};
	inline ~Object214() {};
};

extern ActorProfile Object214_Profile;

