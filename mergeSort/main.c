#define MAX_NUMBER 100
#define SIZE_ARRAY 20
#include <stdio.h>
#include <time.h>

void mergeSort(int* arr, int begin, int end);
void merge(int* arr, int begin, int end);
void print(int* arr);

int main(void)
{
	srand(time(NULL));
	int arr[SIZE_ARRAY];

	for (int i = 0; i < SIZE_ARRAY; ++i)
	{
		arr[i] = rand() % MAX_NUMBER;
	}

	printf("Before mergeSort\n");
	print(arr);

	printf("\nAfter mergeSort\n");
	mergeSort(arr, 0, SIZE_ARRAY - 1);
	print(arr);

	return 0;
}

void mergeSort(int* arr, int begin, int end)
{
	if (begin < end)
	{
		int mid = (begin + end) / 2;
		mergeSort(arr, begin, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, begin, end);
	}
}

void merge(int* arr, int begin, int end)
{
	int tempArray[SIZE_ARRAY] = { 0, };
	int mid = (begin + end) / 2;
	int i = begin;
	int j = mid + 1;
	int index = begin;

	while (i <= mid && j <= end)
	{
		if (arr[i] <= arr[j])
		{
			tempArray[index++] = arr[i++];
		}
		else
		{
			tempArray[index++] = arr[j++];
		}
	}

	for (int k = i; k <= mid; ++k)
	{
		tempArray[index++] = arr[k];
	}

	for (int k = j; k <= end; ++k)
	{
		tempArray[index++] = arr[k];
	}

	for (int k = begin; k <= end; ++k)
	{
		arr[k] = tempArray[k];
	}
}

void print(int* arr)
{
	for (int i = 0; i < SIZE_ARRAY; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}