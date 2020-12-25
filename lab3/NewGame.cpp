#include "NewGame.h"

#include <memory>
#include "RealPlayer.h"
#include "Bot.h"

void NewGame::greeting() {
    std::cout << "Welcome to the game \"Marks and Zeros\"!" << std::endl;
    std::cout << "Now you can choose players from 2 types:" << std::endl;
    std::cout << "1.Human" << std::endl;
    std::cout << "2.Bot" << std::endl;
}

int defineType() {
    bool undefined = true;
    int type = 0;
    while (undefined) {
        std::cout << "Enter the type of player: " << std::endl;
        std::cin >> type;
        if (type > 2 || type < 1) {
            std::cout << "Wrong type!" << std::endl;
            continue;
        }
        undefined = false;
    }
    return type;
}

void NewGame::start() {
    std::unique_ptr<Player> first;
    std::unique_ptr<Player> second;
    greeting();
    int firstOption = defineType();
    int secondOption = defineType();

    switch (firstOption) {
        case 1:
            first = std::make_unique<RealPlayer>();
            break;
        case 2:
            first = std::make_unique<Bot>(&ctx.model);
            break;
        default:
            return;
    }
    switch (secondOption) {
        case 1:
            second = std::make_unique<RealPlayer>();
            break;
        case 2:
            second = std::make_unique<Bot>(&ctx.model);
            break;
        default:
            return;
    }

    ctx.model.addObserver(ctx.viewer);
    while (!ctx.model.isGameEnded()) {
        std::pair <int, int> move;
        std::cout << "Now the move of " << (ctx.model.getSign() == MARKS ? 'X' : 'O') << std::endl;

        if (ctx.model.getSign() == MARKS) {
            if (firstOption == 1) std::cout << "Enter your move, for example <1 1>: ";
            move = first -> doMove();
        } else {
            if (secondOption == 1) std::cout << "Enter your move, for example <1 1>: ";
            move = second -> doMove();
        }
        Controller::updateRequest(move, &ctx.model);
    }
}
