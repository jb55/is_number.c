
# is_number.c

[![Build Status](https://travis-ci.org/jb55/is_number.c.svg)](https://travis-ci.org/jb55/is_number.c)

  Very fast number testing

## Installation

  Install with [clib](https://github.com/clibs/clib/)

    $ clib install jb55/is_number.c

## Example

```c
#include "is_number.h"
#include <assert.h>

int main() {
  const char *str = "1.0";
  int is_num;

  is_num = is_number("1.0", 3);
  assert(is_num);

  is_num = is_number_with("1.", 2, ALLOW_EMPTY_POST_DOT);
  assert(is_num);

  is_num = is_number("1.", 2);
  assert(!is_num);
}
```

## Options

```c
enum is_num_options {
  ALLOW_EMPTY_PRE_DOT  = 1 << 1,  // allow empty digits before the decimal point
  ALLOW_EMPTY_POST_DOT = 1 << 2,  // allow empty digits past the decimal point
  STRICT_WHITESPACE    = 1 << 3,  // don't allow space padding
  ONLY_TEST_INT        = 1 << 4   // don't allow decimals/floats
};
```

