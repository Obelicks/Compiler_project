#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>

int typeCheckTYPE(SymbolTable* symbolTable, TYPE* type){
  int x;
  int typeCheck;
  Symbol* symbol;
  TYPE* next_type;
  fprintf(stderr,"TYPE KIND: %i\n", type->kind);
  switch (type->kind) {
    case idK:
      fprintf(stderr,"looking for symbol %s\n", type->val.idT);
      symbol = getSymbol(symbolTable, type->val.idT);
      if (symbol == NULL){
        return 0;
      }
      fprintf(stderr,"got symbol %s of type %i\n", symbol->name,symbol->type);
      return symbol->type;
      break;

    case intconstK:
      return INTEGER;
      break;

    case boolK:
      return BOOLEAN;
      break;

    case arrayK:
      x =typeCheckTYPE(symbolTable, type->val.arrayT);
      if (x<=0){
        return x;
      }
      break;

    case recordK:
      typeCheckLIST(symbolTable, type->val.recordT);

      break;

    case vareK:
      x=typeCheckTYPE(symbolTable, type->val.vareT.variable);
      if(x){
        return x;
      }
      break;

    case varexpK:
      x=typeCheckTYPE(symbolTable, type->val.varexpT.variable);
      if (x){
        return x;
      }
      x=typeCheckEXP(symbolTable, type->val.varexpT.expression);
      if (x){
        return x;
      }
      break;

    case var_typeK:
      //fprintf(stderr,"here\n");
      typeCheck = typeCheckTYPE(symbolTable, type->val.var_typeT.variable);
      symbol = putSymbol(symbolTable,type->val.var_typeT.id,typeCheck,NULL);
      if (symbol == NULL){
        fprintf(stderr, "putting error\n");
        return 0;
      }
      fprintf(stderr,"putting id: %s of type: %i\n", type->val.var_typeT.id,typeCheck);

      break;

    default:
      fprintf(stderr,"default case in typeCheckTYPE\n");
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
      fprintf(stderr,"ERROR Message: not right type,  line %i\n", type->lineno);
      break;
  }

  return 0;
}
