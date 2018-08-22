#include <stdio.h>
#include "../headers/gen.h"


void generate_DEC(DEC *d){
  fprintf(stderr, "enter generate_DEC with declaration of %d \n", d->kind );
  switch (d->kind) {
    case listK:
      generate_LIST(d->val.listD);

      break;

    case dectypeK:
      //TODO assember der laver en variabel
      fprintf(stdout,"movq $'%s', (%%r9)\n",d->val.dectypeD.id);
      fprintf(stdout,"movq $%i, 64(%%r9)\n", d->val.dectypeD.type->kind);
      fprintf(stdout,"movq $0, 128(%%r9)\n");
      fprintf(stdout,"add $192, %%r9\n");
//      generate_TYPE(d->val.dectypeD.type);

      break;

    case decfuncK:
      generate_FUNC(d->val.decfuncD);
      break;

    default:
      fprintf(stderr,"in default case in DEC\n");
      break;
  }return;
}
