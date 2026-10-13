#include <cmath>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> mergeSort(const vector<vector<int>>& lists) {
    vector<int> final;
    vector<int> checks;

    int vectors = lists.size();

    checks.assign(lists.size(), 0);

    int size = 0;
    for (int i = 0; i < vectors; i++) {
        size += lists[i].size();
    }

    for (int i = 0; i < size; i++) {
        int smallest = INT32_MAX;
        int indexOfVector;
        for (int j = 0; j < vectors; j++) {
            if (lists[j].size() <= checks[j]) continue;
            if (lists[j][checks[j]] < smallest) {
                smallest = lists[j][checks[j]];
                indexOfVector = j;
            }
        }

        checks[indexOfVector]++;
        final.push_back(smallest);
    }

    return final;
}

vector<vector<int>> splitIntoSubLists(const vector<int>& list) {
    vector<vector<int>> final;
    vector<int> temp;

    for (int i = 0; i < list.size(); i++) {
        if (temp.size() != 0 && temp.back() > list[i]) {
            final.push_back(temp);
            temp.clear();
        }

        temp.push_back(list[i]);
    }

    if (!temp.empty()) final.push_back(temp);

    return final;
}

vector<vector<vector<int>>> groupIntoSubGroups(const vector<vector<int>>& lists, int groupSize) {
    vector<vector<vector<int>>> final((int) ceil(lists.size() / (double) groupSize));
    
    for (int i = 0; i < lists.size(); i++) {
        final[i / groupSize].push_back(lists[i]);
    }

    return final;
}

int main() {
    int n, k, a;
    cin >> n >> k >> a;

    vector<int> list(n);
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    for (int repeat = 0; repeat < a; repeat++) {
        /*for (int i = 0; i < list.size(); i++) {
            cout << list[i];
            if (i != list.size() - 1) cout << " ";
        }
        cout << "\n";*/

        vector<vector<int>> splitList = splitIntoSubLists(list);

        vector<vector<vector<int>>> spliterList = groupIntoSubGroups(splitList, k);

        list.clear();

        for (int i = 0; i < spliterList.size(); i++) {
            vector<int> part = mergeSort(spliterList[i]);
            list.insert(list.end(), part.begin(), part.end());
        }
    }

    for (int i = 0; i < list.size(); i++) {
        cout << list[i];
        if (i != list.size() - 1) cout << " ";
    }

    cout << "\n";

    return 0;
}
