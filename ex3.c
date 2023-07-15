#include <stdio.h>
int main()
{
  int num;
  scanf("%d", &num);
  float *v1 = (float*)malloc(num * sizeof(float));
  char **v2 = (char**)malloc(num * sizeof(char*));
  if(v1 == NULL || v2 == NULL)
  {
    exit(1);
  }

  int i;
  for(i = 0; i < num; i++)
  {
    v2 = (char*)malloc(40*sizeof(char));
    if(v2[i] == NULL)
    {
      exit(1);
    }
  }
   FILE *arq = fopen("arq.txt", "w");
   if(arq == NULL)
   {
    exit(1);
   }

   for(i = 0; i < num; i++)
   {
    fprintf(arq, "%s %.2f", v2[i], v1[i]);
   }
  fclose(arq);

  free(v1);
  free(v2);
  return 0;
}