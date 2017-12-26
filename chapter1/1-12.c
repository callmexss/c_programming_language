#include <stdio.h>
#define OUT 0
#define IN 1

int main(int argc, char *argv[])
{
  int c;
  int state = OUT;

  while((c = getchar()) != EOF)
  {
    // out of a word
    if (c == ' ' || c == '\t' || c == '\n')
    {
      if (state == IN) // is `==` not `=` !!!
      {
        putchar('\n');
        state = OUT;
      }
    }
    // the begin of a word
    else if (state == OUT)
    {
      state = IN;
      putchar(c);
    }
    // in a word
    else
    {
      putchar(c);
    }
  }
  return 0;
}
