#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>

int atoi (const char* str);
int typeCheckTERM(SymbolTable* symbolTable, TERM* term){
  fprintf(stderr,"TERM KIND: %i\n", term->kind);
  int x;
  int type;
  switch (term->kind) {
    case notK:
      type = typeCheckTERM(symbolTable, term->val.notT);
      return type;
      break;

    case absoluteK:
      x =typeCheckEXP(symbolTable, term->val.absoluteT);
      if (x){
        return x;
      }
      break;

    case numK:
      //fprintf(stderr,"its an int\n");
      return INTEGER;
      break;

    case expK:
      x =typeCheckEXP(symbolTable, term->val.expT);
      if (x){
        return x;
      }
      break;

    case booleanK:
      //fprintf(stderr,"its a bool\n");
      return BOOLEAN;
      break;

    case variableK:
      x=typeCheckTYPE(symbolTable, term->val.variableT);
      if (x){
        return x;
      }
      break;

    case act_listK:
      if(NULL!=term->val.act_listT.act_list){
        typeCheckLIST(symbolTable, term->val.act_listT.act_list);
      }
      //return atoi(term->val.act_listT.id);
      break;

    default:
      fprintf(stderr,"default case in typeCheckTERM\n");
      break;
  }
  return 0;
}
