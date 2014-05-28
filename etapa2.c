#include "cadeias.h"
#include "etapa2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"


DICIONARIO criar_dicionario (char *ficheiro)
{
	char palavra[50];
	size_t tamanho;

	struct DICIONARIO dic = Hash_Create(64);
	FILE* file = fopen(ficheiro,"r");
	while(!(feof(file))){
			fgets(palavra,10000,file);
			palavra[strlen(palavra)-1] = '\0';
			char *palavra2 = (char *)malloc(sizeof(char)*(strlen(palavra)+1));
			strcpy(palavra2,palavra);
			Hash_Insert(dic,palavra2);
		}
	return dic;
}


int palavra_existe(DICIONARIO dic, char * palavra)
{
	
	if(Hash_Search(dic,palavra)!=NULL)
		return 1;
	else 
		return 0;
}



void jogar(char *ficheiro, DICIONARIO dic)
{

	int x, y, i, j;
	char *modo;
	t_sopa sopa = (t_sopa)malloc(sizeof(struct tabela_sopa));

	FILE *fp;
	fp = fopen(ficheiro,"r");
	fscanf(fp,"%d",&x);
	fscanf(fp, "%d",&y);
	sopa->nlinhas = y;
	sopa->ncolunas = x;


	for(i=0;i<x;i++)
		for(j=0;j<y;j++)
			fscanf(fp,"%c",&(sopa->linha[i][j]));


	printf("Quer jogar no modo serpente ou cavalo?\n");
	scanf("%s", modo);
	while(!(cad_iguais(modo,"serpente")) && !(cad_iguais(modo,"cavalo")))
	{
		printf("Opção inválida. Digite serpente ou cavalo.");
		scanf("%s", modo);
	}
	if(cad_iguais(modo,"serpente")) 
	 	jogar_serpente(sopa, dic);
	
	else 
		jogar_cavalo(sopa, dic);
	
	}	



void jogar_serpente(t_sopa sopa, DICIONARIO dic)
{
	int x, y, jogada, i=0, count1, count2, opcao=0, linha=0, sair = 0;
	char *palavra;
	int *coords[2];

	printf("Insira as coordenadas da primeira letra (x y)");
	scanf("%d %d", &x, &y);
	palavra[i]= sopa->linha[x][y];
	i++;
	
	while(sair == 0){
	printf("Escolha a próxima jogada. Pressione a tecla 0 para sair.");
	for(count1=0;count1<sopa->ncolunas;count1++)
		for(count2=0;count2<sopa->nlinhas;count2++)
			if(jogada_possivel_c(x,y,count1,count2,sopa))
			{
				coords[linha][1] = count1;
				coords[linha][2] = count2;
				linha++;
				opcao++;
				printf("%d. %c (%d,%d)\n", opcao, sopa->linha[count1][count2], count1, count2);
			}
	scanf("%d", &jogada);
	if(jogada == 0)
		sair = 1;
	else
	{
		x = coords[jogada-1][1];
		y = coords[jogada-1][2];
		palavra[i] = sopa->linha[x][y];
		i++;
	}
}
	if(palavra_existe(dic,palavra))
		printf("Parabéns, encontrou uma palavra!\n");
	else
		printf("A palavra que escolheu não se encontra no nosso dicionário. Tente novamente.");
}



int jogada_possivel_s(int x_ant, int y_ant, int x, int y, t_sopa sopa)
{

	if(coord_valida(x,y,sopa))
	{

		if((x - x_ant) == -1)
		{
			if(((y - y_ant) == -1) || ((y - y_ant) == 1) || ((y - y_ant) == 0)) return 1;
		}
		if((x - x_ant) == 1)
		{
			if(((y - y_ant) == -1) || ((y - y_ant) == 1) || ((y - y_ant) == 0)) return 1;
		}
		if((x - x_ant) == 0)
		{
			if(((y - y_ant) == -1) || ((y - y_ant) == 1)) return 1;
		}
	}
	else return 0;
}





void jogar_cavalo(t_sopa sopa, DICIONARIO dic)
{
	int x, y, jogada, i=0, count1, count2, opcao=0, linha=0, sair = 0;
	char *palavra;
	int *coords[2];

	printf("Insira as coordenadas da primeira letra (x y)");
	scanf("%d %d", &x, &y);
	palavra[i]= sopa->linha[x][y];
	i++;
	
	while(sair == 0){
	printf("Escolha a próxima jogada. Pressione a tecla 0 para sair.");
	for(count1=0;count1<sopa->ncolunas;count1++)
		for(count2=0;count2<sopa->nlinhas;count2++)
			if(jogada_possivel_c(x,y,count1,count2, sopa))
			{
				coords[linha][1] = count1;
				coords[linha][2] = count2;
				linha++;
				opcao++;
				printf("%d. %c (%d,%d)\n", opcao, sopa->linha[count1][count2], count1, count2);
			}
	scanf("%d", &jogada);
	if(jogada == 0)
		sair = 1;
	else
	{
		x = coords[jogada-1][1];
		y = coords[jogada-1][2];
		palavra[i] = sopa->linha[x][y];
		i++;
	}
}
	if(palavra_existe(dic,palavra))
		printf("Parabéns, encontrou uma palavra!\n");
	else
		printf("A palavra que escolheu não se encontra no nosso dicionário. Tente novamente.");
}





int jogada_possivel_c(int x_ant, int y_ant, int x , int y, t_sopa sopa)
{
	if(coord_valida(x,y,sopa))
	{
	 if((x - x_ant) == -2)
	 {
	 	if(((y - y_ant) == -1) || ((y - y_ant) == 1)) return 1;
	 }	
	 if((x - x_ant) == 2)
	 {
	 	if(((y - y_ant) == -1) || ((y - y_ant) == 1)) return 1;
	 }
	 if((y - y_ant) == -2)
	 {
	 	if(((x - x_ant) == -1) || ((x - x_ant) == 1)) return 1;
	 }	
	 if((y - y_ant) == 2)
	 {
	 	if(((x - x_ant) == -1) || ((x - x_ant) == 1)) return 1;
	 }
	}
	else 
		return 0;
}



int coord_valida(int x, int y, t_sopa sopa)
{
	if ((x <= sopa->ncolunas) && (y <= sopa->nlinhas)) 
		return 1;
	else 
		return 0;
}