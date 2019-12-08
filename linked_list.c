/* linked_list.c
 * Předmět: Algoritmy (IAL)
 * Projekt: 8. Největší klika v neorientovaném grafu 
 * Vytvořil: Patrik Dobiáš
 * Poslední změna: 8.12.2019
 * 
 * 
 */

#include <stdlib.h>

#include "linked_list.h"

/*
 * Vytvoří prázdný list. 
 * Vrací ukazatel na vytvořený list, v případě chyby vrací NULL.
 */
l_list* create_list() {
    l_list *list = (l_list*) malloc(sizeof(l_list));
    if(list == NULL)
        return NULL;

    list->first = NULL;

    return list;
}

/*
 * Vloží nový prvek na začátek listu.
 */
void insert_first(int value, l_list *list) {
    ll_element *element = (ll_element*) malloc(sizeof(ll_element));

    element->value = value;
    element->next = list->first;
        
    list->first = element;
}

/*
 * Uvolní paměť listu.
 */
void free_list(l_list *list) {
    ll_element *current = list->first;

    while(current != NULL) {
        ll_element *tmp = current;
        current = current->next;
        free(tmp);
    }

    free(list);
}