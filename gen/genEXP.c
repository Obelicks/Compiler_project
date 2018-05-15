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
  fprintf(stdout,"push %%r12 push %%r13\n");
  fprintf(stdout,"push %%r14 push %%rbx\n");
}
/*void generate_FUNC(FUNC root);{

}*/


void generate_EXP_V(EXP* e){
  int aterm;
  TERM* t;
  switch (e->kind) {
    case equaltoK:
      generate_EXP_V(e->val.equaltoE.left);
      generate_EXP_H(e->val.equaltoE.right);
      fprintf(stdout,"cmp %%r13, %%r14\n");
      fprintf(stdout,"jeq .16\n");
      fprintf(stdout,"mov %%r13, 1\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"mov %%r13, 0\n");
      fprintf(stdout,"mov %%rbx, %%r13\n");
      break;

    case nequaltoK:
      generate_EXP_V(e->val.nequaltoE.left);
      generate_EXP_H(e->val.nequaltoE.right);
      fprintf(stdout,"cmp %%r13, %%r14\n");
      fprintf(stdout,"jne .16\n");
      fprintf(stdout,"mov %%r13, 1\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"mov %%r13, 0\n");
      fprintf(stdout,"mov %%rbx, %%r13\n");
      break;

    case andK:
      generate_EXP_V(e->val.andE.left);
      generate_EXP_H(e->val.andE.right);
      fprintf(stdout,"cmp %%r13, 0\n");
      fprintf(stdout,"jne .34\n");
      fprintf(stdout,"cmp %%r14, 0\n");
      fprintf(stdout,"jne .16\n");
      fprintf(stdout,"mov %%r13, 0\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"mov %%r13, 1\n");
      fprintf(stdout,"mov %%rbx, %%r13\n");
      /*mov to RX*/
      /*mov to RY*/
      /*add RX RY to RZ (if true 0+0 = 0)*/
      break;

    case smallerK:
      generate_EXP_V(e->val.smallerE.left);
      generate_EXP_H(e->val.smallerE.right);
      fprintf(stdout,"cmp %%r14, %%r13\n");
      fprintf(stdout,"jge .16\n");
      fprintf(stdout,"mov %%r13, 0\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"mov %%r13, 1\n");
      fprintf(stdout,"mov %%rbx, %%r13\n");
      break;

    case biggerK:
      generate_EXP_V(e->val.biggerE.left);
      generate_EXP_H(e->val.biggerE.right);
      fprintf(stdout,"cmp %%r14, %%r13\n");
      fprintf(stdout,"jle .16\n");
      fprintf(stdout,"mov %%r13, 0\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"mov %%r13, 1");
      fprintf(stdout,"mov %%rbx, %%r13\n");
       break;

    case smalequalK:
      generate_EXP_V(e->val.smalequalE.left);
      generate_EXP_H(e->val.smalequalE.right);
      fprintf(stdout,"cmp %%r14, %%r13\n");
      fprintf(stdout,"jg .16\n");
      fprintf(stdout,"mov %%r13, 0\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"mov %%r13, 1\n");
      fprintf(stdout,"mov %%rbx, %%r13\n");
       break;

    case bigequalK:
      generate_EXP_V(e->val.bigequalE.left);
      generate_EXP_H(e->val.bigequalE.right);
      fprintf(stdout,"cmp %%r14, %%r13\n");
      fprintf(stdout,"jl .16\n");
      fprintf(stdout,"mov %%r13, 0\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"mov %%r13, 1\n");
      fprintf(stdout,"mov %%rbx, %%r13\n");
      break;

     case moduloK:
       generate_EXP_V(e->val.moduloE.left);
       generate_EXP_H(e->val.moduloE.right);
       fprintf(stdout,"cmp %%r13, %%r14\n");
       fprintf(stdout,"jl .22\n");
       fprintf(stdout,"sub %%r13, %%r14\n");
       fprintf(stdout,"jmp .-42\n");
       fprintf(stdout,"mov %%rbx, %%r13\n");
        /*mov to RX*/
       /*mov to RY*/
       /*mod RX RY to RZ*/
       break;

     case timesK:
        generate_EXP_V(e->val.timesE.left);
        generate_EXP_H(e->val.timesE.right);
        fprintf(stdout,"mov %%AX, %%r13\n");
        fprintf(stdout,"mul %%r14\n");
        fprintf(stdout,"mov %%r13, %%AX\n");
        fprintf(stdout,"mov %%rbx, %%r13\n");
         /*mov to RX*/
         /*mov to RY*/
         /*mul RX RY to RZ*/
         break;

     case divK:
       generate_EXP_V(e->val.divE.left);
       generate_EXP_H(e->val.divE.right);
       fprintf(stdout,"mov %%AX, %%r13\n");
       fprintf(stdout,"div %%r14\n");
       fprintf(stdout,"mov %%r13, %%AX\n");
       fprintf(stdout,"mov %%rbx, %%r13\n");
       /*mov to RX*/
       /*mov to RY*/
       /*div RX RY to RZ*/
       break;

     case plusK:
        generate_EXP_V(e->val.plusE.left);
        generate_EXP_H(e->val.plusE.right);
        fprintf(stdout,"add %%r13, %%r14\n");
        fprintf(stdout,"mov %%rbx, %%r13\n");
         /*mov exp to RX*/
       /*mov exp to RY*/
       /*add RX RY to RZ*/
        break;

     case minusK:
      generate_EXP_V(e->val.minusE.left);
      generate_EXP_H(e->val.minusE.right);
      fprintf(stdout,"sub %%r13, %%r14\n");
      fprintf(stdout,"mov %%rbx, %%r13\n");
       /*mov to RX*/
       /*mov to RY*/
       /*min RX RY to RZ*/
       break;

    case termK:
      aterm = generate_TERM(e->val.termE);
      //fprintf(stdout,"%i \n", aterm);
      fprintf(stdout,"mov %%r13,%i \n", aterm);
      fprintf(stdout,"mov %%rbx, %%r13\n");
      break;

    case orK:
      generate_EXP_V(e->val.orE.left);
      generate_EXP_H(e->val.orE.right);
      fprintf(stdout,"cmp %%r13, 0\n");
      fprintf(stdout,"je .28\n");
      fprintf(stdout,"cmp %%r14, 0\n");
      fprintf(stdout,"je .11\n");
      fprintf(stdout,"mov %%r13, 1\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"mov %%r13, 0\n");
      fprintf(stdout,"mov %%rbx, %%r13\n");
       /*mov to RX*/
       /*mov to RY*/
       //or RX RY -> RZ (or RX)
       break;

    default:
       fprintf(stdout,"in default case in EXP\n\n");
       break;
  }
}
void generate_EXP_H(EXP* e){
  char a[80];
  int aterm;
  TERM* term;
  switch (e->kind) {
    case equaltoK:
      generate_EXP_V(e->val.equaltoE.left);
      generate_EXP_H(e->val.equaltoE.right);
      fprintf(stdout,"cmp %%r13, %%r14\n");
      fprintf(stdout,"jeq .16\n");
      fprintf(stdout,"mov %%r14, 1\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"mov %%r14, 0\n");
      fprintf(stdout,"mov %%rbx, %%r14\n");
      break;

    case nequaltoK:
      generate_EXP_V(e->val.nequaltoE.left);
      generate_EXP_H(e->val.nequaltoE.right);
      fprintf(stdout,"cmp %%r13, %%r14\n");
      fprintf(stdout,"jne .16\n");
      fprintf(stdout,"mov %%r14, 1");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"mov %%r14, 0");
      fprintf(stdout,"mov %%rbx, %%r14\n");
      break;

    case andK:
      generate_EXP_V(e->val.andE.left);
      generate_EXP_H(e->val.andE.right);
      fprintf(stdout,"cmp %%r13, 0\n");
      fprintf(stdout,"jne .34\n");
      fprintf(stdout,"cmp %%r14, 0\n");
      fprintf(stdout,"jne .16\n");
      fprintf(stdout,"mov %%r14, 0\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"mov %%r14, 1\n");
      fprintf(stdout,"mov %%rbx, %%r14\n");
    /*mov to RX*/
    /*mov to RY*/
    /*add RX RY to RZ (if true 0+0 = 0)*/
      break;

    case smallerK:
      generate_EXP_V(e->val.smallerE.left);
      generate_EXP_H(e->val.smallerE.right);
      fprintf(stdout,"cmp %%r14, %%r13\n");
      fprintf(stdout,"jge .16\n");
      fprintf(stdout,"mov %%r14, 0\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"mov %%r14, 1\n");
      fprintf(stdout,"mov %%rbx, %%r14\n");
      break;

    case biggerK:
      generate_EXP_V(e->val.biggerE.left);
      generate_EXP_H(e->val.biggerE.right);
      fprintf(stdout,"cmp %%r14, %%r13\n");
      fprintf(stdout,"jle .16\n");
      fprintf(stdout,"mov %%r14, 0\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"mov %%r14, 1\n");
      fprintf(stdout,"mov %%rbx, %%r14\n");
      break;

    case smalequalK:
      generate_EXP_V(e->val.smalequalE.left);
      generate_EXP_H(e->val.smalequalE.right);
      fprintf(stdout,"cmp %%r14, %%r13\n");
      fprintf(stdout,"jg .16\n");
      fprintf(stdout,"mov %%r14, 0\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"mov %%r14, 1\n");
      fprintf(stdout,"mov %%rbx, %%r14\n");
      break;

    case bigequalK:
      generate_EXP_V(e->val.bigequalE.left);
      generate_EXP_H(e->val.bigequalE.right);
      fprintf(stdout,"cmp %%r14, %%r13\n");
      fprintf(stdout,"jl .16\n");
      fprintf(stdout,"mov %%r14, 0\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"mov %%r14, 1\n");
      fprintf(stdout,"mov %%rbx, %%r14\n");
      break;

     case moduloK:
       generate_EXP_V(e->val.moduloE.left);
       generate_EXP_H(e->val.moduloE.right);
       fprintf(stdout,"cmp %%r13, %%r14\n");
       fprintf(stdout,"jl .22\n");
       fprintf(stdout,"sub %%r13, %%r14\n");
       fprintf(stdout,"jmp .-42\n");
       fprintf(stdout,"mov %%r14, %%r13\n");
       fprintf(stdout,"mov %%rbx, %%r14\n");
         /*mov to RX*/
         /*mov to RY*/
         /*mod RX RY to RZ*/
         break;

     case timesK:
      generate_EXP_V(e->val.timesE.left);
      generate_EXP_H(e->val.timesE.right);
      fprintf(stdout,"mov %%AX, %%r14");
      fprintf(stdout,"mul %%r13");
      fprintf(stdout,"mov %%r14, %%AX");
      fprintf(stdout,"mov %%rbx, %%r14\n");
       /*mov to RX*/
       /*mov to RY*/
       /*mul RX RY to RZ*/
       break;

    case divK:
      generate_EXP_V(e->val.divE.left);
      generate_EXP_H(e->val.divE.right);
      fprintf(stdout,"mov %%AX, %%r13\n");
      fprintf(stdout,"div %%r14\n");
      fprintf(stdout,"mov %%r14, %%AX\n");
      fprintf(stdout,"mov %%rbx, %%r14\n");
       /*mov to RX*/
       break;
       /*mov to RY*/
       /*div RX RY to RZ*/

   case plusK:
      generate_EXP_V(e->val.plusE.left);
      generate_EXP_H(e->val.plusE.right);
      fprintf(stdout,"add %%r14, %%r13\n");
      fprintf(stdout,"mov %%rbx, %%r14\n");
      /*mov exp to RX*/
      /*mov exp to RY*/
      /*add RX RY to RZ*/
      break;

   case minusK:
     generate_EXP_V(e->val.minusE.left);
     generate_EXP_H(e->val.minusE.right);
     fprintf(stdout,"sub %%r13, %%r14\n");
     fprintf(stdout,"mov %%r14, %%r13\n");
     fprintf(stdout,"mov %%rbx, %%r14\n");
     /*mov to RY*/
     /*mov to RX*/
     /*min RX RY to RZ*/
     break;
    case termK:
      aterm = generate_TERM(e->val.termE);
      fprintf(stdout,"mov %%r14,%d\n", aterm);
      fprintf(stdout,"mov %%rbx, %%r14\n");
      break;

    case orK:
      generate_EXP_V(e->val.orE.left);
      generate_EXP_H(e->val.orE.right);
      fprintf(stdout,"cmp %%r13, 0\n");
      fprintf(stdout,"je .28\n");
      fprintf(stdout,"cmp %%r14, 0\n");
      fprintf(stdout,"je .11\n");
      fprintf(stdout,"mov %%r14, 1\n");
      fprintf(stdout,"jmp .11\n");
      fprintf(stdout,"mov %%r14, 0\n");
      fprintf(stdout,"mov %%rbx, %%r14\n");
     /*mov to RX*/
     /*mov to RY*/
     //or RX RY -> RZ (or RX)
     break;

  default:
  fprintf( stderr, "default case reached");

     break;
  }
}

void generate_epilogue(){

  fprintf(stdout,"pop %%rbx\n");
  fprintf(stdout,"pop %%r14\n");
  fprintf(stdout,"pop %%r13\n");
  fprintf(stdout,"pop %%r12\n");
  fprintf(stdout,"pop %%rbx\n");
  fprintf(stdout,"movq %%rbp, %%rsp\n");
  fprintf(stdout,"pop %%rbp\n");
  fprintf(stdout,"mov1 %%0, %%rax ret\n");
}
