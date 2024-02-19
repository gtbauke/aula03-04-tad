#include <stdio.h>
#include <stdlib.h>

#include "string_buffer.h"

int main()
{
  StringBuffer *sb = string_buffer_create();

  string_buffer_append(sb, "Hello, ");
  string_buffer_append(sb, "world!");

  char *str = string_buffer_to_string(sb);

  printf("%s\n", str);

  free(str);
  string_buffer_destroy(sb);
  return 0;
}
