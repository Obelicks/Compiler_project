#include <stdio.h>
#include "../headers/gen.h"

void generate_LIST(LIST *l){
  fprintf(stderr, "enter generate_LIST with variable %d\n",l->kind );
  LIST* apointer;//
  int countes = 0;
  int countes2;
  switch (l->kind) {
    case parK:
      if(l->val.parL == NULL){
        return;
      }
      generate_LIST(l->val.parL);
      break;

    case varlistK:
      fprintf(stderr, "generating var_list" );
      while (l->val.varlistL.var_decl_list != NULL){
        TYPE type=l->val.varlistL.var_type;
        id = type->val.var_typeT.id;
        kind = type->kind;

        fprintf(stdout,"add $192, r9\n");
        fprintf(stdout,"cmp %%r9, %%r10\n");
        fprintf(stdout,"jge allocate_more\n");
        fprintf(stdout,"sub $192, r9\n");
        fprintf(stdout,"movq $%i, (%%r9)\n", id);
        fprintf(stdout,"add $64, %%r9\n");
        fprintf(stdout,"movq $%i, (%%r9)\n", kind);
        fprintf(stdout,"movq $0, (%%r9)\n");
        l = l->val.varlistL.var_decl_list;
      }
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
      generate_EXP(l->val.expressionL);
      break;

    case explistK:
      generate_EXP(l->val.explistL.expression);
      generate_LIST(l->val.explistL.exp_list);
      break;

    default:
      fprintf(stderr,"in default case in LIST\n");
      break;
  }

}
