#include <stdio.h>
#include "../headers/gen.h"

void generate_EXP(FILE* file,EXP *e)
{ switch (e->kind) {
    case equaltoK:
      generate_EXP(file,e->val.equaltoE.left);
      generate_EXP(file,e->val.equaltoE.right);
      break;

    case nequaltoK:
      generate_EXP(file,e->val.nequaltoE.left);
      generate_EXP(file,e->val.nequaltoE.right);
      break;

    case andK:
      generate_EXP(file,e->val.andE.left);
      generate_EXP(file,e->val.andE.right);
      /*mov to RX*/
      /*mov to RY*/
      /*add RX RY to RZ (if true 0+0 = 0)*/
      break;

    case smallerK:
      generate_EXP(file,e->val.smallerE.left);
      generate_EXP(file,e->val.smallerE.right);
      break;

    case biggerK:
       generate_EXP(file,e->val.biggerE.left);
       generate_EXP(file,e->val.biggerE.right);
       break;

    case smalequalK:
       generate_EXP(file,e->val.smalequalE.left);
       generate_EXP(file,e->val.smalequalE.right);
       break;

    case bigequalK:
       generate_EXP(file,e->val.bigequalE.left);
       generate_EXP(file,e->val.bigequalE.right);
       break;

     case moduloK:
       generate_EXP(file,e->val.moduloE.left);
       generate_EXP(file,e->val.moduloE.right);
       /*mov to RX*/
       /*mov to RY*/
       /*mod RX RY to RZ*/
       break;

     case timesK:
       generate_EXP(file,e->val.timesE.left);
       generate_EXP(file,e->val.timesE.right);
       /*mov to RX*/
       /*mov to RY*/
       /*mul RX RY to RZ*/
       break;

     case divK:
       generate_EXP(file,e->val.divE.left);
       generate_EXP(file,e->val.divE.right);
       /*mov to RX*/
       /*mov to RY*/
       /*div RX RY to RZ*/
       break;

     case plusK:
       generate_EXP(file,e->val.plusE.left);
       generate_EXP(file,e->val.plusE.right);
       /*mov exp to RX*/
       /*mov exp to RY*/
       /*add RX RY to RZ*/
       break;

     case minusK:
       generate_EXP(file,e->val.minusE.left);
       generate_EXP(file,e->val.minusE.right);
       /*mov to RX*/
       /*mov to RY*/
       /*min RX RY to RZ*/
       break;

    case termK:
      generate_TERM(file,e->val.termE);
       break;

    case orK:
       generate_EXP(file,e->val.orE.left);
       generate_EXP(file,e->val.orE.right);
       /*mov to RX*/
       /*mov to RY*/
       //or RX RY -> RZ (or RX)
       break;

    default:
       printf("in default case in EXP\n");
       break;
  }
}
