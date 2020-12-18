#pragma once
#include "../Interfaces/IOperation.h"
#include <cmath>

class Sqrt : public IOperation {
public:
    void execute(std::list<std::string>& args, Context & ctx) const override;
};
