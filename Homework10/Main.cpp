#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#include <ctime>

using namespace std;

//insertion sort
//param(array, size of array)
void insertionSort(int arr[], int size) {

	int x = size; //size of arr
	int y = 0; //tracks sorted int (counter)

	int pos = 0; //searches list

	int lowestInt = arr[0];
	int lowestIntPos = -1;

	int swappedInt;

	while (y < x) {

		//finds the lowest int
		if (arr[pos] < lowestInt) {
			lowestInt = arr[pos];
			lowestIntPos = pos;
			pos++;
		}
		else {
			pos++;
		}

		//reached end of arr
		if (pos == size) {

			//does the swap
			swappedInt = arr[lowestIntPos];
			arr[lowestIntPos] = arr[y];
			arr[y] = swappedInt;

			y++;
			pos = y;
			lowestInt = arr[y];
			lowestIntPos = y;
		}

	}
}
//part of the quicksort function(arr, left, rightMost)
int partition(int arr[], int x, int y) {

	int pivot = arr[y];    // pivot
	int i = (x - 1);  // Index of smaller element

	for (int j = x; j <= y - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element
			
			int z = arr[j];
			arr[j] = arr[i];
			arr[i] = z;

		}
	}
	int z = arr[y];
	arr[y] = arr[i+1];
	arr[i+1] = z;

	return (i + 1);

}
//param(array, size of arr, amount sorted (should be 0 - dividing line), recursive)
void quicksort(int arr[], int x, int y) {

	if (x < y) {
		//holds x pos...?
		int z = partition(arr, x, y);

		cout << "Partitioning..." << endl;
		for (int i = 0; i < 15; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;

		quicksort(arr, x, z - 1);
		quicksort(arr, z + 1, y);
	}
	
}
void merge(int arr[], int l, int m, int r)
{
	int *L, *R;

	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	L = new int[n1]; R = new int[n2]; //this is never deleted:^(

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void timer()

{

	clock_t startTime;

	clock_t endTime;

	double runningTime;

	start = clock();

	//RUN THE THING YOU WANT TO TIME HERE!!!

	end = clock();

	runningTime = double(endTime) - double(startTime); //running time is now number of clock ticks on your system

	runningTime /= CLOCKS_PER_SECOND; //runningTime is now the number of seconds in real time

	cout << "\nIt took " << runningTime << " seconds to run the test.\n" << endl;

}

int main() {

	srand(time(NULL));

	int *arr = new int[10000];
	
	for (int i = 0; i < 10000; i++) {
		arr[i] = rand() % 500;
	}

	/*INSERTION SORT
	cout << "Before sort:" << endl;
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	insertionSort(arr, 10);

	cout << "After Insertion Sort: " << endl;
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	/*INSERTION SORT*/

	/*QUICKSORT
	cout << "Before Quick Sort:" << endl;
	for (int i = 0; i < 15; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	//quick sort
	quicksort(arr, 0, 14);

	cout << "After Quick Sort: " << endl;
	for (int i = 0; i < 15; i++) {
		cout << arr[i] << " ";
	}
	/*QUICKSORT*/

	/*MERGESORT*/
	cout << "Before Merge Sort: " << endl;
	for (int i = 0; i < 10000; i++) {
		cout << arr[i] << " ";
	}

	mergeSort(arr, 0, 9999);

	cout << "After Merge Sort: " << endl;
	for (int i = 0; i < 10000; i++) {
		cout << arr[i] << " ";
	}
	/*MERGESORT*/



	system("pause");
	return 0;
}