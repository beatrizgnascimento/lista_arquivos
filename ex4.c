#include <stdio.h>
#include <time.h>
int main()
{
  srand(time(NULL));
  int *num = (int*)malloc(100 * sizeof(int));
  if(num == NULL)
  {
    exit(1);
  }
  int i;
  for(i = 0; i < 100; i++)
  {
    num[i] = 1 + rand() % 1000;
  }

  FILE *arq = fopen("arq.bin", "wb");
  if(arq == NULL)
  {
    exit(1);
  }

  fwrite(num, sizeof(int), 100, arq); //em arquivos binarios usamos fwrite
  fclose(arq);
  free(num);
  return 0;
}