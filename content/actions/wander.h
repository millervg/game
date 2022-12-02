#pragma once

#include "action.h"
#include "vec.h"

class Wander : public Action {
public:
    Result perform(Engine& engine) override;
};