#include "impl/c/miscelaneousFunctions.h"

void mapFilesToMemory() 
{

  printf("using mapFilesToMemory method \n");

}

void parseBC() 
{
  FILE* bcFile;
  bcFile = fopen("/home/jesus.juarez/chroot_/git/cd/cpp/SimpleBC.class", "rb");
  int ch;
  while(1) 
  {
    ch = fgetc(bcFile);
    if(ch == 'V')
    {
      printf("value: %c \n", ch);
      break;
    }
  } 
  fclose(bcFile);
}
