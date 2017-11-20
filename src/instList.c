/*
 * Předmět  :   IFJ / IAL
 * Soubor   :   instList.c - Lineární seznam pro ukládání instrukcí
 * Projekt  :   Implementace překladače imperativního jazyka IFJ17
 * Tým č    :   21
 * Varianta :   1
 * Autoři   : xhribe02, David Hříbek (projekt 1 IAL c206)
 *            xkoval14, Marek Kovalčík
 *            xvalus02, Ondřej Valušek
 *            xrutad00, Dominik Ruta
 */

#include "instList.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SCOPE "$$scope"
#define LABELSYMBOL "$"
#define FRAMELF "LF@"
#define FRAMETF "TF@"
#define TYPEINT "int@"
#define TYPEBOOL "bool@"
#define TYPESTRING "string@"
#define TYPEDOUBLE "double@"


/* ----------------------------------------FUNKCE PRO PRACI S INSTRUKCEMI---------------------------------------------*/
void writeInstructionNoOperand(tDLListInstruction *L, int instType){
    generateInstruction(L, instType, NULL, NULL, NULL);
}

void writeInstructionOneOperand(tDLListInstruction *L, int instType, Instr_element element1){
    char *operand1 = ""; char *tmp_operand1 = element1.value.value; int tmp_operand1_type = element1.token_type; bool tmp_operand1_isScope = element1.isScope; bool tmp_operand1_isLabel = element1.isLabel; FRAME tmp_operand1_frame = element1.frame;
    operand1 = malloc((strlen(operand1)+strlen(tmp_operand1)));
    // Operand je proměnná
    if(tmp_operand1_type == sIdentificator)
        if (tmp_operand1_frame == F_LF)
            strcpy(operand1, FRAMELF);
        else /* při práci s proměnnou na Temporary frame */
            strcpy(operand1, FRAMETF);
    // Operand je konstanta
    else if(tmp_operand1_type == sInteger)
        strcpy(operand1, TYPEINT);
    else if(tmp_operand1_type == sDouble)
        strcpy(operand1, TYPEDOUBLE);
    else if(tmp_operand1_type == sString)
        strcpy(operand1, TYPESTRING);
    strcat(operand1, tmp_operand1);
    // Operand je návěští
    if(tmp_operand1_isLabel == true) {
        strcpy(operand1, LABELSYMBOL);
        strcat(operand1, tmp_operand1);
        if (tmp_operand1_isScope == true)
            operand1 = SCOPE;
    }
    generateInstruction(L, instType, operand1, NULL, NULL);
}

void writeInstructionTwoOperands(tDLListInstruction *L, int instType, Instr_element element1, Instr_element element2){
    char *operand1 = ""; char *tmp_operand1 = element1.value.value; int tmp_operand1_type = element1.token_type; bool tmp_operand1_isLabel = element1.isLabel; FRAME tmp_operand1_frame = element1.frame;
    operand1 = malloc((strlen(operand1)+strlen(tmp_operand1)));
    // Operand je proměnná
    if(tmp_operand1_type == sIdentificator)
        if (tmp_operand1_frame == F_LF)
            strcpy(operand1, FRAMELF);
        else /* při práci s proměnnou na Temporary frame */
            strcpy(operand1, FRAMETF);
    // Operand je konstanta
    else if(tmp_operand1_type == sInteger)
        strcpy(operand1, TYPEINT);
    else if(tmp_operand1_type == sDouble)
        strcpy(operand1, TYPEDOUBLE);
    else if(tmp_operand1_type == sString)
        strcpy(operand1, TYPESTRING);
    strcat(operand1, tmp_operand1);
    // Operand je návěští
    if(tmp_operand1_isLabel == true) {
        strcpy(operand1, LABELSYMBOL);
        strcat(operand1, tmp_operand1);
    }

    char *operand2 = ""; char *tmp_operand2 = element2.value.value; int tmp_operand2_type = element2.token_type; bool tmp_operand2_isLabel = element2.isLabel; FRAME tmp_operand2_frame = element2.frame;
    operand2 = malloc((strlen(operand2)+strlen(tmp_operand2)));
    // Operand je proměnná
    if(tmp_operand2_type == sIdentificator)
        if (tmp_operand2_frame == F_LF)
            strcpy(operand2, FRAMELF);
        else /* při práci s proměnnou na Temporary frame */
            strcpy(operand2, FRAMETF);
     // Operand je konstanta
    else if(tmp_operand2_type == sInteger)
        strcpy(operand2, TYPEINT);
    else if(tmp_operand2_type == sDouble)
        strcpy(operand2, TYPEDOUBLE);
    else if(tmp_operand2_type == sString)
        strcpy(operand2, TYPESTRING);
    strcat(operand2, tmp_operand2);
    // Operand je návěští
    if(tmp_operand2_isLabel == true) {
        strcpy(operand2, LABELSYMBOL);
        strcat(operand2, tmp_operand2);
    }

    generateInstruction(L, instType, operand1, operand2, NULL);
}

void writeInstructionThreeOperands(tDLListInstruction *L, int instType, Instr_element element1, Instr_element element2, Instr_element element3){
    char *operand1 = ""; char *tmp_operand1 = element1.value.value; int tmp_operand1_type = element1.token_type; bool tmp_operand1_isLabel = element1.isLabel; FRAME tmp_operand1_frame = element1.frame;
    operand1 = malloc((strlen(operand1)+strlen(tmp_operand1)));
    // Operand je proměnná
    if(tmp_operand1_type == sIdentificator)
        if (tmp_operand1_frame == F_LF)
            strcpy(operand1, FRAMELF);
        else /* při práci s proměnnou na Temporary frame */
            strcpy(operand1, FRAMETF);
        // Operand je konstanta
    else if(tmp_operand1_type == sInteger)
        strcpy(operand1, TYPEINT);
    else if(tmp_operand1_type == sDouble)
        strcpy(operand1, TYPEDOUBLE);
    else if(tmp_operand1_type == sString)
        strcpy(operand1, TYPESTRING);
    strcat(operand1, tmp_operand1);
    // Operand je návěští
    if(tmp_operand1_isLabel == true) {
        strcpy(operand1, LABELSYMBOL);
        strcat(operand1, tmp_operand1);
    }

    char *operand2 = ""; char *tmp_operand2 = element2.value.value; int tmp_operand2_type = element2.token_type; bool tmp_operand2_isLabel = element2.isLabel; FRAME tmp_operand2_frame = element2.frame;
    operand2 = malloc((strlen(operand2)+strlen(tmp_operand2)));
    // Operand je proměnná
    if(tmp_operand2_type == sIdentificator)
        if (tmp_operand2_frame == F_LF)
            strcpy(operand2, FRAMELF);
        else /* při práci s proměnnou na Temporary frame */
            strcpy(operand2, FRAMETF);
        // Operand je konstanta
    else if(tmp_operand2_type == sInteger)
        strcpy(operand2, TYPEINT);
    else if(tmp_operand2_type == sDouble)
        strcpy(operand2, TYPEDOUBLE);
    else if(tmp_operand2_type == sString)
        strcpy(operand2, TYPESTRING);
    strcat(operand2, tmp_operand2);
    // Operand je návěští
    if(tmp_operand2_isLabel == true) {
        strcpy(operand2, LABELSYMBOL);
        strcat(operand2, tmp_operand2);
    }

    char *operand3 = ""; char *tmp_operand3 = element3.value.value; int tmp_operand3_type = element3.token_type; bool tmp_operand3_isLabel = element3.isLabel; FRAME tmp_operand3_frame = element3.frame;
    operand3 = malloc((strlen(operand3)+strlen(tmp_operand3)));
    // Operand je proměnná
    if(tmp_operand3_type == sIdentificator)
        if (tmp_operand3_frame == F_LF)
            strcpy(operand3, FRAMELF);
        else /* při práci s proměnnou na Temporary frame */
            strcpy(operand3, FRAMETF);
        // Operand je konstanta
    else if(tmp_operand3_type == sInteger)
        strcpy(operand3, TYPEINT);
    else if(tmp_operand3_type == sDouble)
        strcpy(operand3, TYPEDOUBLE);
    else if(tmp_operand3_type == sString)
        strcpy(operand3, TYPESTRING);
    strcat(operand3, tmp_operand3);
    // Operand je návěští
    if(tmp_operand3_isLabel == true) {
        strcpy(operand3, LABELSYMBOL);
        strcat(operand3, tmp_operand3);
    }
    generateInstruction(L, instType, operand1, operand2, operand3);
}

void generateInstruction(tDLListInstruction *L, int instType, void *addr1, void *addr2, void *addr3) {
    tInstr instruction;
    instruction.instType = instType;
    instruction.addr1 = addr1;
    instruction.addr2 = addr2;
    instruction.addr3 = addr3;
    // generovani instrukce
    DLInsertLast(L,instruction);
}

void printInstructionList(tDLListInstruction *L) {
    tInstr currentInst; // docasne ulozeni instrukce
    DLFirst(L); // aktivita je na prvni instruci
    while ( DLActive(L) ) {
        DLCopy(L, &currentInst);
        // vypsani typu instrukce
        switch (currentInst.instType) {
            case I_HEADER:          printf(".IFJcode17\n");        break;
            case I_MOVE:            printf("MOVE %s %s\n",         (char *)currentInst.addr1, (char *)currentInst.addr2);        break;
            case I_CREATEFRAME:     printf("CREATEFRAME\n");       break;
            case I_PUSHFRAME:       printf("PUSHFRAME\n");         break;
            case I_POPFRAME:        printf("POPFRAME\n");          break;
            case I_DEFVAR:          printf("DEFVAR %s\n",          (char *)currentInst.addr1);       break;
            case I_CALL:            printf("CALL %s\n",            (char *)currentInst.addr1);       break;
            case I_RETURN:          printf("RETURN\n");            break;


            // prace s datovym zasobnikem
            case I_PUSHS:           printf("PUSHS %s\n",           (char *)currentInst.addr1);       break;
            case I_POPS:            printf("POPS %s\n",            (char *)currentInst.addr1);       break;
            case I_CLEARS:          printf("CLEARS\n");            break;


            // aritmeticke, relacni, booleovske a konverzni instrukce
            case I_ADD:             printf("ADD %s %s %s\n",      (char *)currentInst.addr1, (char *)currentInst.addr2, (char *)currentInst.addr3);        break;
            case I_SUB:             printf("SUB %s %s %s\n",      (char *)currentInst.addr1, (char *)currentInst.addr2, (char *)currentInst.addr3);        break;
            case I_MUL:             printf("MUL %s %s %s\n",      (char *)currentInst.addr1, (char *)currentInst.addr2, (char *)currentInst.addr3);        break;
            case I_DIV:             printf("DIV %s %s %s\n",      (char *)currentInst.addr1, (char *)currentInst.addr2, (char *)currentInst.addr3);        break;
            // zásobníkové verze
            case I_ADDS:             printf("ADDS %s %s %s\n",    (char *)currentInst.addr1, (char *)currentInst.addr2, (char *)currentInst.addr3);        break;
            case I_SUBS:             printf("SUBS %s %s %s\n",    (char *)currentInst.addr1, (char *)currentInst.addr2, (char *)currentInst.addr3);        break;
            case I_MULS:             printf("MULS %s %s %s\n",    (char *)currentInst.addr1, (char *)currentInst.addr2, (char *)currentInst.addr3);        break;
            case I_DIVS:             printf("DIVS %s %s %s\n",    (char *)currentInst.addr1, (char *)currentInst.addr2, (char *)currentInst.addr3);        break;

            case I_LT:              printf("LT %s %s %s\n",       (char *)currentInst.addr1, (char *)currentInst.addr2, (char *)currentInst.addr3);        break;
            case I_GT:              printf("GT %s %s %s\n",       (char *)currentInst.addr1, (char *)currentInst.addr2, (char *)currentInst.addr3);        break;
            case I_EQ:              printf("EQ %s %s %s\n",       (char *)currentInst.addr1, (char *)currentInst.addr2, (char *)currentInst.addr3);        break;
            case I_LTS:             printf("LTS %s %s %s\n",      (char *)currentInst.addr1, (char *)currentInst.addr2, (char *)currentInst.addr3);        break;
            case I_GTS:             printf("GTS %s %s %s\n",      (char *)currentInst.addr1, (char *)currentInst.addr2, (char *)currentInst.addr3);        break;
            case I_EQS:             printf("EQS %s %s %s\n",      (char *)currentInst.addr1, (char *)currentInst.addr2, (char *)currentInst.addr3);        break;

            case I_AND:             printf("AND %s %s %s\n",      (char *)currentInst.addr1, (char *)currentInst.addr2, (char *)currentInst.addr3);        break;
            case I_OR:              printf("OR %s %s %s\n",       (char *)currentInst.addr1, (char *)currentInst.addr2, (char *)currentInst.addr3);        break;
            case I_NOT:             printf("NOT %s %s %s\n",      (char *)currentInst.addr1, (char *)currentInst.addr2, (char *)currentInst.addr3);        break;
            // zasobnikove verze
            case I_ANDS:            printf("ANDS %s %s %s\n",     (char *)currentInst.addr1, (char *)currentInst.addr2, (char *)currentInst.addr3);        break;
            case I_ORS:             printf("ORS %s %s %s\n",      (char *)currentInst.addr1, (char *)currentInst.addr2, (char *)currentInst.addr3);        break;
            case I_NOTS:            printf("NOTS %s %s %s\n",     (char *)currentInst.addr1, (char *)currentInst.addr2, (char *)currentInst.addr3);        break;

            case I_INT2FLOAT:       printf("INT2FLOAT %s %s\n",   (char *)currentInst.addr1, (char *)currentInst.addr2);        break;
            case I_FLOAT2INT:       printf("FLOAT2INT %s %s\n",   (char *)currentInst.addr1, (char *)currentInst.addr2);        break;
            case I_FLOAT2R2EINT:    printf("FLOAT2R2EINT %s %s\n",(char *)currentInst.addr1, (char *)currentInst.addr2);        break;
            case I_FLOAT2R2OINT:    printf("FLOAT2R2OINT %s %s\n",(char *)currentInst.addr1, (char *)currentInst.addr2);        break;
            case I_INT2CHAR:        printf("INT2CHAR %s %s\n",    (char *)currentInst.addr1, (char *)currentInst.addr2);        break;
            case I_STRI2INT:        printf("STRI2INT %s %s %s\n", (char *)currentInst.addr1, (char *)currentInst.addr2, (char *)currentInst.addr3);        break;
            // zasobnikove verze
            case I_INT2FLOATS:      printf("INT2FLOATS %s %s\n",    (char *)currentInst.addr1, (char *)currentInst.addr2);      break;
            case I_FLOAT2INTS:      printf("FLOAT2INTS %s %s\n",    (char *)currentInst.addr1, (char *)currentInst.addr2);      break;
            case I_FLOAT2R2EINTS:   printf("FLOAT2R2EINTS %s %s\n", (char *)currentInst.addr1, (char *)currentInst.addr2);      break;
            case I_FLOAT2R2OINTS:   printf("FLOAT2R2OINTS %s %s\n", (char *)currentInst.addr1, (char *)currentInst.addr2);      break;
            case I_INT2CHARS:       printf("INT2CHARS %s %s\n",     (char *)currentInst.addr1, (char *)currentInst.addr2);      break;
            case I_STRI2INTS:       printf("STRI2INTS %s %s %s\n",  (char *)currentInst.addr1, (char *)currentInst.addr2, (char *)currentInst.addr3);      break;


            // vstupne-vystupni instrukce
            case I_READ:            printf("READ %s %s\n",          (char *)currentInst.addr1, (char *)currentInst.addr2);      break;
            case I_WRITE:           printf("WRITE %s\n",            (char *)currentInst.addr1);                                 break;


            // prace s retezci
            case I_CONCAT:          printf("CONCAT %s %s %s\n",     (char *)currentInst.addr1, (char *)currentInst.addr2, (char *)currentInst.addr3);      break;
            case I_STRLEN:          printf("STRLEN %s %s\n",        (char *)currentInst.addr1, (char *)currentInst.addr2);      break;
            case I_GETCHAR:         printf("GETCHAR %s %s %s\n",    (char *)currentInst.addr1, (char *)currentInst.addr2, (char *)currentInst.addr3);      break;
            case I_SETCHAR:         printf("SETCHAR %s %s %s\n",    (char *)currentInst.addr1, (char *)currentInst.addr2, (char *)currentInst.addr3);      break;


            // prace s type
            case I_TYPE:            printf("TYPE %s %s\n",          (char *)currentInst.addr1, (char *)currentInst.addr2);      break;


            // instrukce pro rizeni toku programu
            case I_LABEL:           printf("LABEL %s\n",            (char *)currentInst.addr1);         break;
            case I_JUMP:            printf("JUMP %s\n",             (char *)currentInst.addr1);         break;
            case I_JUMPIFEQ:        printf("JUMPIFEQ %s %s %s\n",   (char *)currentInst.addr1, (char *)currentInst.addr2, (char *)currentInst.addr3);      break;
            case I_JUMPIFNEQ:       printf("JUMPIFNEQ %s %s %s\n",  (char *)currentInst.addr1, (char *)currentInst.addr2, (char *)currentInst.addr3);      break;
            // zasobnikove verze
            case I_JUMPIFEQS:       printf("JUMPIFEQS %s\n",        (char *)currentInst.addr1);         break;
            case I_JUMPIFNEQS:      printf("JUMPIFNEQS %s\n",       (char *)currentInst.addr1);         break;


            // ladici instrukce
            case I_BREAK:           printf("BREAK\n");                                      break;
            case I_DPRINT:          printf("DPRINT %s\n", (char *)currentInst.addr1);       break;
        }
        // vypsani operandu instrukce
        //printf(" %p %p %p\n", currentInst.addr1, currentInst.addr2, currentInst.addr3); // vypise adresy operandu instrukce

        DLSucc(L);
    }
}

/* ----------------------------------------FUNKCE PRO PRACI S OBOUSTRANNE VAZANYM SEZNAMEM----------------------------*/
void DLInitList (tDLListInstruction *L) {
    // pocatecni ukazatele jsou NULL
    L->First = NULL;
    L->Last = NULL;
    L->Act = NULL;
    generateInstruction(L, I_HEADER, NULL, NULL, NULL);
    generateInstruction(L, I_DEFVAR, "GF@tmp", NULL, NULL);
    generateInstruction(L, I_JUMP, "$$scope", NULL, NULL);
}

void DLDisposeList (tDLListInstruction *L) {
    tDLElemPtrInstruction elemToDelete;
    // dokud neni seznam prazdny: mazani posledniho prvku
    while ( (elemToDelete = L->Last) != NULL) {
        L->Last = elemToDelete->lptr; // poslednim prvkem se stane predposledni prvek
        elemToDelete->lptr = elemToDelete->rptr = NULL;
        free(elemToDelete);
    }
    L->Last = L->First = L->Act = NULL;
}

int DLInsertFirst (tDLListInstruction *L, tInstr instruction) {
    // vytvoreni noveho prku + alokovani pameti pro novy prvek
    tDLElemPtrInstruction newElem;
    if( (newElem = (struct tDLElem*)malloc(sizeof(struct tDLElem))) == NULL ) {
        return 0;
    }
    newElem->instruction = instruction;

    // pokud byl seznam prazdny: pripojeni noveho prvku na zacatek
    if (L->First == NULL) {
        L->First = newElem;
        L->Last = newElem;
        newElem->lptr = NULL;
        newElem->rptr = NULL;
    }
    else {
        tDLElemPtrInstruction elemToJoin = L->First; // prvek pred ktery vlozime novy prvek
        L->First = newElem;
        newElem->lptr = NULL;
        newElem->rptr = elemToJoin;
        elemToJoin->lptr = newElem;
    }
    return 1;
}

int DLInsertLast(tDLListInstruction *L, tInstr instruction) {
    // vytvoreni noveho prku + alokovani pameti pro novy prvek
    tDLElemPtrInstruction newElem;
    if( (newElem = (struct tDLElem*)malloc(sizeof(struct tDLElem))) == NULL ) {
        return 0;
    }
    newElem->instruction = instruction;

    // pokud byl seznam prazdny: pripojeni noveho prvku na zacatek
    if (L->First == NULL) {
        L->First = newElem;
        L->Last = newElem;
        newElem->lptr = NULL;
        newElem->rptr = NULL;
    }
    else {
        L->Last->rptr = newElem;
        newElem->lptr = L->Last;
        newElem->rptr = NULL;
        L->Last = newElem;
    }
    return 1;
}

void DLFirst (tDLListInstruction *L) {
    L->Act = L->First;
}

void DLLast (tDLListInstruction *L) {
    L->Act = L->Last;
}

void DLCopyFirst (tDLListInstruction *L, tInstr *instruction) {
    // pokud je seznam prazdny: chyba
    if (L->First == NULL) {
        return;
    }
    // vraci data prvniho prvku seznamu
    *instruction = L->First->instruction;
}

void DLCopyLast (tDLListInstruction *L, tInstr *instruction) {
    // pokud je seznam prazdny: chyba
    if (L->Last == NULL) {
        return;
    }
    // vraci data prvniho prvku seznamu
    *instruction = L->Last->instruction;
}

void DLDeleteFirst (tDLListInstruction *L) {
    if (L->First) {
        // pokud je prvni prvek aktivni: zruseni aktivity
        if (L->Act == L->First)
            L->Act = NULL;
        // odstraneni prvniho prvku
        L->First = L->First->rptr;
        free(L->First->lptr); // smazani nadbytecneho prvku
        L->First->lptr = NULL;
    }
}

void DLDeleteLast (tDLListInstruction *L) {
    if (L->Last) {
        // pokud je posledni prvek aktivni: zruseni aktivity
        if (L->Act == L->Last)
            L->Act = NULL;
        // odstraneni posledniho prvku
        L->Last = L->Last->lptr; // predposledni prvek se stane poslednim
        free(L->Last->rptr); // smazani nadbytecneho prvku
        L->Last->rptr = NULL;
    }
}

void DLPostDelete (tDLListInstruction *L) {
    if (L->Act && L->Act != L->Last) {
        tDLElemPtrInstruction elemToDelete = L->Act->rptr;
        tDLElemPtrInstruction elemToJoin = elemToDelete->rptr;
        // pokud neni prvek pred aktivnim prvkem poslednim prvkem seznamu
        if (elemToJoin) {
            elemToJoin->lptr = L->Act;
            L->Act->rptr = elemToJoin;
        }
        else {
            L->Act->rptr = NULL;
            L->Last = L->Act;
        }
        free(elemToDelete);
    }
}

void DLPreDelete (tDLListInstruction *L) {
    if (L->Act && L->Act != L->First) {
        tDLElemPtrInstruction elemToDelete = L->Act->lptr;
        tDLElemPtrInstruction elemToJoin = elemToDelete->lptr;
        // pokud neni prvek za aktivnim prvkem prvnim prvkem seznamu
        if (elemToJoin) {
            elemToJoin->rptr = L->Act;
            L->Act->lptr = elemToJoin;
        }
        else {
            L->Act->lptr = NULL;
            L->First = L->Act;
        }
        free(elemToDelete);
    }
}

int DLPostInsert (tDLListInstruction *L, tInstr instruction) {
    if (L->Act) {
        // vytvoreni noveho prku + alokovani pameti pro novy prvek
        tDLElemPtrInstruction newElem;
        if( (newElem = (struct tDLElem*)malloc(sizeof(struct tDLElem))) == NULL ) {
            return 0;
        }
        newElem->instruction = instruction;

        tDLElemPtrInstruction elemToJoin = L->Act->rptr;
        // vlozeni do seznamu
        // pokud je aktivni prvek poslednim prvkem seznamu: vlozeni prvku na konec
        if (elemToJoin == NULL) {
            L->Act->rptr = newElem;
            newElem->lptr = L->Act;
            newElem->rptr = NULL;
            L->Last = newElem;
        }
        else { // vlozeni prvku mezi Act a elemToJoin
            newElem->lptr = L->Act;
            newElem->rptr = elemToJoin;
            L->Act->rptr = newElem;
            elemToJoin->lptr = newElem;
        }
    }
    return 1;
}

int DLPreInsert (tDLListInstruction *L, tInstr instruction) {
    if (L->Act) {
        // vytvoreni noveho prku + alokovani pameti pro novy prvek
        tDLElemPtrInstruction newElem;
        if( (newElem = (struct tDLElem*)malloc(sizeof(struct tDLElem))) == NULL ) {
            return 0;
        }
        newElem->instruction = instruction;

        tDLElemPtrInstruction elemToJoin = L->Act->lptr;
        // vlozeni do seznamu
        // pokud je aktivni prvek prvnim prvkem seznamu: vlozeni prvku na zacatek
        if (elemToJoin == NULL) {
            L->Act->lptr = newElem;
            newElem->rptr = L->Act;
            newElem->lptr = NULL;
            L->First = newElem;
        }
        else { // vlozeni prvku mezi Act a elemToJoin
            newElem->rptr = L->Act;
            newElem->lptr = elemToJoin;
            L->Act->lptr = newElem;
            elemToJoin->rptr = newElem;
        }
    }
    return 1;
}

int DLCopy (tDLListInstruction *L, tInstr *instruction) {
    //pokud je seznam prazdny: chyba
    if (L->Act == NULL) {
        return 0;
    }
    // vraci data aktivniho prvku seznamu
    *instruction = L->Act->instruction;
    return 1;
}

void DLActualize (tDLListInstruction *L, tInstr instruction) {
    // pokud je seznam aktivni
    if (L->Act) {
        // aktualizuj data
        L->Act->instruction = instruction;
    }
}

void DLSucc (tDLListInstruction *L) {
    // pokud je seznam aktivni, posune aktivitu na nasledujici prvek
    if (L->Act) {
        L->Act = L->Act->rptr;
    }
}

void DLPred (tDLListInstruction *L) {
    // pokud je seznam aktivni
    if (L->Act) {
        // posune aktivitu na dalsi prvek
        L->Act = L->Act->lptr;
    }
}

int DLActive (tDLListInstruction *L) {
    return(L->Act != NULL);
}