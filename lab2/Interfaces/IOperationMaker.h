#pragma once
#include "IOperation.h"

class IOperationMaker {
public:
    virtual IOperation *create(const std::string &operationName) const = 0;
};
