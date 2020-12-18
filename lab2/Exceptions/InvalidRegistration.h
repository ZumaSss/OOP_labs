#pragma once
#include "EvaluatorException.h"

class InvalidRegistration : public EvaluatorException {
public:
    InvalidRegistration() : EvaluatorException("Invalid registration!"){};
};
