#pragma once
#include "StageEntity.hpp"
#include "../graphics/3d/modelanm.hpp"

// Reconstructed name for the shared A2DE base at 0x020CEE34.
// Allocation and member layout are recovered; gameplay overrides remain pending.
class ModelAnmEntity : public StageEntity {
public:
    ModelAnm model; /* 0x3F4 */
    u32 _49c;
    Vec2_32 _4a0;
    Vec2_32 _4ac;
    u8 _unrecovered_4b8[4];

    ModelAnmEntity();
    virtual ~ModelAnmEntity();
};
static_assert(sizeof(ModelAnmEntity) == 0x4bc);
