#include <stdio.h>
#include "../headers/gen.h"
#include"../headers/tree.h"
void generate_prologue(){
  printf("form: \n");
  printf(".string \"%%d\n");
  printf("push %%rbp\n");
  printf("movq %%rsp, rbp\n");
  printf("push %%rbx\n");
  printf("push %%r12 push %%r13\n");
  printf("push %%r14 push %%r15\n");
}
/*void generate_FUNC(FUNC root);{

}*/


void generate_EXP_V(EXP* e){
  char a[80];
  int aterm;
  TERM* term;
  switch (e->kind) {
    case equaltoK:
      generate_EXP_V(e->val.equaltoE.left);
      printf("cmp %%r13, %%r14\n");
      printf("jeq .16\n");
      printf("mov %%r13, 1\n");
      printf("jmp .11\n");
      printf("mov %%r13, 0\n");
      printf("mov %%r15, %%r13\n");
      generate_EXP_H(e->val.equaltoE.right);
      break;

    case nequaltoK:
      generate_EXP_V(e->val.nequaltoE.left);
      printf("cmp %%r13, %%r14\n");
      printf("jne .16\n");
      printf("mov %%r13, 1\n");
      printf("jmp .11\n");
      printf("mov %%r13, 0\n");
      printf("mov %%r15, %%r13\n");
      generate_EXP_H(e->val.nequaltoE.right);
      break;

    case andK:
      generate_EXP_V(e->val.andE.left);
      printf("cmp %%r13, 0\n");
      printf("jne .34\n");
      printf("cmp %%r14, 0\n");
      printf("jne .16\n");
      printf("mov %%r13, 0\n");
      printf("jmp .11\n");
      printf("mov %%r13, 1\n");
      printf("mov %%r15, %%r13\n");
      generate_EXP_H(e->val.andE.right);
      /*mov to RX*/
      /*mov to RY*/
      /*add RX RY to RZ (if true 0+0 = 0)*/
      break;

    case smallerK:
      generate_EXP_V(e->val.andE.left);
      printf("cmp %%r14, %%r13\n");
      printf("jge .16\n");
      printf("mov %%r13, 0\n");
      printf("jmp .11\n");
      printf("mov %%r13, 1\n");
      printf("mov %%r15, %%r13\n");
      generate_EXP_H(e->val.andE.right);
      break;

    case biggerK:
      generate_EXP_V(e->val.andE.left);
      printf("cmp %%r14, %%r13\n");
      printf("jle .16\n");
      printf("mov %%r13, 0\n");
      printf("jmp .11\n");
      printf("mov %%r13, 1");
      printf("mov %%r15, %%r13\n");
      generate_EXP_H(e->val.andE.right);
       break;

    case smalequalK:
      generate_EXP_V(e->val.andE.left);
      printf("cmp %%r14, %%r13\n");
      printf("jg .16\n");
      printf("mov %%r13, 0\n");
      printf("jmp .11\n");
      printf("mov %%r13, 1\n");
      printf("mov %%r15, %%r13\n");
      generate_EXP_H(e->val.andE.right);
       break;

    case bigequalK:
      generate_EXP_V(e->val.andE.left);
      printf("cmp %%r14, %%r13\n");
      printf("jl .16\n");
      printf("mov %%r13, 0\n");
      printf("jmp .11\n");
      printf("mov %%r13, 1\n");
      printf("mov %%r15, %%r13\n");
      generate_EXP_H(e->val.andE.right);
      break;

     case moduloK:
       generate_EXP_V(e->val.andE.left);
       printf("cmp %%r13, %%r14\n");
       printf("jl .22\n");
       printf("sub %%r13, %%r14\n");
       printf("jmp .-42\n");
       printf("mov %%r15, %%r13\n");
       generate_EXP_H(e->val.andE.right);
        /*mov to RX*/
       /*mov to RY*/
       /*mod RX RY to RZ*/
       break;

     case timesK:
        generate_EXP_V(e->val.andE.left);
        printf("mov %%AX, %%r13\n");
        printf("mul %%r14\n");
        printf("mov %%r13, %%AX\n");
        printf("mov %%r15, %%r13\n");
        generate_EXP_H(e->val.andE.right);
         /*mov to RX*/
         /*mov to RY*/
         /*mul RX RY to RZ*/
         break;

     case divK:
       generate_EXP_V(e->val.andE.left);
       printf("mov %%AX, %%r13\n");
       printf("div %%r14\n");
       printf("mov %%r13, %%AX\n");
       printf("mov %%r15, %%r13\n");
       generate_EXP_H(e->val.andE.right);
       /*mov to RX*/
       /*mov to RY*/
       /*div RX RY to RZ*/
       break;

     case plusK:
        generate_EXP_V(e->val.andE.left);
        printf("add %%r13, %%r14\n");
        printf("mov %%r15, %%r13\n");
        generate_EXP_H(e->val.andE.right);
         /*mov exp to RX*/
       /*mov exp to RY*/
       /*add RX RY to RZ*/
        break;

     case minusK:
       generate_EXP_V(e->val.andE.left);
       printf("sub %%r13, %%r14\n");
       printf("mov %%r15, %%r13\n");
       generate_EXP_H(e->val.andE.right);
       /*mov to RX*/
       /*mov to RY*/
       /*min RX RY to RZ*/
       break;

    case termK:
      term = e->val.termE;
      if (term->kind == numK){
        aterm = term->val.numT;
      }
      if (term->kind == boolK){
        aterm = term->val.booleanT;
      }
      printf("mov %%r13,%d", aterm);
      printf("mov %%r15, %%r13\n");
      break;

    case orK:
      generate_EXP_V(e->val.andE.left);
      printf("cmp %%r13, 0\n");
      printf("je .28\n");
      printf("cmp %%r14, 0\n");
      printf("je .11\n");
      printf("mov %%r13, 1\n");
      printf("jmp .11\n");
      printf("mov %%r13, 0\n");
      printf("mov %%r15, %%r13\n");
      generate_EXP_H(e->val.andE.right);
       /*mov to RX*/
       /*mov to RY*/
       //or RX RY -> RZ (or RX)
       break;

    default:
       printf("in default case in EXP\n\n");
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
      printf("cmp %%r13, %%r14\n");
      printf("jeq .16\n");
      printf("mov %%r14, 1\n");
      printf("jmp .11\n");
      printf("mov %%r14, 0\n");
      printf("mov %%r15, %%r14\n");
      generate_EXP_H(e->val.equaltoE.right);
      break;

    case nequaltoK:
      generate_EXP_V(e->val.nequaltoE.left);
      printf("cmp %%r13, %%r14\n");
      printf("jne .16\n");
      printf("mov %%r14, 1");
      printf("jmp .11\n");
      printf("mov %%r14, 0");
      printf("mov %%r15, %%r14\n");
      generate_EXP_H(e->val.nequaltoE.right);
      break;

    case andK:
      generate_EXP_V(e->val.andE.left);
      printf("cmp %%r13, 0\n");
      printf("jne .34\n");
      printf("cmp %%r14, 0\n");
      printf("jne .16\n");
      printf("mov %%r14, 0\n");
      printf("jmp .11\n");
      printf("mov %%r14, 1\n");
      printf("mov %%r15, %%r14\n");
      generate_EXP_H(e->val.andE.right);
    /*mov to RX*/
    /*mov to RY*/
    /*add RX RY to RZ (if true 0+0 = 0)*/
      break;

    case smallerK:
      generate_EXP_V(e->val.andE.left);
      printf("cmp %%r14, %%r13\n");
      printf("jge .16\n");
      printf("mov %%r14, 0\n");
      printf("jmp .11\n");
      printf("mov %%r14, 1\n");
      printf("mov %%r15, %%r14\n");
      generate_EXP_H(e->val.andE.right);
      break;

    case biggerK:
      generate_EXP_V(e->val.andE.left);
      printf("cmp %%r14, %%r13\n");
      printf("jle .16\n");
      printf("mov %%r14, 0\n");
      printf("jmp .11\n");
      printf("mov %%r14, 1\n");
      printf("mov %%r15, %%r14\n");
      generate_EXP_H(e->val.andE.right);
      break;

    case smalequalK:
      generate_EXP_V(e->val.andE.left);
      printf("cmp %%r14, %%r13\n");
      printf("jg .16\n");
      printf("mov %%r14, 0\n");
      printf("jmp .11\n");
      printf("mov %%r14, 1\n");
      printf("mov %%r15, %%r14\n");
      generate_EXP_H(e->val.andE.right);
      break;

    case bigequalK:
      generate_EXP_V(e->val.andE.left);
      printf("cmp %%r14, %%r13\n");
      printf("jl .16\n");
      printf("mov %%r14, 0\n");
      printf("jmp .11\n");
      printf("mov %%r14, 1\n");
      printf("mov %%r15, %%r14\n");
      generate_EXP_H(e->val.andE.right);
      break;

     case moduloK:
       generate_EXP_V(e->val.andE.left);
       printf("cmp %%r13, %%r14\n");
       printf("jl .22\n");
       printf("sub %%r13, %%r14\n");
       printf("jmp .-42\n");
       printf("mov %%r14, %%r13\n");
       printf("mov %%r15, %%r14\n");
       generate_EXP_H(e->val.andE.right);
         /*mov to RX*/
         /*mov to RY*/
         /*mod RX RY to RZ*/
         break;

     case timesK:
      generate_EXP_V(e->val.andE.left);
      printf("mov %%AX, %%r14");
      printf("mul %%r13");
      printf("mov %%r14, %%AX");
      printf("mov %%r15, %%r14\n");
      generate_EXP_H(e->val.andE.right);
       /*mov to RX*/
       /*mov to RY*/
       /*mul RX RY to RZ*/
       break;

    case divK:
      generate_EXP_V(e->val.andE.left);
      printf("mov %%AX, %%r13\n");
      printf("div %%r14\n");
      printf("mov %%r14, %%AX\n");
      printf("mov %%r15, %%r14\n");
      generate_EXP_H(e->val.andE.right);
       /*mov to RX*/
       break;
       /*mov to RY*/
       /*div RX RY to RZ*/

   case plusK:
      generate_EXP_V(e->val.andE.left);
      printf("add %%r14, %%r13\n");
      printf("mov %%r15, %%r14\n");
      generate_EXP_H(e->val.andE.right);
      /*mov exp to RX*/
      /*mov exp to RY*/
      /*add RX RY to RZ*/
      break;

   case minusK:
     generate_EXP_V(e->val.andE.left);
     printf("sub %%r13, %%r14\n");
     printf("mov %%r14, %%r13\n");
     printf("mov %%r15, %%r14\n");
     generate_EXP_H(e->val.andE.right);
     /*mov to RY*/
     /*mov to RX*/
     /*min RX RY to RZ*/
     break;
    case termK:
      term = e->val.termE;
      if (term->kind == numK){
          aterm = term->val.numT;
      }
      if (term->kind == boolK){
        aterm = term->val.booleanT;
      }
      printf("mov %%r14,%d\n", aterm);
      printf("mov %%r15, %%r14\n");
      break;

    case orK:
      generate_EXP_V(e->val.andE.left);
      printf("cmp %%r13, 0\n");
      printf("je .28\n");
      printf("cmp %%r14, 0\n");
      printf("je .11\n");
      printf("mov %%r14, 1\n");
      printf("jmp .11\n");
      printf("mov %%r14, 0\n");
      printf("mov %%r15, %%r14\n");
      generate_EXP_H(e->val.andE.right);
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

  printf("pop %%r15\n");
  printf("pop %%r14\n");
  printf("pop %%r13\n");
  printf("pop %%r12\n");
  printf("pop %%rbx\n");
  printf("movq %%rbp, %%rsp\n");
  printf("pop %%rbp\n");
  printf("mov1 %%0, %%rax ret\n");
}
