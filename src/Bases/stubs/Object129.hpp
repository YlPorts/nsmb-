#pragma once
#include "../ModelAnmEntity.hpp"
#include "../../Vec.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 129  |  ov017  |  profile @ 0x02133bd0
class Object129 : public ModelAnmEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	u8 _unrecovered_4bc[0xc];
	Vec3_32 _4c8; /* 0x4C8 */
	Vec3_32 _4d8; /* 0x4D8 */
	Vec3_32 _4e8; /* 0x4E8 */
	u8 _unrecovered_4f8[0xb8];

	void _22();
	void _24();
	void _25();
	void _26();
	void _27();
	void entityCollision();
	static void *create();
	inline Object129() {};
	inline ~Object129() {};
};
static_assert(sizeof(Object129) == 0x5b0);

extern ActorProfile Object129_Profile;

