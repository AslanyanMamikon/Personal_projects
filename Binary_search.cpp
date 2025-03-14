
#include <iostream>

using namespace std;

int binary_search(int arr[], int left, int right, int x) {
	
	int mid;
	
	if (left <= right) {
		mid = (right + left) / 2;

		if (arr[mid] == x) {
			return mid;
		}

		if (mid < x) {
			return binary_search(arr, mid + 1, right, x);
		}
		else {
			return binary_search(arr, left, mid - 1, x);
		}
	}
	return -1;
}

void merge(int arr[], int left, int mid, int right) {

	int n1 = mid - left + 1;
	int n2 = right - mid;
	
	int* arr_left = new int[n1];
	int* arr_right = new int[n2];

	for (int i = 0; i < n1; i++)
		arr_left[i] = arr[left + i];
	for (int i = 0; i < n2; i++)
		arr_right[i] = arr[mid + 1 + i];

	int i = 0, j = 0, k= left;

	while (i < n1 && j < n2) {
		if (arr_left[i] <= arr_right[j]) {
			arr[k] = arr_left[i];
			i++;
		}
		else {
			arr[k] = arr_right[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = arr_left[i];
		i++;
		k++;
	}

	
	while (j < n2) {
		arr[k] = arr_right[j];
		j++;
		k++;
	}

	delete[] arr_right;
	delete[] arr_left;
}

void MergeSort(int arr[], int left, int right) {
	if (left < right) {
		int mid = (right + left) / 2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
}

int main()
{
	int n;
	do { cout << "n=";	cin >> n; } while (n < 2);
	
	int* arr = new int[n];

	for (int i = 0; i < n; ++i) {
		cout << "arr[" << i << "]="; cin >> arr[i];
	}

	MergeSort(arr, 0, n - 1);

	
	for (int i = 0; i < n; i++)
		cout << arr[i] << " " << endl;

	int x;
	cout << "x="; cin >> x;

	cout << binary_search(arr, 0, n - 1, x);

	delete[] arr;
	return 0;
}

