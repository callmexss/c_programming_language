#include <stdio.h>

int isEqual(int*, int*, int);

int main(int argc, char *argv[])
{
  int a[] = {1, 1, 2};
  int b[] = {1, 1, 2};
  int c[] = {1, 2, 2};
  if (isEqual(a, b, 3))
  {
    printf("a equals b\n");
  }
  
  if (!isEqual(a, c, 3))
  {
    printf("a not equals c\n");
  }

  return 0;
}

int isEqual(int* a, int* b, int len)
{
  for (int i = 0; i < len; i++)
  {
    if (a[i] != b[i])
    {
      return 0;
    }
  }
  return 1;
}

