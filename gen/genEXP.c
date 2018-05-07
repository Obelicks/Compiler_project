#include <stdio.h>
#include "../headers/gen.h"
#include"../headers/tree.h"
void generate_prologue(FILE* fp){
  fputs("form: \n.string \"%d\n\" \npush %rbp movq %rsp, rbp push %rbx push %r12 push %r13 push %r14 push %r15", fp);
}
/*void generate_FUNC(FILE* fp,FUNC root);{

}*/


void generate_EXP_V(FILE* fp,EXP* e){
  char a[80];
  int aterm;
  TERM* term;
  switch (e->kind) {
    case equaltoK:
      generate_EXP_V(fp,e->val.equaltoE.left);
      fputs("cmp %r13, %r14 jeq .16 mov %r13, 1 jmp .11 mov %r13, 0",fp);
      generate_EXP_H(fp,e->val.equaltoE.right);
      break;

    case nequaltoK:
      generate_EXP_V(fp,e->val.nequaltoE.left);
      fputs("cmp %r13, %r14 jne .16 mov %r13, 1 jmp .11 mov %r13, 0",fp);
      generate_EXP_H(fp,e->val.nequaltoE.right);
      break;

    case andK:
      generate_EXP_V(fp,e->val.andE.left);
      fputs("cmp %r13, 0 jne .34 cmp %r14, 0 jne .16 mov %r13, 0 jmp .11 mov %r13, 1",fp);
      generate_EXP_H(fp,e->val.andE.right);
      /*mov to RX*/
      /*mov to RY*/
      /*add RX RY to RZ (if true 0+0 = 0)*/
      break;

    case smallerK:
      generate_EXP_V(fp,e->val.andE.left);
      fputs("cmp %r14, %r13 jge .16 mov %r13, 0 jmp .11 mov %r13, 1",fp);
      generate_EXP_H(fp,e->val.andE.right);
      break;

    case biggerK:
      generate_EXP_V(fp,e->val.andE.left);
      fputs("cmp %r14, %r13 jle .16 mov %r13, 0 jmp .11 mov %r13, 1",fp);
      generate_EXP_H(fp,e->val.andE.right);
       break;

    case smalequalK:
      generate_EXP_V(fp,e->val.andE.left);
      fputs("cmp %r14, %r13 jg .16 mov %r13, 0 jmp .11 mov %r13, 1",fp);
      generate_EXP_H(fp,e->val.andE.right);
       break;

    case bigequalK:
      generate_EXP_V(fp,e->val.andE.left);
      fputs("cmp %r14, %r13 jl .16 mov %r13, 0 jmp .11 mov %r13, 1",fp);
      generate_EXP_H(fp,e->val.andE.right);
      break;

     case moduloK:
       generate_EXP_V(fp,e->val.andE.left);
       fputs("cmp %r13, %r14 jl .22 sub %r13, %r14 jmp .-42",fp);
       generate_EXP_H(fp,e->val.andE.right);
        /*mov to RX*/
       /*mov to RY*/
       /*mod RX RY to RZ*/
       break;

     case timesK:
        generate_EXP_V(fp,e->val.andE.left);
        fputs("mov %AX, %r13 mul %r14 mov %r13, %AX",fp);
        generate_EXP_H(fp,e->val.andE.right);
         /*mov to RX*/
         /*mov to RY*/
         /*mul RX RY to RZ*/
         break;

     case divK:
       generate_EXP_V(fp,e->val.andE.left);
       fputs("mov %AX, %r13 div %r14 mov %r13, %AX",fp);
       generate_EXP_H(fp,e->val.andE.right);
       /*mov to RX*/
       /*mov to RY*/
       /*div RX RY to RZ*/
       break;

     case plusK:
        generate_EXP_V(fp,e->val.andE.left);
        fputs("add %r13, %r14",fp);
        generate_EXP_H(fp,e->val.andE.right);
         /*mov exp to RX*/
       /*mov exp to RY*/
       /*add RX RY to RZ*/
        break;

     case minusK:
       generate_EXP_V(fp,e->val.andE.left);
       fputs("sub %r13, %r14",fp);
       generate_EXP_H(fp,e->val.andE.right);
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
      sprintf(a, "mov %%r13,%d", aterm);
      fputs(a ,fp);
      break;

    case orK:
      generate_EXP_V(fp,e->val.andE.left);
      fputs("cmp %r13, 0 je .28 cmp %r14, 0 je .11 mov %r13, 1 jmp .11 mov %r13, 0",fp);
      generate_EXP_H(fp,e->val.andE.right);
       /*mov to RX*/
       /*mov to RY*/
       //or RX RY -> RZ (or RX)
       break;

    default:
       printf("in default case in EXP\n");
       break;
  }
}
void generate_EXP_H(FILE* fp,EXP* e){
  char a[80];
  int aterm;
  TERM* term;
  switch (e->kind) {
    case equaltoK:
      generate_EXP_V(fp,e->val.equaltoE.left);
      fputs("cmp %r13, %r14 jeq .16 mov %r14, 1 jmp .11 mov %r14, 0",fp);
      generate_EXP_H(fp,e->val.equaltoE.right);
      break;

    case nequaltoK:
      generate_EXP_V(fp,e->val.nequaltoE.left);
      fputs("cmp %r13, %r14 jne .16 mov %r14, 1 jmp .11 mov %r14, 0",fp);
      generate_EXP_H(fp,e->val.nequaltoE.right);
      break;

    case andK:
      generate_EXP_V(fp,e->val.andE.left);
      fputs("cmp %r13, 0 jne .34 cmp %r14, 0 jne .16 mov %r14, 0 jmp .11 mov %r14, 1",fp);
      generate_EXP_H(fp,e->val.andE.right);
    /*mov to RX*/
    /*mov to RY*/
    /*add RX RY to RZ (if true 0+0 = 0)*/
      break;

    case smallerK:
      generate_EXP_V(fp,e->val.andE.left);
      fputs("cmp %r14, %r13 jge .16 mov %r14, 0 jmp .11 mov %r14, 1",fp);
      generate_EXP_H(fp,e->val.andE.right);
      break;

    case biggerK:
      generate_EXP_V(fp,e->val.andE.left);
      fputs("cmp %r14, %r13 jle .16 mov %r14, 0 jmp .11 mov %r14, 1",fp);
      generate_EXP_H(fp,e->val.andE.right);
      break;

    case smalequalK:
      generate_EXP_V(fp,e->val.andE.left);
      fputs("cmp %r14, %r13 jg .16 mov %r14, 0 jmp .11 mov %r14, 1",fp);
      generate_EXP_H(fp,e->val.andE.right);
      break;

    case bigequalK:
      generate_EXP_V(fp,e->val.andE.left);
      fputs("cmp %r14, %r13 jl .16 mov %r14, 0 jmp .11 mov %r14, 1",fp);
      generate_EXP_H(fp,e->val.andE.right);
      break;

     case moduloK:
       generate_EXP_V(fp,e->val.andE.left);
       fputs("cmp %r13, %r14 jl .22 sub %r13, %r14 jmp .-42 mov %r14, %r13",fp);
       generate_EXP_H(fp,e->val.andE.right);
         /*mov to RX*/
         /*mov to RY*/
         /*mod RX RY to RZ*/
         break;

     case timesK:
      generate_EXP_V(fp,e->val.andE.left);
      fputs("mov %AX, %r14 mul %r13 mov %r14, %AX",fp);
      generate_EXP_H(fp,e->val.andE.right);
       /*mov to RX*/
       /*mov to RY*/
       /*mul RX RY to RZ*/
       break;

    case divK:
      generate_EXP_V(fp,e->val.andE.left);
      fputs(" mov %AX, %r13 div %r14 mov %r14, %AX",fp);
      generate_EXP_H(fp,e->val.andE.right);
       /*mov to RX*/
       break;
       /*mov to RY*/
       /*div RX RY to RZ*/

   case plusK:
      generate_EXP_V(fp,e->val.andE.left);
      fputs("add %r14, %r13",fp);
      generate_EXP_H(fp,e->val.andE.right);
      /*mov exp to RX*/
      /*mov exp to RY*/
      /*add RX RY to RZ*/
      break;

   case minusK:
     generate_EXP_V(fp,e->val.andE.left);
     fputs("sub %r13, %r14 mov %r14, %r13",fp);
     generate_EXP_H(fp,e->val.andE.right);
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
      sprintf(a, "mov %%r14,%d", aterm);
      fputs(a ,fp);
      break;

    case orK:
      generate_EXP_V(fp,e->val.andE.left);
      fputs("cmp %r13, 0 je .28 cmp %r14, 0 je .11 mov %r14, 1 jmp .11 mov %r14, 0",fp);
      generate_EXP_H(fp,e->val.andE.right);
     /*mov to RX*/
     /*mov to RY*/
     //or RX RY -> RZ (or RX)
     break;

  default:
     printf("in default case in EXP\n");
     break;
  }
}

void generate_epilogue(FILE* fp){
  fputs("pop %r15 pop %r14 pop %r13 pop %r12 pop %rbx movq %rbp, %rsppop %rbp mov1 %0, %rax ret",fp);
}
