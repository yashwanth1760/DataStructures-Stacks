// https://www.geeksforgeeks.org/problems/print-bracket-number4058/1?page=1&difficulty%5B%5D=0&category%5B%5D=Stack&sortBy=submissions

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        // Your code goes here
        stack<int>st;
        int count=1;
        vector<int>ans;
        for(auto it : str){
            if(it=='('){
                ans.push_back(count);
                st.push(count);
                count++;
            }
            if(it==')'){
                ans.push_back(st.top());
                st.pop();
            }
        }
        
        return ans;
    }
};