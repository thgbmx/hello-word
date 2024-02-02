#include<iostream>
#include<stdlib.h>
#include<sys/time.h>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
//#include <algorithm>

using namespace std;

// 2808. 使循环数组所有元素相等的最少秒数
// 
// 1 <= n == nums.length <= 105
// 1 <= nums[i] <= 109

int minimumSeconds(vector<int>& nums) {
    unordered_map<int, vector<int>> mp;
    int n = nums.size(), res = n;
    for (int i = 0; i < n; ++i) {
        mp[nums[i]].push_back(i);
    }
    for (auto& pos : mp) {
        cout << "set size: " << pos.second.size() << endl;
        for (auto n:pos.second) {
            cout << n << ",";
        }
        cout << endl;
        int mx = pos.second.front() + n - pos.second.back();
        cout << "mx: " << mx << endl;
        for (int i = 1; i < pos.second.size(); ++i) {
            mx = max(mx, pos.second[i] - pos.second[i - 1]);
            cout << pos.second[i] << "," << pos.second[i - 1] << endl;
        }
        res = min(res, mx / 2);
    }
    return res;
}

int main(int argc, char** argv)
{
    // test1
    vector<int> nums = {1,11};
    cout << minimumSeconds(nums) << endl;
/*     // test2
    nums = {4,18};
    cout << minimumSeconds(nums) << endl;

    // test3
    nums = {8,8,9,10,9};
    cout << minimumSeconds(nums) << endl;

    // test4
    nums = {8,8,8};
    cout << minimumSeconds(nums) << endl; */
    return 0;
}
