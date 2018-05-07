#include"tree.h"
void generate_prologue(FILE fp){
  fputs("
    form:
    .string \"%d\n\"
    push %rbp
    movq %rsp, rbp
    push %rbx
    push %r12
    push %r13
    push %r14
    push %r15", fp)
}
void generate_FUNC(FILE fp,FUNC root);{

}


void generate_EXP_V(STM statement, FILE fp){
switch (e->kind) {
  case equaltoK:

    generate_EXP_V(file,e->val.equaltoE.left);

    fputs("
      cmp %r13, %r14
      jeq .16
      mov %r13, 1
      jmp .11
      mov %r13, 0
  "}

    generate_EXP_H(file,e->val.equaltoE.right);
    break;

  case nequaltoK:
    generate_EXP_V(file,e->val.nequaltoE.left);
    fputs("
      cmp %r13, %r14
      jne .16
      mov %r13, 1
      jmp .11
      mov %r13, 0
  ",fp);
    generate_EXP_H(file,e->val.nequaltoE.right);
    break;

  case andK:
    generate_EXP_V(file,e->val.andE.left);
        fputs("
    cmp %r13, 0
    jne .34
    cmp %r14, 0
    jne .16
    mov %r13, 0
    jmp .11
    mov %r13, 1
    ",fp)
    generate_EXP_H(file,e->val.andE.right);
    /*mov to RX*/
    /*mov to RY*/
    /*add RX RY to RZ (if true 0+0 = 0)*/
    break;

  case smallerK:
  generate_EXP_V(file,e->val.andE.left);
  fputs("
  cmp %r14, %r13
  jge .16
  mov %r13, 0
  jmp .11
  mov %r13, 1
  ",fp);
  generate_EXP_H(file,e->val.andE.right);
    break;

  case biggerK:
  generate_EXP_V(file,e->val.andE.left);
  fputs("
  cmp %r14, %r13
  jle .16
  mov %r13, 0
  jmp .11
  mov %r13, 1
  ",fp)
  generate_EXP_H(file,e->val.andE.right);
     break;

  case smalequalK:
  generate_EXP_V(file,e->val.andE.left);
  fputs("
  cmp %r14, %r13
  jg .16
  mov %r13, 0
  jmp .11
  mov %r13, 1
  ",fp)
  generate_EXP_H(file,e->val.andE.right);
     break;

  case bigequalK:
  generate_EXP_V(file,e->val.andE.left);
  fputs("
  cmp %r14, %r13
  jl .16
  mov %r13, 0
  jmp .11
  mov %r13, 1
  ",fp)
  generate_EXP_H(file,e->val.andE.right);
     break;

   case moduloK:
   generate_EXP_V(file,e->val.andE.left);
   fputs("
    cmp %r13, %r14
    jl .22
    sub %r13, %r14
    jmp .-42
   ",fp)
   generate_EXP_H(file,e->val.andE.right);
     /*mov to RX*/
     /*mov to RY*/
     /*mod RX RY to RZ*/
     break;

   case timesK:
   generate_EXP_V(file,e->val.andE.left);
    fputs("
      mov %AX, %r13
      mul %r14
      mov %r13, %ax
         ",fp)
   generate_EXP_H(file,e->val.andE.right);
     /*mov to RX*/
     /*mov to RY*/
     /*mul RX RY to RZ*/
     break;

   case divK:
   generate_EXP_V(file,e->val.andE.left);
   fputs("
     mov %AX, %r13
     div %r14
     mov %r13, %ax
        ",fp)
   generate_EXP_H(file,e->val.andE.right);
     /*mov to RX*/
     /*mov to RY*/
     /*div RX RY to RZ*/
     break;

   case plusK:
   generate_EXP_V(file,e->val.andE.left);
   fputs("
      add %r13, %r14
        ",fp)
   generate_EXP_H(file,e->val.andE.right);
     /*mov exp to RX*/
     /*mov exp to RY*/
     /*add RX RY to RZ*/
     break;

   case minusK:
   generate_EXP_V(file,e->val.andE.left);
   fputs("
      sub %r13, %r14
        ",fp)
   generate_EXP_H(file,e->val.andE.right);
     /*mov to RX*/
     /*mov to RY*/
     /*min RX RY to RZ*/
     break;

  case termK:
    char[80] a;
    TERM* term = e->val.termE;
    if (term->kind == numK){
        int aterm = term->val.numT;
    }
        if (term->kind == boolK){
          int aterm = term->val.boolT;
        }


       sprintf(a, "mov %r13,%d", aterm);

  fputs(a ,fp)
     break;

  case orK:
  generate_EXP_V(file,e->val.andE.left);
  fputs("
    cmp %r13, 0
    je .28
    cmp %r14, 0
    je .11
    mov %r13, 1
    jmp .11
    mov %r13, 0
",fp)
  generate_EXP_H(file,e->val.andE.right);
     /*mov to RX*/
     /*mov to RY*/
     //or RX RY -> RZ (or RX)
     break;

  default:
     printf("in default case in EXP\n");
     break;
}
}
void generate_EXP_R(STM statement, FILE fp){
switch (e->kind) {
  case equaltoK:

    generate_EXP_V(file,e->val.equaltoE.left);

    fputs("
      cmp %r13, %r14
      jeq .16
      mov %r14, 1
      jmp .11
      mov %r14, 0
  "}

    generate_EXP_R(file,e->val.equaltoE.right);
    break;

  case nequaltoK:
    generate_EXP_V(file,e->val.nequaltoE.left);
    fputs("
      cmp %r13, %r14
      jne .16
      mov %r14, 1
      jmp .11
      mov %r14, 0
  ",fp)
    generate_EXP_R(file,e->val.nequaltoE.right);
    break;

  case andK:
    generate_EXP_V(file,e->val.andE.left);
        fputs("
    cmp %r13, 0
    jne .34
    cmp %r14, 0
    jne .16
    mov %r14, 0
    jmp .11
    mov %r14, 1
    ",fp)
    generate_EXP_H(file,e->val.andE.right);
    /*mov to RX*/
    /*mov to RY*/
    /*add RX RY to RZ (if true 0+0 = 0)*/
    break;

  case smallerK:
  generate_EXP_V(file,e->val.andE.left);
  fputs("
  cmp %r14, %r13
  jge .16
  mov %r14, 0
  jmp .11
  mov %r14, 1
  ",fp)
  generate_EXP_H(file,e->val.andE.right);
    break;

  case biggerK:
  generate_EXP_V(file,e->val.andE.left);
  fputs("
  cmp %r14, %r13
  jle .16
  mov %r14, 0
  jmp .11
  mov %r14, 1
  ",fp)
  generate_EXP_H(file,e->val.andE.right);
     break;

  case smalequalK:
  generate_EXP_V(file,e->val.andE.left);
  fputs("
  cmp %r14, %r13
  jg .16
  mov %r14, 0
  jmp .11
  mov %r14, 1
  ",fp)
  generate_EXP_H(file,e->val.andE.right);
     break;

  case bigequalK:
  generate_EXP_V(file,e->val.andE.left);
  fputs("
  cmp %r14, %r13
  jl .16
  mov %r14, 0
  jmp .11
  mov %r14, 1
  ",fp)
  generate_EXP_H(file,e->val.andE.right);
     break;

   case moduloK:
   generate_EXP_V(file,e->val.andE.left);
   fputs("
    cmp %r13, %r14
    jl .22
    sub %r13, %r14
    jmp .-42
    mov %r14, %r13
   ",fp)
   generate_EXP_H(file,e->val.andE.right);
     /*mov to RX*/
     /*mov to RY*/
     /*mod RX RY to RZ*/
     break;

   case timesK:
   generate_EXP_V(file,e->val.andE.left);
    fputs("
      mov %AX, %r14
      mul %r13
      mov %r14, %ax
         ",fp)
   generate_EXP_H(file,e->val.andE.right);
     /*mov to RX*/
     /*mov to RY*/
     /*mul RX RY to RZ*/
     break;

   case divK:
   generate_EXP_V(file,e->val.andE.left);
   fputs("
     mov %AX, %r13
     div %r14
     mov %r14, %ax
        ",fp)
   generate_EXP_H(file,e->val.andE.right);
     /*mov to RX*/
     /*mov to RY*/
     /*div RX RY to RZ*/
     break;

   case plusK:
   generate_EXP_V(file,e->val.andE.left);
   fputs("
      add %r14, %r13
        ",fp)
   generate_EXP_H(file,e->val.andE.right);
     /*mov exp to RX*/
     /*mov exp to RY*/
     /*add RX RY to RZ*/
     break;

   case minusK:
   generate_EXP_V(file,e->val.andE.left);
   fputs("
      sub %r13, %r14
      mov %r14, %r13
        ",fp)
   generate_EXP_H(file,e->val.andE.right);
     /*mov to RX*/
     /*mov to RY*/
     /*min RX RY to RZ*/
     break;

  case termK:
    char[80] a;
    TERM* term = e->val.termE;
    if (term->kind == numK){
        int aterm = term->val.numT;
    }
        if (term->kind == boolK){
          int aterm = term->val.boolT;
        }


       sprintf(a, "mov %r14,%d", aterm);

  fputs(a ,fp)
     break;

  case orK:
  generate_EXP_V(file,e->val.andE.left);
  fputs("
    cmp %r13, 0
    je .28
    cmp %r14, 0
    je .11
    mov %r14, 1
    jmp .11
    mov %r14, 0
",fp)
  generate_EXP_H(file,e->val.andE.right);
     /*mov to RX*/
     /*mov to RY*/
     //or RX RY -> RZ (or RX)
     break;

  default:
     printf("in default case in EXP\n");
     break;
}
}


    root.val.bodyF.statement_list.val.statelistL.statement.kind){
    strcat(a, root.val.equaltoE.left.)
    }


  fputs(s)
}
void generate_epilogue(FILE fp);{
  fputs("pop %r15
    pop %r14
    pop %r13
    pop %r12
    pop %rbx
    movq %rbp, %rsp
    pop %rbp
    mov1 %0, %rax
    ret
    ",fp)
}
void
