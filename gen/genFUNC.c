#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/gen.h"
extern long long int jumpnr;
extern long long int variablecounter;
extern long long int returnadress;
void generate_FUNC(FUNC* function){
  long long int r;
  long long int r1;
  switch (function->kind) {
    case functionK:
      fprintf(stderr, "generating generate_FUNC -> functionK\n" );
      generate_FUNC(function->val.functionF.head);
      generate_FUNC(function->val.functionF.body);
      generate_FUNC(function->val.functionF.tail);
      break;

    case headK:
      r = jumpnr;
      jumpnr++;
      fprintf(stderr, "generating generate_FUNC -> headK\n" );
      fprintf(stdout,"jmp .%lli\n", r);
      fprintf(stdout,".%s:\n", function->val.headF.id);
      fprintf(stdout,"push %%r8\n");//static pointer.
      fprintf(stdout,"push %%r9\n");
      fprintf(stdout,"push %%r11\n");
      fprintf(stdout,"push %%r12\n");
      fprintf(stdout,"movq %%rsp, %%r15\n");
      variablecounter = 0;
      fprintf(stdout,"movq %%rsp, %%r8\n");
      fprintf(stdout,"add $-8, %%r8\n");
      if (function->val.headF.par_decl_list != NULL) {
        generate_LIST(function->val.headF.par_decl_list);

      }
      fprintf(stdout,"movq %%rsp, %%r9\n");
      if(variablecounter > 0){
      long long int temp = variablecounter*32;
      temp = temp + 24; //this is to reach past the saved registers.
      long long int temp2 = variablecounter*24;
      temp2 = temp2-24;
      for(;temp2 >= 0; temp2 = temp2 -24){

        fprintf(stdout,"movq %lli(%%rsp), %%r10\n", temp);
        temp = temp-8;
        fprintf(stdout,"movq %%r10, %lli(%%rsp)\n", temp2);
      }
    }
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
      fprintf(stdout,"pop %%r10\n");
      fprintf(stdout,"movq %%r15, %%rsp\n");
      fprintf(stdout,"pop %%r12\n");
      fprintf(stdout,"pop %%r11\n");
      fprintf(stdout,"pop %%r9\n");
      fprintf(stdout,"pop %%r8\n");
      fprintf(stdout,"push %%r10\n");
      fprintf(stdout, "jmp .%s1\n", function->val.headF.id);
      fprintf(stdout,".%lli:\n",(r));
      fprintf(stderr,"end of function %s", function->val.tailF);
      break;

    default:
      fprintf(stderr,"in default case in FUNC (gen)\n");
      break;
  }return;
}
/*void parse_variables( LIST* decl_list ){

}*/
