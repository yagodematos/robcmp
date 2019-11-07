#include "Header.h"

FunctionParams::FunctionParams() {};

void FunctionParams::append(FunctionParam& e) {
	parameters.push_back(e);
};
	
unsigned FunctionParams::getNumParams() const {
	unsigned r = 0;
	for(auto& i : parameters)
		r += 1;
	return r;
};

Type *FunctionParams::getParamType(int position) const {
	// TODO:	
	//Generate Problem
	return(parameters[position].type);
}

String FunctionParams::getParamElement(int position) const {
	return parameters[position].name;
}