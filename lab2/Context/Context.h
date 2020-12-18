#pragma once
#include <stack>
#include <map>

struct Context {
    std::stack <double> operands;
    std::map <std::string, double> defines;
};
