//
// Created by ivana on 25.12.2020.
//

#pragma once
#include "MoveException.h"
#include <iostream>
#include <list>

class Model;
class Viewer;
class Controller;

enum States {
    IN_PROGRESS,
    MARKS_WIN,
    ZEROS_WIN,
    DRAW
};

enum Signs {
    MARKS,
    ZEROS
};

class Model {
    States state;
    char curMove = 'x';
    std::list <Viewer> observers;

    void synchronize();
    void endIfGame();

public:
    Model() {
        for (auto & i : field) {
            for (char & j : i) {
                j = ' ';
            }
        }
        state = IN_PROGRESS;
    }
    bool isFree(int first, int second);
    States getState();
    Signs getSign();
    void setTo(int i, int j);
    void setState(States state);
    bool isGameEnded();
    void addObserver(Viewer viewer);
    char getFrom(int i, int j);
    char field[3][3]{};
};

class Viewer {
public:
    static void display(const Model& model);
};

class Controller {
public:
    static void updateRequest(std::pair <int, int> move, Model *model);
};

struct Context {
    Model model;
    Viewer viewer;
    Controller controller;
};
