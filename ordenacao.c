#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *ArrayMaker(int tamanho) {
  int *v;
  v = (int *)malloc(tamanho * sizeof(int));
  for (int i = 0; i < tamanho; i++) {
    v[i] = rand() % 999;
  }

  return v;
}

void print_array(int array[], int tamanho) {

  for (int i = 0; i < tamanho; i++) {
    printf("%d\t", array[i]);
  }
  printf("\n");
}

void swap(int array[], int a, int b) {
  int temp;
  temp = array[a];
  array[a] = array[b];
  array[b] = temp;
  return;
}

void quicksort(int array[], int start, int fim) {
  int i, j;
  if (start < fim) {
    i = start + 1;
    j = fim;
    while (i < j) {
      if (array[i] > array[start]) {
        swap(array, i, j);
        j--;
      } else {
        i++;
      }
    }
    if (array[i] >= array[start]) {
      i--;
    }
    swap(array, start, i);

    quicksort(array, start, i);
    quicksort(array, j, fim);
  }
}

void BubbleSort(int array[], int tamanho) {

  for (int i = tamanho - 1; i >= 1; i--) {
    for (int j = 0; j < i; j++) {
      if (array[j] > array[j + 1]) {
        int aux = array[j];
        array[j] = array[j + 1];
        array[j + 1] = aux;
      }
    }
  }
}

int main(int argc, const char *argv[]) {
    clock_t t, t2;
    for (int i = 5; i <=20000 ; i = i + 1000) {
        
        ArrayMaker(i);
        t = clock();
        quicksort(ArrayMaker(i), 0, i - 1);
        t = clock() - t;        
        t2 = clock();
        BubbleSort(ArrayMaker(i), i);
        t2 = clock() - t2;
        printf("Quantidade de elementos: %d \nBUBBLE:Tempo de execução: %.5f secs' \nQUICK:Tempo de execução: %.5f secs' \n", i,
                (double)t2 / CLOCKS_PER_SEC, (double)t / CLOCKS_PER_SEC);
        printf("\n");
        
    }

    return 0;
}