#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct ll_element ll_element;

struct ll_element {
    int value;
    ll_element *next;
};

typedef struct {
    ll_element *first;
} l_list;

l_list* create_list();

void insert_first(int value, l_list *list);

void free_list(l_list *list);

#endif