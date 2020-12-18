#pragma once
#include "../Interfaces/IOperation.h"

class Print : public IOperation {
public:
    void execute(std::list<std::string>& args, Context & ctx) const override;
};
