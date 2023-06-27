#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
     stack<int> vals;
    vector<int> ans(n, 0);
    if (n == 0) return ans;
    for (int i = n - 1; i >= 0; i--) {
        if (vals.empty()) {
            ans[i] = -1;
            vals.push(arr[i]);
        } else if (vals.top() >= arr[i]) {
            while (!vals.empty() && vals.top() >= arr[i]) {
                vals.pop();
            }
            if (vals.empty())
                ans[i] = -1;
            else
                ans[i] = vals.top();
            vals.push(arr[i]);
        } else {
            ans[i] = vals.top();
            vals.push(arr[i]);
        }
    }
    return ans;
    // Write your code here.
}
