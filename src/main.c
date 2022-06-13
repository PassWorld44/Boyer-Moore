#include <stdio.h>
#include "boyerMoore.h"

int main()
{
	//char* txt = fic_to_txt("txtExemple.txt");
	//printf("%s", txt);
	char* motif = "ABBABAB";
	
	int* tabDouble = tableau_saut_suffixe(motif);

	for(int i = 0; i < strlen(motif) ; i++)
	{
		printf("%d\n", tabDouble[i]);
	}
	
	free(tabDouble);
	
	return 0;
}