#include <stdio.h>
#include "../headers/gen.h"

void generate_LIST(FILE* file,LIST *l){
  switch (l->kind) {
    case parK:
      generate_LIST(file,l->val.parL);
      break;

    case varlistK:
      generate_TYPE(file,l->val.varlistL.var_type);
      generate_LIST(file,l->val.varlistL.var_decl_list);
      break;

    case varK:
      generate_TYPE(file,l->val.varL);
      break;

    case decK:
      generate_DEC(file,l->val.decL.declaration);
      break;

    case stateK:
      generate_STM(file,l->val.stateL);
      break;

    case statelistK:
      generate_STM(file,l->val.statelistL.statement);
      generate_LIST(file,l->val.statelistL.statement_list);
      break;

    case actlistK:
      generate_LIST(file,l->val.actlistL);
      break;

    case expressionK:
      generate_EXP(file,l->val.expressionL);
      break;

    case explistK:
      generate_EXP(file,l->val.explistL.expression);
      generate_LIST(file,l->val.explistL.exp_list);
      break;

    default:
      printf("in default case in LIST\n");
      break;
  }
}
