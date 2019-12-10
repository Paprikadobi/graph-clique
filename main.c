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
 * Hlavní soubor, ve kterém jsou načteny grafy ze souborů a poté se zavolá funkce pro nalezení největší kliky.
 */

#include <stdlib.h>
#include <stdio.h>

#include "undirected_graph.h"

int main() {
    for(int i = 1; i < 5; i++) {
        char file_name[10];
        sprintf(file_name, "g_%d.txt", i);
        graph *g = load_from_file(file_name);
        if(g == NULL)
            continue;

        printf("Největší kliky grafu: %s\n", file_name);

        find_maximal_cliques(g);

        SL_print_list(g->maximal_cliques);

        printf("\n");

        free_graph(g);
    }

    return 0;
}