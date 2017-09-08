//  main.c
//  lab1
//
//  Created by Ryan Vary on 8/25/17.
//  Copyright (c) 2017 Ryan Vary. All rights reserved.

#include <stdio.h>
#include <stdlib.h>

unsigned generateWord(int x, int y);
unsigned replaceByte(unsigned word, int i, unsigned char byte);
int any_odd_one(unsigned x);
/*
// main -> generateWord(int x, int y)
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
*/

/*
//main -> replaceByte(unsigned word, int i, unsigned char byte)
int main(int argc, const char * argv[])
{
  int i = 3;
  if(i > sizeof(unsigned))
  {
    printf("i must be >= 0 and < sizeof(unsigned) = %lu. i was specified as %d ", sizeof(unsigned int), i);
  }
  else
  {
    unsigned result = replaceByte(0x12345678, i, 0xAB);
    printf("%08x", result);
  }
}
*/

//main -> any_odd_one(unsigned x);
int main(int argc, const char* argv[])
{
  //unsigned input = 0xabcdef01;
  unsigned input = 0x04030201;
  int output = any_odd_one(input);
  printf("%d", output);
}

unsigned generateWord(int x, int y)
{
  int xMasked, yMasked, result;
  xMasked = x & 0x000000ff;
  yMasked = y & 0xffffff00;
  result = xMasked | yMasked;
  return result;
}

unsigned replaceByte(unsigned word, int i, unsigned char byte)
{
  unsigned mask, mask2, wordMod;
  int lshift = 8*i, lshift_ = (4-i)*8 - 1, rshift = (i+1)*8-1;
  mask = byte << lshift;
  mask2 = (word << lshift_) >> lshift_;
  //printf("%08x\n", mask);
  //printf("%08x\n", mask2);
  wordMod = (word >> rshift) << rshift;
  //printf("%08x\n", wordMod);
  wordMod |= (mask | mask2);
  return wordMod;
}

int any_odd_one(unsigned x)
{
  unsigned mask = 0x55, b1, b2, b3, b4;;
  int shift_val = sizeof(x), odd_bit_one;
  b1 = (x << ((shift_val-1) << 3)) >> ((shift_val - 1) << 3);
  b2 = (x << (shift_val << 2)) >> ((shift_val - 1) << 3);
  b3 = (x << (shift_val << 1)) >> ((shift_val - 1) << 3);
  b4 = x >> 24;
  //printf("%08x\n", x);
  //printf("%08x\n", b1);
  //printf("%08x\n", b2);
  //printf("%08x\n", b3);
  //printf("%08x\n", b4);
  odd_bit_one = b1 & mask || b2 & mask || b3 & mask || b4 & mask;
  return odd_bit_one;
}