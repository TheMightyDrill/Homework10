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

int getMedian(int arr[], int size) {
	int x = arr[0];
	int y = arr[size / 2];
	int z = arr[size-1];

	if (x > y) {
		if (z > x) {
			return 0;
		}

		if (y > z) {
			return (size / 2);
		}
	}
	else {
		//y > x

		if (x > z) {
			return 0;
		}

		if (z > y) {
			return size / 2;
		}

	}

	return size - 1;
}
void quicksort(int arr[], int size, bool done) {
	
	int rightMost = -1;

	//recursive
	if (done) {
		return;
	}

	srand(time(NULL));

	int pivPos = getMedian(arr, size);

	int x = size-2;//right (beyond pivot)
	int y = 0;//left

	int pivot = arr[pivPos]; //random pivot

	//move pivot to the right
	int z = arr[pivPos]; //just holds the flipped int
	arr[pivPos] = arr[size - 1];
	arr[size - 1] = z;

	while (x > y) {
		cout << endl;

		while (arr[y] < arr[y + 1] && y < size) {
			y++;
		}
		while (arr[x] > arr[x - 1] && x > 0) {
			x--;
		}

		if (x < y) {
			break;
		}

		//flip
		z = arr[y];
		arr[y] = arr[x];
		arr[x] = z;
		rightMost = x;
		x--;
		y++;

		cout << "Pivot: " << pivot << endl;
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << "x:" << x;
		cout << " y:" << y;
		cout << endl;
	}

	int j = 0;
	int i = 0;
	while (j <= size) {
		if (arr[j] < arr[j + 1]) {
			i++;
		}
		j++;
	}

	if (i == size) {
		quicksort(arr, size, true);
		return;
	}

	//flip left with pivot pos
	z = arr[rightMost];
	arr[rightMost] = arr[size - 1];
	arr[size - 1] = z;

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