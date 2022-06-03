#include "boyerMoore.h"

int recherche_exaustive(char* texte, char* recherche)
//TODO : ajouter la gestion d'éventuels plusieurs cas
{
	int i = 0, j = 0;
	int sol = -1;
	int sizeTxt = strlen(texte); 
	//trouver un meilleur nom en français pour cette variable
	int sizeRech = strlen(recherche);

	//gestion de la multiplicité des cas ?

	for(int i = 0; i < sizeTxt - sizeRech ; i++)
	{
		j = 0;
		
		while(j < sizeRech - 1 && texte[i+j] == recherche[j])
		{
			j++;
		}
		if(j == sizeRech)
		{
			sol = i;
		}
	}

	return sol;
}

int boyer_moore_simple(char* texte, char* recherche);
{
	int i = 0;
	int sol = -1;
	int sizeTxt = strlen(texte); 
	//trouver un meilleur nom en français pour cette variable
	int sizeRech = strlen(recherche);

	char tmp;

	while(i < sizeTxt - sizeRech)
	{
		tmp = texte[i + sizeTxt - 1]
		if(texte[i + sizeTxt - 1] != recherche[sizeTxt - 1])
		//on procède a un saut
		{
			//on verifie si tmp appartient a recherche
		}
	}
}
