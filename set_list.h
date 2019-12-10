/* set_list.h
 * Předmět: Algoritmy (IAL)
 * Projekt: 8. Největší klika v neorientovaném grafu 
 * Vytvořil: Patrik Dobiáš
 * Poslední změna: 10.12.2019
 * 
 * Hlavičkový soubor pro set_list.h
 */

#ifndef SET_LIST_H
#define SET_LIST_H

#include "simple_set.h"

typedef struct set_element set_element;

struct set_element {
    simple_set* value;          // data prvku
    set_element *next;   // ukazatel na další prvek
};

typedef struct {
    set_element *first;  // ukazatel na první prvek v listu
} set_list;

set_list* SL_create_list();

void SL_insert_first(simple_set *value, set_list *list);

void SL_free_list(set_list *list);

void SL_print_list(set_list *list);

#endif