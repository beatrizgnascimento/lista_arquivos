#include <stdio.h>
typedef struct pessoa
{
  char nome[30];
  int dia, mes, ano;
  int idade;
}pessoa;
int main()
{
  char nomearq[100];
  scanf(" %[^\n]", nomearq);

  FILE *arq = fopen(nomearq, "w");
  pessoa vetpessoa[5];
  int i, dia, mes, ano;
 
  for(i = 0; i < 5; i++)
  {
    scanf(" %[^\n]", vetpessoa[i].nome);
    scanf("%d %d %d", &vetpessoa[i].dia, &vetpessoa[i].mes, &vetpessoa[i].ano);
    fprintf(arq, "%s\t%d\t%d\t%d\n", vetpessoa[i].nome, vetpessoa[i].dia, vetpessoa[i].mes, vetpessoa[i].ano); 
  } 
  fclose(arq);

  arq = fopen(nomearq, "r");
  
  scanf("%d %d %d", &dia, &mes, &ano);
  
  for(i = 0; i < 5; i++)
  {
    fscanf(arq, "%s %d %d %d", vetpessoa[i].nome, &vetpessoa[i].dia, &vetpessoa[i].mes, &vetpessoa[i].ano);
    vetpessoa[i].idade = ano - vetpessoa[i].ano;
  }
  fclose(arq);

  arq = fopen(nomearq, "w");
  for(i = 0; i < 5; i++)
  {
    fprintf(arq, "%s\t%d/%d/%d\t%d\n", vetpessoa[i].nome, vetpessoa[i].dia, vetpessoa[i].mes, vetpessoa[i].ano, vetpessoa[i].idade);
  }
 
  fclose(arq);
  return 0;
}