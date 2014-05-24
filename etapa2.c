#include "cadeias.h"
#include "etapa2.h"
// #include "hash.c"

//Função para ver se uma palavra existe no dicionário

// int palavra_existe(DICIONARIO dic, char [] palavra)
// {
// 	char *aleatorio;
// 	return cad_iguais(aleatorio, palavra);

// }



//Função p/ tarefa 4
void jogar(char *ficheiro)
{
	int x, y, i, j;
	char modo;
	t_sopa sopa = (t_sopa)malloc(sizeof(struct tabela_sopa));

	FILE *fp;
	fp = fopen(ficheiro,r);
	fscanf(fp,"%d",x);
	fscanf(fp, "%d",y);
	sopa.nlinhas = y;
	sopa.ncolunas = x;


	for(i=0;i<x;i++)
		for(j=0;j<y;j++)
			fscanf(fp,"%c",sopa.linhas[i][j]);
	

	printf("Quer jogar no modo serpente ou cavalo?\n");
	scanf("%s", modo);
	while(!(cad_iguais(modo,"serpente") || cad_iguais(modo,"cavalo")){
		printf("Opção inválida. Digite serpente ou cavalo.")
		scanf("%s", modo);
	}
	if(cad_iguais(modo,"serpente")) 
	 	jogar_serpente(sopa);
	
	else 
		jogar_cavalo(sopa);
	
	}	


//Função para jogar no modo serpente
	void jogar_serpente(t_sopa sopa)
	{
		int x, y, jogada, i=0, count1, count2, opcao=0, linha=0, sair = 0;
		char *palavra;
		int *coords[2];

		printf("Insira as coordenadas da primeira letra (x y)");
		scanf("%d %d", x, y);
		palavra[i]= sopa.linhas[x][y];
		i++;
		
		while(sair == 0){
		printf("Escolha a próxima jogada. Pressione a tecla 0 para sair.");
		for(count1=0;count1<ncolunas;count1++)
			for(count2=0;count2<nlinhas;count2++)
				if(jogada_possivel_c(x,y,count1,count2))
				{
					coords[linha][1] = count1;
					coords[linha][2] = count2;
					linha++;
					opcao++;
					printf("%d. %c (%d,%d)\n", opcao, sopa.linha[i][j], i, j);
				}
		scanf("%d", jogada);
		if(jogada == 0)
			sair = 1;
		else
		{
			x = coords[jogada-1][1];
			y = coords[jogada-1][2];
			palavra[i] = sopa.linhas[x][y];
			i++;
		}
	}
		if(palavra_existe(dic,palavra))
			printf("Parabéns, encontrou uma palavra!\n");
		else
			printf("A palavra que escolheu não se encontra no nosso dicionário. Tente novamente.")
	}



	int jogada_possivel_s(int x_ant, int y_ant, int x, int y)
	{

		if(coord_valida(x,y,sopa))
		{

			if(x - x_ant == -1)
			{
				if((y - y_ant == -1) || (y - y_ant == 1) || (y - y_ant == 0)) return 1;
			}
			if(x - x_ant == 1)
			{
				if((y - y_ant == -1) || (y - y_ant == 1) || (y - y_ant == 0)) return 1;
			}
			if(x - x_ant == 0)
			{
				if((y - y_ant == -1) || (y - y_ant == 1)) return 1;
			}
		}
		else return 0;
	}


//Função para jogar no modo cavalo
	void jogar_cavalo(t_sopa sopa)
	{
		int x, y, jogada, i=0, count1, count2, opcao=0, linha=0, sair = 0;
		char *palavra;
		int *coords[2];

		printf("Insira as coordenadas da primeira letra (x y)");
		scanf("%d %d", x, y);
		palavra[i]= sopa.linhas[x][y];
		i++;
		
		while(sair == 0){
		printf("Escolha a próxima jogada. Pressione a tecla 0 para sair.");
		for(count1=0;count1<ncolunas;count1++)
			for(count2=0;count2<nlinhas;count2++)
				if(jogada_possivel_c(x,y,count1,count2))
				{
					coords[linha][1] = count1;
					coords[linha][2] = count2;
					linha++;
					opcao++;
					printf("%d. %c (%d,%d)\n", opcao, sopa.linha[i][j], i, j);
				}
		scanf("%d", jogada);
		if(jogada == 0)
			sair = 1;
		else
		{
			x = coords[jogada-1][1];
			y = coords[jogada-1][2];
			palavra[i] = sopa.linhas[x][y];
			i++;
		}
	}
		if(palavra_existe(dic,palavra))
			printf("Parabéns, encontrou uma palavra!\n");
		else
			printf("A palavra que escolheu não se encontra no nosso dicionário. Tente novamente.")
	}


	int jogada_possivel_c(int x_ant, int y_ant, int x , int y)
	{
		if(coord_valida(x,y,sopa))
		{
		 if(x - x_ant == -2)
		 {
		 	if((y - y_ant = -1 || y - yant == 1)) return 1;
		 }	
		 if(x - x_ant == 2)
		 {
		 	if((y - y_ant = -1 || y - yant == 1)) return 1;
		 }
		 if(y - y_ant == -2)
		 {
		 	if((x - x_ant = -1 || x - xant == 1)) return 1;
		 }	
		 if(y - y_ant == 2)
		 {
		 	if((x - x_ant = -1 || x - xant == 1)) return 1;
		 }
		}
		else 
			return 0;
	}

	int coord_valida(int x, int y, t_sopa sopa)
	{
		if ((x <= sopa.ncolunas) && (y <= sopa.nlinhas)) 
			return 1;
		else 
			return 0;
	}