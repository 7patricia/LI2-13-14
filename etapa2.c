#include "cadeias.h"
#include "etapa2.h"

//Função para ver se uma palavra existe no dicionário

int palavra_existe(DICIONARIO dic, char [] palavra)
{
	char *aleatorio;
	return cad_iguais(aleatorio, palavra);

}

void jogar(char *ficheiro)
{
	int x, y, i, j;
	char modo;
	tabela_sopa sopa = (tabela_sopa)malloc(sizeof(struct tabela_sopa));

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
	void jogar_serpente(tabela_sopa sopa)
	{

	}


//Função para jogar no modo cavalo
	void jogar_cavalo(tabela_sopa sopa)
	{
		int x, y, jogada, i=0;
		char *palavra;

		printf("Insira as coordenadas da primeira letra (x y)");
		scanf("%d %d", x, y);
		palavra[i]= sopa.linhas[x][y];
		i++;
		printf("Escolha a próxima jogada.");
		printf("LISTA DE JOGADAS VALIDAS");
		scanf("%d", jogada);

	}

	
	int coord_valida(int x, int y, tabela_sopa sopa)
	{
		if ((x <= sopa.ncolunas) && (y<= sopa.nlinhas)) 
			return 1;
		else 
			return 0;
	}

	int jogada_possivel(int x_ant, int y_ant, int x , int y)
	{
		if(coord_valida(x,y,sopa))
		{
			
		}
		else 
			return 0;
	}