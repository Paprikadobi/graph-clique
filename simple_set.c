#include <stdlib.h>
#include <stdio.h>

#include "simple_set.h"

simple_set* create_set(int count) {
    simple_set *set = (simple_set*) malloc(sizeof(simple_set));

    set->values = (char*) malloc(count * sizeof(char));
    set->max = count;
    set->used = 0;

    for(int i = 0; i < count; i++)
        set->values[i] = 0;

    return set;
}

simple_set* set_copy(simple_set *set) {
    simple_set *copy_set = (simple_set*) malloc(sizeof(simple_set));

    copy_set->values = (char*) malloc(set->max * sizeof(char));
    copy_set->max = set->max;
    copy_set->used = set->used;

    for(int i = 0; i < set->max; i++)
        copy_set->values[i] = set->values[i];

    return copy_set;
}

simple_set* set_intersection(simple_set *set, l_list *list) {
    simple_set *intersected_set = create_set(set->max);

    ll_element *current = list->first;

    while(current != NULL) {
        if(set_contains(current->value, set)) 
            set_insert(current->value, intersected_set);

        current = current->next;
    }

    return intersected_set;
}

void set_insert(int key, simple_set *set) {
    if(set->values[key] == 0)
        set->used++;

    set->values[key] = 1;
}

void set_remove(int key, simple_set *set) {
    if(set->values[key] == 1)
        set->used--;

    set->values[key] = 0;
}

char set_contains(int key, simple_set *set) {
    return set->values[key] == 1;
}

void free_set(simple_set *set) {
    free(set->values);
    free(set);
}

void print_set(simple_set* set) {
    for(int i = 0; i < set->max; i++) 
        if(set->values[i] == 1)
            printf("%d ", i);

    printf("\n");
}