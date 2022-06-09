#include <stdio.h>
#include "boyerMoore.h"

int main()
{
	char* txt = fic_to_txt("txtExemple.txt");
	printf("%s", txt);
	return 0;
}