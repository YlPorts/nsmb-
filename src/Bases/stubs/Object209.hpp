#pragma once
#include "../../graphics/3d/texture.hpp"
#include "../../graphics/3d/model.hpp"
#include "../../Vec.hpp"
#include "../../Collision/Collider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 209  |  ov088  |  profile @ 0x02182578
class Object209 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	Model _3f4; /* 0x3F4 */
	Texture _484; /* 0x484 */
	u8 _unrecovered_48c[0x24];
	Collider _4b0; /* 0x4B0 */
	u8 _unrecovered_510[0xc];
	Collider _51c; /* 0x51C */
	u8 _unrecovered_57c[0xc];
	Collider _588; /* 0x588 */
	u8 _unrecovered_5e8[0xc];
	Vec2_32 _5f4[3]; /* 0x5F4 */
	u8 _unrecovered_618[0x8];
	Vec2_32 _620; /* 0x620 */
	Vec2_32 _62c; /* 0x62C */
	Vec2_32 _638; /* 0x638 */
	Vec2_32 _644; /* 0x644 */
	Vec2_32 _650; /* 0x650 */
	u8 _unrecovered_65c[0xc];
	Vec3_32 _668; /* 0x668 */
	u8 _unrecovered_678[0x14];

	static void *create();
	inline Object209() {};
	inline ~Object209() {};
};
static_assert(sizeof(Object209) == 0x68c);

extern ActorProfile Object209_Profile;

