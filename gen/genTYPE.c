#include <stdio.h>
#include "../headers/gen.h"

void generate_TYPE(FILE* file,TYPE *t){
   switch (t->kind) {
    case idK:
      break;

    case intconstK:
      break;

    case boolK:
      break;

    case arrayK:
      generate_TYPE(file,t->val.arrayT);
      break;

    case recordK:
      generate_LIST(file,t->val.recordT);
      break;

    case vareK:
      generate_TYPE(file,t->val.vareT.variable);
      break;

    case varexpK:
      generate_TYPE(file,t->val.varexpT.variable);
      generate_EXP(file,t->val.varexpT.expression);
      break;

    case var_typeK:
      generate_TYPE(file,t->val.var_typeT.variable);
      break;

    default:
      printf("in default case in TYPE\n");
      break;
  }
}
