#pragma once
#include <exception>
#include <string>

class MoveException : public std::exception {
    const std::string msg {"The move is impossible. Check if field is busy or parameters are incorrect!"};
public:
    const char *what() const noexcept override {
        return msg.c_str();
    }
};
