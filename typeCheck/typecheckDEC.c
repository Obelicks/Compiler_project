#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>

int typeCheckDEC(SymbolTable* symbolTable, DEC* declaration){
  int type,x;

  fprintf(stderr,"DEC kind: %i\n", declaration->kind);

  switch (declaration->kind) {
    case listK:
      // fprintf(stderr,"DEC listK\n");
      x = typeCheckLIST(symbolTable, declaration->val.listD);
      if (x<0){
        return x;
      }
      break;
    case dectypeK:
      type =typeCheckTYPE(symbolTable, declaration->val.dectypeD.type);
      fprintf(stderr,"putting %s %d\n",declaration->val.dectypeD.id,type);
      if(type == 2){
        fprintf(stderr, "%s must be assigned to a type\n", declaration->val.dectypeD.id);
        return -1;
      }
      if (x<0){
        return x;
      }
      putSymbol(symbolTable,declaration->val.dectypeD.id,type,NULL);
      break;
    case decfuncK:
      x =typeCheckFUNC(symbolTable, declaration->val.decfuncD);
      if (x<0){
        return x;
      }
      break;
    default:
      fprintf(stderr,"default case in typeCheckDEC\n");
      break;
  }
  return 0;
}
