#include <stdio.h>
#include "modules/listeChainee.h"
#include "boyerMoore.h"

int main()
{
	char* txt = fic_to_txt("txtExemple.txt");

    afficher(*boyer_moore_simple(txt, "une"));
	return 0;
}
