#include<iostream>
#include<stdlib.h>
#include<sys/time.h>
#include<vector>
#include<map>

using namespace std;

int findRotateSteps(string ring, string key) {
    int m = ring.size(), n = key.size();
    int step = n;
    if (m == 1) {
        return 1;
    }
    int tmp = 0, post = 0;
    for (int i = 0; i < n; i++) {
        while(1) {
            if (ring[tmp] == key[i]) {
                post = tmp;
                break;
            }
            if (ring[post] == key[i]) {
                tmp = post;
                break;
            }
            tmp = (tmp - 1 + m) % m;
            post = (post + 1) % m;
            step++;
        }
    }
    return step;
}

int main(int argc, char** argv)
{
    // test1
    string ring = "godding", key = "gd";
    cout << findRotateSteps(ring, key) << endl;

    // test2
    ring = "gooding", key = "gooding";
    cout << findRotateSteps(ring, key) << endl;

    // test3
    ring = "iotfo", key = "fioot";
    cout << findRotateSteps(ring, key) << endl;
    return 0;
}
