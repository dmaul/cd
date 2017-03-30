#include <stdio.h>
#include <stdlib.h>

int main(){
  char* var1 = (char *) 0x5000001f;
  printf("%c", *var1);
  return 0;
}
