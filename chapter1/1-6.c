/**
 * test the value of `getchar() != EOF`
 **/

#include <stdio.h>


int main()
{
  int res;

  while(res = getchar() != EOF)
  {
    printf("%d\n", res);
  }

  // EOF --> ctrl+d
  printf("%d - at EOF\n", res);

  
  return 0;
}
