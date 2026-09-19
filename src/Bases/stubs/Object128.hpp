#pragma once
#include "../ModelAnmEntity.hpp"
#include "../../graphics/3d/model.hpp"
#include "../../graphics/3d/animation.hpp"
#include "../../Vec.hpp"
#include "../../Collision/activecollider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 128  |  ov016  |  profile @ 0x02133a88
class Object128 : public ModelAnmEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	Model _4bc; /* 0x4BC */
	Animation _54c; /* 0x54C */
	ActiveCollider _56c; /* 0x56C */
	ActiveCollider _61c; /* 0x61C */
	ActiveCollider _6cc; /* 0x6CC */
	ActiveCollider _77c; /* 0x77C */
	u8 _unrecovered_82c[0x60];
	Vec3_32 _88c; /* 0x88C */
	Vec3_32 _89c; /* 0x89C */
	Vec3_32 _8ac; /* 0x8AC */
	Vec3_32 _8bc; /* 0x8BC */
	Vec3_32 _8cc; /* 0x8CC */
	Vec3_32 _8dc; /* 0x8DC */
	Vec3_32 _8ec; /* 0x8EC */
	Vec3_32 _8fc; /* 0x8FC */
	u8 _unrecovered_90c[0x7c];

	s32 onDestroy();
	void _22();
	void _24();
	void _25();
	void _26();
	void _27();
	void entityCollision();
	static void *create();
	inline Object128() {};
	inline ~Object128() {};
};
static_assert(sizeof(Object128) == 0x988);

extern ActorProfile Object128_Profile;

