#include "get_next_line.h"

int main()
{
  printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);

  // int myFile = open("teste.txt", O_RDONLY);
  // int myFile = open("teste2.txt", O_RDONLY);
  // int myFile = open("teste3.txt", O_RDONLY);
  int myFile = open("teste4.txt", O_RDONLY);
  if (myFile == -1)
    printf("NO FILE\n");
  else
  {
    // printf("Current FD = %d\n\n", myFile);
    printf("Returned Line = %s\n", get_next_line(myFile));
    // printf("\n\nCurrent FD = %d\n\n", myFile);
    printf("Returned Line = %s\n", get_next_line(myFile));
    // printf("\n\nCurrent FD = %d\n\n", myFile);
    printf("Returned Line = %s\n", get_next_line(myFile));
  }

  close(myFile);
  return (0);
}