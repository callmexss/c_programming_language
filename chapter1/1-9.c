#include <stdio.h>

int main(int argc, char *argv[])
{
  int c;
  int space = 0;

  while((c = getchar()) != EOF)
  {
    if (c != ' ')
    {
      putchar(c);
      space = 0;
    }
    if (c == ' ' && space == 0)
    {
      putchar(c);
      space++;
    }
  }

  printf("\n");
  
  return 0;
}
