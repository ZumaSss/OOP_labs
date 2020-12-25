#pragma once
#include "Player.h"
#include "Context.h"

class BotI : public Player {
protected:
    std::pair <int, int> possibleMove;
    Model *tiedModel;
    virtual void analyseSituation() = 0;
public:
    explicit BotI(Model *model) {
        tiedModel = model;
    }
    std::pair <int, int> doMove() override;
};
