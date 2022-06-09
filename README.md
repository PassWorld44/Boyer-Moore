# Boyer-Moore :
### Algorithme :

**Traitement du motif :**\
**Tableau 1 :**
- on affect pas le dernier
- et pour chaque lettre du reste, on affect sa distance minimale a la fin

**Tableau 2 :**
- Plus compliqué 		

**Traitement du texte :**
- on place le curseur a la taille du motif
- et on parcourt un autre curseur a l’envers :
	- fini : on en a trouvé 1
	- erreur : on saute en fonctions de la table

**Traitement de l’erreur :**
- si la lettre ne correspond pas :
	- cette lettre est présente plus tôt dans le motif on saute de cette valeur
	- cette lettre n’apparait pas apprès dans le motif on saut de la taille 

**Particularité :**
- pas de complexité
- méthode : c’est un principe pas une stratégie.

**Aller plus loin :**
- 2 décalage : « mauvais caractère » et « bon suffixe »
- concevoir un moteur de recherche utilisable pour des texte

voir [la page wikipédia liée](https://fr.wikipedia.org/wiki/Algorithme_de_Boyer-Moore)

et voir [ceci pour la 2e partie de l'algo](https://www.geeksforgeeks.org/boyer-moore-algorithm-good-suffix-heuristic/)