#include <stdio.h>
#define MAXLEN 512

int getLine(char line[], int maxlen);
int strip(char line[], int len);

int main(int argc, char *argv[])
{
  int c, i, len;
  char line[MAXLEN];
  len = 0;

  while ((len = getLine(line, MAXLEN)) > 0)
  {
    if ((i = strip(line, len)) < len)
      printf("%s", line);
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
  line[i] = '\0';
  return i;
}

int strip(char line[], int len)
{
  // printf("cccc:%d\n", line[len] == '\0'); true
  for (int i = len; i >= 0; i--)
  {
    // printf("_______%d\n", i);
    if (line[i] != ' ' && line[i] != '\t' 
        && line[i] != '\n' && line[i] != '\0')
    {
      /*
      if (i == 1)
      {
        line[2] = '\n';
        line[3] = '\0';
        return 0;
      }
      */
      if (i < len)
      {
        line[i+1] = '\n';
        line[i+2] = '\0';
        return i+2;
      }
    }
    else
    {
      continue;
    }
  }
}
