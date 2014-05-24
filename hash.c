 #include <stdio.h>
 #include <stdlib.h>
 
 
 struct node{
	char word[30];
	struct node *next;
 } *Node;
 
 struct table{
	int size;
	struct node **tab;
 } *HashTable;
 
 Node createNode(char *word){
	Node newnode = (Node)malloc(sizeof(struct node));
	strcpy(newnode->string,word);
	newnode->next=NULL
	return newnode;
 }
 
 HashTable createHTable(int size){
	HashTable newTable;
	if (size < 1) return NULL
	
	newTable = (HashTable)malloc(sizeof(struct table));
	newTable->tab = (Node)malloc(sizeof(struct node)*size);
	for(int i=0; i<size; i++) newTable->tab[i] = NULL;
	newTable->size = size;
 
	return newTable;
 }
 
 
 void insertToHash(HashTable ht, char* word){
	
	
	int hashval = hashFunc(ht, word);
	
	Node n = createNode(word);
	strcpy(n->word,word);
	n->next = ht->tab[hashval];
	ht->tab[hashval] = n;
 
 }
 
 int searchInHash(HashTable ht, char* word){
 
	int hashval = hashFunc(ht, word);
	
	Node n = ht->tab[hashval];  
	
	while(n){
		if(strcmp(n->word,word))
			return 1;
		n = n->next;
		}
		
	return 0;
 }
 
 int hashFunc(HashTable ht, char * word){
 
	for()
		hashval = ;
 
	return hashval % hashtable->size;
 }