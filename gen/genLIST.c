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
      while (l->val.varlistL.var_decl_list != NULL){
        TYPE* type=l->val.varlistL.var_type;
        char* id = type->val.var_typeT.id;
        int kind = type->kind;

        fprintf(stdout,"add $192, r9\n");
        fprintf(stdout,"cmp %%r9, %%r10\n");
        fprintf(stdout,"jge allocate_more\n");//TODO epilogue function
        fprintf(stdout,"sub $192, r9\n");
        fprintf(stdout,"movq $%i, (%%r9)\n", id);
        fprintf(stdout,"add $64, %%r9\n");
        fprintf(stdout,"movq $%i, (%%r9)\n", kind);
        fprintf(stdout,"movq $0, (%%r9)\n");
        l = l->val.varlistL.var_decl_list;
      }
    case varK:
      fprintf(stderr, "generating generate_LIST -> varK\n" );
      generate_TYPE(l->val.varL);
      break;

    case decK:
      fprintf(stderr, "generating generate_LIST -> decK\n" );
      generate_DEC(l->val.decL.declaration);
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
      generate_LIST(l->val.statelistL.statement_list);
      break;

    case actlistK:
      fprintf(stderr, "generating generate_LIST -> actlistK\n" );
      generate_LIST(l->val.actlistL);
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
