#include "csv.h"

void csv::readFile (char* inputFile) {
    std::ifstream file;
    std::string s, s1 = "";
    file.open(inputFile);
    if (!file) throw std::logic_error("Unable to open file!");
    while (getline(file, s)) {
        std::cout << s << std::endl;
        for (char i : s) {
            if (isalpha(i) != 0 or isdigit(i) != 0) {
                s1 += i;
            } else if (!s1.empty()) {
                mp[s1]++;
                s1 = "";
            }
        }
        if (isalpha(s[s.size() - 1]) or isdigit(s[s.size() - 1])) mp[s1]++;
    }
}

void csv::writeCsv(char* outputFile) {
    std::vector <std::pair <std::string, int> > vector;
    std::ofstream csv;
    csv.open(outputFile, std::ios::out);
    if (!csv) throw std::logic_error("Unable to open file!");
    for (const auto& it : mp){
        vector.emplace_back(it.first, it.second);
        total += it.second;
    }
    sort(vector.begin(), vector.end(), [](const auto & a, const auto & b) {return a.second > b.second;});
    auto it1 = vector.begin();
    for (int i = 0; it1 != vector.end(); it1++, i++) csv << i << ") " << it1->first << "; Частота: " << it1->second << "; Частота в %: " << it1->second * 100 / total << "\n";
    csv.close();
}