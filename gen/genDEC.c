#include <stdio.h>
#include "../headers/gen.h"


void generate_DEC(DEC *d){
  fprintf(stderr, "enter generate_DEC with declaration of %d \n", d->kind );
  switch (d->kind) {
    case listK:
      generate_LIST(d->val.listD);

      break;

    case dectypeK:
      generate_TYPE(d->val.dectypeD.type);

      break;

    case decfuncK:
      generate_FUNC(d->val.decfuncD);
      break;

    default:
      fprintf(stderr,"in default case in DEC\n");
      break;
  }return;
}
