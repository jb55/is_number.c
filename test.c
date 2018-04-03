

#include "is_number.h"
#include "assert.h"
#include <string.h>
#include <stdio.h>

#define BLEN 50

int main()
{
  int test = 1;
  int tests = 1;

  printf("1..%i\n", tests);

  assert(is_number("number", sizeof("number")) == 0);
  printf("ok %i 'number' is not a number\n", test++);

  return 0;
}
