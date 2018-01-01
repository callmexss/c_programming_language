#include <stdio.h>

float celsius(float fahr);

int main(int argc, const char *argv[])
{
  int fahr;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper)
  {
    printf("%3d\t%6f\n", fahr, celsius(fahr));
    fahr += step;
  }
  
  return 0;
}

float celsius(float fahr)
{
  return (5 * (fahr - 32) / 9);
}
