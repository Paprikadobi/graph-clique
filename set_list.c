/* set_list.c
 * Předmět: Algoritmy (IAL)
 * Projekt: 8. Největší klika v neorientovaném grafu 
 * Vytvořil: Patrik Dobiáš
 * Poslední změna: 10.12.2019
 * 
 * Implementace funkcí pro jednosměrně vázaný seznam, který obsahuje množiny (simple_set).
 */

#include <stdlib.h>

#include "set_list.h"

/*
 * Vytvoří prázdný list. 
 * Vrací ukazatel na vytvořený list, v případě chyby vrací NULL.
 */
set_list* SL_create_list() {
    set_list *list = (set_list*) malloc(sizeof(set_list));
    if(list == NULL)
        return NULL;

    list->first = NULL;

    return list;
}

/*
 * Vloží nový prvek na začátek listu.
 */
void SL_insert_first(simple_set *value, set_list *list) {
    set_element *element = (set_element*) malloc(sizeof(set_element));

    element->value = value;
    element->next = list->first;
        
    list->first = element;
}

/*
 * Uvolní paměť listu.
 */
void SL_free_list(set_list *list) {
    set_element *current = list->first;

    while(current != NULL) {
        set_element *tmp = current;
        current = current->next;
        free_set(tmp->value);
        free(tmp);
    }

    free(list);
}

/*
 * Vypíše všechny množiny, které list obsahuje.
 */ 
void SL_print_list(set_list *list) {
    set_element *current = list->first;

    while(current != NULL) {
        print_set(current->value);
        current = current->next;
    }
}