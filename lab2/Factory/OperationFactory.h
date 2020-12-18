#pragma once

#include "../Interfaces/IOperation.h"
#include "../Interfaces/IOperationMaker.h"

class OperationFactory {
public:
    static OperationFactory &creator() noexcept;
    IOperation *concreteProduct(const std::string &id) const;
    void clientCode(const std::string &operationName, IOperationMaker *maker);

private:
    OperationFactory() = default;
    std::map<std::string, IOperationMaker*> _opMakers;
};

