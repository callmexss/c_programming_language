#include <stdio.h>

int main(int argc, char *argv[])
{
  int c;
  int line_num = 0;

  for (;(c = getchar()) != EOF;)
  {
    if (c == '\n')
    {
      line_num++;
    }
  }
  printf("There are total %d rows.\n", line_num);
  

  return 0;
}
