#include "cadeias.h"
#include <stdlib.h>


  int cad_tamanho (char s[]){
	 int size=0;
	 while(s[size]!='\0')
	   	size++;
	 return size;
  }

  int cad_procurar_car ( char c , char s []){
    	int i=0;
  	 if(cad_ocorrencias(c,s) == 0) return -1;
  	 while((s[i]!='\0') && (s[i]!=c))
  	    		i++;
	 return i;
    }

  int cad_ocorrencias ( char c , char s []){
  	int i=0, how_many=0;
  	while( s[i]!='\0'){
  		if(s[i] == c) how_many++;
  		i++;
  	}
  	return how_many;
  }


  int cad_procurar_str ( char s1 [] , char s2 [])
  {
  int i, j;
  for(i = 0; s2[i] != '\0'; ++i) {
    int found = 1;
    for(j = 0; s1[j] != '\0'; ++j) {
      if (s2[i+j] != s1[j])
        found = 0;
    }

    if (found)
      return i;
  }

  return -1;
}

  int cad_e_prefixo (char s1[], char s2[]){
  int i=0,flag=1;
  while((s1[i] != '\0') && (s2[i] != '\0') && (flag == 1)) 
    {
    if (s1[i] != s2[i]) flag = 0;
    i++;
    }
  return flag;
  }


  int cad_e_sufixo ( char s1 [] , char s2 []){
    int i=cad_tamanho(s1),j=cad_tamanho(s2);
    while(s1[i]>=0){
      if(s1[i]!=s2[j]) return 0;
      i--;
      j++;
    }
    return 1;
  }



  int cad_iguais (char s1[], char s2[]){
  int i=0;
  int flag=1;
  if(cad_tamanho(s1)==cad_tamanho(s2)) 
	 while((s1[i] != '\0') && (flag == 1)) 
	   	{
		  if (s1[i] != s2[i]) flag = 0;
		  i++;
		  }
  else flag=0;
  return flag;
  }


  int cad_primeiro (char s1 [] , char s2 []){
    int i;
    if(cad_iguais(s1,s2)) return 0;
    else{
    for(i=0;(s1[i]!='\0')&&(s2[i]!='\0');i++)
      if(s1[i]>s2[i]) return 0;
  }
    return 1;
  }


  int cad_comparar ( char s1 [] , char s2 []){

    if(cad_primeiro(s1,s2)) return -1;
    else
      if(cad_iguais(s1,s2)) return 0;
      else return 1;
  }


  int cad_um_dos ( char s1 [] , char s2 []){
    int i, j;
  for(i = 0; s1[i] != '\0'; ++i) {
    for(j = 0; s2[j] != '\0'; ++j) {
      if (s1[i] == s2[j])
        return i;
    }
  }
  return -1;
}


  int cad_nenhum_dos ( char s1 [] , char s2 []){
  int i=0, index=-1;
  while(s1[i]!='\0'){
    if(cad_ocorrencias(s1[i],s2)==0){
      index = i;
      break;
    }
    i++;
  }
  return index;
  }


  void cad_copiar ( char s1 [] , char s2 []){
    int i=0;
    while(s2[i]!='\0'){
      s1[i]=s2[i];
      i++;
    }
    s1[i]='\0';
  }


   void cad_colar ( char s1 [] , char s2 []){
   int i=cad_tamanho(s1), j=0;
   while(s2[j]!='\0'){
    s1[i]=s2[j];
    i++;
    j++;
   }
   s1[i]='\0';
  }

  void cad_mover ( char m1 [] , char m2 [] , int n ) 
{
  int i;
  for(i = 0; i < n; ++i) {
    m1[i] = m2[i];
  }
}

