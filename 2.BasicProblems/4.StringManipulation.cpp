// https://www.geeksforgeeks.org/problems/string-manipulation3706/1?page=1&difficulty%5B%5D=0&category%5B%5D=Stack&sortBy=submissions

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int removeConsecutiveSame(vector<string>& arr) {
        // Your code goes here
        stack<string>st;
        
        int n = arr.size();
        for(int i =0;i<n;i++){
            if(!st.empty()){
                string top = st.top();
                if(top==arr[i]){
                    st.pop();
                    continue;
                }
            }
            
            st.push(arr[i]);
        }
        
        return st.size();
    }
};