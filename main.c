#include <stdio.h>
#include "cadeias.h"

int main() {

	char s1[1000];
	char s2[2000];
	char c;
	int n=2;

	printf("Introduza a primeira string: ");
	scanf("%s", s1);
	printf("Introduza a segunda string: ");
	scanf("%s", s2);
	printf("Introduza um caracter: ");
	scanf(" %c",&c);


	printf("Querie 1\n");
	printf("S1 tamanho: %d  S2 tamanho: %d \n\n", cad_tamanho(s1), cad_tamanho(s2));

	printf("Querie 2\n");
	printf("char ocorre em S1 no indice: %d \n\n",cad_procurar_car(c,s1));
 
	printf("Querie 3\n");
	printf("ocorrencias do char em S1:%d \n\n",cad_ocorrencias(c,s1));

	printf("Querie 4\n");
	printf("indice em que s1 se encontra em s2:%d \n\n",cad_procurar_str(s1,s2));

	printf("Querie 5\n");
	printf("s1 é prefixo de s2? %d \n\n", cad_e_prefixo(s1,s2));

	printf("Querie 6\n");
	printf("s1 é sufixo de s2? %d\n\n", cad_e_sufixo(s1,s2));

	printf("Querie 7\n");
	printf("s1 e s2 sao iguais? %d \n\n", cad_iguais(s1,s2));

	printf("Querie 8\n");
	printf("s1 vem primeiro? %d \n\n", cad_primeiro(s1,s2));

	printf("Querie 9\n");
	printf("comparar s1 e s2 = %d \n\n", cad_comparar(s1,s2));

	printf("Querie 10\n");
	printf("indice em s1 que contem caracter de s2 = %d \n\n", cad_um_dos(s1,s2));

	printf("Querie 11\n");
	printf("indice em s1 onde nao há chars de s2: %d \n\n", cad_nenhum_dos(s1,s2));

	printf("Querie 12\n");
	cad_copiar(s1,s2);
	printf("S1 apos copiar: %s \n\n",s1);

	printf("Querie 13\n");
	cad_colar(s1,s2);
	printf("S1 após colar: %s \n\n",s1);

	printf("Querie 14\n");
	cad_mover(s1,s2,n);
	printf("S1 após mover: %s \n\n",s1);

	return 0;
}