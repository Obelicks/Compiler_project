#include <stdio.h>
#include "../headers/pretty.h"

void prettyFUNC(FUNC *f){
  switch (f->kind) {
    case functionK:
      prettyFUNC(f->val.functionF.head);
      prettyFUNC(f->val.functionF.body);
      prettyFUNC(f->val.functionF.tail);
      break;

    case headK:
      printf("function %s (", f->val.headF.id);
      prettyLIST(f->val.headF.par_decl_list);
      prettyTYPE(f->val.headF.type);
      printf(")\n");
      break;

    case bodyK:
      //printf("decl list\n");
      if(f->val.bodyF.decl_list != NULL){
        prettyLIST(f->val.bodyF.decl_list);
      }
      //printf("stm list\n");
      prettyLIST(f->val.bodyF.statement_list);
      break;

    case tailK:
      printf("end %s\n", f->val.tailF);
      break;

    default:
    printf("in default case in FUNC\n");
      break;
  }
}
