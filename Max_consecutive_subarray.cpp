#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Define a struct to replace tuple
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
	//auto [leftLow, leftHigh, leftSum] = Max_Subarray(arr, low, mid);
	//auto [rightLow, rightHigh, rightSum] = Max_Subarray(arr, mid + 1, high);
	//auto [crossLow, crossHigh, crossSum] = Max_Cross_Subarray(arr, low, mid, high);

	auto left = Max_Subarray(arr, low, mid);
	auto right = Max_Subarray(arr, mid + 1, high);
	auto cross = Max_Cross_Subarray(arr, low, mid, high);

	/*if (leftSum >= rightSum && leftSum >= crossSum)
		return { leftLow, leftHigh,leftSum };
	else if (rightSum >= leftSum && rightSum >= crossSum)
		return { rightLow,rightHigh,rightSum };
	else
		return { crossLow,crossHigh,crossSum };*/

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
	//return get<2>(result);  // Since result is a tuple, we extract the third element (the max sum) using get<2>(result). // get<0>, get<1>, get<2>
	//return result.sum;
	return result;
}

int main() {
	vector<int> arr = { 8, -10, 2, 0, -1, 3, -1, 7, -3 };
	cout << Max_Subarray_Sum(arr).sum;
	return 0;
}
