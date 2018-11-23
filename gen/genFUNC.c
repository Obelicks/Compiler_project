#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/gen.h"

void generate_FUNC(FUNC* function){
  switch (function->kind) {
    case functionK:
      fprintf(stderr, "generating generate_FUNC -> functionK\n" );
      generate_FUNC(function->val.functionF.head);
      generate_FUNC(function->val.functionF.body);
      generate_FUNC(function->val.functionF.tail);
      break;

    case headK:
      fprintf(stderr, "generating generate_FUNC -> headK\n" );
      fprintf(stdout,"%lli:\n",(long long int) function->val.headF.id);
    //  function->val.headF.par_decl_list

      break;

    case bodyK:
      fprintf(stderr, "generating generate_FUNC -> bodyK\n" );
      if (function->val.bodyF.decl_list != NULL) {
        generate_LIST(function->val.bodyF.decl_list);
      }
      generate_LIST(function->val.bodyF.statement_list);//cant be empty so no reason to check
      break;

    case tailK:
      fprintf(stderr, "generating generate_FUNC -> tailK\n" );
      fprintf(stdout,"mov $format, %%rdi\n");
      fprintf(stdout,"pop %%rsi\n");
      fprintf(stdout,"movq $0, %%rax\n");
      fprintf(stdout,"call printf\n");
      fprintf(stdout,"pop %%rax\n");
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stderr,"end of function %s", function->val.tailF);
      break;

    default:
      fprintf(stderr,"in default case in FUNC (gen)\n");
      break;
  }return;
}
/*void parse_variables( LIST* decl_list ){

}*/
