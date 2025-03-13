#include <iostream>
#include <vector>
#include <limits>

using namespace std;

template <typename T>
struct SubarrayResult {
	int left;
	int right;
	T sum;
};

template <typename T>
SubarrayResult<T> Max_Cross_Subarray(vector<T>& arr, int low, int mid, int high)
{
	T leftSum = numeric_limits<T>::lowest();
	T sum = 0;
	int maxLeft = mid;

	for (int i = mid; i >= low; --i)
	{
		sum = sum + arr[i];
		if (sum > leftSum)
		{
			leftSum = sum;
			maxLeft = i;
		}
	}

	T rightSum = numeric_limits<T>::lowest();
	sum = 0;
	int maxRight = mid + 1;

	for (int i = mid + 1; i <= high; ++i)
	{
		sum = sum + arr[i];
		if (sum > rightSum)
		{
			rightSum = sum;
			maxRight = i;
		}
	}

	return {maxLeft, maxRight, leftSum + rightSum};
}

template <typename T>
SubarrayResult<T> Max_Subarray(vector<T>& arr, int low, int high)
{
	if (high == low)
	{
		return {low, high, arr[low]};
	}

	int mid = (low + high) / 2;
	
	auto left = Max_Subarray(arr, low, mid);
	auto right = Max_Subarray(arr, mid + 1, high);
	auto cross = Max_Cross_Subarray(arr, low, mid, high);
	
	if (left.sum >= right.sum && left.sum >= cross.sum)
		return left;
	else if (right.sum >= left.sum && right.sum >= cross.sum)
		return right;
	else
		return cross;
}

template <typename T>
SubarrayResult<T> Max_Subarray_Sum(vector<T>& arr)
{
	if (arr.empty()) {
		return {0, 0, T{}};
	}
	int n = arr.size();
	auto result = Max_Subarray(arr, 0, n - 1);
	return result;
}

int main() {
	vector<int> arr = { 8, -10, 2, 0, -1, 3, -1, 7, -3 };
	cout << Max_Subarray_Sum(arr).sum;
	return 0;
}
