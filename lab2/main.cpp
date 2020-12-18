#include "StackCalculator.h"

int main(int argc, char** argv) {
    if (argc > 1) {
        try {
            std::ifstream fin(argv[1]);
            if (!fin) throw FileNotFound();
            StackCalculator::evaluate(fin);
        } catch (FileNotFound &ex) {
            std::cerr << ex.what() << std::endl;
            StackCalculator::evaluate(std::cin);
        }
    }
    StackCalculator::evaluate(std::cin);
    return 0;
}
