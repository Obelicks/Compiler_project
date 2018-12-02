#include <stdio.h>
#include "../headers/gen.h"
extern long long int jumpnr;

void generate_STM(STM* s, int flag){
  fprintf(stderr, "generating generate_STM %d \n",s->kind);
  long long int r;
  long long int r1, r2, r3;
  switch (s->kind) {
    case returnK:
      fprintf(stderr, "generating generate_STM -> returnK \n" );
      generate_EXP(s->val.returnS, flag);
      break;

    case writeK:
      fprintf(stderr, "generating generate_STM -> writeK \n" );
      generate_EXP(s->val.writeS, flag);

      fprintf(stdout,"movq $format, %%rdi\n");
      fprintf(stdout,"pop %%rsi\n");
      fprintf(stdout,"xorq	%%rax, %%rax\n");
      fprintf(stdout,"push %%r15\n");
      fprintf(stdout,"push %%r12\n");
      fprintf(stdout,"push %%r11\n");
      fprintf(stdout,"push %%r9\n");
      fprintf(stdout,"push %%r8\n");
      fprintf(stdout,"push %%rdx\n");
      fprintf(stdout,"call	printf\n");
      fprintf(stdout,"pop %%rdx\n");
      fprintf(stdout,"pop %%r8\n");
      fprintf(stdout,"pop %%r9\n");
      fprintf(stdout,"pop %%r11\n");
      fprintf(stdout,"pop %%r12\n");
      fprintf(stdout,"pop %%r15\n");
      break;

   case allocateK:
     fprintf(stderr, "generating generate_STM -> allocateK \n" );
      generate_TYPE(s->val.allocateS, flag);
      break;

    case allocateoflengthK:
      fprintf(stderr, "generating generate_STM -> allocateoflengthK \n" );
      generate_TYPE(s->val.allocateoflengthS.variable, flag);
      break;

    case assignK:
      r=jumpnr;
      jumpnr++;
      r1 = jumpnr;
      jumpnr++;
      r2 = jumpnr;
      jumpnr++;
      r3 = jumpnr;
      jumpnr++;

      //typie, code to assign value to variableK
      fprintf(stdout,"movq %%r8, %%r11\n");
      fprintf(stdout,"movq $%i, %%r12\n",hash(s->val.assignS.variable->val.idT));
      fprintf(stdout,"movq %%r9, %%r10\n");
      fprintf(stdout, ".%lli:\n",r1);
      fprintf(stdout,"cmp (%%r11), %%r12\n");
      fprintf(stdout, "je .%lli\n",r);
      fprintf(stdout,"add $-24, %%r11\n");
      fprintf(stdout,"cmp %%r11, %%r10\n");
      fprintf(stdout, "jg .%lli\n",r2);
      fprintf(stdout, "jmp .%lli\n",r1);
      fprintf(stdout, ".%lli:\n",r);
      fprintf(stderr, "generating generate_STM -> assignK \n" );
      generate_EXP(s->val.assignS.expression, flag);
      fprintf(stdout,"pop -16(%%r11)\n");
      fprintf(stdout, "jmp .%lli\n",r3);
      fprintf(stdout, ".%lli:\n",r2);
      fprintf(stdout, "movq 40(%%r8), %%r11\n");
      fprintf(stdout, "movq 32(%%r8), %%r10\n");
      fprintf(stdout, "jmp .%lli\n",r1);
      fprintf(stdout, ".%lli:\n",r3);
      break;

    case ifthenK:
      r =jumpnr;
      jumpnr++;
      fprintf(stderr, "generating generate_STM -> ifthenK \n" );
      generate_EXP(s->val.ifthenS.ifState, flag);
      fprintf(stdout, "pop %%r14\n");
      fprintf(stdout, "cmp $0, %%r14\n");
      fprintf(stdout, "jne .%lli\n",r);
      generate_STM(s->val.ifthenS.thenState, flag);
      fprintf(stdout, ".%lli:\n",r);

      break;

    case ifelseK:
      r=jumpnr;
      jumpnr++;
      r1=jumpnr;
      jumpnr++;

      fprintf(stderr, "generating generate_STM -> ifelseK \n" );

      generate_EXP(s->val.ifelseS.ifState, flag);
      fprintf(stdout, "pop %%r14\n");
      fprintf(stdout, "cmp $0, %%r14\n");
      fprintf(stdout, "jne .%lli\n",r);
      generate_STM(s->val.ifelseS.thenState, flag);
      fprintf(stdout, "jmp .%lli\n",r1);
      fprintf(stdout, ".%lli:\n",r);
      generate_STM(s->val.ifelseS.elseState, flag);
      fprintf(stdout, ".%lli:\n",r1);

      break;

    case whileK:
      //TODO figure out a better way than rand?

      fprintf(stderr, "generating generate_STM -> whileK \n" );

      generate_EXP(s->val.whileS.expression, flag);
      r = jumpnr;
      jumpnr++;
      r1= jumpnr;
      jumpnr++;
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp $0, %%r14\n");
      fprintf(stdout,"jne .%lli\n", r);
      fprintf(stdout,".%lli:\n",r1);
      if(s->val.whileS.statement->kind == stmlistK){
        generate_LIST(s->val.whileS.statement->val.stmlistS, flag);
      }else{
        generate_STM(s->val.whileS.statement, flag);
      }
      generate_EXP(s->val.whileS.expression, flag);
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp $0, %%r14\n");
      fprintf(stdout,"je .%lli\n", r1);
      fprintf(stdout,".%lli:\n", r);

      break;

    case stmlistK:
      fprintf(stderr, "generating generate_STM -> stmlistK \n" );

      if (s->val.stmlistS != NULL){
        generate_LIST(s->val.stmlistS, flag);
      }
      break;
    default:
      fprintf(stderr,"in default case in STM\n");
      break;
  }return;
}
