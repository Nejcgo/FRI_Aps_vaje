#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void popTo(stack<int>& st, int n) {
    while(!st.empty() && st.top() < n) st.pop();
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    if (n <= 1) {
        cout << "0" << endl;
        return 0;
    }

    long long count = 0;
    stack<int> gospodje;
    gospodje.push(nums[0]);
    for (int i = 1; i < n; i++) {
        if (nums[i] > gospodje.top()) {
            popTo(gospodje, nums[i]);
        }
        count += gospodje.size();
        gospodje.push(nums[i]);
    }

    stack<int> gospe;
    gospe.push(nums[n-1]);
    for (int i = n-2; i >= 0; i--) {
        if (nums[i] > gospe.top()) {
            popTo(gospe, nums[i]);
        }
        count += gospe.size();
        gospe.push(nums[i]);
    }

    cout << count << endl;
    return 0;
}