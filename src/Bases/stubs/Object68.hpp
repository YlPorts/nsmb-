#pragma once
#include "../ModelAnmEntity.hpp"
#include "../../graphics/3d/model.hpp"
#include "../../Vec.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 68  |  ov056  |  profile @ 0x02175478
class Object68 : public ModelAnmEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	Model _4bc; /* 0x4BC */
	u8 _unrecovered_54c[0x4];
	Vec3_32 _550; /* 0x550 */
	Vec3_32 _560; /* 0x560 */
	Vec3_16 _570; /* 0x570 */
	u8 _unrecovered_57c[0x30];

	static void *create();
	inline Object68() {};
	inline ~Object68() {};
};
static_assert(sizeof(Object68) == 0x5ac);

extern ActorProfile Object68_Profile;

// MainProfileTable slot 88  |  ov056  |  profile @ 0x02175484
class Object88 : public StageEntity {
public:
	static void *create();
	inline Object88() {};
	inline ~Object88() {};
};

extern ActorProfile Object88_Profile;

// MainProfileTable slot 89  |  ov056  |  profile @ 0x02175490
class Object89 : public StageEntity {
public:
	static void *create();
	inline Object89() {};
	inline ~Object89() {};
};

extern ActorProfile Object89_Profile;

