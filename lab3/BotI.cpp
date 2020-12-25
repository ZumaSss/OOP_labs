#include "BotI.h"

std::pair<int, int> BotI::doMove() {
    analyseSituation();
    return possibleMove;
}

