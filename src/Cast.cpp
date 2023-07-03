
#include "Header.h"

Value *Cast::generate(Function *func, BasicBlock *block, BasicBlock *allocblock)
{
    Value *exprv = expr->generate(func, block, allocblock);
    if (!exprv)
        return NULL;

    Type *destty = robTollvmDataType[dt];
    Value *ret = Coercion::Convert(exprv, destty, block);

    if (ret == NULL) {
        yyerrorcpp("Can't cast from '" + getTypeName(exprv->getType()) + "' to '" + 
            LanguageDataTypeNames[dt], this);
        return NULL;
    }

    return ret;
}

void Cast::accept(Visitor &v) {
	v.visit(*this); 
}
