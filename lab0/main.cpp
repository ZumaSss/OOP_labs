#include "csv.h"

int main() {
    csv CSV;
    CSV.readFile();
    CSV.sortVector();
    CSV.writeCsv();
    return 0;
}
