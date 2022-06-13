#ifndef BOYER_MOORE_H
#define BOYER_MOORE_H

#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "modules/listeChainee.h"

typedef struct str_listTrouves
{
	int taille;
	int* positions;

} ListTrouves;

char* fic_to_txt(char* filepath);
//retourne un char* contenant le texte d'un fichier entier
//lit uniquement les 10 000 premiers charactères de chaque ligne

int recherche_exaustive(char* texte, char* motif);
//retourne l'indice de la derniere 1ere occurence trouvée dans une chaine
//recherche très (trop) exaustive
//retourne -1 si aucune occurence du motif n'est dans le texte

listeChainee* recherche_exaustive_liste(char* texte, char* motif);
//retourne une liste comptant toutes les occurences trouvees

listeChainee* boyer_moore_simple(char* texte, char* motif);
//retourne une liste chainée comportant les occurences trouvées dans une chaine
//utilise l'algo de Boyer_Moore simple

int* tableau_saut_suffixe(char* motif);

listeChainee* boyer_moore_double(char* texte, char* motif);
//retourne une liste chainée comportant les occurences trouvées dans une chaine
//utilise l'algo de Boyer_Moore double

void tests_unitaires();
void test_tableau_saut_suffixe(char* motif);

#endif