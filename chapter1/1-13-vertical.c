#include <stdio.h>

#define MAXHIST 15
#define MAXWORD 11
#define IN       1
#define OUT      0

int isAlpha(char c);
int isSpace(char c);

// print vertical histogram
int main(int argc, char *argv[])
{
  int c, i, j, nc, state; 
  int maxvalue;
  int ovflow;
  int wl[MAXWORD] = { 0 };
  
  state = OUT;
  nc = 0;
  maxvalue = 0;
  ovflow = 0;

  while ((c = getchar()) != EOF)
  {
    if (isSpace(c))
    {
      state = OUT;
      if (nc > 0) // this is the end of the word
      {
        if (nc < MAXWORD)
          wl[nc]++;
        else
          ovflow++;
      }
      nc = 0;
    }
    else if (state == OUT)
    {
      state = IN; // begin of a new word
      nc = 1;
    }
    else if (isAlpha(c))
      nc++;
  }

  for (i = 1; i < MAXWORD; i++)
  {
    if (wl[i] > maxvalue)
      maxvalue = wl[i];
  }


  // the most difficult part, print the gram
  for (i = MAXHIST; i > 0; i--)
  {
    for (j = 1; j < MAXWORD; j++)
    {
      if ((int)(wl[j] * MAXHIST / maxvalue) >= i) // ?
      {
        printf("   * ");
      }
      else
        printf("     ");
    }
    putchar('\n');
  }

  for (i = 1; i < MAXWORD; i++)
  {
    printf("%4d ", i);
  }
  putchar('\n');
  for (i = 1; i < MAXWORD; i++)
  {
    printf("%4d ", wl[i]);
  }
  putchar('\n');

  if (ovflow > 0)
    printf("There are %d words >= %d. \n", ovflow, MAXWORD);
  
  return 0;
}

int isAlpha(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return 1;
  return 0;
}

int isSpace(char c)
{
  if (c == ' ' || c == '\t' || c == '\n')
    return 1;
  return 0;
}
