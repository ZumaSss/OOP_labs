#include "csv.h"

int main(int argc, char* argv[]) {
    csv CSV;
    try {
        CSV.readFile(argv[1]);
        CSV.writeCsv(argv[2]);
    } catch (std::exception &ex) {
        std::cerr << ex.what();
    }
    return 0;
}
