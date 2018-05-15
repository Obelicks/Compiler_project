#include <stdio.h>
#include "../headers/pretty.h"

void prettyEXP(EXP *e)
{ switch (e->kind) {
    case equaltoK:
      prettyEXP(e->val.equaltoE.left);
      fprintf(stderr,"== ");
      prettyEXP(e->val.equaltoE.right);
    break;

    case nequaltoK:
      prettyEXP(e->val.nequaltoE.left);
      fprintf(stderr,"!= ");
      prettyEXP(e->val.nequaltoE.right);
      break;

    case andK:
      prettyEXP(e->val.andE.left);
      fprintf(stderr,"&& ");
      prettyEXP(e->val.andE.right);
      break;

    case smallerK:
      prettyEXP(e->val.smallerE.left);
      fprintf(stderr,"< ");
      prettyEXP(e->val.smallerE.right);
      break;

    case biggerK:
       prettyEXP(e->val.biggerE.left);
       fprintf(stderr,"> ");
       prettyEXP(e->val.biggerE.right);
       break;

    case smalequalK:
       prettyEXP(e->val.smalequalE.left);
       fprintf(stderr,"<= ");
       prettyEXP(e->val.smalequalE.right);
       break;

    case bigequalK:
       prettyEXP(e->val.bigequalE.left);
       fprintf(stderr,">= ");
       prettyEXP(e->val.bigequalE.right);
       break;

     case moduloK:
       fprintf(stderr,"( ");
       prettyEXP(e->val.moduloE.left);
       fprintf(stderr,"%% ");
       prettyEXP(e->val.moduloE.right);
       fprintf(stderr,") ");
       break;

     case timesK:
       fprintf(stderr,"( ");
       prettyEXP(e->val.timesE.left);
       fprintf(stderr,"* ");
       prettyEXP(e->val.timesE.right);
       fprintf(stderr,") ");
       break;

     case divK:
       fprintf(stderr,"( ");
       prettyEXP(e->val.divE.left);
       fprintf(stderr,"/ ");
       prettyEXP(e->val.divE.right);
       fprintf(stderr,") ");
       break;

     case plusK:
       fprintf(stderr,"( ");
       prettyEXP(e->val.plusE.left);
       fprintf(stderr,"+ ");
       prettyEXP(e->val.plusE.right);
       fprintf(stderr,") ");
       break;

     case minusK:
       fprintf(stderr,"( ");
       prettyEXP(e->val.minusE.left);
       fprintf(stderr,"- ");
       prettyEXP(e->val.minusE.right);
       fprintf(stderr,") ");
       break;

    case termK:
       prettyTERM(e->val.termE);
       break;

    case orK:
       prettyEXP(e->val.orE.left);
       fprintf(stderr,"|| ");
       prettyEXP(e->val.orE.right);
       break;

    default:
       fprintf(stderr,"in default case in EXP\n");
       break;
  }
}
