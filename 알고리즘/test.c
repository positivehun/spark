#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int a = 0;
int main()
{
  a++;
  if (a==10){
    return 0;
  }
  printf("hello,%d",a);
  main();
  printf("bye");
  return 0;
  // printf(rand())
}
