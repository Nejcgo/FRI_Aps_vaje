#include <climits>
#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> small{-1}, big{INT_MAX};

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);

        if (a >= small.front() && a < big.front() && small.size() <= big.size()) {
            small.push_back(a);
            push_heap(small.begin(), small.end());
        } else if (a >= small.front() && a < big.front()) {
            big.push_back(a);
            push_heap(big.begin(), big.end(), greater<>());
        } else if (a < small.front() && small.size() <= big.size()) {
            small.push_back(a);
            push_heap(small.begin(), small.end());
        } else if (a < small.front()) {
            big.push_back(small.front());
            pop_heap(small.begin(), small.end());
            small.pop_back();
            small.push_back(a);
            push_heap(big.begin(), big.end(), greater<>());
            push_heap(small.begin(), small.end());
        } else if (a >= big.front() && small.size() <= big.size()) {
            small.push_back(big.front());
            pop_heap(big.begin(), big.end(), greater<>());
            big.pop_back();
            big.push_back(a);
            push_heap(big.begin(), big.end(), greater<>());
            push_heap(small.begin(), small.end());
        } else {
            big.push_back(a);
            push_heap(big.begin(), big.end(), greater<>());
        }

        printf("%d\n", small.front());
    }

    return 0;
}
