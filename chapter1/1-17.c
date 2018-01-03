#include <stdio.h>
#define MAXLEN 512

int getLine(char line[], int maxlen);

int main(int argc, char *argv[])
{
  int c, i, len;
  char line[MAXLEN];
  len = 0;

  while ((len = getLine(line, MAXLEN)) > 0)
  {
    if (len > 80)
      printf("%s\n", line);
  }

  return 0;
}

int getLine(char line[], int lim)
{
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
  {
    line[i] = c;
  }
  if (c == '\n')
  {
    line[i] = c;
    i++;
  }
  return i;
}
