#include <stdio.h>
#include "../headers/gen.h"
#include"../headers/tree.h"


void generate_prologue(){
  fprintf(stdout,".text\n");
  fprintf(stdout,".globl _main\n");
  fprintf(stdout,"_main:\n");
  fprintf(stdout,"push %%rbp\n");
  fprintf(stdout,"movq %%rbp, %%rsp\n");
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
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp %%r14, %%r13\n");
      fprintf(stdout,"jeq .16\n");
      fprintf(stdout,"movq 1, %%r13\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"movq 0, %%r13\n");
      fprintf(stdout,"push %%r13\n");
      break;

    case nequaltoK:
      generate_EXP(e->val.nequaltoE.left);
      generate_EXP(e->val.nequaltoE.right);
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp %%r14, %%r13\n");
      fprintf(stdout,"jne .16\n");
      fprintf(stdout,"movq 1, %%r13\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"movq 0, %%r13\n");
      fprintf(stdout,"push %%r13\n");
      break;

    case andK:
      generate_EXP(e->val.andE.left);
      generate_EXP(e->val.andE.right);
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp 0, %%r13\n");
      fprintf(stdout,"jne .34\n");
      fprintf(stdout,"cmp 0, %%r14\n");
      fprintf(stdout,"jne .16\n");
      fprintf(stdout,"movq 0, %%r13\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"movq 1, %%r13\n");
      fprintf(stdout,"push %%r13\n");
      /*movq to RX*/
      /*movq to RY*/
      /*add RX RY to RZ (if true 0+0 = 0)*/
      break;

    case smallerK:
      generate_EXP(e->val.smallerE.left);
      generate_EXP(e->val.smallerE.right);
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp %%r13, %%r14\n");
      fprintf(stdout,"jge .16\n");
      fprintf(stdout,"movq 0, %%r13\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"movq 1, %%r13\n");
      fprintf(stdout,"push %%r13\n");
      break;

    case biggerK:
      generate_EXP(e->val.biggerE.left);
      generate_EXP(e->val.biggerE.right);
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp %%r13, %%r14\n");
      fprintf(stdout,"jle .16\n");
      fprintf(stdout,"movq 0, %%r13\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"movq 1, %%r13\n");
      fprintf(stdout,"push %%r13\n");
       break;

    case smalequalK:
      generate_EXP(e->val.smalequalE.left);
      generate_EXP(e->val.smalequalE.right);
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp %%r13, %%r14\n");
      fprintf(stdout,"jg .16\n");
      fprintf(stdout,"movq 0, %%r13\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"movq 1, %%r13\n");
      fprintf(stdout,"push %%r13\n");
       break;

    case bigequalK:
      generate_EXP(e->val.bigequalE.left);
      generate_EXP(e->val.bigequalE.right);
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp %%r13, %%r14\n");
      fprintf(stdout,"jl .16\n");
      fprintf(stdout,"movq 0, %%r13\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"movq 1, %%r13\n");
      fprintf(stdout,"push %%r13\n");
      break;

     case moduloK:
       generate_EXP(e->val.moduloE.left);
       generate_EXP(e->val.moduloE.right);
       fprintf(stdout,"pop %%r13\n");
       fprintf(stdout,"pop %%r14\n");
       fprintf(stdout,"cmp %%r14, %%r13\n");
       fprintf(stdout,"jl .22\n");
       fprintf(stdout,"sub %%r14, %%r13\n");
       fprintf(stdout,"jmp .-42\n");
       fprintf(stdout,"push %%r13\n");
       break;

     case timesK:
        generate_EXP(e->val.timesE.left);
        generate_EXP(e->val.timesE.right);
        fprintf(stdout,"pop %%r13\n");
        fprintf(stdout,"pop %%r14\n");
        fprintf(stdout,"movq %%r13, %%rax\n");
        fprintf(stdout,"mul %%r14\n");
        fprintf(stdout,"movq %%rax, %%r13\n");
        fprintf(stdout,"push %%r13\n");
         /*movq to RX*/
         /*movq to RY*/
         /*mul RX RY to RZ*/
         break;

     case divK:
       generate_EXP(e->val.divE.left);
       generate_EXP(e->val.divE.right);
       fprintf(stdout,"pop %%r13\n");
       fprintf(stdout,"pop %%r14\n");
       fprintf(stdout,"movq %%r13, %%rax\n");
       fprintf(stdout,"div %%r14\n");
       fprintf(stdout,"movq %%rax, %%r13\n");
       fprintf(stdout,"push %%r13\n");
       break;

     case plusK:
        generate_EXP(e->val.plusE.left);
        generate_EXP(e->val.plusE.right);
        fprintf(stdout,"pop %%r13\n");
        fprintf(stdout,"pop %%r14\n");
        fprintf(stdout,"add %%r14, %%r13\n");
        fprintf(stdout,"push %%r13\n");
        break;

    case minusK:
    generate_EXP(e->val.minusE.left);
    generate_EXP(e->val.minusE.right);
    fprintf(stdout,"pop %%r13\n");
    fprintf(stdout,"pop %%r14\n");
    fprintf(stdout,"sub %%r14, %%r13\n");
    fprintf(stdout,"push %%r13\n");
    break;

    case termK:
      aterm = generate_TERM(e->val.termE);
      fprintf(stdout,"push %i\n", aterm);
      break;

    case orK:
      generate_EXP(e->val.orE.left);
      generate_EXP(e->val.orE.right);
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp 0, %%r13\n");
      fprintf(stdout,"je .28\n");
      fprintf(stdout,"cmp 0, %%r14\n");
      fprintf(stdout,"je .11\n");
      fprintf(stdout,"movq 1, %%r13\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"movq 0, %%r13\n");
      fprintf(stdout,"push %%r13\n");
      break;

    default:
      fprintf(stdout,"in default case in EXP\n\n");
      break;
  }return;
}

void generate_epilogue(){
  fprintf(stdout,"call __alloca\n");
  fprintf(stdout,"call ___main\n");
  fprintf(stdout,"call _prinf\n");
  fprintf(stdout,"pop %%rbx\n");
  fprintf(stdout,"pop %%r14\n");
  fprintf(stdout,"pop %%r13\n");
  fprintf(stdout,"pop %%r12\n");
  fprintf(stdout,"pop %%rbx\n");
  fprintf(stdout,"movq %%rbp, %%rsp\n");
  fprintf(stdout,"pop %%rbp\n");
  fprintf(stdout,"movq 0, %%rax\n");
  fprintf(stdout,"ret\n");
}
