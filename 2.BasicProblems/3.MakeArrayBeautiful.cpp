// https://www.geeksforgeeks.org/problems/make-the-array-beautiful--170647/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
      
    stack<int> s;

    for (int x : arr) {
        if (!s.empty()) {
            int top = s.top();
            if ((top >= 0 && x < 0) || (top < 0 && x >= 0)) {
                s.pop();
                continue;
            }
        }
        s.push(x);
    }

    // collect remaining in correct order
    int i = s.size()-1;
      vector<int> ans(s.size());
      
    while (!s.empty()) {
        ans[i]=s.top();
        i--;
        s.pop();
    }
   
    return ans;
    }
};

// tc-o(n) sc-o(n)