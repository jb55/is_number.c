
#include <ctype.h>

enum num_state {
    NUM_START,
    NUM_NEG,
    NUM_PRE_DOT,
    NUM_DOT,
    NUM_POST_DOT
};

enum num_options {
  ALLOW_EMPTY_PRE_DOT = 1 << 1,
  ALLOW_EMPTY_POST_DOT = 1 << 2
};

int
is_number_with(const char *num, int len, int options) {
    int state = NUM_START;

    for (int i = 0; i < len; ++i) {
        const char c = num[i];

        switch (state) {
        case NUM_START:
            if (c == '-')
                state = NUM_NEG;
            else if (isdigit(c))
                state = NUM_PRE_DOT;
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
            if (isdigit(c))
                state = NUM_POST_DOT;
            else
                return 0;
            break;
        case NUM_POST_DOT:
            if (!isdigit(c))
                return 0;
            break;
        }
    }

    int is_valid = state == NUM_PRE_DOT || state == NUM_POST_DOT;

    if (is_valid)
      return 1;

    if ((options & ALLOW_EMPTY_POST_DOT) && state == NUM_DOT) {
      return 1;
    }

    return 0;
}



int
is_number(const char *num, int len) {
  return is_number_with(num, len, 0);
}
