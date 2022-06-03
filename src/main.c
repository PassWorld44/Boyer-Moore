#include <stdio.h>
#include "boyerMoore.h"

int main()
{
	printf("a\n");
	char* txt = fic_to_txt("txtEmemple.txt");
	printf("b\n");
	printf("%s", txt);
	printf("c\n");
	return 0;
}