#include <stdio.h>
#include <stdlib.h>
#include <time.h>




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


    int array[] = {90,12,54,1,39,4,65,13,99,123,5,2,81,64,22};
    int array_byte = sizeof(array);
    int tamanho = array_byte/sizeof(int);
    print_array(array, tamanho);    
    
    int *temp = (int*)malloc(array_byte);
    {
        t = clock();
        quicksort(array, 0, tamanho-1);    
        t = clock() - t; 
        printf("Tempo de execucao Quick: %lf", ((double)t)/((CLOCKS_PER_SEC/1000.0)));
        printf("\n");
        printf("Quick \n");
        print_array(array, tamanho);
    }
       
    {
        t2 = clock();
        BubbleSort(array, tamanho);
        t2= clock();
        printf("Tempo de execucao Bubble: %lf", ((double)t2)/((CLOCKS_PER_SEC/1000.0)));
        printf("\n");
        printf("Bubble \n");
        print_array(array, tamanho);
    }

    free(temp);

    return 0;
}