#pragma once
#include "../../graphics/3d/texture.hpp"
#include "../../Vec.hpp"
#include "../../Collision/platform.hpp"
#include "../../Collision/activecollider.hpp"
#include "../../Collision/Collider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 168  |  ov020  |  profile @ 0x02133090
class Object168 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	Texture _3f4[5]; /* 0x3F4 */
	u8 _unrecovered_41c[0xa0];
	Collider _4bc; /* 0x4BC */
	u8 _unrecovered_51c[0x1c];
	ActiveCollider _538[3]; /* 0x538 */
	RotatingPlatform _748[2]; /* 0x748 */
	Vec2_32 _828; /* 0x828 */
	u8 _unrecovered_834[0x18];
	Vec2_32 _84c[3]; /* 0x84C */
	Vec2_32 _870[2]; /* 0x870 */
	u8 _unrecovered_888[0x34];

	static void *create();
	inline Object168() {};
	inline ~Object168() {};
};
static_assert(sizeof(Object168) == 0x8bc);

extern ActorProfile Object168_Profile;

