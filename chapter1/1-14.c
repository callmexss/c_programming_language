#include <stdio.h>
#include <ctype.h>

#define MAXHIST 15
#define MAXCHAR 128

int main(int argc, char *argv[])
{
  int c, i;
  int len = 0;
  int maxvalue = 0;
  int cc[MAXCHAR] = { 0 };

  while ((c = getchar()) != EOF)
    if (c < MAXCHAR)
      cc[c]++;

  for (i = 1; i < MAXCHAR; i++)
    if (cc[i] > maxvalue)
      maxvalue = cc[i];

  for (i = 1; i < MAXCHAR; i++)
  {
    // if (isprint(i))
    if (ispunct(i))
      printf("%5d - %c - %5d : ", i, i, cc[i]);
    else
      printf("%5d -   - %5d : ", i, cc[i]);
    if (cc[i] > 0)
    {
      if ((len = cc[i] * MAXHIST / maxvalue) <= 0)
        len = 1;
    }
    else
    {
      len = 0;
    }
    while (len > 0)
    {
      putchar('*');
      len--;
    }
    putchar('\n');
  }
  

  return 0;
}
