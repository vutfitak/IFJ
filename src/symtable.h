/*
 * Předmět  :   IFJ / IAL
 * Soubor   :   symbtable.h - Implementace tabulky symbolů
 * Projekt  :   Implementace překladače imperativního jazyka IFJ17
 * Tým č    :   21
 * Varianta :   1
 * Autoři   : xhribe02, David Hříbek
 *            xkoval14, Marek Kovalčík
 *            xvalus02, Ondřej Valušek
 *            xrutad00, Dominik Ruta
 */

#include "bintree.h"
#include <stdbool.h>

#ifndef IFJ_SYMTABLE_H
#define IFJ_SYMTABLE_H

typedef struct variable {
    char *name;
    char data_type; // i: INT, d: DOUBLE, s: STRING
} tDataVariable;

typedef struct function {
    char *name;
    char return_data_type; // i: INT, d: DOUBLE, s: STRING
    bool declared;
    bool defined;
    /* TODO seznam parametru */
} tDataFunction;

typedef struct symtable {
    tBSTNodePtr root;
} tSymtable;

void symTableInit(tSymtable*);

void symTableInsertVariable(tSymtable*, char, tDataVariable*);
tDataVariable *createDataVariable(char*, char);

tBSTNodePtr symTableSearch(tSymtable*, char);


#endif //IFJ_SYMTABLE_H
