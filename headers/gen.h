#ifndef __gen_h
#define __gen_h

#include "tree.h"

void generate_prologue(FILE* file);

void generate_epilogue(FILE* file);

void generate_EXP(FILE* file, EXP* expression);

void generate_STM(FILE* file, STM* statement);

void generate_FUNC(FILE* file, FUNC* function);

void generate_LIST(FILE* file, LIST* list);

void generate_TYPE(FILE* file, TYPE* type);

void generate_DEC(FILE* file, DEC* declaration);

//TODO optimization
#endif
