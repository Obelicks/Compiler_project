#include <stdio.h>
#include "headers/symbol.h"

int main(int argc, char const *argv[]) {

  char *string = "kitty";
  int value = 42;

  char *string1 = "kitty";
  int value1 = 9000;

  SymbolTable *newTable;
  newTable = initSymbolTable();

  Symbol *newSymbol;
  newSymbol = putSymbol(newTable, string, value);
  printf("Value in newTable-table[199] before new symbol: %i\n", newTable->table[199]->value);

  Symbol *alsoNewSymbol;
  alsoNewSymbol = putSymbol(newTable, string1, value1);
  printf("Value in newTable-table[199] after new symbol: %i\n", newTable->table[199]->value);

  Symbol *getSymbol;
  getSymbol = getSymbol(newTable,"bla");
  if(getSymbol != NULL){
    printf("%s %d\n", getSymbol->name,getSymbol->value);
  }else{
    printf("Symbol not in tables\n");
  }

  return 0;
}
