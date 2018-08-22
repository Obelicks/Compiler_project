#include <stdio.h>
#include "../headers/gen.h"

void generate_TYPE(TYPE* t){
   switch (t->kind) {
    case idK:

      fprintf(stdout,">%s<",t->val.idT);

      break;

    case intconstK:
      fprintf(stdout,"what happened");
      //fprintf(stdout,"dsf");

      //fprintf(stdout,"this is a test 9");
      break;

    case boolK:
    fprintf(stdout,"this is a test 10");
      break;

    case arrayK:
    fprintf(stdout,"this is a test 5");
      generate_TYPE(t->val.arrayT);
      break;

    case recordK:
    fprintf(stdout,"this is a test 6");
      generate_LIST(t->val.recordT);
      break;

    case vareK:
      generate_TYPE(t->val.vareT.variable);
      fprintf(stdout,"this is a test");
      break;

    case varexpK:
    fprintf(stdout,"this is a test 2");
      generate_TYPE(t->val.varexpT.variable);
      generate_EXP(t->val.varexpT.expression);
      break;

    case var_typeK:
      //add code
      fprintf(stdout,"this is a test 3");
      generate_TYPE(t->val.var_typeT.variable);
      break;

    default:
    fprintf(stdout,"this is a test 4");
      fprintf(stderr,"in default case in TYPE\n");
      break;
  }return;
}
