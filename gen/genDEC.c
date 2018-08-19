#include <stdio.h>
#include "../headers/gen.h"


void generate_DEC(DEC *d){
  fprintf(stderr, "enter generate_DEC with declaration of %d \n", d->kind );
  switch (d->kind) {
    case listK:
      fprintf(stderr, "generating generate_DEC -> listK\n" );
      generate_LIST(d->val.listD);

      break;

    case dectypeK:
      fprintf(stderr, "generating generate_DEC -> dectypeK\n" );
      //TODO assember der laver en variabel

      generate_TYPE(d->val.dectypeD.type);

      break;

    case decfuncK:
      fprintf(stderr, "generating generate_DEC -> decfuncK\n" );
      generate_FUNC(d->val.decfuncD);
      break;

    default:
      fprintf(stderr,"in default case in generate_DEC\n");
      break;
  }return;
}
