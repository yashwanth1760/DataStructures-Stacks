// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/?source=submission-ac

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;

        for (auto c : s) {

            if (!st.empty()) {

                char temp = st.top();
                if ((c == ')' && temp == '(')) {
                    st.pop();
                    continue;
                }
            }
        st.push(c);
        }

    return st.size();
    }

};

// tc - o(n) sc - o(n)

// 2nd method 

int minAddToMakeValid(string s) {
    int balance = 0; // unmatched '(' count
    int additions = 0; // unmatched ')' count

    for (char c : s) {
        if (c == '(') {
            balance++;
        } else { // c == ')'
            if (balance > 0) {
                balance--; // match with a previous '('
            } else {
                additions++; // unmatched ')', needs a '('
            }
        }
    }

    return additions + balance; // need ')' for leftover '(' plus unmatched ')'
}

// tc - o(n) sc - o(1)