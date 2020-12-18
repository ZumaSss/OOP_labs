#pragma once
#include "EvaluatorException.h"

class WrongInput : public EvaluatorException {
public:
    WrongInput() : EvaluatorException("Wrong input!"){};
};
