//  main.c
//  lab1
//
//  Created by Ryan Vary on 8/25/17.
//  Copyright (c) 2017 Ryan Vary. All rights reserved.

#include <stdio.h>
#include <stdlib.h>

unsigned int generateWord(int x, int y);

int main(int argc, const char * argv[])
{
  if(argc != 3)
  {
    printf("Program must be provided with 2 inputs: {x y}. %d args provided!", argc);
    return 1;
  }
  
  unsigned int arg1, arg2;
  scanf("%x",&arg1);
  scanf("%x",&arg2);
  int bitMasking = generateWord(arg1, arg2);
  printf("%08x", bitMasking);
  getchar();
  return 0;
}

unsigned int generateWord(int x, int y)
{
  int xMasked, yMasked, result;
  xMasked = x & 0x000000ff;
  yMasked = y & 0xffffff00;
  result = xMasked | yMasked;
  return result;
}