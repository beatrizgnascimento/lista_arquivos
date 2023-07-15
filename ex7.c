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

  int maisvelho = 0;
  float maisalto = 0;
  int idx1, idx2;
  for(i = 0; i < 5; i++)
  {
    if((vet+i)->idade > maisvelho)
    {
      maisvelho = (vet+i)->idade;
      idx1=i;
    }
    if((vet+i)->altura > maisalto)
    {
      maisalto = (vet+i)->altura;
      idx2 = i;
    }
  }
  FILE *arq = fopen("meusmaridos.bin", "wb");
  if(arq == NULL)
  {
    exit(1);
  }
  fwrite(vet, sizeof(haikyuu), 5, arq);
  fclose(arq);

  arq = fopen("meusmaridos.bin", "rb");
  if(arq == NULL)
  {
    exit(1);
  }
  fseek(arq, sizeof(haikyuu) * idx1, SEEK_SET);
  fread(&(vet[idx1]), sizeof(haikyuu), 1, arq);
  fseek(arq, sizeof(haikyuu) * idx2, SEEK_SET);
  fread(&(vet[idx2]), sizeof(haikyuu), 1, arq);
  fclose(arq);
  printf("%s", vet[idx1].nome);
  printf("%s", vet[idx2].nome);
  return 0;
}