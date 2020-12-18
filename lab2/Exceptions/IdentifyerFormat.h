#pragma once
#include "EvaluatorException.h"

class IdentifyerFormat : public EvaluatorException {
public:
    IdentifyerFormat() : EvaluatorException("Wrong identifyer format!"){};
};
