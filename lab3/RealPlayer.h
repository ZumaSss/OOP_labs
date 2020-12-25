#pragma once
#include "Player.h"

class RealPlayer : public Player {
public:
    std::pair <int, int> doMove() override;
};
