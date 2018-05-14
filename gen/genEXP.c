#include <stdio.h>
#include "../headers/gen.h"
#include"../headers/tree.h"
void generate_prologue(){
  printf("form: \n.string \"%d\n\" \n push %rbp \n movq %rsp, rbp \n push %rbx \n push %r12 \n push %r13 \n push %r14 \n push %r15\n");
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
      printf("cmp %r13, %r14 \n jeq .16 \n mov %r13, 1 \n jmp .11 \n mov %r13, 0\n");
      generate_EXP_H(e->val.equaltoE.right);
      break;

    case nequaltoK:
      generate_EXP_V(e->val.nequaltoE.left);
      printf("cmp %r13, %r14 \n jne .16 \n mov %r13, 1 \n jmp .11 \n mov %r13, 0\n");
      generate_EXP_H(e->val.nequaltoE.right);
      break;

    case andK:
      generate_EXP_V(e->val.andE.left);
      printf("cmp %r13, 0 \n jne .34 \n cmp %r14, 0 \n jne .16 \n mov %r13, 0 \n jmp .11 \n mov %r13, 1\n");
      generate_EXP_H(e->val.andE.right);
      /*mov to RX*/
      /*mov to RY*/
      /*add RX RY to RZ (if true 0+0 = 0)*/
      break;

    case smallerK:
      generate_EXP_V(e->val.andE.left);
      printf("cmp %r14, %r13 \n jge .16 \n mov %r13, 0 \n jmp .11 \n mov %r13, 1\n");
      generate_EXP_H(e->val.andE.right);
      break;

    case biggerK:
      generate_EXP_V(e->val.andE.left);
      printf("cmp %r14, %r13 \n jle .16 \n mov %r13, 0 \n jmp .11 \n mov %r13, 1\n");
      generate_EXP_H(e->val.andE.right);
       break;

    case smalequalK:
      generate_EXP_V(e->val.andE.left);
      printf("cmp %r14, %r13 \n jg .16 \n mov %r13, 0 \n jmp .11 \n mov %r13, 1\n");
      generate_EXP_H(e->val.andE.right);
       break;

    case bigequalK:
      generate_EXP_V(e->val.andE.left);
      printf("cmp %r14, %r13 \n jl .16 \n mov %r13, 0 \n jmp .11 \n mov %r13, 1\n");
      generate_EXP_H(e->val.andE.right);
      break;

     case moduloK:
       generate_EXP_V(e->val.andE.left);
       printf("cmp %r13, %r14 \n jl .22 \n sub %r13, %r14 \n jmp .-42");
       generate_EXP_H(e->val.andE.right);
        /*mov to RX*/
       /*mov to RY*/
       /*mod RX RY to RZ*/
       break;

     case timesK:
        generate_EXP_V(e->val.andE.left);
        printf("mov %AX, %r13 \n mul %r14 \n mov %r13, %AX\n");
        generate_EXP_H(e->val.andE.right);
         /*mov to RX*/
         /*mov to RY*/
         /*mul RX RY to RZ*/
         break;

     case divK:
       generate_EXP_V(e->val.andE.left);
       printf("mov %AX, %r13 \n div %r14 \n mov %r13, %AX\n");
       generate_EXP_H(e->val.andE.right);
       /*mov to RX*/
       /*mov to RY*/
       /*div RX RY to RZ*/
       break;

     case plusK:
        generate_EXP_V(e->val.andE.left);
        printf("add %r13, %r14\n");
        generate_EXP_H(e->val.andE.right);
         /*mov exp to RX*/
       /*mov exp to RY*/
       /*add RX RY to RZ*/
        break;

     case minusK:
       generate_EXP_V(e->val.andE.left);
       printf("sub %r13, %r14\n");
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
      sprintf(a, "mov %%r13,%d\n", aterm);
      printf(a);
      break;

    case orK:
      generate_EXP_V(e->val.andE.left);
      printf("cmp %r13, 0 je .28 \n cmp %r14, 0 je .11 \n mov %r13, 1 \n jmp .11 \n mov %r13, 0\n");
      generate_EXP_H(e->val.andE.right);
       /*mov to RX*/
       /*mov to RY*/
       //or RX RY -> RZ (or RX)
       break;

    default:
       printf("in default case in EXP\n");
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
      printf("cmp %r13, %r14 \n jeq .16 \n mov %r14, 1 \n jmp .11 \n mov %r14, 0\n");
      generate_EXP_H(e->val.equaltoE.right);
      break;

    case nequaltoK:
      generate_EXP_V(e->val.nequaltoE.left);
      printf("cmp %r13, %r14 \njne .16 \nmov %r14, 1 \njmp .11 \nmov %r14, 0\n");
      generate_EXP_H(e->val.nequaltoE.right);
      break;

    case andK:
      generate_EXP_V(e->val.andE.left);
      printf("cmp %r13, 0 \n jne .34 \n cmp %r14, 0 \n jne .16 \n mov %r14, 0 \n jmp .11 \n mov %r14, 1\n");
      generate_EXP_H(e->val.andE.right);
    /*mov to RX*/
    /*mov to RY*/
    /*add RX RY to RZ (if true 0+0 = 0)*/
      break;

    case smallerK:
      generate_EXP_V(e->val.andE.left);
      printf("cmp %r14, %r13 \n jge .16 \n mov %r14, 0 \n jmp .11 \n mov %r14, 1\n");
      generate_EXP_H(e->val.andE.right);
      break;

    case biggerK:
      generate_EXP_V(e->val.andE.left);
      printf("cmp %r14, %r13 \n jle .16 \n mov %r14, 0 \n jmp .11 \n mov %r14, 1\n");
      generate_EXP_H(e->val.andE.right);
      break;

    case smalequalK:
      generate_EXP_V(e->val.andE.left);
      printf("cmp %r14, %r13 \n jg .16 \n mov %r14, 0 \n jmp .11 \n mov %r14, 1\n");
      generate_EXP_H(e->val.andE.right);
      break;

    case bigequalK:
      generate_EXP_V(e->val.andE.left);
      printf("cmp %r14, %r13 \n jl .16 \n mov %r14, 0 \n jmp .11 \n mov %r14, 1\n");
      generate_EXP_H(e->val.andE.right);
      break;

     case moduloK:
       generate_EXP_V(e->val.andE.left);
       printf("cmp %r13, %r14 \n jl .22 \n sub %r13, %r14 \n jmp .-42 \n mov %r14, %r13\n");
       generate_EXP_H(e->val.andE.right);
         /*mov to RX*/
         /*mov to RY*/
         /*mod RX RY to RZ*/
         break;

     case timesK:
      generate_EXP_V(e->val.andE.left);
      printf("mov %AX, %r14 \n mul %r13 \n mov %r14, %AX\n");
      generate_EXP_H(e->val.andE.right);
       /*mov to RX*/
       /*mov to RY*/
       /*mul RX RY to RZ*/
       break;

    case divK:
      generate_EXP_V(e->val.andE.left);
      printf(" mov %AX, %r13 \n div %r14 \n mov %r14, %AX\n");
      generate_EXP_H(e->val.andE.right);
       /*mov to RX*/
       break;
       /*mov to RY*/
       /*div RX RY to RZ*/

   case plusK:
      generate_EXP_V(e->val.andE.left);
      printf("add %r14, %r13\n");
      generate_EXP_H(e->val.andE.right);
      /*mov exp to RX*/
      /*mov exp to RY*/
      /*add RX RY to RZ*/
      break;

   case minusK:
     generate_EXP_V(e->val.andE.left);
     printf("sub %r13, %r14 \n mov %r14, %r13\n");
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
      sprintf(a, "mov %%r14,%d \n", aterm);
      printf(a );
      break;

    case orK:
      generate_EXP_V(e->val.andE.left);
      printf("cmp %r13, 0 \n je .28 \n cmp %r14, 0 je .11 \n mov %r14, 1 \n jmp .11 \n mov %r14, 0\n");
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
  printf("pop %r15 \n pop %r14 \n pop %r13 \n pop %r12 \n pop %rbx \n movq %rbp, %rsp \n pop %rbp \n mov1 %0, %rax \n ret\n");
}
