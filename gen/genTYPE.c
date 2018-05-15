#include <stdio.h>
#include "../headers/gen.h"

extern int regNr;

void generate_TYPE(TYPE *t){
   switch (t->kind) {
    case idK:
      break;

    case intconstK:
      break;

    case boolK:
      break;

    case arrayK:
      generate_TYPE(t->val.arrayT);
      break;

    case recordK:
      generate_LIST(t->val.recordT);
      break;

    case vareK:
      generate_TYPE(t->val.vareT.variable);
      break;

    case varexpK:
      generate_TYPE(t->val.varexpT.variable);
      generate_EXP(t->val.varexpT.expression);
      break;

    case var_typeK:
      generate_TYPE(t->val.var_typeT.variable);
      break;

    default:
      fprintf(stderr,"in default case in TYPE\n");
      break;
  }return;
}
