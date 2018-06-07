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

//param(array, size of arr, amount sorted (should be 0 - dividing line), recursive)
void quicksort(int arr[], int size, bool done) {
	
	int rightMost = -1;

	//recursive
	if (done) {
		return;
	}

	srand(time(NULL));

	int pivPos = rand() % size;

	int x = size-2;//right (beyond pivot)
	int y = 0;//left

	int pivot = arr[pivPos]; //random pivot

	//move pivot to the right
	int z = arr[pivPos]; //just holds the flipped int
	arr[pivPos] = arr[size - 1];
	arr[size - 1] = z;

	while (x > y) {

		if (arr[y] >= pivot && arr[x] <= pivot) {
			//swap
			z = arr[y];
			arr[y] = arr[x];
			arr[x] = z;
			y++;
			x--;
			
			cout << "Pivot: " << pivot << endl;
			for (int i = 0; i < size; i++) {
				cout << arr[i] << " ";
			}
			cout << "x:" << x;
			cout << " y:" << y;
			cout << endl;

			continue;
		}

		if (arr[y] < pivot) {
			y++;
			continue;
		}
		else if (arr[x] > pivot) {
			x--;
		}

	}

	z = arr[x];
	arr[x] = arr[size - 1];
	arr[size - 1] = z;


	int j = 0;
	int i = 0;
	while (j <= size) {
		if (arr[j] < arr[j + 1]) {
			i++;
		}
		else {
			break;
		}
		j++;
	}

	if (i == size) {
		quicksort(arr, size, true);
		return;
	}


	cout << endl;
	cout << "Sorting...";
	cout << endl;

	quicksort(arr, size, done);
	return;

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

	cout << "Before Quick Sort:" << endl;
	for (int i = 0; i < 15; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	//quick sort
	quicksort(arr, 15, false);

	cout << "After Quick Sort: " << endl;
	for (int i = 0; i < 15; i++) {
		cout << arr[i] << " ";
	}

	//merge sort



	system("pause");
	return 0;
}