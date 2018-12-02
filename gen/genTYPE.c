#include <stdio.h>
#include "../headers/gen.h"
#include "../headers/symbol.h"

void generate_TYPE(TYPE* t){
  fprintf(stderr, "generating generate_TYPE\n" );
   switch (t->kind) {
    case idK:
      fprintf(stderr, "generating generate_TYPE -> idK\n" );
      break;

    case intconstK:
      fprintf(stderr, "generating generate_TYPE -> intconstK\n" );
      fprintf(stdout, "push $%i\n", t->kind);
      //fprintf(stdout,"this is a test 9");
      break;

    case boolK:
      fprintf(stderr, "generating generate_TYPE -> boolK\n" );
      break;

    case arrayK:
      fprintf(stderr, "generating generate_TYPE -> arrayK\n" );
      generate_TYPE(t->val.arrayT);
      break;

    case recordK:
      fprintf(stderr, "generating generate_TYPE -> recordK\n" );
      generate_LIST(t->val.recordT);
      break;

    case vareK:
      fprintf(stderr, "generating generate_TYPE -> vareK\n" );
      generate_TYPE(t->val.vareT.variable);
      break;

    case varexpK:
      fprintf(stderr, "generating generate_TYPE -> varexpK\n" );
      generate_TYPE(t->val.varexpT.variable);
      generate_EXP(t->val.varexpT.expression);
      break;

    case var_typeK:
      fprintf(stderr, "generating generate_TYPE -> var_typeK\n" );
      //add code
      fprintf(stderr, "EMIL2 %s \n", t->val.var_typeT.id);
      fprintf(stdout, "push $%i \n",hash(t->val.var_typeT.id));
      generate_TYPE(t->val.var_typeT.variable);
      fprintf(stdout, "push $0 \n");

      break;

    default:
      fprintf(stderr,"in default case in TYPE\n");
      break;
  }return;
}
