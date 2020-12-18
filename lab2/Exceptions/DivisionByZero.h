#pragma once
#include "EvaluatorException.h"

class DivisionByZero : public EvaluatorException {
public:
    DivisionByZero() : EvaluatorException("Division by zero!"){};
};
