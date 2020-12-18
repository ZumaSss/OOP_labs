#include "Add.h"
#include "../Factory/OperationMaker.h"

REGISTER_OPERATION(Add, +);

void Add::execute(std::list<std::string> &args, Context &ctx) const {
    if (ctx.operands.size() < 2) throw OutOfParameters();

    double first = ctx.operands.top();
    ctx.operands.pop();
    double second = ctx.operands.top();
    ctx.operands.pop();

    ctx.operands.push(first + second);
}
