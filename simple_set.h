/* simple_set.h
 * Předmět: Algoritmy (IAL)
 * Projekt: 8. Největší klika v neorientovaném grafu 
 * Vytvořil: Patrik Dobiáš
 * Poslední změna: 8.12.2019
 * 
 * Hlavičkový soubor pro simple_set.h
 */

#ifndef SIMPLE_SET_H
#define SIMPLE_SET_H

#include "linked_list.h"

#define IS_UNSET 0
#define IS_SET 1

typedef struct {
    char *values;   // informace o tom, jestli set obsahuje daný klíč
    int max;        // maximální počet klíčů
    int used;       // existující počet klíčů
} simple_set;

simple_set* create_set(int k);

simple_set* set_copy(simple_set *set);

simple_set* set_intersection(simple_set *set, l_list *list);

void set_insert(int key, simple_set *set);

void set_remove(int key, simple_set *set);

char set_contains(int key, simple_set *set);

void free_set(simple_set *set);

void print_set(simple_set *set);

#endif