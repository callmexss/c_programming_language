#include <stdio.h>


void get_ould_in_line(FILE *, FILE *);

int main(int argc, char *argv[])
{
  FILE *fp;

  if (argc == 1)
  {
    printf("Usage: get_ould_in_line filename\n");
    return 1;
  }
  else
  {
    while (--argc > 0)
    {
      if ((fp = fopen(*++argv, "r")) == NULL)
      {
        printf("can't open %s \n", *argv);
	return 1;
      } // end of if
      else
      {
        get_ould_in_line(fp, stdout);
      } // end of else
    } // end of when
  } // end of else
  
  return 0;
}

void get_ould_in_line(FILE *ifp, FILE *ofp)
{
  int c;
  while ((c = getc(ifp)) != EOF)
  {
    putc(c, ofp);
  }
}
