#pragma once
#include "../../graphics/3d/texture.hpp"
#include "../../Collision/Collider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 188  |  ov097  |  profile @ 0x02188970
class Object188 : public StageEntity {
public:

	// A2DE allocation/member layout; other methods remain incomplete.
	u8 _unrecovered_3f4[0xc];
	Texture _400[3]; /* 0x400 */
	u8 _unrecovered_418[0x18];
	Collider _430; /* 0x430 */
	u8 _unrecovered_490[0xb0];

	static void *create();
	inline Object188() {};
	inline ~Object188() {};
};
static_assert(sizeof(Object188) == 0x540);

extern ActorProfile Object188_Profile;

