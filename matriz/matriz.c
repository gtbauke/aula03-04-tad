#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct Matriz {
  int **array;
  int rows;
  int cols;
};

Matriz* matriz_create(int rows, int cols) {
  Matriz* matriz = malloc(sizeof(Matriz));

  matriz->array = malloc(sizeof(int*) * rows);
  for (int i = 0; i < rows; i++) {
    matriz->array[i] = malloc(sizeof(int) * cols);
  }
  matriz->rows = rows;
  matriz->cols = cols;

  return matriz;
}

void matriz_destroy(Matriz* matriz) {
  for (int i = 0; i < matriz->rows; i++) {
    free(matriz->array[i]);
  }
  free(matriz->array);
  free(matriz);
}

void matriz_print(Matriz* matriz) {
  for (int i = 0; i < matriz->rows; i++) {
    for (int j = 0; j < matriz->cols; j++) {
      printf("%d ", matriz->array[i][j]);
    }
    printf("\n");
  }
}

int matriz_get(Matriz* matriz, int row, int col) {
  return matriz->array[row][col];
}

void matriz_set(Matriz* matriz, int row, int col, int value) {
  matriz->array[row][col] = value;
}

int matriz_rows(Matriz* matriz) {
  return matriz->rows;
}

int matriz_cols(Matriz* matriz) {
  return matriz->cols;
}

