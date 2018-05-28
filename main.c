#include <stdio.h>
#include "headers/symbol.h"
#include "headers/pretty.h"
#include "headers/tree.h"
#include "headers/typecheck.h"
#include "headers/weed.h"
#include "headers/gen.h"
int lineno;
void yyparse();
FILE* yyin;
FUNC* thebody;

int main(int argc, char *argv[]){
  lineno = 1;
  SymbolTable* root = initSymbolTable();
  yyin = fopen(argv[1], "r");
  if (yyin == NULL) {
    fprintf(stderr, "%s is not a file\n",argv[1]);
    //fclose(yyin);
    return 1;
  }
  fprintf(stderr, "Parsing...\n");

  yyparse();

  prettyFUNC(thebody);

  fprintf(stderr, "Typechecking...\n");

  int doesItWork = typeCheckFUNC(root, thebody);
  if (doesItWork) {
    fprintf(stderr, "typecheck error %d\n", doesItWork);
    return 2;
  }else{
    fprintf(stderr, "Generating code...\nGenerating prologue...\n");
    generate_prologue();
    fprintf(stderr,"ending prologue\nwriting main...\n");
    generate_FUNC(thebody);
    fprintf(stderr,"ending code/starting epilogue...\n");
    generate_epilogue();
    fprintf(stderr,"code written\n");
  }
  fclose(yyin);
  // fprintf(stderr,"doesItWork = %i\n", doesItWork);
  return 0;
}
