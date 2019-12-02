#include <stdlib.h>

#include "undirected_graph.h"

int main() {
    graph *g = load_from_file("graph.txt");
    if(g == NULL)
        return 1;

    print_graph(g);

    simple_set* R = create_set(g->V);
    simple_set* P = create_set(g->V);
    simple_set* X = create_set(g->V);

    for(int i = 0; i < g->V; i++)
        set_insert(i, P);

    find_maximal_cliques(R, P, X, g);

    return 0;
}