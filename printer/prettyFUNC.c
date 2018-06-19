#include <stdio.h>
#include "../headers/pretty.h"

void prettyFUNC(FUNC* f){
  switch (f->kind) {
    case functionK:
      prettyFUNC(f->val.functionF.head);
      prettyFUNC(f->val.functionF.body);
      prettyFUNC(f->val.functionF.tail);
      break;

    case headK:
      fprintf(stderr,"function %s (", f->val.headF.id);
      prettyLIST(f->val.headF.par_decl_list);
      prettyTYPE(f->val.headF.type);
      fprintf(stderr,"):\n");
      break;

    case bodyK:
      fprintf(stderr,"do:");
      //fprintf(stderr,"decl list\n");
      if(f->val.bodyF.decl_list != NULL){
        prettyLIST(f->val.bodyF.decl_list);
      }
      //fprintf(stderr,"stm list\n");
      prettyLIST(f->val.bodyF.statement_list);
      break;

    case tailK:
      fprintf(stderr,"end. %s\n", f->val.tailF);
      break;

    default:
    fprintf(stderr,"in default case in FUNC\n");
      break;
  }
}
