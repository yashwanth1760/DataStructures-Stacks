// simple question by using the next smallest on rightside and leftside and taking minimum from the difference between two arrays i.e arr1[i]-arr2[i]

// https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/1722639407/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>right(n);
        vector<int>left(n);

        stack<int>st1;
        stack<int>st2;

        for(int i =0;i<n;i++){
            while(!st1.empty() && heights[st1.top()] > heights[i]){
                right[st1.top()]=i;
                st1.pop();
            }
            st1.push(i);
        }

        while(!st1.empty()){
            right[st1.top()]=n;
            st1.pop();
        }



            for(int i =n-1;i>=0;i--){
            while(!st2.empty() && heights[st2.top()] > heights[i]){
                left[st2.top()]=i;
                st2.pop();
            }
            st2.push(i);
        }

        while(!st2.empty()){
            left[st2.top()]= -1;
            st2.pop();
        }
        int ans=0;
        for(int i =0;i<n;i++){
            int temp =(right[i]-left[i]-1) * heights[i];
             ans = max(ans,temp);
        }

        return ans;
    }
};


// tc- o(n) sc-(n)