#ifndef SYMBOL_H
#define SYMBOL_H


#define ID 1
#define INTEGER 2
#define BOOLEAN 3
#define FUNKTION 4

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
