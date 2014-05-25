#ifndef _HASH_TABLE_H

#define _HASH_TABLE_H 1

/**
 * Elemento de uma tabela de hash
 */
typedef struct hash_elem {
	//long long int key;                /**< Chave do elemento guardado */
	void *data;             /**< Apontador para os dados guardados */
	struct hash_elem *next; /**< Apontador para o proximo elemento (hash table usando o metodo de chaining) */
} *HashElem;

/**
 * Estrutura de uma tabela de hash
 */
typedef struct hash_table {
	int useCount;                       /**< Total de elementos guardados na tabela */
	int totalCount;                     /**< Numero maximo de elementos suportados */
	int (*hashFunction)(void *, int);   /**< Apontador para a funcao de hash */
	void *(*getKey)(void *);            /**< Funcao que extrai a chave */
	int (*compareKeys)(void *, void *); /**< Funcao que compara duas chaves */
        int duplicate;                      /**< Indica se a tabela aceita valores duplicados */
	HashElem *table;                    /**< Apontador para a tabela */
} HashTableStruct, *HashTable;

/**
 * @fn Hash_Create
 * @brief Data uma tabela de hash, inicia-a dando um tamanho inicial ao array
 * 
 * @param maxCount indica o tamanho inicial do array
 * @return Apontador para a nova tabela de hash
 */
HashTable Hash_Create(int maxCount, int (*hashFunction)(void *, int), void *(*getKey)(void *), int (*compareKeys)(void *, void *), int duplicate);

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
int Hash_Insert(HashTable hashT, void *data);

/** 
 * @fn Hash_Remove
 * @brief Remove um bloco da tabela, com base na chave
 * 
 * @param hashT Tabela a utilizar
 * @param key Chave para identificar os dados a remover
 * @return Apontador para os dados removidos, caso se decida fazer free
 */
void *Hash_Remove(HashTable hashT, void *key);

/** 
 * @fn Hash_Search
 * @brief Procura um elemento numa tabela
 * 
 * @param hashT Tabela a pesquisar
 * @param key Chave a utilizar
 * @return Apontador para os dados encontrados, ou NULL se nao existirem
 */
void *Hash_Search(HashTable hashT, void *key);

/** 
 * @fn Hash_ClearAll
 * @brief Elimina a tabela e tudo por ela apontado
 * 
 * @param hashT Tabela a eliminar
 * @return 0 em caso de sucesso
 */
int Hash_ClearAll(HashTable hashT);

/** 
 * @fn Hash_ApplyToAll
 * @brief Aplica uma funcao a todos os elementos da tabela de hash
 * 
 * @param hashT Tabela a usar
 * @param function Funcao a aplicar
 * @return 0 em caso de sucesso
 */
int Hash_ApplyToAll(HashTable hashT, int (*function)(void *, void *, void *), void *params);

/** 
 * @fn Elem_Insert
 * @brief Insere um novo elemento na lista
 *
 * @param hashT Tabela de hash a inserir
 * @param elem Lista de dados
 * @param data Apontador para os dados a inserir
 * @param key Chave indentificar os elementos
 * @return 0 em caso de sucesso
 */
int Elem_Insert(HashTable hashT, HashElem *elem, void *data);

#endif
