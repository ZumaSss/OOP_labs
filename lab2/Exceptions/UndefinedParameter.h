#pragma once
#include "EvaluatorException.h"

class UndefinedParameter : public EvaluatorException {
public:
    UndefinedParameter() : EvaluatorException("Undefined parameter!"){};
};
