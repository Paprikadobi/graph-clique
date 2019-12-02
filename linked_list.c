#include <stdlib.h>

#include "linked_list.h"

l_list* create_list() {
    l_list *list = (l_list*) malloc(sizeof(l_list));
    list->first = NULL;

    return list;
}

void insert_first(int value, l_list *list) {
    ll_element *element = (ll_element*) malloc(sizeof(ll_element));

    element->value = value;
    element->next = list->first;
        
    list->first = element;
}

void free_list(l_list *list) {
    ll_element *current = list->first;

    while(current != NULL) {
        ll_element *tmp = current;
        current = current->next;
        free(tmp);
    }

    free(list);
}