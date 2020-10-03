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
    void readFile ();
    void sortVector();
    void writeCsv();
private:
    std::map <std::string, int> mp;
    std::vector <std::pair <std::string, int> > vector;
    double total = 0;
    std::ifstream file;
    std::ofstream csv;
};


#endif
