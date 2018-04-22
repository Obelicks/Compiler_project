#include <stdio.h>
#include "../headers/gen.h"
extern FILE* file;
void generate_FUNC(FILE* file, FUNC* function){
  switch (function->kind) {
    case functionK:
      generate_FUNC(file, function->val.functionF.head);
      generate_FUNC(file, function->val.functionF.body);
      generate_FUNC(file, function->val.functionF.tail);
      break;

    case headK:
      parse_variables(file,function->val.headF.par_decl_list);
      break;

    case bodyK:
      generate_LIST(file, function->val.bodyF.decl_list);
      generate_LIST(file, function->val.bodyF.statement_list);
      break;

    case tailK:
      fputs("#/end of function", file);
      break;

    default:
      printf("in default case in FUNC (gen)\n");
      break;
  }
}
void parse_variables(FILE* file, LIST* decl_list){
}
