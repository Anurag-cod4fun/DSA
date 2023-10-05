#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//write a function to return the all indexs of such a pair that sums up to target

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