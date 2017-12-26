#include <stdio.h>

#define OUT  0
#define IN  1

int main(int argc, char *argv[])
{
  int c;
  int state = OUT; // whether current character is in a word
  int char_num = 0;
  int word_num = 0;
  int line_num = 0;

  while((c = getchar()) != EOF)
  {
    char_num++;

    if (c == '\n')
    {
      line_num++;
    }

    // current character is out of a word
    if (c == ' ' || c == '\t' || c == '\n')
    {
      state = OUT;
    }
    // if current character is the first alphabet
    // after a ' ' or '\t' or '\n'
    // than this is the very start of a word.
    // so add the word number.
    // don't forget change the state to IN :)
    else if (state == OUT)
    {
      state = IN;
      word_num++;
    }
  }

  printf("The total line number is %d\n", line_num);
  printf("The total word number is %d\n", word_num);
  printf("The total character number is %d\n", char_num);

  return 0;
}
