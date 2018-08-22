#include <stdio.h>
#include "../headers/gen.h"

int rand();
void generate_STM(STM* s){
  int r;
  int r1;
  switch (s->kind) {
    case returnK:
      generate_EXP(s->val.returnS);
      break;

    case writeK:
      generate_EXP(s->val.writeS);
      fprintf(stdout,"movq $format, %%rdi\n");
      fprintf(stdout,"pop %%rsi\n");
      fprintf(stdout,"movq $0, %%rax\n");
      fprintf(stdout,"push %%r13\n");
      fprintf(stdout,"push %%r14\n");
      fprintf(stdout,"push %%rax\n");
      fprintf(stdout,"push %%r8\n");
      fprintf(stdout,"push %%r9\n");
      fprintf(stdout,"push %%r10\n");
      fprintf(stdout,"push %%r11\n");
      fprintf(stdout,"push %%r12\n");
      fprintf(stdout,"push %%rsi\n");
      fprintf(stdout,"push %%rax\n");
      fprintf(stdout,"call printf\n");
      fprintf(stdout,"pop %%rax\n");
      fprintf(stdout,"pop %%rsi\n");
      fprintf(stdout,"pop %%r12\n");
      fprintf(stdout,"pop %%r11\n");
      fprintf(stdout,"pop %%r10\n");
      fprintf(stdout,"pop %%r9\n");
      fprintf(stdout,"pop %%r8\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"pop %%r13\n");
      break;

   case allocateK:
      generate_TYPE(s->val.allocateS);
      break;

    case allocateoflengthK:
      generate_TYPE(s->val.allocateoflengthS.variable);
      break;

    case assignK:
      //typie, code to assign value to variableK
      fprintf(stdout,"movq %%r8, %%r11\n");
      fprintf(stdout,"movq $'%s', %%r12\n",s->val.assignS.variable->val.idT);
      fprintf(stdout,"cmp (%%r11), %%r12\n");
      fprintf(stdout,"je .+11\n");
      fprintf(stdout,"add $192, %%r11\n");
      fprintf(stdout,"jmp .-12\n");
      generate_EXP( s->val.assignS.expression);
      fprintf(stdout,"movq %%r13, 128(%%r11)\n");

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
      fprintf(stdout, "movq 0 %%rax\n");
      fprintf(stdout, "cmp %%rax %%r15\n");
      fprintf(stdout, "jne %i\n", r);
      generate_STM(s->val.ifelseS.thenState);
      fprintf(stdout, "jmp %i\n %i:\n",r+1,r);
      generate_STM(s->val.ifelseS.elseState);
      fprintf(stdout, "%i:\n",r );
      break;

    case whileK:
      r = rand();
      r1 = rand();
      fprintf(stdout,"%i:\n", r1);
      generate_EXP(s->val.whileS.expression);
      fprintf(stdout,"jne %i\n", r);
      if(s->val.whileS.statement->kind == stmlistK){
        generate_LIST(s->val.whileS.statement->val.stmlistS);
      }else{
        generate_STM(s->val.whileS.statement);
      }
      fprintf(stdout,"jmp %i\n", r1);
      fprintf(stdout,"%i\n", r);

      break;

    case stmlistK:
      break;

    default:
      fprintf(stderr,"in default case in STM\n");
      break;
  }return;
}
