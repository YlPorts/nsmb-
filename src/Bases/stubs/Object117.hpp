#pragma once
#include "../ModelAnmEntity.hpp"
#include "../../Vec.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 117  |  ov080  |  profile @ 0x0217d6e0
class Object117 : public ModelAnmEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	Vec2_32 _4bc[4]; /* 0x4BC */
	Vec2_32 _4ec[9]; /* 0x4EC */
	Vec3_32 _558; /* 0x558 */
	Vec3_32 _568; /* 0x568 */
	u8 _unrecovered_578[0x38];
	Vec3_32 _5b0; /* 0x5B0 */
	u8 _unrecovered_5c0[0x48];

	static void *create();
	inline Object117() {};
	inline ~Object117() {};
};
static_assert(sizeof(Object117) == 0x608);

extern ActorProfile Object117_Profile;

