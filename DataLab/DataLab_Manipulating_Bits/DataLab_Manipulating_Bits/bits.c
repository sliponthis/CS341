/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  /*
   * COMMENTS
   * With only ~ | as legal ops bitAnd accomplishes the 
   * boolean bitwise and by the bitwise:
   * 1. NEGATION of x and y to give xNeg, yNeg
   * 2. OR of xNeg, yNeg stored in result
   * 3. NEGATION of result
   */
  int xNeg, yNeg, result;
  xNeg = ~x;
  yNeg = ~y;
  result = ~(xNeg | yNeg);
  return result;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  /*
   * COMMENTS
   *
   * For n = 0-3, getByte needs to shift x
   * by n*8 bits. The shift is accomplished by
   * left shfiting n by 3 bits. The result is
   * obtained by masking desired shifted byte 
   * by 0xff;
   */
  int shift = n << 3, result;
  result = (x >> shift) & 0xff;
  return result;
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  /*
   * COMMENTS
   *
   * 1. Shift out lowest nibble in least significant byte
   
   * 2. Determine if any bits greater than x30 are set
   
   * 3. Is the most signficant bit in the lower nibble set?
   
   * 4. LSNibbleOutsideRange determines if the least significant byte is between 0-9
   
   * 5. return the bitWise & of noBitsMoreSignThanx30set and LSNibbleOutsideRange
   */
  int sOutLSBNibble = (x >> 4) << 4;
  int noBitsMoreSigThanx30Set = !(sOutLSBNibble ^ 0x30);
  int highBit_LSNibble_notSet = !(x & 0x8);
  int LSNibbleOutsideRange = (highBit_LSNibble_notSet | !(x & 0x6));
  int result = noBitsMoreSigThanx30Set & LSNibbleOutsideRange;
  
  return result;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  /*
   * COMMENTS
   
   * 1. Build a mask that will consist of n bits set to 0
   * 
   * 2. Shift x to the right by n and take bitwise & with mask
   * 
  * NOTE: the mask ensures that the negative #'s MS n bits
   * will be set to 0 - this implements the logical shift
   */
  int mask = ((1 << 31) >> n) << 1;
  int res = (x >> n) & ~mask;
  return res;
}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
  /*
   * COMMENTS:
   * RECURSIVE ALGORITHM
   * 1. Shift x by 2^n-1 bits, where n is the iteration count
   * and take bitwise ^ with input
   * 
   * 2. Each iteration uses the output from the previous step
   * (recursive approach)
   * 
   * 3. Extract least significant bit in result; specifies parity
   * Note: Initial approach was correct but required too many ops
   
   //initial approach
  int mask_1 = 0x55, mask_2 = 0x33, mask_4 = 0x0f, mask_8 = 0xff, mask_16 = ~(~0x00 << 16);
  int mask_1_n = 0xaa, mask_2_n = 0xcc, mask_4_n = 0xf0, mask_8_n = 0x00, mask_16_n = ~mask_16;
  //printf("mask_16: %x\n", mask_16);
  int mask1Bit = (x & mask_1) + ((x & mask_1_n) >> 1);
  int mask2Bit = (mask1Bit & mask_2) + ((mask1Bit & mask_2_n) >> 2);
  int mask4Bit = (mask2Bit & mask_4) + ((mask2Bit & mask_4_n) >> 4);
  int mask8Bit = (mask4Bit & mask_8) + ((mask4Bit & mask_8_n) >> 8);
  */
  //printf("x: %x\n", x);
  int sBy1Bit = (x >> 0x01) ^ x;
  int sBy2Bit = (sBy1Bit >> 0x02) ^ sBy1Bit;
  int sBy4Bit = (sBy2Bit >> 0x04) ^ sBy2Bit;
  int sBy8Bit = (sBy4Bit >> 0x08) ^ sBy4Bit;
  int sBy16Bit = (sBy8Bit >> 0x10) ^ sBy8Bit;
  //printf("1Bit: %x, 2Bit: %x, 4Bit: %x, 8Bit: %x, 16Bit: %x\n", sBy1Bit, sBy2Bit, sBy4Bit, sBy8Bit, sBy16Bit);
  int res = sBy16Bit & 0x01;
  return res;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  /*
   * COMMENTS
   * 1. Shift out bits 31:(31-n); bits are irrelevant even
   * if they are 0/1 (positive/negative integer)
   * 
   * 2. Take EXCLUSIVE OR btwn x & integer that results from
   * bit shifts applied in 1
   * 
   * 3. IF x is a positive int, and is > 2^(n-1) - 1, then the
   * shift will result in the n bits (31:(31-n) being set to 1;
   * the EXCLUSIVE OR will result in a int != 0. Negating the 
   * result will return 0, as expected.
  */
   
  /*
   //Code failed on first case because negating 0x80000000 results in 0x80000000
   //Fails on 0x80000000 corner case
  int negOne = ~0x0;
  int shift = n + negOne;
  int intMax = ~(negOne << shift);
  int intMin = negOne << shift;
  printf("intMax: %d, intMin: %d\n", intMax, intMin);
  int xNegated = ~x+1;
  printf("xNegated: %d", xNegated);
  int diffMax = intMax  + xNegated;
  int diffMin = intMin + xNegated;
  printf("diffMax: %d, diffMin: %d\n", diffMax, diffMin);
  int res = ((diffMax >> 31) & 0x1) | (~(diffMin >> 31) & 0x1 );
  return res;
   */
  //printf("x: %x, n: %d ", x, n);
  
  int bitsToShiftOut = 32 + (~n + 1);
  return !(x ^ ((x << bitsToShiftOut) >> bitsToShiftOut));
}
/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x){
  /*
   * COMMENTS
   * SAME LOGIC AS fitsBits, except that in this
   * implementation we know that n = 16
   */
  return !(x^((x << 16) >> 16));
}
/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) {
  /*
   * COMMENTS
   * IF x is min 2's complement #, then the 2's complement negation
   * will results in the same value. Of course, 0x00 has this property,
   * so a check is performed to make sure that x is not 0.
   */
  int twosComplementX = ~x + 1;
  int logicalEquivalent = !(twosComplementX ^ x);
  int isZero = !(x ^ 0x0);
  int res = logicalEquivalent & !isZero;
  return res;
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
int leastBitPos(int x) {
  /*
   * COMMENTS
   * SIMPLE ALGORITHM: 
   * 1. BIT WISE & btwn two's complement negated value
   * of x and x will cancel out all bits except the least
   * significant 1 bit.
   */
  int xNegated = ~x + 1;
  int res = x & xNegated;
  return res;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  /*
   * COMMENTS
   * SIMPLE ALGORITHM: Two's complement negation:
   * 1. Negate each bit in x and then add 1 to determine -x
   */
  int negation = ~x + 1;
  return negation;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  /*
   * COMMENTS
   * SIMPLE ALGORITHM: Check MSB to determine if x is
   * a neg/pos number. Then ensure that x is also not 
   * 0 since 0x00 has the property of also having a 0
   * in the most significant bit location.
   */
  int unSigned = !((x >> 31) & 0x01);
  int zero = !(x ^ 0x00);
  int res = unSigned & !zero;
  return res;
}
/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {
  /*
   * COMMENTS
   * 1. Determine if x and y are negative ints (inspect 
   * most significant bit) 
   
   * 2. 2's complement negation of y
   
   * 3. Compute x - y and determine sign bit of difference
   
   * 4. Boolean logic to determine if sub doesn't result in
   * overflow
   
   * OVERFLOW:
   * x[31] y[31] diff[31]
   *   1     0     0 (neg # subtracted by pos # should result in + diff)
   *   0     1     1 (pos # subtracted by neg # should result in + diff)
   */
  int signBitX = (x >> 31) & 0x01;
  int signBitY = (y >> 31) & 0x01;
  int negateY = ~y + 1;
  int diff = x + negateY;
  int signBitDiff = (diff >> 31) & 0x01;
  int res = !((!signBitX & signBitY & signBitDiff) | (signBitX & !signBitY & !signBitDiff));
  //printf("x: %x, y: %x, diff: %x ", x, y, diff);
  //printf("signBitX: %d, signBitY: %d, signBitDiff: %d, res: %d\n",signBitX, signBitY, signBitDiff,res);
  return res;
}
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
  return 2;
}
/*
 * ezThreeFourths - multiplies by 3/4 rounding toward 0,
 *   Should exactly duplicate effect of C expression (x*3/4),
 *   including overflow behavior.
 *   Examples: ezThreeFourths(11) = 8
 *             ezThreeFourths(-9) = -6
 *             ezThreeFourths(1073741824) = -268435456 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int ezThreeFourths(int x) {
  return 2;
}
/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *   avoiding errors due to overflow
 *   Examples: trueThreeFourths(11) = 8
 *             trueThreeFourths(-9) = -6
 *             trueThreeFourths(1073741824) = 805306368 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int trueThreeFourths(int x)
{
  return 2;
}
