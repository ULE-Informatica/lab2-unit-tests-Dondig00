#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h> 

unsigned int wrapFunctionAdd(unsigned int ui_a, unsigned int ui_b) {
  unsigned int usum;
  /*According to rule INT30-C*/
  /*This noncompliant code example can result in an unsigned integer wrap during the addition of the unsigned operands ui_a and ui_b.
   If this behavior is unexpected, the resulting value may be used to allocate insufficient memory for a subsequent operation or in 
   some other manner that can lead to an exploitable vulnerability.*/
   //precondition test to guarantee there is no possibility of unsigned wrap aborted addition operation
  if (UINT_MAX - ui_a < ui_b) {
    printf("Unsigned wrap aborted addition operation\n");
    return -1;
  } else {
    usum = ui_a + ui_b;
  }
  return usum;
}
/*According to rule INT30-C*/
  /*heap buffer overflow vulnerability resulting from an unsigned integer wrap during the multiplication of the signed int umul and ui_b*/
unsigned int wrapFunctionMul(unsigned int ui_a, unsigned int ui_b) {
  unsigned int umul = ui_a;
  //Precondition test to guarantee that there is no unsigned integer wrap after the multiplication
  if (ui_a > UINT_MAX / ui_b){
    printf("Unsigned wrap aborted multiplication operation\n");
    return -1;
  } else {
    umul *= ui_b;
  }
  
  return umul;
}

/*According to rule INT34-C*/
/*Do not shift an expression by a negative number of bits or by greater than or equal to the number of bits that exist in the operand*/
uint32_t wrapFunctionShift(uint32_t ui_a, unsigned int ui_b) {

  uint32_t uShift;

  /*We check for both unsigned shifts left an right with this pre-condition, ensuring non is negative */
  if (ui_a < 0 || ui_b < 0 || ui_b >= __builtin_popcount(UINT_MAX) || ui_a > (UINT_MAX >> ui_b)) 
  {
    printf("Unsigned wrap aborted during shift operation\n");
    return -1;
  } else {
    uShift = ui_a << ui_b | ui_a >> (32 - ui_b);
  } 
  return uShift;
}
