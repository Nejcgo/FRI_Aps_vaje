#include <cmath>
#include <iostream>
#include <system_error>
#include <vector>
#include <algorithm>

using namespace std;

void mergeSort(vector<int>& list, vector<int>& indices, vector<int>& sizes, int k) {
    vector<int> final;
    
    vector<int> queue(k);
    vector<int> left(k);

    vector<int> newIndices;
    vector<int> newSizes;

    for (int i = 0; i < indices.size(); i += k) {
        if (i+k < indices.size()) {
            for (int j = 0; j < k; j++) {
                queue[j] = indices[i + j];
            }
        } else {
            queue.clear();
            for (int j = 0; i+j < indices.size(); j++) {
                queue.push_back(indices[i + j]);
            }
        }

        // set sizes
        /*for (int j = 0; j < queue.size(); j++) {
            left[j] = sizes[queue[j]];
        }*/

        newIndices.push_back(queue[0]);
        newSizes.push_back(queue.back() - queue[0] + sizes[i + queue.size() - 1]);

        for (int j = 1; j < queue.size(); j++) {
            inplace_merge(list.begin()+queue[0], list.begin()+queue[j], list.begin()+queue[j]+sizes[i+j]);
        }
    }

    indices = newIndices;
    sizes = newSizes;
}

vector<int> splitIntoSubLists(const vector<int>& list, vector<int>& sizes) {
    vector<int> final;
    final.push_back(0);
    int prev = 0;
    
    for (int i = 1; i < list.size(); i++) {
        if (list[i] < list[i-1]) {
            final.push_back(i);
            sizes.push_back(i-prev);
            prev = i;
        }  
    }

    sizes.push_back(list.size() - prev);

    return final;
}

int main() {
    int n, k, a;
    cin >> n >> k >> a;

    vector<int> list(n);
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    if (list.size() == 0) return 0;

    vector<int> sizes;
    vector<int> splitList = splitIntoSubLists(list, sizes);

    for (int repeat = 0; repeat < a; repeat++) {
        /*for (int i = 0; i < list.size(); i++) {
            cout << list[i];
            if (i != list.size() - 1) cout << " ";
        }
        cout << "\n";*/

        mergeSort(list, splitList, sizes, k);
    }

    cout << list[0];
    for (int i = 1; i < list.size(); i++) {
        cout<< " " << list[i];
    }
    cout << "\n";

    return 0;
}
