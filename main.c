#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_table.h"
#include "etapa2.h"

int main()
{
	char palavra[50];
	/* char ficheiro[20]; */

	DICIONARIO dic = criar_dicionario("dicio.txt");

	printf("palavra a consultar:\n");
	fgets(palavra, 50, stdin);
	palavra[strlen(palavra)-1] = '\0';
	if(palavra_existe(dic,palavra))
		printf("A palavra %s está no dicionário.\n", palavra);
	else
		printf("A palavra %s não está no dicionário.\n", palavra);

	/* Testar tarefa 4 */
	/* printf("Introduza o nome do ficheiro onde se encontra a sopa de letras.\n"); */
	/* scanf("%s",ficheiro); */

	/* jogar(ficheiro,dic); */

	return 0;
}
