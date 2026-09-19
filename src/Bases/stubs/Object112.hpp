#pragma once
#include "../ModelAnmEntity.hpp"
#include "../../Vec.hpp"
#include "../../Collision/activecollider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 112  |  ov046  |  profile @ 0x02148548
class Object112 : public ModelAnmEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	ActiveCollider _4bc; /* 0x4BC */
	u8 _unrecovered_56c[0x10];
	Vec3_32 _57c; /* 0x57C */
	Vec3_32 _58c; /* 0x58C */
	Vec2_32 _59c[2]; /* 0x59C */
	u8 _unrecovered_5b4[0x30];

	void _21();
	void onStomped();
	static void *create();
	inline Object112() {};
	inline ~Object112() {};
};
static_assert(sizeof(Object112) == 0x5e4);

extern ActorProfile Object112_Profile;

