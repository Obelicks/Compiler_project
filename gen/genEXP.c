#include <stdio.h>
#include "../headers/gen.h"
#include"../headers/tree.h"
extern long long int jumpnr;
void generate_EXP(EXP* e, int flag){
  fprintf(stderr, "generating generate_EXP\n" );
  int aterm;
  long long int r, r1;
  TERM* t;
  switch (e->kind) {
    case equaltoK:
    r = jumpnr;
    jumpnr++;
    r1 = jumpnr;
    jumpnr++;
    fprintf(stderr, "generating generate_EXP -> equaltoK\n" );
    generate_EXP(e->val.equaltoE.left, flag);
    generate_EXP(e->val.equaltoE.right, flag);
    fprintf(stdout,"pop %%r13\n");
    fprintf(stdout,"pop %%r14\n");
    fprintf(stdout,"cmp %%r14, %%r13\n");
    fprintf(stdout,"jne .%lli\n",r);
    fprintf(stdout,"movq $0, %%r13\n");
    fprintf(stdout,"jmp .%lli\n",r1);
    fprintf(stdout,".%lli:\n",r);
    fprintf(stdout,"movq $1, %%r13\n");
    fprintf(stdout,".%lli:\n",r1);
    fprintf(stdout,"push %%r13\n");
    break;

    case nequaltoK:
    r = jumpnr;
    jumpnr++;
    r1 = jumpnr;
    jumpnr++;
    fprintf(stderr, "generating generate_EXP -> equaltoK\n" );
    generate_EXP(e->val.nequaltoE.left, flag);
    generate_EXP(e->val.nequaltoE.right, flag);
    fprintf(stdout,"pop %%r13\n");
    fprintf(stdout,"pop %%r14\n");
    fprintf(stdout,"cmp %%r14, %%r13\n");
    fprintf(stdout,"jne .%lli\n",r);
    fprintf(stdout,"movq $1, %%r13\n");
    fprintf(stdout,"jmp .%lli\n",r1);
    fprintf(stdout,".%lli:\n",r);
    fprintf(stdout,"movq $0, %%r13\n");
    fprintf(stdout,".%lli:\n",r1);
    fprintf(stdout,"push %%r13\n");
    break;

      break;

    case andK:
      r = jumpnr;
      jumpnr++;
      r1 = jumpnr;
      jumpnr++;
      fprintf(stderr, "generating generate_EXP -> andK\n" );
      generate_EXP(e->val.andE.left, flag);
      generate_EXP(e->val.andE.right, flag);
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp $0, %%r13\n");
      fprintf(stdout,"jne .%lli\n",r);
      fprintf(stdout,"cmp $0, %%r14\n");
      fprintf(stdout,"jne .%lli\n",r);
      fprintf(stdout,"movq $0, %%r13\n");
      fprintf(stdout,"jmp .%lli\n",r1);
      fprintf(stdout,".%lli:\n",r);
      fprintf(stdout,"movq $1, %%r13\n");
      fprintf(stdout,".%lli:\n",r1);
      fprintf(stdout,"push %%r13\n");
      /*movq to RX*/
      /*movq to RY*/
      /*add RX RY to RZ (if true 0+0 = 0)*/
      break;

    case smallerK:
      r = jumpnr;
      jumpnr++;
      r1 = jumpnr;
      jumpnr++;
      fprintf(stderr, "generating generate_EXP -> smallerK\n" );
      generate_EXP(e->val.smallerE.left, flag);
      generate_EXP(e->val.smallerE.right, flag);
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp %%r13, %%r14\n");
      fprintf(stdout,"jl .%lli\n",r);
      fprintf(stdout,"movq $1, %%r13\n");
      fprintf(stdout,"jmp .%lli\n",r1);
      fprintf(stdout,".%lli:\n",r);
      fprintf(stdout,"movq $0, %%r13\n");
      fprintf(stdout,".%lli:\n",r1);
      fprintf(stdout,"push %%r13\n");
      break;

    case biggerK:
    r = jumpnr;
    jumpnr++;
    r1 = jumpnr;
    jumpnr++;
    fprintf(stderr, "generating generate_EXP -> smallerK\n" );
    generate_EXP(e->val.biggerE.left, flag);
    generate_EXP(e->val.biggerE.right, flag);
    fprintf(stdout,"pop %%r13\n");
    fprintf(stdout,"pop %%r14\n");
    fprintf(stdout,"cmp %%r13, %%r14\n");
    fprintf(stdout,"jg .%lli\n",r);
    fprintf(stdout,"movq $1, %%r13\n");
    fprintf(stdout,"jmp .%lli\n",r1);
    fprintf(stdout,".%lli:\n",r);
    fprintf(stdout,"movq $0, %%r13\n");
    fprintf(stdout,".%lli:\n",r1);
    fprintf(stdout,"push %%r13\n");
      break;

    case smalequalK:
    r = jumpnr;
    jumpnr++;
    r1 = jumpnr;
    jumpnr++;
    fprintf(stderr, "generating generate_EXP -> smallerK\n" );
    generate_EXP(e->val.smalequalE.left, flag);
    generate_EXP(e->val.smalequalE.right, flag);
    fprintf(stdout,"pop %%r13\n");
    fprintf(stdout,"pop %%r14\n");
    fprintf(stdout,"cmp %%r13, %%r14\n");
    fprintf(stdout,"jle .%lli\n",r);
    fprintf(stdout,"movq $1, %%r13\n");
    fprintf(stdout,"jmp .%lli\n",r1);
    fprintf(stdout,".%lli:\n",r);
    fprintf(stdout,"movq $0, %%r13\n");
    fprintf(stdout,".%lli:\n",r1);
    fprintf(stdout,"push %%r13\n");
    break;

    case bigequalK:
    r = jumpnr;
    jumpnr++;
    r1 = jumpnr;
    jumpnr++;
      fprintf(stderr, "generating generate_EXP -> bigequalK\n" );
      generate_EXP(e->val.bigequalE.left, flag);
      generate_EXP(e->val.bigequalE.right, flag);
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp %%r13, %%r14\n");
      fprintf(stdout,"jge .%lli\n",r);
      fprintf(stdout,"movq $1, %%r13\n");
      fprintf(stdout,"jmp .%lli\n",r1);
      fprintf(stdout,".%lli:\n",r);
      fprintf(stdout,"movq $0, %%r13\n");
      fprintf(stdout,".%lli:\n",r1);
      fprintf(stdout,"push %%r13\n");
        break;


    case moduloK:
    r = jumpnr;
    jumpnr++;
    r1 = jumpnr;
    jumpnr++;
      fprintf(stderr, "generating generate_EXP -> moduloK\n" );
      generate_EXP(e->val.moduloE.left, flag);
      generate_EXP(e->val.moduloE.right, flag);
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,".%lli:\n",r);
      fprintf(stdout,"cmp %%r14, %%r13\n");
      fprintf(stdout,"jl .%lli\n",r1);
      fprintf(stdout,"sub %%r14, %%r13\n");
      fprintf(stdout,"jmp .%lli\n",r);
      fprintf(stdout,".%lli:\n",r1);
      fprintf(stdout,"push %%r13\n");
      break;

    case timesK:
      fprintf(stderr, "generating generate_EXP -> timesK\n" );
      generate_EXP(e->val.timesE.left, flag);
      generate_EXP(e->val.timesE.right, flag);
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
      fprintf(stderr, "generating generate_EXP -> divK\n" );
      generate_EXP(e->val.divE.left, flag);
      generate_EXP(e->val.divE.right, flag);
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"xor %%rdx, %%rdx\n");
      fprintf(stdout,"movq %%r14, %%rax\n");
      fprintf(stdout,"idiv %%r13\n");
      fprintf(stdout,"movq %%rax, %%r13\n");
      fprintf(stdout,"push %%r13\n");
      break;

    case plusK:
      fprintf(stderr, "generating generate_EXP -> plusK\n" );
      generate_EXP(e->val.plusE.left, flag);
      generate_EXP(e->val.plusE.right, flag);
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"add %%r14, %%r13\n");
      fprintf(stdout,"push %%r13\n");
      break;

    case minusK:
      fprintf(stderr, "generating generate_EXP -> minusK\n" );
      generate_EXP(e->val.minusE.left, flag);
      generate_EXP(e->val.minusE.right, flag);
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"sub %%r14, %%r13\n");
      fprintf(stdout,"push %%r13\n");
      break;

    case termK:
      fprintf(stderr, "generating generate_EXP -> termK\n" );
      aterm = generate_TERM(e->val.termE, flag);
      //TODO since term can be more than just an integer value
      //we will have to move this code into genTerm.c at some point
      //fprintf(stdout,"%i \n", aterm);
      //fprintf(stdout,"movq $%i, %%r13\n", aterm);
    //  fprintf(stdout,"push %%r13\n")
      break;

    case orK:
    r = jumpnr;
    jumpnr++;
    r1 = jumpnr;
    jumpnr++;
      fprintf(stderr, "generating generate_EXP -> orK\n" );
      generate_EXP(e->val.orE.left, flag);
      generate_EXP(e->val.orE.right, flag);
      fprintf(stdout,"pop %%r13\n");
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp $0, %%r13\n");
      fprintf(stdout,"je .%lli\n",r);
      fprintf(stdout,"cmp $0, %%r14\n");
      fprintf(stdout,"je .%lli\n",r);
      fprintf(stdout,"movq $1, %%r13\n");
      fprintf(stdout,"jmp .%lli\n",r1);
      fprintf(stdout,".%lli:\n",r);
      fprintf(stdout,"movq $0, %%r13\n");
      fprintf(stdout,".%lli:\n",r1);
      fprintf(stdout,"push %%r13\n");
      break;

    default:
      fprintf(stderr,"in default case in EXP\n\n");
      break;
  }return;
}


void generate_prologue(){
  fprintf(stdout,"format: \n .string \"%%d\\n\"\n");
  fprintf(stdout,".text\n");
  fprintf(stdout,".globl main\n");/*45 identifies the system call invoked by 0x80, specifically, the free memory pointer */
  fprintf(stdout,"main:\n");
  fprintf(stdout,"movq %%rsp, %%r8\n");
  fprintf(stdout,"add $-8, %%r8\n");
  fprintf(stdout,"movq %%rsp, %%r9\n");
}


void generate_epilogue(){
  fprintf(stdout,"movq %%r9, %%rsp\n");
  fprintf(stdout, "call _exit\n");

}
