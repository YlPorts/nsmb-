#pragma once
#include "StageEntity.hpp"
#include "../graphics/3d/model.hpp"

// Reconstructed name for the shared model-owning A2DE base.
// These inline special members reproduce the observed constructor/destructor
// sequences; the base's gameplay overrides have not all been recovered.
class ModelEntity : public StageEntity {
public:
    Model model; /* 0x3F4 */
    Vec2_32 _484;
    Vec2_32 _490;
    u8 _unrecovered_49c[4];

    inline ModelEntity() {}
    virtual inline ~ModelEntity() {}
};
static_assert(sizeof(ModelEntity) == 0x4a0);
