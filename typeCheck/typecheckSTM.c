#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>

void typeCheckSTM(SymbolTable* symbolTable, STM* statement){

  fprintf(stderr,"STM KIND: %i\n", statement->kind);

  Symbol* symbol;
  SymbolTable* nextsymbolTable;
  int x;
  TYPE* type;
  switch (statement->kind) {
    case returnK:
      typeCheckEXP(symbolTable, statement->val.returnS);
      break;

    case writeK:
      typeCheckEXP(symbolTable, statement->val.writeS);
      break;

    case allocateK:
      typeCheckTYPE(symbolTable, statement->val.allocateS);
      break;

    case allocateoflengthK:
      typeCheckTYPE(symbolTable, statement->val.allocateoflengthS.variable);

      x=typeCheckEXP(symbolTable, statement->val.allocateoflengthS.expression);
      if (x!=INTEGER){
        fprintf(stderr, "TYPECHECK ERROR ALLOCATE LENGTH NOT AN INTEGER ON LINE: %d\n", statement->lineno);
        return;
      }
      break;

    case assignK:
      type = statement->val.assignS.variable;
      typeCheckTYPE(symbolTable, type);
      if(type->kind != 0 ){
        fprintf(stderr,"error undefined assign variable on line %i \n",statement->lineno);
        return;
      }
      symbol = getSymbol(symbolTable, type->val.idT);
      x = typeCheckEXP(symbolTable, statement->val.assignS.expression);
      if (symbol->type == x){
        return symbol->type;
      }else{
        fprintf(stderr,"TYPE ERROR: cant assign type %i to type %i on line %i\n", symbol->type, x,statement->lineno);
      }
      break;

    case ifthenK:
      x= typeCheckEXP(symbolTable, statement->val.ifthenS.ifState);
      if (x!=INTEGER || BOOLEAN){
        fprintf(stderr, "Wrong if type on line %d\n", statement->lineno);
        return;
      }
      typeCheckSTM(symbolTable, statement->val.ifthenS.thenState);

      break;

    case ifelseK:
      x=typeCheckEXP(symbolTable, statement->val.ifelseS.ifState);
      if (x!=INTEGER || BOOLEAN){
        fprintf(stderr, "Wrong if type on line %d\n", statement->lineno);
        return;
      }
      typeCheckSTM(symbolTable, statement->val.ifelseS.thenState);
      typeCheckSTM(symbolTable, statement->val.ifelseS.elseState);
      break;

    case whileK:
      x=typeCheckEXP(symbolTable, statement->val.whileS.expression);
      if (x!=INTEGER || BOOLEAN){
        fprintf(stderr, "Wrong while type on line %d\n", statement->lineno);
      }
      typeCheckSTM(symbolTable, statement->val.whileS.statement);
      break;

    case stmlistK:
      typeCheckLIST(symbolTable, statement->val.stmlistS);
      break;

    default:
      fprintf(stderr,"default case in typeCheckSTM\n");
      break;
  }
  return;
}
