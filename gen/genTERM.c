#include <stdio.h>
#include "../headers/gen.h"

extern int regNr;

void generate_TERM(TERM *t){
  switch (t->kind) {
    case notK:
        generate_TERM(t->val.notT);
        break;

    case absoluteK:
        generate_EXP_V(t->val.absoluteT);
        break;

    case numK:
      //return 0;
        break;

    case expK:
        generate_EXP_V(t->val.expT);
        break;

    case booleanK:
        if(t->val.booleanT == 0){
        }else if(t->val.booleanT == 1){
        }else{
        }
        break;

    case variableK:
        generate_TYPE(t->val.variableT);
        break;

    case act_listK:
        generate_LIST(t->val.act_listT.act_list);
        break;

    default:
        printf("in default case in TERM\n");
        break;
  }
}
