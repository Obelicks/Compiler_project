#include <stdio.h>
#include "../headers/gen.h"

int generate_TERM(TERM* t){
  switch (t->kind) {
    case notK:
        generate_TERM(t->val.notT);
        break;

    case absoluteK:
        generate_EXP(t->val.absoluteT);
        break;

    case numK:
        return t->val.numT;
        break;

    case expK:
        generate_EXP(t->val.expT);
        break;

    case booleanK:
        return t->val.booleanT;
        break;

    case variableK:
        generate_TYPE(t->val.variableT);
        break;

    case act_listK:
        generate_LIST(t->val.act_listT.act_list);//TODO pass the variables needed for the function
        fprintf(stdout, "jmp %s\n",t->val.act_listT.id);
        //jumping to id label
        break;

    default:
        fprintf(stderr,"in default case in TERM\n");
        break;
  }
}
