#pragma once
#include "EvaluatorException.h"

class NumberFormat : public EvaluatorException {
public:
    NumberFormat() : EvaluatorException("Wrong number format!"){};
};
