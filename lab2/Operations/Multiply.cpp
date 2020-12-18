#include "Multiply.h"
#include "../Factory/OperationMaker.h"

REGISTER_OPERATION(Multiply, *);


void Multiply::execute(std::list<std::string> &args, Context &ctx) const {
    if (ctx.operands.size() < 2) throw OutOfParameters();

    double first = ctx.operands.top();
    ctx.operands.pop();
    double second = ctx.operands.top();
    ctx.operands.pop();

    ctx.operands.push(first * second);
}
