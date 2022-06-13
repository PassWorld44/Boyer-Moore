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
	free(ligneLue);

	return taille;
}


char* fic_to_txt(char* filepath)
{
	FILE* f = NULL;
    size_t txtTaille = taille_fic(filepath) * sizeof(char) +1;


	char* txt = (char*)malloc(txtTaille);
    txt[0] = '\0';
	char* ligneLue = (char*)malloc(sizeof(char) * 10000);;


	f = fopen(filepath, "r+");
	assert(f != NULL && "le fichier ne s'est pas ouvert");
	
	while(fgets(ligneLue, 10000, f))
	{
		//printf("%s", ligneLue);
        strcat_s(txt,txtTaille, ligneLue); // ok  Emile le problème est la   apparament la variable txt est corrompu ici
	}
	
	fclose(f);
	free(ligneLue);

	return txt;
}

int recherche_exaustive(char* texte, char* motif)
{
	int j = 0;
	int sol = -1;
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
			sol = i;
		}
	}

	return sol;
}

listeChainee* recherche_exaustive_liste(char* texte, char* motif)
{
	int j = 0;
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
 * renvoie un tableau de int, dont la position corresponds a la chaine,
 * et la valeur corresponds au saut à faire
 *
 * alloue dynamiquement le tableau renvoyé
 */
{
    int* tableau = malloc(sizeof(int)*256);  //tableau de 256, pour stocker les caractère
    assert(tableau != NULL); // test du malloc

    int tailleMotif = strlen(motif);

    for (int i = 0; i<256; i++)  // creatiotn d'un tableau de saut par défaut (saut maximal)
    {
        tableau[i] = tailleMotif;
    }

    for(int i = 0; i<tailleMotif-1; i++)  //parcourds du motif, le premier caractère n'est pas affecté
    {
        tableau[motif[i]] = tailleMotif -i -1;
		//affectation de la distance de la fin
    }

    return tableau;
}

listeChainee* boyer_moore_simple(char* texte, char* motif)
{
	int tailleTexte = strlen(texte); //taile du texte
    int tailleMotif = strlen(motif);

    int* tableauSaut = tableau_saut(motif);  //recupere le tableau de saut


    listeChainee* positions = NULL; //

    int curseur1 = tailleMotif -1;   //curseur qui parcours le texte
    int curseur2;  //curseur qui parcourt a l'envers

    while(curseur1 < tailleTexte) //parcourds du texte
    {
		curseur2 = curseur1;
        while(curseur2 > curseur1 - tailleMotif  && texte[curseur2] == motif[(tailleMotif-1) - (curseur1-curseur2)])
		{
			curseur2--;  // parcours du motif a l'envers
        }
		
		if (curseur1-curseur2 == tailleMotif) //trouvé !
        {
            if (positions == NULL)
            {
                positions = initialisation(curseur2 + 1); // on init une liste chainee car elle n'existe pas
            } else
            {
                insere_noeud(positions, 0, cree_element(curseur2 + 1));  // sauvegarde de l'occurence
            }
            curseur1 += tailleMotif; // on passe à la suite
        }
		else
		{
			curseur1 += tableauSaut[abs(texte[curseur2])];   //ici texte[curseur2] est la lettre correpondant au saut a faire
            // abs est pour passer les caractères corrompus
		}
	}

	free(tableauSaut);

    return positions;
}

int* tableau_saut_suffixe(char* motif)
// Alloue dynamiquement la variable retournee, penser a la free
{
	int tailleTab = min(strlen(motif), 256);
	//une taille de 256 pour un suffixe sera largement suffisante pour faire des sauts de taille conséquente
	int* sufTab = (int*)malloc(sizeof(int) * tailleTab);
	bool estValide, estTrouve;

	for(int i = tailleTab - 1; i >= 0; i--)
	{
		//il faut trouver le suffixe de taille i dans le début du motif
		//possibilté d'utuliser boyer-moore récursivement

		//choix ici de l'exaustif pour l'instant

		//printf("i = %d\n", i);
		estTrouve = false;
		for(int j = tailleTab - 1; j >= 0 && !estTrouve; j--)
		//on cherche la derniere occurence possible
		{
			
			estValide = true;
			//printf("j = %d\n", j);
			for(int k = 0; k < tailleTab - i && estValide; k++)
			{
				//printf("--- %c %c\n", motif[j-k], motif[tailleTab-1-k]);
				//printf("i = %d, j = %d, k = %d\n", i, j, k);
				if(j-k < 0)
				{
					//on sort, c'est normal
					//printf("on sort\n");
					sufTab[tailleTab - 1 - i] = tailleTab - k;
					estTrouve = true;
					estValide = false;
				}
				else if(motif[j-k] != motif[tailleTab-1-k])
				{
					estValide = false;
					
					if(k == tailleTab - i - 1)
					{
						sufTab[tailleTab - 1 - i] = tailleTab-1 - j;
						//on l'a trouvé
						//printf("trouvé\n");
						estTrouve = true;
					}
					
				}
			}
		}
		if(!estTrouve)
		{
			sufTab[tailleTab - 1 - i] = tailleTab;
			//on peut sauter tout le tableau
			//printf("pas trouvé\n");
			estTrouve = true;
		}
	}

	return sufTab;
} 

listeChainee* boyer_moore_double(char* texte, char* motif)
{}

void tests_unitaires()
{
	test_tableau_saut_suffixe("ABBABAB");
	test_tableau_saut_suffixe("ANPANMAN");
}

void test_tableau_saut_suffixe(char* motif)
{
	printf("Calcul de la table de saut de test_tableau_saut_suffixe\n");
	int* tabDouble = tableau_saut_suffixe(motif);

	for(int i = 0; i < strlen(motif) ; i++)
	{
		printf("%d\n", tabDouble[i]);
	}
	
	free(tabDouble);
}