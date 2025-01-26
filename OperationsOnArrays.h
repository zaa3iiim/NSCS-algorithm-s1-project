#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


// Basic array Functions

void initializeArray(int arr[], int size, int value)
{
	int i;
	for (i = 0; i < size; i++)
	{
		arr[i] = value;
	}
}
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d , ", arr[i]);
	}
}
int findMax(int arr[], int size)
{
	int i, max = arr[0];
	for (i = 1; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

int findMin(int arr[], int size)
{
	int i, min = arr[0];
	for (i = 1; i < size; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}
int sumArray(int arr[], int size)
{
	int sum = 0, i;
	for (i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}

double averageArray(int arr[], int size)
{
	int sum;
	sum = sumArray(arr, size);
	return (float)sum / size;
}
bool isSorted(int arr[], int size)
{
	int i, pre = arr[0];
	for (i = 1; i < size; i++)
	{
		if (arr[i] < pre)
		{
			return false;
		}
		pre = arr[i];
	}
	return true;
}

// Intermediate Array Function

void reverseArray(int arr[], int size)
{
	int i, j, s = 0;
	for (i = 0, j = size - 1; i < j; i++, j--)
	{
		s = arr[j];
		arr[j] = arr[i];
		arr[i] = s;
	}
}

void countEvenOdd(int arr[], int size, int *evenCount, int *oddCount)
{
	int i;
	*evenCount = 0;
	*oddCount = 0;
	for (i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0)
		{
			*evenCount += arr[i];
		}
		else
		{
			*oddCount += arr[i];
		}
	}   
}

int secondLargest(int arr[], int size)
{
	int i, max = 0, second = 0, temp = 0;
	for (i = 0; i < size; i++)
	{
		if (arr[i] > second)
		{
			second = arr[i];
		}
		if (second > max)
		{
			temp = second;
			second = max;
			max = temp;
		}
	}
	return second;
}

int arrremoveDuplicates(int arr[], int size);

void elementFrequency(int arr[], int size)
{
	int arr2[size], i, j, count;
	for (i = 0; i < size; i++)
	{
		arr2[i] = arr[i];
	}
	int size2 = arrremoveDuplicates(arr2, size);
	for (i = 0; i < size2; i++)
	{
		count = 0;
		for (j = 0; j < size; j++)
		{
			if (arr[j] == arr2[i])
			{
				count++;
			}
		}
		printf("'%d' : %d  \n", arr2[i], count);
	}
}

void mergeSort(int arr[], int left, int right);

int arrremoveDuplicates(int arr[], int size)
{
	if (size == 0 || size == 1)
	{
		return size;
		// already empty or have one unique element
	}
	mergeSort(arr, 0, size);
	int j = 0;
	for (int i = 1; i < size; i++)
	{
		if (arr[i] != arr[j])
		{
			j++;
			arr[j] = arr[i];
		}
	}
	return j + 1;
}

int binarySearch(int arr[], int size, int target)
{
	int mid = size / 2, low = 0, high = size - 1;

	while (low <= high)
	{
		mid = (high + low) / 2;
		if (arr[mid] == target)
		{
			return mid;
		}
		else if (arr[mid] > target)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	return -1;
}

int linearSearch(int arr[], int size, int target)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (arr[i] == target)
		{
			return i;
		}
	}
	return -1;
}

void leftShift(int arr[], int size, int rotations)
{
	int arr2[size], i, j = 0;
	rotations %= size;
	for (i = rotations; i < size; j++, i++)
	{
		arr2[j] = arr[i];
	}
	for (i = 0; i < rotations; i++, j++)
	{
		arr2[j] = arr[i];
	}
	for (i = 0; i < size; i++)
	{
		arr[i] = arr2[i];
	}
}

void rightShift(int arr[], int size, int rotations)
{
	int arr2[size], i, j = 0;
	for (i = size - rotations; i < size; j++, i++)
	{
		arr2[j] = arr[i];
	}
	for (i = 0; i < size - rotations; i++, j++)
	{
		arr2[j] = arr[i];
	}
	for (i = 0; i < size; i++)
	{
		arr[i] = arr2[i];
	}
}

void arrswap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Sorting Algorithms
void bubbleSort(int arr[], int size)
{
	int i, j;
	bool swp = false;
	do
	{
		swp = false;
		for (i = 0; i < size - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				arrswap(&arr[i], &arr[i + 1]);
				swp = true;
			}
		}
	} while (swp); // repeat the prosses untill no swap is done
}
void selectionSort(int arr[], int size)
{
	int max, l = size, i;
	do
	{
		max = findMax(arr, size);		  // Find the maximum value
		i = linearSearch(arr, size, max); // Find its position
		arrswap(&arr[i], &arr[size - 1]); // Swap max with the last element
		size--;							  // Reduce size
	} while (size > 0);
}
void insertionSort(int arr[], int n)
{
	int i, j, k;
	for (i = 1; i < n; i++)
	{
		k = arr[i]; // The element we're currently inserting
		j = i - 1;	// Compare with the previous elements

		// Shift larger elements to the right to make room for the Key
		while (j >= 0 && arr[j] > k)
		{
			arr[j + 1] = arr[j]; // Shift the element to the right
			j = j - 1;			 // Move to the next element on the left
		}

		arr[j + 1] = k; // Insert the key at the right position
	}
}
void mergeSort(int arr[], int left, int right)
{
	if (left < right)
	{

		int i, k, mid = left + (right - left) / 2, l = mid - left + 1, r = right - mid;
		int l_array[l], r_array[r], j;

		for (i = 0; i < l; i++)
			l_array[i] = arr[left + i];
		for (j = 0; j < r; j++)
			r_array[j] = arr[mid + 1 + j];
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		for (k = 0, j = 0, i = left; i <= right - left; i++)
		{
			if (k <= mid - left && i < right - mid)
			{
				if (r_array[j] <= l_array[k])
				{
					arr[i] = r_array[j];
					j++;
				}
				else
				{
					arr[i] = l_array[k];
					k++;
				}
			}
			if (k > mid - left)
			{
				arr[i] = r_array[j];
				j++;
			}
			else
			{
				arr[i] = l_array[k];
				k++;
			}
		}
	}
}
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pivot = arr[low]; // Choose the first element as pivot
		int left = low + 1;
		int right = high;

		while (left <= right)
		{

			while (left <= right && arr[left] <= pivot)
				left++;
			while (left <= right && arr[right] > pivot)
				right--;

			if (left < right)
			{
				arrswap(&arr[left], &arr[right]);
			}
		}

		// Place pivot in its correct position
		arrswap(&arr[low], &arr[right]);

		// Recursively sort the subarrays
		quickSort(arr, low, right - 1);
		quickSort(arr, right + 1, high);
	}
}

// Advanced Array Functions
int findMissingNumber(int arr[], int size)
{
	mergeSort(arr, 0, size - 1);
	int i;
	for (i = 1; i < size; i++)
	{
		if (arr[i] - arr[i - 1] != 1)
		{
			return arr[i - 1] + 1;
		}
	}
	// Check if the first or last number is missing
	if (arr[0] != 1)
	{
		return 1; // The first number is missing
	}
	else if (arr[size - 1] != size + 1)
	{
		return size + 1; // The last number is missing
	}
	return -1;
}

void findPairsWithSum(int arr[], int size, int sum)
{
	if (size < 2)
	{
		printf("Array must contain at least two elements.\n");
		return;
	}
	bool exist = false;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] + arr[j] == sum)
			{
				printf("(%d + %d) ", arr[i], arr[j]);
				exist = true;
			}
		}
	}

	if (!exist)
	{
		printf("there are none pairs of elements whose sum is equal to%d", sum);
	}
}

void findSubArrayWithSum(int arr[], int size, int sum)
{
	int i = 0, j = 0, currentSum = 0;

	while (j < size)
	{
		currentSum += arr[j]; // Add the current element to the current sum

		while (currentSum > sum && i <= j)
		{
			currentSum -= arr[i]; // Remove elements from the start
			i++;
		}

		// If the current sum equals the desired sum, print the subarray
		if (currentSum == sum)
		{
			printf("(");
			for (int k = i; k <= j; k++)
			{
				printf("%d", arr[k]);
				if (k < j)
					printf("+");
			}
			printf(")\n");
		}

		j++; // Move to the next element
	}

	if (i == 0 && j == 0)
	{
		printf("No subarray found with the given sum %d.\n", sum);
	}
}

void rearrangeAlternatePositiveNegative(int arr[], int size)
{
	int pos[size], neg[size]; // Arrays to store positive and negative numbers
	int posCount = 0, negCount = 0;

	// Separate positive and negative numbers into two arrays
	for (int i = 0; i < size; i++)
	{
		if (arr[i] >= 0)
		{
			pos[posCount++] = arr[i]; // Store positive numbers
		}
		else
		{
			neg[negCount++] = arr[i]; // Store negative numbers
		}
	}

	int i = 0, j = 0, k = 0;

	// Merge the positive and negative numbers into the original array alternating

	while (i < posCount && j < negCount)
	{
		arr[k++] = pos[i++];
		arr[k++] = neg[j++];
	}

	while (i < posCount)
	{
		arr[k++] = pos[i++];
	}
	while (j < negCount)
	{
		arr[k++] = neg[j++];
	}
}

int findMajorityElement(int arr[], int size)
{
	quickSort(arr, 0, size - 1);
	int i, max, current = arr[0], count = 1, element = arr[0];
	for (i = 1; i < size; i++)
	{
		if (arr[i] == current)
		{
			count++;
		}
		else
		{
			if (count > max)
			{
				element = current;
				max = count;
			}
			current = arr[i];
			count = 1;
		}
	}
	return element;
}

void findDuplicates(int arr[], int size)
{
	quickSort(arr, 0, size - 1);
	int i = 1, j = 0;
	printf("the duplicated elements are :");
	while (i < size)
	{
		if (arr[i] == arr[j])
			printf("%d ,", arr[j]);
		while (arr[i] == arr[j])
		{
			i++;
		}

		j = i;
		i++;
	}
}

int longestIncreasingSubsequence(int arr[], int size)
{
	int i, max = 0, current = 1;
	for (i = 1; i < size; i++)
	{
		for (int i = 1; i < size; i++) {
        if (arr[i - 1] < arr[i]) {
            current++;  // Increase the current subsequence length
        } else {
            if (current > max) {
                max = current;  // Update max if the current subsequence is longer
            }
            current = 1;  // Reset current count
        }
    }
	}
	if (current > max) {
        max = current;              //check last subsequnse 
    }
	return max;
}

void findIntersection(int arr1[], int size1, int arr2[], int size2) {
    printf("Intersection of the two arrays: ");
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                printf("%d ", arr1[i]);
                break; // Avoid duplicate checks
            }
        }
    }
}

void findUnion(int arr1[], int size1, int arr2[], int size2) {
    int unionArray[size1 + size2];
    int k = 0;

    // Add all elements of arr1 to the union array
    for (int i = 0; i < size1; i++) {
        unionArray[k++] = arr1[i];
    }
    // Add elements of arr2 that are not already in the union array
    for (int i = 0; i < size2; i++) {
        bool isPresent = false;
        for (int j = 0; j < size1; j++) {
            if (arr2[i] == arr1[j]) {
                isPresent = true;
                break;
            }
        }
        if (!isPresent) {
            unionArray[k++] = arr2[i];
        }
    }

    printf("Union of the two arrays: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", unionArray[i]);
    }
}
