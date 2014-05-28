#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_table.h"
#include "etapa2.h"

int main()
{
	char *palavra;

	DICIONARIO dic = criar_dicionario("dicio.txt");
	printf("palavra a consultar:\n");
	scanf("%s", palavra);
	if(palavra_existe(dic,palavra))
		printf("A palavra %s está no dicionário.\n", palavra);
	else
		printf("A palavra %s não está no dicionário.\n", palavra);

	return 0;
}