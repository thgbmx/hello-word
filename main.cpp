#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int a = 0;
    vector<int> vec = {1, 5, 4, 2};
    sort(vec.begin(), vec.end());
    for (auto& num:vec) {
        printf("%d ,", num);
    }
    sort(vec.begin(), vec.end(), greater<int>());
    for (auto& num:vec) {
        printf("%d ,", num);
    }
    return 0;
}
