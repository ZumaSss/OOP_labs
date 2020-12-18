#pragma once
#include "EvaluatorException.h"

class NoSuchOperation : public EvaluatorException {
public:
    NoSuchOperation() : EvaluatorException("No such operation!"){};
};
