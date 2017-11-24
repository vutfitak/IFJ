/*
 * Předmět  :   IFJ / IAL
 * Soubor   :   instList.h - Lineární seznam pro ukládání instrukcí
 * Projekt  :   Implementace překladače imperativního jazyka IFJ17
 * Tým č    :   21
 * Varianta :   1
 * Autoři   : xhribe02, David Hříbek
 *            xkoval14, Marek Kovalčík
 *            xvalus02, Ondřej Valušek
 *            xrutad00, Dominik Ruta
 */

#ifndef IFJ_INSTLIST_H
#define IFJ_INSTLIST_H

#include "string.h"
#include "expression.h"

typedef enum {
    F_LF,
    F_TF
}FRAME;

typedef struct instr_element{
    string value;
    int token_type;
    FRAME frame;
    bool isLabel;
    bool isScope;
}Instr_element;

typedef enum {
    // prace s ramci, volani funkci
    I_HEADER,
    I_MOVE,             //  <var> <symb>
    I_CREATEFRAME,
    I_PUSHFRAME,
    I_POPFRAME,
    I_DEFVAR,           //  <var>
    I_CALL,             //  <label>
    I_RETURN,


    // prace s datovym zasobnikem
    I_PUSHS,            //  <symb>
    I_POPS,             //  <var>
    I_CLEARS,


    // aritmeticke, relacni, booleovske a konverzni instrukce
    I_ADD,              //  <var> <symb1> <symb2>
    I_SUB,              //  <var> <symb1> <symb2>
    I_MUL,              //  <var> <symb1> <symb2>
    I_DIV,              //  <var> <symb1> <symb2>
    // zásobníkové verze
    I_ADDS,             //  <var> <symb1> <symb2>
    I_SUBS,             //  <var> <symb1> <symb2>
    I_MULS,             //  <var> <symb1> <symb2>
    I_DIVS,             //  <var> <symb1> <symb2>

    I_LT,               //  <var> <symb1> <symb2>
    I_GT,               //  <var> <symb1> <symb2>
    I_EQ,               //  <var> <symb1> <symb2>
    I_LTS,              //  <var> <symb1> <symb2>
    I_GTS,              //  <var> <symb1> <symb2>
    I_EQS,              //  <var> <symb1> <symb2>

    I_AND,              //  <var> <symb1> <symb2>
    I_OR,               //  <var> <symb1> <symb2>
    I_NOT,              //  <var> <symb1> <symb2>
    // zasobnikove verze
    I_ANDS,             //  <var> <symb1> <symb2>
    I_ORS,              //  <var> <symb1> <symb2>
    I_NOTS,             //  <var> <symb1> <symb2>

    I_INT2FLOAT,        //  <var> <symb>
    I_FLOAT2INT,        //  <var> <symb>
    I_FLOAT2R2EINT,     //  <var> <symb>
    I_FLOAT2R2OINT,     //  <var> <symb>
    I_INT2CHAR,         //  <var> <symb>
    I_STRI2INT,         //  <var> <symb1> <symb2>
    // zasobnikove verze
    I_INT2FLOATS,       //  <var> <symb>
    I_FLOAT2INTS,       //  <var> <symb>
    I_FLOAT2R2EINTS,    //  <var> <symb>
    I_FLOAT2R2OINTS,    //  <var> <symb>
    I_INT2CHARS,        //  <var> <symb>
    I_STRI2INTS,        //  <var> <symb1> <symb2>


    // vstupne-vystupni instrukce
    I_READ,             //  <var> <type>
    I_WRITE,            //  <symb>


    // prace s retezci
    I_CONCAT,           //  <var> <symb1> <symb2>
    I_STRLEN,           //  <var> <symb>
    I_GETCHAR,          //  <var> <symb1> <symb2>
    I_SETCHAR,          //  <var> <symb1> <symb2>


    // prace s type
    I_TYPE,             //  <var> <symb>


    // instrukce pro rizeni toku programu
    I_LABEL,            //  <label>
    I_JUMP,             //  <label>
    I_JUMPIFEQ,         //  <label> <symb1> <symb2>
    I_JUMPIFNEQ,        //  <label> <symb1> <symb2>
    // zasobnikove verze
    I_JUMPIFEQS,        //  <label>
    I_JUMPIFNEQS,       //  <label>


    // ladici instrukce
    I_BREAK,
    I_DPRINT,           //  <symb>

} INSTR;

typedef struct {
    int instType;
    void * addr1;
    void * addr2;
    void * addr3;
} tInstr;

typedef struct tDLElem {
    tInstr instruction;
    struct tDLElem *lptr;
    struct tDLElem *rptr;
} *tDLElemPtrInstruction;


typedef struct {
    tDLElemPtrInstruction First;
    tDLElemPtrInstruction Act;
    tDLElemPtrInstruction Last;
} tDLListInstruction;

void DLInitList (tDLListInstruction *);
void DLDisposeList (tDLListInstruction *);
int DLInsertFirst (tDLListInstruction *, tInstr);
int DLInsertLast(tDLListInstruction *, tInstr);
void DLFirst (tDLListInstruction *);
void DLLast (tDLListInstruction *);
void DLCopyFirst (tDLListInstruction *, tInstr *);
void DLCopyLast (tDLListInstruction *, tInstr *);
void DLDeleteFirst (tDLListInstruction *);
void DLDeleteLast (tDLListInstruction *);
void DLPostDelete (tDLListInstruction *);
void DLPreDelete (tDLListInstruction *);
int DLPostInsert (tDLListInstruction *, tInstr);
int DLPreInsert (tDLListInstruction *, tInstr);
int DLCopy (tDLListInstruction *, tInstr *);
void DLActualize (tDLListInstruction *, tInstr);
void DLSucc (tDLListInstruction *);
void DLPred (tDLListInstruction *);
int DLActive (tDLListInstruction *);

void writeInstructionNoOperand(tDLListInstruction *,int);
void writeInstructionOneOperand(tDLListInstruction *,int, Instr_element);
void writeInstructionTwoOperands(tDLListInstruction *,int, Instr_element, Instr_element);
void writeInstructionThreeOperands(tDLListInstruction *,int, Instr_element, Instr_element, Instr_element);
void generateInstruction (tDLListInstruction *, int, void*, void*, void*); // vygeneruje instrukci do instrucni pasky

void printInstructionList (tDLListInstruction *);

#endif //IFJ_INSTLIST_H