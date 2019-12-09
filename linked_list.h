/* linked_list.h
 * Předmět: Algoritmy (IAL)
 * Projekt: 8. Největší klika v neorientovaném grafu 
 * Vytvořil: Patrik Dobiáš
 * Poslední změna: 8.12.2019
 * 
 * Hlavičkový soubor pro linked_list.h
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct ll_element ll_element;

struct ll_element {
    int value;          // data prvku
    ll_element *next;   // ukazatel na další prvek
};

typedef struct {
    ll_element *first;  // ukazatel na první prvek v listu
} l_list;

l_list* create_list();

void insert_first(int value, l_list *list);

void free_list(l_list *list);
#endif