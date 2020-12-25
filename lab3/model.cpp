#include "Context.h"
#include "MoveException.h"

bool Model::isFree(int first, int second) {
    return field[first][second] == ' ';
}

States Model::getState() {
    return state;
}

char Model::getFrom(int i, int j) {
    return field[i][j];
}

void Model::setState(States _state) {
    state = _state;
    std::cout << "Game ended!" << std::endl;
}

void Model::setTo(int i, int j) {
    if (i < 0 || i > 2 || j < 0 || j > 2 || !isFree(i, j)) {
        throw MoveException();
    }
    field[i][j] = curMove;
    curMove = (curMove == 'x' ? 'o' : 'x');
    synchronize();
}

int checkLines(char field[3][3]) {
    for (int i = 0; i < 3; ++i) {
        if (field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] != ' ') {
            return i;
        }
    }
    return -1;
}

int checkColumns(char field[3][3]) {
    for (int i = 0; i < 3; ++i) {
        if (field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i] != ' ') {
            return i;
        }
    }
    return -1;
}

int checkDiagonals(char field[3][3]) {
    bool firstCheck = field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] != ' ';
    bool secondCheck = field[2][0] == field[1][1] && field[1][1] == field[0][2] && field[1][1] != ' ';
    if (firstCheck) {
        return 1;
    } else if (secondCheck) {
        return 2;
    }
    return -1;
}

bool Model::isGameEnded() {
    int val;
    if ((val = checkLines(field)) >= 0) {
        if (field[val][0] == 'x') {
            setState(MARKS_WIN);
        } else {
            setState(ZEROS_WIN);
        }
    }

    if ((val = checkColumns(field)) >= 0) {
        if (field[0][val] == 'x') {
            setState(MARKS_WIN);
        } else {
            setState(ZEROS_WIN);
        }
    }

    if ((val = checkDiagonals(field)) == 1) {
        if (field[0][0] == 'x') {
            setState(MARKS_WIN);
        } else {
            setState(ZEROS_WIN);
        }
    } else if (val == 2) {
        if (field[2][0] == 'x') {
            setState(MARKS_WIN);
        } else {
            setState(ZEROS_WIN);
        }
    }

    if (state == IN_PROGRESS) {
        for (auto & i : field) {
            for (char j : i) {
                if (j == ' ') {
                    return false;
                }
            }
        }
        state = DRAW;
    }
    endIfGame();
    return true;
}

void Model::addObserver(Viewer viewer) {
    observers.push_back(viewer);
}

void Model::synchronize() {
    for (Viewer viewer : observers) {
        Viewer::display(*this);
    }
}

Signs Model::getSign() {
    return (curMove == 'x' ? MARKS : ZEROS);
}

void Model::endIfGame() {
    switch (getState()) {
        case IN_PROGRESS:
            return;
        case MARKS_WIN:
            std::cout << "Marks wins!" << std::endl;
            return;
        case ZEROS_WIN:
            std::cout << "Zeros wins!" << std::endl;
            return;
        case DRAW:
            std::cout << "DRAW!" << std::endl;
            return;
    }
}

