// https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
// next greatest element on right


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 1);      // default span is 1 (itself)
        stack<int> st;              // will hold indices

        // Process from right to left to fill spans for elements
        // that have a greater element to their left
        for (int i = n - 1; i >= 0; i--) {
            // If current element is greater than elements indexed in stack,
            // then those stack indices have their previous greater at i
            while (!st.empty() && arr[st.top()] < arr[i]) {
                ans[st.top()] = st.top() - i; // span = distance from previous greater
                st.pop();
            }
            st.push(i);
        }

        // Remaining indices in stack had NO previous greater element to their left.
        // So their span is index + 1 (all earlier days are <= them).
        while (!st.empty()) {
            ans[st.top()] = st.top() + 1;
            st.pop();
        }

        return ans;
    }
};

/*
Explanation of the final while with example [60, 70, 100]:
Expected spans: [1, 2, 3]
(Because 60 has no greater to left → span 1; 70 sees 60 before it which is ≤70 → span 2; 100 sees all before it ≤100 → span 3.)

After the main loop (right-to-left), the stack contains all indices [2,1,0] because no arr[st.top()] < arr[i] condition ever triggered (we never popped). That means none of those had a previous greater to their left, so their spans default to index + 1:

Pop 0: ans[0] = 0 + 1 = 1

Pop 1: ans[1] = 1 + 1 = 2

Pop 2: ans[2] = 2 + 1 = 3

Resulting ans = [1,2,3] as desired.

tc-o(n) sc-o(n)
*/

