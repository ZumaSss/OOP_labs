#include "csv.h"

void csv::readFile () {
    std::string s, s1 = "";
    file.open("input.txt");
    if (!file) exit(-1);
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

void csv::sortVector() {
    for (const auto& it : mp){
        vector.emplace_back(it.first, it.second);
        total += it.second;
    }
    sort(vector.begin(), vector.end(), [](const auto & a, const auto & b) {return a.second > b.second;});
}

void csv::writeCsv() {
    csv.open("output.csv", std::ios::out);
    if (!csv) exit(-1);
    auto it1 = vector.begin();
    for (int i = 0; it1 != vector.end(); it1++, i++) csv << i << ") " << it1->first << "; Частота: " << it1->second << "; Частота в %: " << it1->second * 100 / total << "\n";
    csv.close();
}