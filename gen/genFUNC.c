#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/gen.h"

extern int regNr;

void generate_FUNC(FILE* file, FUNC* function){
  switch (function->kind) {
    case functionK:
      generate_FUNC(file, function->val.functionF.head);
      generate_FUNC(file, function->val.functionF.body);
      generate_FUNC(file, function->val.functionF.tail);
      break;

    case headK:
      parse_variables(file,function->val.headF.par_decl_list);
      char* s = concat(function->val.headF.id, ":");
      fputs(s,file);
      break;

    case bodyK:
      generate_LIST(file, function->val.bodyF.decl_list);
      generate_LIST(file, function->val.bodyF.statement_list);
      break;

    case tailK:
      fputs("#end of function", file);
      break;

    default:
      printf("in default case in FUNC (gen)\n");
      break;
  }
}
void parse_variables(FILE* file, LIST* decl_list){
}
char* concat(const char *s1, const char *s2){
    char *result = malloc(strlen(s1)+strlen(s2)+1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}
