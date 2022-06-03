/*
Emile BONDU
17/12/2021
listes chainees
*/

#include "listeChainee.h"

noeud* cree_element(int valeur)
//crée un noeud avec la valeur demandée
//si la creation d'un noeud a echouee, 
//	le pointeur retourne sera NULL
{
	noeud* noeud_cree = NULL;
	noeud_cree = (noeud *)malloc(sizeof(noeud));

	if(noeud_cree != NULL)
	{
		noeud_cree->info = valeur;
		noeud_cree->suivant = NULL;
	}

	return noeud_cree;
}

void detruire_element(noeud* n)
//Attention : cette fonction detruit aussi les noeuds 
//	avec lequels elle est liée
{
	if(n->suivant)
	{
		detruire_element(n->suivant);
	}
	free(n);
}

noeud* copie_element(noeud *n)
//crée un noeud similaire au 1er, 
//		sans pointeur suivant
//peut retourner un NULL en cas d'echec
{
	noeud* noeud_cree = cree_element(n->info);

	return noeud_cree;
}

void detruire_liste_chainee(listeChainee* liste)
//detruit une liste chainee proprement
//ATTENTION : il faut utiliser cette fonction 
//	pour detruire une liste
{
	detruire_element(liste->premier_element);
	free(liste);
}

listeChainee* initialisation(int valeur)
//peut renvoyer NULL si l'alloc dynamique a echoue,
//valeur a verifier a l'arrivee
{
	listeChainee* liste = liste_chainee_vide();

	if(liste != NULL)
	{
		liste->premier_element = cree_element(valeur);
		assert(liste->premier_element != NULL);
	}

	return liste;
}

listeChainee* liste_chainee_vide()
//peut renvoyer NULL si l'alloc dynamique a echoue,
//valeur a verifier a l'arrivee
{
	listeChainee* liste = NULL;
	liste = (listeChainee*)malloc(sizeof(listeChainee));

	return liste;
}

int copie_liste(listeChainee liste, listeChainee *copie)
//PRE-CONDITION : copie a besoin d'etre crée avant la fonction
//VALEURS DE RETOUR :
//	retourne 0  si la copie est reussie
//	retourne -1 si echec de copie des differents elements
//		 -> la liste peut y etre tronquée
{
	noeud* aux = liste.premier_element;
	noeud** next = NULL;

	next = &copie->premier_element;

	while(aux != NULL)
	{
		*next = copie_element(aux);

		if(*next == NULL)
		//echec partiel de la creation : seule une partie peut avoir été crée
		{
			return -1;
		}

		next = &(*next)->suivant;
		aux = aux->suivant;
	}

	return 0;
}

void afficher(listeChainee liste)
//affiche la liste (format python)
{
	noeud* aux = NULL;
	aux = liste.premier_element;
	printf("[");
	while(aux != NULL)
	{
		if(aux->suivant == NULL)
		{	
			printf("%d", aux->info);
		}
		else
		{
			printf("%d, ", aux->info);
		}
		aux = aux->suivant;
	}
	printf("]\n");
}

int longueur_liste(listeChainee lst)
//retourne le nombre d'elements dans cette liste
{
	noeud* aux = NULL;
	int taille = 0;
	aux = lst.premier_element;
	while(aux != NULL)
	{
		taille++;
		aux = aux->suivant;
	}

	return taille;
}

int recherche_valeur(listeChainee liste, int valeur)
//retourne la 1ere occurence de la valeur demandée
//retourne -1 si aucune occurence a été trouvée
{
	noeud* aux = liste.premier_element;
	int compteur = 0;

	while(aux != NULL)
	{
		if(aux->info == valeur)
		{
			return compteur;
		}
		compteur++;
		aux = aux->suivant;
	}

	//on a pas trouvé d'occurences
	return -1;
}

noeud* acceder_element(listeChainee* liste, int indice)
//si l'indice n'est pas accessible, on retournera NULL
{
	noeud* aux = liste->premier_element;

	for(int i = 0; i < indice; i++)
	{
		if(aux->suivant == NULL)
		{
			//on a pas trouve l'element pointe
			return NULL;
		}
		aux = aux->suivant;
	}
	return aux;
}

int insere_noeud(listeChainee* liste, int indice, noeud* elem)
//val de retour : -1 si l'insertion a echouee
//				  0 si l'insertion a ete effectuee avec succes
{
	noeud* it = acceder_element(liste, indice - 1);

	if(it == NULL)
	{
		return -1;
	}
	
	elem->suivant = it->suivant;
	it->suivant = elem;

	return 0;
}

int suppr_noeud(listeChainee* liste, int indice)
//val de retour : -1 si l'insertion a echouee
//				  0 si l'insertion a ete effectuee avec succes
{
	noeud** precedent;
	noeud* elem;

	//il faut aussi changer le pointeur qui va vers
	//l'element a supprimer
	if(indice - 1 >= 0)
	{
		precedent = &acceder_element(liste, indice-1)->suivant;
	}
	else
	{
		precedent = &(liste->premier_element);
	}

	elem = *precedent;

	if(elem == NULL)
	{
		return -1;
	}

	*precedent = elem->suivant;

	free(elem);

	return 0;
}

/*
int concatene_liste(listeChainee* liste1, listeChainee liste2) //NON FINI
//VALEURS DE RETOUR :
// 0 si la concatenation est réussie
// -1 en cas d'echec : la fonction n'a rien effectuée
{
	listeChainee* copieListe2;
	noeud* aux = &(liste1->premier_element);
	int codeRetour

	copieListe2 = (listeChainee*)malloc(sizeof(listeChainee));
	codeRetour = copie_liste(liste2, copieListe2);

	if(codeRetour == -1) //echec de la copie dans copieListe2
	{
		return -1;
	}

	//on cherche la fin de la 2e liste
	while(*aux != NULL)
	{
		aux = &(*aux->suivant);
	}

	*aux = copieListe2->premier_element;
	premier_element = NULL; //nécéssaire pour liberer l'espace memoire

	detruire_liste_chainee(liste2);

	return 0;
}
*/

void tests_unitaire_liste_chainee()
{
	listeChainee *liste, *liste2;

	liste = initialisation(42);
	afficher(*liste);

	insere_noeud(liste, 1, cree_element(17));
	insere_noeud(liste, 2, cree_element(14));
	insere_noeud(liste, 1, cree_element(4));
	afficher(*liste);

	suppr_noeud(liste, 2);
	afficher(*liste);
	printf("taille : %d\n", longueur_liste(*liste));
	printf("indice du 14 : %d\n", 
			recherche_valeur(*liste, 14));
	printf("indice du 18 : %d\n", 
			recherche_valeur(*liste, 18));

	liste2 = (listeChainee*)malloc(sizeof(listeChainee));

	copie_liste(*liste, liste2);
	afficher(*liste2);

	detruire_liste_chainee(liste);
	detruire_liste_chainee(liste2);
}