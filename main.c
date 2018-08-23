#include <stdio.h>
#include "headers/symbol.h"
#include "headers/pretty.h"
#include "headers/tree.h"
#include "headers/typecheck.h"
#include "headers/weed.h"
#include "headers/gen.h"
int lineno;
long long int jumpnr;
void yyparse();
FILE* yyin;
FUNC* thebody;

int main(int argc, char* argv[]){
  jumpnr = 0;
  lineno = 1;
  SymbolTable* root = initSymbolTable();
  fprintf(stderr, "Parsing...\n");
  yyparse();
  fprintf(stderr, "Parsed\n");
  //prettyFUNC(thebody);
  fprintf(stderr, "Typechecking...\n");
  int doesItWork = typeCheckFUNC(root, thebody);
  if (doesItWork<0) {
    fprintf(stderr, "typecheck error, code: %i\n", doesItWork);
    return 10 + doesItWork;
  }else{

    fprintf(stderr, "typecheked\n");
    //doesItWork = weeder(thebody);
    //if(doesItWork) return 100 + doesItWork;
    fprintf(stderr, "Generating code...\nGenerating prologue...\n");
    generate_prologue();//method is in genEXP.c
    fprintf(stderr,"ending prologue\nwriting main...\n");
    generate_FUNC(thebody);
    fprintf(stderr,"ending code/starting epilogue...\n");
    generate_epilogue();//method is in genEXP.c
    fprintf(stderr,"code written\n");
  }
  fclose(yyin);
  // fprintf(stderr,"doesItWork = %i\n", doesItWork);
  return 0;
}
