#include <stdio.h>
#include "../headers/gen.h"
extern long long int jumpnr;
extern long long int comparator;
extern long long int returnadress;
int generate_TERM(TERM* t){
  fprintf(stderr, "generating generate_TERM \n" );
  long long int r, r1, r2, r3;
  //int val;
  switch (t->kind) {
    case notK:
      fprintf(stderr, "generating generate_TERM -> notK \n" );
      generate_TERM(t->val.notT);
      fprintf(stdout,"pop %%r14\n");
      fprintf(stdout,"cmp $0, %%r14\n");
      fprintf(stdout,"jne .+6\n");
      fprintf(stdout,"push $1\n");
      fprintf(stdout,"jmp .+4\n");
      fprintf(stdout,"push $0\n");
      break;

    case absoluteK:
      fprintf(stderr, "generating generate_TERM -> absoluteK \n" );
      /*val=*/generate_EXP(t->val.absoluteT);
      //TODO this will have to be done in assembler
      //unless we can peephole it
      /*if (val < 0){
        val = val * (-1);
      }
      return val;*/
      break;

    case numK:
        fprintf(stderr, "generating generate_TERM -> numK \n" );
        fprintf(stdout,"push $%i\n", t->val.numT);



        break;

    case expK:
      fprintf(stderr, "generating generate_TERM -> expK \n" );
      generate_EXP(t->val.expT);
      break;

    case booleanK:
      fprintf(stderr, "generating generate_TERM -> booleanK \n" );
      fprintf(stdout,"push $%i\n", t->val.booleanT);
      break;

    case variableK:
        r = jumpnr;
        jumpnr++;
        r1 = jumpnr;
        jumpnr++;
        r2 = jumpnr;
        jumpnr++;
        r3 = jumpnr;
        jumpnr++;
        //assembly that returns
        fprintf(stderr, "generating generate_TERM -> variableK \n" );
        fprintf(stdout,"movq $%i, %%r12\n",hash(t->val.variableT->val.idT));
        fprintf(stdout,"movq %%r8, %%r11\n");
        fprintf(stdout,"movq %%r9, %%r10\n");
        fprintf(stdout, ".%lli:\n",r1);
        fprintf(stdout,"cmp (%%r11), %%r12\n");
        fprintf(stdout, "je .%lli\n",r);
        fprintf(stdout,"add $-24, %%r11\n");
        fprintf(stdout,"cmp %%r11, %%r10\n");
        fprintf(stdout, "jg .%lli\n",r2);
        fprintf(stdout, "jmp .%lli\n",r1);
        fprintf(stdout, ".%lli:\n",r);
        fprintf(stdout,"push -16(%%r11)\n");
        fprintf(stdout, "jmp .%lli\n",r3);
        fprintf(stdout, ".%lli:\n",r2);
        fprintf(stdout, "movq 40(%%r8), %%r11\n");
        fprintf(stdout, "movq 32(%%r8), %%r10\n");
        fprintf(stdout, "jmp .%lli\n",r1);
        fprintf(stdout, ".%lli:\n",r3);

        //generate_TYPE(t->val.variableT);
        break;

    case act_listK:
      fprintf(stderr, "generating generate_TERM -> actlistK \n" );
      if (NULL != t->val.act_listT.act_list){
        generate_LIST(t->val.act_listT.act_list);
      }
      fprintf(stdout, "call .%s\n",t->val.act_listT.id);

      break;

    default:
      fprintf(stderr,"in default case in TERM\n");
      break;
  }
}
