#include <stdio.h>

int main(int argc, char *argv[])
{
  int c;

  for (; (c = getchar()) != EOF;)
  {
    if (c == '\t')
    {
      putchar('\\');
      putchar('t');
    }

    if (c == '\b')
    {
      putchar('\\');
      putchar('b');
    }

    if (c == '\\')
    {
      putchar('\\');
      putchar('\\');
    }
  }
  

  return 0;
}
