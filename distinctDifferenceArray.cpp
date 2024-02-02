#include<iostream>
#include<stdlib.h>
#include<sys/time.h>
#include<vector>
#include<map>

using namespace std;

// 2670. 找出不同元素数目差数组
// https://leetcode.cn/problems/find-the-distinct-difference-array/?envType=daily-question&envId=2024-01-31

vector<int> distinctDifferenceArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 0);
    map<int, int> pre;
    map<int, int> post;

    // 统计不同元素个数，及相同元素个数
    for (int num : nums) {
        post[num]++;
    }

    for (int i = 0; i < n; i++) {
        pre[nums[i]]++;
        if (post[nums[i]] > 1) {
            post[nums[i]]--;
        } else {
            post.erase(nums[i]);
        }
        ans[i] = pre.size() - post.size();
    }
    return ans;
}

int main(int argc, char** argv)
{
    // test1
    vector<int> nums = {1,3,3,2};
    vector<int> ans = distinctDifferenceArray(nums);
    for (auto num : ans) {
        cout << num << "," ;
    }
    cout << endl;

    // test2
    nums = {1};
    ans = distinctDifferenceArray(nums);
    for (auto num : ans) {
        cout << num << "," ;
    }
    cout << endl;

    return 0;
}
