/*
Emile BONDU
17/12/2021
listes chainees
*/

#ifndef LISTE_CHAINEE_H
#define LISTE_CHAINEE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct str_noeud
{
	int info;
	struct str_noeud *suivant;
} noeud;

typedef struct liste_simplement_chainee
{
	noeud *premier_element;
}listeChainee;

noeud* cree_element(int valeur);
//crée un noeud avec la valeur demandée
//si la creation d'un noeud a echouee, 
//	le pointeur retourne sera NULL
void detruire_element(noeud *n);
//Attention : cette fonction detruit aussi les noeuds 
//	avec lequels elle est liée
noeud* copie_element(noeud *n);
//crée un noeud similaire au 1er, 
//		sans pointeur suivant
//peut retourner un NULL en cas d'echec

void detruire_liste_chainee(listeChainee* liste);
//detruit une liste chainee proprement
//ATTENTION : il faut utiliser cette fonction 
//	pour detruire une liste
listeChainee* initialisation(int valeur);
//peut renvoyer NULL si l'alloc dynamique a echoue,
//valeur a verifier a l'arrivee
listeChainee* liste_chainee_vide();
//cree une liste chainee vide

int copie_liste(listeChainee lst, listeChainee *copie);
//PRE-CONDITION : copie a besoin d'etre crée avant la fonction
//VALEURS DE RETOUR :
//	retourne 0  si la copie est reussie
//	retourne -1 si echec de copie des differents elements
//		 -> la liste peut y etre tronquée

void afficher(listeChainee liste);
//affiche la liste (format python)
int longueur_liste(listeChainee lst);
//retourne le nombre d'elements dans cette liste
int recherche_valeur(listeChainee liste, int valeur);
//retourne la 1ere occurence de la valeur demandée
//retourne -1 si aucune occurence a été trouvée

noeud* acceder_element(listeChainee* liste, int indice);
//si l'indice n'est pas accessible, on retournera NULL
int insere_noeud(listeChainee* liste, int indice, noeud* element);
//val de retour : -1 si l'insertion a echouee
//				  0 si l'insertion a ete effectuee avec succes
int suppr_noeud(listeChainee* liste, int indice);
//val de retour : -1 si l'insertion a echouee
//				  0 si l'insertion a ete effectuee avec succes

/*
int concatene_liste(listeChainee* liste1, listeChainee liste2);
//VALEURS DE RETOUR :
// 0 si la concatenation est réussie
// -1 en cas d'echec : la fonction n'a rien effectuée
*/

void tests_unitaire_liste_chainee();

#endif