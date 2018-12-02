#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>

void typeCheckFUNC(SymbolTable* symbolTable, FUNC* func){

  fprintf(stderr,"FUNC kind: %i\n", func->kind);
  int x,y,z;
  switch (func->kind) {
    case functionK:
      typeCheckFUNC(symbolTable, func->val.functionF.head);
      typeCheckFUNC(symbolTable, func->val.functionF.body);
      typeCheckFUNC(symbolTable, func->val.functionF.tail);
      break;

    case headK:
      //TODO: Add id



      if(NULL != func->val.headF.par_decl_list){
        typeCheckLIST(symbolTable, func->val.headF.par_decl_list);
      }
      typeCheckTYPE(symbolTable, func->val.headF.type);
      break;

    case bodyK:
      if (func->val.bodyF.decl_list != NULL) {
        typeCheckLIST(symbolTable, func->val.bodyF.decl_list);
      }
      typeCheckLIST(symbolTable, func->val.bodyF.statement_list);
      break;

    case tailK:
      //TODO: add tailF get symbol
      break;
  }

  return;
}
