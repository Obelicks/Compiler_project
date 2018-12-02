#ifndef TYPECHECK_H
#define TYPECHECK_H

#include "tree.h"

void typeCheckFUNC(SymbolTable* symbolTable, FUNC* body);

int typeCheckTYPE(SymbolTable* symbolTable, TYPE* type);

void typeCheckDEC(SymbolTable* symbolTable, DEC* declaration);

void typeCheckSTM(SymbolTable* symbolTable, STM* statement);

int typeCheckTERM(SymbolTable* symbolTable, TERM* term);

int typeCheckEXP(SymbolTable* symbolTable, EXP* expression);

void typeCheckLIST(SymbolTable* symbolTable, LIST* list);

//Help functions
int findType(TYPE* type);

#endif
