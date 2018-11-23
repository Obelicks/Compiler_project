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
      fprintf(stderr, "generating generate_LIST -> var_list\n" );
      fprintf(stderr, "generating generate_DEC -> dectypeK\n" );
      //TODO assember der laver en variabel
      fprintf(stdout,"push $%lli\n",(long long int)*l->val.varlistL.var_type->val.var_typeT.id);
      fprintf(stdout,"push $%lli\n",(long long int)l->val.varlistL.var_type->kind);
      fprintf(stdout,"push $0\n");
      fprintf(stdout,"add $192, %%r9\n");

      if (l->val.varlistL.var_decl_list != NULL){
        generate_LIST(l->val.varlistL.var_decl_list);

      }
      break;
    case varK:
      fprintf(stderr, "generating generate_LIST -> varK\n" );
      fprintf(stderr, "generating generate_LIST -> var_list\n" );
      fprintf(stderr, "generating generate_DEC -> dectypeK\n" );
      //TODO assember der laver en variabel
      fprintf(stdout,"push $%lli\n",(long long int)*l->val.varL->val.var_typeT.id);
      fprintf(stdout,"push $%lli\n", (long long int)l->val.varL->kind);
      fprintf(stdout,"push $0\n");
      fprintf(stdout,"add $192, %%r9\n");
      break;

    case decK:
      fprintf(stderr, "generating generate_LIST -> decK\n" );
      generate_DEC(l->val.decL.declaration);
      if (l->val.decL.decl_list != NULL){
        generate_LIST(l->val.decL.decl_list);
      }

      break;

    case stateK:
      fprintf(stderr, "generating generate_LIST -> stateK\n" );
      generate_STM(l->val.stateL);
      break;

    case statelistK:
      fprintf(stderr, "generating generate_LIST -> statelistK\n" );
      //fprintf(stderr,"statelist1\n");
      generate_STM(l->val.statelistL.statement);
      //fprintf(stderr,"statelist2\n");
      if (l->val.statelistL.statement_list != NULL){
        generate_LIST(l->val.statelistL.statement_list);
      }
      break;

    case actlistK:
      fprintf(stderr, "generating generate_LIST -> actlistK\n" );
      if(NULL != l->val.actlistL){
        generate_LIST(l->val.actlistL);
      }
      break;

    case expressionK:
      fprintf(stderr, "generating generate_LIST -> expressionK\n" );
      generate_EXP(l->val.expressionL);
      break;

    case explistK:
      fprintf(stderr, "generating generate_LIST -> explistK\n" );
      generate_EXP(l->val.explistL.expression);
      generate_LIST(l->val.explistL.exp_list);
      break;

    default:
      fprintf(stderr,"in default case in LIST\n");
      break;
  }

}
