#pragma once
#include "EvaluatorException.h"

class OutOfParameters : public EvaluatorException {
public:
    OutOfParameters() : EvaluatorException("Out of parameters!"){};
};
