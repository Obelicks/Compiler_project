#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>

int typeCheckDEC(SymbolTable* symbolTable, DEC* declaration){
  int type;

  fprintf(stderr,"DEC kind: %i\n", declaration->kind);
  
  switch (declaration->kind) {
    case listK:
      // fprintf(stderr,"DEC listK\n");
      typeCheckLIST(symbolTable, declaration->val.listD);
      break;
    case dectypeK:
      type =typeCheckTYPE(symbolTable, declaration->val.dectypeD.type);
      fprintf(stderr,"putting %s %d\n",declaration->val.dectypeD.id,type);
      putSymbol(symbolTable,declaration->val.dectypeD.id,type,NULL);
      break;
    case decfuncK:
      typeCheckFUNC(symbolTable, declaration->val.decfuncD);
      break;
    default:
      fprintf(stderr,"default case in typeCheckDEC\n");
      break;
  }
  return 0;
}
