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
typedef struct BLOCK {
  char* label;
  char* code;
  char* jump;
  struct BLOCK* next;
}BLOCK;

void generate_prologue(FILE* file);

void generate_epilogue(FILE* file);

void generate_EXP_H(FILE* file,EXP* expression);

void generate_EXP_V(FILE* file,EXP* expression);

void generate_STM(FILE* file, STM* statement);

void generate_FUNC(FILE* file, FUNC* function);

void generate_LIST(FILE* file, LIST* list);

void generate_TYPE(FILE* file, TYPE* type);

void generate_DEC(FILE* file, DEC* declaration);

void parse_variables(FILE* file, LIST* decl_list);

char* concat(const char *s1, const char *s2);

#endif
