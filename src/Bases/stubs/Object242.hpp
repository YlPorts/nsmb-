#pragma once
#include "../ModelAnmEntity.hpp"
#include "../../Vec.hpp"
#include "../../Collision/Collider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 242  |  ov054  |  profile @ 0x02171020
class Object242 : public ModelAnmEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	u8 _unrecovered_4bc[0x2c];
	Collider _4e8; /* 0x4E8 */
	u8 _unrecovered_548[0xc];
	Vec3_32 _554; /* 0x554 */
	u8 _unrecovered_564[0x8];
	Vec2_32 _56c; /* 0x56C */
	u8 _unrecovered_578[0x4c];
	Vec2_32 _5c4; /* 0x5C4 */
	u8 _unrecovered_5d0[0x18];

	static void *create();
	inline Object242() {};
	inline ~Object242() {};
};
static_assert(sizeof(Object242) == 0x5e8);

extern ActorProfile Object242_Profile;

// MainProfileTable slot 243  |  ov054  |  profile @ 0x0217102c
class Object243 : public StageEntity {
public:
	static void *create();
	inline Object243() {};
	inline ~Object243() {};
};

extern ActorProfile Object243_Profile;

// MainProfileTable slot 244  |  ov054  |  profile @ 0x02171038
class Object244 : public StageEntity {
public:
	static void *create();
	inline Object244() {};
	inline ~Object244() {};
};

extern ActorProfile Object244_Profile;

// MainProfileTable slot 245  |  ov054  |  profile @ 0x02171044
class Object245 : public StageEntity {
public:
	static void *create();
	inline Object245() {};
	inline ~Object245() {};
};

extern ActorProfile Object245_Profile;

// MainProfileTable slot 246  |  ov054  |  profile @ 0x02171050
class Object246 : public StageEntity {
public:
	static void *create();
	inline Object246() {};
	inline ~Object246() {};
};

extern ActorProfile Object246_Profile;

// MainProfileTable slot 247  |  ov054  |  profile @ 0x0217105c
class Object247 : public StageEntity {
public:
	static void *create();
	inline Object247() {};
	inline ~Object247() {};
};

extern ActorProfile Object247_Profile;

