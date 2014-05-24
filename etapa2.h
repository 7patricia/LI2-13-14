#include "cadeias.h"
//#include "hash.c"
#include <stdlib.h>
#include <stdio.h>

typedef struct tabela_sopa
{
	int nlinhas;
	int ncolunas;
	char linha[ncolunas][nlinhas];
}t_sopa;

void jogar(char *ficheiro);

void jogar_serpente(t_sopa sopa);

int jogada_possivel_s(int x_ant, int y_ant, int x, int y);

void jogar_cavalo(t_sopa sopa);

int jogada_possivel_c(int x_ant, int y_ant, int x , int y);

int coord_valida(int x, int y, t_sopa sopa);



