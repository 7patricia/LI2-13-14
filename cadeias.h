
/**
  * cad_tamanho
  * \brief Calcular o tamanho de uma string s1
  * \param s String da qual se vai calcular o tamanho
  * \var size Inicia a 0 e incrementa a cada iteração do ciclo
  * \return size Tamanho da string
  */
int cad_tamanho ( char s []);

/**
  * cad_procurar_car
  * \brief Procurar um caractere c numa string s e devolver o primeiro índice onde ele se encontra
  * \param c Caracter a ser procurado
  * \param s String na qual se vai porcurar o caracter
  * \var i inicia a 0 e incrementa a cada iteração do ciclo até encontrar o caractér pretendido
  * \return i indice se for encontrado, -1 caso contrário
  */

int cad_procurar_car ( char c , char s []);

/**
  * cad_ocorrencias
  * \brief Contar o número de ocorrências de um caractere c numa string s
  * \param c Caracter cujas ocorrências vão ser calculadas
  * \param s String onde se vai procurar o caracter
  * \var i inicia a 0 e incrementa a cada iteração do ciclo
  * \var how_many inicia a 0 e incrementa a cada caracter igual ao pedido que encontra
  * \return O numero de caracteres iguais que encontrou
  */

int cad_ocorrencias ( char c , char s []);


/**
  * cad_procurar_str
  * \brief Devolver o primeiro índice em que uma string s1 se encontra dentro de outra string s2
  * \param s1 Primeira string
  * \param s2 Segunda string
  * \return i se encontrar, -1 caso contrário
  */

int cad_procurar_str ( char s1 [] , char s2 []);

/**
  * cad_e_prefixo
  * \brief Verificar se uma string s1 é prefixo de outra string s2
  * \param s1 Primeira string
  * \param s2 Segunda string
  * \return flag Tem o valor 0 se não for prefixo, 1 caso contrário
  */
int cad_e_prefixo ( char s1 [] , char s2 []);


/**
  * cad_e_sufixo
  * \brief Verificar se uma string s1 é sufixo de outra string s2
  * \param s1 Primeira String
  * \param s2 Segunda String
  * \return 0 ou 1, se não for ou for sufixo respetivamente
  */

int cad_e_sufixo ( char s1 [] , char s2 []);

/**
  * cad_iguais 
  * \brief Verificar se duas strings s1 e s2 são iguais
  * \param s1 Primeira string
  * \param s2 Segunda string
  * \return flag Tem o valor 0 se não forem iguais, 1 caso contrário
  */
int cad_iguais ( char s1 [] , char s2 []);

/**
  * cad_primeiro
  * \brief Verificar se uma string s1 é menor do que uma string s2
  * \param s1 Primeira string
  * \param s2 Segunda String
  * \return 1 se for menor, 0 caso contrário
  */
int cad_primeiro ( char s1 [] , char s2 []);

/**
  * cad_comparar
  * \brief Comparar duas strings pela sua ordem lexicográfica
  * \param s1 Primeira string
  * \param s2 Segunda string
  * \return -1 se s1 for menor, 1 se s2 for menor, 0 se forem iguais
  */
int cad_comparar ( char s1 [] , char s2 []);

/**
  * cad_um_dos
  * \brief Procura o primeiro índice em s1 que contém um dos caracteres na string s2
  * \param s1 Primeira string
  * \param s2 Segunda string
  * \return i Indice que contem o caracter ou -1 se o caracter nao existir
  */
int cad_um_dos ( char s1 [] , char s2 []);

/**
  * cad_nenhum_dos
  * \brief Procura o primeiro índice em s1 que não contém um dos caracteres na string s2
  * \param s1 Primeira string
  * \param s2 Segunda string
  * \return i Indice que nao contem nenhum caracter de s2 ou -1 se isso nao acontecer
  */
int cad_nenhum_dos ( char s1 [] , char s2 []);

/**
  * cad_copiar
  * \brief Copiar para s1 a string s2
  * \param s1 Primeira string
  * \param s2 Segunda String

  */

void cad_copiar ( char s1 [] , char s2 []);

  /**
  * cad_colar
  * \brief Colar s2 ao fim da string s1
  * \param s1 Primeira string
  * \param s2 Segunda string
  */

void cad_colar ( char s1 [] , char s2 []);

  /**
  * cad_mover Mover n bytes da área m2 para a área m1 (esta função deverá funcionar mesmo que m1 e m2
partilhem memória)
  * \brief
  * \param m1 área 1
  * \param m2 área 2
  * \param n número de bytes a serem movidos
  */
void cad_mover ( char m1 [] , char m2 [] , int n );
