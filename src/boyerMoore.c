#include "boyerMoore.h"

int taille_fic(char* filepath)
{
	FILE* f = NULL;
	int taille = 0;
	char* ligneLue = (char*)malloc(sizeof(char) * 10000);

	f = fopen(filepath, "r+");
	assert(f != NULL && "le fichier ne s'est pas ouvert");

	
	while(fgets(ligneLue, 10000, f))
	{
		taille += strlen(ligneLue);
		
	}

	fclose(f);

	return taille;
}

char* fic_to_txt(char* filepath)
{
	FILE* f = NULL;
	
	char* txt = (char*)malloc(taille_fic(filepath) * sizeof(char));
	char* ligneLue = (char*)malloc(sizeof(char) * 10000);;

	printf("%d", taille_fic(filepath));
	
	f = fopen(filepath, "r+");
	assert(f != NULL && "le fichier ne s'est pas ouvert");
	
	while(fgets(ligneLue, 10000, f))
	{
		printf("%s", ligneLue);
		strcat(txt, ligneLue);
	}
	
	fclose(f);

	return txt;
}

int recherche_exaustive(char* texte, char* motif)
//TODO : ajouter la gestion d'éventuels plusieurs cas
{
	int i = 0, j = 0;
	int sol = -1;
	int sizeTxt = strlen(texte); 
	int sizeMotif = strlen(motif);

	//trouver un meilleur nom en français pour cette variable

	//gestion de la multiplicité des cas ?

	for(int i = 0; i < sizeTxt - sizeMotif ; i++)
	{
		j = 0;
		
		while(j < sizeMotif - 1 && texte[i+j] == motif[j])
		// on regarde si le motif est entierent dans le texte
		{
			j++;
		}
		if(j == sizeMotif)
		{
			sol = i;
		}
	}

	return sol;
}

listeChainee* recherche_exaustive_liste(char* texte, char* motif)
{
	int i = 0, j = 0;
	listeChainee* sol = liste_chainee_vide();
	int sizeTxt = strlen(texte); 
	int sizeMotif = strlen(motif);

	for(int i = 0; i < sizeTxt - sizeMotif ; i++)
	{
		j = 0;
		
		while(j < sizeMotif - 1 && texte[i+j] == motif[j])
		// on regarde si le motif est entierent dans le texte
		{
			j++;
		}
		if(j == sizeMotif)
		{
			insere_noeud(sol, 0, cree_element(i));
		}
	}

	return sol;
}

int* tableau_saut(char* motif)
/*
 * fonction qui cree une tablea de saut avec un motif donne
 * char* motif : une chaine de caractère contenant un motif
 *
 * renoie un tableau de int, dont la position correpsonds a la chaine,
 * et la valeurs corresponds au saut a faire
 */
{
    int* tableau = malloc(sizeof(int)*256);  //tableau de 256, pour stocker les caractère
    assert(tableau != NULL); // test du malloc

    int tailleMotif = strlen(motif);

    for (int i = 0; i<256; i++)  // creatiotn d'un tableau de saut par défaut (saut maximal)
    {
        tableau[i] = tailleMotif;
    }

    for(int i = tailleMotif -1; i; i--)  //parcourds du motif, le premier caractère n'est pas affecté
    {
        if (tableau[(int) motif[i]] == tailleMotif)   // teste pour eviter les repetition
        {
            tableau[(int) motif[i]] = tailleMotif - i;  //affectation de la distance de la fin
        }
    }

    return tableau;
}

listeChainee* boyer_moore_simple(char* texte, char* motif)
{
	int curseur1 = 0;   //curseur qui parcours le texte

	int tailleTexte = strlen(texte); //taile du texte
    int tailleMotif = strlen(motif);

    int* tableauSaut = tableau_saut(motif);  //recupere le tableau de saut

    listeChainee* positions = initialisation(0); //faudra une liste vide

    while(curseur1 < tailleTexte - tailleMotif) //parcourds du texte
    {
        for (int curseur2 = curseur1; curseur2 < curseur1 - tailleMotif; curseur2--) 
		{
            if (texte[curseur2] != motif[curseur1-curseur2])    //on procède a un saut
            {
                curseur1 += tableauSaut[texte[curseur2]];   //ici texte[curseur2] est la lettre correpondant au saut a faire
            }
            if (curseur1-curseur2 == tailleMotif) //trouvé 1
            {
                insere_noeud(positions,0, cree_element(curseur2));  // sauvegarde de l'occurence
            }
        }
	}
    return positions;
}
