#pragma once

#include "action.h"
#include "vec.h"

class Wander : public Action {
public:
    Wander(Vec position);
    Result perform(Engine& engine) override;
private:
    Vec position;
};