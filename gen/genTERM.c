#include <stdio.h>
#include "../headers/gen.h"

extern int regNr;

int generate_TERM(TERM *t){
  switch (t->kind) {
    case notK:
        generate_TERM(t->val.notT);
        break;

    case absoluteK:
        generate_EXP_V(t->val.absoluteT);
        break;

    case numK:
        return t->val.numT;
        break;

    case expK:
        generate_EXP_V(t->val.expT);
        break;

    case booleanK:
        return t->val.booleanT;
        break;

    case variableK:
        generate_TYPE(t->val.variableT);
        break;

    case act_listK:
        fprintf(stdout, "jmp %s:\n",t->val.act_listT.id);
        generate_LIST(t->val.act_listT.act_list);
        break;

    default:
        fprintf(stderr,"in default case in TERM\n");
        break;
  }
}
