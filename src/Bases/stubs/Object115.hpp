#pragma once
#include "../../graphics/3d/model.hpp"
#include "../../graphics/3d/modelanm.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 115  |  ov040  |  profile @ 0x02146870
class Object115 : public StageEntity {
public:

	ModelAnm _3f4; /* 0x3F4 */
	Model _49c; /* 0x49C */
	Vec3_32 _52c; /* 0x52C */
	Vec3_16 _53c; /* 0x53C */
	u8 _pad_548[0x24];

	static void *create();
	inline Object115() {};
	inline ~Object115() {};
};
static_assert(sizeof(Object115) == 0x56c);

extern ActorProfile Object115_Profile;

