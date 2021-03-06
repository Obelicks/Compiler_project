#include "stdio.h"
#include "../headers/memory.h"
#include "../headers/tree.h"

extern int lineno;

DEC* makeDEClist(LIST* list){
  DEC* dec;
  dec = NEW(DEC);
  dec->lineno = lineno;
  dec->kind = listK;
  dec->val.listD = list;
  return dec;
}


DEC* makeDECtype(char* id, TYPE* type){
  DEC* dec;
  dec = NEW(DEC);
  dec->lineno = lineno;
  dec->kind = dectypeK;
  dec->val.dectypeD.id = id;
  dec->val.dectypeD.type = type;
  return dec;
}

DEC* makeDECfunc(FUNC* func){
  DEC* dec;
  dec = NEW(DEC);
  dec->lineno = lineno;
  dec->kind = decfuncK;
  dec->val.decfuncD = func;
  return dec;
}
