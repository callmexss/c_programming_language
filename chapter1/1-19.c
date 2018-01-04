#include <stdio.h>
#define MAXLEN 512

int getLine(char line[], int maxlen);
void reverse(char line[], int len);

int main(int argc, char *argv[])
{
  int c, i, len;
  char line[MAXLEN];
  len = 0;

  while ((len = getLine(line, MAXLEN)) > 0)
  {
    reverse(line, len);
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

void reverse(char line[], int len)
{
  char tmp[len];
  // printf("true???%d\n", line[len-1] == '\n'); true 
  if (line[len - 1] != '\n')
  {
    len = len + 1;
  }

  for (int i = 0; i < len - 1; i++)
  {
    tmp[i] = line[i];
  }
  
  for (int i = 0; i < len - 1; i++)
  {
    line[i] = tmp[len - i - 2];
  }
}
