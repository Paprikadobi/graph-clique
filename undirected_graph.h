#ifndef UNDIRECTED_GRAPH_H
#define UNDIRECTED_GRAPH_H

#include "linked_list.h"
#include "simple_set.h"

#define MAX_NUMBER_OF_MAX_CLIQUES 10

typedef struct {
    int V;
    l_list **adjacents;
    simple_set *maximal_cliques[MAX_NUMBER_OF_MAX_CLIQUES];
    int maximal_clique, number_of_max_cliques;
} graph;

graph* create_graph(int V);

graph* load_from_file(char* file_name);

void add_edge(int first, int second, graph *g);

void print_graph();

void find_maximal_cliques(graph *g);

void _find_maximal_cliques(simple_set *R, simple_set *P, simple_set *X, graph *g);

#endif