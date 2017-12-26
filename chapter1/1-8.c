#include <stdio.h>

int main(int argc, char *argv[])
{
  int c;
  int total = 0;

  while((c = getchar()) != EOF)
  {
    if (c == ' ' || c == '\t' || c == '\n')
    {
      total++;
    }
  }

  printf("The total special char number is %d\n", total);
  

  return 0;
}
