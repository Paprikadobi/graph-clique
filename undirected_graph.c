#include <stdlib.h>
#include <stdio.h>

#include "undirected_graph.h"

graph* create_graph(int V) {
    graph *g = (graph*) malloc(sizeof(graph));

    g->V = V;
    g->adjacents = (l_list**) malloc(g->V * sizeof(l_list*));
    g->maximal_clique = -1;
    g->number_of_max_cliques = 0;

    for(int i = 0; i < V; i++) 
        g->adjacents[i] = create_list();

    for(int i = 0; i < MAX_NUMBER_OF_MAX_CLIQUES; i++) 
        g->maximal_cliques[i] = NULL;

    return g;
}

graph* load_from_file(char* file_name) {
    FILE *file = fopen(file_name, "r");
    if(file == NULL) {
        printf("Nepodařilo se otevřít soubor s názvem %s.", file_name);
        return NULL;
    }

    int V, first, second;

    fscanf(file, "%d", &V);

    graph *g = create_graph(V);

    while(!feof(file)) {
        fscanf(file, "%d %d", &first, &second);
        add_edge(first, second, g);
    }

    fclose(file);

    return g;
}

void add_edge(int first, int second, graph *g) {
    if(first >= g->V || second >= g->V) 
        return;

    insert_first(first, g->adjacents[second]);
    insert_first(second, g->adjacents[first]);
}

void find_maximal_cliques(graph *g) {
    simple_set* R = create_set(g->V);
    simple_set* P = create_set(g->V);
    simple_set* X = create_set(g->V);

    for(int i = 0; i < g->V; i++)
        set_insert(i, P);

    _find_maximal_cliques(R, P, X, g);
}

void _find_maximal_cliques(simple_set *R, simple_set *P, simple_set *X, graph *g) {
    if(P->used == 0 && X->used == 0) {
        if(R->used == g->maximal_clique) {
            if(g->number_of_max_cliques < MAX_NUMBER_OF_MAX_CLIQUES)
                g->maximal_cliques[g->number_of_max_cliques++] = R;
            else
                printf("Bylo nalezeno více než maximální počet maximálních klik\n");
        } else if(R->used > g->maximal_clique) {
            g->maximal_clique = R->used;

            for(int i = 0; i < g->number_of_max_cliques; i++) {
                free(g->maximal_cliques[i]);
                g->maximal_cliques[i] = NULL;
            }

            g->number_of_max_cliques = 0;
            g->maximal_cliques[g->number_of_max_cliques++] = R;
        }
        
        return;
    }

    for(int i = 0; i < P->max; i++) {
        if(!set_contains(i, P))
            continue;

        simple_set *tmp_R = set_copy(R);
        set_insert(i, tmp_R);
        
        _find_maximal_cliques(tmp_R, set_intersection(P, g->adjacents[i]), set_intersection(X, g->adjacents[i]), g);

        set_remove(i, P);
        set_insert(i, X);
    }
}

void print_graph(graph *g) {
    for(int i = 0; i < g->V; i++) {
        printf("%d: ", i);

        ll_element *current = g->adjacents[i]->first;

        while(current != NULL) {
            printf("%d ", current->value);
            current = current->next;
        }
        printf("\n");
    }
}