#pragma once
#include "../ModelAnmEntity.hpp"
#include "../../graphics/3d/model.hpp"
#include "../../Vec.hpp"
#include "../../Collision/activecollider.hpp"
#include "../../Collision/Collider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 36  |  ov012  |  profile @ 0x021320a0
class Object36 : public ModelAnmEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	u8 _unrecovered_4bc[0x4];
	Model _4c0; /* 0x4C0 */
	Vec3_32 _550; /* 0x550 */
	Vec3_32 _560; /* 0x560 */
	Collider _570; /* 0x570 */
	u8 _unrecovered_5d0[0xc];
	ActiveCollider _5dc; /* 0x5DC */
	ActiveCollider _68c; /* 0x68C */
	u8 _unrecovered_73c[0x20];

	void pendingDestroy();
	static void *create();
	inline Object36() {};
	inline ~Object36() {};
};
static_assert(sizeof(Object36) == 0x75c);

extern ActorProfile Object36_Profile;

