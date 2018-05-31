#ifndef __gen_h
#define __gen_h
#include "tree.h"
/*typedef struct IRtree {
  int lineno;
  enum {mainK, funcK, elseK} kind;
  union {
    struct {char * code; IRtree* next} mainI;
    struct {IRtree* func} funcI;
    struct {IRtree* i; IRtree* el} elseI;
  }val;
}IRtree;
*/
void generate_prologue();

void generate_epilogue();

void generate_EXP(EXP* expression);

void generate_STM(STM* statement);

void generate_FUNC(FUNC* function);

void generate_LIST(LIST* list);

void generate_TYPE(TYPE* type);

int generate_TERM(TERM* term);

void generate_DEC(DEC* declaration);

void parse_variables(LIST* decl_list);

char* concat(const char *s1, const char *s2);

#endif
