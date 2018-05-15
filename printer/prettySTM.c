#include <stdio.h>
#include "../headers/pretty.h"

void prettySTM(STM *s){
  switch (s->kind) {
    case returnK:
      fprintf(stderr,"return( ");
      prettyEXP(s->val.returnS);
      fprintf(stderr,") \n");
      break;

    case writeK:
      fprintf(stderr,"write( ");
      prettyEXP(s->val.writeS);
      fprintf(stderr,") \n");
      break;

   case allocateK:
      fprintf(stderr,"allocating: ");
      prettyTYPE(s->val.allocateS);
      break;

    case allocateoflengthK:
      fprintf(stderr,"allocating: ");
      prettyTYPE(s->val.allocateoflengthS.variable);
      prettyEXP(s->val.allocateoflengthS.expression);
      break;

    case assignK:
      fprintf(stderr,"assigning: ");
      prettyTYPE(s->val.assignS.variable);
      prettyEXP(s->val.assignS.expression);
      break;

    case ifthenK:
      fprintf(stderr,"if( ");
      prettyEXP(s->val.ifthenS.ifState);
      fprintf(stderr,")\n");
      fprintf(stderr,"then( ");
      prettySTM(s->val.ifthenS.thenState);
      fprintf(stderr,")\n");
      break;

    case ifelseK:
      fprintf(stderr,"if( ");
      prettyEXP(s->val.ifelseS.ifState);
      fprintf(stderr,")\n");
      fprintf(stderr,"then( ");
      prettySTM(s->val.ifelseS.thenState);
      fprintf(stderr,")\n");
      fprintf(stderr,"else( ");
      prettySTM(s->val.ifelseS.elseState);
      fprintf(stderr,")\n");
      break;

    case whileK:
      fprintf(stderr,"while( ");
      prettyEXP(s->val.whileS.expression);
      fprintf(stderr,"){\n");
      fprintf(stderr,"do:\n");
      if(s->val.whileS.statement->kind == stmlistK){
        prettyLIST(s->val.whileS.statement->val.stmlistS);
      }else{
        prettySTM(s->val.whileS.statement);
      }
      fprintf(stderr,"}end\n");
      break;

    case stmlistK:
    //TODO: MAKE THIS!!
      fprintf(stderr,"prettySTM case stmlistK\n");
      break;

    default:
      fprintf(stderr,"in default case in STM\n");
      break;
  }
}
