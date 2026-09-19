#pragma once
#include "../../graphics/3d/model.hpp"
#include "../../Vec.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 212  |  ov116  |  profile @ 0x0218f168
class Object212 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	Model _3f4[4]; /* 0x3F4 */
	u8 _unrecovered_634[0x4];
	Vec3_32 _638; /* 0x638 */
	Vec3_32 _648; /* 0x648 */
	Vec3_32 _658; /* 0x658 */
	Vec3_32 _668; /* 0x668 */
	Vec3_32 _678; /* 0x678 */
	Vec3_16 _688; /* 0x688 */
	u8 _unrecovered_694[0x34];

	static void *create();
	inline Object212() {};
	inline ~Object212() {};
};
static_assert(sizeof(Object212) == 0x6c8);

extern ActorProfile Object212_Profile;

