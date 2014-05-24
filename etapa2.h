#include "etapa2.h"
#include "cadeias.h"
#include <stdlib.h>

typedef struct tabela_sopa
{
	int nlinhas;
	int ncolunas;
	char linha[ncolunas][nlinhas];
}tabela_sopa;


typedef struct chain 
{


}

typedef struct tabela
{
	int tamanho;
	int preenchidos;
	chain array;

}


typedef struct lista 
{

	char *palavra;
	struct lista *seguinte;

} lista;