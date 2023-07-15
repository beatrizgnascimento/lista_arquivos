#include <stdio.h>
typedef struct cidade
{
  char nome[40];
  int n;
}cidade;
int main()
{
  FILE *arq = fopen("arquivo.txt", "w");
  if(arq == NULL)
  {
    exit(1);
  }
  int i;
  cidade vetcidade[5];
 for(i = 0; i < 5; i++)
 {
  scanf("%d", &vetcidade[i].n);
  scanf("%d", vetcidade[i].nome);
  fprintf(arq, "%d\t%s", vetcidade[i].n, vetcidade[i].nome); 
 }
  fclose(arq);

  arq = fopen("arquivo.txt", "r");
  for(i = 0; i < 5; i++)
  {
    fscanf(arq, "%s", vetcidade[i].nome);
    fscanf(arq, "%d", &vetcidade[i].n );
  }

  for(i = 0; i < 5; i++)
  {
    printf("%s %d", vetcidade[i].nome, vetcidade[i].n);
  }

  fclose(arq);
  return 0;
}