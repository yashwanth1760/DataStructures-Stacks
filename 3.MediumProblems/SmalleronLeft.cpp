// https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/1

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> leftSmaller(vector<int> arr) {
        // code here
         int n = arr.size();
        vector<int>ans(n,-1);
        stack<int>st;
        
        for(int i =n-1;i>=0;i--){
            
                while(!st.empty() && arr[st.top()]>arr[i]){
                    ans[st.top()] =arr[i];
                    st.pop();
                }
                st.push(i);
            
        }
        
        return ans;
    }
};