#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct livros
{
  char titulo[30];
  char autor[40];
  int num;
  int ano;
}livros;
int main()
{
  FILE *arq = fopen("livros.bin", "wb");
  if(arq == NULL)
  {
    exit(1);
  }
  livros a;
  int num_livros=0;
  while(1)
  {
    scanf(" %[^\n]", a.titulo);
    if(strcmp(a.titulo, "saior")==0)
    {
      break;
    }
    scanf(" %[^\n]", a.autor);
    scanf("%d", &a.num);
    scanf("%d", &a.ano);

    fwrite(&a, sizeof(livros), 1, arq);
    num_livros++;
  }
  fclose(arq);

  int n;
  scanf("%d", &n);

  arq = fopen("livros.bin", "rb");
  if(arq == NULL)
  {
    exit(1);
  }

  while(n>0 && n<=num_livros)
  {
    fseek(arq, (n-1)*sizeof(livros), SEEK_SET);
    fread(&a, sizeof(livros), 1, arq);
    printf("%s %s %d %d", a.titulo, a.autor, a.ano, a.num);
  }
  fclose(arq);
  return 0;
}