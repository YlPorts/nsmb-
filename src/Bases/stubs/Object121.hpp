#pragma once
#include "../../graphics/3d/model.hpp"
#include "../../Vec.hpp"
#include "../../Collision/activecollider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 121  |  ov054  |  profile @ 0x02170130
class Object121 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	Model _3f4; /* 0x3F4 */
	u8 _unrecovered_484[0x8];
	ActiveCollider _48c[10]; /* 0x48C */
	Vec2_32 _b6c[10]; /* 0xB6C */
	Vec2_32 _be4[10]; /* 0xBE4 */
	Vec2_32 _c5c[10]; /* 0xC5C */
	Vec3_16 _cd4[10]; /* 0xCD4 */
	u8 _unrecovered_d4c[0x28];

	void _21();
	void pendingDestroy();
	static void *create();
	inline Object121() {};
	inline ~Object121() {};
};
static_assert(sizeof(Object121) == 0xd74);

extern ActorProfile Object121_Profile;

