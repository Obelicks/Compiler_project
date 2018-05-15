#include <stdio.h>
#include "../headers/gen.h"

extern int regNr;

void generate_LIST(LIST *l){
  switch (l->kind) {
    case parK:
      generate_LIST(l->val.parL);
      break;

    case varlistK:
      generate_TYPE(l->val.varlistL.var_type);
      generate_LIST(l->val.varlistL.var_decl_list);
      break;

    case varK:
      generate_TYPE(l->val.varL);
      break;

    case decK:
      generate_DEC(l->val.decL.declaration);
      break;

    case stateK:
      generate_STM(l->val.stateL);
      break;

    case statelistK:
      //fprintf(stderr,"statelist1\n");
      generate_STM(l->val.statelistL.statement);
      //fprintf(stderr,"statelist2\n");
      generate_LIST(l->val.statelistL.statement_list);
      break;

    case actlistK:
      generate_LIST(l->val.actlistL);
      break;

    case expressionK:
      generate_EXP_V(l->val.expressionL);
      break;

    case explistK:
      generate_EXP_V(l->val.explistL.expression);
      generate_LIST(l->val.explistL.exp_list);
      break;

    default:
      fprintf(stderr,"in default case in LIST\n");
      break;
  }return;
}
