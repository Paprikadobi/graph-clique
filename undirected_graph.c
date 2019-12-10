/* undirected_graph.c
 * Předmět: Algoritmy (IAL)
 * Projekt: 8. Největší klika v neorientovaném grafu 
 * Vytvořil: Patrik Dobiáš
 * Poslední změna: 8.12.2019
 * 
 * V tomto souboru jsou implementovány funkce pro vytvoření grafu.
 * Dále je tu implementován Bron–Kerboschův algoritmus pro nalezení maximální kliky v grafu.
 */

#include <stdlib.h>
#include <stdio.h>

#include "undirected_graph.h"

/* 
 * Vytvoří graf se zadaným počtem prvků. 
 * Vrací ukazatel na vytvořený graf, v případě chyby vrací NULL.
 */
graph* create_graph(int V) {
    graph *g = (graph*) malloc(sizeof(graph));
    if(g == NULL)
        return NULL;

    g->V = V;
    g->adjacents = (int_list**) malloc(g->V * sizeof(int_list*));
    g->maximal_cliques = SL_create_list();

    for(int i = 0; i < V; i++) 
        g->adjacents[i] = IL_create_list();

    return g;
}

/*
 * Načte graf ze souboru. 
 * Jestliže zadaný soubor nelze přečíst vrací NULL, jinak vrací ukazatel na vytvořený graf.
 */
graph* load_from_file(char* file_name) {
    FILE *file = fopen(file_name, "r");
    if(file == NULL) {
        printf("Nepodařilo se otevřít soubor s názvem %s.\n\n", file_name);
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

/*
 * Přidá hranu mezi dva prvky v grafu.
 */
void add_edge(int first, int second, graph *g) {
    if(first >= g->V || second >= g->V) 
        return;

    IL_insert_first(first, g->adjacents[second]);
    IL_insert_first(second, g->adjacents[first]);
}

/*
 * Najde maximalní kliky v grafu. V této funkci se vytvoří pomocné sety, které jsou pro algoritmus hledání potřebné.
 * Nalezené maximální kliky jsou uloženy v proměnné "maximal_cliques" grafu g.
 */
void find_maximal_cliques(graph *g) {
    simple_set* R = create_set(g->V);
    simple_set* P = create_set(g->V);
    simple_set* X = create_set(g->V);

    for(int i = 0; i < g->V; i++)
        set_insert(i, P);

    _find_maximal_cliques(R, P, X, g);
}

/*
 * Funkce implementující Bron–Kerboschův algoritmus pro hledání maximální kliky v grafu.
 */
void _find_maximal_cliques(simple_set *R, simple_set *P, simple_set *X, graph *g) {
    if(P->used == 0 && X->used == 0) {
        SL_insert_first(R, g->maximal_cliques);

        free_set(P);
        free_set(X);
        
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

    free_set(R);
    free_set(P);
    free_set(X);
}

/*
 * Uvolní paměť grafu.
 */
void free_graph(graph *g) {
    for(int i = 0; i < g->V; i++) 
        IL_free_list(g->adjacents[i]);
 
    SL_free_list(g->maximal_cliques);

    free(g);
}

/*
 * Vypíše všechny prvky grafu a informaci o tom, se kterými prvky jsou propojeny.
 */
void print_graph(graph *g) {
    for(int i = 0; i < g->V; i++) {
        printf("%d: ", i);

        int_element *current = g->adjacents[i]->first;

        while(current != NULL) {
            printf("%d ", current->value);
            current = current->next;
        }
        printf("\n");
    }
}