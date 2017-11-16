/*
 * Předmět  :   IFJ / IAL
 * Soubor   :   symbtable.c - Implementace tabulky symbolů
 * Projekt  :   Implementace překladače imperativního jazyka IFJ17
 * Tým č    :   21
 * Varianta :   1
 * Autoři   : xhribe02, David Hříbek
 *            xkoval14, Marek Kovalčík
 *            xvalus02, Ondřej Valušek
 *            xrutad00, Dominik Ruta
 */

#include "symtable.h"
#include "string.h"
#include <stdlib.h>
#include <stdio.h>

/* --------------------inicialiace symtable-------------------- */
void symTableInit(tSymtable* Table) {
    BSTInit(&(Table->root));
}

//void symtableInsert(tSymtable* Table, string Key, void* dataPtr) {
//    BSTInsert(&(Table->root), Key.value, dataPtr);
//}

/* --------------------vlozeni dat o funkci do symtable--------------------*/
void symTableInsertFunction(tSymtable* Table, string Key, tDataFunction* dataPtr) { // vlozi do symtable zaznam s klicem Key a data dataPtr
    BSTInsert(&(Table->root), Key.value, dataPtr, ndtFunction);
}

tDataFunction *createDataFunction(int returnDataType, bool declared, bool defined, char* parameters) { // alokuje novou datovou polozku pro data funkce a vrati ukazatel
    tDataFunction * newitem;
    if ( (newitem = (tDataFunction*)malloc(sizeof(tDataFunction))) == NULL ) {
        return NULL;
    }
    // inicializace dat
    newitem->returnDataType = returnDataType;
    newitem->declared = declared;
    newitem->defined = defined;
    newitem->parameters = parameters;
    return newitem;
}

/* --------------------vlozeni dat o promenne do symtable--------------------*/
void symTableInsertVariable(tSymtable* Table, string Key, tDataVariable* dataPtr) { // vlozi do symtable zaznam s klicem Key a data dataPtr
    BSTInsert(&(Table->root), Key.value, dataPtr, ndtVariable);
}

tDataVariable *createDataVariable(int dataType) { // alokuje novou datovou polozku pro data promenne a vrati ukazatel
    tDataVariable * newitem;
    if ( (newitem = (tDataVariable*)malloc(sizeof(tDataVariable))) == NULL ) {
        return NULL;
    }
    newitem->dataType = dataType;
    return newitem;
}

/* --------------------vyhledani prvku v symtable--------------------*/
tBSTNodePtr symTableSearch(tSymtable* Table, string Key) { // vraci ukazatel na hledany uzel, pokud nenajde vraci NULL
    return BSTSearch(Table->root, Key.value);
}

/* --------------------smazani prvku v symtable--------------------*/
void symTableDelete(tSymtable* Table, string Key) {
    BSTDelete(&(Table->root), Key.value);
}

/* --------------------smazani cele symtable--------------------*/
void symTableDispose(tSymtable* Table) {
    BSTDispose(&(Table->root));
}