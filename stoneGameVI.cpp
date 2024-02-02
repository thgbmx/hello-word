#include<iostream>
#include<stdlib.h>
#include<sys/time.h>
#include<vector>
#include<map>

using namespace std;

// 1686. 石子游戏 VI
// 贪心，每次选择两者合最大的位置
int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
    int n = aliceValues.size();
    multimap<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp.emplace(aliceValues[i] + bobValues[i], i);
    }
    int aliceSum = 0, bobSum = 0;
    bool bAliceSel = true;
    for (auto iter = mp.rbegin(); iter != mp.rend(); iter++) {
        // cout << iter->first << " " << iter->second << endl;
        if (bAliceSel) {
            aliceSum += aliceValues[iter->second];
            bAliceSel = false;
        } else {
            bobSum += bobValues[iter->second];
            bAliceSel = true;
        }
    }

    if (aliceSum == bobSum) {
        return 0;
    }
    return (aliceSum > bobSum) ? 1:(-1);
}

int main(int argc, char** argv)
{
    // test1
    vector<int> aliceValues = {1,3}, bobValues = {2,1};
    cout << stoneGameVI(aliceValues, bobValues) << endl;

    // test2
    aliceValues = {1, 2}, bobValues = {3, 1};
    cout << stoneGameVI(aliceValues, bobValues) << endl;

    // test3
    // vector<int> aliceValuesV3 = {2,4,3}, bobValuesV3 = {1,6,7};
    aliceValues = {2,4,3}, bobValues = {1,6,7};
    cout << stoneGameVI(aliceValues, bobValues) << endl;
    return 0;
}
