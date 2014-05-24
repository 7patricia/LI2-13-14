#include <stdio.h>
#include <stdlib.h>

typedef struct tabela_sopa
{
	int nlinhas;
	int ncolunas;
	char linha[ncolunas][nlinhas];
}t_sopa;

void jogar(char *ficheiro);

void jogar_serpente(tsopa sopa);

int jogada_possivel_s(int x_ant, int y_ant, int x, int y, tsopa sopa);

void jogar_cavalo(tsopa sopa);

int jogada_possivel_c(int x_ant, int y_ant, int x , int y, tsopa sopa);

int coord_valida(int x, int y, tsopa sopa);



