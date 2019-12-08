/* simple_set.c
 * Předmět: Algoritmy (IAL)
 * Projekt: 8. Největší klika v neorientovaném grafu 
 * Vytvořil: Patrik Dobiáš
 * Poslední změna: 8.12.2019
 * 
 * 
 */


#include <stdlib.h>
#include <stdio.h>

#include "simple_set.h"

/*
 * Vytvoří nový set. 
 * Vrací ukazatel na tento set, v případě chyby vrací NULL.
 */
simple_set* create_set(int k) {
    simple_set *set = (simple_set*) malloc(sizeof(simple_set));
    if(set == NULL)
        return NULL;

    set->values = (char*) malloc(k * sizeof(char));
    set->max = k;
    set->used = 0;

    for(int i = 0; i < k; i++)
        set->values[i] = IS_UNSET;

    return set;
}

/*
 * Vytvoří kopii setu.
 * Vrací ukazatel na tento set, v případě chyby vrací NULL.
 */
simple_set* set_copy(simple_set *set) {
    simple_set *copy_set = (simple_set*) malloc(sizeof(simple_set));
    if(copy_set == NULL)
        return NULL;

    copy_set->values = (char*) malloc(set->max * sizeof(char));
    copy_set->max = set->max;
    copy_set->used = set->used;

    for(int i = 0; i < set->max; i++)
        copy_set->values[i] = set->values[i];

    return copy_set;
}

/*
 * Vytvoří set, který obsahuje prvky, které mají zadaný set a list společné. 
 */
simple_set* set_intersection(simple_set *set, l_list *list) {
    simple_set *intersected_set = create_set(set->max);
    if(intersected_set == NULL)
        return NULL;

    ll_element *current = list->first;

    while(current != NULL) {
        if(set_contains(current->value, set)) 
            set_insert(current->value, intersected_set);

        current = current->next;
    }

    return intersected_set;
}

/*
 * Vloží klíč do setu. 
 */
void set_insert(int key, simple_set *set) {
    if(set->values[key] == IS_UNSET)
        set->used++;

    set->values[key] = IS_SET;
}

/*
 * Odstraní klíč ze setu.
 */
void set_remove(int key, simple_set *set) {
    if(set->values[key] == IS_SET)
        set->used--;

    set->values[key] = IS_UNSET;
}

/*
 * Zjistí, jestli set obsahuje klíč.
 */
char set_contains(int key, simple_set *set) {
    return set->values[key] == IS_SET;
}

/*
 * Uvolní paměť setu.
 */
void free_set(simple_set *set) {
    free(set->values);
    free(set);
}

void print_set(simple_set* set) {
    for(int i = 0; i < set->max; i++) 
        if(set->values[i] == IS_SET)
            printf("%d ", i);

    printf("\n");
}