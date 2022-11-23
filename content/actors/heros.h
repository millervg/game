#pragma once

#include "herotype.h"
#include "none.h"
#include "move.h"
#include "closedoor.h"
#include "rest.h"

namespace Heros {
    
    const std::unordered_map<std::string, Reaction> key_bindings = {
        {"Right", []() {
            return std::make_unique<Move>(Vec{1, 0});
        }},
        {"Left", []() {
            return std::make_unique<Move>(Vec{-1, 0});
        }},
        {"Down", []() {
            return std::make_unique<Move>(Vec{0, -1});
        }},
        {"Up", []() {
            return std::make_unique<Move>(Vec{0, 1});
        }},
        {"C", []() {
            return std::make_unique<CloseDoor>();
        }},
        {"R", []() {
            return std::make_unique<Rest>();
        }}
    };

    constexpr int default_speed{8};
    const HeroType nobody{"none", default_speed, 1, std::make_shared<None>(), {}};
    const HeroType knight{"knight", default_speed, 1, std::make_shared<None>(), key_bindings};
    
}
