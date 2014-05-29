#include "cadeias.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

typedef struct tabela_sopa
{
	int nlinhas;
	int ncolunas;
	char **linha;
}*t_sopa;

typedef char** DICIONARIO;

/**
 * @fn criar_dicionario
 * @brief cria uma tabela de hash com o dicionario que nos foi fornecido
 * 
 * @param ficheiro nome do ficheiro onde se encontra o dicionario
 * @return a estrutura com o respectivo dicionário
 */
DICIONARIO criar_dicionario (char *ficheiro);

/**
 * @fn palavra_existe
 * @brief verifica se uma palavra existe no dicionário
 * 
 * @param dic estrutura com o dicionário onde se vai efetuar a procura
 * @palavra palavra que se quer encontrar
 * @return 0 se não existir, 1 caso contrário
 */
int palavra_existe(DICIONARIO dic, char * palavra);

/**
 * @fn jogar
 * @brief Permite ao utilizador escolher o modo de jogo (serpente ou cavalo) e jogar nesse modo
 * 
 * @param ficheiro Nome do ficheiro onde se encontra a sopa de letras com que se vai jogar
 * @return void
 */
void jogar(char *ficheiro, DICIONARIO dic);

/**
 * @fn jogar_serpente
 * @brief Permite jogar no modo serpente
 * 
 * @param sopa Estrutura com a sopa de letras em que se está a jogar
 * @return void
 */
void jogar_serpente(t_sopa sopa, DICIONARIO dic);

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
int jogada_possivel_s(int x_ant, int y_ant, int x, int y, t_sopa sopa);

/**
 * @fn jogar_cavalo
 * @brief Permite jogar no modo cavalo
 * 
 * @param sopa Estrutura com a sopa de letras em que se está a jogar
 * @return void
 */
void jogar_cavalo(t_sopa sopa, DICIONARIO dic);

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
int jogada_possivel_c(int x_ant, int y_ant, int x , int y, t_sopa sopa);

/**
* @fn coord_valida
* @brief Determina se um par de coordenadas existe numa sopa de letras
* @param x valor da abcissa que se quer analisar
* @param y valor da ordenada que se quer analisar
* @param sopa estrutura da sopa que está a ser analisada
* @return 1 se for válida, 0 caso contrário
*/
int coord_valida(int x, int y, t_sopa sopa);



