#include <stdio.h>
#include "../headers/gen.h"
extern long long int variablecounter;

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
      int holder = hash(*d->val.dectypeD.id);
      fprintf(stdout,"push $%i\n",holder);
      if(d->val.dectypeD.type->kind == 7){
        generate_TYPE(d->val.dectypeD.type);
      }else{
        fprintf(stdout,"push $%lli\n",(long long int)d->val.dectypeD.type->kind);
      }
      fprintf(stdout,"push $0\n");

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
int hash (const char* word) // hash based on javas string hash from stackoverflow
{
    unsigned int hash = 0;
    for (int i = 0 ; word[i] != '\0' ; i++)
    {
        hash = 31*hash + word[i];
    }
    return hash % 18446744073709551615;
}
