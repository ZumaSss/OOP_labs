#pragma once
#include "EvaluatorException.h"

class NegativeParameter : public EvaluatorException {
public:
    NegativeParameter() : EvaluatorException("Negative parameter!"){};
};