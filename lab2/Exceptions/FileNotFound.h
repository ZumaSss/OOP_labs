#pragma once
#include "EvaluatorException.h"

class FileNotFound : public EvaluatorException {
public:
    FileNotFound() : EvaluatorException("File not found!"){};
};
