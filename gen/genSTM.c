#include <stdio.h>
#include "../headers/gen.h"

void generate_STM( STM *s){
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
      generate_EXP(s->val.ifthenS.ifState);
      generate_STM(s->val.ifthenS.thenState);
      break;

    case ifelseK:
      generate_EXP(s->val.ifelseS.ifState);
      fprintf(stdout, "movq 0 %%rax\ncmp %%rax %%r15\nje else\n");
      generate_STM(s->val.ifelseS.thenState);
      fprintf(stdout, "jmp end\n else:\n");

      generate_STM(s->val.ifelseS.elseState);
      fprintf(stdout, "end:\n", );
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
