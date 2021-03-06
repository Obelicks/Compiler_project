#include <stdio.h>
#include "../headers/gen.h"
#include"../headers/tree.h"


void generate_prologue(){
  fprintf(stdout,".data\n");
  fprintf(stdout,"format: .ascii \"%%d\\n\"\n");
  fprintf(stdout,".text\n");
  fprintf(stdout,".globl main\n");
  fprintf(stdout,"main:\n");
  fprintf(stdout,"subq $8, %%rsp\n");
  fprintf(stdout,"movq $0, %%rdi\n");
  fprintf(stdout,"push %%r13\n");
  fprintf(stdout,"push %%r14\n");
  fprintf(stdout,"push %%rax\n");
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
      fprintf(stdout,"je .+11\n");
      fprintf(stdout,"movq $1, %%r13\n");
      fprintf(stdout,"jmp .+9\n");
      fprintf(stdout,"movq $0, %%r13\n");
      fprintf(stdout,"push %%r13\n");
      break;

    case nequaltoK:
      generate_EXP(e->val.nequaltoE.left);
      generate_EXP(e->val.nequaltoE.right);
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp %%r14, %%r13\n");
      fprintf(stdout,"jne .+11\n");
      fprintf(stdout,"movq $1, %%r13\n");
      fprintf(stdout,"jmp .+9\n");
      fprintf(stdout,"movq $0, %%r13\n");
      fprintf(stdout,"push %%r13\n");
      break;

    case andK:
      generate_EXP(e->val.andE.left);
      generate_EXP(e->val.andE.right);
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp $0, %%r13\n");
      fprintf(stdout,"jne .+18\n");
      fprintf(stdout,"cmp $0, %%r14\n");
      fprintf(stdout,"jne .+11\n");
      fprintf(stdout,"movq $0, %%r13\n");
      fprintf(stdout,"jmp .+9\n");
      fprintf(stdout,"movq $1, %%r13\n");
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
      fprintf(stdout,"jge .+11\n");
      fprintf(stdout,"movq $0, %%r13\n");
      fprintf(stdout,"jmp .+9\n");
      fprintf(stdout,"movq $1, %%r13\n");
      fprintf(stdout,"push %%r13\n");
      break;

    case biggerK:
      generate_EXP(e->val.biggerE.left);
      generate_EXP(e->val.biggerE.right);
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp %%r13, %%r14\n");
      fprintf(stdout,"jle .+11\n");
      fprintf(stdout,"movq $0, %%r13\n");
      fprintf(stdout,"jmp .+9\n");
      fprintf(stdout,"movq $1, %%r13\n");
      fprintf(stdout,"push %%r13\n");
       break;

    case smalequalK:
      generate_EXP(e->val.smalequalE.left);
      generate_EXP(e->val.smalequalE.right);
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp %%r13, %%r14\n");
      fprintf(stdout,"jg .+11\n");
      fprintf(stdout,"movq $0, %%r13\n");
      fprintf(stdout,"jmp .+9\n");
      fprintf(stdout,"movq $1, %%r13\n");
      fprintf(stdout,"push %%r13\n");
      break;

    case bigequalK:
      generate_EXP(e->val.bigequalE.left);
      generate_EXP(e->val.bigequalE.right);
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp %%r13, %%r14\n");
      fprintf(stdout,"jl .+11\n");
      fprintf(stdout,"movq $0, %%r13\n");
      fprintf(stdout,"jmp .+9\n");
      fprintf(stdout,"movq $1, %%r13\n");
      fprintf(stdout,"push %%r13\n");
      break;

     case moduloK:
       generate_EXP(e->val.moduloE.left);
       generate_EXP(e->val.moduloE.right);
       fprintf(stdout,"pop %%r14\n");
       fprintf(stdout,"pop %%r13\n");
       fprintf(stdout,"cmp %%r14, %%r13\n");
       fprintf(stdout,"jl .+7\n");
       fprintf(stdout,"sub %%r14, %%r13\n");
       fprintf(stdout,"jmp .-8\n");
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
       fprintf(stdout,"xor %%rdx, %%rdx\n");
       fprintf(stdout,"movq %%r14, %%rax\n");
       fprintf(stdout,"idiv %%r13\n");
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
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"sub %%r14, %%r13\n");
      fprintf(stdout,"push %%r13\n");
      break;

    case termK:
      aterm = generate_TERM(e->val.termE);
      //TODO since term can be more than just an integer value
      //we will have to move this code into genTerm.c at some point
      //fprintf(stdout,"%i \n", aterm);
      fprintf(stdout,"movq $%i, %%r13\n", aterm);
      fprintf(stdout,"push %%r13\n");
      break;

    case orK:
      generate_EXP(e->val.orE.left);
      generate_EXP(e->val.orE.right);
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp $0, %%r13\n");
      fprintf(stdout,"je .+17\n");
      fprintf(stdout,"cmp $0, %%r14\n");
      fprintf(stdout,"je .+11\n");
      fprintf(stdout,"movq $1, %%r13\n");
      fprintf(stdout,"jmp .+9\n");
      fprintf(stdout,"movq $0, %%r13\n");
      fprintf(stdout,"push %%r13\n");
      break;

    default:
      fprintf(stdout,"in default case in EXP\n\n");
      break;
  }return;
}

void generate_epilogue(){
  fprintf(stdout,"mov $format, %%rdi\n");
  fprintf(stdout,"pop %%rsi\n");
  fprintf(stdout,"mov $0, %%eax\n");
  fprintf(stdout,"call printf\n");
  fprintf(stdout,"pop %%rax\n");
  fprintf(stdout,"pop %%r13\n");
  fprintf(stdout,"pop %%r14\n");
  fprintf(stdout,"call _exit\n");
}
