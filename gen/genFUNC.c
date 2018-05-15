#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/gen.h"

void generate_FUNC(FUNC* function){
  switch (function->kind) {
    case functionK:
      generate_FUNC(function->val.functionF.head);
      generate_FUNC(function->val.functionF.body);
      generate_FUNC(function->val.functionF.tail);
      break;

    case headK:
      fprintf(stdout, "%s:\n", function->val.headF.id);
      //TODO function prologue with parsing variables
      break;

    case bodyK:
      if (function->val.bodyF.decl_list != NULL) {
        generate_LIST(function->val.bodyF.decl_list);
      }
      generate_LIST(function->val.bodyF.statement_list);//cant be empty so no reason to check
      break;

    case tailK:
      //TODO write epilogoue?
      fprintf(stderr,"end of function %s", function->val.tailF);
      break;

    default:
      fprintf(stderr,"in default case in FUNC (gen)\n");
      break;
  }return;
}
/*void parse_variables( LIST* decl_list ){

}*/
