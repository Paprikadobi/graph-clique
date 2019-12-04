#include <stdlib.h>
#include <stdio.h>

#include "undirected_graph.h"

int main() {
    graph *g = load_from_file("graph.txt");
    if(g == NULL)
        return 1;

    // print_graph(g);

    find_maximal_cliques(g);

    for(int i = 0; i < g->number_of_max_cliques; i++) 
        print_set(g->maximal_cliques[i]);

    return 0;
}