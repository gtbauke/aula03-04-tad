#include <stdio.h>
#include <stdlib.h>

#include "array_dinamico.h"
#include "element.h"

#define INITIAL_CAPACITY 10

struct ArrayDinamico
{
  Element *data;
  int size;
  int capacity;
};

ArrayDinamico *array_dinamico_create()
{
  ArrayDinamico *array = malloc(sizeof(ArrayDinamico));
  array->data = malloc(INITIAL_CAPACITY * sizeof(Element));
  array->size = 0;
  array->capacity = INITIAL_CAPACITY;

  return array;
}

void array_dinamico_destroy(ArrayDinamico *array)
{
  free(array->data);
  free(array);
}

void array_dinamico_print(ArrayDinamico *array)
{
  for (int i = 0; i < array->size; i++)
  {
    element_print(array->data[i]);
  }

  printf("\n");
}

int array_dinamico_size(ArrayDinamico *array)
{
  return array->size;
}

void array_dinamico_resize(ArrayDinamico *array, int new_capacity)
{
  Element *new_array = realloc(array->data, new_capacity * sizeof(Element));

  if (new_array != NULL)
  {
    array->data = new_array;
    array->capacity = new_capacity;
  }
}

void array_dinamico_add(ArrayDinamico *array, Element element)
{
  if (array->size == array->capacity)
  {
    array_dinamico_resize(array, array->capacity * 2);
  }

  array->data[array->size] = element;
  array->size++;
}

void array_dinamico_set(ArrayDinamico *array, int index, Element element)
{
}

Element array_dinamico_get(ArrayDinamico *array, int index)
{
  if (index < 0 || index >= array->size)
  {
    printf("Index out of bounds\n");
    abort();
  }

  return array->data[index];
}
