#ifndef _HASH_TABLE_H

#define _HASH_TABLE_H 1

/**
 * Elemento de uma tabela de hash
 */
typedef struct hash_elem {
	char *data;             /**< Apontador para os dados guardados */
	struct hash_elem *next; /**< Apontador para o proximo elemento (hash table usando o metodo de chaining) */
} *HashElem;

/**
 * Estrutura de uma tabela de hash
 */
typedef struct hash_table {
	int size;                       /**< Total de elementos guardados na tabela */
	int array_size;                     /**< Numero maximo de elementos suportados */
	HashElem *table;                    /**< Apontador para a tabela */
} HashTableStruct, *HashTable;

/**
 * @fn Hash_Create
 * @brief Dada uma tabela de hash, inicia-a dando um tamanho inicial ao array
 * 
 * @param maxCount indica o tamanho inicial do array
 * @return Apontador para a nova tabela de hash
 */
HashTable Hash_Create(int maxCount);

/** 
 * @fn Hash_IsFull
 * @brief Indica se uma tabela esta com taxa de uso acima dos 80%, altura em que e aconselhavel expandi-la
 * 
 * @param hashT Tabela a utilizar
 * @return 1 se a tabela estiver acima dos 80% de utilizacao, e 0 caso contrario
 */
int Hash_IsFull(HashTable hashT);

/** 
 * @fn Hash_Expand
 * @brief Expande a tabela, duplicando o seu tamanho, e re-organizando a informacao contida
 * 
 * @param hashT Tabela a expandir
 * @return 0 em caso de sucesso
 */
int Hash_Expand(HashTable hashT);

/** 
 * @fn Hash_Insert
 * @brief Insere um bloco de informacao na tabela. Se a chave ja existir, a informacao e substituida
 * 
 * @param hashT Tabela a utilizar
 * @param data Dados a inserir
 * @return 0 em caso de sucesso, diferente de 0 em caso de erro
 */
void Hash_Insert(HashTable hashT, char *data);

/** 
 * @fn Hash_Search
 * @brief Procura um elemento numa tabela
 * 
 * @param hashT Tabela a pesquisar
 * @param key Chave a utilizar
 * @return Apontador para os dados encontrados, ou NULL se nao existirem
 */
char *Hash_Search(HashTable hashT, char *key);

#endif
