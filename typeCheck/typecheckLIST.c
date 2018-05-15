#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>

int typeCheckLIST(SymbolTable* symbolTable, LIST* list){

  fprintf(stderr,"LIST kind: %i\n", list->kind);

  switch (list->kind) {
    case parK:
      // fprintf(stderr,"par\n");
      typeCheckLIST(symbolTable, list->val.parL);
      break;

    case varlistK:
      // fprintf(stderr,"varlist\n");
      typeCheckTYPE(symbolTable, list->val.varlistL.var_type);
      typeCheckLIST(symbolTable, list->val.varlistL.var_decl_list);
      break;

    case varK:
      // fprintf(stderr,"var\n");
      typeCheckTYPE(symbolTable, list->val.varL);
      break;

    case decK:
      // fprintf(stderr,"dec\n");
      typeCheckDEC(symbolTable, list->val.decL.declaration);

      if (list->val.decL.decl_list != NULL){
        typeCheckLIST(symbolTable, list->val.decL.decl_list);
      }
      break;

    case stateK:
      // fprintf(stderr,"state\n");
      typeCheckSTM(symbolTable, list->val.stateL);
      break;

    case statelistK:
      // fprintf(stderr,"statelist\n");
      typeCheckSTM(symbolTable, list->val.statelistL.statement);
      typeCheckLIST(symbolTable, list->val.statelistL.statement_list);
      break;

    case actlistK:
      // fprintf(stderr,"actlist\n");
      typeCheckLIST(symbolTable, list->val.actlistL);
      break;

    case expressionK:
      // fprintf(stderr,"expression\n");
      typeCheckEXP(symbolTable, list->val.expressionL);
      break;

    case explistK:
      // fprintf(stderr,"explist\n");
      typeCheckEXP(symbolTable, list->val.explistL.expression);
      typeCheckLIST(symbolTable, list->val.explistL.exp_list);
      break;

    default:
      fprintf(stderr,"default case in typeCheckLIST\n");
      break;
  }

  return 0;
}
