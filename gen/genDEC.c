#include <stdio.h>
#include "../headers/gen.h"

extern int regNr;

void generate_DEC(FILE* file,DEC *d){
  switch (d->kind) {
    case listK:
      generate_LIST(file,d->val.listD);
      break;

    case dectypeK:
      //generate_TYPE(file,d->val.dectypeD.type);
      return 0;
      break;

    case decfuncK:
      generate_FUNC(file,d->val.decfuncD);
      break;

    default:
      printf("in default case in DEC\n");
      break;
  }
}
void generate_prologue(FILE* file){
}
void generate_epilogue(FILE* file){
}
