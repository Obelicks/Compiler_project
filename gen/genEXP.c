#include <stdio.h>
#include "../headers/gen.h"
#include"../headers/tree.h"

int generate_TERM(TERM* term);
void generate_prologue(){
  printf("form: \n");
  printf(".string \"%%d\n");
  printf("push %%rbp\n");
  printf("movq %%rsp, rbp\n");
  fprintf(stdout,"push %%rbx\n");
  fprintf(stdout,"push %%r12\n");
  fprintf(stdout,"push %%r13\n");
  fprintf(stdout,"push %%r14\n");
  fprintf(stdout,"push %%rbx\n");
}
/*void generate_FUNC(FUNC root);{

}*/


void generate_EXP(EXP* e){
  int aterm;
  TERM* t;
  switch (e->kind) {
    case equaltoK:
      generate_EXP(e->val.equaltoE.left);
      generate_EXP(e->val.equaltoE.right);
      printf("pop %%r13\n");
      printf("pop %%r14\n");
      printf("cmp %%r13, %%r14\n");
      printf("jeq .16\n");
      printf("mov %%r13, 1\n");
      printf("jmp .11\n");
      printf("mov %%r13, 0\n");
      printf("push %%r13\n");
      break;

    case nequaltoK:
      generate_EXP(e->val.nequaltoE.left);
      generate_EXP(e->val.nequaltoE.right);
      printf("pop %%r13\n");
      printf("pop %%r14\n");
      printf("cmp %%r13, %%r14\n");
      printf("jne .16\n");
      printf("mov %%r13, 1\n");
      printf("jmp .11\n");
      printf("mov %%r13, 0\n");
      printf("push %%r13\n");
      break;

    case andK:
      generate_EXP(e->val.andE.left);
      generate_EXP(e->val.andE.right);
      printf("pop %%r13\n");
      printf("pop %%r14\n");
      printf("cmp %%r13, 0\n");
      printf("jne .34\n");
      printf("cmp %%r14, 0\n");
      printf("jne .16\n");
      printf("mov %%r13, 0\n");
      printf("jmp .11\n");
      printf("mov %%r13, 1\n");
      printf("push %%r13\n");
      /*mov to RX*/
      /*mov to RY*/
      /*add RX RY to RZ (if true 0+0 = 0)*/
      break;

    case smallerK:
      generate_EXP(e->val.smallerE.left);
      generate_EXP(e->val.smallerE.right);
      printf("pop %%r13\n");
      printf("pop %%r14\n");
      printf("cmp %%r14, %%r13\n");
      printf("jge .16\n");
      printf("mov %%r13, 0\n");
      printf("jmp .11\n");
      printf("mov %%r13, 1\n");
      printf("push %%r13\n");
      break;

    case biggerK:
      generate_EXP(e->val.biggerE.left);
      generate_EXP(e->val.biggerE.right);
      printf("pop %%r13\n");
      printf("pop %%r14\n");
      printf("cmp %%r14, %%r13\n");
      printf("jle .16\n");
      printf("mov %%r13, 0\n");
      printf("jmp .11\n");
      printf("mov %%r13, 1\n");
      printf("push %%r13\n");
       break;

    case smalequalK:
      generate_EXP(e->val.smalequalE.left);
      generate_EXP(e->val.smalequalE.right);
      printf("pop %%r13\n");
      printf("pop %%r14\n");
      printf("cmp %%r14, %%r13\n");
      printf("jg .16\n");
      printf("mov %%r13, 0\n");
      printf("jmp .11\n");
      printf("mov %%r13, 1\n");
      printf("push %%r13\n");
       break;

    case bigequalK:
      generate_EXP(e->val.bigequalE.left);
      generate_EXP(e->val.bigequalE.right);
      printf("pop %%r13\n");
      printf("pop %%r14\n");
      printf("cmp %%r14, %%r13\n");
      printf("jl .16\n");
      printf("mov %%r13, 0\n");
      printf("jmp .11\n");
      printf("mov %%r13, 1\n");
      printf("push %%r13\n");
      break;

     case moduloK:
       generate_EXP(e->val.moduloE.left);
       generate_EXP(e->val.moduloE.right);
       printf("pop %%r13\n");
       printf("pop %%r14\n");
       printf("cmp %%r13, %%r14\n");
       printf("jl .22\n");
       printf("sub %%r13, %%r14\n");
       printf("jmp .-42\n");
       printf("push %%r13\n");
       break;

     case timesK:
        generate_EXP(e->val.timesE.left);
        generate_EXP(e->val.timesE.right);
        printf("pop %%r13\n");
        printf("pop %%r14\n");
        printf("mov %%AX, %%r13\n");
        printf("mul %%r14\n");
        printf("mov %%r13, %%AX\n");
        printf("push %%r13\n");
         /*mov to RX*/
         /*mov to RY*/
         /*mul RX RY to RZ*/
         break;

     case divK:
       generate_EXP(e->val.divE.left);
       generate_EXP(e->val.divE.right);
       printf("pop %%r13\n");
       printf("pop %%r14\n");
       printf("mov %%AX, %%r13\n");
       printf("div %%r14\n");
       printf("mov %%r13, %%AX\n");
       printf("push %%r13\n");
       /*mov to RX*/
       /*mov to RY*/
       /*div RX RY to RZ*/
       break;

     case plusK:
        generate_EXP(e->val.plusE.left);
        generate_EXP(e->val.plusE.right);
        printf("pop %%r13\n");
        printf("pop %%r14\n");
        printf("add %%r13, %%r14\n");
        printf("push %%r13\n");
         /*mov exp to RX*/
       /*mov exp to RY*/
       /*add RX RY to RZ*/
        break;

     case minusK:
      generate_EXP(e->val.minusE.left);
      generate_EXP(e->val.minusE.right);
      printf("pop %%r13\n");
      printf("pop %%r14\n");
      printf("sub %%r13, %%r14\n");
      printf("push %%r13\n");
       /*mov to RX*/
       /*mov to RY*/
       /*min RX RY to RZ*/
       break;

    case termK:
      aterm = generate_TERM(e->val.termE);
      //printf("%i \n", aterm);
      printf("push %i\n", aterm);
      break;

    case orK:
      generate_EXP(e->val.orE.left);
      generate_EXP(e->val.orE.right);
      printf("pop %%r13\n");
      printf("pop %%r14\n");
      printf("cmp %%r13, 0\n");
      printf("je .28\n");
      printf("cmp %%r14, 0\n");
      printf("je .11\n");
      printf("mov %%r13, 1\n");
      printf("jmp .11\n");
      printf("mov %%r13, 0\n");
      printf("push %%r13\n");
       /*mov to RX*/
       /*mov to RY*/
       //or RX RY -> RZ (or RX)
       break;

    default:
       fprintf(stdout,"in default case in EXP\n\n");
       break;
  }return;
}

void generate_epilogue(){
  printf("pop %%eax\n");
  printf("prinf %%eax\n");
  printf("pop %%rbx\n");
  printf("pop %%r14\n");
  printf("pop %%r13\n");
  printf("pop %%r12\n");
  printf("pop %%rbx\n");
  printf("movq %%rbp, %%rsp\n");
  printf("pop %%rbp\n");
  printf("mov1 %%0, %%rax ret\n");
}
