/* undirected_graph.h
 * Předmět: Algoritmy (IAL)
 * Projekt: 8. Největší klika v neorientovaném grafu 
 * Vytvořil: Patrik Dobiáš
 * Poslední změna: 8.12.2019
 * 
 * Hlavičkový soubor pro undirected_graph.c 
 */

#ifndef UNDIRECTED_GRAPH_H
#define UNDIRECTED_GRAPH_H

#include "linked_list.h"
#include "simple_set.h"

#define MAX_NUMBER_OF_MAX_CLIQUES 30

typedef struct {
    int V;                                                      // informace o počtu prvků v grafu 
    l_list **adjacents;                                         // jednosměrně vázaný list reprezentující propojení prvků v grafu
    simple_set *maximal_cliques[MAX_NUMBER_OF_MAX_CLIQUES];     // maximální nalazené kliky grafu
    int maximal_clique;                                         // počet prvků v maximální klice grafu
    int number_of_max_cliques;                                  // počet nalezených maximálních klik
} graph;

graph* create_graph(int V);

graph* load_from_file(char* file_name);

void add_edge(int first, int second, graph *g);

void find_maximal_cliques(graph *g);

void _find_maximal_cliques(simple_set *R, simple_set *P, simple_set *X, graph *g);

void free_graph(graph *g);

void print_graph();

#endif