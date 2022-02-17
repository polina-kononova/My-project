#include <stdio.h>
#include <stdlib.h>

#define N 10

void create_arr(int** array, int * size);
void sort_arr(int** array, int * size);
void remove_arr(int** array);

void create_arr(int** array, int size[]) {
  array = (int **)calloc(N, sizeof(int *));
  for (size_t i = 0; i < N; i++) {
    size[i] = rand() % 10;
    array[i] = (int *)calloc(size[i], sizeof(int));
    printf("array %ld size %d: ", i, size[i]);
    for (size_t j = 0; j < size[i]; j++) {
       array[i][j] = rand() % 5;
       printf("%d ", array[i][j]);
     }
     printf("\n");
  }
}

void sort_arr(int** array, int * size);

void remove_arr(int** array) {
  for (size_t i = 0; i < N; i++) {
    free(array[i]);
  }
}


void main () {
  int** array;
  int * size = (int *)calloc(N, sizeof(int));
  create_arr(array, size);
  // remove_arr(array);
  free(size);
}

