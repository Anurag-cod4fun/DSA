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