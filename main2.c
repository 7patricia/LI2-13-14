#include "cadeias.h"
#include "etapa2.h"

// #include "hash.c"

void main()
{
	char *nome;

	printf("Insira o nome do ficheiro com a sopa de letras:\n");
	scanf("%s",nome);
	jogar(nome);
}