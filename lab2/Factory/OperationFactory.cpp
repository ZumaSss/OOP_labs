#include "OperationFactory.h"

OperationFactory& OperationFactory::creator() noexcept {
    static OperationFactory factory;
    return factory;
}

IOperation* OperationFactory::concreteProduct(const std::string& id) const {
    auto i = _opMakers.find(id);
    if (i == _opMakers.end()) throw NoSuchOperation();
    IOperationMaker *maker = i -> second;
    return (maker -> create(id));
}

void OperationFactory::clientCode(const std::string &operationName, IOperationMaker *maker) {
    if (_opMakers.find(operationName) != _opMakers.end()) throw InvalidRegistration();
    _opMakers[operationName] = maker;
}


