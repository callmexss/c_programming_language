#include <stdio.h>

#define MAXHIST 15
#define MAXLEN  2048 

int main(int argc, char *argv[])
{
  int c, i;
  int num[10] = { 0 };
  int alpha[26] = { 0 };
  int maximum = 0;
  int white = 0;
  int other = 0;
  int len = 0;

  while ((c = getchar()) != EOF)
  {
    if (c == ' ' || c == '\t' || c == '\n')
    {
      if (white < MAXLEN) white++;
    }
    else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
      if (c < 'a') c += 32;
      if (alpha[c-'a'] < MAXLEN) alpha[c-'a']++;
    }
    else if ((c >= '0') && c <= '9')
    {
      if (num[c-'0'] < MAXLEN) num[c-'0']++;
    }
    else if (other < MAXLEN) other++;
  }

  // if (white > maximum) maximum = white;
  if (other > maximum) maximum = other;
  for (i = 0; i < 10; i++)
  {
    if (num[i] > maximum)
      maximum = num[i];
  }

  for (i = 0; i < 26; i++)
  {
    if (alpha[i] > maximum)
      maximum = alpha[i];
  }

  for (i = 0; i < 10; i++)
  {
    printf("%5d-%5d: ", i, num[i]);
    len = num[i] * MAXHIST / maximum; 
    while(len > 0)
    {
      printf("*");
      len--;
    }
    putchar('\n');
  }

  for (i = 0; i < 26; i++)
  {
    printf("%5c-%5d: ", i + 'a', alpha[i]);
    len = alpha[i] * MAXHIST / maximum; 
    while(len > 0)
    {
      printf("*");
      len--;
    }
    putchar('\n');
  }

  return 0;
}
