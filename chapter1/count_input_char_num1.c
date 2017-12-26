#include <stdio.h>

int main(int argc, char *argv[])
{
  int c;
  double total = 0;

  for (;(c = getchar()) != EOF;total++)
    ;
  printf("%.0f\n", total);
  

  return 0;
}
