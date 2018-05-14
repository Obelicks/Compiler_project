#include <stdio.h>
#include "headers/symbol.h"
#include "headers/pretty.h"
#include "headers/tree.h"
#include "headers/typecheck.h"
#include "headers/weed.h"
#include "headers/gen.h"
int lineno;
int debug;
int regNr;
void yyparse();

FILE* yyin;

FUNC* thebody;

int main(){
  regNr = 1;
  lineno = 1;
  //set debug to 1 to enter debug mode
  debug = 0;
  SymbolTable* root = initSymbolTable();
  yyin = fopen("test.sk", "r");
  fprintf(stderr, "Parsing...\n");
  yyparse();
  if (debug){
    prettyFUNC(thebody);
  }
  fprintf(stderr, "Typechecking...\n");
  int doesItWork = typeCheckFUNC(root, thebody);
  if (!doesItWork) {
    fprintf(stderr, "typecheck error %d\n", doesItWork);
  }else{
    fprintf(stderr, "Generating code...\n");
    generate_prologue();
    generate_FUNC(thebody);
    generate_epilogue();
  }
  fclose(yyin);
  // printf("doesItWork = %i\n", doesItWork);
  return 0;
}
