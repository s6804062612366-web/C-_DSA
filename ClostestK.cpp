#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> findClosestElements(const vector<int>& arr, int k, int x) {
	vector<int> result;
	int n = arr.size();
	
	auto it = lower_bound(arr.begin(), arr.end(), x);
	int right = distance(arr.begin(), it);
	int left = right - 1;
	
	if (right < n && arr[right] == x) {
		right++;
	}
	
	for(int i = 0; i < k; i++) {
		
		if (left < 0) {
			result.push_back(arr[right]);
			right++;
			
		} else if (right >= n) {
			result.push_back(arr[left]);
			left--;
			
		} else {
			int distL = abs(arr[left] - x);
			int distR = abs(arr[right] - x);
			
			if (distR <= distL) {
				result.push_back(arr[right]);
				right++;
			} else {
				result.push_back(arr[left]);
				left--;
			}
		}
	}
	return result;
}

int main() {
    
    vector<int> arr1 = {1, 3, 4, 10, 12};
    int k1 = 2, x1 = 4;
    vector<int> ans1 = findClosestElements(arr1, k1, x1);
    
    cout << "[";
    for (int i = 0; i < ans1.size(); i++) {
        cout << ans1[i] << (i == ans1.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl; 

  
    vector<int> arr2 = {10, 20, 30, 40, 50};
    int k2 = 3, x2 = 25;
    vector<int> ans2 = findClosestElements(arr2, k2, x2);
    
    cout << "[";
    for (int i = 0; i < ans2.size(); i++) {
        cout << ans2[i] << (i == ans2.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl; 

    return 0;
}
