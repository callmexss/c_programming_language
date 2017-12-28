#include <stdio.h>

#define MAXHIST 15
#define MAXWORD 11
#define IN      1
#define OUT     0

int isAlpha(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return 1;
  return 0;
}

int main(int argc, char *argv[])
{
  int c, i, nc, state;
  int len; // length of each bar
  int maxvalue; // maximum value for wl[]
  int ovflow; // number of overflow words
  int wl[MAXWORD] = { 0 };

  state = OUT;
  nc = 0;
  len = 0;
  ovflow = 0;
  maxvalue = 0;

  while((c = getchar()) != EOF)
  {
    if (c == ' ' || c == '\t' || c == '\n')
    {
      state = OUT; // the end of a word
      if (nc > 0)
      {
        if (nc < MAXWORD)
          wl[nc]++;
        else 
          ovflow++;
        nc = 0;
      }
    }
    else if (state == OUT)
    {
      state = IN; // start of a new word
      nc = 1;
    }
    else if (isAlpha(c)) 
      nc++; // still in a word
  }

  for (i = 1; i < MAXWORD; i++)
  {
    if (wl[i] > maxvalue)
     maxvalue = wl[i]; 
  }
  
  for (i = 1; i < MAXWORD; i++)
  {
    printf("%5d - %5d: ", i, wl[i]);
    if (wl[i] > 0)
    {
      if ((len = wl[i] * MAXHIST / maxvalue) <= 0)
      {
        len = 1;
      }
    }
    else 
    {
      len = 0;
    }
    while (len > 0)
    {
      putchar ('*');
      --len;
    }
    putchar('\n');
  }
  if (ovflow > 0)
    printf("There are %d words >= %d\n", ovflow, MAXWORD);

  

  return 0;
}
