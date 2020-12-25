#pragma once
#include <utility>

class Player {
protected:
    char sign = 'x';
public:
    virtual std::pair<int, int> doMove() = 0;
};
