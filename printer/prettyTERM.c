#include <stdio.h>
#include "../headers/pretty.h"

void prettyTERM(TERM *t){
  switch (t->kind) {
    case notK:
        fprintf(stderr,"not( ");
        prettyTERM(t->val.notT);
        fprintf(stderr,") " );
        break;

    case absoluteK:
        fprintf(stderr,"| ");
        prettyEXP(t->val.absoluteT);
        fprintf(stderr,"| ");
        break;

    case numK:
        fprintf(stderr,"%d ",t->val.numT );
        break;

    case expK:
        prettyEXP(t->val.expT);
        break;

    case booleanK:
        if(t->val.booleanT == 0){
          fprintf(stderr,"true ");
        }else if(t->val.booleanT == 1){
          fprintf(stderr,"false ");
        }else{
          fprintf(stderr,"NULL ");
        }
        break;

    case variableK:
        prettyTYPE(t->val.variableT);
        break;

    case act_listK:
        fprintf(stderr,"%s ", t->val.act_listT.id);
        prettyLIST(t->val.act_listT.act_list);
        break;

    default:
        fprintf(stderr,"in default case in TERM\n");
        break;
  }
}
