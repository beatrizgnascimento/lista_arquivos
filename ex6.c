#include <stdio.h>
#include <stdlib.h>
typedef struct haikyuu
{
  char nome[50];
  int idade;
  float altura;
}haikyuu;

int main()
{
  haikyuu *vet = (haikyuu*)malloc(5 * sizeof(haikyuu));
  int i;
  if(vet == NULL)
  {
    exit(1);
  }
  for(i = 0; i < 5; i++)
  {
    scanf(" %[^\n]", (vet+i)->nome);
    scanf("%d", &(vet+i)->idade);
    scanf("%f", &(vet+i)->altura);
  }
  FILE *arq = fopen("meusmaridos.bin", "wb");
  if(arq == NULL)
  {
    exit(1);
  }
  fwrite(vet, sizeof(haikyuu), 5, arq);
  fclose(arq);
  return 0;
}