#include <stdio.h>
#include "../headers/gen.h"
#include"../headers/tree.h"

int generate_TERM(TERM* term);
void generate_prologue(){
  fprintf(stdout,"form: \n");
  fprintf(stdout,".string \"%%d\n");
  fprintf(stdout,"push %%rbp\n");
  fprintf(stdout,"movq %%rsp, rbp\n");
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
      fprintf(stdout,"cmp %%r13, %%r14\n");
      fprintf(stdout,"jeq .16\n");
      fprintf(stdout,"mov %%r13, 1\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"mov %%r13, 0\n");
      fprintf(stdout,"push %%r13\n");
      break;

    case nequaltoK:
      generate_EXP(e->val.nequaltoE.left);
      generate_EXP(e->val.nequaltoE.right);
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp %%r13, %%r14\n");
      fprintf(stdout,"jne .16\n");
      fprintf(stdout,"mov %%r13, 1\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"mov %%r13, 0\n");
      fprintf(stdout,"push %%r13\n");
      break;

    case andK:
      generate_EXP(e->val.andE.left);
      generate_EXP(e->val.andE.right);
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp %%r13, 0\n");
      fprintf(stdout,"jne .34\n");
      fprintf(stdout,"cmp %%r14, 0\n");
      fprintf(stdout,"jne .16\n");
      fprintf(stdout,"mov %%r13, 0\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"mov %%r13, 1\n");
      fprintf(stdout,"push %%r13\n");
      /*mov to RX*/
      /*mov to RY*/
      /*add RX RY to RZ (if true 0+0 = 0)*/
      break;

    case smallerK:
      generate_EXP(e->val.smallerE.left);
      generate_EXP(e->val.smallerE.right);
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp %%r14, %%r13\n");
      fprintf(stdout,"jge .16\n");
      fprintf(stdout,"mov %%r13, 0\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"mov %%r13, 1\n");
      fprintf(stdout,"push %%r13\n");
      break;

    case biggerK:
      generate_EXP(e->val.biggerE.left);
      generate_EXP(e->val.biggerE.right);
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp %%r14, %%r13\n");
      fprintf(stdout,"jle .16\n");
      fprintf(stdout,"mov %%r13, 0\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"mov %%r13, 1\n");
      fprintf(stdout,"push %%r13\n");
       break;

    case smalequalK:
      generate_EXP(e->val.smalequalE.left);
      generate_EXP(e->val.smalequalE.right);
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp %%r14, %%r13\n");
      fprintf(stdout,"jg .16\n");
      fprintf(stdout,"mov %%r13, 0\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"mov %%r13, 1\n");
      fprintf(stdout,"push %%r13\n");
       break;

    case bigequalK:
      generate_EXP(e->val.bigequalE.left);
      generate_EXP(e->val.bigequalE.right);
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp %%r14, %%r13\n");
      fprintf(stdout,"jl .16\n");
      fprintf(stdout,"mov %%r13, 0\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"mov %%r13, 1\n");
      fprintf(stdout,"push %%r13\n");
      break;

     case moduloK:
       generate_EXP(e->val.moduloE.left);
       generate_EXP(e->val.moduloE.right);
       fprintf(stdout,"pop %%r13\n");
       fprintf(stdout,"pop %%r14\n");
       fprintf(stdout,"cmp %%r13, %%r14\n");
       fprintf(stdout,"jl .22\n");
       fprintf(stdout,"sub %%r13, %%r14\n");
       fprintf(stdout,"jmp .-42\n");
       fprintf(stdout,"push %%r13\n");
       break;

     case timesK:
        generate_EXP(e->val.timesE.left);
        generate_EXP(e->val.timesE.right);
        fprintf(stdout,"pop %%r13\n");
        fprintf(stdout,"pop %%r14\n");
        fprintf(stdout,"mov %%AX, %%r13\n");
        fprintf(stdout,"mul %%r14\n");
        fprintf(stdout,"mov %%r13, %%AX\n");
        fprintf(stdout,"push %%r13\n");
         /*mov to RX*/
         /*mov to RY*/
         /*mul RX RY to RZ*/
         break;

     case divK:
       generate_EXP(e->val.divE.left);
       generate_EXP(e->val.divE.right);
       fprintf(stdout,"pop %%r13\n");
       fprintf(stdout,"pop %%r14\n");
       fprintf(stdout,"mov %%AX, %%r13\n");
       fprintf(stdout,"div %%r14\n");
       fprintf(stdout,"mov %%r13, %%AX\n");
       fprintf(stdout,"push %%r13\n");
       /*mov to RX*/
       /*mov to RY*/
       /*div RX RY to RZ*/
       break;

     case plusK:
        generate_EXP(e->val.plusE.left);
        generate_EXP(e->val.plusE.right);
        fprintf(stdout,"pop %%r13\n");
        fprintf(stdout,"pop %%r14\n");
        fprintf(stdout,"add %%r13, %%r14\n");
        fprintf(stdout,"push %%r13\n");
         /*mov exp to RX*/
       /*mov exp to RY*/
       /*add RX RY to RZ*/
        break;

     case minusK:
      generate_EXP(e->val.minusE.left);
      generate_EXP(e->val.minusE.right);
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"sub %%r13, %%r14\n");
      fprintf(stdout,"push %%r13\n");
       /*mov to RX*/
       /*mov to RY*/
       /*min RX RY to RZ*/
       break;

    case termK:
      aterm = generate_TERM(e->val.termE);
      //fprintf(stdout,"%i \n", aterm);
      fprintf(stdout,"push %i\n", aterm);
      break;

    case orK:
      generate_EXP(e->val.orE.left);
      generate_EXP(e->val.orE.right);
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp %%r13, 0\n");
      fprintf(stdout,"je .28\n");
      fprintf(stdout,"cmp %%r14, 0\n");
      fprintf(stdout,"je .11\n");
      fprintf(stdout,"mov %%r13, 1\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"mov %%r13, 0\n");
      fprintf(stdout,"push %%r13\n");
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
  fprintf(stdout,"pop %%eax\n");
  fprintf(stdout,"prinf %%eax\n");
  fprintf(stdout,"pop %%rbx\n");
  fprintf(stdout,"pop %%r14\n");
  fprintf(stdout,"pop %%r13\n");
  fprintf(stdout,"pop %%r12\n");
  fprintf(stdout,"pop %%rbx\n");
  fprintf(stdout,"movq %%rbp, %%rsp\n");
  fprintf(stdout,"pop %%rbp\n");
  fprintf(stdout,"mov1 %%0, %%rax ret\n");
}
