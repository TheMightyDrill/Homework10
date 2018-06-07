#include <iostream>
#include <time.h>

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

/*Got help from online :^( Change later*/
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

int main() {

	srand(time(NULL));

	
	int arr[15] = {5, 3, 6, 2, 7, 1, 7, 8, 9 , 30, 10, 13, 5, 15 ,16};

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

	/*QUICKSORT*/
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
	/*MERGESORT*/



	system("pause");
	return 0;
}