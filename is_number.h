

#ifndef IS_NUMBER_H
#define IS_NUMBER_H

enum is_num_state {
  NUM_START,
  NUM_NEG,
  NUM_PRE_DOT,
  NUM_DOT,
  NUM_POST_DOT,
  NUM_END_WHITESPACE,
};

enum is_num_options {
  ALLOW_EMPTY_PRE_DOT = 1 << 1,
  ALLOW_EMPTY_POST_DOT = 1 << 2,
  STRICT_WHITESPACE = 1 << 3,
  ONLY_TEST_INT = 1 << 4
};

int is_number_with(const char *num, int len, int options);
int is_number(const char *num, int len);


#endif /* IS_NUMBER_H */
