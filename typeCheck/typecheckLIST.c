#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>

int typeCheckLIST(SymbolTable* symbolTable, LIST* list){

  fprintf(stderr,"LIST kind: %i\n", list->kind);
  int x;
  switch (list->kind) {
    case parK:
      // fprintf(stderr,"par\n");
      x = typeCheckLIST(symbolTable, list->val.parL);
      if (x<0){
        return x;
      }
      break;

    case varlistK:
      // fprintf(stderr,"varlist\n");
      x = typeCheckTYPE(symbolTable, list->val.varlistL.var_type);
      if (x<0){
        return x;
      }
      x = typeCheckLIST(symbolTable, list->val.varlistL.var_decl_list);
      if (x<0){
        return x;
      }
      break;

    case varK:
      // fprintf(stderr,"var\n");
      x = typeCheckTYPE(symbolTable, list->val.varL);
      if (x<0){
        return x;
      }
      break;

    case decK:
      // fprintf(stderr,"dec\n");
      x = typeCheckDEC(symbolTable, list->val.decL.declaration);
      if (x<0){
        return x;
      }
      if (list->val.decL.decl_list != NULL){
        x = typeCheckLIST(symbolTable, list->val.decL.decl_list);
        if (x<0){
          return x;
        }
      }
      break;

    case stateK:
      // fprintf(stderr,"state\n");
      x = typeCheckSTM(symbolTable, list->val.stateL);
      if (x<0){
        return x;
      }
      break;

    case statelistK:
      // fprintf(stderr,"statelist\n");
      x = typeCheckSTM(symbolTable, list->val.statelistL.statement);
      if (x<0){
        return x;
      }
      x =typeCheckLIST(symbolTable, list->val.statelistL.statement_list);
      if (x<0){
        return x;
      }
      break;

    case actlistK:
      // fprintf(stderr,"actlist\n");
      x = typeCheckLIST(symbolTable, list->val.actlistL);
      if (x<0){
        return x;
      }
      break;

    case expressionK:
      // fprintf(stderr,"expression\n");
      x = typeCheckEXP(symbolTable, list->val.expressionL);
      if (x<0){
        return x;
      }
      break;

    case explistK:
      // fprintf(stderr,"explist\n");
      x = typeCheckEXP(symbolTable, list->val.explistL.expression);
      if (x<0){
        return x;
      }
      x = typeCheckLIST(symbolTable, list->val.explistL.exp_list);
      if (x<0){
        return x;
      }
      break;

    default:
      fprintf(stderr,"default case in typeCheckLIST\n");
      break;
  }

  return 0;
}
