#include <stdio.h>


int main()
{
  int c;
  while((c = getchar()) != EOF)
  {
    if (c != '\n')
    {
      continue;
    }
    printf("Please input 'EOF'.\n");

  }
  printf("EOF: %c\n", c);
  printf("EOF: %d\n", c);

  return 0;
}
