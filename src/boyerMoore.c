#include "boyerMoore.h"

char* fic_to_txt(char* filepath)
{
	FILE* f = NULL;
	
	char* txt = "";
	char* ligneLue;
	
	f = fopen(filepath, "r+");
	if(f == NULL)
	{
		printf("le fichier ne s'est pas ouvert");
	}

	while(fscanf(f, "%s", ligneLue) != EOF)
	{
		strcat(txt, ligneLue);
	}

	return txt;
}

int recherche_exaustive(char* texte, char* recherche)
{
	int i = 0, j = 0;
	int sol = -1;
	int sizeTxt = strlen(texte); 
	int sizeRech = strlen(recherche);

	for(int i = 0; i < sizeTxt - sizeRech ; i++)
	{
		j = 0;
		
		while(j < sizeRech - 1 && texte[i+j] == recherche[j])
		// on regarde si le motif est entierent dans le texte
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

listeChainee* recherche_exaustive_liste(char* texte, char* recherche)
{
	int i = 0, j = 0;
	listeChainee* sol = liste_chainee_vide();
	int sizeTxt = strlen(texte); 
	int sizeRech = strlen(recherche);

	for(int i = 0; i < sizeTxt - sizeRech ; i++)
	{
		j = 0;
		
		while(j < sizeRech - 1 && texte[i+j] == recherche[j])
		// on regarde si le motif est entierent dans le texte
		{
			j++;
		}
		if(j == sizeRech)
		{
			insere_noeud(sol, 0, cree_element(i));
		}
	}

	return sol;
}

/*
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

*/