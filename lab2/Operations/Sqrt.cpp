#include "Sqrt.h"
#include "../Factory/OperationMaker.h"

REGISTER_OPERATION(Sqrt, SQRT);

void Sqrt::execute(std::list<std::string> &args, Context &ctx) const {
    if (ctx.operands.empty()) throw OutOfParameters();

    double first = ctx.operands.top();
    ctx.operands.pop();

    if (first < 0) throw NegativeParameter();

    ctx.operands.push(sqrt(first));
}
