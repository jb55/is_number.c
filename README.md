
# is_number.c

  Very fast number testing

## Installation

  Install with clib

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
