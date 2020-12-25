#pragma once
#include "BotI.h"

class Bot : public BotI {
    void analyseSituation() override;
public:
    explicit Bot(Model* model) : BotI(model){};
};
