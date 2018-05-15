#include <stdio.h>
#include "../headers/pretty.h"

void prettyTYPE(TYPE *t){
   switch (t->kind) {
    case idK:
      fprintf(stderr,"id %s ", t->val.idT);
      break;

    case intconstK:
      fprintf(stderr,"int ");
      break;

    case boolK:
      fprintf(stderr,"bool ");
      break;

    case arrayK:
      fprintf(stderr,"array ");
      prettyTYPE(t->val.arrayT);
      break;

    case recordK:
      fprintf(stderr,"record ");
      prettyLIST(t->val.recordT);
      break;

    case vareK:
      fprintf(stderr,"vareK %s = ",t->val.vareT.id);
      prettyTYPE(t->val.vareT.variable);
      break;

    case varexpK:
      prettyTYPE(t->val.varexpT.variable);
      fprintf(stderr,"= ");
      prettyEXP(t->val.varexpT.expression);
      break;

    case var_typeK:
      fprintf(stderr,"typeK ");
      prettyTYPE(t->val.var_typeT.variable);
      fprintf(stderr,"%s ", t->val.var_typeT.id);
      fprintf(stderr,"\n");
      break;

    default:
      fprintf(stderr,"in default case in TYPE\n");
      break;
  }
}
