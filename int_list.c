/* int_list.c
 * Předmět: Algoritmy (IAL)
 * Projekt: 8. Největší klika v neorientovaném grafu 
 * Vytvořil: Patrik Dobiáš
 * Poslední změna: 8.12.2019
 * 
 * Implementace funkcí pro jednosměrně vázaný seznam, který obsahuje celočíselné hodnoty.
 */

#include <stdlib.h>

#include "int_list.h"

/*
 * Vytvoří prázdný list. 
 * Vrací ukazatel na vytvořený list, v případě chyby vrací NULL.
 */
int_list* IL_create_list() {
    int_list *list = (int_list*) malloc(sizeof(int_list));
    if(list == NULL)
        return NULL;

    list->first = NULL;

    return list;
}

/*
 * Vloží nový prvek na začátek listu.
 */
void IL_insert_first(int value, int_list *list) {
    int_element *element = (int_element*) malloc(sizeof(int_element));

    element->value = value;
    element->next = list->first;
        
    list->first = element;
}

/*
 * Uvolní paměť listu.
 */
void IL_free_list(int_list *list) {
    int_element *current = list->first;

    while(current != NULL) {
        int_element *tmp = current;
        current = current->next;
        free(tmp);
    }

    free(list);
}