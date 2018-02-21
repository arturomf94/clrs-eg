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
	for(j = mid + 1; j <= high; j++)
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

struct Subarray maxSubarray(int arr[], int low, int high)
{
	struct Subarray result;
	struct Subarray left_result;
	struct Subarray right_result;
	struct Subarray cross_result;

	if (high == low)
	{
		result.max_left = low;
		result.max_right = high;
		result.total_sum = arr[low];
		return result;
	}
	else
	{
		if (high - low == 2)
		{
			result.max_left = low;
			result.max_right = high;
			result.total_sum = arr[low] + arr[high];
			return result;
		}
		int mid = floor((low + high) / 2);
		left_result = maxSubarray(arr, low, mid);
		right_result = maxSubarray(arr, mid + 1, high);
		cross_result = maxCrossingSubarray(arr, low, mid, high);
		if (left_result.total_sum >= right_result.total_sum and left_result.total_sum >= cross_result.total_sum)
		{
			return left_result;
		}
		if (right_result.total_sum >= left_result.total_sum and right_result.total_sum >= cross_result.total_sum)
		{
			return right_result;
		}
		else
		{
			return cross_result;
		}
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

void printSubarray(int A[], int low, int high)
{
    int i;
    for (i=low; i < high; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 
int main()
{
    int arr[] = {10, -2, 3, -4};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    struct Subarray max_subarray;

    max_subarray = maxSubarray(arr, 0, arr_size - 1);

    printf("Given array is \n");
    printArray(arr, arr_size);
    printf("\n");

    printf("The max subarray is \n");
    printSubarray(arr, max_subarray.max_left, max_subarray.max_right + 1);
    printf("\n");


 
    return 0;
}