#pragma once
#include "action.h"

class CloseDoor : public Action {
    public:
        Result perform(Engine& engine) override;

        // actor->get_position;
};