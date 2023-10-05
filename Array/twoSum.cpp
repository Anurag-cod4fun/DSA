/*

Certainly! Here's a problem statement for the given code:

---

**Problem: Finding Pairs with a Target Sum**

You are given an array of integers, and your task is to find all unique pairs of integers in the array that sum up to a given target value. Each pair should be represented by a vector of two integers.

Write a function `twoSum` that takes an array of integers `nums` and an integer `target` as parameters, and returns a vector of pairs containing the unique pairs that sum up to the target.

Consequently, implement the `main` function to take the array elements, the target sum, and output the pairs.

Function Signature:
```cpp
vector<pair<int, int>> twoSum(vector<int>& nums, int target);
```

**Input:**
- An integer `n` (1 ≤ n ≤ 1000): the size of the input array.
- A list of `n` integers `nums[i]` (-1000 ≤ nums[i] ≤ 1000): representing the elements of the array.
- An integer `target` (-2000 ≤ target ≤ 2000): the target sum.

**Output:**
- A vector of pairs, where each pair represents a unique pair (in ascending order) that sums up to the target.
- The output vector should be sorted in non-descending order of the first element in each pair.
- Each pair should be unique.

**Example:**
```
Input:
5
[-1, 0, 1, 2, -1]
0

Output:
-1 1
```

**Note:**
- Each pair should be unique, meaning there should be no duplicate pairs in the output.
- The order of elements within a pair does not matter, but the order of the pairs themselves does matter. The output should be sorted based on the first element of each pair in non-descending order.

---

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> twoSum(vector<int> &nums, int target) {
    vector<pair<int,int>> ans;
    sort(nums.begin(), nums.end());
    int leftPtr = 0;
    int rightPtr = nums.size() - 1;

    while(leftPtr < rightPtr) {
        int sum = nums[leftPtr] + nums[rightPtr];
        if(sum == target) {
            ans.push_back({nums[leftPtr],nums[rightPtr]});
            leftPtr++;
            rightPtr--;
        }
        else if (sum > target) {
            rightPtr--;
        }
        else {
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
    vector<pair<int, int>> ans = twoSum(input, target);

    for(auto i: ans) {
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}