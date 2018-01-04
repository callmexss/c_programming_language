#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int getLine();
void copy();

int main(int argc, char *argv[])
{
  int len;
  extern int max;
  extern char longest[];

  max = 0;
  while ((len = getLine(line, MAXLINE)) > 0)
  {
    if (len > max)
    {
      max = len;
      copy(longest, line);
    }
  }
  if (max > 0)
    printf("%s", longest);

  return 0;
}

/* Special version */
int getLine()
{
  int c, i;
  extern char line[];
  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    line[i] = c;
  if (c == '\n')
  {
    line[i] = c;
    i++;
  }
  line[i] = '\0';
  return i;
}

/* Special version */
void copy()
{
  int i = 0;
  extern char line[], longest[];
  while ((longest[i] = line[i]) != '\0')
    i++;
}
