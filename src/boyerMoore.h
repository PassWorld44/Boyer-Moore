#ifndef BOYER_MOORE_H
#define BOYER_MOORE_H

#include <string.h>

#include "modules.listChainee.h"

typedef struct str_listTrouves
{
	int taille;
	int* positions;

} ListTrouves;

int recherche_exaustive(char* texte, char* recherche);
//retourne l'indice de la 1ere occurence trouvée dans une chaine
//recherche très (trop) exaustive

int boyer_moore_simple(char* texte, char* recherche);
//retourne l'indice de la 1ere occurence trouvée dans une chaine
//utulise l'algo de Boyer_Moore simple

#endif