#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>

int typeCheckSTM(SymbolTable* symbolTable, STM* statement){

  fprintf(stderr,"STM KIND: %i\n", statement->kind);

  Symbol* symbol;
  SymbolTable* nextsymbolTable;
  int x;
  TYPE* type;
  switch (statement->kind) {
    case returnK:
      x=typeCheckEXP(symbolTable, statement->val.returnS);
      if (x<0){
        return x;
      }
      break;

    case writeK:
      x=typeCheckEXP(symbolTable, statement->val.writeS);
      if (x<0){
        return x;
      }
      break;

    case allocateK:
      x=typeCheckTYPE(symbolTable, statement->val.allocateS);
      if (x<0){
        return x;
      }
      break;

    case allocateoflengthK:
      x=typeCheckTYPE(symbolTable, statement->val.allocateoflengthS.variable);
      if (x<0){
        return x;
      }
      x=typeCheckEXP(symbolTable, statement->val.allocateoflengthS.expression);
      if (x<0){
        return x;
      }
      break;

    case assignK:
      type = statement->val.assignS.variable;
      typeCheckTYPE(symbolTable, type);
      if(type->kind != 0 ){
        fprintf(stderr,"error undefined assign variable \n");
        return -1;
      }
      symbol = getSymbol(symbolTable, type->val.idT);
      x = typeCheckEXP(symbolTable, statement->val.assignS.expression);
      if (symbol->type == x){
        return symbol->type;
      }else{
        fprintf(stderr,"TYPE ERROR: cant assign type %i to type %i\n", symbol->type, x);
      }
      break;

    case ifthenK:
      x= typeCheckEXP(symbolTable, statement->val.ifthenS.ifState);
      if (x<0){
        return x;
      }
      x =typeCheckSTM(symbolTable, statement->val.ifthenS.thenState);
      if (x<0){
        return x;
      }
      break;

    case ifelseK:
      x=typeCheckEXP(symbolTable, statement->val.ifelseS.ifState);
      if (x<0){
        return x;
      }
      x=typeCheckSTM(symbolTable, statement->val.ifelseS.thenState);
      if (x<0){
        return x;
      }
      x=typeCheckSTM(symbolTable, statement->val.ifelseS.elseState);
      if (x<0){
        return x;
      }
      break;

    case whileK:
      x=typeCheckEXP(symbolTable, statement->val.whileS.expression);
      if (x<0){
        return x;
      }
      x=typeCheckSTM(symbolTable, statement->val.whileS.statement);
      if (x<0){
        return x;
      }
      break;

    case stmlistK:
      x=typeCheckLIST(symbolTable, statement->val.stmlistS);
      if (x<0){
        return x;
      }
      break;

    default:
      fprintf(stderr,"default case in typeCheckSTM\n");
      break;
  }
  return 0;
}
