#pragma once

#include "Exceptions/Exceptions.h"
#include "Context/Context.h"

#include "Factory/OperationFactory.h"
#include "Factory/OperationMaker.h"

#include "Interfaces/IOperationMaker.h"
#include "Interfaces/IOperation.h"

#include <fstream>
#include <iostream>
#include <list>

class StackCalculator {
public:
    static double evaluate(std::istream& is);
};
