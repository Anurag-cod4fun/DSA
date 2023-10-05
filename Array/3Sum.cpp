/*
---

**Problem: Finding Triplets with a Target Sum**

You are given an array of integers, and your task is to find all unique triplets in the array that sum up to a given target value. Each triplet should be represented by a vector of three integers.

Write a function `threeSum` that takes an array of integers `nums` and an integer `target` as parameters, and returns a vector of vectors containing the unique triplets that sum up to the target.

Consequently, implement the `main` function to take the array elements, the target sum, and output the triplets.

Function Signature:
```cpp
vector<vector<int>> threeSum(vector<int>& nums, int target);
```

**Input:**
- An integer `n` (1 ≤ n ≤ 1000): the size of the input array.
- A list of `n` integers `nums[i]` (-1000 ≤ nums[i] ≤ 1000): representing the elements of the array.
- An integer `target` (-2000 ≤ target ≤ 2000): the target sum.

**Output:**
- A vector of vectors, where each inner vector represents a unique triplet (in ascending order) that sums up to the target.
- The output vector should be sorted in non-descending order of the first element in each triplet.
- Each triplet should be unique.

**Example:**
```
Input:
5
[-1, 0, 1, 2, -1]
0

Output:
-1 -1 2
-1 0 1
```

**Note:**
- Each triplet should be unique, meaning there should be no duplicate triplets in the output.
- The order of elements within a triplet does not matter, but the order of the triplets themselves does matter. The output should be sorted based on the first element of each triplet in non-descending order.

---


*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums, int target) {

	vector<vector<int>> ans;

	sort(nums.begin(), nums.end());
	int n = nums.size();

	if (n < 3)
		return {};

	for (int i=0; i < n; i++) {
		int find_sum = target - nums[i];
		int leftPtr = i+1;
		int rightPtr = n - 1;

		if ( i>0 and nums[i] == nums[i-1] ) continue;
		int sum = 0;
		while(leftPtr < rightPtr) {
			sum = nums[leftPtr] + nums[rightPtr];
			if(sum == find_sum) {
				ans.push_back({nums[i],nums[leftPtr],nums[rightPtr]});
				while(leftPtr<rightPtr && nums[leftPtr] == nums[leftPtr+1]) leftPtr++;
				while(leftPtr<rightPtr && nums[rightPtr] == nums[rightPtr-1]) rightPtr++;
				leftPtr++;
				rightPtr--;
			}
			else if (sum > find_sum) {
				rightPtr--;
			}
			else
				leftPtr++;
		}
	}
	return ans;
	
}

int main() {
	freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        input[i] = a;
    }
    int target;
    cin >> target;
    
    vector<vector<int>> ans = threeSum(input, target);
    for(auto i: ans) {
    	for (auto j: i) {
    		cout << j << " ";
    	}
    	cout << "\n";
    }
    return 0;
}