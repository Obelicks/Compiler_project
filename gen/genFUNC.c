#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/gen.h"

extern int regNr;
extern int debug;

void generate_FUNC(FUNC* function){
  switch (function->kind) {
    case functionK:
      generate_FUNC(function->val.functionF.head);
      generate_FUNC(function->val.functionF.body);
      generate_FUNC(function->val.functionF.tail);
      break;

    case headK:
      //parse_variables(function->val.headF.par_decl_list);
      //char* s = concat(function->val.headF.id, ":");
      //printf("%s\n", s);
      break;

    case bodyK:
      if (function->val.bodyF.decl_list != NULL) {
        generate_LIST( function->val.bodyF.decl_list);
      }
      generate_LIST( function->val.bodyF.statement_list);
      break;

    case tailK:
      //printf("#end of function", );
      break;

    default:
      fprintf(stderr,"in default case in FUNC (gen)\n");
      break;
  }return;
}
void parse_variables( LIST* decl_list){

}
char* concat(const char *s1, const char *s2){
    char *result = malloc(strlen(s1)+strlen(s2)+1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}
