#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * ArrayMaker(int tamanho){
    int *v; 
    v = (int *) malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++)    {        
        v[i] = rand() % 999;
    }
    
    return v;
}


void print_array(int array[], int tamanho)
{
   
    for (int i=0; i<tamanho; i++)
    {
        printf("%d\t",array[i]);
    }
    printf("\n");
}

void swap(int array[], int a, int b)
{
    int temp;
    temp = array[a];
    array[a] = array[b];
    array[b] = temp;
    return;
}


void quicksort(int array[],int start,int fim)
{
    int i,j;
    if(start<fim)
    {
        i = start+1;
        j = fim;
        while (i<j)
        {
            if (array[i]>array[start])
            {
                swap(array, i, j);
                j--;
            }
            else
            {
                i++;
            }
        }
        if (array[i]>=array[start])    
        {
            i--;
        }
        swap(array, start, i);
     
        quicksort(array, start, i);
        quicksort(array, j, fim);
    }

    

}

void BubbleSort(int array[], int tamanho){

   for (int i = tamanho - 1; i >= 1; i--)
	{
		for (int j = 0; j < i; j++)
		{			
			if (array[j] > array[j + 1])
			{
				int aux = array[j];
				array[j] = array[j + 1];
				array[j + 1] = aux;
			}
		}
    }
    
}


int main(int argc, const char * argv[]){
    clock_t t, t2;
    int i;    

    int *array = ArrayMaker(i);
    int array_byte = sizeof(array);
    
      
    
    for (i=2; i<200; i=i+10) {
        int *array = ArrayMaker(i);
        int array_byte = sizeof(array);
        int *temp = (int*)malloc(array_byte);
        {
            t = clock();
            quicksort(array, 0, i-1);    
            t = clock() - t; 
            printf("Quick: Quantidade de elementos: %d\n Tempo de execução: %lf",i, ((double)t2)/((CLOCKS_PER_SEC/1000.0)));
            printf("\n");
            printf("\n");
            
        }
        
        {
            t2 = clock();
            BubbleSort(array, i);
            t2= clock();
            printf("BUBBLE: Quantidade de elementos: %d\n Tempo de execução: %lf",i, ((double)t2)/((CLOCKS_PER_SEC/1000.0)));
            printf("\n");
            printf("\n");
            
        }
        printf("\n");
        free(temp);
    }
    


    return 0;
}