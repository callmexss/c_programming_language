#include <stdio.h>

int main(int argc, char *argv[])
{
  int c;
  int total = 0;

  while((c = getchar()) != EOF)
  {
    total++;
  }
  printf("The total number of input chars is %d\n", total);
  

  return 0;
}
