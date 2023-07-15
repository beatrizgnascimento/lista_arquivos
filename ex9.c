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
  int i;
  for(i = 0; i < num_livros; i++)
  {
    fseek(arq, i*sizeof(livros), SEEK_SET);
    fread(&a, sizeof(livros), 1, arq);
    if((i + 1)==n)
    {
      printf("%s %s %d %d", a.titulo, a.autor, a.ano, a.num);
      break;
    }
    
  }
  fclose(arq);

  arq = fopen("livros.bin", "rb");
  if(arq == NULL)
  {
    exit(1);
  }

  livros *vetlivros = (livros*)malloc(num_livros * sizeof(livros));
  if(vetlivros == NULL)
  {
    exit(1);
  }

  
  fread(&a, sizeof(livros), num_livros, arq);
  int i;
  for(i = 0; i < num_livros; i++)
  {
    printf("%s", vetlivros[i].titulo);
    printf("%s", vetlivros[i].autor);
    printf("%d", vetlivros[i].ano);
    printf("%d", vetlivros[i].num);
  }
  fclose(arq);
  free(vetlivros);
  return 0;
}