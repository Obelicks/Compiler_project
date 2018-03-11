#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>


int typeCheckTYPE(SymbolTable* symbolTable, TYPE* type){
  int error;
  int typeCheck;
  Symbol* symbol;
  // printf("KIND: %i\n", type->kind);
  switch (type->kind) {
    case idK:
      //TODO: find out how to do this
      break;

    case intconstK:
      //TODO: find out how to do this
      break;

    case boolK:
      //TODO: find out how to do this
      break;

    case arrayK:
      typeCheckTYPE(symbolTable, type->val.arrayT);
      break;

    case recordK:
      typeCheckLIST(symbolTable, type->val.recordT);
      break;

    case vareK:
      typeCheckTYPE(symbolTable, type->val.vareT.variable);
      //TODO: find out how to do id
      break;

    case varexpK:
      typeCheckTYPE(symbolTable, type->val.varexpT.variable);
      typeCheckEXP(symbolTable, type->val.varexpT.expression);
      break;

    case var_typeK:
      error = typeCheckTYPE(symbolTable, type->val.var_typeT.variable);
      if (error == 0){
        typeCheck = findType(type->val.var_typeT.variable);
        printf("Typecheck: %i\n", typeCheck);
        symbol = putSymbol(symbolTable, type->val.var_typeT.id, typeCheck, NULL);
      }
      break;

    default:
      printf("default case in typeCheckTYPE\n");
      break;
  }
  return 0;
}


int findType(TYPE* type){
  switch (type->kind) {
    case intconstK:
      return INTEGER;
      break;

    case boolK:
      return BOOLEAN;
      break;

    default:
      printf("Error not right type\n");
      break;
  }

  return -1;
}
