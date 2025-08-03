 // https://www.naukri.com/code360/problems/next-smaller-element_1112581?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
using namespace std;


vector<int> nextSmallerElement(vector<int> &nums, int n)
{
    // Write your code here.
    vector<int>ans(n,-1);
        stack<int> st;

        for(int i =0;i<n;i++){

            while(!st.empty()&& nums[st.top()]>nums[i]){
                ans[st.top()]=nums[i];
                st.pop();
            }

            st.push(i);
            
        }

        return ans;
}

// tc - O(n) sc - O(n)
