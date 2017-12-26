#include <stdio.h>
#define MAXLINE 1000

int getline_(char line[], int max);
int strindex(char src[], char tag[]);

char pattern[] = "ould";


int main()
{
  char line[MAXLINE];
  int found = 0;

  while (getline_(line, MAXLINE) > 0)
  {
    if (strindex(line, pattern) > 0)
    {
      printf("%s", line);
      found++;
    } // end of if 
  } // end of when

  return found;
}

int getline_(char line[], int max)
{
  int c, i;
  i = 0;
  
  /**
   * if current line size is less than MAXLINE
   * if current char is not end of file
   * if current char is not breaking line
   * add current char to line
   */
  while (--max > 0 && (c = getchar()) != EOF && c != '\n')
  {
    line[i++] = c;
  } // end of while
  
  /**
   * if current char is breaking line
   * add it to line
   */
  if (c == '\n')
  {
    line[i++] = c;
  } // end of if

  /**
   * if current char is end of file 
   * add it to line
   */
  line[i] = '\0'; // end of c type string
  return i;
}

int strindex(char src[], char tag[])
{
  int i, j, k;

  for (i = 0; src[i] != '\0'; i++)
  {
    for (j = i, k = 0; tag[k] != '\0' && src[j] == tag[k]; j++, k++)
      ;
    if (k > 0 && tag[k] == '\0')
      {
        return i;
      }
  }
  return -1;
}
