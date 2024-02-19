#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inc/array_dinamico.h"
#include "inc/element.h"
#include "string_buffer.h"

struct StringBuffer
{
  ArrayDinamico *data;
};

StringBuffer *string_buffer_create()
{
  StringBuffer *sb = malloc(sizeof(StringBuffer));
  sb->data = array_dinamico_create();

  return sb;
}

void string_buffer_destroy(StringBuffer *sb)
{
  array_dinamico_destroy(sb->data);
  free(sb);
}

void string_buffer_append(StringBuffer *sb, char *str)
{
  for (int i = 0; i < strlen(str); ++i)
  {
    array_dinamico_add(sb->data, str[i]);
  }
}

char *string_buffer_to_string(StringBuffer *sb)
{
  int size = array_dinamico_size(sb->data) + 1;
  char *str = malloc(sizeof(char) * size);

  for (int i = 0; i < size - 1; ++i)
  {
    str[i] = array_dinamico_get(sb->data, i);
  }

  str[size - 1] = '\0';
  return str;
}
