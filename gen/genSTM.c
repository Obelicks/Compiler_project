#include <stdio.h>
#include "../headers/gen.h"
extern int regNr;
void generate_STM(FILE* file, STM *s){
  switch (s->kind) {
    case returnK:
      generate_EXP(file,s->val.returnS);
      //Intern or extern
      break;

    case writeK:
      generate_EXP(file,s->val.writeS);
      break;

   case allocateK:
      generate_TYPE(file,s->val.allocateS);
      break;

    case allocateoflengthK:
      generate_TYPE(file,s->val.allocateoflengthS.variable);
      break;

    case assignK:
      generate_TYPE(file, s->val.assignS.variable);
      generate_EXP(file, s->val.assignS.expression);
      break;

    case ifthenK:
      generate_EXP(file,s->val.ifthenS.ifState);
      //jnp start
      /*start mark*/generate_STM(file,s->val.ifthenS.thenState);
      break;

    case ifelseK:
      generate_EXP(file,s->val.ifelseS.ifState);
      //jne
      generate_STM(file,s->val.ifelseS.thenState);
      generate_STM(file,s->val.ifelseS.elseState);
      break;

    case whileK:
      generate_EXP(file,s->val.whileS.expression);
      //start
      if(s->val.whileS.statement->kind == stmlistK){
        generate_LIST(file,s->val.whileS.statement->val.stmlistS);
      }else{
        generate_STM(file,s->val.whileS.statement);
      }
      //jne to start
      break;

    case stmlistK:
      break;

    default:
      printf("in default case in STM\n");
      break;
  }
}
