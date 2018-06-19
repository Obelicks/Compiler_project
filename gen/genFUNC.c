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
      fprintf(stdout,".data\n");
      fprintf(stdout,"format: .ascii \"%%d\\n\"\n");
      fprintf(stdout,".text\n");
      fprintf(stdout, ".globl %s:\n", function->val.headF.id);
      fprintf(stdout, "%s:\n", function->val.headF.id);
      fprintf(stdout,"subq $8, %%rsp\n");
      fprintf(stdout,"movq $0, %%rdi\n");
      fprintf(stdout,"push %%r13\n");
      fprintf(stdout,"push %%r14\n");
      fprintf(stdout,"push %%rax\n");
      //TODO function prologue with parsing variables
      break;

    case bodyK:
      if (function->val.bodyF.decl_list != NULL) {
        generate_LIST(function->val.bodyF.decl_list);
      }
      generate_LIST(function->val.bodyF.statement_list);//cant be empty so no reason to check
      break;

    case tailK:
      fprintf(stdout,"mov $format, %%rdi\n");
      fprintf(stdout,"pop %%rsi\n");
      fprintf(stdout,"mov $0, %%eax\n");
      fprintf(stdout,"call printf\n");
      fprintf(stdout,"pop %%rax\n");
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
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
