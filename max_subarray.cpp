// Maximum Subarray (D&C)


/* O(n*log(n)) */
#include <stdio.h>
#include <math.h>
#include <limits.h>

struct Subarray {
    int max_left;
    int max_right;
    int total_sum;
};

struct Subarray maxCrossingSubarray(int arr[], int low, int mid, int high)
{	
	struct Subarray result;
	result.total_sum = 0;
	int left_sum = INT_MIN;
	int sum = 0;
	int i = 0;
	result.max_left = INT_MIN;
	for(i = mid; i >= low; i--)
	{
		sum = sum + arr[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			result.max_left = i;
		}
	}
	int right_sum = INT_MIN;
	sum = 0;
	int j = 0;
	result.max_right = INT_MIN;
	for(j = mid + 1; j < high; j++)
	{
		sum = sum + arr[j];
		if (sum > right_sum)
		{
			right_sum = sum;
			result.max_right = j;
		}
	}
	result.total_sum = left_sum + right_sum;
	return result;
}

/* Utility */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void printSubarray(int A[], int low, int high)
{
    int i;
    for (i=low; i <= high; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 
int main()
{
    int arr[] = {1, -16, 24, 20, -25, -16, 100};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int mid = arr_size / 2;

    struct Subarray max_crossing_subarray;

    max_crossing_subarray = maxCrossingSubarray(arr, 0, mid, arr_size);
 
    printf("Given array is \n");
    printArray(arr, arr_size);
    printf("\n");

    printf("The  max crossing subarray is ");
    printSubarray(arr, max_crossing_subarray.max_left, max_crossing_subarray.max_right);
    printf("\n");

 
    return 0;
}