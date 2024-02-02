#include<iostream>
#include<stdlib.h>
#include<sys/time.h>
#include<vector>
#include<map>

using namespace std;

typedef unsigned long int uint64;

uint64 fib(uint64 N) {
    if (N == 1 || N == 2) return 1;
    uint64 a = 1;
    uint64 b = 2;
    uint64 c = a + b;
    uint64 n = 3;
    while(N != n) {
            a = b;
            b = c;
            c = a + b;
            ++n;
    }

    return c;
}

uint64 fib_recur(uint64 N) {
    if (N == 1 || N == 2) return 1;
    return fib(N - 1) + fib(N - 2);
}

// 2670. 找出不同元素数目差数组
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

void distinctDifferenceArray_test()
{
    vector<int> nums = {1,3,3,2};
    vector<int> ans = distinctDifferenceArray(nums);
    for (auto num : ans) {
        cout << num << "," ;
    }
    cout << endl;

    nums = {1};
    ans = distinctDifferenceArray(nums);
    for (auto num : ans) {
        cout << num << "," ;
    }
    cout << endl;
}

int main(int argc, char** argv)
{
/*     int N = atoi((const char*)argv[1]);
    cout << "N = " << N  << endl;
    N = 20;
    struct timeval time_now {};
    gettimeofday(&time_now, nullptr);
    time_t msecs_st = (time_now.tv_sec * 1000) + (time_now.tv_usec);

    cout << "seconds since epoch: " << time_now.tv_sec << endl;
    //cout << "milliseconds since epoch: " << msecs_time << endl << endl;

    int ans = fib(N);
    cout << ans << endl;

    struct timeval time_tmp {};
    gettimeofday(&time_tmp, nullptr);
    time_t msecs_tmp = (time_tmp.tv_sec - time_now.tv_sec)*1000*1000 + (time_tmp.tv_usec - time_now.tv_usec);
    cout << "fib time consume: " << msecs_tmp << endl;

    ans = fib_recur(N);
    cout << ans << endl;

    struct timeval time_et {};
    gettimeofday(&time_et, nullptr);
    msecs_tmp = (time_et.tv_sec - time_tmp.tv_sec)*1000*1000 + (time_et.tv_usec - time_tmp.tv_usec);
    cout << "fib_recur time consume: " << msecs_tmp << endl; */

    distinctDifferenceArray_test();

    return 0;
}
