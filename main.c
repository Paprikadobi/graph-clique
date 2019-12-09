/* main.c
 * Předmět: Algoritmy (IAL)
 * Projekt: 8. Největší klika v neorientovaném grafu 
 * Vytvořil: Patrik Dobiáš
 * Poslední změna: 8.12.2019
 * 
 * Zadání:
 * Klika grafu je podgraf, který je úplným grafem. Kterýkoliv vrchol kliky je tedy spojen hranou se všemi ostatními vrcholy kliky. 
 * Vytvořte program pro hledání největší kliky v neorientovaném grafu. Pokud existuje více řešení, nalezněte všechna. 
 * Výsledky prezentujte vhodným způsobem. Součástí projektu bude načítání grafů ze souboru a vhodné testovací grafy. 
 * V dokumentaci uveďte teoretickou složitost úlohy a porovnejte ji s experimentálními výsledky.
 * 
 */

#include <stdlib.h>
#include <stdio.h>

#include "undirected_graph.h"

int main() {
    graph *g = load_from_file("g_4.txt");
    if(g == NULL)
        return 1;

    find_maximal_cliques(g);

    for(int i = 0; i < g->number_of_max_cliques; i++) 
        print_set(g->maximal_cliques[i]);

    free_graph(g);

    return 0;
}