// https://leetcode.com/problems/valid-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty())
                    return false;
                else {
                    char temp = st.top();
                    if ((c == ')' && temp == '(') ||
                        (c == ']' && temp == '[') ||
                        (c == '}' && temp == '{')) {
                        st.pop();
                        continue;
                    }
                    else{
                        return false;
                    }
                }
            }
    
        }

        return st.empty();
    }
};