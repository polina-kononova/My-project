#include <stdio.h>
#include <stdlib.h>


int ** task(unsigned int n);
void create_arr(int** array, int * size, unsigned int n);
void sort_arr(int** array, int * size, unsigned int n);

int ** task(unsigned int n) {
  int** array;
  int * size = (int *)calloc(n, sizeof(int));
  create_arr(array, size, n);
  sort_arr(array, size, n);


  for (size_t i = 0; i < n; i++) {
    printf("array %ld: ", i, size[i]);
    for (size_t j = 0; j < size[i]; j++) {
        printf("%d ", array[i][j]);
      }
    printf("\n");
  }
  free(size);
  return array;
}

void create_arr(int** array, int size[], unsigned int n) {
  for (size_t i = 0; i < n; i++) {
    size[i] = rand() % 5;
    printf("size[%ld]=%d\n", i, size[i]);
    array[i] = (int *)calloc(size[i], sizeof(int));
    for (size_t j = 0; j < size[i]; j++) {
       array[i][j] = rand() % 20;
     }
  }
}

void sort_arr(int** array, int * size, unsigned int n) {
  int control;
	int left;
	int right;
  int tmp;
  for (int i = 0; i < n; i+=2) {
    control = size[i] - 1;
	  left  = 0;
	  right = size[i] - 1;
    do {
    for (int j = left; j < right; j++) {
      if (array[i][j] > array[i][j+1]) {
        tmp = array[i][j];
        array[i][j] = array[i][j+1];
        array[i][j+1] = tmp;
        control = j;
      }
    }
    right = control;
    for (int j = right; j > left; j--) {
      if (array[i][j] < array[i][j-1]) {
        tmp = array[i][j];
        array[i][j] = array[i][j-1];
        array[i][j-1] = tmp;
        control = j;
      }
      }
    left = control;
    } while (left < right);
  }
  for (int i = 1; i < n; i+=2) {
    control = size[i] - 1;
	  left  = 0;
	  right = size[i] - 1;
    do {
    for (int j = left; j < right; j++) {
      if (array[i][j] < array[i][j+1]) {
        tmp = array[i][j];
        array[i][j] = array[i][j+1];
        array[i][j+1] = tmp;
        control = j;
      }
    }
    right = control;
    for (int j = right; j > left; j--) {
      if (array[i][j] > array[i][j-1]) {
        tmp = array[i][j];
        array[i][j] = array[i][j-1];
        array[i][j-1] = tmp;
        control = j;
      }
      }
    left = control;
    } while (left < right);
  }
}


void main () {
  unsigned int n = 10;
  int** array = task(n);
}
