#include <stdio.h>
#include "../headers/gen.h"

int rand();
void generate_STM(STM* s){
  fprintf(stderr, "generating generate_STM \n" );
  int r;
  int r1;
  switch (s->kind) {
    case returnK:
      fprintf(stderr, "generating generate_STM -> returnK \n" );
      generate_EXP(s->val.returnS);
      break;

    case writeK:
      fprintf(stderr, "generating generate_STM -> writeK \n" );
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
     fprintf(stderr, "generating generate_STM -> allocateK \n" );
      generate_TYPE(s->val.allocateS);
      break;

    case allocateoflengthK:
      fprintf(stderr, "generating generate_STM -> allocateoflengthK \n" );
      generate_TYPE(s->val.allocateoflengthS.variable);
      break;

    case assignK:
      //typie, code to assign value to variableK
      fprintf(stdout,"movq %%r8, %%r11\n");
      fprintf(stdout,"movq $%i, %%r12\n",(long long int)*s->val.assignS.variable->val.idT);
      fprintf(stdout,"cmp (%%r11), %%r12\n");
      fprintf(stdout,"je .+11\n");
      fprintf(stdout,"add $192, %%r11\n");
      fprintf(stdout,"jmp .-12\n");
      fprintf(stderr, "generating generate_STM -> assignK \n" );
      generate_EXP(s->val.assignS.expression);
      fprintf(stdout,"pop 128(%%r11)\n");

      break;

    case ifthenK:
      //TODO figure out a better way than rand?
      fprintf(stderr, "generating generate_STM -> ifthenK \n" );
      r = rand();
      generate_EXP(s->val.ifthenS.ifState);
      fprintf(stdout, "movq 0 %%rax\ncmp %%rax %%r15\njne %i\n",r);
      generate_STM(s->val.ifthenS.thenState);
      fprintf(stdout, "%i:\n",r);
      break;

    case ifelseK:
      //TODO figure out a better way than rand?
      fprintf(stderr, "generating generate_STM -> ifelseK \n" );
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
      //TODO figure out a better way than rand?

      fprintf(stderr, "generating generate_STM -> whileK \n" );
      fprintf(stdout, "movq .+7 %%r10\n");

      fprintf(stdout,"");
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
      fprintf(stderr, "generating generate_STM -> stmlistK \n" );
      break;

    default:
      fprintf(stderr,"in default case in STM\n");
      break;
  }return;
}
