// Heap Sort


/* O(n*log(n)) */
#include <stdio.h>
#include <math.h>
#include <limits.h>

void maxHeapify(int arr[], int i)
{
	int l = 2 * i;
	int r = 2 * i + 1;
	int largest = INT_MIN;
	int aux = INT_MIN;

	int heap_size = sizeof(arr)/sizeof(arr[0]);

	if(l <= heap_size and arr[l] > arr[i])
	{
		largest = l;
	}
	else
	{
		largest = i;
	}
	if(largest != i)
	{
		aux = arr[i]
		arr[i] = arr[largest]
		arr[largest] = aux
		maxHeapify(arr, largest)
	}
}

void buildMaxHeap(int arr[])
{
	int i = 0;
	int heap_size = sizeof(arr)/sizeof(arr[0]);
	for(i = floor(heap_size / 2), i >= 1, i--)
	{
		maxHeapify(arr, i)
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
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    /*heapSort(arr);*/

    buildMaxHeap(arr)
    printArray(arr, n);
 
    return 0;
}