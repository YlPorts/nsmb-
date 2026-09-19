#pragma once
#include "../ModelAnmEntity.hpp"
#include "../../graphics/3d/model.hpp"
#include "../../Vec.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 69  |  ov054  |  profile @ 0x0216e16c
class Object69 : public ModelAnmEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	Model _4bc; /* 0x4BC */
	u8 _unrecovered_54c[0x4];
	Vec3_32 _550; /* 0x550 */
	Vec3_32 _560; /* 0x560 */
	Vec3_16 _570; /* 0x570 */
	u8 _unrecovered_57c[0x44];

	void entityCollision();
	static void *create();
	inline Object69() {};
	inline ~Object69() {};
};
static_assert(sizeof(Object69) == 0x5c0);

extern ActorProfile Object69_Profile;

