#pragma once
#include "../ModelAnmEntity.hpp"
#include "../../graphics/3d/model.hpp"
#include "../../Vec.hpp"
#include "../../Collision/activecollider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 70  |  ov056  |  profile @ 0x02175818
class Object70 : public ModelAnmEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	ActiveCollider _4bc; /* 0x4BC */
	u8 _unrecovered_56c[0x10];
	Model _57c; /* 0x57C */
	u8 _unrecovered_60c[0x14];
	Vec3_32 _620; /* 0x620 */
	Vec3_32 _630; /* 0x630 */
	Vec3_32 _640; /* 0x640 */
	Vec3_32 _650; /* 0x650 */
	Vec3_16 _660; /* 0x660 */
	Vec3_16 _66c; /* 0x66C */
	u8 _unrecovered_678[0x24];

	static void *create();
	inline Object70() {};
	inline ~Object70() {};
};
static_assert(sizeof(Object70) == 0x69c);

extern ActorProfile Object70_Profile;

