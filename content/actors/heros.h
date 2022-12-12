#pragma once

#include "herotype.h"
#include "none.h"
#include "move.h"
#include "closedoor.h"
#include "knife.h"
#include "opendoor.h"

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
        }}
    };

    constexpr int default_speed{8};
    const HeroType knight{"knight", default_speed, 10, std::make_shared<Knife>(2), key_bindings};
    
}
