#include <stdio.h>
#include "../headers/gen.h"

int generate_TERM(TERM* t){
  int v;
  //int val;
  switch (t->kind) {
    case notK:
        v =generate_TERM(t->val.notT);
        v = !v;
        return v;
        break;

    case absoluteK:
        /*val=*/generate_EXP(t->val.absoluteT);
        //TODO this will have to be done in assembler
        //unless we can peephole it
        /*if (val < 0){
          val = val * (-1);
        }
        return val;*/
        break;

    case numK:
        //assembly here to replace returnK
        fprintf(stdout,"movq $%i, %%r13\n", t->val.numT);
        /*return t->val.numT;
*/
        break;

    case expK:
        generate_EXP(t->val.expT);
        break;

    case booleanK:
        return t->val.booleanT;
        break;

    case variableK:
        //assembly that returns

        fprintf(stdout,"movq $'%s', %%r12\n", t->val.variableT->val.idT);
        fprintf(stdout,"movq %%r8, %%r11\n");
        fprintf(stdout,"cmp (%%r11), %%r12\n");
        fprintf(stdout,"je .+11\n");
        fprintf(stdout,"add $192, %%r11\n");
        fprintf(stdout,"jmp .-12\n");
        fprintf(stdout,"push 128(%%r11)\n");
        //generate_TYPE(t->val.variableT);
        break;

    case act_listK:
        generate_LIST(t->val.act_listT.act_list);//TODO pass the variables needed for the function
        fprintf(stdout, "jmp %s\n",t->val.act_listT.id);
        break;

    default:
        fprintf(stderr,"in default case in TERM\n");
        break;
  }
}
