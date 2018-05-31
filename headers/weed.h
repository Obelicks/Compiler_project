#ifndef __weed_h
#define __weed_h
#include "tree.h"


int checkForDevideByZero(EXP* exp);
int checkForTautaulogy(STM* stm);
int checkForReturns(FUNC* func);
int EXPtautology(EXP *e);
//statements that always return true

#endif
