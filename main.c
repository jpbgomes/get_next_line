#include "get_next_line.h"

int main()
{
  int myFile = open("teste.txt", O_RDONLY);
  if (myFile == -1)
    printf("NO FILE\n");
  else
  {
    printf("YES FILE\n");
    printf("Current Line = %s\n", get_next_line(myFile));
  }

  close(myFile);
  return (0);
}