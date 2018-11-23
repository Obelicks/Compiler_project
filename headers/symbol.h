#ifndef SYMBOL_H
#define SYMBOL_H


#define ID 0
#define INTEGER 1
#define BOOLEAN 2
#define FUNKTION 3

#define HashSize 317

typedef struct Symbol {
  char* name;
  int type;
  void* value;
  struct Symbol* next;
} Symbol;

typedef struct SymbolTable {
  Symbol* table[HashSize];
  struct SymbolTable* next;
} SymbolTable;

int Hash(char* str);

SymbolTable* initSymbolTable();

SymbolTable* scopeSymbolTable(SymbolTable* t);

Symbol* putSymbol(SymbolTable* t, char* name, int type, void* value);

Symbol* getSymbol(SymbolTable* t, char* name);

void dropLinkedList(Symbol* s, int i);

void printSymbolTable(SymbolTable* t);

#endif
