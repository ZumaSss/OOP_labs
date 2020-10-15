#ifndef LAB0_CSV_H
#define LAB0_CSV_H
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <map>
#include <vector>
#include <algorithm>

class csv {
public:
    void readFile (char* inputFile);
    void writeCsv (char* outputFile);
private:
    std::map <std::string, int> mp;
    double total = 0;
};


#endif
