#pragma once

#include "Node.h"
#include "Identifier.h"

class Load: public Node {
private:
	Identifier ident;
	Variable *leftValue = NULL;
	
public:
	Load(const char* i): ident(i) {	}
	Load(Identifier i): ident(i) { }
 
	virtual Value *generate(FunctionImpl *func, BasicBlock *block, BasicBlock *allocblock) override;

	virtual DataType getDataType() override;

	virtual bool isConstExpr() override;

	virtual void setLeftValue(Variable *symbol) override;
};
