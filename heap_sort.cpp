// Heap Sort


/* O(n*log(n)) */
#include <stdio.h>
#include <math.h>
#include <limits.h>

void maxHeapify(int arr[], int i, int n)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = INT_MIN;
	int aux = INT_MIN;

	if(l < n and arr[l] > arr[i])
	{		
		largest = l;
	}
	else
	{
		largest = i;
	}
	if(r < n and arr[r] > arr[largest])
	{
		largest = r;
	}
	if(largest != i)
	{
		aux = arr[i];
		arr[i] = arr[largest];
		arr[largest] = aux;
		maxHeapify(arr, largest, n);
	}
}

void buildMaxHeap(int arr[], int n)
{
	int i = 0;
	for(i = floor(n / 2); i >= 0; i--)
		maxHeapify(arr, i, n);
}


void heapSort(int arr[], int n)
{
	int aux = INT_MIN;
	int j = INT_MIN;

	buildMaxHeap(arr, n);
	for (j = n - 1; j > 0; j--)
	{
		aux = arr[0];
		arr[0] = arr[j];
		arr[j] = aux;
		maxHeapify(arr, 0, j);
	}
}

/* Print array */
void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}

/* Driver program to test heap sort */
int main()
{
    int arr[] = {6, 1, 7, 2, 14, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);
    printArray(arr, n);
 
    return 0;
}