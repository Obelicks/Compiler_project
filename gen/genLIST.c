#include <stdio.h>
#include "../headers/gen.h"
extern long long int variablecounter;

void generate_LIST(LIST *l, int flag){
  fprintf(stderr, "enter generate_LIST with variable %d\n",l->kind );
  LIST* apointer;//
  int countes = 0;
  int countes2;

  switch (l->kind) {
    case parK:
      if(l->val.parL == NULL){
        return;
      }
      generate_LIST(l->val.parL, flag);
      break;

    case varlistK:
      fprintf(stderr, "generating generate_LIST -> var_list\n" );

      generate_TYPE(l->val.varlistL.var_type, flag);


      if (l->val.varlistL.var_decl_list != NULL){
        generate_LIST(l->val.varlistL.var_decl_list, flag);
        if(!flag){
          variablecounter++;
        }
      }
      break;
    case varK:
      fprintf(stderr, "generating generate_LIST -> varK\n" );
      //TODO assember der laver en variabel
      fprintf(stdout,"push $%i\n",hash(l->val.varL->val.var_typeT.id));
      fprintf(stderr,"%s\n",l->val.varL->val.var_typeT.id);
      fprintf(stdout,"push $%i\n", l->val.varL->kind);
      fprintf(stdout,"push $0\n");

      if (!flag){
              variablecounter++;
        flag = 1;
      }


      break;

    case decK:
      fprintf(stderr, "generating generate_LIST -> decK\n" );
      generate_DEC(l->val.decL.declaration, flag);
      if (l->val.decL.decl_list != NULL){
        generate_LIST(l->val.decL.decl_list, flag);
      }

      break;

    case stateK:
      fprintf(stderr, "generating generate_LIST -> stateK\n" );
      generate_STM(l->val.stateL, flag);
      break;

    case statelistK:
      fprintf(stderr, "generating generate_LIST -> statelistK\n" );
      //fprintf(stderr,"statelist1\n");
      generate_STM(l->val.statelistL.statement, flag);
      //fprintf(stderr,"statelist2\n");
      if (l->val.statelistL.statement_list != NULL){
        generate_LIST(l->val.statelistL.statement_list, flag);
      }
      break;

    case actlistK:
      fprintf(stderr, "generating generate_LIST -> actlistK\n" );
      if(NULL != l->val.actlistL){

        generate_LIST(l->val.actlistL, flag);
      }

      break;

    case expressionK:
      fprintf(stderr, "generating generate_LIST -> expressionK\n" );
      generate_EXP(l->val.expressionL, flag);
      variablecounter++;
      break;

    case explistK:
      fprintf(stderr, "generating generate_LIST -> explistK\n" );
      generate_EXP(l->val.explistL.expression, flag);
      generate_LIST(l->val.explistL.exp_list, flag);
      break;

    default:
      fprintf(stderr,"in default case in LIST\n");
      break;
  }
  return;
}
