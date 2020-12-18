#pragma once

#include "../Context/Context.h"
#include "../Exceptions/Exceptions.h"
#include <list>

#define REGISTER_OPERATION(T, NAME) static OperationMaker<T> maker(#NAME)

class IOperation {
public:
    virtual void execute(std::list<std::string> &arg, Context & ctx) const = 0;

    virtual ~IOperation() = default;
};
