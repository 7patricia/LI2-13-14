#include <stdlib.h>
#include <stdio.h>

typedef char* Linha;
typedef Linha* Tab;

void ignorar_espacos() {
  scanf("%*[ \n\t]");
}

int main() {
  int sizeX, sizeY, i, j;
  scanf("%d", &sizeX);
  scanf("%d", &sizeY);
  ignorar_espacos();

  Tab tab = (Tab) malloc(sizeof(Linha) * sizeX);
  for(i = 0; i < sizeX; ++i) {
    tab[i] = (Linha) malloc(sizeof(char) * sizeY);

    for(j = 0; j < sizeY; ++j) {
      scanf("%c", &tab[i][j]);
      ignorar_espacos();
    }
  }

  int coord_count;
  scanf("%d\n", &coord_count);

  for(i = 0; i < coord_count; ++i) {
    int x, y;
    scanf("%d\n", &x);
    scanf("%d\n", &y);

    printf("%c", tab[x-1][y-1]);
  }
  printf("\n");
}