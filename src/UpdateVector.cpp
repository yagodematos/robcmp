#include "Header.h"

Value *UpdateVector::generate(Function *func, BasicBlock *block, BasicBlock *allocblock) {
		Value *sym = search_symbol(ident, allocblock, block);	
		/* TODO */
		if (sym == NULL) {
			yyerrorcpp("Variable " + ident + " not defined.");
			return NULL;
		}

		AllocaInst *allocInst = dyn_cast<AllocaInst>(sym);
		ArrayType *arrayTy = dyn_cast<ArrayType>(allocInst->getAllocatedType());
		if (arrayTy == NULL) {
			yyerrorcpp("Variable " + ident + " is not an array type.");
			return NULL;
		}
		Value *indice = position->generate(func, block, allocblock);
		if (!indice->getType()->isIntegerTy()){
			yyerrorcpp("Not Allowed");
			return NULL;
		}

		Value *zero = ConstantInt::get(Type::getInt8Ty(global_context), 0);
		//Value *indice = ConstantInt::get(Type::getInt8Ty(global_context), npos);

		Value* indexList[2] = {zero, indice};
		//GetElementPtrInst* ptr = GetElementPtrInst::Create(Type *PointeeType, Value *Ptr, ArrayRef<Value*> IdxList, const Twine &NameStr="", Instruction/BasicBlock *Insert)
		GetElementPtrInst* ptr = GetElementPtrInst::Create(arrayTy, sym, ArrayRef<Value*>(indexList), "", block);
//		GetElementPtrInst* gep = GetElementPtrInst::Create(arrayType, sym, ArrayRef<Value*>(indexList), "", block);
		Value *val = exprs->generate(func, block, allocblock);
		StoreInst *store = new StoreInst(val, ptr, false, block);

		return NULL;
	//	return ret;
}

