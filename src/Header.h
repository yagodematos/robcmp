
#pragma once

#ifndef SCANNER_OR_VISITOR
#error Please include this file only on .y or visitor files
#endif

//#define ENABLE_ARDUINO
//#define ENABLE_PRINT

#include "HeaderGlobals.h"
#include "SourceLocation.h"
#include "Scanner.h"
#include "Node.h"
#include "ArrayElements.h"
#include "AttachInterrupt.h"
#include "BinaryOp.h"
#include "Capsule.h"
#include "CmpOp.h"
#include "Coercion.h"
#include "Delay.h"
#include "Double.h"
#include "Float.h"
#include "Float128.h"
#include "FunctionCall.h"
#include "FunctionDecl.h"
#include "FunctionImpl.h"
#include "FunctionParams.h"
#include "If.h"
#include "Int1.h"
#include "Int8.h"
#include "Int16.h"
#include "Int32.h"
#include "Int64.h"
#include "InPort.h"
#include "Load.h"
#include "LoadArray.h"
#include "LoadMatrix.h"
#include "Matrix.h"
#include "MatrixElements.h"
#include "OutPort.h"
#include "ParamsCall.h"
#include "Print.h"
#include "Program.h"
#include "Return.h"
#include "Scalar.h"
#include "Semantic.h"
#include "StringConst.h"
#include "UpdateArray.h"
#include "UpdateMatrix.h"
#include "Array.h"
#include "While.h"
#include "Loop.h"
#include "Pointer.h"
#include "FlipOp.h"
#include "Cast.h"
#include "InlineAssembly.h"
#include "Interface.h"
#include "UserType.h"
#include "Enum.h"
#include "MemCopy.h"

extern Node* getNodeForIntConst(int64_t i);
