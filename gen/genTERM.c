#include <stdio.h>
#include "../headers/gen.h"
extern int regNr;
void generate_TERM(FILE* file,TERM *t){
  switch (t->kind) {
    case notK:
        printf("not( ");
        generate_TERM(file,t->val.notT);
        printf(") " );
        break;

    case absoluteK:
        printf("| ");
        generate_EXP(file,t->val.absoluteT);
        printf("| ");
        break;

    case numK:
        break;

    case expK:
        generate_EXP(file,t->val.expT);
        break;

    case booleanK:
        if(t->val.booleanT == 0){
        }else if(t->val.booleanT == 1){
        }else{
        }
        break;

    case variableK:
        generate_TYPE(file,t->val.variableT);
        break;

    case act_listK:
        generate_LIST(file,t->val.act_listT.act_list);
        break;

    default:
        printf("in default case in TERM\n");
        break;
  }
}
