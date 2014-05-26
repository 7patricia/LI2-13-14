#include "cadeias.h"
#include "etapa2.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @fn palavra_existe
 * @brief verifica se uma palavra existe no dicionário
 * 
 * @param dic estrutura com o dicionário onde se vai efetuar a procura
 * @palavra palavra que se quer encontrar
 * @return 0 se não existir, 1 caso contrário
 */

// int palavra_existe(DICIONARIO dic, char [] palavra)
// {
// 	char *aleatorio;
// 	return cad_iguais(aleatorio, palavra);

// }


/**
 * @fn jogar
 * @brief Permite ao utilizador escolher o modo de jogo (serpente ou cavalo) e jogar nesse modo
 * 
 * @param ficheiro Nome do ficheiro onde se encontra a sopa de letras com que se vai jogar
 * @return void
 */
void jogar(char *ficheiro)
{

	int x, y, i, j;
	char *modo;
	tsopa sopa = (tsopa)malloc(sizeof(tsopa));

	FILE *fp;
	fp = fopen(ficheiro,"r");
	fscanf(fp,"%d",x);
	fscanf(fp, "%d",y);
	sopa.nlinhas = y;
	sopa.ncolunas = x;


	for(i=0;i<x;i++)
		for(j=0;j<y;j++)
			fscanf(fp,"%c",sopa.linha[i][j]);


	printf("Quer jogar no modo serpente ou cavalo?\n");
	scanf("%s", modo);
	while(!(cad_iguais(modo,"serpente")) && !(cad_iguais(modo,"cavalo")))
	{
		printf("Opção inválida. Digite serpente ou cavalo.");
		scanf("%s", modo);
	}
	if(cad_iguais(modo,"serpente")) 
	 	jogar_serpente(sopa);
	
	else 
		jogar_cavalo(sopa);
	
	}	


/**
 * @fn jogar_serpente
 * @brief Permite jogar no modo serpente
 * 
 * @param sopa Estrutura com a sopa de letras em que se está a jogar
 * @return void
 */


	void jogar_serpente(tsopa sopa)
	{
		int x, y, jogada, i=0, count1, count2, opcao=0, linha=0, sair = 0;
		char *palavra;
		int *coords[2];

		printf("Insira as coordenadas da primeira letra (x y)");
		scanf("%d %d", x, y);
		palavra[i]= sopa.linha[x][y];
		i++;
		
		while(sair == 0){
		printf("Escolha a próxima jogada. Pressione a tecla 0 para sair.");
		for(count1=0;count1<ncolunas;count1++)
			for(count2=0;count2<nlinhas;count2++)
				if(jogada_possivel_c(x,y,count1,count2,sopa))
				{
					coords[linha][1] = count1;
					coords[linha][2] = count2;
					linha++;
					opcao++;
					printf("%d. %c (%d,%d)\n", opcao, sopa.linha[count1][count2], count1, count2);
				}
		scanf("%d", jogada);
		if(jogada == 0)
			sair = 1;
		else
		{
			x = coords[jogada-1][1];
			y = coords[jogada-1][2];
			palavra[i] = sopa.linha[x][y];
			i++;
		}
	}
		// if(palavra_existe(dic,palavra))
		// 	printf("Parabéns, encontrou uma palavra!\n");
		// else
		// 	printf("A palavra que escolheu não se encontra no nosso dicionário. Tente novamente.");
	}


/**
 * @fn jogada_possivel_s
 * @brief Determina se um par de coordenadas corresponde a uma jogada possivel
 * no modo serpente
 * 
 * @param x_ant valor da abcissa da letra escolhida anteriormente
 * @param y_ant valor da ordenada da letra escolhida anteriormente
 * @param x valor da abcissa da jogada que se pretende analisar
 * @param y valor da ordenada da jogada que se pretende analisar
 * @return 1 se for possível, 0 caso contrário
 */
	int jogada_possivel_s(int x_ant, int y_ant, int x, int y, tsopa sopa)
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



/**
 * @fn jogar_cavalo
 * @brief Permite jogar no modo cavalo
 * 
 * @param sopa Estrutura com a sopa de letras em que se está a jogar
 * @return void
 */

	void jogar_cavalo(tsopa sopa)
	{
		int x, y, jogada, i=0, count1, count2, opcao=0, linha=0, sair = 0;
		char *palavra;
		int *coords[2];

		printf("Insira as coordenadas da primeira letra (x y)");
		scanf("%d %d", x, y);
		palavra[i]= sopa.linha[x][y];
		i++;
		
		while(sair == 0){
		printf("Escolha a próxima jogada. Pressione a tecla 0 para sair.");
		for(count1=0;count1<ncolunas;count1++)
			for(count2=0;count2<nlinhas;count2++)
				if(jogada_possivel_c(x,y,count1,count2, sopa))
				{
					coords[linha][1] = count1;
					coords[linha][2] = count2;
					linha++;
					opcao++;
					printf("%d. %c (%d,%d)\n", opcao, sopa.linha[count1][count2], count1, count2);
				}
		scanf("%d", jogada);
		if(jogada == 0)
			sair = 1;
		else
		{
			x = coords[jogada-1][1];
			y = coords[jogada-1][2];
			palavra[i] = sopa.linha[x][y];
			i++;
		}
	}
		// if(palavra_existe(dic,palavra))
		// 	printf("Parabéns, encontrou uma palavra!\n");
		// else
		// 	printf("A palavra que escolheu não se encontra no nosso dicionário. Tente novamente.");
	}


/**
 * @fn jogada_possivel_c
 * @brief Determina se um par de coordenadas corresponde a uma jogada possivel
 * no modo cavalo
 * 
 * @param x_ant valor da abcissa da letra escolhida anteriormente
 * @param y_ant valor da ordenada da letra escolhida anteriormente
 * @param x valor da abcissa da jogada que se pretende analisar
 * @param y valor da ordenada da jogada que se pretende analisar
 * @param sopa estrutura da sopa de letras que está a ser analisada
 * @return 1 se for possível, 0 caso contrário
 */


	int jogada_possivel_c(int x_ant, int y_ant, int x , int y, tsopa sopa)
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

/**
* @fn coord_valida
* @brief Determina se um par de coordenadas existe numa sopa de letras
* @param x valor da abcissa que se quer analisar
* @param y valor da ordenada que se quer analisar
* @param sopa estrutura da sopa que está a ser analisada
* @return 1 se for válida, 0 caso contrário
*/

	int coord_valida(int x, int y, tsopa sopa)
	{
		if ((x <= sopa.ncolunas) && (y <= sopa.nlinhas)) 
			return 1;
		else 
			return 0;
	}