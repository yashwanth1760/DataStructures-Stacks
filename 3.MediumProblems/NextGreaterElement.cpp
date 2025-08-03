// https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>ans(n,-1);
        stack<int>st;
        
        for(int i =0;i<n;i++){
            
                while(!st.empty() && arr[st.top()]<arr[i]){
                    ans[st.top()] =arr[i];
                    st.pop();
                }
                st.push(i);
            
        }
        
        return ans;
    }
};

// tc - o(n) sc-o(n)