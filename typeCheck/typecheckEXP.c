#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>

int typeCheckEXP(SymbolTable* symbolTable, EXP* expression){

  fprintf(stderr,"EXP KIND: %i\n", expression->kind);

  int x,y;
  switch (expression->kind) {
    case equaltoK:
      x = typeCheckEXP(symbolTable, expression->val.equaltoE.left);
      y = typeCheckEXP(symbolTable, expression->val.equaltoE.right);
      if (x == y && x>=0){
        return x;
      }else{
        fprintf(stderr,"type-error '==' on line %i\n",expression->lineno);
        return 0;
      }
      break;

    case nequaltoK:
      x = typeCheckEXP(symbolTable, expression->val.nequaltoE.left);
      y = typeCheckEXP(symbolTable, expression->val.nequaltoE.right);
      if (x == y && x>=0){
        return x;
      }else{
        fprintf(stderr,"type-error '!=' on line %i\n",expression->lineno);
        return 0;
      }
      break;

    case andK:
      x=typeCheckEXP(symbolTable, expression->val.andE.left);
      y=typeCheckEXP(symbolTable, expression->val.andE.right);
      if (x == y && (x == BOOLEAN || x == INTEGER)){
        return x;
      }else{
        fprintf(stderr,"type-error '&&' on line %i\n",expression->lineno);
        return 0;
      }
      break;

    case smallerK:
      x=typeCheckEXP(symbolTable, expression->val.smallerE.left);
      y=typeCheckEXP(symbolTable, expression->val.smallerE.right);
      if (x == y && x == INTEGER){
        return x;
      }else{
        fprintf(stderr,"type-error '<' on line %i\n",expression->lineno);
        return 0;
      }
      break;

    case biggerK:
      x = typeCheckEXP(symbolTable, expression->val.biggerE.left);
      y = typeCheckEXP(symbolTable, expression->val.biggerE.right);
      if (x == y && x == INTEGER){
        return x;
      }else{
        fprintf(stderr,"type-error '>' on line %i\n",expression->lineno);
        return 0;
      }
      break;

    case smalequalK:
      x = typeCheckEXP(symbolTable, expression->val.smalequalE.left);
      y = typeCheckEXP(symbolTable, expression->val.smalequalE.right);
      if (x == y && x == INTEGER){
        return x;
      }else{
        fprintf(stderr,"type-error '<=' on line %i\n",expression->lineno);
        return 0;
      }
      break;

    case bigequalK:
      x = typeCheckEXP(symbolTable, expression->val.bigequalE.left);
      y = typeCheckEXP(symbolTable, expression->val.bigequalE.right);
      if (x == y && x == INTEGER){
        return x;
      }else{
        fprintf(stderr,"type-error '>=' on line %i\n",expression->lineno);
        return 0;
      }
      break;

    case moduloK:
      x = typeCheckEXP(symbolTable, expression->val.moduloE.left);
      y = typeCheckEXP(symbolTable, expression->val.moduloE.right);
      if (x == y && x == INTEGER){
        return x;
      }else{
        fprintf(stderr,"type-error 'mod' on line %i\n",expression->lineno);
        return 0;
      }
      break;

    case timesK:
      x = typeCheckEXP(symbolTable, expression->val.timesE.left);
      y = typeCheckEXP(symbolTable, expression->val.timesE.right);
      if (x == y && x ==INTEGER){
        return x;
      }else{
        fprintf(stderr,"type-error '*' on line %i\n",expression->lineno);
        return 0;
      }
      break;

    case divK:
      x = typeCheckEXP(symbolTable, expression->val.divE.left);
      y = typeCheckEXP(symbolTable, expression->val.divE.right);
      if (x == y && x == INTEGER){
        return x;
      }else{
        fprintf(stderr,"type-error '/' on line %i\n",expression->lineno);
        return 0;
      }
      break;

    case plusK:
      x = typeCheckEXP(symbolTable, expression->val.plusE.left);
      y = typeCheckEXP(symbolTable, expression->val.plusE.right);
      // fprintf(stderr,"x = %i y =%i\n",x,y );
      if (x == y && x == INTEGER){
        return x;
      }else{
        fprintf(stderr,"type-error '+' on line %i\n",expression->lineno);
        return 0;
      }
      break;

    case minusK:
      x = typeCheckEXP(symbolTable, expression->val.minusE.left);
      y = typeCheckEXP(symbolTable, expression->val.minusE.right);
      //fprintf(stderr,"x = %i y =%i\n",x,y );
      if (x == y && x == INTEGER){
        return x;
      }else{
        fprintf(stderr,"type-error '-' on line %i\n",expression->lineno);
        return 0;
      }
      break;

    case termK:
      x=typeCheckTERM(symbolTable, expression->val.termE);
      if (x<=0){
        return x;
      }
      //fprintf(stderr,"found term of kind: %i\n", x);

      return x;
      break;

    case orK:
      x = typeCheckEXP(symbolTable, expression->val.orE.left);
      y = typeCheckEXP(symbolTable, expression->val.orE.right);
      if (x == y && (x == BOOLEAN || x == INTEGER)){
        return x;
      }else{
        fprintf(stderr,"type-error '||' on line %i\n",expression->lineno);
        return 0;
      }
      break;

    default:
      fprintf(stderr,"default case in typeCheckEXP\n");
      return 0;
      break;
  }
  return 1;
}
