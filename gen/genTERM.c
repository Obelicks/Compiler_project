#include <stdio.h>
#include "../headers/gen.h"

int generate_TERM(TERM* t){
  fprintf(stderr, "generating generate_TERM \n" );
  int v;
  //int val;
  switch (t->kind) {
    case notK:
      fprintf(stderr, "generating generate_TERM -> notK \n" );
      v =generate_TERM(t->val.notT);
      v = !v;
      return v;
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
      //assembly here to replace returnK
      //fprintf(stdout,"--->%i<---", t->val.numT);
      return t->val.numT;
      break;

    case expK:
      fprintf(stderr, "generating generate_TERM -> expK \n" );
      generate_EXP(t->val.expT);
      break;

    case booleanK:
      fprintf(stderr, "generating generate_TERM -> booleanK \n" );
      return t->val.booleanT;
      break;

    case variableK:
      fprintf(stderr, "generating generate_TERM -> variableK \n" );
      /*return */generate_TYPE(t->val.variableT);
      break;

    case act_listK:
      fprintf(stderr, "generating generate_TERM -> actlistK \n" );
      generate_LIST(t->val.act_listT.act_list);//TODO pass the variables needed for the function
      fprintf(stdout, "jmp %s\n",t->val.act_listT.id);
      break;

    default:
      fprintf(stderr,"in default case in TERM\n");
      break;
  }
}
