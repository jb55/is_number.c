
#include "is_number.h"
#include "assert.h"
#include <string.h>
#include <stdio.h>

#define BLEN 50

#define strsize(s) (sizeof(s)-1)

int main()
{
  int test = 1;
  int tests = 20;

  int prepost = ALLOW_EMPTY_POST_DOT | ALLOW_EMPTY_PRE_DOT;

  printf("1..%i\n", tests);

  assert(is_number("number", strsize("number")) == 0);
  printf("ok %i  'number' is NOT a number\n", test++);

  assert(is_number("-1", strsize("-1")) == 1);
  printf("ok %i  '-1' is a number\n", test++);

  assert(is_number("", strsize("")) == 0);
  printf("ok %i  '' is NOT a number\n", test++);

  assert(is_number(" ", strsize(" ")) == 0);
  printf("ok %i  ' ' is NOT a number\n", test++);

  assert(is_number("0", strsize("0")) == 1);
  printf("ok %i  '0' is a number\n", test++);

  assert(is_number("1.0", strsize("1.0")) == 1);
  printf("ok %i  '1.0' is a number\n", test++);

  assert(is_number("1..0", strsize("1..0")) == 0);
  printf("ok %i  '1..0' is NOT a number\n", test++);

  assert(is_number("1.0.", strsize("1.0.")) == 0);
  printf("ok %i  '1.0.' is NOT a number\n", test++);

  assert(is_number("10.0", strsize("10.0")) == 1);
  printf("ok %i  '10.0' is a number\n", test++);

  assert(is_number_with("10.0", strsize("10.0"), ONLY_TEST_INT) == 0);
  printf("ok %i  '10.0' is NOT a number with ONLY_TEST_INT\n", test++);

  assert(is_number_with(".0", strsize(".0"), ONLY_TEST_INT | ALLOW_EMPTY_PRE_DOT) == 0);
  printf("ok %i  '.0' is NOT a number with ONLY_TEST_INT | ALLOW_EMPTY_PRE_DOT\n", test++);

  assert(is_number_with("0.", strsize("0."), ONLY_TEST_INT | ALLOW_EMPTY_POST_DOT) == 0);
  printf("ok %i  '0.' is NOT a number with ONLY_TEST_INT | ALLOW_EMPTY_POST_DOT\n", test++);

  assert(is_number(" 10", strsize(" 10")) == 1);
  printf("ok %i  ' 10' is a number\n", test++);

  assert(is_number("\t10", strsize("\t10")) == 1);
  printf("ok %i  '\\t10' is a number\n", test++);

  assert(is_number(" 10 1", strsize(" 10 1") ) == 0);
  printf("ok %i  ' 10 1' is NOT a number\n", test++);

  assert(is_number_with("\t10", strsize("\t10"), STRICT_WHITESPACE) == 0);
  printf("ok %i  '\\t10' is NOT a number with STRICT_WHITESPACE\n", test++);

  assert(is_number_with(" 10", strsize(" 10"), STRICT_WHITESPACE) == 0);
  printf("ok %i  ' 10' is NOT a number with STRICT_WHITESPACE\n", test++);

  assert(is_number_with("10 ", strsize("10 "), STRICT_WHITESPACE) == 0);
  printf("ok %i  '10 ' is NOT a number with STRICT_WHITESPACE\n", test++);

  assert(is_number("1.", strsize("1.")) == 0);
  printf("ok %i  '1.' is NOT a number\n", test++);

  assert(is_number_with("1.", strsize("1."), ALLOW_EMPTY_POST_DOT) == 1);
  printf("ok %i  '1.' is a number with ALLOW_EMPTY_POST_DOT\n", test++);

  assert(is_number_with(".1", strsize(".1"), ALLOW_EMPTY_PRE_DOT) == 1);
  printf("ok %i  '.1' is a number with ALLOW_EMPTY_PRE_DOT\n", test++);

  assert(is_number_with("-.1", strsize("-.1"), ALLOW_EMPTY_PRE_DOT) == 1);
  printf("ok %i  '-.1' is a number with ALLOW_EMPTY_PRE_DOT\n", test++);

  assert(is_number_with(".", strsize("."), ALLOW_EMPTY_POST_DOT) == 0);
  printf("ok %i  '.' is NOT a number with ALLOW_EMPTY_POST_DOT\n", test++);

  assert(is_number_with(".", strsize("."), ALLOW_EMPTY_PRE_DOT) == 0);
  printf("ok %i  '.' is NOT a number with ALLOW_EMPTY_PRE_DOT\n", test++);

  assert(is_number_with(".", strsize("."), prepost) == 1);
  printf("ok %i  '.' is a number with ALLOW_EMPTY_{PRE,POST}_DOT\n", test++);

  assert(is_number_with("-.", strsize("-."), ALLOW_EMPTY_POST_DOT) == 0);
  printf("ok %i  '-.' is NOT a number with ALLOW_EMPTY_POST_DOT\n", test++);

  assert(is_number_with("-.", strsize("-."), prepost) == 1);
  printf("ok %i  '-.' is a number with ALLOW_EMPTY_{PRE,POST}_DOT\n", test++);

  assert(is_number_with("-.1", strsize("-.1"), ALLOW_EMPTY_PRE_DOT) == 1);
  printf("ok %i  '-.1' is a number with ALLOW_EMPTY_PRE_DOT\n", test++);

  assert(is_number("-", strsize("-")) == 0);
  printf("ok %i  '-' is NOT a number\n", test++);

  assert(is_number_with("-", strsize("-"), prepost) == 0);
  printf("ok %i  '-' is NOT a number with PREPOST\n", test++);

  return 0;
}
