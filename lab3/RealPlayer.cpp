#include "RealPlayer.h"
#include <iostream>

std::pair <int, int> RealPlayer::doMove() {
    int first, second;
    std::cin >> first >> second;
    std::pair <int, int> move {first - 1, second - 1};
    return move;
}
