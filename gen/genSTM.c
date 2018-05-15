#include <stdio.h>
#include "../headers/gen.h"

int rand();
void generate_STM( STM *s){
  int r;
  switch (s->kind) {
    case returnK:
      generate_EXP(s->val.returnS);
      break;

    case writeK:
      generate_EXP(s->val.writeS);
      break;

   case allocateK:
      generate_TYPE(s->val.allocateS);
      break;

    case allocateoflengthK:
      generate_TYPE(s->val.allocateoflengthS.variable);
      break;

    case assignK:
      generate_TYPE( s->val.assignS.variable);
      generate_EXP( s->val.assignS.expression);
      break;

    case ifthenK:
      r = rand();
      generate_EXP(s->val.ifthenS.ifState);
      fprintf(stdout, "movq 0 %%rax\ncmp %%rax %%r15\njne %i\n",r);
      generate_STM(s->val.ifthenS.thenState);
      fprintf(stdout, "%i:\n",r);
      break;

    case ifelseK:
      r = rand();
      generate_EXP(s->val.ifelseS.ifState);
      fprintf(stdout, "movq 0 %%rax\ncmp %%rax %%r15\njne %i\n",r);
      generate_STM(s->val.ifelseS.thenState);
      fprintf(stdout, "jmp %i\n %i:\n",r+1,r);
      generate_STM(s->val.ifelseS.elseState);
      fprintf(stdout, "%i:\n",r );
      break;

    case whileK:
      generate_EXP(s->val.whileS.expression);
      if(s->val.whileS.statement->kind == stmlistK){
        generate_LIST(s->val.whileS.statement->val.stmlistS);
      }else{
        generate_STM(s->val.whileS.statement);
      }
      break;

    case stmlistK:
      break;

    default:
      fprintf(stderr,"in default case in STM\n");
      break;
  }return;
}
