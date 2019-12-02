#ifndef UNDIRECTED_GRAPH_H
#define UNDIRECTED_GRAPH_H

#include "linked_list.h"
#include "simple_set.h"

typedef struct {
    int V;
    l_list **adjacents;
} graph;

graph* create_graph(int V);

graph* load_from_file(char* file_name);

void add_edge(int first, int second, graph *g);

void print_graph();

simple_set* find_maximal_cliques(simple_set *R, simple_set *P, simple_set *X, graph *g);

#endif