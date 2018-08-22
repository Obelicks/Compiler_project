#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>

int typeCheckFUNC(SymbolTable* symbolTable, FUNC* func){

  fprintf(stderr,"FUNC kind: %i\n", func->kind);
  int x,y,z;
  switch (func->kind) {
    case functionK:
      x =typeCheckFUNC(symbolTable, func->val.functionF.head);
      y =typeCheckFUNC(symbolTable, func->val.functionF.body);
      z =typeCheckFUNC(symbolTable, func->val.functionF.tail);
      return x+y+z;
      break;

    case headK:
      //TODO: Add id
      x = typeCheckLIST(symbolTable, func->val.headF.par_decl_list);
      y = typeCheckTYPE(symbolTable, func->val.headF.type);
      return x+y;
      break;

    case bodyK:
      if (func->val.bodyF.decl_list != NULL) {
        x =typeCheckLIST(symbolTable, func->val.bodyF.decl_list);
        if (x < 0){
          return x;
        }
      }
      y =typeCheckLIST(symbolTable, func->val.bodyF.statement_list);
      return y;
      break;

    case tailK:
      //TODO: add tailF get symbol
      break;
  }

  return 0;
}
