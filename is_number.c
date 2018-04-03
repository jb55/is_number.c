
#include <ctype.h>
#include <assert.h>
#include "is_number.h"

int is_number_with(const char *num, int len, int options) {
    int state = NUM_START;
    int i;

    for (i = 0; i < len; ++i) {
        const char c = num[i];

        switch (state) {
        case NUM_START:
            if (c == '-')
                state = NUM_NEG;
            else if (!(options & STRICT_WHITESPACE) && isspace(c))
                continue;
            else if (isdigit(c))
                state = NUM_PRE_DOT;
            else if ((options & ALLOW_EMPTY_PRE_DOT) && c == '.')
              state = NUM_DOT;
            else
                return 0;
            break;
        case NUM_NEG:
            if (isdigit(c))
                state = NUM_PRE_DOT;
            else if ((options & ALLOW_EMPTY_PRE_DOT) && c == '.')
                state = NUM_DOT;
            else
                return 0;
            break;
        case NUM_PRE_DOT:
            if (c == '.')
                state = NUM_DOT;
            else if (isdigit(c))
                state = NUM_PRE_DOT;
            else
                return 0;
            break;
        case NUM_DOT:
            if (options & ONLY_TEST_INT)
                return 0;
            if (isdigit(c))
                state = NUM_POST_DOT;
            else
                return 0;
            break;
        case NUM_POST_DOT:
            if (!isdigit(c))
                return 0;
            else if (!(options & STRICT_WHITESPACE) && isspace(c))
                state = NUM_END_WHITESPACE;
            break;
        case NUM_END_WHITESPACE:
            if (!isspace(c))
              return 0;
            break;
        }
    }

    if (state == NUM_PRE_DOT || state == NUM_POST_DOT)
      return 1;

    if ((options & ALLOW_EMPTY_POST_DOT) &&
       !(options & ONLY_TEST_INT) &&
        state == NUM_DOT)
      return 1;

    if (!(options & STRICT_WHITESPACE) && state == NUM_END_WHITESPACE)
      return 1;

    return 0;
}



int is_number(const char *num, int len) {
  return is_number_with(num, len, 0);
}
