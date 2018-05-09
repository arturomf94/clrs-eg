// Quicksort

/* O(nlog(n)) (average case) */

#include <stdio.h>
#include <math.h>

int partition(int arr[], int p, int r)
{

	int x = arr[r];
	int i = p - 1;
	int j;
	int aux;
	for(j = p; j < r; j++)
	{
		if(arr[j] <= x)
		{
			i = i + 1;
			aux = arr[i];
			arr[i] = arr[j];
			arr[j] = aux;
		} 
	}
	aux = arr[i + 1];
	arr[i + 1] = arr[r];
	arr[r] = aux;

	return (i + 1);
}

void quickSort(int arr[], int p, int r)
{	
	int q;
	if(p < r)
	{
		q = partition(arr, p, r);
		quickSort(arr, p, q - 1);
		quickSort(arr, q, r);
	}
}

/* Utility */

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    quickSort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}