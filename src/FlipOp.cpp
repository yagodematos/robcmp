
#include "Header.h"

FlipOp::FlipOp(Node *value) : value(value) {
    this->node_children.reserve(1);
    this->node_children.push_back(value);
};

Value *FlipOp::generate(Function *func, BasicBlock *block, BasicBlock *allocblock) {
    // generate code to produce the value to flip
	Value *exprv = value->generate(func, block, allocblock);
    if (exprv == NULL)
        return NULL;
    return BinaryOperator::Create(Instruction::Xor, exprv, 
        Constant::getAllOnesValue(exprv->getType()), "neg", block);
}

void FlipOp::accept(Visitor& v) {
	v.visit(*this);
}
