#pragma once

class LineReader {
public:
    static void splitString(std::list <std::string>&, const std::string&);
    static bool readNextLine(std::istream& is, std::list <std::string>& args);
};