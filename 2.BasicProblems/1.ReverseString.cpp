// https://leetcode.com/problems/reverse-string/description/ 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char>st;
        for(auto it:s){
            st.push(it);
        }
        int i =0;
        int n = s.size();
        while(!st.empty() && i<n ){
            s[i]=st.top();
            st.pop();
            i++;
        }
        
    }
};

//tc - o(n) sc - o(n)