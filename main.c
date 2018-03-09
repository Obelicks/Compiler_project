#include <stdio.h>
#include "headers/symbol.h"
#include "headers/pretty.h"
#include "headers/tree.h"
#include "headers/typecheck.h"
int lineno;

void yyparse();

FILE* yyin;

FUNC* thebody;

int main(){
  lineno = 1;
  SymbolTable* root = initSymbolTable();
  yyin = fopen("test.sk", "r");
  yyparse();
  int doesItWork = typeCheckFUNC(thebody,root);
  fclose(yyin);
  // printf("doesItWork = %i\n", doesItWork);
  return 0;
}
