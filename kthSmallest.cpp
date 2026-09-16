#include <iostream>
#include <algorithm>

using namespace std;

int kthSmallest(int arr[], int n, int k) {
	
	sort(arr, arr + n);
	
	return arr[k - 1];
}

int main() {
	int arr1[] = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
	int k1 = 4;
	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	cout << k1 << "th smallest element in the given array is " << kthSmallest(arr1, n1, k1) << endl;
	
	int arr2[] = {7, 10, 4, 3, 20, 15};
	int k2 = 3;
	int n2 = sizeof(arr2)/sizeof(arr2[0]);
	cout << k2 << "th smallest element in the given array is "  << kthSmallest(arr2, n2, k2) << endl;
	
	return 0;
}
