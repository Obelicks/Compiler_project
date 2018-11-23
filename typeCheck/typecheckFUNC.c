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
      if (x<=0){
        return x;
      }
      y =typeCheckFUNC(symbolTable, func->val.functionF.body);
      if (y<0){
        return y;
      }
      z =typeCheckFUNC(symbolTable, func->val.functionF.tail);
      if (z<0){
        return z;
      }
      return 0;
      break;

    case headK:
      //TODO: Add id
      if(NULL == putSymbol(symbolTable,func->val.headF.id,FUNKTION,0)){
        return -11;
      }
      x = typeCheckLIST(symbolTable, func->val.headF.par_decl_list);
      if (x<=0){
        return x;
      }
      y = typeCheckTYPE(symbolTable, func->val.headF.type);
      return y;
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
