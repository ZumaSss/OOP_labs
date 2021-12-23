#include "matrix.h"

int main() {
    Matrix matrix;
    try {
        Matrix::start(matrix);
    } catch (std::exception &ex) {
        std::cerr << ex.what();
        return -1;
    }
    return 0;
}
