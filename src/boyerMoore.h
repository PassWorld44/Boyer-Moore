#ifndef BOYER_MOORE_H
#define BOYER_MOORE_H

#include <string.h>
#include <stdlib.h>

#include "modules/listeChainee.h"

typedef struct str_listTrouves
{
	int taille;
	int* positions;

} ListTrouves;

char* fic_to_txt(char* filepath);
//retourne un char* contenant le texte d'un fichier entier

int recherche_exaustive(char* texte, char* recherche);
//retourne l'indice de la derniere 1ere occurence trouvée dans une chaine
//recherche très (trop) exaustive
//retourne -1 si aucune occurence du motif n'est dans le texte

listeChainee* recherche_exaustive_liste(char* texte, char* recherche);
//retourne une liste comptant toutes les occurences trouvees

int boyer_moore_simple(char* texte, char* recherche);
//retourne l'indice de la 1ere occurence trouvée dans une chaine
//utulise l'algo de Boyer_Moore simple

#endif