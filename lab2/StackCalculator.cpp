#include "StackCalculator.h"
#include "LineReader.h"
#include "memory"

double StackCalculator::evaluate(std::istream& is) {
    Context ctx;
    size_t lineCounter = 1;
    std::list <std::string> curArgs;
    while (LineReader::readNextLine(is, curArgs)) {
        try {
            char symb = curArgs.front()[0];
            if (symb == '#') continue;

            std::unique_ptr<IOperation> op (OperationFactory::creator().concreteProduct(curArgs.front()));
            curArgs.pop_front();
            op -> execute(curArgs, ctx);
        } catch (EvaluatorException& ex) {
            std::cout << ex.what() << " Line " << lineCounter << "." << std::endl;

            curArgs.clear();
            lineCounter++;
            continue;
        }
        curArgs.clear();
        lineCounter++;
    }
    return ctx.operands.top();
}

bool LineReader::readNextLine(std::istream& is, std::list <std::string> &args) {
    std::string curLine;
    if (!getline(is, curLine)) return false;

    splitString(args, curLine);
    return true;
}

void LineReader::splitString(std::list<std::string> &args, const std::string& line) {
    size_t curBeginning = 0;
    for (size_t i = 0; i < line.size(); ++i) {
        if (line[i] == ' ' && i - curBeginning > 0) {
            args.push_back(line.substr(curBeginning, i - curBeginning));
            curBeginning = i + 1;
        }
    }

    if (line.size() - curBeginning > 0) args.push_back(line.substr(curBeginning));
}
