/* int_list.h
 * Předmět: Algoritmy (IAL)
 * Projekt: 8. Největší klika v neorientovaném grafu 
 * Vytvořil: Patrik Dobiáš
 * Poslední změna: 8.12.2019
 * 
 * Hlavičkový soubor pro int_list.h
 */

#ifndef INT_LIST_H
#define INT_LIST_H

typedef struct int_element int_element;

struct int_element {
    int value;          // data prvku
    int_element *next;   // ukazatel na další prvek
};

typedef struct {
    int_element *first;  // ukazatel na první prvek v listu
} int_list;

int_list* IL_create_list();

void IL_insert_first(int value, int_list *list);

void IL_free_list(int_list *list);
#endif