#pragma once
#include "../ModelAnmEntity.hpp"
#include "../../graphics/3d/animation.hpp"
#include "../../Vec.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 113  |  ov028  |  profile @ 0x021413d0
class Object113 : public ModelAnmEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	u8 _unrecovered_4bc[0x28];
	Animation _4e4; /* 0x4E4 */
	u8 _unrecovered_504[0x18];
	Vec3_32 _51c; /* 0x51C */
	Vec3_32 _52c; /* 0x52C */
	u8 _unrecovered_53c[0x88];

	s32 onDestroy();
	void pendingDestroy();
	void _36();
	void _25();
	void _27();
	void _26();
	void _24();
	static void *create();
	inline Object113() {};
	inline ~Object113() {};
};
static_assert(sizeof(Object113) == 0x5c4);

extern ActorProfile Object113_Profile;

